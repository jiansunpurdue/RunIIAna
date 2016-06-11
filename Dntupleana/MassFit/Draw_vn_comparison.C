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

#include "HIN-11-012.h"

void Draw_vn_comparison(TString input_morephibin = "rootfiles/vn_morephibin_MBtrig_cent30to50.root", TString input_inoutplane = "rootfiles/vn_inoutplane_MBtrig_cent30to50.root", TString input_vnvmass_EP = "rootfiles/vn_vnvsmass_MBtrig_EP_cent30to50.root", TString input_vnvmass_SP = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 1.5, double pthigh = 35.0, bool DrawvnvsmassSP = true, bool DrawvnvsmassEP = false, bool Drawinoutplane = false, bool Drawchargedparticle = true, TString fitoption = "poly3bkg")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Drawcomparison(TH1D * vn_morephibin, TH1D * vn_inoutplane, TH1D * vn_vnvsmass_EP, TH1D * vn_vnvsmass_SP, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool DrawvnvsmassSP = true, bool DrawvnvsmassEP = false, bool Drawinoutplane = false, bool Drawchargedparticle = false, TString fitoption = "poly3bkg");

	if( Drawchargedparticle ) HIN_11_012();

	TFile * inputdata_morephibin = new TFile(input_morephibin);
	TFile * inputdata_inoutplane = new TFile(input_inoutplane);
	TFile * inputdata_vnvsmass_EP = new TFile(input_vnvmass_EP);
	TFile * inputdata_vnvsmass_SP = new TFile(input_vnvmass_SP);

	TH1D * v2_morephibin = (TH1D *) inputdata_morephibin->Get("v2_morephibin");
	TH1D * v3_morephibin = (TH1D *) inputdata_morephibin->Get("v3_morephibin");
	v2_morephibin->SetName("v2_morephibin"); v2_morephibin->SetTitle("v2_morephibin");
	v3_morephibin->SetName("v3_morephibin"); v3_morephibin->SetTitle("v3_morephibin");

	TH1D * v2_inoutplane = (TH1D *) inputdata_inoutplane->Get("v2_inoutplane");
	TH1D * v3_inoutplane = (TH1D *) inputdata_inoutplane->Get("v3_inoutplane");
	v2_inoutplane->SetName("v2_inoutplane"); v2_inoutplane->SetTitle("v2_inoutplane");
	v3_inoutplane->SetName("v3_inoutplane"); v3_inoutplane->SetTitle("v3_inoutplane");

	TH1D * h_v2_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v2_pt");
	TH1D * h_v3_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v3_pt");
	h_v2_pt_EP->SetName("h_v2_pt_EP"); h_v2_pt_EP->SetTitle("h_v2_pt_EP");
	h_v3_pt_EP->SetName("h_v3_pt_EP"); h_v3_pt_EP->SetTitle("h_v3_pt_EP");

	TH1D * h_v2_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt");
	TH1D * h_v3_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt");
	h_v2_pt_SP->SetName("h_v2_pt_SP"); h_v2_pt_SP->SetTitle("h_v2_pt_SP");
	h_v3_pt_SP->SetName("h_v3_pt_SP"); h_v3_pt_SP->SetTitle("h_v3_pt_SP");

	Drawcomparison( v2_morephibin, v2_inoutplane, h_v2_pt_EP, h_v2_pt_SP, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh, DrawvnvsmassSP, DrawvnvsmassEP, Drawinoutplane, Drawchargedparticle, fitoption);

	if( Drawchargedparticle ) return;
	Drawcomparison( v3_morephibin, v3_inoutplane, h_v3_pt_EP, h_v3_pt_SP, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh, DrawvnvsmassSP, DrawvnvsmassEP, Drawinoutplane, false, fitoption);

	TFile * output = new TFile(Form("rootfiles/vn_EPSPinoutplane_%s_cent%dto%d_%s.root", trigname.Data(), cent_low, cent_high, fitoption.Data()),"RECREATE");
	v2_morephibin->Write();
	v3_morephibin->Write();
	v2_inoutplane->Write();
	v3_inoutplane->Write();
	h_v2_pt_EP->Write();
	h_v3_pt_EP->Write();
	h_v2_pt_SP->Write();
	h_v3_pt_SP->Write();
	output->Close();
}

void Drawcomparison(TH1D * vn_morephibin, TH1D * vn_inoutplane, TH1D * vn_vnvsmass_EP, TH1D * vn_vnvsmass_SP, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool DrawvnvsmassSP = true, bool DrawvnvsmassEP = false, bool Drawinoutplane = false, bool Drawchargedparticle = false, TString fitoption = "poly3bkg")
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));

	vn_morephibin->Draw();
	if( DrawvnvsmassEP ) vn_vnvsmass_EP->Draw("same");
	if( DrawvnvsmassSP ) vn_vnvsmass_SP->Draw("same");
	if( Drawinoutplane ) vn_inoutplane->Draw("same");

	if( vnname == "v2" && Drawchargedparticle && cent_low == 0 && cent_high == 10 ) grHIN_v2pt[0]->Draw("psame");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 10 && cent_high == 30 ) grHIN_v2pt[1]->Draw("psame");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 30 && cent_high == 50 ) grHIN_v2pt[3]->Draw("psame");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 50 && cent_high == 70 ) grHIN_v2pt[5]->Draw("psame");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.05);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
	Tl.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

	TLegend * leg;
	if( vnname == "v2" && Drawchargedparticle ) leg = new TLegend(0.45, 0.67, 0.65, 0.90);
	else leg = new TLegend(0.45, 0.78, 0.65, 0.90);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	if( DrawvnvsmassEP ) leg->AddEntry(vn_vnvsmass_EP, Form("%s vs mass method {EP}", Ytitle.Data()));
	if( DrawvnvsmassSP ) leg->AddEntry(vn_vnvsmass_SP, Form("%s vs mass method {SP}", Ytitle.Data()));
	leg->AddEntry(vn_morephibin, "#Delta#Phi bins");
	if( Drawinoutplane ) leg->AddEntry(vn_inoutplane, "In and out plane method");

	if( vnname == "v2" && Drawchargedparticle )
		leg->AddEntry(grHIN_v2pt[0], "Charged particle", "p");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 0 && cent_high == 10 ) 
		leg->AddEntry((TObject*)0, "#scale[0.7]{Cent. 0-10%, HIN-11-012}", "");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 10 && cent_high == 30 ) 
		leg->AddEntry((TObject*)0, "#scale[0.7]{Cent. 10-20%, HIN-11-012}", "");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 30 && cent_high == 50 ) 
		leg->AddEntry((TObject*)0, "#scale[0.7]{Cent. 30-40%, HIN-11-012}", "");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 50 && cent_high == 70 ) 
		leg->AddEntry((TObject*)0, "#scale[0.7]{Cent. 50-60%, HIN-11-012}", "");

	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->Draw();

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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_comparison_%s_%s_cent%dto%d_charged%d_vnvsmassSP%dEP%d_inoutplane%d_%s.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, DrawvnvsmassSP, DrawvnvsmassEP, Drawchargedparticle, Drawinoutplane, fitoption.Data()));
}
