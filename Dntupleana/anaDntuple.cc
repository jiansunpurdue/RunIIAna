#include "anaDntuple.hh"
#include "EP_resolution.h"
#include "uti.h"
#include "parameters.h"

//
anaDntuple::anaDntuple()
{
}

//
anaDntuple::~anaDntuple()
{
	//    delete filename;
	delete outputfile;
}
//

void anaDntuple::Init(string outfilename)
{
	outputfile = new TFile(outfilename.c_str(), "recreate");

	ntDkpi = 0;
	ntHi = 0;
	ntSkim = 0;
	ntHlt = 0;
}

void anaDntuple::Histobookforanalysis()
{
	hevt_trig_hiBin->Sumw2();
	h_v1_hiBin_cosndiffeppepm->Sumw2();
	h_v2_hiBin_cosndiffeppepm->Sumw2();
	h_v3_hiBin_cosndiffeppepm->Sumw2();
	h_v4_hiBin_cosndiffeppepm->Sumw2();

	h_v2_hiBin_HFm_QAB->Sumw2(); h_v2_hiBin_HFm_QAC->Sumw2(); h_v2_hiBin_HFm_QBC->Sumw2();
	h_v2_hiBin_HFp_QAB->Sumw2(); h_v2_hiBin_HFp_QAC->Sumw2(); h_v2_hiBin_HFp_QBC->Sumw2();
	h_v3_hiBin_HFm_QAB->Sumw2(); h_v3_hiBin_HFm_QAC->Sumw2(); h_v3_hiBin_HFm_QBC->Sumw2();
	h_v3_hiBin_HFp_QAB->Sumw2(); h_v3_hiBin_HFp_QAC->Sumw2(); h_v3_hiBin_HFp_QBC->Sumw2();

	Gen_D0_pt_noweight_forptreweight->Sumw2();
	Gen_D0_pt_pthatweight->Sumw2(); Gen_D0_pt_ptweight->Sumw2(); Gen_D0_pt_noweight->Sumw2();
	MBmatched_allcuts_D0_pt_pthatweight->Sumw2(); MBmatched_allcuts_D0_pt_ptweight->Sumw2(); MBmatched_allcuts_D0_pt_noweight->Sumw2();
	Dtrigmatched_allcuts_D0_pt_pthatweight->Sumw2(); Dtrigmatched_allcuts_D0_pt_ptweight->Sumw2(); Dtrigmatched_allcuts_D0_pt_noweight->Sumw2();

	cout << "Begin book histogram" << endl;
	book_masshist( mc_matched_signal_noweight, ptbins, Nptbin, "mc_matched_signal_noweight", Nmassbin, massmin, massmax);
	book_masshist( mc_matched_kpiswapped_noweight, ptbins, Nptbin, "mc_matched_kpiswapped_noweight", Nmassbin, massmin, massmax);
	book_masshist( mc_matched_signal_ptweight, ptbins, Nptbin, "mc_matched_signal_ptweight", Nmassbin, massmin, massmax);
	book_masshist( mc_matched_kpiswapped_ptweight, ptbins, Nptbin, "mc_matched_kpiswapped_ptweight", Nmassbin, massmin, massmax);
	book_masshist( mc_matched_signal_pthatweight, ptbins, Nptbin, "mc_matched_signal_pthatweight", Nmassbin, massmin, massmax);
	book_masshist( mc_matched_kpiswapped_pthatweight, ptbins, Nptbin, "mc_matched_kpiswapped_pthatweight", Nmassbin, massmin, massmax);

	book_masshist( Dtrig_mc_matched_signal_noweight, ptbins, Nptbin, "Dtrig_mc_matched_signal_noweight", Nmassbin, massmin, massmax);
	book_masshist( Dtrig_mc_matched_kpiswapped_noweight, ptbins, Nptbin, "Dtrig_mc_matched_kpiswapped_noweight", Nmassbin, massmin, massmax);
	book_masshist( Dtrig_mc_matched_signal_ptweight, ptbins, Nptbin, "Dtrig_mc_matched_signal_ptweight", Nmassbin, massmin, massmax);
	book_masshist( Dtrig_mc_matched_kpiswapped_ptweight, ptbins, Nptbin, "Dtrig_mc_matched_kpiswapped_ptweight", Nmassbin, massmin, massmax);
	book_masshist( Dtrig_mc_matched_signal_pthatweight, ptbins, Nptbin, "Dtrig_mc_matched_signal_pthatweight", Nmassbin, massmin, massmax);
	book_masshist( Dtrig_mc_matched_kpiswapped_pthatweight, ptbins, Nptbin, "Dtrig_mc_matched_kpiswapped_pthatweight", Nmassbin, massmin, massmax);

	book_masshist( hmass_MB_HFandpart, ptbins, Nptbin, "hmass_MB_HFandpart_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_MB_cent30to100_trig, ptbins, Nptbin, "hmass_MB_cent30to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_MB_cent50to100_trig, ptbins, Nptbin, "hmass_MB_cent50to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_MB_cent70to100_trig, ptbins, Nptbin, "hmass_MB_cent70to100_trig", Nmassbin, massmin, massmax);

	book_masshist( hmass_Dtrig_combined, ptbins, Nptbin, "hmass_Dtrig_combined", Nmassbin, massmin, massmax);

	book_masshist( hmass_Dpt8, ptbins, Nptbin, "hmass_Dpt8_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt15, ptbins, Nptbin, "hmass_Dpt15_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt20, ptbins, Nptbin, "hmass_Dpt20_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt20_cent0to10, ptbins, Nptbin, "hmass_Dpt20_cent0to10_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt20_cent30to100, ptbins, Nptbin, "hmass_Dpt20_cent30to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt20_cent50to100, ptbins, Nptbin, "hmass_Dpt20_cent50to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt30, ptbins, Nptbin, "hmass_Dpt30_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt30_cent0to10, ptbins, Nptbin, "hmass_Dpt30_cent0to10_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt30_cent30to100, ptbins, Nptbin, "hmass_Dpt30_cent30to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt30_cent50to100, ptbins, Nptbin, "hmass_Dpt30_cent50to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt40, ptbins, Nptbin, "hmass_Dpt40_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt40_cent0to10, ptbins, Nptbin, "hmass_Dpt40_cent0to10_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt40_cent30to100, ptbins, Nptbin, "hmass_Dpt40_cent30to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt40_cent50to100, ptbins, Nptbin, "hmass_Dpt40_cent50to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt50, ptbins, Nptbin, "hmass_Dpt50_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt60, ptbins, Nptbin, "hmass_Dpt60_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt60_cent0to10, ptbins, Nptbin, "hmass_Dpt60_cent0to10_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt60_cent30to100, ptbins, Nptbin, "hmass_Dpt60_cent30to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt60_cent50to100, ptbins, Nptbin, "hmass_Dpt60_cent50to100_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_Dpt70, ptbins, Nptbin, "hmass_Dpt70_trig", Nmassbin, massmin, massmax);

	book_masshist( hmass_CaloJet40, ptbins, Nptbin, "hmass_CaloJet40_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_CaloJet60, ptbins, Nptbin, "hmass_CaloJet60_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_CaloJet80, ptbins, Nptbin, "hmass_CaloJet80_trig", Nmassbin, massmin, massmax);
	book_masshist( hmass_CaloJet100, ptbins, Nptbin, "hmass_CaloJet100_trig", Nmassbin, massmin, massmax);

	if( isPbPbCollision )
	{
		book_hist_vn_inoutplane( hmass_MB_HFandpart_v1, ptbins, Nptbin, Nphibin, "hmass_MB_HFandpart_v1", Nmassbin, massmin, massmax);
		book_hist_vn_inoutplane( hmass_MB_HFandpart_v2, ptbins, Nptbin, Nphibin, "hmass_MB_HFandpart_v2", Nmassbin, massmin, massmax);
		book_hist_vn_inoutplane( hmass_MB_HFandpart_v3, ptbins, Nptbin, Nphibin, "hmass_MB_HFandpart_v3", Nmassbin, massmin, massmax);
		book_hist_vn_inoutplane( hmass_MB_HFandpart_v4, ptbins, Nptbin, Nphibin, "hmass_MB_HFandpart_v4", Nmassbin, massmin, massmax);

		book_TProfile_mass_vn( h_mass_v1_MB_HFandpart, ptbins, Nptbin, "h_mass_v1_MB_HFandpart", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v2_MB_HFandpart, ptbins, Nptbin, "h_mass_v2_MB_HFandpart", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v3_MB_HFandpart, ptbins, Nptbin, "h_mass_v3_MB_HFandpart", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v4_MB_HFandpart, ptbins, Nptbin, "h_mass_v4_MB_HFandpart", Nmassbin, massmin, massmax);

		book_TProfile_mass_vn( h_mass_v1_SP_MB_HFandpart, ptbins, Nptbin, "h_mass_v1_SP_MB_HFandpart", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v2_SP_MB_HFandpart, ptbins, Nptbin, "h_mass_v2_SP_MB_HFandpart", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v3_SP_MB_HFandpart, ptbins, Nptbin, "h_mass_v3_SP_MB_HFandpart", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v4_SP_MB_HFandpart, ptbins, Nptbin, "h_mass_v4_SP_MB_HFandpart", Nmassbin, massmin, massmax);

		book_hist_vn_inoutplane( hmass_Dtrig_combined_v1, ptbins, Nptbin, Nphibin, "hmass_Dtrig_combined_v1", Nmassbin, massmin, massmax);
		book_hist_vn_inoutplane( hmass_Dtrig_combined_v2, ptbins, Nptbin, Nphibin, "hmass_Dtrig_combined_v2", Nmassbin, massmin, massmax);
		book_hist_vn_inoutplane( hmass_Dtrig_combined_v3, ptbins, Nptbin, Nphibin, "hmass_Dtrig_combined_v3", Nmassbin, massmin, massmax);
		book_hist_vn_inoutplane( hmass_Dtrig_combined_v4, ptbins, Nptbin, Nphibin, "hmass_Dtrig_combined_v4", Nmassbin, massmin, massmax);

		book_TProfile_mass_vn( h_mass_v1_Dtrig_combined, ptbins, Nptbin, "h_mass_v1_Dtrig_combined", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v2_Dtrig_combined, ptbins, Nptbin, "h_mass_v2_Dtrig_combined", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v3_Dtrig_combined, ptbins, Nptbin, "h_mass_v3_Dtrig_combined", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v4_Dtrig_combined, ptbins, Nptbin, "h_mass_v4_Dtrig_combined", Nmassbin, massmin, massmax);

		book_TProfile_mass_vn( h_mass_v1_SP_Dtrig_combined, ptbins, Nptbin, "h_mass_v1_SP_Dtrig_combined", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v2_SP_Dtrig_combined, ptbins, Nptbin, "h_mass_v2_SP_Dtrig_combined", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v3_SP_Dtrig_combined, ptbins, Nptbin, "h_mass_v3_SP_Dtrig_combined", Nmassbin, massmin, massmax);
		book_TProfile_mass_vn( h_mass_v4_SP_Dtrig_combined, ptbins, Nptbin, "h_mass_v4_SP_Dtrig_combined", Nmassbin, massmin, massmax);
	}
	cout << "End book histogram" << endl;
}

void anaDntuple::readtrees(bool isPbPb, bool isDkpi, bool detailedmoed)
{
	readevttree(ntHi, isPbPb);
	readskimtree(ntSkim);
	readDntupletree(ntDkpi, isDkpi, detailedmoed);
	if(isPbPb)
		readPbPbhlttree(ntHlt);
	else
		readpphlttree(ntHlt);
	if(isMC) readGenDtree(ntGen);
}

void anaDntuple::GetMCPtWeightFunction( TTree * GenDtree )
{
	for( int ientry = 0; ientry < GenDtree->GetEntries(); ientry++ )
	{
		GenDtree->GetEntry(ientry);
		for( int igend = 0; igend < Gsize; igend++ )
		{
			if( TMath::Abs( Gy[igend]) > Drapiditycut ) continue; //rapidity cut
			if( TMath::Abs( GpdgId[igend] ) != 421 ) continue; //D0 only

			Gen_D0_pt_noweight_forptreweight->Fill( Gpt[igend] );
		}
	}

	divideBinWidth(Gen_D0_pt_noweight_forptreweight);

	TFile * FileFONLLD0 = new TFile("/home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch2/src/Dntupleana/rootfiles/output_pp_d0meson_5TeV_y1.root");
	TGraphAsymmErrors* gaeFONLLD0Reference = (TGraphAsymmErrors*) FileFONLLD0->Get("gaeSigmaDzero");

	TH1D * hFONLL = new TH1D( "hFONLL", "hFONLL", bins_reweight, ptmin_reweight, ptmax_reweight);
	double x,y;
	for( int i=0; i < bins_reweight; i++)
	{
		gaeFONLLD0Reference->GetPoint(i,x,y);
		hFONLL->SetBinContent(i+1,y);
	}

	FONLL_over_GenD0Pt_forptreweight = ( TH1D *) hFONLL->Clone("FONLL_over_GenD0Pt_forptreweight");
	FONLL_over_GenD0Pt_forptreweight->Divide(Gen_D0_pt_noweight_forptreweight);

	//fit w/o draw
	TF1 * fit_FONLL_over_GenD0Pt = new TF1("fit_FONLL_over_GenD0Pt","pow(10,[0]*x+[1]+x*x*[2])+pow(10,[3]*x+[4]+x*x*[5])", 0, 150);
	FONLL_over_GenD0Pt_forptreweight->Fit("fit_FONLL_over_GenD0Pt","0 q","",2,100);
	FONLL_over_GenD0Pt_forptreweight->Fit("fit_FONLL_over_GenD0Pt","0 q","",2,100);
	FONLL_over_GenD0Pt_forptreweight->Fit("fit_FONLL_over_GenD0Pt","0 q","",2,100);
	FONLL_over_GenD0Pt_forptreweight->Fit("fit_FONLL_over_GenD0Pt","0 q","",2,100);

	//save fitted function
	fit_FONLL_over_GenD0Pt->SetLineColor(4.0);
	FONLL_over_GenD0Pt_forptreweight->GetListOfFunctions()->Add(fit_FONLL_over_GenD0Pt);

	MCPtWeidhtFunction = new TF1("fit_FONLL_over_GenD0Pt","pow(10,[0]*x+[1]+x*x*[2])+pow(10,[3]*x+[4]+x*x*[5])", 0, 300);
	MCPtWeidhtFunction->SetParameter( 0, fit_FONLL_over_GenD0Pt->GetParameter(0));
	MCPtWeidhtFunction->SetParameter( 1, fit_FONLL_over_GenD0Pt->GetParameter(1));
	MCPtWeidhtFunction->SetParameter( 2, fit_FONLL_over_GenD0Pt->GetParameter(2));
	MCPtWeidhtFunction->SetParameter( 3, fit_FONLL_over_GenD0Pt->GetParameter(3));
	MCPtWeidhtFunction->SetParameter( 4, fit_FONLL_over_GenD0Pt->GetParameter(4));
	MCPtWeidhtFunction->SetParameter( 5, fit_FONLL_over_GenD0Pt->GetParameter(5));
}

void anaDntuple::PbPbTrigComb_PDs()
{
	temp_HLT_HIL1MinimumBiasHF1AND_v1 = HLT_HIL1MinimumBiasHF1AND_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_v1 = HLT_HIL1MinimumBiasHF2AND_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part1_v1 = HLT_HIL1MinimumBiasHF2AND_part1_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part2_v1 = HLT_HIL1MinimumBiasHF2AND_part2_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part3_v1 = HLT_HIL1MinimumBiasHF2AND_part3_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part4_v1 = HLT_HIL1MinimumBiasHF2AND_part4_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part5_v1 = HLT_HIL1MinimumBiasHF2AND_part5_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part6_v1 = HLT_HIL1MinimumBiasHF2AND_part6_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part7_v1 = HLT_HIL1MinimumBiasHF2AND_part7_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part8_v1 = HLT_HIL1MinimumBiasHF2AND_part8_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part9_v1 = HLT_HIL1MinimumBiasHF2AND_part9_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part10_v1 = HLT_HIL1MinimumBiasHF2AND_part11_v1;
	temp_HLT_HIL1MinimumBiasHF2AND_part11_v1 = HLT_HIL1Centralityext30100HFplusANDminusTH0_v1;
	temp_HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = HLT_HIL1Centralityext30100HFplusANDminusTH0_v1;
	temp_HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = HLT_HIL1Centralityext50100HFplusANDminusTH0_v1;
	temp_HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = HLT_HIL1Centralityext70100HFplusANDminusTH0_v1;
	temp_HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1;
	temp_HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1;
	temp_HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1;
	temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1;
	temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1;
	temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1;
	temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1;
	temp_HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1;

	if( PbPbPD == 0 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 1 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		if( run >= 263155 )
			HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		//else
		//	HLT_HIL1MinimumBiasHF2AND_v1 = HLT_HIL1MinimumBiasHF2AND_v1;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part7_v1 = HLT_HIL1MinimumBiasHF2AND_part7_v1;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		//HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = HLT_HIL1Centralityext30100HFplusANDminusTH0_v1;
		//HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = HLT_HIL1Centralityext50100HFplusANDminusTH0_v1;
		//HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = HLT_HIL1Centralityext70100HFplusANDminusTH0_v1;
		if( run >= 263155 )
			HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		//else
		//	HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1;
		//HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1;
		//HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		//HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1;
	}

	if( PbPbPD == 2 )
	{
		//HLT_HIL1MinimumBiasHF1AND_v1 = HLT_HIL1MinimumBiasHF1AND_v1;
		//if( run >= 263155 && run <= 263186 )
		//	HLT_HIL1MinimumBiasHF2AND_v1 = HLT_HIL1MinimumBiasHF2AND_v1;
		if( !(run >= 263155 && run <= 263186) )
			HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part1_v1 = HLT_HIL1MinimumBiasHF2AND_part1_v1;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 3 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part2_v1 = HLT_HIL1MinimumBiasHF2AND_part2_v1;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		//if( run >= 263155 && run <= 263186 )
		//	HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1;
		if( !( run >= 263155 && run <= 263186 ) )
			HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		//HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 4 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part3_v1 = HLT_HIL1MinimumBiasHF2AND_part3_v1;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 5 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part4_v1 = HLT_HIL1MinimumBiasHF2AND_part4_v1;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		//HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 6 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part5_v1 = HLT_HIL1MinimumBiasHF2AND_part5_v1;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		//HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 7 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part6_v1 = HLT_HIL1MinimumBiasHF2AND_part6_v1;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		//HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 8 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part8_v1 = HLT_HIL1MinimumBiasHF2AND_part8_v1;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 9 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part9_v1 = HLT_HIL1MinimumBiasHF2AND_part9_v1;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 10 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part10_v1 = HLT_HIL1MinimumBiasHF2AND_part10_v1;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 11 )
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		//HLT_HIL1MinimumBiasHF2AND_part11_v1 = HLT_HIL1MinimumBiasHF2AND_part11_v1;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 12 ) //HIOniaL1DoubleMu0
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		//if( run >= 263728 && run <= 263740 )
		//	HLT_HIL1MinimumBiasHF2AND_part8_v1 = HLT_HIL1MinimumBiasHF2AND_part8_v1;
		if( !(run >= 263728 && run <= 263740) )
			HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 13 ) //HIOniaL1DoubleMu0B
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		//if( run >= 263728 && run <= 263740 )
		//	HLT_HIL1MinimumBiasHF2AND_part9_v1 = HLT_HIL1MinimumBiasHF2AND_part9_v1;
		if( !(run >= 263728 && run <= 263740) )
			HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 14 ) //HIOniaL1DoubleMu0C
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		//if( run >= 263728 && run <= 263740 )
		//	HLT_HIL1MinimumBiasHF2AND_part10_v1 = HLT_HIL1MinimumBiasHF2AND_part10_v1;
		if( !(run >= 263728 && run <= 263740) )
			HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}

	if( PbPbPD == 15 ) //HIOniaL1DoubleMu0D
	{
		HLT_HIL1MinimumBiasHF1AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part4_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part5_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part6_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part7_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part8_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part9_v1 = 0;
		HLT_HIL1MinimumBiasHF2AND_part10_v1 = 0;
		//if( run >= 263728 && run <= 263740 )
		//	HLT_HIL1MinimumBiasHF2AND_part11_v1 = HLT_HIL1MinimumBiasHF2AND_part11_v1;
		if( !(run >= 263728 && run <= 263740) )
			HLT_HIL1MinimumBiasHF2AND_part11_v1 = 0;
		HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 = 0;
		HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1 = 0;
		HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1 = 0;
	}
}

void anaDntuple::Combine_TrigPart_TrigVersion()
{
	if( isPbPbCollision )
	{
		if( run > 263155 )
		{
			MBtrig_part_combined = HLT_HIL1MinimumBiasHF2AND_v1 || HLT_HIL1MinimumBiasHF2AND_part1_v1 || HLT_HIL1MinimumBiasHF2AND_part2_v1 || HLT_HIL1MinimumBiasHF2AND_part3_v1 || HLT_HIL1MinimumBiasHF2AND_part4_v1 || HLT_HIL1MinimumBiasHF2AND_part5_v1 || HLT_HIL1MinimumBiasHF2AND_part6_v1 || HLT_HIL1MinimumBiasHF2AND_part7_v1 || HLT_HIL1MinimumBiasHF2AND_part8_v1 || HLT_HIL1MinimumBiasHF2AND_part9_v1 || HLT_HIL1MinimumBiasHF2AND_part10_v1 || HLT_HIL1MinimumBiasHF2AND_part11_v1;
			MBtrig_cent30to100_part_combined = HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 || HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 || HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 || HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1;
			MBtrig_cent50to100_part_combined = HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1;
			MBtrig_cent70to100_part_combined = 0;

			temp_MBtrig_part_combined = temp_HLT_HIL1MinimumBiasHF2AND_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part1_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part2_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part3_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part4_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part5_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part6_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part7_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part8_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part9_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part10_v1 || temp_HLT_HIL1MinimumBiasHF2AND_part11_v1;
			temp_MBtrig_cent30to100_part_combined = temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1 || temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1 || temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1 || temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1;
			temp_MBtrig_cent50to100_part_combined = temp_HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1;
			temp_MBtrig_cent70to100_part_combined = 0;

			if( run > 263728 )
			{
				MBtrig_cent30to100_part_combined = 0;
				MBtrig_cent50to100_part_combined = 0;

				temp_MBtrig_cent30to100_part_combined = 0;
				temp_MBtrig_cent50to100_part_combined = 0;
			}
		}
		else if( run < 263155 )
		{
			MBtrig_part_combined = HLT_HIL1MinimumBiasHF1AND_v1;
			MBtrig_cent30to100_part_combined = HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 || HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1;
			MBtrig_cent50to100_part_combined = HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 || HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1;
			MBtrig_cent70to100_part_combined = HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 || HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1;

			temp_MBtrig_part_combined = temp_HLT_HIL1MinimumBiasHF1AND_v1;
			temp_MBtrig_cent30to100_part_combined = temp_HLT_HIL1Centralityext30100HFplusANDminusTH0_v1 || temp_HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1;
			temp_MBtrig_cent50to100_part_combined = temp_HLT_HIL1Centralityext50100HFplusANDminusTH0_v1 || temp_HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1;
			temp_MBtrig_cent70to100_part_combined = temp_HLT_HIL1Centralityext70100HFplusANDminusTH0_v1 || temp_HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1;
		}

		//remove the overlap in event counts
		MBtrig_cent30to100_part_combined = MBtrig_cent30to100_part_combined && !temp_MBtrig_part_combined;
		MBtrig_cent50to100_part_combined = MBtrig_cent50to100_part_combined && !temp_MBtrig_part_combined && !temp_MBtrig_cent30to100_part_combined;
		MBtrig_cent70to100_part_combined = MBtrig_cent70to100_part_combined && !temp_MBtrig_part_combined && !temp_MBtrig_cent30to100_part_combined && !temp_MBtrig_cent50to100_part_combined;

		//overlaps not removed yet!!!!!!!!!!
		if( cent_low >= 30 && cent_low < 50 && cent_high <= 50 ) MBtrig_part_combined = MBtrig_part_combined || ( MBtrig_cent30to100_part_combined && !temp_MBtrig_part_combined);
		if( cent_low >= 50 && cent_high <= 100 ) MBtrig_part_combined = MBtrig_part_combined || ( MBtrig_cent30to100_part_combined && !temp_MBtrig_part_combined) || ( MBtrig_cent50to100_part_combined && !temp_MBtrig_part_combined && !temp_MBtrig_cent30to100_part_combined);
		//if( cent_low >= 50 && cent_high <= 70 ) MBtrig_part_combined = MBtrig_part_combined || ( MBtrig_cent30to100_part_combined && !temp_MBtrig_part_combined) || ( MBtrig_cent50to100_part_combined && !temp_MBtrig_part_combined && !temp_MBtrig_cent30to100_part_combined);
		//MBtrig_cent70to100_part_combined just saved pretty small number of events
		//if( cent_low >= 70 && cent_high <= 100 ) MBtrig_part_combined = MBtrig_part_combined || ( MBtrig_cent30to100_part_combined && !temp_MBtrig_part_combined) || ( MBtrig_cent50to100_part_combined && !temp_MBtrig_part_combined && !temp_MBtrig_cent30to100_part_combined) || ( MBtrig_cent70to100_part_combined && !temp_MBtrig_part_combined && !temp_MBtrig_cent30to100_part_combined && !temp_MBtrig_cent50to100_part_combined);

		HLT_HIDmesonHITrackingGlobal_Dpt20_combined = HLT_HIDmesonHITrackingGlobal_Dpt20_v1 || HLT_HIDmesonHITrackingGlobal_Dpt20_v2;

		HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_combined = HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1 || HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2;

		HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_combined = HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1 || HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2 || HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3;

		HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_combined = HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1 || HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2 || HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3;

		HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_combined = HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1 || HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2;

		HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_combined = HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1 || HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2;
	}
	else
	{
		MBtrig_part_combined = HLT_L1MinimumBiasHF1OR_part0_v1 || HLT_L1MinimumBiasHF1OR_part1_v1 || HLT_L1MinimumBiasHF1OR_part2_v1 || HLT_L1MinimumBiasHF1OR_part3_v1 || HLT_L1MinimumBiasHF1OR_part4_v1 || HLT_L1MinimumBiasHF1OR_part5_v1 || HLT_L1MinimumBiasHF1OR_part6_v1 || HLT_L1MinimumBiasHF1OR_part7_v1 || HLT_L1MinimumBiasHF1OR_part8_v1 || HLT_L1MinimumBiasHF1OR_part9_v1 || HLT_L1MinimumBiasHF1OR_part10_v1 || HLT_L1MinimumBiasHF1OR_part11_v1 || HLT_L1MinimumBiasHF1OR_part12_v1 || HLT_L1MinimumBiasHF1OR_part13_v1 || HLT_L1MinimumBiasHF1OR_part14_v1 || HLT_L1MinimumBiasHF1OR_part15_v1 || HLT_L1MinimumBiasHF1OR_part16_v1 || HLT_L1MinimumBiasHF1OR_part17_v1 || HLT_L1MinimumBiasHF1OR_part18_v1 || HLT_L1MinimumBiasHF1OR_part19_v1;
	}
}

//
//
void anaDntuple::LoopOverFile(int startFile, int endFile, string filelist, bool isPbPb, bool isMCornot, double hibin_low, double hibin_high, int whichPbPbPD)
{//.. loop over files in the "*filelist" from startFile to endFile in sequence
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();
	isPbPbCollision = isPbPb;
	isMC = isMCornot;
	PbPbPD = whichPbPbPD;
	hibin_cut_low = hibin_low;
	hibin_cut_high = hibin_high;
	cent_low = round(hibin_low*0.5);
	cent_high = round(hibin_high*0.5);

	string outfilename;
	ostringstream oss1;
	ostringstream oss2;
	oss1 << startFile;
	oss2 << endFile;
	ostringstream osscentlow;
	ostringstream osscenthigh;
	osscentlow<< round(hibin_low*0.5);
	osscenthigh<< round(hibin_high*0.5);
	outfilename = "anaDntuple_" + filelist + "_" + oss1.str() + "to" + oss2.str() + "_Cent" + osscentlow.str() + "to" + osscenthigh.str() + ".root";
	Init(outfilename);

	Histobookforanalysis();

	string inputfilename;

	//
	ifstream file_stream(filelist.c_str());
	int ifile = 0;

	while (file_stream >> inputfilename) 
	{

		ifile++;
		if(ifile-1 >= endFile) {
			break;
		} else if(ifile-1 < startFile) {
			continue;
		}
		cout << "file  = " << ifile<<" name = "<<inputfilename <<endl;
		if (!TFile::Open(inputfilename.c_str()))   { cout << " fail to open file" << endl; continue;}
		TFile * inputf = TFile::Open(inputfilename.c_str());

		ntDkpi = (TTree *) inputf->Get("ntDkpi");
		ntHlt = (TTree *) inputf->Get("ntHlt");
		ntSkim = (TTree *) inputf->Get("ntSkim");
		ntHi = (TTree *) inputf->Get("ntHi");
		if(isMC) ntGen = (TTree *) inputf->Get("ntGen");

		readtrees(isPbPb);
		if(isMC) GetMCPtWeightFunction( ntGen ); //actually not work for file loop case because need to get the gen pt of all files
		//for MC, the file loop won't be used

		ntDkpi->AddFriend(ntHlt);
		ntDkpi->AddFriend(ntSkim);
		ntDkpi->AddFriend(ntHi);
		if(isMC) ntDkpi->AddFriend(ntGen);

		LoopOverEvt( ntDkpi );
		inputf->Close();
	}

	Write();

	outputfile->Close();
	return;
}

void anaDntuple::ProcessPartialEvents( string inputfilename, bool isPbPb, bool isMCornot, int startevt, int endevt, double hibin_low, double hibin_high, int whichPbPbPD)
{
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();
	isPbPbCollision = isPbPb;
	isMC = isMCornot;
	PbPbPD = whichPbPbPD;
	hibin_cut_low = hibin_low;
	hibin_cut_high = hibin_high;
	cent_low = round(hibin_low*0.5);
	cent_high = round(hibin_high*0.5);

	string outfilename;
	ostringstream oss1;
	ostringstream oss2;
	oss1 << startevt;
	oss2 << endevt;
	ostringstream osscentlow;
	ostringstream osscenthigh;
	osscentlow<< round(hibin_low*0.5);
	osscenthigh<< round(hibin_high*0.5);
	//	cout << " fs::basename(inputfilename): " << fs::basename(inputfilename) << endl;
	outfilename = "anaDntuple_" + fs::basename(inputfilename) + "_Cent" + osscentlow.str() + "to" + osscenthigh.str() + "_Evt" + oss1.str() + "to" + oss2.str() + ".root";
	//cout << " outfilename: " << outfilename << endl;
	Init(outfilename);

	Histobookforanalysis();

	if (!TFile::Open(inputfilename.c_str()))   { cout << " fail to open file" << endl; return;}
	TFile * inputf = TFile::Open(inputfilename.c_str());

	ntDkpi = (TTree *) inputf->Get("ntDkpi");
	ntHlt = (TTree *) inputf->Get("ntHlt");
	ntSkim = (TTree *) inputf->Get("ntSkim");
	ntHi = (TTree *) inputf->Get("ntHi");
	if(isMC) ntGen = (TTree *) inputf->Get("ntGen");

	readtrees(isPbPb);
	if(isMC) GetMCPtWeightFunction( ntGen );

	ntDkpi->AddFriend(ntHlt);
	ntDkpi->AddFriend(ntSkim);
	ntDkpi->AddFriend(ntHi);
	if(isMC) ntDkpi->AddFriend(ntGen);

	LoopOverEvt( ntDkpi, startevt, endevt);

	inputf->Close();

	Write();

	outputfile->Close();
	return;

}

void anaDntuple::LoopOverEvt( TTree * inhtree , int startevt, int endevt )
{
	if( endevt > inhtree->GetEntries() || endevt == -1 ) endevt = inhtree->GetEntries();

	for(int entry = startevt; entry < endevt; entry++)
	{
		inhtree->GetEntry(entry);
		if( entry % 1000000 == 0 )  cout << entry+1 << "st event" << endl;

		//centrality range
		if( isPbPbCollision && (hiBin < hibin_cut_low || hiBin > hibin_cut_high) )  continue;

		if( isPbPbCollision ) PbPbTrigComb_PDs();
		Combine_TrigPart_TrigVersion();

		//event filter
		if( isPbPbCollision && !isMC )
		{
			if( ! ( pcollisionEventSelection && pprimaryVertexFilter && phfCoincFilter3 && pclusterCompatibilityFilter ) )  continue;
		}
		else
		{
			if( ! ( pPAprimaryVertexFilter && pBeamScrapingFilter ) ) continue;
		}


		if( !isPbPbCollision ) hiBin = 1;

		//if want to use all events
		if( isMC ) MBtrig_part_combined = 1;
		Evt_weight = 1.0; //only used for MC
		if( isMC ) Evt_weight = pthatweight;

		FillEvtTrighibin();
		if( isPbPbCollision ) FillEPresohisto();

		if(isMC) LoopOverGenDs();

		LoopOverDcandidates();
	}
}

void anaDntuple::FillEPresohisto_SP(int EP, TProfile * h_QAB, TProfile * h_QAC, TProfile * h_QBC)
{
	comp QA (hiEvtPlanesqx[EP],hiEvtPlanesqy[EP]);
	comp QB (hiEvtPlanesqx[RCMate1[EP]], hiEvtPlanesqy[RCMate1[EP]]);
	comp QC (hiEvtPlanesqx[RCMate2[EP]], hiEvtPlanesqy[RCMate2[EP]]);
	comp QAB(0,0);
	comp QAC(0,0);
	comp QBC(0,0);
	QAB =  QA*std::conj(QB);
	QAC =  QA*std::conj(QC);
	QBC =  QB*std::conj(QC);

	h_QAB->Fill( hiBin, QAB.real());
	h_QAC->Fill( hiBin, QAC.real());
	h_QBC->Fill( hiBin, QBC.real());
}

void anaDntuple::FillEPresohisto()
{
	if( MBtrig_part_combined )
	{
		h_v1_hiBin_cosndiffeppepm->Fill( hiBin, TMath::Cos( hiEvtPlanes[0] - hiEvtPlanes[1]));
		h_v2_hiBin_cosndiffeppepm->Fill( hiBin, TMath::Cos( 2.*(hiEvtPlanes[6] - hiEvtPlanes[7])));
		h_v3_hiBin_cosndiffeppepm->Fill( hiBin, TMath::Cos( 3.*(hiEvtPlanes[13] - hiEvtPlanes[14])));
		h_v4_hiBin_cosndiffeppepm->Fill( hiBin, TMath::Cos( 4.*(hiEvtPlanes[19] - hiEvtPlanes[20])));

		FillEPresohisto_SP(HFm2, h_v2_hiBin_HFm_QAB, h_v2_hiBin_HFm_QAC, h_v2_hiBin_HFm_QBC);
		FillEPresohisto_SP(HFp2, h_v2_hiBin_HFp_QAB, h_v2_hiBin_HFp_QAC, h_v2_hiBin_HFp_QBC);
		FillEPresohisto_SP(HFm3, h_v3_hiBin_HFm_QAB, h_v3_hiBin_HFm_QAC, h_v3_hiBin_HFm_QBC);
		FillEPresohisto_SP(HFp3, h_v3_hiBin_HFp_QAB, h_v3_hiBin_HFp_QAC, h_v3_hiBin_HFp_QBC);
	}
}

void anaDntuple::FillEvtTrighibin()
{
	if( MBtrig_part_combined ) hevt_trig_hiBin->Fill( 1, hiBin);
	if( MBtrig_cent30to100_part_combined ) hevt_trig_hiBin->Fill( 2, hiBin);
	if( MBtrig_cent50to100_part_combined ) hevt_trig_hiBin->Fill( 3, hiBin);
	if( MBtrig_cent70to100_part_combined ) hevt_trig_hiBin->Fill( 4, hiBin);

	if( isPbPbCollision )
	{
		if( HLT_HIDmesonHITrackingGlobal_Dpt20_combined ) hevt_trig_hiBin->Fill( 5, hiBin); 
		if( HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_combined ) hevt_trig_hiBin->Fill( 6, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_combined ) hevt_trig_hiBin->Fill( 7, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_combined ) hevt_trig_hiBin->Fill( 8, hiBin);

		if( HLT_HIDmesonHITrackingGlobal_Dpt30_v1 ) hevt_trig_hiBin->Fill( 9, hiBin); 
		if( HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_combined ) hevt_trig_hiBin->Fill( 10, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1 ) hevt_trig_hiBin->Fill( 11, hiBin); 
		if( HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1 ) hevt_trig_hiBin->Fill( 12, hiBin);

		if( HLT_HIDmesonHITrackingGlobal_Dpt40_v1 ) hevt_trig_hiBin->Fill( 13, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_combined ) hevt_trig_hiBin->Fill( 14, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1 ) hevt_trig_hiBin->Fill( 15, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1 ) hevt_trig_hiBin->Fill( 16, hiBin);

		if( HLT_HIDmesonHITrackingGlobal_Dpt50_v1 ) hevt_trig_hiBin->Fill( 17, hiBin);
		//	if( HLT_HIDmesonHITrackingGlobal_Dpt50_Cent0_10_v1 ) hevt_trig_hiBin->Fill( 18, hiBin);
		//	if( HLT_HIDmesonHITrackingGlobal_Dpt50_Cent30_100_v1 ) hevt_trig_hiBin->Fill( 19, hiBin);
		//	if( HLT_HIDmesonHITrackingGlobal_Dpt50_Cent50_100_v1 ) hevt_trig_hiBin->Fill( 20, hiBin);

		if( HLT_HIDmesonHITrackingGlobal_Dpt60_v1 ) hevt_trig_hiBin->Fill( 21, hiBin);
		//	if( HLT_HIDmesonHITrackingGlobal_Dpt60_Cent0_10_v1 ) hevt_trig_hiBin->Fill( 22, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1 ) hevt_trig_hiBin->Fill( 23, hiBin);
		if( HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1 ) hevt_trig_hiBin->Fill( 24, hiBin);

		if( HLT_HIDmesonHITrackingGlobal_Dpt70_v1 ) hevt_trig_hiBin->Fill( 25, hiBin);
	}

	if( !isPbPbCollision )
	{
		if( HLT_DmesonPPTrackingGlobal_Dpt8_v1 )    hevt_trig_hiBin->Fill( 26, hiBin); 
		if( HLT_DmesonPPTrackingGlobal_Dpt15_v1 )   hevt_trig_hiBin->Fill( 27, hiBin);
		if( HLT_DmesonPPTrackingGlobal_Dpt20_v1 )   hevt_trig_hiBin->Fill( 28, hiBin);
		if( HLT_DmesonPPTrackingGlobal_Dpt30_v1 )   hevt_trig_hiBin->Fill( 29, hiBin);
		if( HLT_DmesonPPTrackingGlobal_Dpt40_v1 )   hevt_trig_hiBin->Fill( 30, hiBin);
		if( HLT_DmesonPPTrackingGlobal_Dpt50_v1 )   hevt_trig_hiBin->Fill( 31, hiBin);
		if( HLT_DmesonPPTrackingGlobal_Dpt60_v1 )   hevt_trig_hiBin->Fill( 32, hiBin);
	}
}

void anaDntuple::LoopOverGenDs()
{
	double GenDptweight;

	for( int igend = 0; igend < Gsize; igend++)
	{
		if( TMath::Abs( Gy[igend]) > Drapiditycut ) continue; //rapidity cut
		if( TMath::Abs( GpdgId[igend] ) != 421 ) continue; //D0 only

		Gen_D0_pt_noweight->Fill( Gpt[igend]);
		Gen_D0_pt_pthatweight->Fill( Gpt[igend], pthatweight);

		GenDptweight = MCPtWeidhtFunction->Eval( Gpt[igend] );
		Gen_D0_pt_ptweight->Fill( Gpt[igend], GenDptweight);
	}
}

void anaDntuple::LoopOverDcandidates()
{
	for(int icand = 0; icand<Dsize; icand++)
	{
		if( ! ( Dtrk1highPurity[icand] && Dtrk2highPurity[icand] ) )  continue;
		if( TMath::Abs(Dtrk1Eta[icand]) > Tketacut || TMath::Abs(Dtrk2Eta[icand]) > Tketacut ) continue;
		if( TMath::Abs( Dy[icand] ) > Drapiditycut )    continue;

		int iptbin = decideptbin( Dpt[icand], ptbins, Nptbin);

		//topological cuts
		if( isPbPbCollision )
		{
			if( !( (DsvpvDistance[icand]/DsvpvDisErr[icand]) > vertex3dcut_PbPb[iptbin] && 
						Dalpha[icand] < alphacut_PbPb[iptbin] && 
						Dchi2cl[icand] > vertexprobcut_PbPb[iptbin] ) )
				continue;
		}
		else
		{
			if( !( (DsvpvDistance[icand]/DsvpvDisErr[icand]) > vertex3dcut_pp[iptbin] && 
						Dalpha[icand] < alphacut_pp[iptbin] && 
						Dchi2cl[icand] > vertexprobcut_pp[iptbin] ) )
				continue;
		}

		if( isPbPbCollision )
		{
			dcanddeltaphiv1 = Calculatedeltaphi( icand, 1);
			dcanddeltaphiv2 = Calculatedeltaphi( icand, 2);
			dcanddeltaphiv3 = Calculatedeltaphi( icand, 3);
			dcanddeltaphiv4 = Calculatedeltaphi( icand, 4);

			dcandiphiv1 = Decideinoutplane( dcanddeltaphiv1, 1);
			dcandiphiv2 = Decideinoutplane( dcanddeltaphiv2, 2);
			dcandiphiv3 = Decideinoutplane( dcanddeltaphiv3, 3);
			dcandiphiv4 = Decideinoutplane( dcanddeltaphiv4, 4);

			if( dcandiphiv1 < 0 || dcandiphiv2 < 0 || dcandiphiv3 < 0 || dcandiphiv4 < 0)
			{
				cout << " dcandiphi is wrong!!!!!!" << "  icand: " << icand << endl;
				cout << " dcandiphiv1: " << dcandiphiv1 << " dcandiphiv2: " << dcandiphiv2 << " dcandiphiv3: " << dcandiphiv3 << " dcandiphiv4: " << dcandiphiv4 << endl;
				exit(2);
			}

			//decide EP resolution
			int icentbin = Decide_centbin_for_EPresolution( cent_low, cent_high);
			if( icentbin >= 0 )
			{
				if( Deta[icand] >= 0 )
				{
					EP_resolution_v1 = EPm_resolution_v1[icentbin];
					EP_resolution_v2 = EPm_resolution_v2[icentbin];
					EP_resolution_v3 = EPm_resolution_v3[icentbin];
					EP_resolution_v4 = EPm_resolution_v4[icentbin];

					SP_EP_resolution_v1 = 1;
					SP_EP_resolution_v2 = SP_EPm_resolution_v2[icentbin];
					SP_EP_resolution_v3 = SP_EPm_resolution_v3[icentbin];
					SP_EP_resolution_v4 = 1;
				}
				else
				{
					EP_resolution_v1 = EPp_resolution_v1[icentbin];
					EP_resolution_v2 = EPp_resolution_v2[icentbin];
					EP_resolution_v3 = EPp_resolution_v3[icentbin];
					EP_resolution_v4 = EPp_resolution_v4[icentbin];

					SP_EP_resolution_v1 = 1;
					SP_EP_resolution_v2 = SP_EPp_resolution_v2[icentbin];
					SP_EP_resolution_v3 = SP_EPp_resolution_v3[icentbin];
					SP_EP_resolution_v4 = 1;
				}
			}
			else
			{
				EP_resolution_v1 = 1;
				EP_resolution_v2 = 1;
				EP_resolution_v3 = 1;
				EP_resolution_v4 = 1;

				SP_EP_resolution_v1 = 1;
				SP_EP_resolution_v2 = 1;
				SP_EP_resolution_v3 = 1;
				SP_EP_resolution_v4 = 1;
			}
		}

		//apply MB track pt cut first. After MB histograms are filled, apply trig track pt cut
		if( isPbPbCollision && ( Dtrk1Pt[icand] <  MBTkptcut_PbPb || Dtrk2Pt[icand] <  MBTkptcut_PbPb ) ) continue;
		if( !isPbPbCollision && ( Dtrk1Pt[icand] <  MBTkptcut_pp || Dtrk2Pt[icand] <  MBTkptcut_pp ) )  continue;
		if( Dtrk1PtErr[icand]/Dtrk1Pt[icand] > TkPtresolution_MB || Dtrk2PtErr[icand]/Dtrk2Pt[icand] > TkPtresolution_MB ) continue;
		///////////////////////////////analysis with MB trig/////////////////////////////////////////

		FillMBhisto( icand, iptbin);
		if( isMC ) FillMCMBhisto( icand, iptbin);

		////////////////////////////// end analysis with MB trig/////////////////////////////////////
		//apply trig track pt cut
		if( isPbPbCollision && ( Dtrk1Pt[icand] <  TrigTkptcut_PbPb || Dtrk2Pt[icand] <  TrigTkptcut_PbPb ) ) continue;
		if( !isPbPbCollision && ( Dtrk1Pt[icand] <  TrigTkptcut_pp || Dtrk2Pt[icand] <  TrigTkptcut_pp ) )  continue;
		if( !isPbPbCollision && ( Dtrk1Algo[icand] > TkAlgoCut_Trig || Dtrk2Algo[icand] > TkAlgoCut_Trig ) ) continue;
		if( isPbPbCollision && ( ( Dtrk1Algo[icand] > TkAlgoCut_Trig && Dtrk1Algo[icand] != 11 ) || 
					( Dtrk2Algo[icand] > TkAlgoCut_Trig && Dtrk1Algo[icand] != 11 ) ) ) continue;
		if( Dtrk1PtErr[icand]/Dtrk1Pt[icand] > TkPtresolution_Trig || Dtrk2PtErr[icand]/Dtrk2Pt[icand] > TkPtresolution_Trig ) continue;
		if( (Dtrk1PixelHit[icand]+Dtrk1StripHit[icand]) < TkHitCut_Trig || (Dtrk2PixelHit[icand]+Dtrk2StripHit[icand]) < TkHitCut_Trig ) continue;

		FillJettrighisto( icand, iptbin);

		Dtrig_combination( icand );
		if( isMC ) Dtrig_combined = 1;

		if( isPbPbCollision )  FillDtrighisto_PbPb( icand, iptbin);
		else FillDtrighisto_pp( icand, iptbin);
		if( isMC ) FillMCDtrighisto( icand, iptbin);
	}
}

void anaDntuple::Dtrig_combination( int icand )
{
	Dtrig_combined = 0;
	Dtrig_combined_Cent0_10 = 0;
	Dtrig_combined_Cent30_100 = 0;
	Dtrig_combined_Cent50_100 = 0;

	if( isPbPbCollision )
	{
		if(
				(HLT_HIDmesonHITrackingGlobal_Dpt20_combined&&Dpt[icand]>25.&&Dpt[icand]<45.)||
				(HLT_HIDmesonHITrackingGlobal_Dpt40_v1&&Dpt[icand]>45.&&Dpt[icand]<65.)||
				(HLT_HIDmesonHITrackingGlobal_Dpt60_v1&&Dpt[icand]>65.)	
		  )
			Dtrig_combined = 1;

		if( PbPbPD == 16 ) //HardProbe
		{
			if(
					HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_combined&&Dpt[icand]>25.
			  )
				Dtrig_combined_Cent0_10 = 1;

			if( cent_low >= 0 && cent_high <= 10 )
				Dtrig_combined = Dtrig_combined || Dtrig_combined_Cent0_10;
		}

		if( PbPbPD == 17 ) //HardProbePeripheral
		{
			if(
					run > 262750 && 
					( (HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_combined&&Dpt[icand]>25.&&Dpt[icand]<35.)||
					  (HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1&&Dpt[icand]>35.&&Dpt[icand]<45.)||
					  (HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1&&Dpt[icand]>45.&&Dpt[icand]<65.)||
					  (HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1&&Dpt[icand]>65.) )
			  )
				Dtrig_combined_Cent30_100 = 1;

			if(
					( (HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_combined&&Dpt[icand]>25.&&Dpt[icand]<35.)||
					  (HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1&&Dpt[icand]>35.&&Dpt[icand]<45.)||
					  (HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1&&Dpt[icand]>45.&&Dpt[icand]<65.)||
					  (HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1&&Dpt[icand]>65.) )
			  )
				Dtrig_combined_Cent50_100 = 1;

			if( cent_low >= 30 && cent_low < 50 && cent_high <= 100 )
				Dtrig_combined = !Dtrig_combined && Dtrig_combined_Cent30_100; //remove overlap with 0-100% D triggers

			if( cent_low >= 50 && cent_high <= 100 )
				Dtrig_combined = !Dtrig_combined && ( Dtrig_combined_Cent30_100 || Dtrig_combined_Cent50_100 );
		}
	}
	else
	{
		if( 
				(HLT_DmesonPPTrackingGlobal_Dpt15_v1&&Dpt[icand]>20.&&Dpt[icand]<25.)||
				(HLT_DmesonPPTrackingGlobal_Dpt20_v1&&Dpt[icand]>25.&&Dpt[icand]<35.)|| 
				(HLT_DmesonPPTrackingGlobal_Dpt30_v1&&Dpt[icand]>35.&&Dpt[icand]<55.)||
				(HLT_DmesonPPTrackingGlobal_Dpt50_v1&&Dpt[icand]>55.) 
		  )
			Dtrig_combined = 1;
	}
}

float anaDntuple::Calculatedeltaphi( int icand, int floworder )
{
	if( floworder < 1 || floworder > 5 )    { cout << "floworder out of range!!!!!!!" << endl; return -99.; }

	float deltaphi = -99.;
	float dcandphi = Dphi[icand];
	float dcandeta = Deta[icand];

	if( floworder == 1 )
	{
		if( dcandeta >= 0 )   
		{
			deltaphi = dcandphi - hiEvtPlanes[0];
			SP_Qmag_v1 = TMath::Sqrt( hiEvtPlanesqx[0] * hiEvtPlanesqx[0] + hiEvtPlanesqy[0] * hiEvtPlanesqy[0] );
		}
		else 
		{
			deltaphi = dcandphi - hiEvtPlanes[1];
			SP_Qmag_v1 = TMath::Sqrt( hiEvtPlanesqx[1] * hiEvtPlanesqx[1] + hiEvtPlanesqy[1] * hiEvtPlanesqy[1] );
		}
		return deltaphi;
	}

	if( floworder == 2 )
	{
		if( dcandeta >= 0 )   
		{
			deltaphi = dcandphi - hiEvtPlanes[6];
			SP_Qmag_v2 = TMath::Sqrt( hiEvtPlanesqx[6] * hiEvtPlanesqx[6] + hiEvtPlanesqy[6] * hiEvtPlanesqy[6] );
		}
		else 
		{
			deltaphi = dcandphi - hiEvtPlanes[7];
			SP_Qmag_v2 = TMath::Sqrt( hiEvtPlanesqx[7] * hiEvtPlanesqx[7] + hiEvtPlanesqy[7] * hiEvtPlanesqy[7] );
		}
		return deltaphi;
	}

	if( floworder == 3 )
	{
		if( dcandeta >= 0 )   
		{
			deltaphi = dcandphi - hiEvtPlanes[13];
			SP_Qmag_v3 = TMath::Sqrt( hiEvtPlanesqx[13] * hiEvtPlanesqx[13] + hiEvtPlanesqy[13] * hiEvtPlanesqy[13] );
		}
		else 
		{
			deltaphi = dcandphi - hiEvtPlanes[14];
			SP_Qmag_v3 = TMath::Sqrt( hiEvtPlanesqx[14] * hiEvtPlanesqx[14] + hiEvtPlanesqy[14] * hiEvtPlanesqy[14] );
		}
		return deltaphi;
	}

	if( floworder == 4 )
	{
		if( dcandeta >= 0 )   
		{
			deltaphi = dcandphi - hiEvtPlanes[19];
			SP_Qmag_v4 = TMath::Sqrt( hiEvtPlanesqx[19] * hiEvtPlanesqx[19] + hiEvtPlanesqy[19] * hiEvtPlanesqy[19] );
		}
		else 
		{
			deltaphi = dcandphi - hiEvtPlanes[20];
			SP_Qmag_v4 = TMath::Sqrt( hiEvtPlanesqx[20] * hiEvtPlanesqx[20] + hiEvtPlanesqy[20] * hiEvtPlanesqy[20] );
		}
		return deltaphi;
	}

	return -99.;
}

int anaDntuple::Decideinoutplane(float deltaphi, int floworder)
{
	if( floworder < 1 || floworder > 5 )    { cout << "floworder out of range!!!!!!!!!" << endl; return -1; }

	int iphi = -1;

	if( floworder == 1 )
	{
		if( deltaphi < 0 )   deltaphi = deltaphi + 2.*PI;
		if( ( deltaphi >= 0 && deltaphi < PI/2. ) || ( deltaphi >= 3.*PI/2. && deltaphi < 2.*PI ) )  iphi = 0;
		else if( deltaphi >= PI/2. && deltaphi < 3.*PI/2. )  iphi = 1;
		return iphi;
	}

	if( floworder == 2 )
	{
		if( deltaphi < -1.*PI/4. ) deltaphi = deltaphi + 2.*PI;
		if( ( deltaphi > -1.*PI/4. && deltaphi < PI/4. ) || ( deltaphi > 3.*PI/4. && deltaphi < 5.*PI/4 ) )  iphi = 0;
		else if( ( deltaphi > PI/4. && deltaphi < 3.*PI/4. ) || ( deltaphi > 5.*PI/4. && deltaphi < 7.*PI/4. ) )  iphi =1;
		return iphi;
	}

	if( floworder == 3 )
	{
		if( deltaphi < -1.*PI/6. ) deltaphi = deltaphi + 2.*PI;
		if( ( deltaphi > -1.*PI/6 && deltaphi < PI/6. ) || ( deltaphi > PI/2. && deltaphi < 5.*PI/6 ) || ( deltaphi > 7.*PI/6. && deltaphi < 3.*PI/2.) )
			iphi = 0;
		else
			if( ( deltaphi > PI/6. && deltaphi < PI/2. ) || ( deltaphi > 5.*PI/6 && deltaphi < 7.*PI/6. ) || ( deltaphi > 3.*PI/2. && deltaphi < 11.*PI/6.))
				iphi = 1;
		return iphi;
	}

	if( floworder == 4 )
	{
		if( deltaphi < -1.*PI/8. ) deltaphi = deltaphi + 2.*PI;
		if( ( deltaphi > -1.*PI/8. && deltaphi < PI/8. ) || ( deltaphi > 3.*PI/8. && deltaphi < 5.*PI/8. ) || ( deltaphi > 7.*PI/8. && deltaphi < 9.*PI/8.)  || ( deltaphi > 11.*PI/8. && deltaphi < 13.*PI/8. ) )
			iphi = 0;
		else
			if( ( deltaphi > PI/8. && deltaphi < 3.*PI/8. ) || ( deltaphi > 5.*PI/8. && deltaphi < 7.*PI/8. ) || ( deltaphi > 9.*PI/8. && deltaphi < 11.*PI/8. ) || ( deltaphi > 13.*PI/8. && deltaphi < 15.*PI/8. ) )
				iphi = 1;
		return iphi;
	}

	return -1;
}

void anaDntuple::FillMCMBhisto(int icand, int iptbin)
{
	double Candptweight = MCPtWeidhtFunction->Eval( Dpt[icand]);

	if( MBtrig_part_combined && Dgen[icand] == 23333 )
	{
		mc_matched_signal_noweight[iptbin]->Fill(Dmass[icand]);
		mc_matched_signal_pthatweight[iptbin]->Fill(Dmass[icand], pthatweight);
		mc_matched_signal_ptweight[iptbin]->Fill( Dmass[icand], Candptweight);

		MBmatched_allcuts_D0_pt_noweight->Fill(Dpt[icand]);
		MBmatched_allcuts_D0_pt_pthatweight->Fill(Dpt[icand], pthatweight);
		MBmatched_allcuts_D0_pt_ptweight->Fill(Dpt[icand], Candptweight);
	}

	if( MBtrig_part_combined && Dgen[icand] == 23344 )
	{
		mc_matched_kpiswapped_noweight[iptbin]->Fill(Dmass[icand]);
		mc_matched_kpiswapped_pthatweight[iptbin]->Fill(Dmass[icand], pthatweight);
		mc_matched_kpiswapped_ptweight[iptbin]->Fill(Dmass[icand], Candptweight);
	}
}

void anaDntuple::FillMBhisto(int icand, int iptbin)
{
	if( MBtrig_part_combined )
	{
		hmass_MB_HFandpart[iptbin]->Fill(Dmass[icand]);

		if( isPbPbCollision )
		{
			hmass_MB_HFandpart_v1[iptbin][dcandiphiv1]->Fill(Dmass[icand]);
			hmass_MB_HFandpart_v2[iptbin][dcandiphiv2]->Fill(Dmass[icand]);
			hmass_MB_HFandpart_v3[iptbin][dcandiphiv3]->Fill(Dmass[icand]);
			hmass_MB_HFandpart_v4[iptbin][dcandiphiv4]->Fill(Dmass[icand]);

			h_mass_v1_MB_HFandpart[iptbin]->Fill(Dmass[icand], TMath::Cos(dcanddeltaphiv1)/EP_resolution_v1);
			h_mass_v2_MB_HFandpart[iptbin]->Fill(Dmass[icand], TMath::Cos(2.*dcanddeltaphiv2)/EP_resolution_v2);
			h_mass_v3_MB_HFandpart[iptbin]->Fill(Dmass[icand], TMath::Cos(3.*dcanddeltaphiv3)/EP_resolution_v3);
			h_mass_v4_MB_HFandpart[iptbin]->Fill(Dmass[icand], TMath::Cos(4.*dcanddeltaphiv4)/EP_resolution_v4);

			//h_mass_v1_SP_MB_HFandpart[iptbin]->Fill(Dmass[icand], SP_Qmag_v1 * TMath::Cos(dcanddeltaphiv1)/SP_EP_resolution_v1);
			h_mass_v2_SP_MB_HFandpart[iptbin]->Fill(Dmass[icand], SP_Qmag_v2 * TMath::Cos(2.*dcanddeltaphiv2)/SP_EP_resolution_v2);
			h_mass_v3_SP_MB_HFandpart[iptbin]->Fill(Dmass[icand], SP_Qmag_v3 * TMath::Cos(3.*dcanddeltaphiv3)/SP_EP_resolution_v3);
			//h_mass_v4_SP_MB_HFandpart[iptbin]->Fill(Dmass[icand], SP_Qmag_v4 * TMath::Cos(4.*dcanddeltaphiv4)/SP_EP_resolution_v4);
		}
	}

	if( isPbPbCollision ) //centrality MB trig
	{
		if( MBtrig_cent30to100_part_combined && !MBtrig_part_combined)  
			//if( MBtrig_cent30to100_part_combined )  
			hmass_MB_cent30to100_trig[iptbin]->Fill(Dmass[icand]);

		if( MBtrig_cent50to100_part_combined && !MBtrig_part_combined && !MBtrig_cent30to100_part_combined )  
			//if( MBtrig_cent50to100_part_combined )  
			hmass_MB_cent50to100_trig[iptbin]->Fill(Dmass[icand]);

		if( MBtrig_cent70to100_part_combined && !MBtrig_part_combined && !MBtrig_cent30to100_part_combined && !MBtrig_cent50to100_part_combined)  
			//if( MBtrig_cent70to100_part_combined )  
			hmass_MB_cent70to100_trig[iptbin]->Fill(Dmass[icand]);
	}
}

void anaDntuple::FillMCDtrighisto(int icand, int iptbin)
{
	double Candptweight = MCPtWeidhtFunction->Eval( Dpt[icand]);

	if( Dtrig_combined && Dgen[icand] == 23333 )
	{
		Dtrig_mc_matched_signal_noweight[iptbin]->Fill(Dmass[icand]);
		Dtrig_mc_matched_signal_pthatweight[iptbin]->Fill(Dmass[icand], pthatweight);
		Dtrig_mc_matched_signal_ptweight[iptbin]->Fill(Dmass[icand],Candptweight);

		Dtrigmatched_allcuts_D0_pt_noweight->Fill(Dpt[icand]);
		Dtrigmatched_allcuts_D0_pt_pthatweight->Fill(Dpt[icand], pthatweight);
		Dtrigmatched_allcuts_D0_pt_ptweight->Fill(Dpt[icand],Candptweight);
	}

	if( Dtrig_combined && Dgen[icand] == 23344 )
	{
		Dtrig_mc_matched_kpiswapped_noweight[iptbin]->Fill(Dmass[icand]);
		Dtrig_mc_matched_kpiswapped_pthatweight[iptbin]->Fill(Dmass[icand], pthatweight);
		Dtrig_mc_matched_kpiswapped_ptweight[iptbin]->Fill(Dmass[icand],Candptweight);
	}
}

void anaDntuple::FillDtrighisto_pp(int icand, int iptbin)
{
	if( HLT_DmesonPPTrackingGlobal_Dpt8_v1 )   hmass_Dpt8[iptbin]->Fill(Dmass[icand]);
	if( HLT_DmesonPPTrackingGlobal_Dpt15_v1 )   hmass_Dpt15[iptbin]->Fill(Dmass[icand]);
	if( HLT_DmesonPPTrackingGlobal_Dpt20_v1 )   hmass_Dpt20[iptbin]->Fill(Dmass[icand]);
	if( HLT_DmesonPPTrackingGlobal_Dpt30_v1 )   hmass_Dpt30[iptbin]->Fill(Dmass[icand]);
	if( HLT_DmesonPPTrackingGlobal_Dpt40_v1 )   hmass_Dpt40[iptbin]->Fill(Dmass[icand]);
	if( HLT_DmesonPPTrackingGlobal_Dpt50_v1 )   hmass_Dpt50[iptbin]->Fill(Dmass[icand]);
	if( HLT_DmesonPPTrackingGlobal_Dpt60_v1 )   hmass_Dpt60[iptbin]->Fill(Dmass[icand]);
	if( Dtrig_combined )  hmass_Dtrig_combined[iptbin]->Fill(Dmass[icand]);
}

void anaDntuple::FillDtrighisto_PbPb(int icand, int iptbin)
{
	if( HLT_HIDmesonHITrackingGlobal_Dpt20_combined ) hmass_Dpt20[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_combined ) hmass_Dpt20_cent0to10[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_combined ) hmass_Dpt20_cent30to100[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_combined ) hmass_Dpt20_cent50to100[iptbin]->Fill(Dmass[icand]);

	if( HLT_HIDmesonHITrackingGlobal_Dpt30_v1 ) hmass_Dpt30[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_combined ) hmass_Dpt30_cent0to10[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1 ) hmass_Dpt30_cent30to100[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1 ) hmass_Dpt30_cent50to100[iptbin]->Fill(Dmass[icand]);

	if( HLT_HIDmesonHITrackingGlobal_Dpt40_v1 ) hmass_Dpt40[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_combined ) hmass_Dpt40_cent0to10[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1 ) hmass_Dpt40_cent30to100[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1 ) hmass_Dpt40_cent50to100[iptbin]->Fill(Dmass[icand]);

	if( HLT_HIDmesonHITrackingGlobal_Dpt50_v1 ) hmass_Dpt50[iptbin]->Fill(Dmass[icand]);

	if( HLT_HIDmesonHITrackingGlobal_Dpt60_v1 ) hmass_Dpt60[iptbin]->Fill(Dmass[icand]);
	//	if( HLT_HIDmesonHITrackingGlobal_Dpt60_Cent0_10_v1 ) hmass_Dpt60_cent0to10[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1 ) hmass_Dpt60_cent30to100[iptbin]->Fill(Dmass[icand]);
	if( HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1 ) hmass_Dpt60_cent50to100[iptbin]->Fill(Dmass[icand]);

	if( HLT_HIDmesonHITrackingGlobal_Dpt70_v1 ) hmass_Dpt70[iptbin]->Fill(Dmass[icand]);

	if( Dtrig_combined )  
	{
		hmass_Dtrig_combined[iptbin]->Fill(Dmass[icand]);

		hmass_Dtrig_combined_v1[iptbin][dcandiphiv1]->Fill(Dmass[icand]);
		hmass_Dtrig_combined_v2[iptbin][dcandiphiv2]->Fill(Dmass[icand]);
		hmass_Dtrig_combined_v3[iptbin][dcandiphiv3]->Fill(Dmass[icand]);
		hmass_Dtrig_combined_v4[iptbin][dcandiphiv4]->Fill(Dmass[icand]);

		h_mass_v1_Dtrig_combined[iptbin]->Fill(Dmass[icand], TMath::Cos(dcanddeltaphiv1)/EP_resolution_v1);
		h_mass_v2_Dtrig_combined[iptbin]->Fill(Dmass[icand], TMath::Cos(2.*dcanddeltaphiv2)/EP_resolution_v2);
		h_mass_v3_Dtrig_combined[iptbin]->Fill(Dmass[icand], TMath::Cos(3.*dcanddeltaphiv3)/EP_resolution_v3);
		h_mass_v4_Dtrig_combined[iptbin]->Fill(Dmass[icand], TMath::Cos(4.*dcanddeltaphiv4)/EP_resolution_v4);

		//h_mass_v1_SP_Dtrig_combined[iptbin]->Fill(Dmass[icand], SP_Qmag_v1 * TMath::Cos(dcanddeltaphiv1)/SP_EP_resolution_v1);
		h_mass_v2_SP_Dtrig_combined[iptbin]->Fill(Dmass[icand], SP_Qmag_v2 * TMath::Cos(2.*dcanddeltaphiv2)/SP_EP_resolution_v2);
		h_mass_v3_SP_Dtrig_combined[iptbin]->Fill(Dmass[icand], SP_Qmag_v3 * TMath::Cos(3.*dcanddeltaphiv3)/SP_EP_resolution_v3);
		//h_mass_v4_SP_Dtrig_combined[iptbin]->Fill(Dmass[icand], SP_Qmag_v4 * TMath::Cos(4.*dcanddeltaphiv4)/SP_EP_resolution_v4);
	}
}

void anaDntuple::FillJettrighisto( int icand, int iptbin )
{
	if( isPbPbCollision )
	{
	}
	else
	{
		if( HLT_AK4CaloJet40_Eta5p1_v1 ) hmass_CaloJet40[iptbin]->Fill(Dmass[icand]);
		if( HLT_AK4CaloJet60_Eta5p1_v1 ) hmass_CaloJet60[iptbin]->Fill(Dmass[icand]);
		if( HLT_AK4CaloJet80_Eta5p1_v1 ) hmass_CaloJet80[iptbin]->Fill(Dmass[icand]);
		if( HLT_AK4CaloJet100_Eta5p1_v1 ) hmass_CaloJet100[iptbin]->Fill(Dmass[icand]);
	}
}

void anaDntuple::Write()
{
	outputfile->cd();

	hevt_trig_hiBin->Write();
	h_v1_hiBin_cosndiffeppepm->Write();
	h_v2_hiBin_cosndiffeppepm->Write();
	h_v3_hiBin_cosndiffeppepm->Write();
	h_v4_hiBin_cosndiffeppepm->Write();
	h_v2_hiBin_HFm_QAB->Write();
	h_v2_hiBin_HFm_QAC->Write();
	h_v2_hiBin_HFm_QBC->Write();
	h_v2_hiBin_HFp_QAB->Write();
	h_v2_hiBin_HFp_QAC->Write();
	h_v2_hiBin_HFp_QBC->Write();
	h_v3_hiBin_HFm_QAB->Write();
	h_v3_hiBin_HFm_QAC->Write();
	h_v3_hiBin_HFm_QBC->Write();
	h_v3_hiBin_HFp_QAB->Write();
	h_v3_hiBin_HFp_QAC->Write();
	h_v3_hiBin_HFp_QBC->Write();

	for(int i = 0; i<Nptbin; i++)
	{
		hmass_MB_HFandpart[i]->Write();
		hmass_MB_cent30to100_trig[i]->Write();
		hmass_MB_cent50to100_trig[i]->Write();
		hmass_MB_cent70to100_trig[i]->Write();

		hmass_Dtrig_combined[i]->Write();
		hmass_Dpt8[i]->Write();
		hmass_Dpt15[i]->Write();
		hmass_Dpt20[i]->Write();
		hmass_Dpt20_cent0to10[i]->Write();
		hmass_Dpt20_cent30to100[i]->Write();
		hmass_Dpt20_cent50to100[i]->Write();
		hmass_Dpt30[i]->Write();
		hmass_Dpt30_cent0to10[i]->Write();
		hmass_Dpt30_cent30to100[i]->Write();
		hmass_Dpt30_cent50to100[i]->Write();
		hmass_Dpt40[i]->Write();
		hmass_Dpt40_cent0to10[i]->Write();
		hmass_Dpt40_cent30to100[i]->Write();
		hmass_Dpt40_cent50to100[i]->Write();
		hmass_Dpt50[i]->Write();
		hmass_Dpt60[i]->Write();
		//		hmass_Dpt60_cent0to10[i]->Write();
		hmass_Dpt60_cent30to100[i]->Write();
		hmass_Dpt60_cent50to100[i]->Write();
		hmass_Dpt70[i]->Write();
	}

	if( isPbPbCollision )
	{
		for(int i = 0; i<Nptbin; i++)
		{
			for(int j = 0; j<Nphibin; j++)
			{
				hmass_MB_HFandpart_v1[i][j]->Write();
				hmass_MB_HFandpart_v2[i][j]->Write();
				hmass_MB_HFandpart_v3[i][j]->Write();
				hmass_MB_HFandpart_v4[i][j]->Write();
			}

			h_mass_v1_MB_HFandpart[i]->Write();
			h_mass_v2_MB_HFandpart[i]->Write();
			h_mass_v3_MB_HFandpart[i]->Write();
			h_mass_v4_MB_HFandpart[i]->Write();

			h_mass_v1_SP_MB_HFandpart[i]->Write();
			h_mass_v2_SP_MB_HFandpart[i]->Write();
			h_mass_v3_SP_MB_HFandpart[i]->Write();
			h_mass_v4_SP_MB_HFandpart[i]->Write();
		}

		for(int i = 0; i<Nptbin; i++)
		{
			for(int j = 0; j<Nphibin; j++)
			{
				hmass_Dtrig_combined_v1[i][j]->Write();
				hmass_Dtrig_combined_v2[i][j]->Write();
				hmass_Dtrig_combined_v3[i][j]->Write();
				hmass_Dtrig_combined_v4[i][j]->Write();
			}

			h_mass_v1_Dtrig_combined[i]->Write();
			h_mass_v2_Dtrig_combined[i]->Write();
			h_mass_v3_Dtrig_combined[i]->Write();
			h_mass_v4_Dtrig_combined[i]->Write();

			h_mass_v1_SP_Dtrig_combined[i]->Write();
			h_mass_v2_SP_Dtrig_combined[i]->Write();
			h_mass_v3_SP_Dtrig_combined[i]->Write();
			h_mass_v4_SP_Dtrig_combined[i]->Write();
		}
	}

	for(int i = 0; i<Nptbin; i++)
	{
		hmass_CaloJet40[i]->Write();
		hmass_CaloJet60[i]->Write();
		hmass_CaloJet80[i]->Write();
		hmass_CaloJet100[i]->Write();
	}

	if( isMC )
	{
		Gen_D0_pt_noweight_forptreweight->Write();
		FONLL_over_GenD0Pt_forptreweight->Write();
		Gen_D0_pt_pthatweight->Write();
		Gen_D0_pt_ptweight->Write();
		Gen_D0_pt_noweight->Write();
		MBmatched_allcuts_D0_pt_pthatweight->Write();
		MBmatched_allcuts_D0_pt_ptweight->Write();
		MBmatched_allcuts_D0_pt_noweight->Write();
		Dtrigmatched_allcuts_D0_pt_pthatweight->Write();
		Dtrigmatched_allcuts_D0_pt_ptweight->Write();
		Dtrigmatched_allcuts_D0_pt_noweight->Write();

		for(int i = 0; i<Nptbin; i++)
		{
			mc_matched_signal_noweight[i]->Write();
			mc_matched_kpiswapped_noweight[i]->Write();
			mc_matched_signal_ptweight[i]->Write();
			mc_matched_kpiswapped_ptweight[i]->Write();
			mc_matched_signal_pthatweight[i]->Write();
			mc_matched_kpiswapped_pthatweight[i]->Write();

			Dtrig_mc_matched_signal_noweight[i]->Write();
			Dtrig_mc_matched_kpiswapped_noweight[i]->Write();
			Dtrig_mc_matched_signal_ptweight[i]->Write();
			Dtrig_mc_matched_kpiswapped_ptweight[i]->Write();
			Dtrig_mc_matched_signal_pthatweight[i]->Write();
			Dtrig_mc_matched_kpiswapped_pthatweight[i]->Write();
		}
	}

}
