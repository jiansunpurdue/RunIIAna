#ifndef parameters_H
#define parameters_H

#include <TH2D.h>
#include <TH1D.h>
#include <TProfile.h>

#define PI 3.14159265

#define Nptbin 22

float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 12.0, 16.0, 20.0, 25.0, 30.0, 
                                  35.0, 40.0, 45.0, 50.0, 60.0, 80.0, 100.0, 120.0, 150.0, 200.0};

float vertex3dcut_PbPb[Nptbin] = {6.0, 6.0, 6.0, 5.86, 5.86, 4.86, 4.54, 4.42, 4.06, 3.71, 3.25, 3.0, 3.0, 
                                    3.0,  3.0,  3.0,  3.0,  3.0,   3.0,  3.0,  3.0,  3.0};
float alphacut_PbPb[Nptbin]  = {0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 
                                    0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12};
float vertexprobcut_PbPb[Nptbin] = {0.25, 0.25, 0.25, 0.224, 0.224, 0.170, 0.125, 0.091, 0.069, 0.056, 0.054, 0.05, 0.05,
                                    0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
float DlxyBScut_PbPb_MB = -1.5;
float DlxyBScut_PbPb_Dtrig = 1.5;

float vertex3dcut_pp[Nptbin]  =  {3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,  3.0,  3.0,  3.0, 3.0, 3.0, 
                                    3.0,  3.0,  3.0,  3.0,  3.0, 3.0,  3.0,  3.0,  3.0};
float alphacut_pp[Nptbin]  =   {0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 
                                    0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12};
float vertexprobcut_pp[Nptbin] = { 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05,
                                    0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
float DlxyBScut_pp_MB = -1.5;
float DlxyBScut_pp_Dtrig = 1.5;

//track cuts
//PbPb
#define MBTkptcut_PbPb 0.7
//#define MBTkptcut_PbPb 1.0  //should be lowered a bit when MC sample is produced with lower track pt cut
#define Tketacut_PbPb 1.2
#define TrigTkptcut_PbPb 8.5
//pp
#define MBTkptcut_pp 0.7
//#define MBTkptcut_pp 1.0
#define Tketacut_pp 1.2
#define TrigTkptcut_pp 3.0

//D rapidity and track eta cuts
#define Drapiditycut 1.0
#define TkPtresolution_MB 0.3
#define TkPtresolution_Trig 0.1
#define TkHitCut_Trig 10.5 //>=
#define TkAlgoCut_Trig 7.5 //<=

//histograms to be filled
const float massmin = 1.7;
const float massmax = 2.00;
const int   Nmassbin = 60;
const double initialmassbinsize = (massmax - massmin) / Nmassbin;

const double generalfitrange_masslow = 1.7;
const double generalfitrange_masshigh = 2.00;

//MC pt reweight parameters
double ptmin_reweight = 0.0;
double ptmax_reweight = 100.0;
int bins_reweight = 50;
TH1D * Gen_D0_pt_noweight_forptreweight = new TH1D( "Gen_D0_pt_noweight_forptreweight", "Gen_D0_pt_noweight_forptreweight", bins_reweight, ptmin_reweight, ptmax_reweight);
TH1D * FONLL_over_GenD0Pt_forptreweight;

//mc histograms 
TH1D * Gen_D0_pt_pthatweight = new TH1D("Gen_D0_pt_pthatweight","Gen_D0_pt_pthatweight",Nptbin,ptbins);
TH1D * Gen_D0_pt_ptweight = new TH1D("Gen_D0_pt_ptweight","Gen_D0_pt_ptweight",Nptbin,ptbins);
TH1D * Gen_D0_pt_noweight = new TH1D("Gen_D0_pt_noweight","Gen_D0_pt_noweight",Nptbin,ptbins);
TH1D * MBmatched_allcuts_D0_pt_pthatweight = new TH1D("MBmatched_allcuts_D0_pt_pthatweight","MBmatched_allcuts_D0_pt_pthatweight",Nptbin,ptbins);
TH1D * MBmatched_allcuts_D0_pt_ptweight = new TH1D("MBmatched_allcuts_D0_pt_ptweight","MBmatched_allcuts_D0_pt_ptweight",Nptbin,ptbins);
TH1D * MBmatched_allcuts_D0_pt_noweight = new TH1D("MBmatched_allcuts_D0_pt_noweight","MBmatched_allcuts_D0_pt_noweight",Nptbin,ptbins);
TH1D * Dtrigmatched_allcuts_D0_pt_pthatweight = new TH1D("Dtrigmatched_allcuts_D0_pt_pthatweight","Dtrigmatched_allcuts_D0_pt_pthatweight",Nptbin,ptbins);
TH1D * Dtrigmatched_allcuts_D0_pt_ptweight = new TH1D("Dtrigmatched_allcuts_D0_pt_ptweight","Dtrigmatched_allcuts_D0_pt_ptweight",Nptbin,ptbins);
TH1D * Dtrigmatched_allcuts_D0_pt_noweight = new TH1D("Dtrigmatched_allcuts_D0_pt_noweight","Dtrigmatched_allcuts_D0_pt_noweight",Nptbin,ptbins);

TH1D * mc_matched_signal_noweight[Nptbin];
TH1D * mc_matched_kpiswapped_noweight[Nptbin];
TH1D * mc_matched_signal_ptweight[Nptbin];
TH1D * mc_matched_kpiswapped_ptweight[Nptbin];
TH1D * mc_matched_signal_pthatweight[Nptbin];
TH1D * mc_matched_kpiswapped_pthatweight[Nptbin];

TH1D * Dtrig_mc_matched_signal_noweight[Nptbin];
TH1D * Dtrig_mc_matched_kpiswapped_noweight[Nptbin];
TH1D * Dtrig_mc_matched_signal_ptweight[Nptbin];
TH1D * Dtrig_mc_matched_kpiswapped_ptweight[Nptbin];
TH1D * Dtrig_mc_matched_signal_pthatweight[Nptbin];
TH1D * Dtrig_mc_matched_kpiswapped_pthatweight[Nptbin];

//event level trigger decision
TH2D * hevt_trig_hiBin = new TH2D("hevt_trig_hiBin","hevt_trig_hiBin", 35, 0, 35, 200, 0, 200); //2D histogram for trig vs hiBin

//for event plane resolution with 2-sub event
#define NCentbins 6
double hibinbins[NCentbins+1] = { -0.5, 19.5, 59.5, 99.5, 139.5, 179.5, 199.5};
TProfile * h_v1_hiBin_cosndiffeppepm = new TProfile("h_v1_hiBin_cosndiffeppepm","h_v1_hiBin_cosndiffeppepm", NCentbins, hibinbins);
TProfile * h_v2_hiBin_cosndiffeppepm = new TProfile("h_v2_hiBin_cosndiffeppepm","h_v2_hiBin_cosndiffeppepm", NCentbins, hibinbins);
TProfile * h_v3_hiBin_cosndiffeppepm = new TProfile("h_v3_hiBin_cosndiffeppepm","h_v3_hiBin_cosndiffeppepm", NCentbins, hibinbins);
TProfile * h_v4_hiBin_cosndiffeppepm = new TProfile("h_v4_hiBin_cosndiffeppepm","h_v4_hiBin_cosndiffeppepm", NCentbins, hibinbins);

TProfile * h_v2_hiBin_HFm_QAB = new TProfile("h_v2_hiBin_HFm_QAB","h_v2_hiBin_HFm_QAB", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFm_QAC = new TProfile("h_v2_hiBin_HFm_QAC","h_v2_hiBin_HFm_QAC", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFm_QBC = new TProfile("h_v2_hiBin_HFm_QBC","h_v2_hiBin_HFm_QBC", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFp_QAB = new TProfile("h_v2_hiBin_HFp_QAB","h_v2_hiBin_HFp_QAB", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFp_QAC = new TProfile("h_v2_hiBin_HFp_QAC","h_v2_hiBin_HFp_QAC", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFp_QBC = new TProfile("h_v2_hiBin_HFp_QBC","h_v2_hiBin_HFp_QBC", NCentbins, hibinbins);

TProfile * h_v3_hiBin_HFm_QAB = new TProfile("h_v3_hiBin_HFm_QAB","h_v3_hiBin_HFm_QAB", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFm_QAC = new TProfile("h_v3_hiBin_HFm_QAC","h_v3_hiBin_HFm_QAC", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFm_QBC = new TProfile("h_v3_hiBin_HFm_QBC","h_v3_hiBin_HFm_QBC", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFp_QAB = new TProfile("h_v3_hiBin_HFp_QAB","h_v3_hiBin_HFp_QAB", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFp_QAC = new TProfile("h_v3_hiBin_HFp_QAC","h_v3_hiBin_HFp_QAC", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFp_QBC = new TProfile("h_v3_hiBin_HFp_QBC","h_v3_hiBin_HFp_QBC", NCentbins, hibinbins);

//foreground
TH1D * hmass_MB_HFandpart[Nptbin];
TH1D * hmass_MB_cent30to100_trig[Nptbin];
TH1D * hmass_MB_cent50to100_trig[Nptbin];
TH1D * hmass_MB_cent70to100_trig[Nptbin];

TH1D * hmass_Dtrig_combined[Nptbin];

TH1D * hmass_Dpt8[Nptbin];
TH1D * hmass_Dpt15[Nptbin];
TH1D * hmass_Dpt20[Nptbin];
TH1D * hmass_Dpt20_cent0to10[Nptbin];
TH1D * hmass_Dpt20_cent30to100[Nptbin];
TH1D * hmass_Dpt20_cent50to100[Nptbin];
TH1D * hmass_Dpt30[Nptbin];
TH1D * hmass_Dpt30_cent0to10[Nptbin];
TH1D * hmass_Dpt30_cent30to100[Nptbin];
TH1D * hmass_Dpt30_cent50to100[Nptbin];
TH1D * hmass_Dpt40[Nptbin];
TH1D * hmass_Dpt40_cent0to10[Nptbin];
TH1D * hmass_Dpt40_cent30to100[Nptbin];
TH1D * hmass_Dpt40_cent50to100[Nptbin];
TH1D * hmass_Dpt50[Nptbin];
TH1D * hmass_Dpt50_cent0to10[Nptbin];
TH1D * hmass_Dpt50_cent30to100[Nptbin];
TH1D * hmass_Dpt50_cent50to100[Nptbin];
TH1D * hmass_Dpt60[Nptbin];
TH1D * hmass_Dpt60_cent0to10[Nptbin];
TH1D * hmass_Dpt60_cent30to100[Nptbin];
TH1D * hmass_Dpt60_cent50to100[Nptbin];
TH1D * hmass_Dpt70[Nptbin];
TH1D * hmass_Dpt70_cent0to10[Nptbin];
TH1D * hmass_Dpt70_cent30to100[Nptbin];
TH1D * hmass_Dpt70_cent50to100[Nptbin];

TH1D * hmass_CaloJet40[Nptbin];
TH1D * hmass_CaloJet60[Nptbin];
TH1D * hmass_CaloJet80[Nptbin];
TH1D * hmass_CaloJet100[Nptbin];

//for vn calculation

//in and out plane method
#define Nphibin 2
TH1D * hmass_MB_HFandpart_v1[Nptbin][Nphibin];
TH1D * hmass_MB_HFandpart_v2[Nptbin][Nphibin];
TH1D * hmass_MB_HFandpart_v3[Nptbin][Nphibin];
TH1D * hmass_MB_HFandpart_v4[Nptbin][Nphibin];

TH1D * hmass_Dtrig_combined_v1[Nptbin][Nphibin];
TH1D * hmass_Dtrig_combined_v2[Nptbin][Nphibin];
TH1D * hmass_Dtrig_combined_v3[Nptbin][Nphibin];
TH1D * hmass_Dtrig_combined_v4[Nptbin][Nphibin];

//#define Vn_low -1.5
//#define Vn_high 1.5
//#define N_Vnbin 1000
//invariant mass method
//should use TProfile instead of TH2D
TProfile * h_mass_v1_MB_HFandpart[Nptbin];
TProfile * h_mass_v2_MB_HFandpart[Nptbin];
TProfile * h_mass_v3_MB_HFandpart[Nptbin];
TProfile * h_mass_v4_MB_HFandpart[Nptbin];

TProfile * h_mass_v1_Dtrig_combined[Nptbin];
TProfile * h_mass_v2_Dtrig_combined[Nptbin];
TProfile * h_mass_v3_Dtrig_combined[Nptbin];
TProfile * h_mass_v4_Dtrig_combined[Nptbin];

TProfile * h_mass_v1_SP_MB_HFandpart[Nptbin];
TProfile * h_mass_v2_SP_MB_HFandpart[Nptbin];
TProfile * h_mass_v3_SP_MB_HFandpart[Nptbin];
TProfile * h_mass_v4_SP_MB_HFandpart[Nptbin];

TProfile * h_mass_v1_SP_Dtrig_combined[Nptbin];
TProfile * h_mass_v2_SP_Dtrig_combined[Nptbin];
TProfile * h_mass_v3_SP_Dtrig_combined[Nptbin];
TProfile * h_mass_v4_SP_Dtrig_combined[Nptbin];

#endif //  parameters_H
