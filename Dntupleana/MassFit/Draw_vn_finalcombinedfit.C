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

#include <./SetChargedparticle_vn.C>
#include <./Systematics.h>
#include <./Set_theoryD.C>

void Draw_vn_finalcombinedfit(TString input_vnvmass_SP = "rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 40.0, bool Drawchargedparticle = true, TString fitoption = "poly3bkg_floatwidth", TString input_promptD0fraction = "promptD0_totaluncertainties/Fractionchange_ratioband_cent30to50.root", bool DrawsysBfeeddown_Alice = false, bool DrawsysBfeeddown_data = true, bool Drawtheory = true)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	Getchargedparticle( cent_low, cent_high );
	Set_theoryD();

	void CalculateBfeeddownError( TH1D * h_promptf_totaluncertainties, TGraphAsymmErrors * gr_vn_pt_sys_Bfeeddown);
	void Drawfinalcombinedfit(TH1D * vn_vnvsmass_SP, TGraphErrors * gr_vn_vnvsmass_SP_sys, TGraphAsymmErrors * gr_vn_vnvsmass_sys_Bfeeddown, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg", bool DrawsysBfeeddown_Alice = false, bool DrawsysBfeeddown_data = false, bool Drawtheory = false);

	//theory predictions
//	TFile * input_CUJET3 = new TFile("TheoryCalculation/CUJet3p0/PredictionsCUJET3_Dv2_pt.root");
//	TGraphAsymmErrors * gv2Dmeson5TeV_CUJET3 = ( TGraphAsymmErrors *) input_CUJET3->Get(Form("gv2Dmeson5TeV_CUJET3_cent%dto%d",cent_low,cent_high));
//	gv2Dmeson5TeV_CUJET3->SetName("gv2Dmeson5TeV_CUJET3");
	//end theory predictions

	TFile * inputdata_promptD0fraction = new TFile(input_promptD0fraction);
	TH1D * h_promptf_totaluncertainties = (TH1D *) inputdata_promptD0fraction->Get("h_promptf_totaluncertainties_DCAcut");

	TFile * inputdata_vnvsmass_SP = new TFile(input_vnvmass_SP);

	TH1D * h_v2_pt = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt");
	TH1D * h_v3_pt = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt");
	h_v2_pt->SetName("h_v2_pt"); h_v2_pt->SetTitle("h_v2_pt");
	h_v3_pt->SetName("h_v3_pt"); h_v3_pt->SetTitle("h_v3_pt");

	//fill histogram for sys
	TH1D * h_v2_pt_sys = (TH1D *) h_v2_pt->Clone("h_v2_pt_sys");
	TH1D * h_v3_pt_sys = (TH1D *) h_v3_pt->Clone("h_v3_pt_sys");
	h_v2_pt_sys->SetName("h_v2_pt_sys"); h_v2_pt_sys->SetTitle("h_v2_pt_sys");
	h_v3_pt_sys->SetName("h_v3_pt_sys"); h_v3_pt_sys->SetTitle("h_v3_pt_sys");

    TH1D * h_v2_pt_relativesys = new TH1D("h_v2_pt_relativesys", "h_v2_pt_relativesys", Nptbin, ptbins);
    TH1D * h_v3_pt_relativesys = new TH1D("h_v3_pt_relativesys", "h_v3_pt_relativesys", Nptbin, ptbins);

    if( fitoption == "poly3bkg_floatwidth" )
    {   
        Calculatetotalsys( cent_low, cent_high, ptlow, pthigh, "SP", "v2", h_v2_pt, h_v2_pt_sys, h_v2_pt_relativesys);
        Calculatetotalsys( cent_low, cent_high, ptlow, pthigh, "SP", "v3", h_v3_pt, h_v3_pt_sys, h_v3_pt_relativesys);
		h_v2_pt_sys->SetBinContent( 1, 3 );
		h_v2_pt_sys->SetBinContent( 2, 3 );
		h_v3_pt_sys->SetBinContent( 1, 3 );
		h_v3_pt_sys->SetBinContent( 2, 3 );
    }
	//end fill histogram for sys

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

	Drawfinalcombinedfit( h_v2_pt, gr_v2_pt_sys, gr_v2_pt_sys_Bfeeddown, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh, Drawchargedparticle, fitoption, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data, Drawtheory);

	Drawfinalcombinedfit( h_v3_pt, gr_v3_pt_sys, gr_v3_pt_sys_Bfeeddown, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh, Drawchargedparticle, fitoption, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data, Drawtheory);

	TFile * output = new TFile(Form("rootfiles/vn_finalcombinedfit_vnvsmass_%s_SP_cent%dto%d_%s_Bfeeddownsys_Alice%d_data%d_effcorrected0.root", trigname.Data(), cent_low, cent_high, fitoption.Data(), DrawsysBfeeddown_Alice, DrawsysBfeeddown_data),"RECREATE");
	h_v2_pt->Write();
	h_v3_pt->Write();
	gr_v2_pt_sys->Write();
	gr_v3_pt_sys->Write();
	gr_v2_pt_sys_Bfeeddown->Write();
	gr_v3_pt_sys_Bfeeddown->Write();
	h_v2_pt_sys->Write();
	h_v3_pt_sys->Write();
	h_v2_pt_relativesys->Write();
	h_v3_pt_relativesys->Write();
//	gv2Dmeson5TeV_CUJET3->Write();
	grSteveSPv2_chargeparticle->Write();
	grSteveSPv2_sys_chargeparticle->Write();
	grSteveSPv3_chargeparticle->Write();
	grSteveSPv3_sys_chargeparticle->Write();
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

void Drawfinalcombinedfit(TH1D * vn_vnvsmass_SP, TGraphErrors * gr_vn_vnvsmass_SP_sys, TGraphAsymmErrors * gr_vn_vnvsmass_sys_Bfeeddown, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false, TString fitoption = "poly3bkg", bool DrawsysBfeeddown_Alice = false, bool DrawsysBfeeddown_data = false, bool Drawtheory = false)
{
	int theoryindex = 99;
	if( cent_low == 0 && cent_high == 10 ) theoryindex = 0;
	if( cent_low == 10 && cent_high == 30 ) theoryindex = 1;
	if( cent_low == 30 && cent_high == 50 ) theoryindex = 2;

	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));

	vn_vnvsmass_SP->GetYaxis()->SetTitleOffset(1.2);
	vn_vnvsmass_SP->GetYaxis()->SetRangeUser(-0.18,0.295);

	vn_vnvsmass_SP->SetLineColor(kRed+1);
	vn_vnvsmass_SP->SetMarkerColor(kRed+1);
	vn_vnvsmass_SP->SetLineWidth(0);
	vn_vnvsmass_SP->SetMarkerSize(0.8);
	
	vn_vnvsmass_SP->Draw();

    gr_vn_vnvsmass_sys_Bfeeddown->SetMarkerColor(kRed+1);
    gr_vn_vnvsmass_sys_Bfeeddown->SetMarkerStyle(20);
    gr_vn_vnvsmass_sys_Bfeeddown->SetLineWidth(0);
    gr_vn_vnvsmass_sys_Bfeeddown->SetFillStyle(1001);
	gr_vn_vnvsmass_sys_Bfeeddown->SetFillColor(kRed-9);
    gr_vn_vnvsmass_sys_Bfeeddown->SetLineColor(kRed-9);

	if( DrawsysBfeeddown_Alice || DrawsysBfeeddown_data ) gr_vn_vnvsmass_sys_Bfeeddown->Draw("2same");

	if( Drawtheory && vnname == "v2" ) 
	{
		gv2Dmeson5TeV_CUJET3[theoryindex]->SetLineWidth(3);
		gv2Dmeson5TeV_TAMU[theoryindex]->SetLineWidth(3);
		gv2Dmeson5TeV_LBT[theoryindex]->SetLineWidth(3);
		gv2Dmeson5TeV_LPang[theoryindex]->SetLineWidth(3);

		gv2Dmeson5TeV_CUJET3[theoryindex]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[theoryindex]->Draw("CXsame");
		gv2Dmeson5TeV_TAMU[theoryindex]->Draw("3same");
		gv2Dmeson5TeV_TAMU[theoryindex]->Draw("CXsame");
		gv2Dmeson5TeV_LBT[theoryindex]->Draw("Csame");
		gv2Dmeson5TeV_LPang[theoryindex]->Draw("Csame");
	}

	if( Drawtheory && vnname == "v3" ) 
	{
		gv3Dmeson5TeV_LBT[theoryindex]->SetLineWidth(3);
		gv3Dmeson5TeV_LBT[theoryindex]->Draw("Csame");
	}

	if( Drawchargedparticle && vnname == "v2" )
	{
		grSteveSPv2_sys_chargeparticle->Draw("2same");
		grSteveSPv2_chargeparticle->Draw("psame");
	}

	if( Drawchargedparticle && vnname == "v3" )
	{
		grSteveSPv3_sys_chargeparticle->Draw("2same");
		grSteveSPv3_chargeparticle->Draw("psame");
	}

	for( int ibin = 0; ibin < gr_vn_vnvsmass_SP_sys->GetN(); ibin++)
		gr_vn_vnvsmass_SP_sys->GetEX()[ibin] = 0.5;

    gr_vn_vnvsmass_SP_sys->SetMarkerColor(kRed+1);
    gr_vn_vnvsmass_SP_sys->SetMarkerStyle(20);
    //gr_vn_vnvsmass_SP_sys->SetLineWidth(1);
    gr_vn_vnvsmass_SP_sys->SetLineWidth(0);//hard probes
    gr_vn_vnvsmass_SP_sys->SetFillStyle(0);
    gr_vn_vnvsmass_SP_sys->SetLineColor(kRed+1);

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
		if( vnname == "v2" ) leg->AddEntry(grSteveSPv2_chargeparticle, "Charged particle", "p");
		if( vnname == "v3" ) leg->AddEntry(grSteveSPv3_chargeparticle, "Charged particle", "p");
		leg->AddEntry((TObject*)0, "#scale[0.7]{CMS-PAS-HIN-15-014}", "");

		leg->SetBorderSize(0);
		leg->SetFillStyle(0);
		leg->Draw();
	}

//	if( Drawchargedparticle && Drawtheory )
//	{
//		TLegend * leg = new TLegend(0.50, 0.65, 0.70, 0.87);
//		leg->SetTextSize(0.05);
//		leg->SetTextFont(42);
//		leg->AddEntry(vn_vnvsmass_SP, "D^{0}");
//		leg->AddEntry(gv2Dmeson5TeV_CUJET3, "D^{0} CUJET3", "l");
//		if( vnname == "v2" ) leg->AddEntry(grSteveSPv2_chargeparticle, "Charged particle", "p");
//		if( vnname == "v3" ) leg->AddEntry(grSteveSPv3_chargeparticle, "Charged particle", "p");
//		leg->AddEntry((TObject*)0, "#scale[0.7]{CMS-PAS-HIN-15-014}", "");
//
//		leg->SetBorderSize(0);
//		leg->SetFillStyle(0);
//		leg->Draw();
//	}

	TLatex* tex;
	tex = new TLatex(0.22,0.83,"|y| < 1.0");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.22,0.88,Form("Cent. %d-%d%%", cent_low, cent_high));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetLineWidth(2);
	tex->Draw();
	
	if( DrawsysBfeeddown_Alice || DrawsysBfeeddown_data )
	{
		tex = new TLatex(0.3,0.22,"Filled box: syst. from non-prompt D^{0}");
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.035);
		tex->SetLineWidth(2);
		tex->Draw();

		tex = new TLatex(0.3,0.17,"Open box: other syst.");
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.035);
		tex->SetLineWidth(2);
		tex->Draw();
	}

	if( Drawtheory && vnname == "v2" ) 
	{
        TLatex Ttheory;
        Ttheory.SetTextFont(42);
        Ttheory.SetTextSize(0.04);
        Ttheory.SetNDC();
        Ttheory.DrawLatex(0.3, 0.39, "Theory prediction for prompt D");

        TLegend * leg1 = new TLegend(0.30, 0.27, 0.60, 0.37);
        leg1->SetTextSize(0.04);
        leg1->SetTextFont(42);
        leg1->AddEntry(gv2Dmeson5TeV_LBT[0], "LBT", "l");
        leg1->AddEntry(gv2Dmeson5TeV_TAMU[0], "TAMU", "l");
        leg1->SetBorderSize(0);
        leg1->SetFillStyle(0);
        leg1->Draw();

        TLegend * leg2 = new TLegend(0.55, 0.27, 0.85, 0.37);
        leg2->SetTextSize(0.04);
        leg2->SetTextFont(42);
		leg2->AddEntry(gv2Dmeson5TeV_LPang[0], "L. Pang", "l");
        leg2->AddEntry(gv2Dmeson5TeV_CUJET3[0], "CUJET3", "l");
        leg2->SetBorderSize(0);
        leg2->SetFillStyle(0);
        leg2->Draw();
	}

	if( Drawtheory && vnname == "v3" ) 
	{
        TLatex Ttheory;
        Ttheory.SetTextFont(42);
        Ttheory.SetTextSize(0.04);
        Ttheory.SetNDC();
        Ttheory.DrawLatex(0.3, 0.35, "Theory prediction for prompt D");

        TLegend * leg1 = new TLegend(0.30, 0.27, 0.60, 0.33);
        leg1->SetTextSize(0.04);
        leg1->SetTextFont(42);
        leg1->AddEntry(gv2Dmeson5TeV_LBT[0], "LBT", "l");
        leg1->SetBorderSize(0);
        leg1->SetFillStyle(0);
        leg1->Draw();
	}

	TF1 * fun = new TF1("fun", "0.0", 0, 100);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(1);
	fun->Draw("same");

	cfg_vn->SaveAs(Form("Plots_vn/cfg_finalcombinedfit_vnvsmass_%s_%s_SP_cent%dto%d_charged%d_Bfeeddownsys_Alice%d_data%d_%s_effcorrected0.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, Drawchargedparticle, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data, fitoption.Data()));
	cfg_vn->SaveAs(Form("Plots_vn/cfg_finalcombinedfit_vnvsmass_%s_%s_SP_cent%dto%d_charged%d_Bfeeddownsys_Alice%d_data%d_%s_effcorrected0.png", trigname.Data(), vnname.Data(), cent_low, cent_high, Drawchargedparticle, DrawsysBfeeddown_Alice, DrawsysBfeeddown_data, fitoption.Data()));
}
