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

#include <./../parameters.h>
#include <./../uti.h>
#include <./../EP_resolution.h>

void Draw_vn_morephibin( TString inputfilename = "rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_poly3bkg_effcorrected0.root", TString trigname = "MBtrig", int cent_low = 0, int cent_high = 10, int iptstart = 4, int iptend = 5, TString fitoption = "poly3bkg", bool effcorrected = false, bool isMC = false)
{
	TH1::SetDefaultSumw2();
	gStyle->SetHistMinimumZero(kFALSE);
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	Initiate_EPSPresolution();

	void Fit_dNdpt_phibins_in_oneptbin( int ipt, TH1D * dNdpt_phibins_in_oneptbin, TH1D * vn_morephibin, TString trigname, TString vnname, int cent_low, int cent_high, TString fitoption, bool effcorrected);
	void Get_vn_morephibin( TH1D * vn_morephibin, TH1D * dNdpt_phibins_in_oneptbin[], double EPresolution, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, int iptstart = 2, int iptend = 5, TString fitoption = "poly3bkg", bool effcorrected = false);

	//decide event plane resolution
	double resolution_EP_v1 = 1., resolution_EP_v2 = 1., resolution_EP_v3 = 1., resolution_EP_v4 = 1.;
	int icentbin = Decide_centbin_for_EPresolution( cent_low, cent_high, isMC);
	if( icentbin != -99 )
	{
		if( !isMC )
		{
			resolution_EP_v2 = (EPm_resolution_v2_etagap[0][icentbin] + EPp_resolution_v2_etagap[0][icentbin]) / 2.0;
			resolution_EP_v3 = (EPm_resolution_v3_etagap[0][icentbin] + EPp_resolution_v3_etagap[0][icentbin]) / 2.0;
		}
		else
		{
			resolution_EP_v2 = (EPm_resolution_v2_MC[icentbin] + EPp_resolution_v2_MC[icentbin]) / 2.0;
			resolution_EP_v3 = (EPm_resolution_v3_MC[icentbin] + EPp_resolution_v3_MC[icentbin]) / 2.0;
		}
	}
	cout << "EP resolution, v1: " << resolution_EP_v1 << " v2: " << resolution_EP_v2 << " v3: " << resolution_EP_v3 << " v4: " << resolution_EP_v4 << endl;

	TFile * inputdata = new TFile(inputfilename);

	TH1D * dNdpt_v2_phibins_in_oneptbin[Nptbin];
	TH1D * dNdpt_v3_phibins_in_oneptbin[Nptbin];
	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_phibins_in_oneptbin[ipt] = (TH1D *) inputdata->Get(Form("dNdpt_v2_%s_phibins_in_oneptbin_%d", fitoption.Data(), ipt));
		dNdpt_v3_phibins_in_oneptbin[ipt] = (TH1D *) inputdata->Get(Form("dNdpt_v3_%s_phibins_in_oneptbin_%d", fitoption.Data(), ipt));
	}

	TH1D * v2_morephibin = new TH1D( "v2_morephibin", "v2_morephibin", Nptbin,ptbins);
	TH1D * v3_morephibin = new TH1D( "v3_morephibin", "v3_morephibin", Nptbin,ptbins);
	v2_morephibin->Sumw2();
	v3_morephibin->Sumw2();

	Get_vn_morephibin( v2_morephibin, dNdpt_v2_phibins_in_oneptbin, resolution_EP_v2, trigname, "v2", "v_{2}", cent_low, cent_high, iptstart, iptend, fitoption, effcorrected);
	Get_vn_morephibin( v3_morephibin, dNdpt_v3_phibins_in_oneptbin, resolution_EP_v3, trigname, "v3", "v_{3}", cent_low, cent_high, iptstart, iptend, fitoption, effcorrected);

	TFile * output = new TFile(Form("rootfiles/vn_morephibin_%s_cent%dto%d_%s_effcorrected%d.root", trigname.Data(), cent_low, cent_high, fitoption.Data(), effcorrected),"RECREATE");

	v2_morephibin->Write();
	v3_morephibin->Write();

	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_phibins_in_oneptbin[ipt]->Write();
		dNdpt_v3_phibins_in_oneptbin[ipt]->Write();
	}

	output->Close();
}

void Get_vn_morephibin( TH1D * vn_morephibin, TH1D * dNdpt_phibins_in_oneptbin[], double EPresolution, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 30, int cent_high = 50, int iptstart = 2, int iptend = 5, TString fitoption = "poly3bkg", bool effcorrected = false) 
{
	void Fit_dNdpt_phibins_in_oneptbin( int ipt, TH1D * dNdpt_phibins_in_oneptbin, TH1D * vn_morephibin, TString trigname, TString vnname, int cent_low, int cent_high, TString fitoption, bool effcorrected);
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		Fit_dNdpt_phibins_in_oneptbin( ipt, dNdpt_phibins_in_oneptbin[ipt], vn_morephibin, trigname, vnname, cent_low, cent_high, fitoption, effcorrected);
	}

	vn_morephibin->Scale( 1.0/EPresolution);

    TCanvas * cfg_vn = new TCanvas(Form("cfg_%s_%s", trigname.Data(), vnname.Data()));

    if( cent_low == 0 && cent_high == 10 ) 
    {   
        vn_morephibin->SetBinContent( vn_morephibin->FindBin(1.5), 3 );
        vn_morephibin->SetBinError( vn_morephibin->FindBin(1.5), 0 );
    }   

    //vn_morephibin->GetXaxis()->SetRangeUser(ptbins[iptstart]+0.05, ptbins[iptend]-0.05);
    vn_morephibin->GetXaxis()->SetRangeUser(0+0.05, ptbins[iptend]-0.05);
    vn_morephibin->GetYaxis()->SetRangeUser(-0.2, 0.4);
    vn_morephibin->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    vn_morephibin->GetYaxis()->SetTitle(Ytitle);
	vn_morephibin->GetYaxis()->CenterTitle();
	vn_morephibin->GetXaxis()->CenterTitle();

    vn_morephibin->GetYaxis()->SetTitleSize(0.05);
    vn_morephibin->GetXaxis()->SetTitleSize(0.05);

    vn_morephibin->SetMarkerColor(2.0);
    vn_morephibin->SetMarkerStyle(20);
    vn_morephibin->SetMarkerSize(1.0);
    vn_morephibin->SetLineColor(2.0);
    vn_morephibin->Draw();

    TLatex Tl; 
    Tl.SetNDC();
    Tl.SetTextAlign(12);
    Tl.SetTextSize(0.05);
    Tl.SetTextFont(42);
    Tl.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
    Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

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

    cfg_vn->SaveAs(Form("Plots_vn/cfg_morephibin_%s_%s_cent%dto%d_%s_effcorrected%d.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, fitoption.Data(), effcorrected));
}

void Fit_dNdpt_phibins_in_oneptbin( int ipt, TH1D * dNdpt_phibins_in_oneptbin, TH1D * vn_morephibin, TString trigname, TString vnname, int cent_low, int cent_high, TString fitoption, bool effcorrected)
{
	divideBinWidth( dNdpt_phibins_in_oneptbin );
	double phirange = -999;
	if( vnname == "v2" )  phirange = PI/2.;
	else if( vnname == "v3" ) phirange = PI/3.;

	TCanvas * cfg = new TCanvas(Form("cfg_fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), Form("cfg_fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), 600, 600);
	cfg->SetLeftMargin(0.20);

	TF1 * fit_dNdpt_phibins_in_oneptbin = NULL;
	if( vnname == "v2" ) 
		fit_dNdpt_phibins_in_oneptbin = new TF1( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "[0] * (1.0 + 2.0 * [1] * cos( 2.0 * x ) )", 0, phirange);
	else if( vnname == "v3" )
		fit_dNdpt_phibins_in_oneptbin = new TF1( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "[0] * (1.0 + 2.0 * [1] * cos( 3.0 * x ) )", 0, phirange);

	fit_dNdpt_phibins_in_oneptbin->SetLineColor(2.0);
	fit_dNdpt_phibins_in_oneptbin->SetLineStyle(2);

	dNdpt_phibins_in_oneptbin->Fit( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "I q", "", 0, phirange);
	dNdpt_phibins_in_oneptbin->Fit( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "I q", "", 0, phirange);
	dNdpt_phibins_in_oneptbin->Fit( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "I q", "", 0, phirange);
	dNdpt_phibins_in_oneptbin->Fit( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "I q m", "", 0, phirange);
	dNdpt_phibins_in_oneptbin->Fit( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "I q m", "", 0, phirange);
	dNdpt_phibins_in_oneptbin->Fit( Form("fit_dNdpt_phibins_in_oneptbin_%s_%d", (trigname+vnname).Data(), ipt), "I m", "", 0, phirange);

	dNdpt_phibins_in_oneptbin->GetXaxis()->SetTitle("#Delta#Phi");
	dNdpt_phibins_in_oneptbin->GetYaxis()->SetTitle("#frac{d^{2}N}{dp_{T}d#Delta#Phi}");
	dNdpt_phibins_in_oneptbin->GetYaxis()->SetTitleOffset(2.0);

	vn_morephibin->SetBinContent( ipt+1, fit_dNdpt_phibins_in_oneptbin->GetParameter(1));
	vn_morephibin->SetBinError( ipt+1, fit_dNdpt_phibins_in_oneptbin->GetParError(1));

    TLatex Tl; 
    Tl.SetNDC();
    Tl.SetTextAlign(12);
    Tl.SetTextSize(0.05);
    Tl.SetTextFont(42);
    Tl.DrawLatex(0.20,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
    Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	TLatex* tex;
	tex = new TLatex(0.55,0.83,"|y| < 1.0");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.55,0.78,Form("Cent. %d-%d%%", cent_low, cent_high));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	float ptmin = ptbins[ipt];
	float ptmax = ptbins[ipt+1];

	tex = new TLatex(0.55,0.73,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	if( vnname == "v2" ) 
		tex = new TLatex(0.55,0.68,Form("v_{2}^{obs} = %.3f #pm %.3f",fit_dNdpt_phibins_in_oneptbin->GetParameter(1), fit_dNdpt_phibins_in_oneptbin->GetParError(1)));
	else if( vnname == "v3" )
		tex = new TLatex(0.55,0.68,Form("v_{3}^{obs} = %.3f #pm %.3f",fit_dNdpt_phibins_in_oneptbin->GetParameter(1), fit_dNdpt_phibins_in_oneptbin->GetParError(1)));

	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	float fitchi2 = fit_dNdpt_phibins_in_oneptbin->GetChisquare();
    int NDFfit = fit_dNdpt_phibins_in_oneptbin->GetNDF();

    tex = new TLatex(0.55,0.63,Form("#chi^{2}#/NDF: %.1f/%d", fitchi2, NDFfit));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
//	tex->Draw();
	
	cfg->SaveAs(Form("Plots_vn/fitmorephibin/cfg_fit_dNdpt_phibins_in_oneptbin_%s_cent%dto%d_%d_%s_effcorrected%d.pdf", (trigname+vnname).Data(), cent_low, cent_high, ipt, fitoption.Data(), effcorrected));
	cfg->SaveAs(Form("Plots_vn/fitmorephibin/cfg_fit_dNdpt_phibins_in_oneptbin_%s_cent%dto%d_%d_%s_effcorrected%d.png", (trigname+vnname).Data(), cent_low, cent_high, ipt, fitoption.Data(), effcorrected));
}
