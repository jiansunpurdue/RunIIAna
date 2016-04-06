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

void Draw_vn_centrality( TString filecent0to10 = "rootfiles/vn_vnvsmass_MBtrig_SP_cent0to10.root", 
                         TString filecent10to30 = "rootfiles/vn_vnvsmass_MBtrig_SP_cent10to30.root",
                         TString filecent30to50 = "rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50.root", 
						 TString filecent50to70 = "rootfiles/vn_vnvsmass_MBtrig_SP_cent50to70.root")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	void Draw_vn(TH1D * vn_cent0to10, TH1D * vn_cent10to30, TH1D * vn_cent30to50, TH1D * vn_cent50to70, TString vnname = "v2_SP", TString Ytitle = "v_{2}{SP}");

	TFile * inputcent0to10 = new TFile(filecent0to10);
	TFile * inputcent10to30 = new TFile(filecent10to30);
	TFile * inputcent30to50 = new TFile(filecent30to50);
	TFile * inputcent50to70 = new TFile(filecent50to70);

	TH1D * v2_cent0to10 = (TH1D *) inputcent0to10->Get("h_v2_pt");
	TH1D * v2_cent10to30 = (TH1D *) inputcent10to30->Get("h_v2_pt");
	TH1D * v2_cent30to50 = (TH1D *) inputcent30to50->Get("h_v2_pt");
	TH1D * v2_cent50to70 = (TH1D *) inputcent50to70->Get("h_v2_pt");

	Draw_vn( v2_cent0to10, v2_cent10to30, v2_cent30to50, v2_cent50to70, "v2_SP", "v_{2}{SP}");
}

void Draw_vn(TH1D * vn_cent0to10, TH1D * vn_cent10to30, TH1D * vn_cent30to50, TH1D * vn_cent50to70, TString vnname = "v2_SP", TString Ytitle = "v_{2}{SP}")
{
	TCanvas * cfg_vn_centrality = new TCanvas(Form("cfg_%s_centrality", vnname.Data()), Form("cfg_%s_centrality", vnname.Data()));

	vn_cent10to30->SetLineColor(4.0);
	vn_cent10to30->SetMarkerColor(4.0);

	vn_cent30to50->SetLineColor(2.0);
	vn_cent30to50->SetMarkerColor(2.0);

	vn_cent50to70->SetLineColor(8.0);
	vn_cent50to70->SetMarkerColor(8.0);

	vn_cent0to10->GetYaxis()->SetTitle(Ytitle);

	vn_cent0to10->Draw();
	vn_cent10to30->Draw("same");
	vn_cent30to50->Draw("same");
	vn_cent50to70->Draw("same");

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);
    fun->Draw("same");

	TLegend * leg = new TLegend(0.45, 0.67, 0.65, 0.90);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry( vn_cent0to10, "Cent. 0-10%");
	leg->AddEntry( vn_cent10to30, "Cent. 10-30%");
	leg->AddEntry( vn_cent30to50, "Cent. 30-50%");
	leg->AddEntry( vn_cent50to70, "Cent. 50-70%");
	leg->Draw();

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

	cfg_vn_centrality->SaveAs(Form("Plots_vn/cfg_%s_centrality.pdf", vnname.Data()));
}
