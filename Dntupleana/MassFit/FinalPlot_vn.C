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

void FinalPlot_vn( bool Drawchargedparticle = true, bool Drawtheory = true)
{
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	
	Readvn_SP();
	Readvn_phibin();

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);

    TH2F* hempty = new TH2F("hempty","",20,0.01,41.,10.,-0.18,0.4);
    hempty->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    hempty->GetYaxis()->SetTitle("v_{2}");
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
	
	TLatex latex;

	TCanvas * cfg_Dv2_charged_theory = new TCanvas("cfg_Dv2_charged_theory","cfg_Dv2_charged_theory",1000,400);
	makeMultiPanelCanvas(cfg_Dv2_charged_theory, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv2_charged_theory->cd(1);
	hempty->Draw();
	gr_v2_pt_sys_Bfeeddown[0]->Draw("2same");
	if( Drawtheory )
	{
		gv2Dmeson5TeV_CUJET3[0]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[0]->Draw("CXsame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv2_sys_chargeparticle[0]->Draw("2same");
		grSteveSPv2_chargeparticle[0]->Draw("psame");
	}
	gr_v2_pt_sys[0]->Draw("2same");
	h_v2_pt[0]->Draw("same");
    fun->Draw("same");

    latex.SetTextFont(43);
    latex.SetTextSize(18);
    latex.SetTextAlign(13);
    latex.DrawLatex(3, 0.3, "|y| < 1.0");
    latex.DrawLatex(3, 0.35, "Cent. 0-10%");

	cfg_Dv2_charged_theory->cd(2);
	hempty->Draw();
	gr_v2_pt_sys_Bfeeddown[1]->Draw("2same");
	if( Drawtheory )
	{
		gv2Dmeson5TeV_CUJET3[1]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[1]->Draw("CXsame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv2_sys_chargeparticle[1]->Draw("2same");
		grSteveSPv2_chargeparticle[1]->Draw("psame");
	}
	gr_v2_pt_sys[1]->Draw("2same");
	h_v2_pt[1]->Draw("same");
    fun->Draw("same");

    latex.SetTextFont(43);
    latex.SetTextSize(18);
    latex.SetTextAlign(13);
    latex.DrawLatex(3, 0.35, "Cent. 10-30%");

	cfg_Dv2_charged_theory->cd(3);
	hempty->Draw();
	gr_v2_pt_sys_Bfeeddown[2]->Draw("2same");
	if( Drawtheory )
	{
		gv2Dmeson5TeV_CUJET3[2]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[2]->Draw("CXsame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv2_sys_chargeparticle[2]->Draw("2same");
		grSteveSPv2_chargeparticle[2]->Draw("psame");
	}
	gr_v2_pt_sys[2]->Draw("2same");
	h_v2_pt[2]->Draw("same");
    fun->Draw("same");

    latex.SetTextFont(43);
    latex.SetTextSize(18);
    latex.SetTextAlign(13);
    latex.DrawLatex(3, 0.35, "Cent. 30-50%");

	cfg_Dv2_charged_theory->cd(1);

    if( Drawchargedparticle )
    {   
        TLegend * leg = new TLegend(0.55, 0.70, 0.75, 0.87);
        leg->SetTextSize(18);
        leg->SetTextFont(43);
        leg->AddEntry(h_v2_pt[0], "D^{0}");
        leg->AddEntry(grSteveSPv2_chargeparticle[0], "Charged particle", "p");
        leg->AddEntry((TObject*)0, "#scale[0.7]{CMS-PAS-HIN-15-014}", "");

        leg->SetBorderSize(0);
        leg->SetFillStyle(0);
        leg->Draw();
    }   
	
	TLatex* texv2 = new TLatex(0.3,0.25,"Filled box: syst. from non-prompt D^{0}");
    texv2->SetNDC();
    texv2->SetTextFont(42);
    texv2->SetTextSize(0.04);
    texv2->SetLineWidth(2);
    texv2->Draw();

    texv2 = new TLatex(0.3,0.20,"Open box: other syst.");
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

	cfg_Dv2_charged_theory->cd(3);

    if( Drawtheory )
    {   
        TLegend * leg1 = new TLegend(0.25, 0.65, 0.45, 0.78);
        leg1->SetTextSize(15);
        leg1->SetTextFont(43);
		leg1->AddEntry((TObject*)0, "Theory prediction for prompt D^{0}", "");
		leg1->AddEntry(gv2Dmeson5TeV_CUJET3[0], "CUJET3", "l");
        leg1->SetBorderSize(0);
        leg1->SetFillStyle(0);
        leg1->Draw();
    }   

	cfg_Dv2_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv2SP_charged%d_theory%d.pdf",Drawchargedparticle,Drawtheory));
	cfg_Dv2_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv2SP_charged%d_theory%d.png",Drawchargedparticle,Drawtheory));

	//for v3
	TH2F* hemptyv3 = (TH2F *) hempty->Clone("hemptyv3");
    hemptyv3->GetYaxis()->SetTitle("v_{3}");

	TCanvas * cfg_Dv3_charged_theory = new TCanvas("cfg_Dv3_charged_theory","cfg_Dv3_charged_theory",1000,400);
	makeMultiPanelCanvas(cfg_Dv3_charged_theory, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv3_charged_theory->cd(1);
	hemptyv3->Draw();
	gr_v3_pt_sys_Bfeeddown[0]->Draw("2same");
	if( Drawtheory )
	{
	}
	if( Drawchargedparticle )
	{
		grSteveSPv3_sys_chargeparticle[0]->Draw("2same");
		grSteveSPv3_chargeparticle[0]->Draw("psame");
	}
	gr_v3_pt_sys[0]->Draw("2same");
	h_v3_pt[0]->Draw("same");
    fun->Draw("same");

    latex.SetTextFont(43);
    latex.SetTextSize(18);
    latex.SetTextAlign(13);
    latex.DrawLatex(3, 0.3, "|y| < 1.0");
    latex.DrawLatex(3, 0.35, "Cent. 0-10%");

	cfg_Dv3_charged_theory->cd(2);
	hemptyv3->Draw();
	gr_v3_pt_sys_Bfeeddown[1]->Draw("2same");
	if( Drawtheory )
	{
	}
	if( Drawchargedparticle )
	{
		grSteveSPv3_sys_chargeparticle[1]->Draw("2same");
		grSteveSPv3_chargeparticle[1]->Draw("psame");
	}
	gr_v3_pt_sys[1]->Draw("2same");
	h_v3_pt[1]->Draw("same");
    fun->Draw("same");

    latex.SetTextFont(43);
    latex.SetTextSize(18);
    latex.SetTextAlign(13);
    latex.DrawLatex(3, 0.35, "Cent. 10-30%");

	cfg_Dv3_charged_theory->cd(3);
	hemptyv3->Draw();
	gr_v3_pt_sys_Bfeeddown[2]->Draw("2same");
	if( Drawtheory )
	{
	}
	if( Drawchargedparticle )
	{
		grSteveSPv3_sys_chargeparticle[2]->Draw("2same");
		grSteveSPv3_chargeparticle[2]->Draw("psame");
	}
	gr_v3_pt_sys[2]->Draw("2same");
	h_v3_pt[2]->Draw("same");
    fun->Draw("same");

    latex.SetTextFont(43);
    latex.SetTextSize(18);
    latex.SetTextAlign(13);
    latex.DrawLatex(3, 0.35, "Cent. 30-50%");

	cfg_Dv3_charged_theory->cd(1);
    if( Drawchargedparticle )
    {   
        TLegend * leg = new TLegend(0.55, 0.70, 0.75, 0.87);
        leg->SetTextSize(18);
        leg->SetTextFont(43);
        leg->AddEntry(h_v3_pt[0], "D^{0}");
        leg->AddEntry(grSteveSPv3_chargeparticle[0], "Charged particle", "p");
        leg->AddEntry((TObject*)0, "#scale[0.7]{CMS-PAS-HIN-15-014}", "");

        leg->SetBorderSize(0);
        leg->SetFillStyle(0);
        leg->Draw();
    }   
	
	TLatex* texv3 = new TLatex(0.3,0.25,"Filled box: syst. from non-prompt D^{0}");
    texv3->SetNDC();
    texv3->SetTextFont(42);
    texv3->SetTextSize(0.04);
    texv3->SetLineWidth(2);
    texv3->Draw();

    texv3 = new TLatex(0.3,0.20,"Open box: other syst.");
    texv3->SetNDC();
    texv3->SetTextFont(42);
    texv3->SetTextSize(0.04);
    texv3->SetLineWidth(2);
    texv3->Draw();

    TLatex Tlv3; 
    Tlv3.SetNDC();
    Tlv3.SetTextAlign(12);
    Tlv3.SetTextSize(0.06);
    Tlv3.SetTextFont(42);
    Tlv3.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	cfg_Dv3_charged_theory->cd(3);

    if( Drawtheory )
    {   
    }   

	cfg_Dv3_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv3SP_charged%d_theory%d.pdf",Drawchargedparticle,0));
	cfg_Dv3_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv3SP_charged%d_theory%d.png",Drawchargedparticle,0));
}
