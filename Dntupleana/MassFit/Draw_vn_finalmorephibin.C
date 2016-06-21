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

#include <./Systematics.h>

void Draw_vn_finalmorephibin(TString input_morephibin = "rootfiles/vn_morephibin_MBtrig_cent30to50_poly3bkg_effcorrected0.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 40.0, TString fitoption = "poly3bkg")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	void Drawmorephibinvn(TH1D * vn_morephibin, TH1D * vn_morephibin_sys, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 40.0, TString fitoption = "poly3bkg");

	TFile * inputdata_morephibin = new TFile(input_morephibin);

	TH1D * v2_morephibin = (TH1D *) inputdata_morephibin->Get("v2_morephibin");
	TH1D * v3_morephibin = (TH1D *) inputdata_morephibin->Get("v3_morephibin");
	v2_morephibin->SetName("v2_morephibin"); v2_morephibin->SetTitle("v2_morephibin");
	v3_morephibin->SetName("v3_morephibin"); v3_morephibin->SetTitle("v3_morephibin");

    TH1D * v2_morephibin_sys = (TH1D *) v2_morephibin->Clone("v2_morephibin_sys");
    TH1D * v3_morephibin_sys = (TH1D *) v3_morephibin->Clone("v3_morephibin_sys");

    TH1D * v2_morephibin_relativesys = new TH1D("v2_morephibin_relativesys", "v2_morephibin_relativesys", Nptbin, ptbins);
    TH1D * v3_morephibin_relativesys = new TH1D("v3_morephibin_relativesys", "v3_morephibin_relativesys", Nptbin, ptbins);

    if( fitoption == "poly3bkg" )
    {
        Calculatetotalsys( cent_low, cent_high, 1.0, 40.0, "deltaphibins", "v2", v2_morephibin, v2_morephibin_sys, v2_morephibin_relativesys);
        Calculatetotalsys( cent_low, cent_high, 1.0, 40.0, "deltaphibins", "v3", v3_morephibin, v3_morephibin_sys, v3_morephibin_relativesys);
    }

	Drawmorephibinvn( v2_morephibin, v2_morephibin_sys, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh, fitoption);
	Drawmorephibinvn( v3_morephibin, v3_morephibin_sys, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh, fitoption);

	TFile * output = new TFile(Form("rootfiles/vn_finalmorephibin_%s_cent%dto%d_%s_effcorrected0.root", trigname.Data(), cent_low, cent_high, fitoption.Data()),"RECREATE");

	v2_morephibin->Write();
	v3_morephibin->Write();
	v2_morephibin_sys->Write();
	v3_morephibin_sys->Write();

	output->Close();
}

void Drawmorephibinvn(TH1D * vn_morephibin, TH1D * vn_morephibin_sys, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 40.0, TString fitoption = "poly3bkg")
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));

	vn_morephibin_sys->SetBinContent( 1, 3 );
	vn_morephibin_sys->SetBinContent( 2, 3 );
    if( cent_low == 0 && cent_high == 10 ) 
    {   
        vn_morephibin->SetBinContent( vn_morephibin->FindBin(1.5), 3 );
        vn_morephibin->SetBinError( vn_morephibin->FindBin(1.5), 0 );

        vn_morephibin_sys->SetBinContent( vn_morephibin->FindBin(1.5), 3 );
        vn_morephibin_sys->SetBinError( vn_morephibin->FindBin(1.5), 0 );
    }   

	vn_morephibin_sys->SetFillStyle(0);
	vn_morephibin_sys->SetLineColor(2.0);
	vn_morephibin_sys->SetMarkerSize(0);

	vn_morephibin->Draw();
	if( fitoption == "poly3bkg" ) vn_morephibin_sys->Draw("E2same");
	vn_morephibin->Draw("same");

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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_finalmorephibin_%s_%s_cent%dto%d_%s_effcorrected0.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, fitoption.Data()));
}
