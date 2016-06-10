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

void Draw_vn_differentbkgPDF( TString inputdefault = "rootfiles/vn_morephibin_MBtrig_cent30to50_poly3bkg_floatwidth.root", TString inputpoly2bkg = "rootfiles/vn_morephibin_MBtrig_cent30to50_poly2bkg_floatwidth.root", TString inputexpobkg2ndbkg = "rootfiles/vn_morephibin_MBtrig_cent30to50_expobkg_2nd_floatwidth.root", TString method = "deltaphibins", TString MBorDtrig= "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 40.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_poly2bkg, TH1D * vn_expobkg2ndbkg, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh);

	TFile * inputdata_default = new TFile(inputdefault);
	TFile * inputdata_poly2bkg = new TFile(inputpoly2bkg);
	TFile * inputdata_expobkg2ndbkg = new TFile(inputexpobkg2ndbkg);

	TH1D * v2_default = NULL;
	TH1D * v2_poly2bkg = NULL;
	TH1D * v2_expobkg2ndbkg = NULL;

	TH1D * v3_default = NULL;
	TH1D * v3_poly2bkg = NULL;
	TH1D * v3_expobkg2ndbkg = NULL;

	if( method == "SP" )
	{
		v2_default = (TH1D *) inputdata_default->Get("h_v2_pt");
		v2_poly2bkg = (TH1D *) inputdata_poly2bkg->Get("h_v2_pt");
		v2_expobkg2ndbkg = (TH1D *) inputdata_expobkg2ndbkg->Get("h_v2_pt");
		
		v3_default = (TH1D *) inputdata_default->Get("h_v3_pt");
		v3_poly2bkg = (TH1D *) inputdata_poly2bkg->Get("h_v3_pt");
		v3_expobkg2ndbkg = (TH1D *) inputdata_expobkg2ndbkg->Get("h_v3_pt");
	}

	if( method == "deltaphibins" )
	{
		v2_default = (TH1D *) inputdata_default->Get("v2_morephibin");
		v2_poly2bkg = (TH1D *) inputdata_poly2bkg->Get("v2_morephibin");
		v2_expobkg2ndbkg = (TH1D *) inputdata_expobkg2ndbkg->Get("v2_morephibin");
		
		v3_default = (TH1D *) inputdata_default->Get("v3_morephibin");
		v3_poly2bkg = (TH1D *) inputdata_poly2bkg->Get("v3_morephibin");
		v3_expobkg2ndbkg = (TH1D *) inputdata_expobkg2ndbkg->Get("v3_morephibin");
	}

	v2_default->SetName("v2_default"); v2_default->SetTitle("v2_default");
	v2_poly2bkg->SetName("v2_poly2bkg"); v2_poly2bkg->SetTitle("v2_poly2bkg");
	v2_expobkg2ndbkg->SetName("v2_expobkg2ndbkg"); v2_expobkg2ndbkg->SetTitle("v2_expobkg2ndbkg");

	v3_default->SetName("v3_default"); v3_default->SetTitle("v3_default");
	v3_poly2bkg->SetName("v3_poly2bkg"); v3_poly2bkg->SetTitle("v3_poly2bkg");
	v3_expobkg2ndbkg->SetName("v3_expobkg2ndbkg"); v3_expobkg2ndbkg->SetTitle("v3_expobkg2ndbkg");
	
	Draw_vn_ratio( v2_default, v2_poly2bkg, v2_expobkg2ndbkg, "v2", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
	Draw_vn_ratio( v3_default, v3_poly2bkg, v3_expobkg2ndbkg, "v3", method, MBorDtrig, cent_low, cent_high, ptlow, pthigh);
}

void Draw_vn_ratio( TH1D * vn_default, TH1D * vn_poly2bkg, TH1D * vn_expobkg2ndbkg, TString vnname, TString method, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh)
{
	TCanvas * cfg_vn_diffbkgPDF = new TCanvas(Form("cfg_vn_diffbkgPDF_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), Form("cfg_vn_diffbkgPDF_%s_cent%dto%d", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high), 400, 600);
	
	TPad *pad1 = new TPad("pad1","top pad",0.0,0.4,1.0,1.0);
	pad1->SetBottomMargin(0.01);
	pad1->Draw();
	
	TPad *pad2 = new TPad("pad2","bottom pad",0.0,0.0,1.0,0.4);
	pad2->SetTopMargin(0.0);
	pad2->Draw();

	pad1->cd();
	vn_default->Draw();
	vn_poly2bkg->SetMarkerColor(6);
	vn_poly2bkg->SetLineColor(6);
	vn_poly2bkg->Draw("same");
	vn_expobkg2ndbkg->SetMarkerColor(8);
	vn_expobkg2ndbkg->SetLineColor(8);
	vn_expobkg2ndbkg->Draw("same");

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);
    fun->Draw("same");

	TLegend *  leg = new TLegend(0.45, 0.65, 0.65, 0.90);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry( (TObject*)0, Form("Cent. %d-%d%%", cent_low, cent_high) , "");
	leg->AddEntry( vn_default, "Default (Poly3 Bkg)");
	leg->AddEntry( vn_poly2bkg, "Poly2 Bkg");
	leg->AddEntry( vn_expobkg2ndbkg, "Expo Bkg");
	leg->Draw();

	pad2->cd();
	TH1D * h_vn_ratio_poly2bkg_default = (TH1D *) vn_poly2bkg->Clone("h_vn_ratio_poly2bkg_default");
	TH1D * h_vn_ratio_expobkg2ndbkg_default = (TH1D *) vn_expobkg2ndbkg->Clone("h_vn_ratio_expobkg2ndbkg_default");

	h_vn_ratio_poly2bkg_default->Divide( vn_poly2bkg, vn_default, 1.0, 1.0, "B");
	h_vn_ratio_expobkg2ndbkg_default->Divide( vn_expobkg2ndbkg, vn_default, 1.0, 1.0, "B");

	h_vn_ratio_poly2bkg_default->GetYaxis()->SetRangeUser(0.95,1.05);
	if( method == "deltaphibins" ) h_vn_ratio_poly2bkg_default->GetYaxis()->SetRangeUser(0.8,1.2);
	h_vn_ratio_poly2bkg_default->GetYaxis()->SetTitle("*/Default");
	h_vn_ratio_poly2bkg_default->Draw();
	h_vn_ratio_expobkg2ndbkg_default->Draw("same");

    TF1 * fun1 = new TF1("fun1", "1.0", 0, 100);
    fun1->SetLineColor(1.0);
    fun1->SetLineStyle(3);
    fun1->SetLineWidth(1);
    fun1->Draw("same");

	cfg_vn_diffbkgPDF->SaveAs(Form("Plots_vn/plots_PDFvariation/cfg_vn_diffbkgPDF_%s_cent%dto%d.pdf", (vnname+"_"+method+"_"+MBorDtrig).Data(), cent_low, cent_high));
}
