void Qvector_average(int cent_low = 50, int cent_high = 70)
{
	TFile * input = new TFile("rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100.root");

	TH2D * h_hiBin_Dcandphi = (TH2D *) input->Get("h_hiBin_Dcandphi");
	TH2D * h_hiBin_cosnphi_v2 = (TH2D *) input->Get("h_hiBin_cosnphi_v2");
	TH2D * h_hiBin_sinnphi_v2 = (TH2D *) input->Get("h_hiBin_sinnphi_v2");
	TH2D * h_hiBin_cosnphi_v3 = (TH2D *) input->Get("h_hiBin_cosnphi_v3");
	TH2D * h_hiBin_sinnphi_v3 = (TH2D *) input->Get("h_hiBin_sinnphi_v3");

	TProfile * h_hiBin_Dcandphi_profile = (TProfile *) input->Get("h_hiBin_Dcandphi_profile");
	TProfile * h_hiBin_cosnphi_v2_profile = (TProfile *) input->Get("h_hiBin_cosnphi_v2_profile");
	TProfile * h_hiBin_sinnphi_v2_profile = (TProfile *) input->Get("h_hiBin_sinnphi_v2_profile");
	TProfile * h_hiBin_cosnphi_v3_profile = (TProfile *) input->Get("h_hiBin_cosnphi_v3_profile");
	TProfile * h_hiBin_sinnphi_v3_profile = (TProfile *) input->Get("h_hiBin_sinnphi_v3_profile");

	TH1D * h_Dcandphi = h_hiBin_Dcandphi->ProjectionY("h_Dcandphi",2*cent_low+1,2*cent_high,"e");
	TH1D * h_cosnphi_v2 = h_hiBin_cosnphi_v2->ProjectionY("h_cosnphi_v2",2*cent_low+1,2*cent_high,"e");
	TH1D * h_sinnphi_v2 = h_hiBin_sinnphi_v2->ProjectionY("h_sinnphi_v2",2*cent_low+1,2*cent_high,"e");
	TH1D * h_cosnphi_v3 = h_hiBin_cosnphi_v3->ProjectionY("h_cosnphi_v3",2*cent_low+1,2*cent_high,"e");
	TH1D * h_sinnphi_v3 = h_hiBin_sinnphi_v3->ProjectionY("h_sinnphi_v3",2*cent_low+1,2*cent_high,"e");

	cout << "h_cosnphi_v2: " << h_cosnphi_v2->GetMean() << "+/-" << h_cosnphi_v2->GetMeanError() << " h_sinnphi_v2: " << h_sinnphi_v2->GetMean() << "+/-" << h_sinnphi_v2->GetMeanError() << endl;
	cout << "h_cosnphi_v3: " << h_cosnphi_v3->GetMean() << "+/-" << h_cosnphi_v3->GetMeanError() << " h_sinnphi_v3: " << h_sinnphi_v3->GetMean() << "+/-" << h_sinnphi_v3->GetMeanError() << endl;

	int ibinprofile = 0;
	if( cent_low == 0 && cent_high == 10 ) ibinprofile = 1;
	if( cent_low == 10 && cent_high == 30 ) ibinprofile = 2;
	if( cent_low == 30 && cent_high == 50 ) ibinprofile = 3;
	if( cent_low == 50 && cent_high == 70 ) ibinprofile = 4;

	cout << " ibinprofile::::::::: " << ibinprofile << endl;

	cout << "h_cosnphi_v2_profile: " << h_hiBin_cosnphi_v2_profile->GetBinContent(ibinprofile) << "+/-" << h_hiBin_cosnphi_v2_profile->GetBinError(ibinprofile) << " h_sinnphi_v2_profile: " << h_hiBin_sinnphi_v2_profile->GetBinContent(ibinprofile) << "+/-" << h_hiBin_sinnphi_v2_profile->GetBinError(ibinprofile) << endl;
	cout << "h_cosnphi_v3_profile: " << h_hiBin_cosnphi_v3_profile->GetBinContent(ibinprofile) << "+/-" << h_hiBin_cosnphi_v3_profile->GetBinError(ibinprofile) << " h_sinnphi_v3_profile: " << h_hiBin_sinnphi_v3_profile->GetBinContent(ibinprofile) << "+/-" << h_hiBin_sinnphi_v3_profile->GetBinError(ibinprofile) << endl;

	TFile * output = new TFile(Form("otherstudy_rootfiles/Qvector_average_cent%dto%d.root",cent_low,cent_high),"RECREATE");
	h_Dcandphi->Write();
	h_cosnphi_v2->Write();
	h_sinnphi_v2->Write();
	h_cosnphi_v3->Write();
	h_sinnphi_v3->Write();
	output->Close();
}
