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

void Draw_vn_floatwidth( TString inputdefault = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50_poly3bkg.root", TString inputpoly3bkg_floatwidth = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth.root", TString method = "SP", TString MBorDtrig= "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 45.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_poly3bkg_floatwidth, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh);

	TFile * inputdata_default = new TFile(inputdefault);
	TFile * inputdata_poly3bkg_floatwidth = new TFile(inputpoly3bkg_floatwidth);

	TH1D * v2_default = NULL;
	TH1D * v2_poly3bkg_floatwidth = NULL;

	TH1D * v3_default = NULL;
	TH1D * v3_poly3bkg_floatwidth = NULL;

	if( method == "SP" )
	{
		v2_default = (TH1D *) inputdata_default->Get("h_v2_pt");
		v2_poly3bkg_floatwidth = (TH1D *) inputdata_poly3bkg_floatwidth->Get("h_v2_pt");
		
		v3_default = (TH1D *) inputdata_default->Get("h_v3_pt");
		v3_poly3bkg_floatwidth = (TH1D *) inputdata_poly3bkg_floatwidth->Get("h_v3_pt");
	}

	if( method == "5phibins" )
	{
		v2_default = (TH1D *) inputdata_default->Get("v2_morephibin");
		v2_poly3bkg_floatwidth = (TH1D *) inputdata_poly3bkg_floatwidth->Get("v2_morephibin");
		
		v3_default = (TH1D *) inputdata_default->Get("v3_morephibin");
		v3_poly3bkg_floatwidth = (TH1D *) inputdata_poly3bkg_floatwidth->Get("v3_morephibin");
	}

	v2_default->SetName("v2_default"); v2_default->SetTitle("v2_default");
	v2_poly3bkg_floatwidth->SetName("v2_poly3bkg_floatwidth"); v2_poly3bkg_floatwidth->SetTitle("v2_poly3bkg_floatwidth");

	v3_default->SetName("v3_default"); v3_default->SetTitle("v3_default");
	v3_poly3bkg_floatwidth->SetName("v3_poly3bkg_floatwidth"); v3_poly3bkg_floatwidth->SetTitle("v3_poly3bkg_floatwidth");
	
	Draw_vn_ratio( v2_default, v2_poly3bkg_floatwidth, "v2", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
	Draw_vn_ratio( v3_default, v3_poly3bkg_floatwidth, "v3", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
}

void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_poly3bkg_floatwidth, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh)
{
	TCanvas * cfg_vn_floatwidth = new TCanvas(Form("cfg_vn_floatwidth_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), Form("cfg_vn_floatwidth_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), 400, 600);
	
	TPad *pad1 = new TPad("pad1","top pad",0.0,0.4,1.0,1.0);
	pad1->SetBottomMargin(0.01);
	pad1->Draw();
	
	TPad *pad2 = new TPad("pad2","bottom pad",0.0,0.0,1.0,0.4);
	pad2->SetTopMargin(0.0);
	pad2->Draw();

	pad1->cd();
	vn_default->Draw();
	vn_poly3bkg_floatwidth->SetMarkerColor(4);
	vn_poly3bkg_floatwidth->SetLineColor(4);
	vn_poly3bkg_floatwidth->Draw("same");

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
	leg->AddEntry( vn_default, "Default");
	leg->AddEntry( vn_poly3bkg_floatwidth, "Float width");
	leg->Draw();

	pad2->cd();
	TH1D * h_vn_ratio_poly3bkg_floatwidth_default = (TH1D *) vn_poly3bkg_floatwidth->Clone("h_vn_ratio_poly3bkg_floatwidth_default");

	h_vn_ratio_poly3bkg_floatwidth_default->Divide( vn_poly3bkg_floatwidth, vn_default, 1.0, 1.0, "B");

	h_vn_ratio_poly3bkg_floatwidth_default->GetYaxis()->SetRangeUser(0.7,1.3);
	h_vn_ratio_poly3bkg_floatwidth_default->GetYaxis()->SetTitle("*/Default");
	h_vn_ratio_poly3bkg_floatwidth_default->Draw();

    TF1 * fun1 = new TF1("fun1", "1.0", 0, 100);
    fun1->SetLineColor(1.0);
    fun1->SetLineStyle(3);
    fun1->SetLineWidth(1);
    fun1->Draw("same");

	cfg_vn_floatwidth->SaveAs(Form("Plots_vn/plots_PDFvariation/cfg_vn_floatwidth_%s_cent%dto%d.pdf", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high));
}
