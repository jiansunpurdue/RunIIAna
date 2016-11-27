#include <TTree.h>
#include <TFile.h>
#include <TDirectory.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "EventMatchingCMS.h"

void Match_Evt_forDntuple(TString file1 = "/data/jisun/PbPb2015/Production_setup0514/Dntuple_crab_PbPb_HIMinimumBias3_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON.root", TString file2 = "/data/jisun/PbPb2015/EPCalibration_calodefault_trackeronly_noDfinder_v2v3etagap_11242016/crab_PbPb_HIMinimumBias3_noDfinder_EPCalifortkonly_calodf_v2v3etagap_TrackerOnly_JSON_11242016.root", TString outputfile = "/data/jisun/PbPb2015/EvtMatching_EPCalibration_calodefault_trackeronly_v2v3etagap_11242016_Production_setup0514/Dntuple_crab_PbPb_HIMinimumBias3_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON_EvtMatch_EPCalibration_calodefault_11242016.root")
{
	TFile * input1 = new TFile(file1);
	TFile * input2 = new TFile(file2);

	TTree * ntHi_1 = (TTree *) input1->Get("ntHi");
	TTree * ntHlt_1 = (TTree *) input1->Get("ntHlt");
	TTree * ntDkpi_1 = (TTree *) input1->Get("ntDkpi");
	TTree * ntSkim_1 = (TTree *) input1->Get("ntSkim");

	TTree * ntHi_2 = (TTree *) input2->Get("hiEvtAnalyzer/HiTree");

	TFile * outfile = new TFile(outputfile,"RECREATE");

	TTree * ntHi_out = (TTree *) ntHi_2->CloneTree(0);
	TTree * ntHlt_out = (TTree *) ntHlt_1->CloneTree(0);
	TTree * ntDkpi_out = (TTree *) ntDkpi_1->CloneTree(0);
	TTree * ntSkim_out = (TTree *) ntSkim_1->CloneTree(0);
	TTree * ntHi_out_old = (TTree *) ntHi_1->CloneTree(0);

	ntHi_out->SetName("ntHi");

	ntHi_1->SetName("ntHi_1"); 
	ntHlt_1->SetName("ntHlt_1");
	ntDkpi_1->SetName("ntDkpi_1");
	ntSkim_1->SetName("ntSkim_1");
	ntHi_2->SetName("ntHi_2");
	ntHi_out_old->SetName("ntHi_out_old");

	UInt_t run1, run2;
	ULong64_t event1, event2;
	UInt_t lumi1, lumi2;

	ntHi_1->SetBranchAddress("run",&run1);
	ntHi_1->SetBranchAddress("evt",&event1);
	ntHi_1->SetBranchAddress("lumi",&lumi1);

	ntHi_2->SetBranchAddress("run",&run2);
	ntHi_2->SetBranchAddress("evt",&event2);
	ntHi_2->SetBranchAddress("lumi",&lumi2);

	EventMatchingCMS * EvtMatch = new EventMatchingCMS();

	cout << "----- Begin build map" << endl;

	for( Long64_t ientry = 0; ientry < ntHi_2->GetEntries(); ientry++ )
	{
		if( ientry%5000000 == 0 ) cout << " entry: " << ientry << endl;
		ntHi_2->GetEntry(ientry);
		EvtMatch->addEvent( event2, lumi2, run2, ientry);
	}

	cout << "----- Match map done" << endl;

	for( Long64_t ientry1 = 0; ientry1 < ntHi_1->GetEntries(); ientry1++)
	{
		if( ientry1%5000000 == 0 ) cout << " entry: " << ientry1 << endl;

		ntHi_1->GetEntry(ientry1);

		Long64_t ientry2 = EvtMatch->retrieveEvent( event1, lumi1, run1);

		if( ientry2 < 0 ) continue;
		
		//get the entry for ther trees
		ntHlt_1->GetEntry(ientry1);
		ntDkpi_1->GetEntry(ientry1); 
		ntSkim_1->GetEntry(ientry1);
		ntHi_2->GetEntry(ientry2); 

		if( event1 != event2 || lumi1 != lumi2 || run1 != run2 ) 
		{
			cout << "----- Error Error Error" << endl;
			exit(2);
		}

		ntHi_out->Fill();
		ntHlt_out->Fill();
		ntDkpi_out->Fill();
		ntSkim_out->Fill();
		ntHi_out_old->Fill();
	}

//	outfile->cd();
	ntHi_out->Write();
	ntHlt_out->Write();
	ntDkpi_out->Write();
	ntSkim_out->Write();
	ntHi_out_old->Write();

	outfile->Close();

	cout << "----- Event match done" << endl;
}
