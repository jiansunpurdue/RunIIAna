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
#include <TROOT.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TMultiGraph.h>

#include "./SetDvn.C"
#include "style.h"
#include "Set_Alice_result.C"

//1, 0, 0, 1
//1, 1, 0, 1
//0, 0, 1, 0

void FinalPlot_compareAlice()
{
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	Readvn_SP();
	Readvn_phibin();
	Set_Alice_result();

	TF1 * fun = new TF1("fun", "0.0", 0, 100);
	fun->SetLineColor(1.0);
	fun->SetLineStyle(3);
	fun->SetLineWidth(1);

	TH2F* hemptyv2 = new TH2F("hemptyv2","",20,0.01,41.,10.,-0.18,0.295);
	hemptyv2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hemptyv2->GetYaxis()->SetTitle("v_{2}");
	hemptyv2->GetXaxis()->CenterTitle();
	hemptyv2->GetYaxis()->CenterTitle();
	hemptyv2->GetYaxis()->SetTitleFont(43);
	hemptyv2->GetXaxis()->SetTitleFont(43);
	hemptyv2->SetTitleSize  (16,"X");
	hemptyv2->SetTitleSize  (22,"Y");
	hemptyv2->SetTitleOffset(1.2,"Y");
	hemptyv2->SetTitleOffset(1.5,"X");
	hemptyv2->SetLabelOffset(0.008,"Y");
	hemptyv2->SetLabelFont  (43   ,"Y");
	hemptyv2->SetLabelOffset(0.008,"X");
	hemptyv2->SetLabelFont  (43   ,"X");
	hemptyv2->GetXaxis()->SetLabelSize(14);
	hemptyv2->GetYaxis()->SetLabelSize(14);

	TLatex latex;

	TCanvas * cfg_Dv2_compareAlice = new TCanvas("cfg_Dv2_compareAlice","cfg_Dv2_compareAlice",1000,400);
	makeMultiPanelCanvas(cfg_Dv2_compareAlice, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv2_compareAlice->cd(1);
	hemptyv2->Draw();
	gr_v2_Alice_sys_np[0]->Draw("2same");
	gr_v2_pt_sys_Bfeeddown[0]->Draw("2same");
	gr_v2_Alice_sys[0]->Draw("2same");
	gr_v2_Alice_stat[0]->Draw("psame");
	gr_v2_pt_sys[0]->Draw("2same");
	h_v2_pt[0]->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	//latex.DrawLatex(3, 0.3, "|y| < 1.0");
	latex.DrawLatex(1, 0.27, "Cent. 0-10%");

	cfg_Dv2_compareAlice->cd(2);
	hemptyv2->Draw();
	gr_v2_Alice_sys_np[1]->Draw("2same");
	gr_v2_pt_sys_Bfeeddown[1]->Draw("2same");
	gr_v2_Alice_sys[1]->Draw("2same");
	gr_v2_Alice_stat[1]->Draw("psame");
	gr_v2_pt_sys[1]->Draw("2same");
	h_v2_pt[1]->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(1, 0.27, "Cent. 10-30%");

	cfg_Dv2_compareAlice->cd(3);
	hemptyv2->Draw();
	gr_v2_Alice_sys_np[2]->Draw("2same");
	gr_v2_pt_sys_Bfeeddown[2]->Draw("2same");
	gr_v2_Alice_sys[2]->Draw("2same");
	gr_v2_Alice_stat[2]->Draw("psame");
	gr_v2_pt_sys[2]->Draw("2same");
	h_v2_pt[2]->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(1, 0.27, "Cent. 30-50%");

	cfg_Dv2_compareAlice->cd(1);

	TLegend * leg = new TLegend(0.55, 0.65, 0.75, 0.87);
	leg->SetTextSize(18);
	leg->SetTextFont(43);
	leg->AddEntry(h_v3_pt[0], "CMS, |y| < 1.0");
	leg->AddEntry(gr_v2_Alice_stat[0], "ALICE, |y| < 0.8", "p");
	leg->AddEntry((TObject*)0, "#scale[0.7]{PbPb #sqrt{s_{NN}} = 2.76 TeV}", "");
	leg->AddEntry((TObject*)0, "#scale[0.7]{PRC 90 (2014) 034904}", "");

	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->Draw();

	TLatex* texv2 = new TLatex(0.3,0.22,"Filled box: syst. from non-prompt D^{0}");
	texv2->SetNDC();
	texv2->SetTextFont(42);
	texv2->SetTextSize(0.04);
	texv2->SetLineWidth(2);
	texv2->Draw();

	texv2 = new TLatex(0.3,0.18,"Open box: other syst.");
	texv2->SetNDC();
	texv2->SetTextFont(42);
	texv2->SetTextSize(0.04);
	texv2->SetLineWidth(2);
	texv2->Draw();

	TLatex Tlv2; 
	Tlv2.SetNDC();
	Tlv2.SetTextAlign(12);
	Tlv2.SetTextSize(0.06);
	Tlv2.SetTextFont(42);
	Tlv2.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	cfg_Dv2_compareAlice->SaveAs("finalplotforPAS/cfg_Dv2SP_compareAlice.pdf");
	cfg_Dv2_compareAlice->SaveAs("finalplotforPAS/cfg_Dv2SP_compareAlice.png");
}
