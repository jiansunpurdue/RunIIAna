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
#include "./Set_theoryD.C"
#include "style.h"

//1, 0, 0, 1
//1, 1, 0, 1
//0, 0, 1, 0

void FinalPlot_vn( bool Drawchargedparticle = true, bool Drawtheory = true, bool Drawphibinmethod = false, bool Drawsysfromnonprompt = true)
{
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	if( Drawphibinmethod ) Drawsysfromnonprompt = false;

	Readvn_SP();
	Readvn_phibin();
	Set_theoryD();

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

	TCanvas * cfg_Dv2_charged_theory = new TCanvas("cfg_Dv2_charged_theory","cfg_Dv2_charged_theory",1000,400);
	makeMultiPanelCanvas(cfg_Dv2_charged_theory, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv2_charged_theory->cd(1);
	hemptyv2->Draw();
	if( Drawsysfromnonprompt )
	{
		if( Drawphibinmethod ) gr_v2_pt_sys_Bfeeddown_phibin[0]->Draw("2same");
		gr_v2_pt_sys_Bfeeddown[0]->Draw("2same");
	}
	if( Drawtheory )
	{
		gv2Dmeson5TeV_CUJET3[0]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[0]->Draw("CXsame");
		gv2Dmeson5TeV_TAMU[0]->Draw("3same");
		gv2Dmeson5TeV_TAMU[0]->Draw("CXsame");
		gv2Dmeson5TeV_LBT[0]->Draw("Csame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv2_sys_chargeparticle[0]->Draw("2same");
		grSteveSPv2_chargeparticle[0]->Draw("psame");
	}
	if( Drawphibinmethod ) 
	{
		gr_v2_pt_sys_phibin[0]->Draw("2same");
		h_v2_pt_phibin[0]->Draw("same");
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
	hemptyv2->Draw();
	if( Drawsysfromnonprompt )
	{
		if( Drawphibinmethod ) gr_v2_pt_sys_Bfeeddown_phibin[1]->Draw("2same");
		gr_v2_pt_sys_Bfeeddown[1]->Draw("2same");
	}
	if( Drawtheory )
	{
		gv2Dmeson5TeV_CUJET3[1]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[1]->Draw("CXsame");
		gv2Dmeson5TeV_TAMU[1]->Draw("3same");
		gv2Dmeson5TeV_TAMU[1]->Draw("CXsame");
		gv2Dmeson5TeV_LBT[1]->Draw("Csame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv2_sys_chargeparticle[1]->Draw("2same");
		grSteveSPv2_chargeparticle[1]->Draw("psame");
	}
	if( Drawphibinmethod ) 
	{
		gr_v2_pt_sys_phibin[1]->Draw("2same");
		h_v2_pt_phibin[1]->Draw("same");
	}
	gr_v2_pt_sys[1]->Draw("2same");
	h_v2_pt[1]->Draw("same");
	fun->Draw("same");

	latex.SetTextFont(43);
	latex.SetTextSize(18);
	latex.SetTextAlign(13);
	latex.DrawLatex(3, 0.35, "Cent. 10-30%");

	cfg_Dv2_charged_theory->cd(3);
	hemptyv2->Draw();
	if( Drawsysfromnonprompt )
	{
		if( Drawphibinmethod ) gr_v2_pt_sys_Bfeeddown_phibin[2]->Draw("2same");
		gr_v2_pt_sys_Bfeeddown[2]->Draw("2same");
	}
	if( Drawtheory )
	{
		gv2Dmeson5TeV_CUJET3[2]->Draw("3same");
		gv2Dmeson5TeV_CUJET3[2]->Draw("CXsame");
		gv2Dmeson5TeV_TAMU[2]->Draw("3same");
		gv2Dmeson5TeV_TAMU[2]->Draw("CXsame");
		gv2Dmeson5TeV_LBT[2]->Draw("Csame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv2_sys_chargeparticle[2]->Draw("2same");
		grSteveSPv2_chargeparticle[2]->Draw("psame");
	}
	if( Drawphibinmethod ) 
	{
		gr_v2_pt_sys_phibin[2]->Draw("2same");
		h_v2_pt_phibin[2]->Draw("same");
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

	if( Drawsysfromnonprompt )
	{
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
	}

	if( Drawphibinmethod && !Drawchargedparticle)
	{   
		TLegend * leg = new TLegend(0.55, 0.70, 0.75, 0.87);
		leg->SetTextSize(18);
		leg->SetTextFont(43);
		leg->AddEntry(h_v2_pt[0], "SP method");
		leg->AddEntry(h_v2_pt_phibin[0], "#Delta#Phi bins method");

		leg->SetBorderSize(0);
		leg->SetFillStyle(0);
		leg->Draw();
	}   

	if( Drawphibinmethod && !Drawsysfromnonprompt )
	{
		TLatex* texv2 = new TLatex(0.3,0.20,"Syst. from non-prompt D^{0} not shown");
		texv2->SetNDC();
		texv2->SetTextFont(42);
		texv2->SetTextSize(0.04);
		texv2->SetLineWidth(2);
		texv2->Draw();
	}

	TLatex Tlv2; 
	Tlv2.SetNDC();
	Tlv2.SetTextAlign(12);
	Tlv2.SetTextSize(0.06);
	Tlv2.SetTextFont(42);
	Tlv2.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	cfg_Dv2_charged_theory->cd(3);

	if( Drawtheory )
	{   
		TLatex Ttheory;
		Ttheory.SetTextFont(43);
		Ttheory.SetTextSize(15);
		Ttheory.SetTextAlign(13);
		Ttheory.DrawLatex(13, 0.3, "Theory prediction for prompt D");

		TLegend * leg1 = new TLegend(0.30, 0.61, 0.60, 0.73);
		leg1->SetTextSize(15);
		leg1->SetTextFont(43);
		leg1->AddEntry(gv2Dmeson5TeV_LBT[0], "LBT", "l");
		leg1->AddEntry(gv2Dmeson5TeV_TAMU[0], "TAMU", "l");
		leg1->SetBorderSize(0);
		leg1->SetFillStyle(0);
		leg1->Draw();

		TLegend * leg2 = new TLegend(0.60, 0.67, 0.90, 0.73);
		leg2->SetTextSize(15);
		leg2->SetTextFont(43);
		leg2->AddEntry(gv2Dmeson5TeV_CUJET3[0], "CUJET3", "l");
		leg2->SetBorderSize(0);
		leg2->SetFillStyle(0);
		leg2->Draw();
	}   

	cfg_Dv2_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv2SP_charged%d_theory%d_phibin%d.pdf",Drawchargedparticle,Drawtheory, Drawphibinmethod));
	cfg_Dv2_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv2SP_charged%d_theory%d_phibin%d.png",Drawchargedparticle,Drawtheory, Drawphibinmethod));

	//v3
	TH2F * hemptyv3 = ( TH2F *) hemptyv2->Clone("hemptyv3");
	hemptyv3->GetYaxis()->SetTitle("v_{3}");

	TCanvas * cfg_Dv3_charged_theory = new TCanvas("cfg_Dv3_charged_theory","cfg_Dv3_charged_theory",1000,400);
	makeMultiPanelCanvas(cfg_Dv3_charged_theory, 3, 1, 0.0, 0., 0.15, 0.15, 0.04, 0.08);

	cfg_Dv3_charged_theory->cd(1);
	hemptyv3->Draw();
	if( Drawsysfromnonprompt )
	{
		if( Drawphibinmethod ) gr_v3_pt_sys_Bfeeddown_phibin[0]->Draw("2same");
		gr_v3_pt_sys_Bfeeddown[0]->Draw("2same");
	}
	if( Drawtheory )
	{
		gv3Dmeson5TeV_LBT[0]->Draw("Csame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv3_sys_chargeparticle[0]->Draw("2same");
		grSteveSPv3_chargeparticle[0]->Draw("psame");
	}
	if( Drawphibinmethod ) 
	{
		gr_v3_pt_sys_phibin[0]->Draw("2same");
		h_v3_pt_phibin[0]->Draw("same");
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
	if( Drawsysfromnonprompt )
	{
		if( Drawphibinmethod ) gr_v3_pt_sys_Bfeeddown_phibin[1]->Draw("2same");
		gr_v3_pt_sys_Bfeeddown[1]->Draw("2same");
	}
	if( Drawtheory )
	{
		gv3Dmeson5TeV_LBT[1]->Draw("Csame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv3_sys_chargeparticle[1]->Draw("2same");
		grSteveSPv3_chargeparticle[1]->Draw("psame");
	}
	if( Drawphibinmethod ) 
	{
		gr_v3_pt_sys_phibin[1]->Draw("2same");
		h_v3_pt_phibin[1]->Draw("same");
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
	if( Drawsysfromnonprompt )
	{
		if( Drawphibinmethod ) gr_v3_pt_sys_Bfeeddown_phibin[2]->Draw("2same");
		gr_v3_pt_sys_Bfeeddown[2]->Draw("2same");
	}
	if( Drawtheory )
	{
		gv3Dmeson5TeV_LBT[2]->Draw("Csame");
	}
	if( Drawchargedparticle )
	{
		grSteveSPv3_sys_chargeparticle[2]->Draw("2same");
		grSteveSPv3_chargeparticle[2]->Draw("psame");
	}
	if( Drawphibinmethod ) 
	{
		gr_v3_pt_sys_phibin[2]->Draw("2same");
		h_v3_pt_phibin[2]->Draw("same");
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

	if( Drawsysfromnonprompt )
	{
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
	}

	if( Drawphibinmethod && !Drawchargedparticle)
	{   
		TLegend * leg = new TLegend(0.55, 0.70, 0.75, 0.87);
		leg->SetTextSize(18);
		leg->SetTextFont(43);
		leg->AddEntry(h_v3_pt[0], "SP method");
		leg->AddEntry(h_v3_pt_phibin[0], "#Delta#Phi bins method");

		leg->SetBorderSize(0);
		leg->SetFillStyle(0);
		leg->Draw();
	}   

	if( Drawphibinmethod && !Drawsysfromnonprompt )
	{
		TLatex* texv3 = new TLatex(0.3,0.20,"Syst. from non-prompt D^{0} not shown");
		texv3->SetNDC();
		texv3->SetTextFont(42);
		texv3->SetTextSize(0.04);
		texv3->SetLineWidth(2);
		texv3->Draw();
	}

	TLatex Tlv3; 
	Tlv3.SetNDC();
	Tlv3.SetTextAlign(12);
	Tlv3.SetTextSize(0.06);
	Tlv3.SetTextFont(42);
	Tlv3.DrawLatex(0.15,0.960, "#font[61]{CMS} #scale[0.8]{Preliminary PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	cfg_Dv3_charged_theory->cd(3);

	if( Drawtheory )
	{   
		TLatex Ttheory;
		Ttheory.SetTextFont(43);
		Ttheory.SetTextSize(15);
		Ttheory.SetTextAlign(13);
		Ttheory.DrawLatex(13, 0.3, "Theory prediction for prompt D");

		TLegend * leg1 = new TLegend(0.30, 0.67, 0.60, 0.73);
		leg1->SetTextSize(15);
		leg1->SetTextFont(43);
		leg1->AddEntry(gv2Dmeson5TeV_LBT[0], "LBT", "l");
		leg1->SetBorderSize(0);
		leg1->SetFillStyle(0);
		leg1->Draw();
	}   

	cfg_Dv3_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv3SP_charged%d_theory%d_phibin%d.pdf",Drawchargedparticle,Drawtheory,Drawphibinmethod));
	cfg_Dv3_charged_theory->SaveAs(Form("finalplotforPAS/cfg_Dv3SP_charged%d_theory%d_phibin%d.png",Drawchargedparticle,Drawtheory,Drawphibinmethod));
}
