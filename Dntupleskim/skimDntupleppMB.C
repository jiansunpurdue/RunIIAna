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
void skimDntupleppMB(char* infname = "/depot/fqwang/data/sun229/Dntuple_crab_pp_MinimumBias1to20_AOD_D0Dsy1p1_tkpt0p5eta2p0_04122016.root", int PbPbPD = 0, int startevt = 0, int endevt = 50000, char* outputdir = "./")
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
	float Dpt[15000];
	float Dy[15000];
	float Dtrk1Pt[15000];
	float Dtrk2Pt[15000];
	float Dalpha[15000];
	float DsvpvDistance[15000];
	float DsvpvDisErr[15000];

	ntDkpi->SetBranchAddress("Dsize",&Dsize);
	ntDkpi->SetBranchAddress("Dpt",Dpt);
	ntDkpi->SetBranchAddress("Dy",Dy);
	ntDkpi->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	ntDkpi->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
	ntDkpi->SetBranchAddress("Dalpha",Dalpha);
	ntDkpi->SetBranchAddress("DsvpvDistance",DsvpvDistance);
	ntDkpi->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);

	// main loop
	if( endevt > ntDkpi->GetEntries() || endevt == -1 ) endevt = ntDkpi->GetEntries();

	for (Long64_t i=startevt;i<endevt;i++)
	{
		if (i%10000==0) cout <<ntDkpi->GetEntries()<<"/"<<i<<endl;
		ntDkpi->GetEntry(i);

		//if pass the selection -> accept this event
		if ( Dsize<=0 )  continue;

//		int ncand=0;
//		for (int j=0;j<Dsize;j++) {
//			if ( 
//				( Dpt[j] > 0.0 && Dpt[j] < 4.0 && Dtrk1Pt[j]>0.7 && Dtrk2Pt[j]>0.7 && Dy[j]>-1.1 && Dy[j]<1.1 && Dalpha[j] < 0.12 && DsvpvDistance[j]/DsvpvDisErr[j]>5.5) || 
//				( Dpt[j] >= 4.0 && Dpt[j] < 8.0 && Dtrk1Pt[j]>0.7 && Dtrk2Pt[j]>0.7 && Dy[j]>-1.1 && Dy[j]<1.1 && Dalpha[j] < 0.12 && DsvpvDistance[j]/DsvpvDisErr[j]>4.5) || 
//				( Dpt[j] >= 8.0 && Dpt[j] < 50.0 && Dtrk1Pt[j]>0.7 && Dtrk2Pt[j]>0.7 && Dy[j]>-1.1 && Dy[j]<1.1 && Dalpha[j] < 0.12 && DsvpvDistance[j]/DsvpvDisErr[j]>3.0)
//			   ) 
//			{
//				ncand++;
//				break;
//			}
//		}
//
//		if (ncand <= 0) continue;


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

	skimDntupleppMB( argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);

	return 0;
}
