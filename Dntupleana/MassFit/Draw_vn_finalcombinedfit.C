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
#include <TGraphAsymmErrors.h>
#include <TMultiGraph.h>

#include <./DataPoints_HIN_15_014.C>
#include <./Systematics.h>

void Draw_vn_finalcombinedfit(TString input_vnvmass_SP = "rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 40.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg_floatwidth", TString input_promptD0fraction = "promptD0_totaluncertainties/Fractionchange_ratioband_cent30to50.root", bool DrawsysBfeeddown_Alice = true, bool DrawsysBfeeddown_data = false)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	DataPoints();

	void CalculateBfeeddownError( TH1D * h_promptf_totaluncertainties, TGraphAsymmErrors * gr_vn_pt_sys_Bfeeddown);
	void Drawfinalcombinedfit(TH1D * vn_vnvsmass_SP, TGraphErrors * gr_vn_vnvsmass_SP_sys, TGraphAsymmErrors * gr_vn_vnvsmass_sys_Bfeeddown, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg", bool DrawsysBfeeddown_Alice = false, bool DrawsysBfeeddown_data = false);

	TFile * inputdata_promptD0fraction = new TFile(input_promptD0fraction);
	TH1D * h_promptf_totaluncertainties = (TH1D *) inputdata_promptD0fraction->Get("h_promptf_totaluncertainties_DCAcut");

	TFile * inputdata_vnvsmass_SP = new TFile(input_vnvmass_SP);

	TH1D * h_v2_pt = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt");
	TH1D * h_v3_pt = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt");
	h_v2_pt->SetName("h_v2_pt"); h_v2_pt->SetTitle("h_v2_pt");
	h_v3_pt->SetName("h_v3_pt"); h_v3_pt->SetTitle("h_v3_pt");

	TH1D * h_v2_pt_sys = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt_sys");
	TH1D * h_v3_pt_sys = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt_sys");
	h_v2_pt_sys->SetName("h_v2_pt_sys"); h_v2_pt_sys->SetTitle("h_v2_pt_sys");
	h_v3_pt_sys->SetName("h_v3_pt_sys"); h_v3_pt_sys->SetTitle("h_v3_pt_sys");

	TGraphErrors * gr_v2_pt_sys = new TGraphErrors(h_v2_pt_sys); gr_v2_pt_sys->SetName("gr_v2_pt_sys");
	TGraphErrors * gr_v3_pt_sys = new TGraphErrors(h_v3_pt_sys); gr_v3_pt_sys->SetName("gr_v3_pt_sys");

	TGraphAsymmErrors* gr_v2_pt_sys_Bfeeddown = new TGraphAsymmErrors(h_v2_pt_sys); gr_v2_pt_sys_Bfeeddown->SetName("gr_v2_pt_sys_Bfeeddown");
	TGraphAsymmErrors* gr_v3_pt_sys_Bfeeddown = new TGraphAsymmErrors(h_v3_pt_sys); gr_v3_pt_sys_Bfeeddown->SetName("gr_v3_pt_sys_Bfeeddown");

	if( DrawsysBfeeddown_Alice )
	{
		CalculateBfeeddownError( h_promptf_totaluncertainties, gr_v2_pt_sys_Bfeeddown);
		CalculateBfeeddownError( h_promptf_totaluncertainties, gr_v3_pt_sys_Bfeeddown);
	}
	
	if( DrawsysBfeeddown_data )
	{
		Calculate_sys_Bfeeddown( cent_low, cent_high, 1.0, 40.0, "SP", "v2", h_v2_pt, gr_v2_pt_sys_Bfeeddown);
		Calculate_sys_Bfeeddown( cent_low, cent_high, 1.0, 40.0, "SP", "v3", h_v3_pt, gr_v3_pt_sys_Bfeeddown);
	}

	Drawfinalcombinedfit( h_v2_pt, gr_v2_pt_sys, gr_v2_pt_sys_Bfeeddown, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh, Drawchargedparticle, fitoption, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data);

	Drawfinalcombinedfit( h_v3_pt, gr_v3_pt_sys, gr_v3_pt_sys_Bfeeddown, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh, false, fitoption, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data);

	TFile * output = new TFile(Form("rootfiles/vn_finalcombinedfit_vnvsmass_%s_SP_cent%dto%d_%s_Bfeeddownsys_Alice%d_data%d_effcorrected0.root", trigname.Data(), cent_low, cent_high, fitoption.Data(), DrawsysBfeeddown_Alice, DrawsysBfeeddown_data),"RECREATE");
	h_v2_pt->Write();
	h_v3_pt->Write();
	gr_v2_pt_sys->Write();
	gr_v3_pt_sys->Write();
	gr_v2_pt_sys_Bfeeddown->Write();
	gr_v3_pt_sys_Bfeeddown->Write();
	h_v2_pt_sys->Write();
	h_v3_pt_sys->Write();
	output->Close();
}

void CalculateBfeeddownError( TH1D * h_promptf_totaluncertainties, TGraphAsymmErrors * gr_vn_pt_sys_Bfeeddown)
{
	for( int ibin = 0; ibin < gr_vn_pt_sys_Bfeeddown->GetN(); ibin++ )
	{
		gr_vn_pt_sys_Bfeeddown->GetEXlow()[ibin] = 0.5;
		gr_vn_pt_sys_Bfeeddown->GetEXhigh()[ibin] = 0.5;
		gr_vn_pt_sys_Bfeeddown->GetEYlow()[ibin] = 0.0;

		double vnvalue = gr_vn_pt_sys_Bfeeddown->GetY()[ibin];
		double promptfraction_lower = h_promptf_totaluncertainties->GetBinContent(ibin+1) - h_promptf_totaluncertainties->GetBinError(ibin+1);

		cout << " ibin: " << ibin << " vnvalue: " << vnvalue << " promptfraction: " << h_promptf_totaluncertainties->GetBinContent(ibin+1) << " error: " << h_promptf_totaluncertainties->GetBinError(ibin+1) << endl;

		if( promptfraction_lower > 0 && vnvalue < 1.0)
			gr_vn_pt_sys_Bfeeddown->GetEYhigh()[ibin] = vnvalue/promptfraction_lower - vnvalue;
		else
			gr_vn_pt_sys_Bfeeddown->GetEYhigh()[ibin] = 0;
	}
}

void Drawfinalcombinedfit(TH1D * vn_vnvsmass_SP, TGraphErrors * gr_vn_vnvsmass_SP_sys, TGraphAsymmErrors * gr_vn_vnvsmass_sys_Bfeeddown, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg", bool DrawsysBfeeddown_Alice = false, bool DrawsysBfeeddown_data = false)
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));
	
	vn_vnvsmass_SP->Draw();

    gr_vn_vnvsmass_sys_Bfeeddown->SetMarkerColor(4.0);
    gr_vn_vnvsmass_sys_Bfeeddown->SetMarkerStyle(21);
    gr_vn_vnvsmass_sys_Bfeeddown->SetLineWidth(0);
    gr_vn_vnvsmass_sys_Bfeeddown->SetFillStyle(1001);
	gr_vn_vnvsmass_sys_Bfeeddown->SetFillColor(kBlue-10);
    gr_vn_vnvsmass_sys_Bfeeddown->SetLineColor(kBlue-10);

	if( DrawsysBfeeddown_Alice || DrawsysBfeeddown_data ) gr_vn_vnvsmass_sys_Bfeeddown->Draw("2same");

	if( Drawchargedparticle )
	{
		grSteveSPv2[8]->SetMarkerStyle(24);
		grSteveSPv2[8]->SetMarkerColor(1.0);
		grSteveSPv2[8]->SetLineColor(1.0);
		grSteveSPv2[8]->SetMarkerSize(1);

		grSteveSPv2[9]->SetMarkerStyle(24);
		grSteveSPv2[9]->SetMarkerColor(1.0);
		grSteveSPv2[9]->SetLineColor(1.0);
		grSteveSPv2[9]->SetMarkerSize(1);

		grSteveSPv2[10]->SetMarkerStyle(24);
		grSteveSPv2[10]->SetMarkerColor(1.0);
		grSteveSPv2[10]->SetLineColor(1.0);
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

	for( int ibin = 0; ibin < gr_vn_vnvsmass_SP_sys->GetN(); ibin++)
		gr_vn_vnvsmass_SP_sys->GetEX()[ibin] = 0.5;

    gr_vn_vnvsmass_SP_sys->SetMarkerColor(4.0);
    gr_vn_vnvsmass_SP_sys->SetMarkerStyle(21);
    gr_vn_vnvsmass_SP_sys->SetLineWidth(0);
    gr_vn_vnvsmass_SP_sys->SetFillStyle(0);
    gr_vn_vnvsmass_SP_sys->SetLineColor(4.0);

	gr_vn_vnvsmass_SP_sys->Draw("2same");
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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_finalcombinedfit_vnvsmass_%s_%s_SP_cent%dto%d_charged%d_Bfeeddownsys_Alice%d_data%d_%s_effcorrected0.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, Drawchargedparticle, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data, fitoption.Data()));
}
