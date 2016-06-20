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

void Draw_vn_bkgvnPDF( TString inputdefault = "rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent50to70_poly3bkg_floatwidth_effcorrected0.root", TString inputbkgvnpoly2 = "rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent50to70_poly3bkg_floatwidth_poly2bkg_effcorrected0.root", TString method = "SP", TString MBorDtrig= "MBtrig", int cent_low = 50, int cent_high = 70, double ptlow = 0.0, double pthigh = 40.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_bkgvnpoly2, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh);

	TFile * inputdata_default = new TFile(inputdefault);
	TFile * inputdata_bkgvnpoly2 = new TFile(inputbkgvnpoly2);

	TH1D * v2_default = NULL;
	TH1D * v2_bkgvnpoly2 = NULL;

	TH1D * v3_default = NULL;
	TH1D * v3_bkgvnpoly2 = NULL;

	if( method == "SP" )
	{
		v2_default = (TH1D *) inputdata_default->Get("h_v2_pt");
		v2_bkgvnpoly2 = (TH1D *) inputdata_bkgvnpoly2->Get("h_v2_pt");
		
		v3_default = (TH1D *) inputdata_default->Get("h_v3_pt");
		v3_bkgvnpoly2 = (TH1D *) inputdata_bkgvnpoly2->Get("h_v3_pt");
	}

	if( method == "deltaphibins" )
	{
		v2_default = (TH1D *) inputdata_default->Get("v2_morephibin");
		v2_bkgvnpoly2 = (TH1D *) inputdata_bkgvnpoly2->Get("v2_morephibin");
		
		v3_default = (TH1D *) inputdata_default->Get("v3_morephibin");
		v3_bkgvnpoly2 = (TH1D *) inputdata_bkgvnpoly2->Get("v3_morephibin");
	}

	v2_default->SetName("v2_default"); v2_default->SetTitle("v2_default");
	v2_bkgvnpoly2->SetName("v2_bkgvnpoly2"); v2_bkgvnpoly2->SetTitle("v2_bkgvnpoly2");

	v3_default->SetName("v3_default"); v3_default->SetTitle("v3_default");
	v3_bkgvnpoly2->SetName("v3_bkgvnpoly2"); v3_bkgvnpoly2->SetTitle("v3_bkgvnpoly2");
	
	Draw_vn_ratio( v2_default, v2_bkgvnpoly2, "v2", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
	Draw_vn_ratio( v3_default, v3_bkgvnpoly2, "v3", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
}

void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_bkgvnpoly2, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh)
{
	TCanvas * cfg_vn_effcorrection = new TCanvas(Form("cfg_vn_effcorrection_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), Form("cfg_vn_effcorrection_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), 400, 600);
	
	TPad *pad1 = new TPad("pad1","top pad",0.0,0.6,1.0,1.0);
	pad1->SetBottomMargin(0.0);
	pad1->Draw();
	
	TPad *pad2 = new TPad("pad2","middle pad",0.0,0.3,1.0,0.6);
	pad2->SetTopMargin(0.0);
	pad2->SetBottomMargin(0.0);
	pad2->Draw();

	TPad *pad3 = new TPad("pad3","bottom pad",0.0,0.0,1.0,0.3);
	pad3->SetTopMargin(0.0);
	pad3->Draw();

	pad1->cd();
	
	vn_default->SetTitleSize(0.06,"xyz");
	vn_default->SetLabelSize(0.08,"xyz");
	vn_default->Draw();
	vn_bkgvnpoly2->SetMarkerColor(6);
	vn_bkgvnpoly2->SetLineColor(6);
	vn_bkgvnpoly2->Draw("same");

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);
    fun->Draw("same");

	TLegend *  leg = new TLegend(0.45, 0.65, 0.65, 0.90);
	leg->SetTextSize(0.06);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry( (TObject*)0, Form("Cent. %d-%d%%", cent_low, cent_high) , "");
	leg->AddEntry( vn_default, "Default");
	leg->AddEntry( vn_bkgvnpoly2, "Bkg vn poly2");
	leg->Draw();

	pad2->cd();
	TH1D * h_vn_diff_bkgvnpoly2_default = (TH1D *) vn_bkgvnpoly2->Clone("h_vn_diff_bkgvnpoly2_default");

	h_vn_diff_bkgvnpoly2_default->Add( vn_default, -1.0);

	h_vn_diff_bkgvnpoly2_default->GetYaxis()->SetRangeUser(-0.04,0.04);
	if( method == "deltaphibins" ) h_vn_diff_bkgvnpoly2_default->GetYaxis()->SetRangeUser(0.04,0.04);
	h_vn_diff_bkgvnpoly2_default->GetYaxis()->SetTitle("*-Default");
	h_vn_diff_bkgvnpoly2_default->SetTitleSize(0.06,"xyz");
	h_vn_diff_bkgvnpoly2_default->SetLabelSize(0.08,"xyz");
	h_vn_diff_bkgvnpoly2_default->Draw();

    TF1 * fun1 = new TF1("fun1", "0.0", 0, 100);
    fun1->SetLineColor(1.0);
    fun1->SetLineStyle(3);
    fun1->SetLineWidth(1);
    fun1->Draw("same");

	pad3->cd();
	TH1D * h_vn_ratio_bkgvnpoly2_default = (TH1D *) vn_bkgvnpoly2->Clone("h_vn_ratio_bkgvnpoly2_default");

	h_vn_ratio_bkgvnpoly2_default->Divide( vn_bkgvnpoly2, vn_default, 1.0, 1.0, "B");

	h_vn_ratio_bkgvnpoly2_default->GetYaxis()->SetRangeUser(0.8,1.2);
	if( method == "deltaphibins" ) h_vn_ratio_bkgvnpoly2_default->GetYaxis()->SetRangeUser(0.5,1.5);
	h_vn_ratio_bkgvnpoly2_default->GetYaxis()->SetTitle("*/Default");
	h_vn_ratio_bkgvnpoly2_default->SetTitleSize(0.06,"xyz");
	h_vn_ratio_bkgvnpoly2_default->SetLabelSize(0.08,"xyz");
	h_vn_ratio_bkgvnpoly2_default->Draw();

    TF1 * fun2 = new TF1("fun2", "1.0", 0, 100);
    fun2->SetLineColor(1.0);
    fun2->SetLineStyle(3);
    fun2->SetLineWidth(1);
    fun2->Draw("same");

	cfg_vn_effcorrection->SaveAs(Form("Plots_vn/plots_bkgvnPDF/cfg_vn_bkgvnpoly2_%s_cent%dto%d.pdf", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high));
}
