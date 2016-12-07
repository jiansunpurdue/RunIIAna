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


void Draw_vn_2comparison_goldentracker(TString input_1= "rootfiles_trackeronly/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_poly3bkg_floatwidth_effcorrected0.root", TString input_vnvmass_SP = "rootfiles_golden/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_poly3bkg_floatwidth_effcorrected0.root", TString input_v2_1name = "h_v2_pt", TString input_v3_1name = "h_v3_pt", TString input_v2_2name = "h_v2_pt", TString input_v3_2name = "h_v3_pt", TString str_legend1 = "Tracker only", TString str_legend2 = "Golden", TString cfgname = "SP_golden_trackeronly", TString trigname = "MBtrig", int cent_low = 10, int cent_high = 30, double ptlow = 0.0, double pthigh = 40.0)
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

	//calculate chi2 and probability
	//if( str_legend1 == "Tracker only" )
	if( 0 )
	{
		int iptstart = 2;
		int iptend = 12;//not included
		double chi2 = 0;
		int numberofpoints = 0;

		if( cent_low == 0 ) iptstart = 3;

		for( int ipt = iptstart; ipt < iptend; ipt++ )
		{
			if( cent_low == 0 && ipt == 9 ) continue;
			if( cent_low == 10 && ipt == 5 ) continue;
			if( cent_low == 30 && ( ipt == 5 || ipt == 6 )) continue;
			cout << "bin center: " << vn_2->GetBinCenter(ipt+1) << endl;
			double temp = ( vn_2->GetBinContent(ipt+1) - vn_1->GetBinContent(ipt+1) ) * ( vn_2->GetBinContent(ipt+1) - vn_1->GetBinContent(ipt+1) ) / ( vn_2->GetBinError(ipt+1)*vn_2->GetBinError(ipt+1)+vn_1->GetBinError(ipt+1)*vn_1->GetBinError(ipt+1) );
			chi2 = chi2 + temp;
			numberofpoints++;
		}
		
		cout << "Chi2: " << chi2 << " Prob: " << TMath::Prob( chi2, numberofpoints ) << endl;

		tex = new TLatex(0.50,0.65,Form("#chi^{2}: %1.3f", chi2));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.05);
		tex->SetLineWidth(2);
		tex->SetTextAlign(11);
		tex->Draw();

		tex = new TLatex(0.50,0.58,Form("p value: %1.4f", TMath::Prob( chi2, numberofpoints ) ));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.05);
		tex->SetLineWidth(2);
		tex->SetTextAlign(11);
		tex->Draw();
	}

	cfg_vn->SaveAs(Form("plots_comparision/cfg_%s_%s_%s_cent%dto%d.pdf", cfgname.Data(), trigname.Data(), vnname.Data(), cent_low, cent_high));

	TCanvas * cfg_diff_vn = new TCanvas(Form("cfg_diff_%s_%s", trigname.Data(), vnname.Data()),Form("cfg_diff_%s_%s", trigname.Data(), vnname.Data())); 

	TH1D * diff_vn = (TH1D *) vn_2->Clone("diff_vn");
	diff_vn->Add(vn_1,-1.0);

	for( int ibin = 0; ibin < diff_vn->GetNbinsX(); ibin++)
		diff_vn->SetBinError(ibin+1,TMath::Sqrt(vn_2->GetBinError(ibin+1)*vn_2->GetBinError(ibin+1)+vn_1->GetBinError(ibin+1)*vn_1->GetBinError(ibin+1)));
	//golden and tracker only data are uncorrelated

	diff_vn->GetYaxis()->SetRangeUser(-0.1,0.1);
	diff_vn->GetYaxis()->SetTitle("Diff");
	diff_vn->Draw();

	TF1 * fun1 = new TF1("fun1", "0.0", 0, 100);
	fun1->SetLineColor(1.0);
	fun1->SetLineStyle(3);
	fun1->SetLineWidth(1);
	fun1->Draw("same");

	cfg_diff_vn->SaveAs(Form("plots_comparision/cfg_%s_%s_%s_cent%dto%d_diff.pdf", cfgname.Data(), trigname.Data(), vnname.Data(), cent_low, cent_high));
}
