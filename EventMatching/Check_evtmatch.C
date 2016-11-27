#include <TTree.h>
#include <TFile.h>
#include <TDirectory.h>
#include <iostream>
#include <iomanip>
#include <fstream>

void Check_evtmatch( TString inputfilename = "/data/jisun/PbPb2015/EvtMatching_EPCalibration_calodefault_trackeronly_v2v3etagap_11242016_Production_setup0514/Dntuple_crab_PbPb_HIMinimumBias3_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON_EvtMatch_EPCalibration_calodefault_11242016.root")
{
	TFile * inputfile = new TFile(inputfilename);

	TTree * ntHi = (TTree *) inputfile->Get("ntHi");
	TTree * ntHi_old = (TTree *) inputfile->Get("ntHi_out_old");
	TTree * ntHlt = (TTree *) inputfile->Get("ntHlt");

	//For event tree
	UInt_t run1, run2;
    ULong64_t event1, event2;
    UInt_t lumi1, lumi2;

	//For HLT tree
	unsigned long long Event;
	int Lumi;
	int Run;

    ntHi->SetBranchAddress("run",&run1);
    ntHi->SetBranchAddress("evt",&event1);
    ntHi->SetBranchAddress("lumi",&lumi1);

    ntHi_old->SetBranchAddress("run",&run2);
    ntHi_old->SetBranchAddress("evt",&event2);
    ntHi_old->SetBranchAddress("lumi",&lumi2);

    ntHlt->SetBranchAddress("Run",&Run);
    ntHlt->SetBranchAddress("Event",&Event);
    ntHlt->SetBranchAddress("LumiBlock",&Lumi);

	for( Long64_t ientry = 0; ientry < ntHi->GetEntries(); ientry++ )
	{
		ntHi->GetEntry(ientry);
		ntHi_old->GetEntry(ientry);
		ntHlt->GetEntry(ientry);

		if( ientry%5000000 == 0 ) cout << " entry: " << ientry << endl;

		if( run1 != run2 || event1 != event2 || lumi1 != lumi2 )
		{
			cout << "--- Error Error Error" << endl;
			exit(2);
		}

		if( run1 != Run || event1 != Event || lumi1 != Lumi )
		{
			cout << "--- Error Error Error" << endl;
			exit(2);
		}
	}

	cout << "--- All good. Done" << endl;

	inputfile->Close();
}
