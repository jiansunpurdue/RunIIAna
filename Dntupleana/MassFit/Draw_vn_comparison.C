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

void Draw_vn_comparison(TString input_inoutplane = "rootfiles/vn_inoutplane_MBtrig_cent30to50.root", TString input_vnvmass_EP = "rootfiles/vn_vnvsmass_MBtrig_EP_cent30to50.root", TString input_vnvmass_SP = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50.root", TString trigname = "MBtrig", int cent_low = 30, int cent_high = 50, double ptlow = 1.5, double pthigh = 35.0, bool Drawchargedparticle = false)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	void Drawcomparison(TH1D * vn_inoutplane, TH1D * vn_vnvsmass_EP, TH1D * vn_vnvsmass_SP, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false);

	if( Drawchargedparticle ) HIN_11_012();

	TFile * inputdata_inoutplane = new TFile(input_inoutplane);
	TFile * inputdata_vnvsmass_EP = new TFile(input_vnvmass_EP);
	TFile * inputdata_vnvsmass_SP = new TFile(input_vnvmass_SP);

	TH1D * v1_inoutplane = (TH1D *) inputdata_inoutplane->Get("v1_inoutplane");
	TH1D * v2_inoutplane = (TH1D *) inputdata_inoutplane->Get("v2_inoutplane");
	TH1D * v3_inoutplane = (TH1D *) inputdata_inoutplane->Get("v3_inoutplane");
	TH1D * v4_inoutplane = (TH1D *) inputdata_inoutplane->Get("v4_inoutplane");
	v1_inoutplane->SetName("v1_inoutplane"); v1_inoutplane->SetTitle("v1_inoutplane");
	v2_inoutplane->SetName("v2_inoutplane"); v2_inoutplane->SetTitle("v2_inoutplane");
	v3_inoutplane->SetName("v3_inoutplane"); v3_inoutplane->SetTitle("v3_inoutplane");
	v4_inoutplane->SetName("v4_inoutplane"); v4_inoutplane->SetTitle("v4_inoutplane");

	TH1D * h_v1_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v1_pt");
	TH1D * h_v2_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v2_pt");
	TH1D * h_v3_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v3_pt");
	TH1D * h_v4_pt_EP = (TH1D *) inputdata_vnvsmass_EP->Get("h_v4_pt");
	h_v1_pt_EP->SetName("h_v1_pt_EP"); h_v1_pt_EP->SetTitle("h_v1_pt_EP");
	h_v2_pt_EP->SetName("h_v2_pt_EP"); h_v2_pt_EP->SetTitle("h_v2_pt_EP");
	h_v3_pt_EP->SetName("h_v3_pt_EP"); h_v3_pt_EP->SetTitle("h_v3_pt_EP");
	h_v4_pt_EP->SetName("h_v4_pt_EP"); h_v4_pt_EP->SetTitle("h_v4_pt_EP");

	TH1D * h_v1_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v1_pt");
	TH1D * h_v2_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v2_pt");
	TH1D * h_v3_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v3_pt");
	TH1D * h_v4_pt_SP = (TH1D *) inputdata_vnvsmass_SP->Get("h_v4_pt");
	h_v1_pt_SP->SetName("h_v1_pt_SP"); h_v1_pt_SP->SetTitle("h_v1_pt_SP");
	h_v2_pt_SP->SetName("h_v2_pt_SP"); h_v2_pt_SP->SetTitle("h_v2_pt_SP");
	h_v3_pt_SP->SetName("h_v3_pt_SP"); h_v3_pt_SP->SetTitle("h_v3_pt_SP");
	h_v4_pt_SP->SetName("h_v4_pt_SP"); h_v4_pt_SP->SetTitle("h_v4_pt_SP");

	Drawcomparison( v2_inoutplane, h_v2_pt_EP, h_v2_pt_SP, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh, Drawchargedparticle);

	if( Drawchargedparticle ) return;
	//Drawcomparison( v1_inoutplane, h_v1_pt_EP, h_v1_pt_SP, trigname, "v1", "v_{1}", cent_low, cent_high, ptlow, pthigh, false);
	Drawcomparison( v3_inoutplane, h_v3_pt_EP, h_v3_pt_SP, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh, false);
	//Drawcomparison( v4_inoutplane, h_v4_pt_EP, h_v4_pt_SP, trigname, "v4", "v_{4}", cent_low, cent_high, ptlow, pthigh, false);

	TFile * output = new TFile(Form("rootfiles/vn_EPSPinoutplane_%s_cent%dto%d.root", trigname.Data(), cent_low, cent_high),"RECREATE");
	v2_inoutplane->Write();
	v3_inoutplane->Write();
	h_v2_pt_EP->Write();
	h_v3_pt_EP->Write();
	h_v2_pt_SP->Write();
	h_v3_pt_SP->Write();
	output->Close();
}

void Drawcomparison(TH1D * vn_inoutplane, TH1D * vn_vnvsmass_EP, TH1D * vn_vnvsmass_SP, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0, bool Drawchargedparticle = false)
{
	TCanvas * cfg_vn = new TCanvas(Form("cfg_comparison_%s_%s", trigname.Data(), vnname.Data()));

	vn_inoutplane->Draw();
	vn_vnvsmass_EP->Draw("same");
	vn_vnvsmass_SP->Draw("same");

	if( vnname == "v2" && Drawchargedparticle && cent_low == 0 && cent_high == 10 ) grHIN_v2pt[0]->Draw("psame");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 10 && cent_high == 30 ) grHIN_v2pt[1]->Draw("psame");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 30 && cent_high == 50 ) grHIN_v2pt[3]->Draw("psame");
	if( vnname == "v2" && Drawchargedparticle && cent_low == 50 && cent_high == 70 ) grHIN_v2pt[5]->Draw("psame");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.04);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.125,0.96, "#scale[1.25]{CMS} Preliminary");
	Tl.DrawLatex(0.57,0.96, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLegend * leg;
	if( vnname == "v2" && Drawchargedparticle ) leg = new TLegend(0.45, 0.67, 0.65, 0.90);
	else leg = new TLegend(0.45, 0.75, 0.65, 0.90);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->AddEntry(vn_inoutplane, "In and out plane method");
	leg->AddEntry(vn_vnvsmass_EP, Form("%s vs mass method {EP}", Ytitle.Data()));
	leg->AddEntry(vn_vnvsmass_SP, Form("%s vs mass method {SP}", Ytitle.Data()));
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

	cfg_vn->SaveAs(Form("Plots_vn/cfg_comparison_%s_%s_cent%dto%d_charged%d.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high, Drawchargedparticle));
	//cfg_vn->SaveAs(Form("Plots_vn/cfg_comparison_%s_%s_cent%dto%d_charged%d.png", trigname.Data(), vnname.Data(), cent_low, cent_high, Drawchargedparticle));
}
