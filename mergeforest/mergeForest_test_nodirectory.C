// mergeForest.C
// Authors Alex Barbieri and Dragos Velicanu
// Merge small HiForests into one large HiForest by combining trees.

#include <TChain.h>
#include <TFile.h>
#include <TString.h>
#include <iostream>

void mergeForest_test_nodirectory(TString fname = "/depot/cms/users/sun229/Dntuple_crab2_PbPb_HIMinimumBias6_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016/*.root",
		TString outfile="/depot/fqwang/data/sun229/Dntuple_crab2_PbPb_HIMinimumBias6_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016.root",
		bool failOnError = false)
{
	TTree::SetMaxTreeSize(1LL*1024*1024*1024*1024);
	// First, find on of the files within 'fname' and use it to make a
	// list of trees. Unfortunately we have to know in advance at least
	// one of the tree names. hiEvtAnalyzer/HiTree is a safe choice for
	// HiForests. We also assume that every TTree is inside a
	// TDirectoryFile which is in the top level of the root file.
	TFile* file = new TFile(outfile, "RECREATE");

	TChain *dummyChain = new TChain("ntHlt");
	dummyChain->Add(fname);
	TFile *testFile = dummyChain->GetFile();
	TList *topKeyList = testFile->GetListOfKeys();

	std::vector<TString> trees;

	for(int j = 0; j < topKeyList->GetEntries(); ++j)
	{
		TString treeName = topKeyList->At(j)->GetName();

		TTree* tree = (TTree*)testFile->Get(treeName);
		tree->SetMaxTreeSize(1LL*1024*1024*1024*1024);
		if(strcmp(tree->ClassName(), "TTree") != 0 && strcmp(tree->ClassName(), "TNtuple") != 0) continue;

		trees.push_back(treeName);
	}

	testFile->Close();
	delete dummyChain;

	// Now use the list of tree names to make a new root file, filling
	// it with the trees from 'fname'.
	const int Ntrees = trees.size();
	TChain* ch[Ntrees];

	long long unsigned nentries = 0;
	for(int i = 0; i < Ntrees; ++i){
		ch[i] = new TChain(trees[i]);
		ch[i]->Add(fname);
		std::cout << "Tree loaded : " << trees[i] << std::endl;
		std::cout << "Entries : " << ch[i]->GetEntries() << std::endl;

		// If the number of entries in this tree is different from other
		// trees there is a problem. Quit and inform the user without
		// producing output.
		if(failOnError)
		{
			if(strcmp(trees[i],"HiForest/HiForestVersion") == 0 || strcmp(trees[i],"ntDkpipi") == 0 || strcmp(trees[i],"ntDkpipipi") == 0 || strcmp(trees[i],"ntGen") == 0) continue;
			if(i == 0) nentries = ch[i]->GetEntries();
			else if (nentries != ch[i]->GetEntries())
			{
				std::cout << "ERROR: number of entries in this tree does not match." << std::endl;
				std::cout << "First inconsistent file: " <<ch[i]->GetFile()->GetName()<<std::endl;
				std::cout << "Exiting. Please check input." << std::endl;
				return;
			}
		}
		else
		{
			std::cout << "WARN: error checking disabled" << std::endl;
		}
	}

	file->cd();

	for(int i = 0; i < Ntrees; ++i)
	{
		file->cd();
		std::cout << trees[i] << std::endl;
		ch[i]->Merge(file,0,"keep");
		delete ch[i];
	}
	//file->Write();
	file->Close();

	std::cout << "Done. Output: " << outfile << std::endl;
}

int main(int argc, char *argv[])
{
	if((argc != 3) && (argc != 4))
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}

	if(argc == 3)
		mergeForest_test_nodirectory(argv[1], argv[2]);
	else if (argc == 4)
		mergeForest_test_nodirectory(argv[1], argv[2], argv[3]);
	return 0;
}
