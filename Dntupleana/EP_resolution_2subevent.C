#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TF1.h>
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

void EP_resolution_2subevent(TString infilename = "rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to100.root")
{
	TH1::SetDefaultSumw2();

	TFile * inputfile = new TFile(infilename);

	TProfile * h_v1_hiBin_cosndiffeppepm = (TProfile *) inputfile->Get("h_v1_hiBin_cosndiffeppepm");
	TProfile * h_v2_hiBin_cosndiffeppepm = (TProfile *) inputfile->Get("h_v2_hiBin_cosndiffeppepm");
	TProfile * h_v3_hiBin_cosndiffeppepm = (TProfile *) inputfile->Get("h_v3_hiBin_cosndiffeppepm");
	TProfile * h_v4_hiBin_cosndiffeppepm = (TProfile *) inputfile->Get("h_v4_hiBin_cosndiffeppepm");

	TH1D * h_v1_EPreso = new TH1D( "h_v1_EPreso", "h_v1_EPreso", NCentbins, hibinbins);
	TH1D * h_v2_EPreso = new TH1D( "h_v2_EPreso", "h_v2_EPreso", NCentbins, hibinbins);
	TH1D * h_v3_EPreso = new TH1D( "h_v3_EPreso", "h_v3_EPreso", NCentbins, hibinbins);
	TH1D * h_v4_EPreso = new TH1D( "h_v4_EPreso", "h_v4_EPreso", NCentbins, hibinbins);

	for( int ibin = 0; ibin < NCentbins; ibin++  )
	{
		h_v1_EPreso->SetBinContent( ibin+1, TMath::Sqrt( h_v1_hiBin_cosndiffeppepm->GetBinContent(ibin+1) ));
		h_v2_EPreso->SetBinContent( ibin+1, TMath::Sqrt( h_v2_hiBin_cosndiffeppepm->GetBinContent(ibin+1) ));
		h_v3_EPreso->SetBinContent( ibin+1, TMath::Sqrt( h_v3_hiBin_cosndiffeppepm->GetBinContent(ibin+1) ));
		h_v4_EPreso->SetBinContent( ibin+1, TMath::Sqrt( h_v4_hiBin_cosndiffeppepm->GetBinContent(ibin+1) ));

		h_v1_EPreso->SetBinError( ibin+1, h_v1_hiBin_cosndiffeppepm->GetBinError(ibin+1)/( 2.0 * h_v1_EPreso->GetBinContent(ibin+1)));
		h_v2_EPreso->SetBinError( ibin+1, h_v2_hiBin_cosndiffeppepm->GetBinError(ibin+1)/( 2.0 * h_v2_EPreso->GetBinContent(ibin+1)));
		h_v3_EPreso->SetBinError( ibin+1, h_v3_hiBin_cosndiffeppepm->GetBinError(ibin+1)/( 2.0 * h_v3_EPreso->GetBinContent(ibin+1)));
		h_v4_EPreso->SetBinError( ibin+1, h_v4_hiBin_cosndiffeppepm->GetBinError(ibin+1)/( 2.0 * h_v4_EPreso->GetBinContent(ibin+1)));
	}

	cout << "EP_v1: ";
	for( int ibin = 0; ibin < NCentbins; ibin++  )
		cout << h_v1_EPreso->GetBinContent( ibin+1 ) << ", ";
	cout << endl;
	cout << "EP_v2: ";
	for( int ibin = 0; ibin < NCentbins; ibin++  )
		cout << h_v2_EPreso->GetBinContent( ibin+1 ) << ", ";
	cout << endl;
	cout << "EP_v3: ";
	for( int ibin = 0; ibin < NCentbins; ibin++  )
		cout << h_v3_EPreso->GetBinContent( ibin+1 ) << ", ";
	cout << endl;
	cout << "EP_v4: ";
	for( int ibin = 0; ibin < NCentbins; ibin++  )
		cout << h_v4_EPreso->GetBinContent( ibin+1 ) << ", ";
	cout << endl;

	TFile * output = new TFile("Output_EPresolution_2subevt.root","RECREATE");

	h_v1_EPreso->Write();
	h_v2_EPreso->Write();
	h_v3_EPreso->Write();
	h_v4_EPreso->Write();
	output->Close();
}
