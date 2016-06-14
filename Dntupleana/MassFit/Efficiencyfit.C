#include <iostream>
#include <iomanip>
#include <utility>
#include <TFile.h>
#include <TDirectoryFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH2D.h>
#include <TString.h>
#include <TProfile.h>
#include <TEfficiency.h>
#include <TGraph.h>
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

#define Nptbinnew 14 

double ptbinsnew[Nptbinnew+1] = { 1, 2, 3, 4, 6, 8, 10, 12, 14, 16, 20, 25, 30, 35, 40};

using namespace std;

void Efficiencyfit(TString filenamemc = "./../rootfiles/anaDntuple_ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight_Cent-0to100_Evt0to-1.root", bool isPbPb = false, TString MBorDtrig = "MBtrig", int centlow = 0, int centhigh = 100, float ptmin = 1.0, float ptmax = 40.0)
//void Efficiencyfit(TString filenamemc = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Cent-0to100_Evt0to-1.root", bool isPbPb = false, TString MBorDtrig = "MBtrig", int centlow = 0, int centhigh = 100, float ptmin = 1.0, float ptmax = 40.0)
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * inputMC = new TFile(filenamemc);

	TH1D * Gen_D0_pt;
	TH1D * MBmatched_allcuts_D0_pt;
	Gen_D0_pt = (TH1D *) inputMC->Get("Gen_D0_pt_ptweight_finebins");
	MBmatched_allcuts_D0_pt = (TH1D *) inputMC->Get("MBmatched_allcuts_D0_pt_ptweight_finebins");

	TH1D * Gen_D0_pt_Rebin = (TH1D *) Gen_D0_pt->Rebin( Nptbinnew, "Gen_D0_pt_Rebin", ptbinsnew);
	TH1D * MBmatched_allcuts_D0_pt_Rebin = (TH1D *) MBmatched_allcuts_D0_pt->Rebin( Nptbinnew, "MBmatched_allcuts_D0_pt_Rebin", ptbinsnew);
	
	TH1D * h_accxeff = (TH1D *) MBmatched_allcuts_D0_pt_Rebin->Clone("h_accxeff");
	h_accxeff->SetTitle("h_accxeff");
	h_accxeff->Divide( MBmatched_allcuts_D0_pt_Rebin, Gen_D0_pt_Rebin, 1.0, 1.0, "B");
	h_accxeff->SetBinContent( 1, 0.2*h_accxeff->GetBinContent(2));
	
	TCanvas * cfg_efffit = new TCanvas("cfg_efffit","cfg_efffit",600,600);

	TF1 * func = new TF1( "func", "TMath::Erf([0]+[1]*x)*0.5*(1-[2])", ptmin, ptmax);
	//TF1 * func = new TF1( "func", "[0]+[1]*x+[2]*x*x+[3]*x*x*x", ptmin, ptmax);
	func->SetLineColor(2);
	func->SetLineStyle(2);
	h_accxeff->Fit( "func", "", "", ptmin, ptmax);
	h_accxeff->Fit( "func", "", "", ptmin, ptmax);
	h_accxeff->Fit( "func", "", "", ptmin, ptmax);
	h_accxeff->Fit( "func", "", "", ptmin, ptmax);
	h_accxeff->Fit( "func", "", "", ptmin, ptmax);

	h_accxeff->GetXaxis()->SetRangeUser(ptmin+0.2, ptmax-0.2);
	h_accxeff->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
	h_accxeff->GetYaxis()->SetTitle("Efficiency");

	h_accxeff->Draw();

	cfg_efffit->SaveAs("Plots_random/Efficiency_fit_cent0to100.pdf");
}
