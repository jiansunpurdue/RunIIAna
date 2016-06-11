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

void Draw_vn_combinedfit(TString inputfilename = "rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_poly3bkg.root", TString MBorDtrig = "MBtrig", TString EPorSP = "SP", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 45.0, TString fitoption = "poly3bkg", bool effcorrected = false)
{
	void Draw_vn( TH1D * h_vn_pt, TString MBorDtrig = "MBtrig", TString EPorSP = "EP", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, TString fitoption = "poly3bkg", bool effcorrected = false);

	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * inputdata = new TFile(inputfilename);

	TH1D * h_v1_pt = (TH1D *) inputdata->Get("h_v1_pt");
	TH1D * h_v2_pt = (TH1D *) inputdata->Get("h_v2_pt");
	TH1D * h_v3_pt = (TH1D *) inputdata->Get("h_v3_pt");
	TH1D * h_v4_pt = (TH1D *) inputdata->Get("h_v4_pt");

	//	Draw_vn( h_v1_pt, MBorDtrig, EPorSP, "v1_"+EPorSP, Form("v_{1}{%s}", EPorSP.Data()), cent_low, cent_high, ptlow, pthigh);
	Draw_vn( h_v2_pt, MBorDtrig, EPorSP, "v2_"+EPorSP, Form("v_{2}{%s}", EPorSP.Data()), cent_low, cent_high, ptlow, pthigh, fitoption);
	Draw_vn( h_v3_pt, MBorDtrig, EPorSP, "v3_"+EPorSP, Form("v_{3}{%s}", EPorSP.Data()), cent_low, cent_high, ptlow, pthigh, fitoption);
	//	Draw_vn( h_v4_pt, MBorDtrig, EPorSP, "v4_"+EPorSP, Form("v_{4}{%s}", EPorSP.Data()), cent_low, cent_high, ptlow, pthigh);

	TFile * output = new TFile(Form("rootfiles/vn_combinedfit_vnvsmass_%s_%s_cent%dto%d_%s_effcorrected%d.root", MBorDtrig.Data(), EPorSP.Data(), cent_low, cent_high, fitoption.Data(), effcorrected),"RECREATE");

	h_v1_pt->Write();
	h_v2_pt->Write();
	h_v3_pt->Write();
	h_v4_pt->Write();

	output->Close();
}

void Draw_vn( TH1D * h_vn_pt, TString MBorDtrig = "MBtrig", TString EPorSP = "EP", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, TString fitoption = "poly3bkg", bool effcorrected = false)
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_%s_%s", MBorDtrig.Data(), vnname.Data()));

	h_vn_pt->GetXaxis()->SetRangeUser(ptlow+0.05, pthigh-0.05);
	h_vn_pt->GetYaxis()->SetRangeUser(-0.2, 0.4);
	h_vn_pt->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
	h_vn_pt->GetYaxis()->SetTitle(Ytitle);

	h_vn_pt->GetYaxis()->SetTitleSize(0.05);
	h_vn_pt->GetXaxis()->SetTitleSize(0.05);

	if( EPorSP == "EP" )
	{
		h_vn_pt->SetMarkerColor(6.0);
		h_vn_pt->SetLineColor(6.0);
		h_vn_pt->SetMarkerStyle(22);
		h_vn_pt->SetMarkerSize(1.0);
	}
	else if( EPorSP == "SP" )
	{
		h_vn_pt->SetMarkerColor(4.0);
		h_vn_pt->SetLineColor(4.0);
		h_vn_pt->SetMarkerStyle(21);
		h_vn_pt->SetMarkerSize(1.3);
	}

	h_vn_pt->Draw();

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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_combinedfit_vnvsmass_%s_%s_cent%dto%d_%s_effcorrected%d.pdf", MBorDtrig.Data(), vnname.Data(), cent_low, cent_high, fitoption.Data(), effcorrected));
}
