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

void Draw_comparewithJing( TString inputdefault = "rootfiles/vn_morephibin_MBtrig_cent10to30_poly3bkg_effcorrected0.root", TString inputfromJing = "v2outputfilesfromJing/V2PtHisto_cent_10_30.root", TString method = "deltaphibins", TString MBorDtrig= "MBtrig", int cent_low = 10, int cent_high = 30, double ptlow = 0.0, double pthigh = 40.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_fromJing, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh);

	TFile * inputdata_default = new TFile(inputdefault);
	TFile * inputdata_fromJing = new TFile(inputfromJing);

	TH1D * v2_default = NULL;
	TH1D * v2_fromJing = NULL;

	TH1D * v3_default = NULL;
	TH1D * v3_fromJing = NULL;

	if( method == "SP" )
	{
		v2_default = (TH1D *) inputdata_default->Get("h_v2_pt");
		v2_fromJing = (TH1D *) inputdata_fromJing->Get("h_v2_pt");
		
		v3_default = (TH1D *) inputdata_default->Get("h_v3_pt");
		v3_fromJing = (TH1D *) inputdata_fromJing->Get("h_v3_pt");
	}

	if( method == "deltaphibins" )
	{
		v2_default = (TH1D *) inputdata_default->Get("v2_morephibin");
		v2_fromJing = (TH1D *) inputdata_fromJing->Get("hV2");
		
//		v3_default = (TH1D *) inputdata_default->Get("v3_morephibin");
//		v3_fromJing = (TH1D *) inputdata_fromJing->Get("v3_morephibin");
	}

	v2_default->SetName("v2_default"); v2_default->SetTitle("v2_default");
	v2_fromJing->SetName("v2_fromJing"); v2_fromJing->SetTitle("v2_fromJing");

//	v3_default->SetName("v3_default"); v3_default->SetTitle("v3_default");
//	v3_fromJing->SetName("v3_fromJing"); v3_fromJing->SetTitle("v3_fromJing");
	
	Draw_vn_ratio( v2_default, v2_fromJing, "v2", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
//	Draw_vn_ratio( v3_default, v3_fromJing, "v3", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
}

void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_fromJing, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh)
{
	TCanvas * cfg_vn_effcorrection = new TCanvas(Form("cfg_vn_effcorrection_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), Form("cfg_vn_effcorrection_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), 600, 600);
	
//	TPad *pad1 = new TPad("pad1","top pad",0.0,0.6,1.0,1.0);
//	pad1->SetBottomMargin(0.0);
//	pad1->Draw();
//	
//	TPad *pad2 = new TPad("pad2","middle pad",0.0,0.3,1.0,0.6);
//	pad2->SetTopMargin(0.0);
//	pad2->SetBottomMargin(0.0);
//	pad2->Draw();
//
//	TPad *pad3 = new TPad("pad3","bottom pad",0.0,0.0,1.0,0.3);
//	pad3->SetTopMargin(0.0);
//	pad3->Draw();
//
//	pad1->cd();
	
//	vn_default->SetTitleSize(0.06,"xyz");
//	vn_default->SetLabelSize(0.08,"xyz");
	vn_default->Draw();
	vn_fromJing->SetMarkerColor(8);
	vn_fromJing->SetLineColor(8);
	vn_fromJing->Draw("same");

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);
    fun->Draw("same");

	TLegend *  leg = new TLegend(0.60, 0.65, 0.75, 0.90);
	leg->SetTextSize(0.045);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry( (TObject*)0, Form("Cent. %d-%d%%", cent_low, cent_high) , "");
	leg->AddEntry( vn_default, "Default");
	leg->AddEntry( vn_fromJing, "Jing");
	leg->Draw();

//	pad2->cd();
//	TH1D * h_vn_diff_fromJing_default = (TH1D *) vn_fromJing->Clone("h_vn_diff_fromJing_default");
//
//	h_vn_diff_fromJing_default->Add( vn_default, -1.0);
//
//	h_vn_diff_fromJing_default->GetYaxis()->SetRangeUser(-0.1,0.1);
//	h_vn_diff_fromJing_default->GetYaxis()->SetTitle("*-Default");
//	h_vn_diff_fromJing_default->SetTitleSize(0.06,"xyz");
//	h_vn_diff_fromJing_default->SetLabelSize(0.08,"xyz");
//	h_vn_diff_fromJing_default->Draw();
//
//    TF1 * fun1 = new TF1("fun1", "0.0", 0, 100);
//    fun1->SetLineColor(1.0);
//    fun1->SetLineStyle(3);
//    fun1->SetLineWidth(1);
//    fun1->Draw("same");
//
//	pad3->cd();
//	TH1D * h_vn_ratio_fromJing_default = (TH1D *) vn_fromJing->Clone("h_vn_ratio_fromJing_default");
//
//	h_vn_ratio_fromJing_default->Divide( vn_fromJing, vn_default, 1.0, 1.0, "B");
//
//	h_vn_ratio_fromJing_default->GetYaxis()->SetRangeUser(0.8,1.2);
//	if( method == "deltaphibins" ) h_vn_ratio_fromJing_default->GetYaxis()->SetRangeUser(0.5,1.5);
//	h_vn_ratio_fromJing_default->GetYaxis()->SetTitle("*/Default");
//	h_vn_ratio_fromJing_default->SetTitleSize(0.06,"xyz");
//	h_vn_ratio_fromJing_default->SetLabelSize(0.08,"xyz");
//	h_vn_ratio_fromJing_default->Draw();
//
//    TF1 * fun2 = new TF1("fun2", "1.0", 0, 100);
//    fun2->SetLineColor(1.0);
//    fun2->SetLineStyle(3);
//    fun2->SetLineWidth(1);
//    fun2->Draw("same");
//
	cfg_vn_effcorrection->SaveAs(Form("Plots_vn/cfg_vn_fromJing_%s_cent%dto%d.pdf", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high));
}
