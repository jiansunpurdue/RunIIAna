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

using namespace std;

#define Nptbin 14
float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};

//cut w/o DCA cut, need to plus the prompt or non-prompt cut
TCut cutPbPbMB_noDCA = "Dgen==23333&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1PixelHit+Dtrk1StripHit>10.5&&Dtrk2PixelHit+Dtrk2StripHit>10.5&&Dtrk1Chi2ndf/(Dtrk1nStripLayer+Dtrk1nPixelLayer)<=0.15&&Dtrk2Chi2ndf/(Dtrk2nStripLayer+Dtrk2nPixelLayer)<=0.15&&Dtrk1Pt>0.7&&Dtrk2Pt>0.7&&Dtrk1PtErr/Dtrk1Pt<0.1&&Dtrk2PtErr/Dtrk2Pt<0.1&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&(Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.5&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>3.0&&Dchi2cl>0.05)))";

void Calculate_DCAcut_efficiency( bool isPrompt = true, TString filenameinputMC = "/depot/fqwang/data/sun229/Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight.root", TH1D * h_DCAeff = NULL)
//void DCAcut_efficiency( bool isPrompt = false, TString filenameinputMC = "/depot/fqwang/data/sun229/ntD_EvtBase_20160618_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_nonprompt_Dpt1Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root")
{
	TCut cut_pornp = NULL;
	if( isPrompt )
		cut_pornp = "DgenBAncestorpt < 0";
	else
		cut_pornp = "DgenBAncestorpt > 0";

	TFile * inputMC = new TFile(filenameinputMC);
	TTree * ntDkpi = (TTree *) inputMC->Get("ntDkpi");

	TH1D * h_pt_noDCAcut = new TH1D("h_pt_noDCAcut","h_pt_noDCAcut",Nptbin,ptbins); 
	TH1D * h_pt_DCAcut = new TH1D("h_pt_DCAcut","h_pt_DCAcut",Nptbin,ptbins);

	ntDkpi->Project("h_pt_noDCAcut","Dpt",cutPbPbMB_noDCA&&cut_pornp);
	ntDkpi->Project("h_pt_DCAcut","Dpt",cutPbPbMB_noDCA&&cut_pornp&&"DsvpvDistance * TMath::Sin(Dalpha) < 0.008");

	h_DCAeff->Divide(h_pt_DCAcut,h_pt_noDCAcut,1.0,1.0,"B");

	TCanvas * cfg_DCAeff = new TCanvas(Form("cfg_DCAeff_prompt%d",isPrompt),Form("cfg_DCAeff_prompt%d",isPrompt),600,600);

	if( isPrompt )
	{
		h_DCAeff->SetLineColor(2.0);
		h_DCAeff->SetMarkerColor(2.0);
		h_DCAeff->SetMarkerStyle(20);
	}
	else
	{
		h_DCAeff->SetLineColor(4.0);
		h_DCAeff->SetMarkerColor(4.0);
		h_DCAeff->SetMarkerStyle(21);
	}

	h_DCAeff->GetXaxis()->SetRangeUser(0.1,39.);
	h_DCAeff->GetYaxis()->SetRangeUser(0.,1.);
	h_DCAeff->GetYaxis()->SetTitle("DCA cut efficiency");
	h_DCAeff->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	h_DCAeff->Draw();

	TLegend *  leg = new TLegend(0.55, 0.60, 0.65, 0.70);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	if( isPrompt ) 
		leg->AddEntry( (TObject*)0, "Prompt D^{0}" , "");
	else
		leg->AddEntry( (TObject*)0, "Non-prompt D^{0}" , "");
	leg->Draw();

	cfg_DCAeff->SaveAs(Form("cfg_DCAeff_prompt%d.pdf",isPrompt));
}

void DCAcut_efficiency()
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TH1D * h_DCAeff_prompt = new TH1D("h_DCAeff_prompt","h_DCAeff_prompt",Nptbin,ptbins);
	TH1D * h_DCAeff_nonprompt = new TH1D("h_DCAeff_nonprompt","h_DCAeff_nonprompt",Nptbin,ptbins);

	Calculate_DCAcut_efficiency( true, "/depot/fqwang/data/sun229/Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight.root", h_DCAeff_prompt);
	Calculate_DCAcut_efficiency( false, "/depot/fqwang/data/sun229/ntD_EvtBase_20160618_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_nonprompt_Dpt1Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root", h_DCAeff_nonprompt);

	TCanvas * cfg_DCAeff = new TCanvas("cfg_DCAeff","cfg_DCAeff");
	h_DCAeff_prompt->Draw();
	h_DCAeff_nonprompt->Draw("same");

	TLegend *  leg = new TLegend(0.55, 0.62, 0.75, 0.75);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry( h_DCAeff_prompt, "Prompt D^{0}");
	leg->AddEntry( h_DCAeff_nonprompt, "Non-prompt D^{0}");
	leg->Draw();

	TFile * output = new TFile("DCAeff_prompt.root","RECREATE");
	h_DCAeff_prompt->Write();
	h_DCAeff_nonprompt->Write();
	output->Close();
}
