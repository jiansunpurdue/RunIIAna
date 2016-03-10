#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
//#include <boost/filesystem.hpp>
#include <libgen.h>

#include <TTree.h>
#include <TFile.h>

using namespace std;
//namespace fs = boost::filesystem;

// Get entry from the forest
void GetEntry(vector<TTree*> forest, Long64_t j)
{
	for (unsigned int i=0; i<forest.size(); i++)
	{
		forest[i]->GetEntry(j);
	}

}

// Fill the output for each tree in the forest
void FillOutput(vector<TTree*> cloneForest)
{
	for (unsigned int i=0; i<cloneForest.size(); i++)
	{
		cloneForest[i]->Fill();
	}
}

// Clone a tree
void AddCloneTree(vector<TTree*> &cloneForest,TFile *outf, TTree* t, const char *treeName)
{
	// Make directory
	outf->cd();
	//outf->mkdir(dirName);
	//outf->cd(dirName);

	// Add a clone tree to the clone forest
	TTree *tClone = t->CloneTree(0);
	tClone->SetMaxTreeSize(500000000000);
	tClone->SetName(treeName);

	cloneForest.push_back(tClone);
	cout <<"size"<<" "<<cloneForest.size()<<endl;
}

// main routine
void skimDntuple(char* infname = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_withQvector_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016/Dntuple_crab_PbPb_HIMinimumBias2_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016.root", int PbPbPD = 2, int startevt = 0, int endevt = 50000, char* outputdir = "./")
{
	string outfilename;
	ostringstream oss1;
	ostringstream oss2;
	oss1 << startevt;
	oss2 << endevt;
	string outfname = string(outputdir) + "/skim_" + string(basename(infname)) + "_Evt" + oss1.str() + "to" + oss2.str() + ".root";

	cout << "infname: " << infname << "   outfname: " << outfname << endl;
	vector<TTree*> cloneForest;
	vector<TTree*> forest;

	TFile *inf = new TFile(infname);

	// take the relevant trees from the file
	TTree *ntDkpi = (TTree*)inf->Get("ntDkpi");
	TTree *ntHlt = (TTree*)inf->Get("ntHlt");
	TTree *ntHi = (TTree*)inf->Get("ntHi");
	TTree *ntSkim = (TTree*)inf->Get("ntSkim");
	TTree *ntGen = (TTree*)inf->Get("ntGen");

	ntHlt->SetBranchStatus("HLT_HIL1Centralityext010HFplusANDminusTH0ForZS_v*",0);
	ntHi->SetBranchStatus("hiEvtPlanes*",0);

	forest.push_back(ntDkpi);
	forest.push_back(ntHlt);
	forest.push_back(ntSkim);
	forest.push_back(ntGen);
	forest.push_back(ntHi);

	// define an output file
	TFile *outf = new TFile(outfname.c_str(),"recreate");

	AddCloneTree(cloneForest,outf,ntDkpi,"ntDkpi");
	AddCloneTree(cloneForest,outf,ntHlt,"ntHlt");
	AddCloneTree(cloneForest,outf,ntSkim,"ntSkim");
	AddCloneTree(cloneForest,outf,ntGen,"ntGen");
	AddCloneTree(cloneForest,outf,ntHi,"ntHi");

	// You only need the branches which can help you decide if you want to keep the event
	int Dsize;   
	ntDkpi->SetBranchAddress("Dsize",&Dsize);

	Int_t           HLT_HIL1MinimumBiasHF2AND_part1_v1; //MB2
	Int_t           HLT_HIL1MinimumBiasHF2AND_part2_v1; //MB3
	Int_t           HLT_HIL1MinimumBiasHF2AND_part3_v1; //MB4
	Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1; //MB5
	Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1; //MB6
	Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1; //MB7
	Int_t           HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1; //MB1

	ntHlt->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part1_v1", &HLT_HIL1MinimumBiasHF2AND_part1_v1);
	ntHlt->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part2_v1", &HLT_HIL1MinimumBiasHF2AND_part2_v1);
	ntHlt->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part3_v1", &HLT_HIL1MinimumBiasHF2AND_part3_v1);
	ntHlt->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1);
	ntHlt->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1);
	ntHlt->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1);
	ntHlt->SetBranchAddress("HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1", &HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1);

	// main loop
	if( endevt > ntDkpi->GetEntries() || endevt == -1 ) endevt = ntDkpi->GetEntries();

	for (Long64_t i=startevt;i<endevt;i++)
	{
		if (i%10000==0) cout <<ntDkpi->GetEntries()<<"/"<<i<<endl;
		ntDkpi->GetEntry(i);
		ntHlt->GetEntry(i);

		// if pass the selection -> accept this event
		//if ( Dsize<=0 )  continue;

		int HLT_HIL1MinimumBiasHF2AND_part_combined = HLT_HIL1MinimumBiasHF2AND_part1_v1 || HLT_HIL1MinimumBiasHF2AND_part2_v1 || HLT_HIL1MinimumBiasHF2AND_part3_v1;
		int HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part_combined = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 || HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 || HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1;
		if( PbPbPD == 2 && !HLT_HIL1MinimumBiasHF2AND_part1_v1 ) continue;
		if( PbPbPD == 3 && !HLT_HIL1MinimumBiasHF2AND_part2_v1 ) continue;
		if( PbPbPD == 4 && !HLT_HIL1MinimumBiasHF2AND_part3_v1 ) continue;
		if( PbPbPD == 5 && !( HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 && !HLT_HIL1MinimumBiasHF2AND_part_combined ) ) continue;
		if( PbPbPD == 6 && !( HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 && !HLT_HIL1MinimumBiasHF2AND_part_combined ) ) continue;
		if( PbPbPD == 7 && !( HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 && !HLT_HIL1MinimumBiasHF2AND_part_combined ) ) continue;
		if( PbPbPD == 1 && !( HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 && !HLT_HIL1MinimumBiasHF2AND_part_combined && !HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part_combined ) ) continue;

		GetEntry(forest,i);
		FillOutput(cloneForest);
	}

	for (unsigned int i=0;i<cloneForest.size();i++)
	{
		cloneForest[i]->AutoSave();
	}

	outf->Close();
}

int main(int argc, char *argv[])
{
	if( argc != 6 )
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}

	skimDntuple( argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);

	return 0;
}
