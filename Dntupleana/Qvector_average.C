void Qvector_average(int cent_low = 0, int cent_high = 10)
{
	TFile * input = new TFile("rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100.root");

	TH2D * h_hiBin_Dcandphi = (TH2D *) input->Get("h_hiBin_Dcandphi");
	TH2D * h_hiBin_cosnphi_v2 = (TH2D *) input->Get("h_hiBin_cosnphi_v2");
	TH2D * h_hiBin_sinnphi_v2 = (TH2D *) input->Get("h_hiBin_sinnphi_v2");
	TH2D * h_hiBin_cosnphi_v3 = (TH2D *) input->Get("h_hiBin_cosnphi_v3");
	TH2D * h_hiBin_sinnphi_v3 = (TH2D *) input->Get("h_hiBin_sinnphi_v3");

	TH1D * h_Dcandphi = h_hiBin_Dcandphi->ProjectionY("h_Dcandphi",2*cent_low+1,2*cent_high,"e");
	TH1D * h_cosnphi_v2 = h_hiBin_cosnphi_v2->ProjectionY("h_cosnphi_v2",2*cent_low+1,2*cent_high,"e");
	TH1D * h_sinnphi_v2 = h_hiBin_sinnphi_v2->ProjectionY("h_sinnphi_v2",2*cent_low+1,2*cent_high,"e");
	TH1D * h_cosnphi_v3 = h_hiBin_cosnphi_v3->ProjectionY("h_cosnphi_v3",2*cent_low+1,2*cent_high,"e");
	TH1D * h_sinnphi_v3 = h_hiBin_sinnphi_v3->ProjectionY("h_sinnphi_v3",2*cent_low+1,2*cent_high,"e");

	cout << "h_cosnphi_v2: " << h_cosnphi_v2->GetMean() << " h_sinnphi_v2: " << h_sinnphi_v2->GetMean() << endl;
	cout << "h_cosnphi_v3: " << h_cosnphi_v3->GetMean() << " h_sinnphi_v3: " << h_sinnphi_v3->GetMean() << endl;

	TFile * output = new TFile(Form("otherstudy_rootfiles/Qvector_average_cent%dto%d.root",cent_low,cent_high),"RECREATE");
	h_Dcandphi->Write();
	h_cosnphi_v2->Write();
	h_sinnphi_v2->Write();
	h_cosnphi_v3->Write();
	h_sinnphi_v3->Write();
	output->Close();
}
