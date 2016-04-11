void Compare_signal_sig()
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TFile * input_tight_eta1p2 = new TFile("rootfiles/Raw_spectrum_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root");
	TFile * input_tight_eta1p5 = new TFile("rootfiles/Raw_spectrum_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_tighttk_eta1p5.root");
	TFile * input_loose_eta1p2 = new TFile("rootfiles_loosetkcuts/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root");

	TH1D * h_tight_eta1p2 = (TH1D *) input_tight_eta1p2->Get("dNdpt_poly3bkg");
	h_tight_eta1p2->SetName("h_tight_eta1p2");

	TH1D * h_tight_eta1p5 = (TH1D *) input_tight_eta1p5->Get("dNdpt_poly3bkg");
	h_tight_eta1p5->SetName("h_tight_eta1p5");

	TH1D * h_loose_eta1p2 = (TH1D *) input_loose_eta1p2->Get("dNdpt_poly3bkg");
	h_loose_eta1p2->SetName("h_loose_eta1p2");

	TH1D * h_Nsigovererror_tight_eta1p2 = (TH1D *) h_tight_eta1p2->Clone("h_Nsigovererror_tight_eta1p2"); 
	TH1D * h_Nsigovererror_tight_eta1p5 = (TH1D *) h_tight_eta1p5->Clone("h_Nsigovererror_tight_eta1p5");
	TH1D * h_Nsigovererror_loose_eta1p2 = (TH1D *) h_loose_eta1p2->Clone("h_Nsigovererror_loose_eta1p2");

	for( int ibin = 0; ibin < h_tight_eta1p2->GetNbinsX(); ibin++)
	{
		h_Nsigovererror_tight_eta1p2->SetBinError( ibin+1, 0);
		h_Nsigovererror_tight_eta1p5->SetBinError( ibin+1, 0);
		h_Nsigovererror_loose_eta1p2->SetBinError( ibin+1, 0);

		if( h_tight_eta1p2->GetBinContent(ibin+1) > 0 )
		{
			h_Nsigovererror_tight_eta1p2->SetBinContent( ibin+1, h_tight_eta1p2->GetBinContent(ibin+1)/h_tight_eta1p2->GetBinError(ibin+1));
			h_Nsigovererror_tight_eta1p5->SetBinContent( ibin+1, h_tight_eta1p5->GetBinContent(ibin+1)/h_tight_eta1p5->GetBinError(ibin+1));
			h_Nsigovererror_loose_eta1p2->SetBinContent( ibin+1, h_loose_eta1p2->GetBinContent(ibin+1)/h_loose_eta1p2->GetBinError(ibin+1));
		}
	}

	TCanvas * cfg_Nsigovererror = new TCanvas("cfg_Nsigovererror","cfg_Nsigovererror");

	h_Nsigovererror_tight_eta1p2->SetLineColor(2);
	h_Nsigovererror_tight_eta1p5->SetLineColor(1);
	h_Nsigovererror_loose_eta1p2->SetLineColor(4);

	h_Nsigovererror_tight_eta1p2->SetLineWidth(2);
	h_Nsigovererror_tight_eta1p5->SetLineWidth(2);
	h_Nsigovererror_loose_eta1p2->SetLineWidth(2);

	h_Nsigovererror_tight_eta1p2->GetXaxis()->SetRangeUser(1.1, 39);
	h_Nsigovererror_tight_eta1p2->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
	h_Nsigovererror_tight_eta1p2->GetYaxis()->SetTitle("N_{sig}/#sigma(N_{sig})");

	h_Nsigovererror_tight_eta1p2->Draw("HIST");
	h_Nsigovererror_tight_eta1p5->Draw("HISTsame");
	h_Nsigovererror_loose_eta1p2->Draw("HISTsame");

	cfg_Nsigovererror->SaveAs("Plots_random/cfg_Nsigovererror.pdf");

	TCanvas * cfg_Nsigovererror_ratio = new TCanvas("cfg_Nsigovererror_ratio","cfg_Nsigovererror_ratio");
	
	TH1D * h_ratio_Nsigovererror_tight_eta1p5 = (TH1D *) h_Nsigovererror_tight_eta1p5->Clone("h_ratio_Nsigovererror_tight_eta1p5");
	TH1D * h_ratio_Nsigovererror_loose_eta1p5 = (TH1D *) h_Nsigovererror_loose_eta1p2->Clone("h_ratio_Nsigovererror_loose_eta1p5");

	h_ratio_Nsigovererror_tight_eta1p5->Divide(h_Nsigovererror_tight_eta1p2);
	h_ratio_Nsigovererror_loose_eta1p5->Divide(h_Nsigovererror_tight_eta1p2);

	h_ratio_Nsigovererror_tight_eta1p5->GetXaxis()->SetRangeUser(1.1, 39);
	h_ratio_Nsigovererror_tight_eta1p5->GetYaxis()->SetRangeUser(0.5, 1.2);
	h_ratio_Nsigovererror_tight_eta1p5->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
	h_ratio_Nsigovererror_tight_eta1p5->GetYaxis()->SetTitle("Ratio");

	h_ratio_Nsigovererror_tight_eta1p5->Draw("HIST");
	h_ratio_Nsigovererror_loose_eta1p5->Draw("HISTsame");

	cfg_Nsigovererror_ratio->SaveAs("Plots_random/cfg_Nsigovererror_ratio.pdf");
}
