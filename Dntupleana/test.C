void test()
{
    TH1::SetDefaultSumw2();
    TH2::SetDefaultSumw2();
    TH1::StatOverflows();
    TH2::StatOverflows();

	TH2D * h2 = new TH2D( "h2", "h2", 20, 0, 20, 20, 0, 20);

	h2->Fill( 10, 10);
	h2->Fill( 15, 5);
	h2->Fill( 30, 5);
	h2->Fill( -100, 15);

	//cout << "h2 x mean: " << h2->GetMean() << " y mean: " << h2->GetMean(2) << endl;

	TH1D * h1 = h2->ProjectionX("h1", 1, 8);
	//TH1D * h1 = h2->ProjectionX("h1", 13, 20);
	//TH1D * h1 = h2->ProjectionX("h1");
	
	h1->Draw("hist");

	//cout << "h1 mean: " << h1->GetMean() << endl;

	TProfile * hf = new TProfile("hf","hf",100,0,100);
	hf->Fill(1.1, 10);
	hf->Fill(1.2, 20);
	hf->Fill(1.3, 30);
	hf->Fill(2.1, 40);
	hf->Fill(2.2, 50);
	hf->Fill(2.3, 60);

	cout << "bin entries: " << hf->GetBinEntries(1) << " " << hf->GetBinEntries(2) << " " << hf->GetBinEntries(3) << endl;
	cout << "test done" << endl;

	//hf->Rebin(4);

	hf->Draw();
}
