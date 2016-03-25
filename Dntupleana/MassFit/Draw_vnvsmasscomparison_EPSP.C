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

void Draw_vnvsmasscomparison_EPSP(TString input_vnvmass_EP = "rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root", TString input_vnvmass_SP = "rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, int iptstart = 3, int iptend = 7)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Draw_vnvsmasscomparison( TH1D * h_mass_meanvn_MBorDtrig_EP, TH1D * h_mass_meanvn_MBorDtrig_SP, int ipt, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 30, int cent_high = 50);

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

	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		Draw_vnvsmasscomparison( h_mass_meanv2_MBorDtrig_EP[ipt], h_mass_meanv2_MBorDtrig_SP[ipt], ipt, "MBtrig", "v2", "v_{2}", cent_low, cent_high);
		Draw_vnvsmasscomparison( h_mass_meanv3_MBorDtrig_EP[ipt], h_mass_meanv3_MBorDtrig_SP[ipt], ipt, "MBtrig", "v3", "v_{3}", cent_low, cent_high);
	}
}

void Draw_vnvsmasscomparison( TH1D * h_mass_meanvn_MBorDtrig_EP, TH1D * h_mass_meanvn_MBorDtrig_SP, int ipt, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 30, int cent_high = 50)
{
	TCanvas * cfg_vnvsmass = new TCanvas( Form("cfg_vnvsmass_%s_%d", (trigname+vnname).Data(), ipt));

	h_mass_meanvn_MBorDtrig_EP->GetYaxis()->SetRangeUser(-0.2, 0.6);
	h_mass_meanvn_MBorDtrig_EP->GetYaxis()->SetTitle(Ytitle);
	h_mass_meanvn_MBorDtrig_EP->GetXaxis()->SetTitle("m_{#piK} (GeV/c^{2})");
	h_mass_meanvn_MBorDtrig_EP->GetXaxis()->SetTitleSize(0.05);
	h_mass_meanvn_MBorDtrig_EP->GetYaxis()->SetTitleSize(0.05);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetRangeUser(-0.2, 0.6);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetTitle(Ytitle);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetTitle("m_{#piK} (GeV/c^{2})");
	h_mass_meanvn_MBorDtrig_SP->GetXaxis()->SetTitleSize(0.05);
	h_mass_meanvn_MBorDtrig_SP->GetYaxis()->SetTitleSize(0.05);

	h_mass_meanvn_MBorDtrig_EP->SetMarkerColor(4.0);
	h_mass_meanvn_MBorDtrig_EP->GetFunction(Form("f_vn_mass_%s_%d", (trigname+vnname).Data(), ipt))->SetLineColor(4.0);
	h_mass_meanvn_MBorDtrig_EP->GetFunction(Form("f_vn_mass_%s_%d", (trigname+vnname).Data(), ipt))->SetLineStyle(2);
	h_mass_meanvn_MBorDtrig_EP->SetLineColor(4.0);
	h_mass_meanvn_MBorDtrig_EP->SetMarkerStyle(21);
	h_mass_meanvn_MBorDtrig_EP->SetMarkerSize(1.0);

	h_mass_meanvn_MBorDtrig_SP->SetMarkerColor(6.0);
	h_mass_meanvn_MBorDtrig_SP->GetFunction(Form("f_vn_mass_%s_%d", (trigname+vnname).Data(), ipt))->SetLineColor(6.0);
	h_mass_meanvn_MBorDtrig_SP->GetFunction(Form("f_vn_mass_%s_%d", (trigname+vnname).Data(), ipt))->SetLineStyle(2);
	h_mass_meanvn_MBorDtrig_SP->SetLineColor(6.0);
	h_mass_meanvn_MBorDtrig_SP->SetMarkerStyle(22);
	h_mass_meanvn_MBorDtrig_SP->SetMarkerSize(1.3);

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

	cfg_vnvsmass->SaveAs(Form("Plots_vn/vnvsmassfit/cfg_vnvsmass_%s_cent%dto%d_%d.pdf", (trigname+vnname).Data(), cent_low, cent_high, ipt));
}
