#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>
#include <boost/filesystem.hpp>

#include <./../parameters.h>
#include <./../uti.h>
#include <./Plotoption_massfit.h>

#include <./FitFunction_poly3bkg_floatwidth.C>
#include <./FitFunction_expobkg_2nd_floatwidth.C>
#include <./FitFunction_poly2bkg_floatwidth.C>

namespace fs = boost::filesystem;

void MassFit(string inputdatafilename = "./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIHardProbes_tkpt6p0eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100.root", string inputmcfilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "Dtrig", int iptstart = 11, int iptend = 14, bool isPbPb = 1, int centlow=0, int centhigh=100, TString fitoption = "poly3bkg_floatwidth")
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, TString fitoption);

	// Get MC histograms
	TH1D * mc_matched_signal[Nptbin];
	TH1D * mc_matched_kpiswapped[Nptbin];
	TFile * inputmcfile = new TFile(Form("%s",inputmcfilename.c_str()));
	if( MBorDtrig == "MBtrig" )
	{
		get_masshist(inputmcfile, mc_matched_signal, Nptbin, "mc_matched_signal_ptweight");
		get_masshist(inputmcfile, mc_matched_kpiswapped, Nptbin, "mc_matched_kpiswapped_ptweight");
	}
	else if( MBorDtrig == "Dtrig")
	{
		get_masshist(inputmcfile, mc_matched_signal, Nptbin, "Dtrig_mc_matched_signal_ptweight");
		get_masshist(inputmcfile, mc_matched_kpiswapped, Nptbin, "Dtrig_mc_matched_kpiswapped_ptweight");
	}

	// Get Data histograms
	TH1D * hmass_MBorDtrig[Nptbin];
	TFile * inputdatafile = new TFile(Form("%s",inputdatafilename.c_str()));
	if( MBorDtrig == "MBtrig" )
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_MB_HFandpart_trig");
	else if( MBorDtrig == "Dtrig")
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_Dtrig_combined");
	//to keep track number of MB events used, needed for RAA study
	TH2D * h_trig_hiBin = (TH2D *) inputdatafile->Get("hevt_trig_hiBin");
	TH1D * h_hiBin = (TH1D *) h_trig_hiBin->ProjectionY("h_hiBin",2,2);

	TH1D * dNdpt = new TH1D( Form("dNdpt_%s", fitoption.Data()), Form("dNdpt_%s", fitoption.Data()), Nptbin, ptbins);
	Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, dNdpt, fitoption);

	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_%s_%s.root",(fs::basename(inputdatafilename)).c_str(), fitoption.Data()),"RECREATE");
	dNdpt->Write();
	h_hiBin->Write();
	output->Close();

	return;
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, TString fitoption)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		TF1* signalfittedfunc = NULL;

		int iptmc = ipt;
//		if( ipt > 2 ) 
//			iptmc = ipt;
//		else
//			iptmc = 3;

		if( fitoption == "poly3bkg_floatwidth")
			signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		if( fitoption == "expobkg_2nd_floatwidth")
			signalfittedfunc = fit_histo_expobkg_2nd_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		if( fitoption == "poly2bkg_floatwidth")
			signalfittedfunc = fit_histo_poly2bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}
}
