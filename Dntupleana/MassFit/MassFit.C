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

#include <./FitFunction_expobkg.C>
#include <./FitFunction_poly3bkg.C>

namespace fs = boost::filesystem;

void MassFit(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIHardProbes_Dtrig_ForestAOD_D0_deta2p4_tkpt8p0eta2p4_goldenjson_01302016_Cent-0to100.root", string inputmcfilename = "./../rootfiles/anaDntuple_ntD_EvtBase_20160127_Dfinder_20151229_Pythia8_prompt_D0_pthatweight_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "Dtrig", int iptstart = 11, int iptend = 23, bool isPbPb = 1, int centlow=0, int centhigh=100)
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
    void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt_poly3bkg);

    // Get MC histograms
    TH1D * mc_matched_signal[Nptbin];
	TH1D * mc_matched_kpiswapped[Nptbin];
    TFile * inputmcfile = new TFile(Form("%s",inputmcfilename.c_str()));
	get_masshist(inputmcfile, mc_matched_signal, Nptbin, "mc_matched_signal_noweight");
	get_masshist(inputmcfile, mc_matched_kpiswapped, Nptbin, "mc_matched_kpiswapped_noweight");

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

	TH1D * dNdpt_poly3bkg = new TH1D( Form("dNdpt_%s_poly3bkg", MBorDtrig.Data()), Form("dNdpt_%s_poly3bkg", MBorDtrig.Data()), Nptbin, ptbins);
    Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, dNdpt_poly3bkg);

	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_%s.root",(fs::basename(inputdatafilename)).c_str()),"RECREATE");
	dNdpt_poly3bkg->Write();
	h_hiBin->Write();
	output->Close();

	return;
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt_poly3bkg)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		TF1* signalfittedfunc;

		int iptmc;
		if( ipt > 3 ) 
			iptmc = ipt;
		else
			iptmc = 4;

		signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt_poly3bkg->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt_poly3bkg->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}
}
