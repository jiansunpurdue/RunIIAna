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

////for MC
//#define NCentbins 9
//double hibinbins[NCentbins+1] = { -0.5, 9.5, 29.5, 69.5, 79.5, 99.5, 119.5, 139.5, 179.5, 199.5};
//#define NCentbins 6
//double hibinbins[NCentbins+1] = { -0.5, 9.5, 39.5, 79.5, 119.5, 159.5, 199.5};

void EP_resolution_3subevent(TString infilename = "rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root")
{
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();
	void Calculate_EPreso_EP( TH1D * h_EPreso_EP, string EPname, TProfile * h_hiBin_cosndiffepAB, TProfile * h_hiBin_cosndiffepAC, TProfile * h_hiBin_cosndiffepBC);

	TFile * inputfile = new TFile(infilename);

	TProfile * h_v2_hiBin_HFm_cosndiffepAB = (TProfile *) inputfile->Get("h_v2_hiBin_HFm_cosndiffepAB");
	TProfile * h_v2_hiBin_HFm_cosndiffepAC = (TProfile *) inputfile->Get("h_v2_hiBin_HFm_cosndiffepAC");
	TProfile * h_v2_hiBin_HFm_cosndiffepBC = (TProfile *) inputfile->Get("h_v2_hiBin_HFm_cosndiffepBC");
	TProfile * h_v2_hiBin_HFp_cosndiffepAB = (TProfile *) inputfile->Get("h_v2_hiBin_HFp_cosndiffepAB");
	TProfile * h_v2_hiBin_HFp_cosndiffepAC = (TProfile *) inputfile->Get("h_v2_hiBin_HFp_cosndiffepAC");
	TProfile * h_v2_hiBin_HFp_cosndiffepBC = (TProfile *) inputfile->Get("h_v2_hiBin_HFp_cosndiffepBC");

	TProfile * h_v3_hiBin_HFm_cosndiffepAB = (TProfile *) inputfile->Get("h_v3_hiBin_HFm_cosndiffepAB");
	TProfile * h_v3_hiBin_HFm_cosndiffepAC = (TProfile *) inputfile->Get("h_v3_hiBin_HFm_cosndiffepAC");
	TProfile * h_v3_hiBin_HFm_cosndiffepBC = (TProfile *) inputfile->Get("h_v3_hiBin_HFm_cosndiffepBC");
	TProfile * h_v3_hiBin_HFp_cosndiffepAB = (TProfile *) inputfile->Get("h_v3_hiBin_HFp_cosndiffepAB");
	TProfile * h_v3_hiBin_HFp_cosndiffepAC = (TProfile *) inputfile->Get("h_v3_hiBin_HFp_cosndiffepAC");
	TProfile * h_v3_hiBin_HFp_cosndiffepBC = (TProfile *) inputfile->Get("h_v3_hiBin_HFp_cosndiffepBC");

	TH1D * h_v2_EPreso_HFm_EP = new TH1D( "h_v2_EPreso_HFm_EP", "h_v2_EPreso_HFm_EP", NCentbins, hibinbins);
	TH1D * h_v2_EPreso_HFp_EP = new TH1D( "h_v2_EPreso_HFp_EP", "h_v2_EPreso_HFp_EP", NCentbins, hibinbins);
	Calculate_EPreso_EP( h_v2_EPreso_HFm_EP, "HFm2", h_v2_hiBin_HFm_cosndiffepAB, h_v2_hiBin_HFm_cosndiffepAC, h_v2_hiBin_HFm_cosndiffepBC);
	Calculate_EPreso_EP( h_v2_EPreso_HFp_EP, "HFp2", h_v2_hiBin_HFp_cosndiffepAB, h_v2_hiBin_HFp_cosndiffepAC, h_v2_hiBin_HFp_cosndiffepBC);

	TH1D * h_v3_EPreso_HFm_EP = new TH1D( "h_v3_EPreso_HFm_EP", "h_v3_EPreso_HFm_EP", NCentbins, hibinbins);
	TH1D * h_v3_EPreso_HFp_EP = new TH1D( "h_v3_EPreso_HFp_EP", "h_v3_EPreso_HFp_EP", NCentbins, hibinbins);
	Calculate_EPreso_EP( h_v3_EPreso_HFm_EP, "HFm3", h_v3_hiBin_HFm_cosndiffepAB, h_v3_hiBin_HFm_cosndiffepAC, h_v3_hiBin_HFm_cosndiffepBC);
	Calculate_EPreso_EP( h_v3_EPreso_HFp_EP, "HFp3", h_v3_hiBin_HFp_cosndiffepAB, h_v3_hiBin_HFp_cosndiffepAC, h_v3_hiBin_HFp_cosndiffepBC);
}

void Calculate_EPreso_EP( TH1D * h_EPreso_EP, string EPname, TProfile * h_hiBin_cosndiffepAB, TProfile * h_hiBin_cosndiffepAC, TProfile * h_hiBin_cosndiffepBC)
{
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

    for( int ibin = 0; ibin < NCentbins; ibin++  )
    {
		h_EPreso_EP->SetBinContent( ibin+1, TMath::Sqrt( h_hiBin_cosndiffepAB->GetBinContent(ibin+1) * h_hiBin_cosndiffepAC->GetBinContent(ibin+1) / h_hiBin_cosndiffepBC->GetBinContent(ibin+1) ));
	}

	cout << EPname<< " Resolution for EP: ";
	for( int ibin = 0; ibin < NCentbins; ibin++  )
		cout << h_EPreso_EP->GetBinContent( ibin+1 ) << ", ";
	cout << endl;
}
