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
#include <TGraphErrors.h>
#include <TMultiGraph.h>

void Draw_vn_2stepfit_combinefit( TString input2stepfit = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50_poly3bkg.root", TString inputcombinefit = "rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg.root", TString MBorDtrig= "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 45.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Draw_vn_ratio( TH1D * vn_2stepfit, TH1D * vn_combinefit, TString vnname, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh);

	TFile * inputdata_2stepfit = new TFile(input2stepfit);
	TFile * inputdata_combinefit = new TFile(inputcombinefit);

	TH1D * v2_2stepfit = (TH1D *) inputdata_2stepfit->Get("h_v2_pt");
	TH1D * v2_combinefit = (TH1D *) inputdata_combinefit->Get("h_v2_pt");

	TH1D * v3_2stepfit = (TH1D *) inputdata_2stepfit->Get("h_v3_pt");
	TH1D * v3_combinefit = (TH1D *) inputdata_combinefit->Get("h_v3_pt");

	v2_2stepfit->SetName("v2_2stepfit"); v2_2stepfit->SetTitle("v2_2stepfit");
	v2_combinefit->SetName("v2_combinefit"); v2_combinefit->SetTitle("v2_combinefit");
	v3_2stepfit->SetName("v3_2stepfit"); v3_2stepfit->SetTitle("v3_2stepfit");
	v3_combinefit->SetName("v3_combinefit"); v3_combinefit->SetTitle("v3_combinefit");

	Draw_vn_ratio( v2_2stepfit, v2_combinefit, "v2", MBorDtrig, cent_low, cent_high, ptlow, pthigh);
	Draw_vn_ratio( v3_2stepfit, v3_combinefit, "v3", MBorDtrig, cent_low, cent_high, ptlow, pthigh);
}

void Draw_vn_ratio( TH1D * vn_2stepfit, TH1D * vn_combinefit, TString vnname, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh)
{
	TCanvas * cfg_vn_combindfit = new TCanvas(Form("cfg_vn_combindfit_%s_cent%dto%d", (vnname+"_"+MBorDtrig).Data(), cent_low, cent_high), Form("cfg_vn_combindfit_%s_cent%dto%d", (vnname+"_"+MBorDtrig).Data(), cent_low, cent_high), 400, 600);

	TPad *pad1 = new TPad("pad1","top pad",0.0,0.4,1.0,1.0);
	pad1->SetBottomMargin(0.01);
	pad1->Draw();

	TPad *pad2 = new TPad("pad2","bottom pad",0.0,0.0,1.0,0.4);
	pad2->SetTopMargin(0.0);
	pad2->Draw();

	pad1->cd();
	vn_2stepfit->SetMarkerSize(1);
	vn_2stepfit->SetMarkerColor(6);
	vn_2stepfit->SetLineColor(6);
	vn_2stepfit->Draw();
	vn_combinefit->SetMarkerSize(1);
	vn_combinefit->SetMarkerColor(4);
	vn_combinefit->SetLineColor(4);
	vn_combinefit->Draw("same");

	TF1 * fun = new TF1("fun", "0.0", 0, 100);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(1);
	fun->Draw("same");

	TLegend *  leg = new TLegend(0.45, 0.70, 0.65, 0.90);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry( (TObject*)0, Form("Cent. %d-%d%%", cent_low, cent_high) , "");
	leg->AddEntry( vn_2stepfit, "2 Step Fit");
	leg->AddEntry( vn_combinefit, "Simultaneous Fit");
	leg->Draw();

	pad2->cd();
	TH1D * h_vn_ratio_combinefit_2stepfit = (TH1D *) vn_combinefit->Clone("h_vn_ratio_combinefit_2stepfit");

	h_vn_ratio_combinefit_2stepfit->Divide( vn_combinefit, vn_2stepfit, 1.0, 1.0, "B");

	h_vn_ratio_combinefit_2stepfit->GetYaxis()->SetRangeUser(0.95,1.05);
	h_vn_ratio_combinefit_2stepfit->GetYaxis()->SetTitle("Ratio");
	h_vn_ratio_combinefit_2stepfit->Draw();

	TF1 * fun1 = new TF1("fun1", "1.0", 0, 100);
	fun1->SetLineColor(1.0);
	fun1->SetLineStyle(3);
	fun1->SetLineWidth(1);
	fun1->Draw("same");

	cfg_vn_combindfit->SaveAs(Form("Plots_vn/combinemassvnfit/cfg_vn_2stepfit_combindfit_%s_cent%dto%d.pdf", (vnname+"_"+MBorDtrig).Data(), cent_low, cent_high));
}
