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

void MassFit(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", int iptstart = 1, int iptend = 11, bool isPbPb = 1, int centlow=30, int centhigh=50, TString fitoption = "poly3bkg_floatwidth")
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

		int iptmc;
		if( ipt > 2 ) 
			iptmc = ipt;
		else
			iptmc = 3;

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
