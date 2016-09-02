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

void FinalPlot_PromptDfraction(TString inputfilename_cent0to10 = "promptD0_totaluncertainties/Fractionchange_ratioband_cent0to10.root", TString inputfilename_cent10to30 = "promptD0_totaluncertainties/Fractionchange_ratioband_cent10to30.root", TString inputfilename_cent30to50 = "promptD0_totaluncertainties/Fractionchange_ratioband_cent30to50.root", bool DrawnoDCAcut = true)
{
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * input_cent0to10 = new TFile(inputfilename_cent0to10);
	TFile * input_cent10to30 = new TFile(inputfilename_cent10to30);
	TFile * input_cent30to50 = new TFile(inputfilename_cent30to50);

	TGraphAsymmErrors * promptfraction_DCAcut_cent0to10 = ( TGraphAsymmErrors * ) input_cent0to10->Get("promptfraction_DCAcut");
	TGraphAsymmErrors * systematics_promptfraction_DCAcut_cent0to10 = ( TGraphAsymmErrors * ) input_cent0to10->Get("systematics_promptfraction_DCAcut");
	promptfraction_DCAcut_cent0to10->SetName("promptfraction_DCAcut_cent0to10");
	systematics_promptfraction_DCAcut_cent0to10->SetName("systematics_promptfraction_DCAcut_cent0to10");

	TGraphAsymmErrors * promptfraction_DCAcut_cent10to30 = ( TGraphAsymmErrors * ) input_cent10to30->Get("promptfraction_DCAcut");
	TGraphAsymmErrors * systematics_promptfraction_DCAcut_cent10to30 = ( TGraphAsymmErrors * ) input_cent10to30->Get("systematics_promptfraction_DCAcut");
	promptfraction_DCAcut_cent10to30->SetName("promptfraction_DCAcut_cent10to30");
	systematics_promptfraction_DCAcut_cent10to30->SetName("systematics_promptfraction_DCAcut_cent10to30");

	TGraphAsymmErrors * promptfraction_DCAcut_cent30to50 = ( TGraphAsymmErrors * ) input_cent30to50->Get("promptfraction_DCAcut");
	TGraphAsymmErrors * systematics_promptfraction_DCAcut_cent30to50 = ( TGraphAsymmErrors * ) input_cent30to50->Get("systematics_promptfraction_DCAcut");
	promptfraction_DCAcut_cent30to50->SetName("promptfraction_DCAcut_cent30to50");
	systematics_promptfraction_DCAcut_cent30to50->SetName("systematics_promptfraction_DCAcut_cent30to50");

	//no DCA cut
	TGraphAsymmErrors * promptfraction_noDCAcut_cent0to10 = ( TGraphAsymmErrors * ) input_cent0to10->Get("promptfraction_noDCAcut");
	TGraphAsymmErrors * systematics_promptfraction_noDCAcut_cent0to10 = ( TGraphAsymmErrors * ) input_cent0to10->Get("systematics_promptfraction_noDCAcut");
	promptfraction_noDCAcut_cent0to10->SetName("promptfraction_noDCAcut_cent0to10");
	systematics_promptfraction_noDCAcut_cent0to10->SetName("systematics_promptfraction_noDCAcut_cent0to10");

	TGraphAsymmErrors * promptfraction_noDCAcut_cent10to30 = ( TGraphAsymmErrors * ) input_cent10to30->Get("promptfraction_noDCAcut");
	TGraphAsymmErrors * systematics_promptfraction_noDCAcut_cent10to30 = ( TGraphAsymmErrors * ) input_cent10to30->Get("systematics_promptfraction_noDCAcut");
	promptfraction_noDCAcut_cent10to30->SetName("promptfraction_noDCAcut_cent10to30");
	systematics_promptfraction_noDCAcut_cent10to30->SetName("systematics_promptfraction_noDCAcut_cent10to30");

	TGraphAsymmErrors * promptfraction_noDCAcut_cent30to50 = ( TGraphAsymmErrors * ) input_cent30to50->Get("promptfraction_noDCAcut");
	TGraphAsymmErrors * systematics_promptfraction_noDCAcut_cent30to50 = ( TGraphAsymmErrors * ) input_cent30to50->Get("systematics_promptfraction_noDCAcut");
	promptfraction_noDCAcut_cent30to50->SetName("promptfraction_noDCAcut_cent30to50");
	systematics_promptfraction_noDCAcut_cent30to50->SetName("systematics_promptfraction_noDCAcut_cent30to50");

	TH2F* hempty = new TH2F("hempty","",20,0.01,41.,10.,0.,1.02);
	hempty->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hempty->GetYaxis()->SetTitle("Prompt D^{0} fraction");
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitleFont(43);
	hempty->GetXaxis()->SetTitleFont(43);
	hempty->SetTitleSize  (16,"X");
	hempty->SetTitleSize  (16,"Y");
	hempty->SetTitleOffset(1.5,"Y");
	hempty->SetTitleOffset(1.5,"X");
	hempty->SetLabelOffset(0.008,"Y");
	hempty->SetLabelFont  (43   ,"Y");
	hempty->SetLabelOffset(0.008,"X");
	hempty->SetLabelFont  (43   ,"X");
	hempty->GetXaxis()->SetLabelSize(14);
	hempty->GetYaxis()->SetLabelSize(14);

	TCanvas * cfg_promptfraction = new TCanvas("cfg_promptfraction","cfg_promptfraction",1000,400);
	makeMultiPanelCanvas(cfg_promptfraction, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	TLatex latex;

	cfg_promptfraction->cd(1);
	hempty->Draw();
	if( DrawnoDCAcut )
	{
		systematics_promptfraction_noDCAcut_cent0to10->Draw("2same");
		promptfraction_noDCAcut_cent0to10->Draw("Psame");
	}
	systematics_promptfraction_DCAcut_cent0to10->Draw("2same");
	promptfraction_DCAcut_cent0to10->Draw("Psame");
	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(13, 0.4, "Cent. 0-10%");


	cfg_promptfraction->cd(2);
	hempty->Draw();
	if( DrawnoDCAcut )
	{
		systematics_promptfraction_noDCAcut_cent10to30->Draw("2same");
		promptfraction_noDCAcut_cent10to30->Draw("Psame");
	}
	systematics_promptfraction_DCAcut_cent10to30->Draw("2same");
	promptfraction_DCAcut_cent10to30->Draw("Psame");
	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(13, 0.4, "Cent. 10-30%");

	cfg_promptfraction->cd(3);
	hempty->Draw();
	if( DrawnoDCAcut )
	{
		systematics_promptfraction_noDCAcut_cent30to50->Draw("2same");
		promptfraction_noDCAcut_cent30to50->Draw("Psame");
	}
	systematics_promptfraction_DCAcut_cent30to50->Draw("2same");
	promptfraction_DCAcut_cent30to50->Draw("Psame");
	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(13, 0.4, "Cent. 30-50%");

	cfg_promptfraction->cd(1);

    TLegend * leg = new TLegend(0.40, 0.25, 0.60, 0.40);
    leg->SetTextSize(0.05);
    leg->SetTextFont(42);
    leg->AddEntry(promptfraction_DCAcut_cent30to50, "All analysis cuts","pl");
    leg->AddEntry(promptfraction_noDCAcut_cent30to50, "w/o b_{0} < 0.008 cm cut","pl");
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    if( DrawnoDCAcut ) leg->Draw();

	TLatex Tl; 
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.06);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");
//	Tl.DrawLatex(0.15,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
//	Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	cfg_promptfraction->SaveAs(Form("finalplotforPAS/Final_cfg_promptfraction_drawnocut%d.pdf",DrawnoDCAcut));
	cfg_promptfraction->SaveAs(Form("finalplotforPAS/Final_cfg_promptfraction_drawnocut%d.png",DrawnoDCAcut));
}
