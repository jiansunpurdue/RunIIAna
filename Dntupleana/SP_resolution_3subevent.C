#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TProfile.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>

#define NCentbins 6
double hibinbins[NCentbins+1] = { -0.5, 19.5, 59.5, 99.5, 139.5, 179.5, 199.5};

//void SP_resolution_3subevent(TString infilename = "rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to100.root")
void SP_resolution_3subevent(TString infilename = "anaDntuple_Dntuple_crab_PbPb_HIMinimumBias3_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root")
{
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();
	void Calculate_EPreso_SP( TH1D * h_EPreso_SP, string EPname, TProfile * h_hiBin_QAB, TProfile * h_hiBin_QAC, TProfile * h_hiBin_QBC);

	TFile * inputfile = new TFile(infilename);

	TProfile * h_v2_hiBin_HFm_QAB = (TProfile *) inputfile->Get("h_v2_hiBin_HFm_QAB");
	TProfile * h_v2_hiBin_HFm_QAC = (TProfile *) inputfile->Get("h_v2_hiBin_HFm_QAC");
	TProfile * h_v2_hiBin_HFm_QBC = (TProfile *) inputfile->Get("h_v2_hiBin_HFm_QBC");
	TProfile * h_v2_hiBin_HFp_QAB = (TProfile *) inputfile->Get("h_v2_hiBin_HFp_QAB");
	TProfile * h_v2_hiBin_HFp_QAC = (TProfile *) inputfile->Get("h_v2_hiBin_HFp_QAC");
	TProfile * h_v2_hiBin_HFp_QBC = (TProfile *) inputfile->Get("h_v2_hiBin_HFp_QBC");

	TProfile * h_v3_hiBin_HFm_QAB = (TProfile *) inputfile->Get("h_v3_hiBin_HFm_QAB");
	TProfile * h_v3_hiBin_HFm_QAC = (TProfile *) inputfile->Get("h_v3_hiBin_HFm_QAC");
	TProfile * h_v3_hiBin_HFm_QBC = (TProfile *) inputfile->Get("h_v3_hiBin_HFm_QBC");
	TProfile * h_v3_hiBin_HFp_QAB = (TProfile *) inputfile->Get("h_v3_hiBin_HFp_QAB");
	TProfile * h_v3_hiBin_HFp_QAC = (TProfile *) inputfile->Get("h_v3_hiBin_HFp_QAC");
	TProfile * h_v3_hiBin_HFp_QBC = (TProfile *) inputfile->Get("h_v3_hiBin_HFp_QBC");

	TH1D * h_v2_EPreso_HFm_SP = new TH1D( "h_v2_EPreso_HFm_SP", "h_v2_EPreso_HFm_SP", NCentbins, hibinbins);
	TH1D * h_v2_EPreso_HFp_SP = new TH1D( "h_v2_EPreso_HFp_SP", "h_v2_EPreso_HFp_SP", NCentbins, hibinbins);
	Calculate_EPreso_SP( h_v2_EPreso_HFm_SP, "HFm2", h_v2_hiBin_HFm_QAB, h_v2_hiBin_HFm_QAC, h_v2_hiBin_HFm_QBC);
	Calculate_EPreso_SP( h_v2_EPreso_HFp_SP, "HFp2", h_v2_hiBin_HFp_QAB, h_v2_hiBin_HFp_QAC, h_v2_hiBin_HFp_QBC);

	TH1D * h_v3_EPreso_HFm_SP = new TH1D( "h_v3_EPreso_HFm_SP", "h_v3_EPreso_HFm_SP", NCentbins, hibinbins);
	TH1D * h_v3_EPreso_HFp_SP = new TH1D( "h_v3_EPreso_HFp_SP", "h_v3_EPreso_HFp_SP", NCentbins, hibinbins);
	Calculate_EPreso_SP( h_v3_EPreso_HFm_SP, "HFm3", h_v3_hiBin_HFm_QAB, h_v3_hiBin_HFm_QAC, h_v3_hiBin_HFm_QBC);
	Calculate_EPreso_SP( h_v3_EPreso_HFp_SP, "HFp3", h_v3_hiBin_HFp_QAB, h_v3_hiBin_HFp_QAC, h_v3_hiBin_HFp_QBC);
}

void Calculate_EPreso_SP( TH1D * h_EPreso_SP, string EPname, TProfile * h_hiBin_QAB, TProfile * h_hiBin_QAC, TProfile * h_hiBin_QBC)
{
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

    for( int ibin = 0; ibin < NCentbins; ibin++  )
    {
		h_EPreso_SP->SetBinContent( ibin+1, TMath::Sqrt( h_hiBin_QAB->GetBinContent(ibin+1) * h_hiBin_QAC->GetBinContent(ibin+1) / h_hiBin_QBC->GetBinContent(ibin+1) ));
	}

	cout << EPname<< " Resolution for SP: ";
	for( int ibin = 0; ibin < NCentbins; ibin++  )
		cout << h_EPreso_SP->GetBinContent( ibin+1 ) << ", ";
	cout << endl;
}
