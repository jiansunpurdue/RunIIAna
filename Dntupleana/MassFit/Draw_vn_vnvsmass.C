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

void Draw_vn_vnvsmass(TString inputfilename = "rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_poly3bkg.root", TString MBorDtrig = "MBtrig", TString EPorSP = "SP", int cent_low = 30, int cent_high = 50, double ptlow = 0.0, double pthigh = 45.0, TString fitoption = "poly3bkg", bool get_staterror_signalfraction = false, TString inputfilename_staterrorfraction = "rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_poly3bkg_staterrsigfrfunc.root")
{
	void Draw_vn( TH1D * h_vn_pt, TString MBorDtrig = "MBtrig", TString EPorSP = "EP", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, TString fitoption = "poly3bkg");
	void Get_vn_pt_staterror_signalfraction( TH1D * h_vn_pt_staterror_signalfraction, TH1D * h_vn_toyMC_oneptbin[], TString MBorDtrig, TString EPorSP, TString vnname, int cent_low, int cent_high, int iptstart, int iptend, TString fitoption);
	void Combine_staterror( TH1D * h_vn_pt, TH1D * h_vn_pt_nostaterror_signalfraction, TH1D * h_vn_pt_staterror_signalfraction, int iptstart, int iptend);
	void Get_errorratio_signalfractiononly_over_no( TH1D * h_vn_pt_errorratio_signalfraction_over_no, TH1D * h_vn_pt_nostaterror_signalfraction, TH1D * h_vn_pt_staterror_signalfraction, int iptstart, int iptend, TString MBorDtrig, TString EPorSP, TString vnname, int cent_low, int cent_high);

	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * inputdata = new TFile(inputfilename);

	TH1D * h_v1_pt = (TH1D *) inputdata->Get("h_v1_pt");
	TH1D * h_v2_pt = (TH1D *) inputdata->Get("h_v2_pt");
	TH1D * h_v3_pt = (TH1D *) inputdata->Get("h_v3_pt");
	TH1D * h_v4_pt = (TH1D *) inputdata->Get("h_v4_pt");

	TFile * inputdata_staterror_signalfraction = NULL;
	TH1D * h_v2_toyMC_oneptbin[Nptbin];
	TH1D * h_v3_toyMC_oneptbin[Nptbin];
	TH1D * h_v2_pt_staterror_signalfraction = NULL;//save mean and sigma from fit
	TH1D * h_v3_pt_staterror_signalfraction = NULL;
	TH1D * h_v2_pt_nostaterror_signalfraction = NULL;
	TH1D * h_v3_pt_nostaterror_signalfraction = NULL;
	TH1D * h_v2_pt_errorratio_signalfraction_over_no = NULL;
	TH1D * h_v3_pt_errorratio_signalfraction_over_no = NULL;

	if( get_staterror_signalfraction && fitoption == "poly3bkg")
	{
		inputdata_staterror_signalfraction = new TFile(inputfilename_staterrorfraction);

		int iptstart = 2;//should be fixed later. Now hard coded
		int iptend = 12;
		for( int ipt = iptstart; ipt < iptend; ipt++ )
		{
			h_v2_toyMC_oneptbin[ipt] = (TH1D *) inputdata_staterror_signalfraction->Get(Form("h_v2_toyMC_oneptbin_%d", ipt));
			h_v3_toyMC_oneptbin[ipt] = (TH1D *) inputdata_staterror_signalfraction->Get(Form("h_v3_toyMC_oneptbin_%d", ipt));
		}

		h_v2_pt_staterror_signalfraction = (TH1D *) h_v2_pt->Clone("h_v2_pt_staterror_signalfraction");
		h_v3_pt_staterror_signalfraction = (TH1D *) h_v3_pt->Clone("h_v3_pt_staterror_signalfraction");
		h_v2_pt_nostaterror_signalfraction = (TH1D *) h_v2_pt->Clone("h_v2_pt_nostaterror_signalfraction");
		h_v3_pt_nostaterror_signalfraction = (TH1D *) h_v3_pt->Clone("h_v3_pt_nostaterror_signalfraction");
		h_v2_pt_errorratio_signalfraction_over_no = (TH1D *) h_v2_pt->Clone("h_v2_pt_errorratio_signalfraction_over_no");
		h_v3_pt_errorratio_signalfraction_over_no = (TH1D *) h_v3_pt->Clone("h_v3_pt_errorratio_signalfraction_over_no");

		Get_vn_pt_staterror_signalfraction( h_v2_pt_staterror_signalfraction, h_v2_toyMC_oneptbin, MBorDtrig, EPorSP, "v2", cent_low, cent_high, iptstart, iptend, fitoption);
		Get_vn_pt_staterror_signalfraction( h_v3_pt_staterror_signalfraction, h_v3_toyMC_oneptbin, MBorDtrig, EPorSP, "v3", cent_low, cent_high, iptstart, iptend, fitoption);

		Combine_staterror( h_v2_pt, h_v2_pt_nostaterror_signalfraction, h_v2_pt_staterror_signalfraction, iptstart, iptend);
		Combine_staterror( h_v3_pt, h_v3_pt_nostaterror_signalfraction, h_v3_pt_staterror_signalfraction, iptstart, iptend);

		Get_errorratio_signalfractiononly_over_no( h_v2_pt_errorratio_signalfraction_over_no, h_v2_pt_nostaterror_signalfraction, h_v2_pt_staterror_signalfraction, iptstart, iptend, MBorDtrig, EPorSP, "v2", cent_low, cent_high);
		Get_errorratio_signalfractiononly_over_no( h_v3_pt_errorratio_signalfraction_over_no, h_v3_pt_nostaterror_signalfraction, h_v3_pt_staterror_signalfraction, iptstart, iptend, MBorDtrig, EPorSP, "v3", cent_low, cent_high);
	}

	//	Draw_vn( h_v1_pt, MBorDtrig, EPorSP, "v1_"+EPorSP, Form("v_{1}{%s}", EPorSP.Data()), cent_low, cent_high, ptlow, pthigh);
	Draw_vn( h_v2_pt, MBorDtrig, EPorSP, "v2_"+EPorSP, "v_{2}", cent_low, cent_high, ptlow, pthigh, fitoption);
	Draw_vn( h_v3_pt, MBorDtrig, EPorSP, "v3_"+EPorSP, "v_{3}", cent_low, cent_high, ptlow, pthigh, fitoption);
	//	Draw_vn( h_v4_pt, MBorDtrig, EPorSP, "v4_"+EPorSP, Form("v_{4}{%s}", EPorSP.Data()), cent_low, cent_high, ptlow, pthigh);

	TFile * output = new TFile(Form("rootfiles/vn_vnvsmass_%s_%s_cent%dto%d_%s.root", MBorDtrig.Data(), EPorSP.Data(), cent_low, cent_high, fitoption.Data()),"RECREATE");

	h_v1_pt->Write();
	h_v2_pt->Write();
	h_v3_pt->Write();
	h_v4_pt->Write();

	if( get_staterror_signalfraction && fitoption == "poly3bkg")
	{
		h_v2_pt_staterror_signalfraction->Write();
		h_v3_pt_staterror_signalfraction->Write();
		h_v2_pt_nostaterror_signalfraction->Write();
		h_v3_pt_nostaterror_signalfraction->Write();
		h_v2_pt_errorratio_signalfraction_over_no->Write();
		h_v3_pt_errorratio_signalfraction_over_no->Write();
	}

	output->Close();
}

void Draw_vn( TH1D * h_vn_pt, TString MBorDtrig = "MBtrig", TString EPorSP = "EP", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, TString fitoption = "poly3bkg")
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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_vnvsmass_%s_%s_cent%dto%d_%s.pdf", MBorDtrig.Data(), vnname.Data(), cent_low, cent_high, fitoption.Data()));
}

void Get_vn_pt_staterror_signalfraction( TH1D * h_vn_pt_staterror_signalfraction, TH1D * h_vn_toyMC_oneptbin[], TString MBorDtrig, TString EPorSP, TString vnname, int cent_low, int cent_high, int iptstart, int iptend, TString fitoption)
{
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		TCanvas * cfg_fit_staterror_signalfraction = new TCanvas( Form("cfg_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), Form("cfg_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), 600, 600);
		float vn_mean = h_vn_pt_staterror_signalfraction->GetBinContent( ipt+1 );
		float v3_staterror = h_vn_pt_staterror_signalfraction->GetBinError( ipt+1 );

		float fitrangelow;
		float fitrangehigh;
		if( vnname == "v2" )
		{
			fitrangelow = vn_mean - 0.4 * v3_staterror;
			fitrangehigh = vn_mean + 0.4 * v3_staterror;
		}
		else
		{
			fitrangelow = vn_mean - 0.2 * v3_staterror;
			fitrangehigh = vn_mean + 0.2 * v3_staterror;
		}

		cout << "ipt: " << ipt << "  vn_mean: " << vn_mean << "  v3_staterror: " << v3_staterror << endl;

		TF1 * fit = new TF1( Form("f_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), "gaus(0)", fitrangelow, fitrangehigh);
		fit->SetParameter( 0, 30.);
		fit->SetParameter( 1, vn_mean);
		fit->SetParameter( 2, 0.05 * v3_staterror);
		fit->SetLineColor(2);

		h_vn_toyMC_oneptbin[ipt]->Fit( Form("f_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), "q", "", fitrangelow, fitrangehigh);
		h_vn_toyMC_oneptbin[ipt]->Fit( Form("f_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), "L q", "", fitrangelow, fitrangehigh);
		h_vn_toyMC_oneptbin[ipt]->Fit( Form("f_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), "L q", "", fitrangelow, fitrangehigh);
		h_vn_toyMC_oneptbin[ipt]->Fit( Form("f_staterror_signalfraction_%s_%s_%d", MBorDtrig.Data(), vnname.Data(), ipt), "L m", "", fitrangelow, fitrangehigh);

		h_vn_toyMC_oneptbin[ipt]->GetXaxis()->SetRangeUser( fitrangelow, fitrangehigh);

		h_vn_pt_staterror_signalfraction->SetBinContent( ipt+1, fit->GetParameter(1));
		h_vn_pt_staterror_signalfraction->SetBinError( ipt+1, fit->GetParameter(2));

		TLatex Tl; 
		Tl.SetNDC();
		Tl.SetTextAlign(12);
		Tl.SetTextSize(0.05);
		Tl.SetTextFont(42);
		Tl.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
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
		
		cfg_fit_staterror_signalfraction->SaveAs(Form("Plots_vn/plots_fit_staterror_signalfraction/cfg_staterror_signalfraction_%s_%s_%d_%s_cent%dto%d_%s.pdf", MBorDtrig.Data(), vnname.Data(), ipt, EPorSP.Data(), cent_low, cent_high, fitoption.Data()));
	}
}
void Combine_staterror( TH1D * h_vn_pt, TH1D * h_vn_pt_nostaterror_signalfraction, TH1D * h_vn_pt_staterror_signalfraction, int iptstart, int iptend)
{
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		h_vn_pt->SetBinError( ipt+1, TMath::Sqrt( h_vn_pt_nostaterror_signalfraction->GetBinError(ipt+1) * h_vn_pt_nostaterror_signalfraction->GetBinError(ipt+1) + h_vn_pt_staterror_signalfraction->GetBinError(ipt+1) * h_vn_pt_staterror_signalfraction->GetBinError(ipt+1) ));
	}
}

void Get_errorratio_signalfractiononly_over_no( TH1D * h_vn_pt_errorratio_signalfraction_over_no, TH1D * h_vn_pt_nostaterror_signalfraction, TH1D * h_vn_pt_staterror_signalfraction, int iptstart, int iptend, TString MBorDtrig, TString EPorSP, TString vnname, int cent_low, int cent_high)
{
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		h_vn_pt_errorratio_signalfraction_over_no->SetBinContent( ipt+1, h_vn_pt_staterror_signalfraction->GetBinError(ipt+1) / h_vn_pt_nostaterror_signalfraction->GetBinError(ipt+1) );
		h_vn_pt_errorratio_signalfraction_over_no->SetBinError( ipt+1, 0.0);
	}
	
	TCanvas * cfg_errorratio_signalfractiononly_over_no = new TCanvas( Form("cfg_errorratio_signalfractiononly_over_no_%s_%s_cent%dto%d", MBorDtrig.Data(), vnname.Data(), cent_low, cent_high), Form("cfg_errorratio_signalfractiononly_over_no_%s_%s_cent%dto%d", MBorDtrig.Data(), vnname.Data(), cent_low, cent_high), 600, 600);

    h_vn_pt_errorratio_signalfraction_over_no->GetXaxis()->SetRangeUser(0.+0.05, 38.-0.05);
    h_vn_pt_errorratio_signalfraction_over_no->GetYaxis()->SetRangeUser(0.0, 0.3);
    h_vn_pt_errorratio_signalfraction_over_no->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
    h_vn_pt_errorratio_signalfraction_over_no->GetYaxis()->SetTitle("Error Ratio");

    h_vn_pt_errorratio_signalfraction_over_no->GetYaxis()->SetTitleSize(0.05);
    h_vn_pt_errorratio_signalfraction_over_no->GetXaxis()->SetTitleSize(0.05);
	
	h_vn_pt_errorratio_signalfraction_over_no->Draw("hist");
	h_vn_pt_errorratio_signalfraction_over_no->Draw("psame");
	
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

	cfg_errorratio_signalfractiononly_over_no->SaveAs(Form("Plots_vn/plots_fit_staterror_signalfraction/cfg_errorratio_signalfractiononly_over_no_%s_%s_cent%dto%d.pdf", MBorDtrig.Data(), vnname.Data(), cent_low, cent_high));
}
