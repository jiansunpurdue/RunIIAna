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
#include <TString.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>

#include "./../parameters.h"

void Draw_vnvsmasscomparison_EPSP(TString input_vnvmass_EP = "rootfiles/Raw_spectrum_combinemassvnfit_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_poly3bkg_floatwidth_effcorrected0.root", TString input_vnvmass_SP = "rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_poly3bkg_floatwidth_effcorrected0.root", TString trigname = "MBtrig", int cent_low = 0, int cent_high = 10, int iptstart = 4, int iptend = 5, TString fitoption = "poly3bkg_floatwidth")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	void Draw_vn_ratio( TH1D * h_vn_EP, TH1D * h_vn_SP, TString vnname, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh, TString fitoption );
	void Draw_vnvsmasscomparison( TH1D * h_mass_meanvn_MBorDtrig_EP, TH1D * h_mass_meanvn_MBorDtrig_SP, int ipt, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 30, int cent_high = 50, TString fitoption = "poly3bkg");

	TH1D * h_mass_meanv1_MBorDtrig_EP[Nptbin];
	TH1D * h_mass_meanv2_MBorDtrig_EP[Nptbin];
	TH1D * h_mass_meanv3_MBorDtrig_EP[Nptbin];
	TH1D * h_mass_meanv4_MBorDtrig_EP[Nptbin];

	TH1D * h_mass_meanv1_MBorDtrig_SP[Nptbin];
	TH1D * h_mass_meanv2_MBorDtrig_SP[Nptbin];
	TH1D * h_mass_meanv3_MBorDtrig_SP[Nptbin];
	TH1D * h_mass_meanv4_MBorDtrig_SP[Nptbin];


	TFile * input_EP = new TFile(input_vnvmass_EP);
	TFile * input_SP = new TFile(input_vnvmass_SP);
	
	TH1D * h_v2_pt_EP = (TH1D *) input_EP->Get("h_v2_pt");
	TH1D * h_v3_pt_EP = (TH1D *) input_EP->Get("h_v3_pt");
	h_v2_pt_EP->SetName("h_v2_pt_EP");  h_v2_pt_EP->SetTitle("h_v2_pt_EP");
	h_v3_pt_EP->SetName("h_v3_pt_EP");  h_v3_pt_EP->SetTitle("h_v3_pt_EP");
	
	TH1D * h_v2_pt_SP = (TH1D *) input_SP->Get("h_v2_pt");
	TH1D * h_v3_pt_SP = (TH1D *) input_SP->Get("h_v3_pt");
	h_v2_pt_SP->SetName("h_v2_pt_SP");  h_v2_pt_SP->SetTitle("h_v2_pt_SP");
	h_v3_pt_SP->SetName("h_v3_pt_SP");  h_v3_pt_SP->SetTitle("h_v3_pt_SP");

	//get histograms
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		h_mass_meanv2_MBorDtrig_EP[ipt] = (TH1D *) input_EP->Get(Form("h_mass_meanv2_MBorDtrig_%d", ipt));
		h_mass_meanv2_MBorDtrig_EP[ipt]->SetName(Form("h_mass_meanv2_MBorDtrig_EP_%d", ipt));
		h_mass_meanv3_MBorDtrig_EP[ipt] = (TH1D *) input_EP->Get(Form("h_mass_meanv3_MBorDtrig_%d", ipt));
		h_mass_meanv3_MBorDtrig_EP[ipt]->SetName(Form("h_mass_meanv3_MBorDtrig_EP_%d", ipt));

		h_mass_meanv2_MBorDtrig_SP[ipt] = (TH1D *) input_SP->Get(Form("h_mass_meanv2_MBorDtrig_%d", ipt));
		h_mass_meanv2_MBorDtrig_SP[ipt]->SetName(Form("h_mass_meanv2_MBorDtrig_SP_%d", ipt));
		h_mass_meanv3_MBorDtrig_SP[ipt] = (TH1D *) input_SP->Get(Form("h_mass_meanv3_MBorDtrig_%d", ipt));
		h_mass_meanv3_MBorDtrig_SP[ipt]->SetName(Form("h_mass_meanv3_MBorDtrig_SP_%d", ipt));
	}

	Draw_vn_ratio( h_v2_pt_EP, h_v2_pt_SP, "v2", "MBtrig", cent_low, cent_high, 0.0, 40.0, fitoption);
	Draw_vn_ratio( h_v3_pt_EP, h_v3_pt_SP, "v3", "MBtrig", cent_low, cent_high, 0.0, 40.0, fitoption);

	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		Draw_vnvsmasscomparison( h_mass_meanv2_MBorDtrig_EP[ipt], h_mass_meanv2_MBorDtrig_SP[ipt], ipt, "MBtrig", "v2", "v_{2}", cent_low, cent_high, fitoption);
		Draw_vnvsmasscomparison( h_mass_meanv3_MBorDtrig_EP[ipt], h_mass_meanv3_MBorDtrig_SP[ipt], ipt, "MBtrig", "v3", "v_{3}", cent_low, cent_high, fitoption);
	}
}


void Draw_vn_ratio( TH1D * h_vn_EP, TH1D * h_vn_SP, TString vnname, TString MBorDtrig, int cent_low, int cent_high, float ptlow, float pthigh, TString fitoption )
{
    TCanvas * cfg_vn_combindfit = new TCanvas(Form("cfg_vn_combindfit_%s_cent%dto%d", (vnname+"_"+MBorDtrig).Data(), cent_low, cent_high), Form("cfg_vn_combindfit_%s_cent%dto%d", (vnname+"_"+MBorDtrig).Data(), cent_low, cent_high), 400, 600);

    TPad *pad1 = new TPad("pad1","top pad",0.0,0.4,1.0,1.0);
    pad1->SetBottomMargin(0.01);
    pad1->Draw();

    TPad *pad2 = new TPad("pad2","bottom pad",0.0,0.0,1.0,0.4);
    pad2->SetTopMargin(0.0);
    pad2->Draw();

    pad1->cd();
	h_vn_EP->GetXaxis()->SetRangeUser( ptlow+0.2, pthigh-0.2);
	h_vn_EP->GetYaxis()->SetRangeUser( -0.2, 0.4);
	if( vnname == "v2" ) h_vn_EP->GetYaxis()->SetTitle("v_{2}");
	if( vnname == "v3" ) h_vn_EP->GetYaxis()->SetTitle("v_{3}");
	h_vn_EP->SetMarkerStyle(22);
    h_vn_EP->SetMarkerSize(1);
    h_vn_EP->SetMarkerColor(6);
    h_vn_EP->SetLineColor(6);
    h_vn_EP->Draw();
	h_vn_SP->SetMarkerStyle(21);
    h_vn_SP->SetMarkerSize(1);
    h_vn_SP->SetMarkerColor(4);
    h_vn_SP->SetLineColor(4);
    h_vn_SP->Draw("same");

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
    leg->AddEntry( h_vn_EP, "EP");
    leg->AddEntry( h_vn_SP, "SP");
    leg->Draw();

    pad2->cd();
    TH1D * h_vn_ratio_EPSP = (TH1D *) h_vn_EP->Clone("h_vn_ratio_EPSP");

    h_vn_ratio_EPSP->Divide( h_vn_EP, h_vn_SP, 1.0, 1.0, "B");

    h_vn_ratio_EPSP->GetYaxis()->SetRangeUser(0.8,1.2);
    h_vn_ratio_EPSP->GetYaxis()->SetTitle("Ratio");
    h_vn_ratio_EPSP->Draw();

    TF1 * fun1 = new TF1("fun1", "1.0", 0, 100);
    fun1->SetLineColor(1.0);
    fun1->SetLineStyle(3);
    fun1->SetLineWidth(1);
    fun1->Draw("same");

    cfg_vn_combindfit->SaveAs(Form("Plots_vn/combinemassvnfit/cfg_compare_EPSP_combindfit_%s_cent%dto%d_%s.pdf", (vnname+"_"+MBorDtrig).Data(), cent_low, cent_high, fitoption.Data()));
}

void Draw_vnvsmasscomparison( TH1D * h_mass_meanvn_MBorDtrig_EP, TH1D * h_mass_meanvn_MBorDtrig_SP, int ipt, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 30, int cent_high = 50, TString fitoption = "poly3bkg")
{
	TCanvas * cfg_vnvsmass = new TCanvas( Form("cfg_vnvsmass_%s_%d", (trigname+vnname).Data(), ipt));

	h_mass_meanvn_MBorDtrig_EP->GetYaxis()->SetRangeUser(-0.2, 0.6);
	h_mass_meanvn_MBorDtrig_EP->GetYaxis()->SetTitle(Ytitle);
	h_mass_meanvn_MBorDtrig_EP->GetXaxis()->SetTitle("m_{#piK} (GeV/c^{2})");
	h_mass_meanvn_MBorDtrig_EP->GetXaxis()->SetTitleSize(0.05);
	h_mass_meanvn_MBorDtrig_EP->GetYaxis()->SetTitleSize(0.05);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetRangeUser(-0.2, 0.6);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetTitle(Ytitle);
	h_mass_meanvn_MBorDtrig_SP->GetXaxis()->SetTitle("m_{#piK} (GeV/c^{2})");
	h_mass_meanvn_MBorDtrig_SP->GetXaxis()->SetTitleSize(0.05);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetTitleSize(0.05);

	h_mass_meanvn_MBorDtrig_EP->SetMarkerColor(6.0);
	h_mass_meanvn_MBorDtrig_EP->GetFunction(Form("fvn_combinemassvnfit_%svn_effcorrected0_%d", trigname.Data(), ipt))->SetLineColor(6.0);
	h_mass_meanvn_MBorDtrig_EP->GetFunction(Form("fvn_combinemassvnfit_%svn_effcorrected0_%d", trigname.Data(), ipt))->SetLineStyle(2);
	h_mass_meanvn_MBorDtrig_EP->SetLineColor(6.0);
	h_mass_meanvn_MBorDtrig_EP->SetMarkerStyle(22);
	h_mass_meanvn_MBorDtrig_EP->SetMarkerSize(1.0);
//
	h_mass_meanvn_MBorDtrig_SP->SetMarkerColor(4.0);
	h_mass_meanvn_MBorDtrig_SP->GetFunction(Form("fvn_combinemassvnfit_%svn_effcorrected0_%d", trigname.Data(), ipt))->SetLineColor(4.0);
	h_mass_meanvn_MBorDtrig_SP->GetFunction(Form("fvn_combinemassvnfit_%svn_effcorrected0_%d", trigname.Data(), ipt))->SetLineStyle(2);
	h_mass_meanvn_MBorDtrig_SP->SetLineColor(4.0);
	h_mass_meanvn_MBorDtrig_SP->SetMarkerStyle(21);
	h_mass_meanvn_MBorDtrig_SP->SetMarkerSize(1.0);

	h_mass_meanvn_MBorDtrig_EP->Draw();
	h_mass_meanvn_MBorDtrig_SP->Draw("same");

    TLatex Tl; 
    Tl.SetNDC();
    Tl.SetTextAlign(12);
    Tl.SetTextSize(0.05);
    Tl.SetTextFont(42);
    Tl.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
    Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	TLegend * leg = new TLegend(0.60, 0.75, 0.80, 0.85);
	leg->SetTextFont(42);
	leg->SetTextSize(0.04);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry(h_mass_meanvn_MBorDtrig_EP, "EP method");
	leg->AddEntry(h_mass_meanvn_MBorDtrig_SP, "SP method");
	leg->Draw();

	TLatex* tex;
	tex = new TLatex(0.18,0.83,"|y| < 1.0");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.18,0.78,Form("Cent. %d-%d%%", cent_low, cent_high));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

    float ptmin = ptbins[ipt];
    float ptmax = ptbins[ipt+1];

	tex = new TLatex(0.18,0.73,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	cfg_vnvsmass->SaveAs(Form("Plots_vn/vnvsmassfit/cfg_vnvsmass_%s_cent%dto%d_%d_%s.pdf", (trigname+vnname).Data(), cent_low, cent_high, ipt, fitoption.Data()));
}
