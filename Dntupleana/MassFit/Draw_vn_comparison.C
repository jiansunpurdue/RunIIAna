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

void Draw_vn_comparison(TString input_inoutplane = "rootfiles/vn_inoutplane_MBtrig_cent30to50.root", TString input_vnvmass_EP = "rootfiles/vn_vnvsmass_MBtrig_EP_cent30to50.root", TString input_vnvmass_SP = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 1.5, double pthigh = 35.0)
{
	void Drawcomparison(TH1D * vn_inoutplane, TH1D * vn_vnvsmass_EP, TH1D * vn_vnvsmass_SP, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0);
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * inputdata_inoutplane = new TFile(input_inoutplane);
	TFile * inputdata_vnvsmass_EP = new TFile(input_vnvmass_EP);
	TFile * inputdata_vnvsmass_SP = new TFile(input_vnvmass_SP);

	TH1D * v1_inoutplane = (TH1D *) inputdata_inoutplane->Get("v1_inoutplane");
	TH1D * v2_inoutplane = (TH1D *) inputdata_inoutplane->Get("v2_inoutplane");
	TH1D * v3_inoutplane = (TH1D *) inputdata_inoutplane->Get("v3_inoutplane");
	TH1D * v4_inoutplane = (TH1D *) inputdata_inoutplane->Get("v4_inoutplane");

	TH1D * h_v1_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v1_pt");
	TH1D * h_v2_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v2_pt");
	TH1D * h_v3_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v3_pt");
	TH1D * h_v4_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v4_pt");

	TH1D * h_v1_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v1_pt");
	TH1D * h_v2_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt");
	TH1D * h_v3_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt");
	TH1D * h_v4_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v4_pt");

	//Drawcomparison( v1_inoutplane, h_v1_pt_EP, h_v1_pt_SP, trigname, "v1", "v_{1}", cent_low, cent_high, ptlow, pthigh);
	Drawcomparison( v2_inoutplane, h_v2_pt_EP, h_v2_pt_SP, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh);
	Drawcomparison( v3_inoutplane, h_v3_pt_EP, h_v3_pt_SP, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh);
	//Drawcomparison( v4_inoutplane, h_v4_pt_EP, h_v4_pt_SP, trigname, "v4", "v_{4}", cent_low, cent_high, ptlow, pthigh);
}

void Drawcomparison(TH1D * vn_inoutplane, TH1D * vn_vnvsmass_EP, TH1D * vn_vnvsmass_SP, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0)
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));

	vn_inoutplane->Draw();
	vn_vnvsmass_EP->Draw("same");
	vn_vnvsmass_SP->Draw("same");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.04);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.125,0.96, "#scale[1.25]{CMS} Preliminary");
	Tl.DrawLatex(0.57,0.96, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLegend * leg = new TLegend(0.45, 0.77, 0.65, 0.87);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->AddEntry(vn_inoutplane, "In and out plane method");
    leg->AddEntry(vn_vnvsmass_EP, Form("%s vs mass method {EP}", Ytitle.Data()));
    leg->AddEntry(vn_vnvsmass_SP, Form("%s vs mass method {SP}", Ytitle.Data()));
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->Draw();

	TLatex* tex;
	tex = new TLatex(0.20,0.83,"|y| < 1.0");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.20,0.78,Form("Cent. %d-%d%%", cent_low, cent_high));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	TF1 * fun = new TF1("fun", "0.0", 0, 100);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(1);
	fun->Draw("same");

	cfg_vn->SaveAs(Form("Plots_vn/cfg_comparison_%s_%s_cent%dto%d.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high));
	//cfg_vn->SaveAs(Form("Plots_vn/cfg_comparison_%s_%s_cent%dto%d.png", trigname.Data(), vnname.Data(), cent_low, cent_high));
}
