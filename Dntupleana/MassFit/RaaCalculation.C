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

#define BRchain 0.0388

using namespace std;

//assuming sigma=70mb, Nevents=2213 millions, estimated MB efficiency=0.9  Lumi=2.213*10^9/(70*0.85*10^9pb)=2.213/(70*0.9)=0.0351
const float LumiMBpp = 0.0351;
//assuming sigma=7750 mb, Nevents=1.0 millions, estimated MB efficiency=0.9  Lumi=0.001*10^9/(7750*0.90*10^9pb)=0.001/(7750*0.9)=7.20*1e-6
const float LumiMBPbPbpermillionevt = 1.43369e-07;

void RaaCalculation(TString fileinputppdata = "rootfiles/EfficiencyandCorrectedSpectrum_PbPb0_MBtrig_cent0to100.root", TString fileinputPbPbdata = "rootfiles/EfficiencyandCorrectedSpectrum_PbPb1_MBtrig_cent0to100.root", TString MBorDtrig = "MBtrig", int centlow = 0, int centhigh = 100, float ptmin = 2.0, float ptmax = 35.0)
{
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	TH1::SetDefaultSumw2();

	TFile * inputppdata = new TFile(fileinputppdata); 
	TFile * inputPbPbdata = new TFile(fileinputPbPbdata);

	TH1D * dNdpt_data_corrected_pp = (TH1D *) inputppdata->Get("dNdpt_data_corrected");
	TH1D * h_accxeff_pp = (TH1D *) inputppdata->Get("h_accxeff");

	TH1D * dNdpt_data_corrected_PbPb = (TH1D *) inputPbPbdata->Get("dNdpt_data_corrected");
	TH1D * h_accxeff_PbPb = (TH1D *) inputPbPbdata->Get("h_accxeff");
	TH1D * h_hibin = (TH1D *) inputPbPbdata->Get("h_hiBin");
	const float LumiMBPbPb = LumiMBPbPbpermillionevt * h_hibin->GetEntries()/1.0e6;

	TH1D * dsigmadpt_data_pp = (TH1D *) dNdpt_data_corrected_pp->Clone("dsigmadpt_data_pp");
	dsigmadpt_data_pp->Scale( 0.5 * 1.0/BRchain * 1.0/LumiMBpp);

	TH1D * dsigmadpt_data_PbPb_overNcoll = (TH1D *) dNdpt_data_corrected_PbPb->Clone("dsigmadpt_data_PbPb_overNcoll");
	dsigmadpt_data_PbPb_overNcoll->Scale(0.5 * 1.0/BRchain * 1.0/LumiMBPbPb * 1.0/(208*208));

	TH1D * RAAD0 = (TH1D *) dsigmadpt_data_pp->Clone("RAAD0");
	RAAD0->Divide( dsigmadpt_data_PbPb_overNcoll, dsigmadpt_data_pp, 1.0, 1.0);

	TCanvas * cfg_RAA = new TCanvas("cfg_RAA","cfg_RAA");

	RAAD0->GetXaxis()->SetRangeUser(ptmin+0.2, ptmax-0.2);
	RAAD0->GetYaxis()->SetRangeUser(0,1.5);
	RAAD0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	RAAD0->GetYaxis()->SetTitle("D^{0} R_{AA}");

	RAAD0->SetMarkerStyle(20);
	RAAD0->SetMarkerSize(1.0);
	RAAD0->SetMarkerColor(4.0);
	RAAD0->SetLineColor(4.0);
	RAAD0->Draw();

	TF1 * fun = new TF1("fun", "1.0", 0, 500);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(0);
	fun->Draw("same");

	cfg_RAA->SaveAs(Form("Plots_RAA/cfg_cfg_RAA_%s_cent%dto%d.pdf", MBorDtrig.Data(), centlow, centhigh));

	TFile * output = new TFile(Form("rootfiles/RAA_and_crosssection_%s_cent%dto%d.root", MBorDtrig.Data(), centlow, centhigh),"RECREATE");

	dsigmadpt_data_pp->Write();
	dsigmadpt_data_PbPb_overNcoll->Write();
	RAAD0->Write();

	output->Close();
}
