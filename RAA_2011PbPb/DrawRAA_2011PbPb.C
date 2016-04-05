void DrawRAA_2011PbPb()
{
	TFile * input = new TFile("PromptRAA_D0_PbPb_spectrum_fonll_effunpre_cent0to100_ptbin12_y1_dataplusfonll.root");

	TGraphAsymmErrors * D0_fonll_raa_errorsys = ( TGraphAsymmErrors *) input->Get("D0_fonll_raa_errorsys");
	TGraphAsymmErrors * D0_fonll_raa_errorfonll = ( TGraphAsymmErrors *) input->Get("D0_fonll_raa_errorfonll");//error from pp reference, not only fonll
	TGraphAsymmErrors * D0_fonll_raa_errordata_dataextraref = ( TGraphAsymmErrors *) input->Get("D0_fonll_raa_errordata_dataextraref");
	TGraphAsymmErrors * D0_fonll_raa_errordata_FONLLref = ( TGraphAsymmErrors *) input->Get("D0_fonll_raa_errordata_FONLLref");

	TCanvas * cfg_RAA_2011 = new TCanvas("cfg_RAA_2011", "cfg_RAA_2011");

	D0_fonll_raa_errorsys->Draw("A2");
	D0_fonll_raa_errorfonll->Draw("2same");
	D0_fonll_raa_errordata_dataextraref->Draw("psame");
	D0_fonll_raa_errordata_FONLLref->Draw("psame");
}
