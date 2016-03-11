#include <iostream>
#include <iomanip>
#include <utility>
#include <TFile.h>
#include <TDirectoryFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH2D.h>
#include <TString.h>
#include <TProfile.h>
#include <TEfficiency.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TBox.h>
#include <TCut.h>
#include <TMath.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TROOT.h>
#include <TStyle.h>

using namespace std;

void EfficiencyandCorrectedSpectrum(TString filenamemc = "./../rootfiles/anaDntuple_ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight_Cent-0to100_Evt0to-1.root", TString filenamedata = "rootfiles/Raw_spectrum_anaDntuple_skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016.root", bool isPbPb = false, TString MBorDtrig = "MBtrig", int centlow = 0, int centhigh = 100, float ptmin = 2.0, float ptmax = 35.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * inputMC = new TFile(filenamemc);
	TFile * inputdata = new TFile(filenamedata);

	TH1D * Gen_D0_pt;
	TH1D * MBmatched_allcuts_D0_pt;
	Gen_D0_pt = (TH1D *) inputMC->Get("Gen_D0_pt_ptweight");
	MBmatched_allcuts_D0_pt = (TH1D *) inputMC->Get("MBmatched_allcuts_D0_pt_ptweight");
	
	TH1D * dNdpt_data;
	dNdpt_data = (TH1D *) inputdata->Get("dNdpt_poly3bkg");
	TH1D * h_hibin;
	if(isPbPb) h_hibin = (TH1D *) inputdata->Get("h_hiBin");

//	TEfficiency * hteff_accxeff = new TEfficiency( *MBmatched_allcuts_D0_pt, *Gen_D0_pt);
//	hteff_accxeff->SetName("hteff_accxeff");
//	hteff_accxeff->SetTitle("hteff_accxeff");
    TGraphAsymmErrors *  hteff_accxeff = new TGraphAsymmErrors();
	hteff_accxeff->SetName("hteff_accxeff");
	hteff_accxeff->SetTitle("hteff_accxeff");
	hteff_accxeff->Divide( MBmatched_allcuts_D0_pt, Gen_D0_pt, "cp");

	TH1D * h_accxeff = (TH1D *) MBmatched_allcuts_D0_pt->Clone("h_accxeff");
	h_accxeff->SetTitle("h_accxeff");
	h_accxeff->Divide( MBmatched_allcuts_D0_pt, Gen_D0_pt, 1.0, 1.0, "B");
	h_accxeff->GetXaxis()->SetRangeUser(ptmin+0.2, ptmax-0.2);

	TH1D * dNdpt_data_corrected = (TH1D *) dNdpt_data->Clone("dNdpt_data_corrected");
	dNdpt_data_corrected->Divide(h_accxeff);
	dNdpt_data_corrected->GetXaxis()->SetRangeUser(ptmin+0.2, ptmax-0.2);

	TFile * output = new TFile(Form("rootfiles/EfficiencyandCorrectedSpectrum_PbPb%d_%s_cent%dto%d.root", isPbPb, MBorDtrig.Data(), centlow, centhigh),"RECREATE");
	dNdpt_data->Write();
	dNdpt_data_corrected->Write();
	h_accxeff->Write();
	hteff_accxeff->Write();
	if(isPbPb) h_hibin->Write();
	output->Close();
}
