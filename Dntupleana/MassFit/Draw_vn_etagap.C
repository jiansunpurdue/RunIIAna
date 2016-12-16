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

using namespace std;

void Draw_vn_etagap(TString trigname = "MBtrig", TString method = "SP", TString vnorder = "v3", TString histotoget = "h_v3_pt", int cent_low = 30, int cent_high = 50, TString infileeta2p0 = "Files_etagapstudy/rootfiles_EPa/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString infileeta2p5 = "Files_etagapstudy/rootfiles_EPb/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString infileeta3p0 = "Files_etagapstudy/rootfiles_EPdefault/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString infileeta3p5 = "Files_etagapstudy/rootfiles_EPd/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString infileeta4p0 = "Files_etagapstudy/rootfiles_EPe/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString infileeta4p5 = "Files_etagapstudy/rootfiles_EPf/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root")
{
    TH1::SetDefaultSumw2();
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

	TFile * inputeta2p0 = new TFile(infileeta2p0);
	TFile * inputeta2p5 = new TFile(infileeta2p5);
	TFile * inputeta3p0 = new TFile(infileeta3p0);
	TFile * inputeta3p5 = new TFile(infileeta3p5);
	TFile * inputeta4p0 = new TFile(infileeta4p0);
	TFile * inputeta4p5 = new TFile(infileeta4p5);
	
	TH1D * histoeta2p0 = (TH1D *) inputeta2p0->Get(histotoget);
	TH1D * histoeta2p5 = (TH1D *) inputeta2p5->Get(histotoget);
	TH1D * histoeta3p0 = (TH1D *) inputeta3p0->Get(histotoget);
	TH1D * histoeta3p5 = (TH1D *) inputeta3p5->Get(histotoget);
	TH1D * histoeta4p0 = (TH1D *) inputeta4p0->Get(histotoget);
	TH1D * histoeta4p5 = (TH1D *) inputeta4p5->Get(histotoget);

	histoeta2p0->SetLineColor(1);
	histoeta2p0->SetMarkerColor(1);
	histoeta2p5->SetLineColor(8);
	histoeta2p5->SetMarkerColor(8);
	histoeta3p5->SetLineColor(4);
	histoeta3p5->SetMarkerColor(4);
	histoeta4p0->SetLineColor(6);
	histoeta4p0->SetMarkerColor(6);
	histoeta4p5->SetLineColor(7);
	histoeta4p5->SetMarkerColor(7);

	TCanvas * cfg_vnetagap = new TCanvas("cfg_vnetagap","cfg_vnetagap",600,600);

	histoeta2p0->Draw();
	histoeta2p5->Draw("same");
	histoeta3p0->Draw("same");
	histoeta3p5->Draw("same");
	histoeta4p0->Draw("same");
	histoeta4p5->Draw("same");

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);
    fun->Draw("same");

	TLegend * leg = new TLegend(0.50, 0.60, 0.70, 0.90);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	
	leg->AddEntry(histoeta2p0,"|#Delta#eta|>2.0");
	leg->AddEntry(histoeta2p5,"|#Delta#eta|>2.5");
	leg->AddEntry(histoeta3p0,"|#Delta#eta|>3.0 (default)");
	leg->AddEntry(histoeta3p5,"|#Delta#eta|>3.5");
	leg->AddEntry(histoeta4p0,"|#Delta#eta|>4.0");
	leg->AddEntry(histoeta4p5,"|#Delta#eta|>4.5");
	
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

	cfg_vnetagap->SaveAs(Form("plots_systematic/plots_etagap/cfg_vnetagap_%s_%s_%s_cent%dto%d.pdf",trigname.Data(),method.Data(),vnorder.Data(),cent_low,cent_high));

	TH1D * histo_diff_eta2p0 = (TH1D *) histoeta2p0->Clone("histo_diff_eta2p0");
	TH1D * histo_diff_eta2p5 = (TH1D *) histoeta2p5->Clone("histo_diff_eta2p5");
	TH1D * histo_diff_eta3p5 = (TH1D *) histoeta3p5->Clone("histo_diff_eta3p5");
	TH1D * histo_diff_eta4p0 = (TH1D *) histoeta4p0->Clone("histo_diff_eta4p0");
	TH1D * histo_diff_eta4p5 = (TH1D *) histoeta4p5->Clone("histo_diff_eta4p5");

	histo_diff_eta2p0->Add(histoeta3p0,-1.0);
	histo_diff_eta2p5->Add(histoeta3p0,-1.0);
	histo_diff_eta3p5->Add(histoeta3p0,-1.0);
	histo_diff_eta4p0->Add(histoeta3p0,-1.0);
	histo_diff_eta4p5->Add(histoeta3p0,-1.0);

	TCanvas * cfg_diff_etagap = new TCanvas("cfg_diff_etagap","cfg_diff_etagap",600,600);
	cfg_diff_etagap->cd();

	histo_diff_eta2p0->GetYaxis()->SetRangeUser(-0.1,0.1);
	histo_diff_eta2p0->GetYaxis()->SetTitle("Diff");
	
	histo_diff_eta2p0->Draw();
	histo_diff_eta2p5->Draw("same");
	histo_diff_eta3p5->Draw("same");
	histo_diff_eta4p0->Draw("same");
	histo_diff_eta4p5->Draw("same");
    
	fun->Draw("same");
    
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
	
	cfg_diff_etagap->SaveAs(Form("plots_systematic/plots_etagap/cfg_diff_vnetagap_%s_%s_%s_cent%dto%d.pdf",trigname.Data(),method.Data(),vnorder.Data(),cent_low,cent_high));
}
