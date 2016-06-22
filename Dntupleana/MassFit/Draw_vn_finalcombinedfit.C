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

#include <./DataPoints_HIN_15_014.C>

void Draw_vn_finalcombinedfit(TString input_vnvmass_SP = "rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 40.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg_floatwidth")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	DataPoints();

	void Drawfinalcombinedfit(TH1D * vn_vnvsmass_SP, TH1D * vn_vnvsmass_SP_sys, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg");

	TFile * inputdata_vnvsmass_SP = new TFile(input_vnvmass_SP);

	TH1D * h_v2_pt = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt");
	TH1D * h_v3_pt = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt");
	h_v2_pt->SetName("h_v2_pt"); h_v2_pt->SetTitle("h_v2_pt");
	h_v3_pt->SetName("h_v3_pt"); h_v3_pt->SetTitle("h_v3_pt");

	TH1D * h_v2_pt_sys = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt_sys");
	TH1D * h_v3_pt_sys = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt_sys");
	h_v2_pt_sys->SetName("h_v2_pt_sys"); h_v2_pt_sys->SetTitle("h_v2_pt_sys");
	h_v3_pt_sys->SetName("h_v3_pt_sys"); h_v3_pt_sys->SetTitle("h_v3_pt_sys");

	Drawfinalcombinedfit( h_v2_pt, h_v2_pt_sys, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh, Drawchargedparticle, fitoption);

	if( Drawchargedparticle ) return;
	Drawfinalcombinedfit( h_v3_pt, h_v3_pt_sys, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh, false, fitoption);

	TFile * output = new TFile(Form("rootfiles/vn_finalcombinedfit_vnvsmass_%s_SP_cent%dto%d_%s_effcorrected0.root", trigname.Data(), cent_low, cent_high, fitoption.Data()),"RECREATE");
	h_v2_pt->Write();
	h_v3_pt->Write();
	h_v2_pt_sys->Write();
	h_v3_pt_sys->Write();
	output->Close();
}

void Drawfinalcombinedfit(TH1D * vn_vnvsmass_SP, TH1D * vn_vnvsmass_SP_sys, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg")
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));
	
	vn_vnvsmass_SP->Draw();

	if( Drawchargedparticle )
	{
		grSteveSPv2[8]->SetMarkerStyle(24);
		grSteveSPv2[8]->SetMarkerColor(14);
		grSteveSPv2[8]->SetLineColor(14);
		grSteveSPv2[8]->SetMarkerSize(1);

		grSteveSPv2[9]->SetMarkerStyle(24);
		grSteveSPv2[9]->SetMarkerColor(14);
		grSteveSPv2[9]->SetLineColor(14);
		grSteveSPv2[9]->SetMarkerSize(1);

		grSteveSPv2[10]->SetMarkerStyle(24);
		grSteveSPv2[10]->SetMarkerColor(14);
		grSteveSPv2[10]->SetLineColor(14);
		grSteveSPv2[10]->SetMarkerSize(1);

		if( cent_low == 0 && cent_high == 10 ) 
		{
			//grSteveSPv2sys[8]->Draw("2same");
			grSteveSPv2[8]->Draw("psame");
		}
		if( cent_low == 10 && cent_high == 30 ) 
		{
			//grSteveSPv2sys[9]->Draw("2same");
			grSteveSPv2[9]->Draw("psame");
		}
		if( cent_low == 30 && cent_high == 50 ) 
		{
			//grSteveSPv2sys[10]->Draw("2same");
			grSteveSPv2[10]->Draw("psame");
		}
	}

	vn_vnvsmass_SP_sys->Draw("E2same");
	vn_vnvsmass_SP->Draw("same");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.05);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
	Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	if( Drawchargedparticle )
	{
		TLegend * leg = new TLegend(0.50, 0.70, 0.70, 0.87);
		leg->SetTextSize(0.05);
		leg->SetTextFont(42);
		leg->AddEntry(vn_vnvsmass_SP, "D^{0}");
		leg->AddEntry(grSteveSPv2[10], "Charged particle", "p");
		leg->AddEntry((TObject*)0, "#scale[0.7]{HIN-15-014}", "");

		leg->SetBorderSize(0);
		leg->SetFillStyle(0);
		leg->Draw();
	}

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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_finalcombinedfit_vnvsmass_%s_%s_SP_cent%dto%d_charged%d_%s_effcorrected0.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, Drawchargedparticle, fitoption.Data()));
}