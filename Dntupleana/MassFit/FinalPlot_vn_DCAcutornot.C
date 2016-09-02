#include <iostream>
#include <array>
#include <iomanip>
#include <utility>
#include <TFile.h>
#include <TDirectoryFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH3F.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TBox.h>
#include <TCut.h>
#include <TMath.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TProfile.h>
#include "TFitter.h"
#include "TFitResult.h"

#include "style.h"

using namespace std;

void Set_plottingstyle_noDCAcut( TH1D * h)
{
	h->SetMarkerColor(2);
	h->SetLineColor(2);
	h->SetMarkerStyle(20);
}

void FinalPlot_vn_DCAcutornot( 
		TString name_cent0to10_DCA = "rootfiles_Data/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_poly3bkg_floatwidth_effcorrected0.root", TString name_cent0to10_noDCA = "rootfiles_Data_noDCAcut/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_poly3bkg_floatwidth_effcorrected0.root", 
		TString name_cent10to30_DCA = "rootfiles_Data/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_poly3bkg_floatwidth_effcorrected0.root", TString name_cent10to30_noDCA = "rootfiles_Data_noDCAcut/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_poly3bkg_floatwidth_effcorrected0.root", 
		TString name_cent30to50_DCA = "rootfiles_Data/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root", TString name_cent30to50_noDCA = "rootfiles_Data_noDCAcut/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * input_cent0to10_DCA = new TFile(name_cent0to10_DCA);
	TFile * input_cent0to10_noDCA = new TFile(name_cent0to10_noDCA);
	TFile * input_cent10to30_DCA = new TFile(name_cent10to30_DCA);
	TFile * input_cent10to30_noDCA = new TFile(name_cent10to30_noDCA);
	TFile * input_cent30to50_DCA = new TFile(name_cent30to50_DCA);
	TFile * input_cent30to50_noDCA = new TFile(name_cent30to50_noDCA);

	TH1D * h_v2_cent0to10_DCA = (TH1D *) input_cent0to10_DCA->Get("h_v2_pt");
	TH1D * h_v2_cent0to10_noDCA = (TH1D *) input_cent0to10_noDCA->Get("h_v2_pt");
	TH1D * h_v2_cent10to30_DCA = (TH1D *) input_cent10to30_DCA->Get("h_v2_pt");
	TH1D * h_v2_cent10to30_noDCA = (TH1D *) input_cent10to30_noDCA->Get("h_v2_pt");
	TH1D * h_v2_cent30to50_DCA = (TH1D *) input_cent30to50_DCA->Get("h_v2_pt");
	TH1D * h_v2_cent30to50_noDCA = (TH1D *) input_cent30to50_noDCA->Get("h_v2_pt");

	TH1D * h_v3_cent0to10_DCA = (TH1D *) input_cent0to10_DCA->Get("h_v3_pt");
	TH1D * h_v3_cent0to10_noDCA = (TH1D *) input_cent0to10_noDCA->Get("h_v3_pt");
	TH1D * h_v3_cent10to30_DCA = (TH1D *) input_cent10to30_DCA->Get("h_v3_pt");
	TH1D * h_v3_cent10to30_noDCA = (TH1D *) input_cent10to30_noDCA->Get("h_v3_pt");
	TH1D * h_v3_cent30to50_DCA = (TH1D *) input_cent30to50_DCA->Get("h_v3_pt");
	TH1D * h_v3_cent30to50_noDCA = (TH1D *) input_cent30to50_noDCA->Get("h_v3_pt");

	Set_plottingstyle_noDCAcut(h_v2_cent0to10_noDCA);
	Set_plottingstyle_noDCAcut(h_v2_cent10to30_noDCA);
	Set_plottingstyle_noDCAcut(h_v2_cent30to50_noDCA);

	Set_plottingstyle_noDCAcut(h_v3_cent0to10_noDCA);
	Set_plottingstyle_noDCAcut(h_v3_cent10to30_noDCA);
	Set_plottingstyle_noDCAcut(h_v3_cent30to50_noDCA);

	TF1 * fun = new TF1("fun", "0.0", 0, 100);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(1);

	TH2F* hemptyv2 = new TH2F("hemptyv2","",20,0.01,41.,10.,-0.18,0.4);
	hemptyv2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hemptyv2->GetYaxis()->SetTitle("v_{2}");
	hemptyv2->GetXaxis()->CenterTitle();
	hemptyv2->GetYaxis()->CenterTitle();
	hemptyv2->GetYaxis()->SetTitleFont(43);
	hemptyv2->GetXaxis()->SetTitleFont(43);
	hemptyv2->SetTitleSize  (16,"X");
	hemptyv2->SetTitleSize  (16,"Y");
	hemptyv2->SetTitleOffset(1.5,"Y");
	hemptyv2->SetTitleOffset(1.5,"X");
	hemptyv2->SetLabelOffset(0.008,"Y");
	hemptyv2->SetLabelFont  (43   ,"Y");
	hemptyv2->SetLabelOffset(0.008,"X");
	hemptyv2->SetLabelFont  (43   ,"X");
	hemptyv2->GetXaxis()->SetLabelSize(14);
	hemptyv2->GetYaxis()->SetLabelSize(14);

	TLatex latex;

	TCanvas * cfg_Dv2_DCAcutandnot = new TCanvas("cfg_Dv2_DCAcutandnot","cfg_Dv2_DCAcutandnot",1000,400);
	makeMultiPanelCanvas(cfg_Dv2_DCAcutandnot, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv2_DCAcutandnot->cd(1);
	hemptyv2->Draw();
	h_v2_cent0to10_noDCA->Draw("same");
	h_v2_cent0to10_DCA->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.3, "|y| < 1.0");
	latex.DrawLatex(3, 0.35, "Cent. 0-10%");

	cfg_Dv2_DCAcutandnot->cd(2);
	hemptyv2->Draw();
	h_v2_cent10to30_noDCA->Draw("same");
	h_v2_cent10to30_DCA->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.35, "Cent. 10-30%");

	cfg_Dv2_DCAcutandnot->cd(3);
	hemptyv2->Draw();
	h_v2_cent30to50_noDCA->Draw("same");
	h_v2_cent30to50_DCA->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.35, "Cent. 30-50%");

	cfg_Dv2_DCAcutandnot->cd(1);

	TLegend * legv2 = new TLegend(0.48, 0.70, 0.68, 0.87);
	legv2->SetTextSize(18);
	legv2->SetTextFont(43);
	legv2->AddEntry(h_v2_cent0to10_DCA, "All analysis cuts");
	legv2->AddEntry(h_v2_cent0to10_noDCA, "w/o b_{0} < 0.008 cm cut");

	legv2->SetBorderSize(0);
	legv2->SetFillStyle(0);
	legv2->Draw();

	TLatex Tlv2; 
	Tlv2.SetNDC();
	Tlv2.SetTextAlign(12);
	Tlv2.SetTextSize(0.06);
	Tlv2.SetTextFont(42);
	Tlv2.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	TLatex* texv2 = new TLatex(0.6,0.20,"Syst. not shown");
	texv2->SetNDC();
	texv2->SetTextFont(42);
	texv2->SetTextSize(0.045);
	texv2->SetLineWidth(2);
	texv2->Draw();

	cfg_Dv2_DCAcutandnot->SaveAs("finalplotforPAS/cfg_Dv2_DCAcutandnot_comparison.pdf");
	cfg_Dv2_DCAcutandnot->SaveAs("finalplotforPAS/cfg_Dv2_DCAcutandnot_comparison.png");

	//for v3
	TH2F* hemptyv3 = (TH2F*) hemptyv2->Clone("hemptyv3");
	hemptyv3->GetYaxis()->SetTitle("v_{3}");

	TCanvas * cfg_Dv3_DCAcutandnot = new TCanvas("cfg_Dv3_DCAcutandnot","cfg_Dv3_DCAcutandnot",1000,400);
	makeMultiPanelCanvas(cfg_Dv3_DCAcutandnot, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv3_DCAcutandnot->cd(1);
	hemptyv3->Draw();
	h_v3_cent0to10_noDCA->Draw("same");
	h_v3_cent0to10_DCA->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.3, "|y| < 1.0");
	latex.DrawLatex(3, 0.35, "Cent. 0-10%");

	cfg_Dv3_DCAcutandnot->cd(2);
	hemptyv3->Draw();
	h_v3_cent10to30_noDCA->Draw("same");
	h_v3_cent10to30_DCA->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.35, "Cent. 10-30%");

	cfg_Dv3_DCAcutandnot->cd(3);
	hemptyv3->Draw();
	h_v3_cent30to50_noDCA->Draw("same");
	h_v3_cent30to50_DCA->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.35, "Cent. 30-50%");

	cfg_Dv3_DCAcutandnot->cd(1);

	TLegend * legv3 = new TLegend(0.48, 0.70, 0.68, 0.87);
	legv3->SetTextSize(18);
	legv3->SetTextFont(43);
	legv3->AddEntry(h_v3_cent0to10_DCA, "All analysis cuts");
	legv3->AddEntry(h_v3_cent0to10_noDCA, "w/o b_{0} < 0.008 cm cut");

	legv3->SetBorderSize(0);
	legv3->SetFillStyle(0);
	legv3->Draw();

	TLatex Tlv3; 
	Tlv3.SetNDC();
	Tlv3.SetTextAlign(12);
	Tlv3.SetTextSize(0.06);
	Tlv3.SetTextFont(42);
	Tlv3.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	TLatex* texv3 = new TLatex(0.6,0.20,"Syst. not shown");
	texv3->SetNDC();
	texv3->SetTextFont(42);
	texv3->SetTextSize(0.045);
	texv3->SetLineWidth(2);
	texv3->Draw();

	cfg_Dv3_DCAcutandnot->SaveAs("finalplotforPAS/cfg_Dv3_DCAcutandnot_comparison.pdf");
	cfg_Dv3_DCAcutandnot->SaveAs("finalplotforPAS/cfg_Dv3_DCAcutandnot_comparison.png");
}
