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


void Draw_vn_2comparison(TString input_1= "rootfiles_Data_noDCAcut/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString input_vnvmass_SP = "rootfiles_Data/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString input_v2_1name = "h_v2_pt", TString input_v3_1name = "h_v3_pt", TString input_v2_2name = "h_v2_pt", TString input_v3_2name = "h_v3_pt", TString str_legend1 = "w/o DCA Cut", TString str_legend2 = "DCA < 0.008 cm", TString cfgname = "DCAcut", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 40.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Drawcomparison(TH1D * vn_1, TH1D * vn_2, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", TString str_legend1 = "W/O DCA Cut", TString str_legend2 = "DCA < 0.008", TString cfgname = "DCAcut",int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0);

	TFile * inputdata_1 = new TFile(input_1);
	TFile * inputdata_2 = new TFile(input_vnvmass_SP);

	TH1D * v2_1 = (TH1D *) inputdata_1->Get(Form("%s",input_v2_1name.Data()));
	TH1D * v3_1 = (TH1D *) inputdata_1->Get(Form("%s",input_v3_1name.Data()));
	v2_1->SetName("v2_1"); v2_1->SetTitle("v2_1");
	v3_1->SetName("v3_1"); v3_1->SetTitle("v3_1");

	TH1D * h_v2_2 = (TH1D *) inputdata_2->Get(Form("%s",input_v2_2name.Data()));
	TH1D * h_v3_2 = (TH1D *) inputdata_2->Get(Form("%s",input_v3_2name.Data()));
	h_v2_2->SetName("h_v2_2"); h_v2_2->SetTitle("h_v2_2");
	h_v3_2->SetName("h_v3_2"); h_v3_2->SetTitle("h_v3_2");

	Drawcomparison( v2_1, h_v2_2, trigname, "v2", "v_{2}", str_legend1, str_legend2, cfgname, cent_low, cent_high, ptlow, pthigh);
	Drawcomparison( v3_1, h_v3_2, trigname, "v3", "v_{3}", str_legend1, str_legend2, cfgname, cent_low, cent_high, ptlow, pthigh);
}

void Drawcomparison(TH1D * vn_1, TH1D * vn_2, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", TString str_legend1 = "W/O DCA Cut", TString str_legend2 = "DCA < 0.008", TString cfgname = "DCAcut",int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0)
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()),Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));

	vn_1->SetMarkerColor(4);
	vn_1->SetLineColor(4);
	vn_2->SetMarkerColor(2);
	vn_2->SetLineColor(2);

	vn_1->Draw();
	vn_2->Draw("same");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.05);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
	Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	TLegend * leg = new TLegend(0.50, 0.74, 0.70, 0.87);
	leg->SetTextSize(0.05);
	leg->SetTextFont(42);
	leg->AddEntry(vn_1, str_legend1);
	leg->AddEntry(vn_2, str_legend2);

	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->Draw();

	TLatex* tex;
	tex = new TLatex(0.20,0.83,"|y| < 1.0");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.05);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.20,0.76,Form("Cent. %d-%d%%", cent_low, cent_high));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.05);
	tex->SetLineWidth(2);
	tex->Draw();

	TF1 * fun = new TF1("fun", "0.0", 0, 100);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(1);
	fun->Draw("same");

	cfg_vn->SaveAs(Form("plots_otherstudy/cfg_%s_%s_%s_cent%dto%d.pdf", cfgname.Data(), trigname.Data(), vnname.Data(), cent_low, cent_high));

	TCanvas * cfg_diff_vn = new TCanvas(Form("cfg_diff_%s_%s", trigname.Data(), vnname.Data()),Form("cfg_diff_%s_%s", trigname.Data(), vnname.Data())); 

	TH1D * diff_vn = (TH1D *) vn_2->Clone("diff_vn");
	diff_vn->Add(vn_1,-1.0);

	for( int ibin = 0; ibin < diff_vn->GetNbinsX(); ibin++)
		diff_vn->SetBinError(ibin+1,vn_2->GetBinError(ibin+1));

	diff_vn->GetYaxis()->SetRangeUser(-0.1,0.1);
	diff_vn->GetYaxis()->SetTitle("Diff");
	diff_vn->Draw();

    TF1 * fun1 = new TF1("fun1", "0.0", 0, 100);
    fun1->SetLineColor(1.0);
    fun1->SetLineStyle(3);
    fun1->SetLineWidth(1);
    fun1->Draw("same");

	cfg_diff_vn->SaveAs(Form("plots_otherstudy/cfg_%s_%s_%s_cent%dto%d_diff.pdf", cfgname.Data(), trigname.Data(), vnname.Data(), cent_low, cent_high));
}
