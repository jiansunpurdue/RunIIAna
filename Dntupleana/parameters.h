#ifndef parameters_H
#define parameters_H

#include <TH2D.h>
#include <TH1D.h>
#include <TProfile.h>

#include "Dcand_tk_cuts.h"

#define PI 3.1415926536

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

//to fit efficiency curve
TH1D * Gen_D0_pt_ptweight_finebins = new TH1D("Gen_D0_pt_ptweight_finebins","Gen_D0_pt_ptweight_finebins",100,0,100.);
TH1D * MBmatched_allcuts_D0_pt_ptweight_finebins = new TH1D("MBmatched_allcuts_D0_pt_ptweight_finebins","MBmatched_allcuts_D0_pt_ptweight_finebins",100,0,100.);

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
//histograms for event plane
#define NEvtPlanesSave 35
TH1D * h_EvtPlane[NEvtPlanesSave];

//for data
#define NCentbins 6
double hibinbins[NCentbins+1] = { -0.5, 19.5, 59.5, 99.5, 139.5, 179.5, 199.5};
//for MC
//#define NCentbins 9 
//double hibinbins[NCentbins+1] = { -0.5, 9.5, 29.5, 69.5, 79.5, 99.5, 119.5, 139.5, 179.5, 199.5};
//#define NCentbins 6 
//double hibinbins[NCentbins+1] = { -0.5, 9.5, 39.5, 79.5, 119.5, 159.5, 199.5};

//for D cand Q vector recenter
TH2D * h_hiBin_Dcandphi = new TH2D("h_hiBin_Dcandphi","h_hiBin_Dcandphi",200,0,200,400,-4.,4.);

//for event plane resolution with 2-sub and 3-sub event
TProfile * h_v1_hiBin_cosndiffeppepm = new TProfile("h_v1_hiBin_cosndiffeppepm","h_v1_hiBin_cosndiffeppepm", NCentbins, hibinbins);
TProfile * h_v2_hiBin_cosndiffeppepm = new TProfile("h_v2_hiBin_cosndiffeppepm","h_v2_hiBin_cosndiffeppepm", NCentbins, hibinbins);
TProfile * h_v3_hiBin_cosndiffeppepm = new TProfile("h_v3_hiBin_cosndiffeppepm","h_v3_hiBin_cosndiffeppepm", NCentbins, hibinbins);
TProfile * h_v4_hiBin_cosndiffeppepm = new TProfile("h_v4_hiBin_cosndiffeppepm","h_v4_hiBin_cosndiffeppepm", NCentbins, hibinbins);

TProfile * h_v2_hiBin_HFm_cosndiffepAB = new TProfile("h_v2_hiBin_HFm_cosndiffepAB","h_v2_hiBin_HFm_cosndiffepAB", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFm_cosndiffepAC = new TProfile("h_v2_hiBin_HFm_cosndiffepAC","h_v2_hiBin_HFm_cosndiffepAC", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFm_cosndiffepBC = new TProfile("h_v2_hiBin_HFm_cosndiffepBC","h_v2_hiBin_HFm_cosndiffepBC", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFp_cosndiffepAB = new TProfile("h_v2_hiBin_HFp_cosndiffepAB","h_v2_hiBin_HFp_cosndiffepAB", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFp_cosndiffepAC = new TProfile("h_v2_hiBin_HFp_cosndiffepAC","h_v2_hiBin_HFp_cosndiffepAC", NCentbins, hibinbins);
TProfile * h_v2_hiBin_HFp_cosndiffepBC = new TProfile("h_v2_hiBin_HFp_cosndiffepBC","h_v2_hiBin_HFp_cosndiffepBC", NCentbins, hibinbins);

TProfile * h_v3_hiBin_HFm_cosndiffepAB = new TProfile("h_v3_hiBin_HFm_cosndiffepAB","h_v3_hiBin_HFm_cosndiffepAB", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFm_cosndiffepAC = new TProfile("h_v3_hiBin_HFm_cosndiffepAC","h_v3_hiBin_HFm_cosndiffepAC", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFm_cosndiffepBC = new TProfile("h_v3_hiBin_HFm_cosndiffepBC","h_v3_hiBin_HFm_cosndiffepBC", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFp_cosndiffepAB = new TProfile("h_v3_hiBin_HFp_cosndiffepAB","h_v3_hiBin_HFp_cosndiffepAB", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFp_cosndiffepAC = new TProfile("h_v3_hiBin_HFp_cosndiffepAC","h_v3_hiBin_HFp_cosndiffepAC", NCentbins, hibinbins);
TProfile * h_v3_hiBin_HFp_cosndiffepBC = new TProfile("h_v3_hiBin_HFp_cosndiffepBC","h_v3_hiBin_HFp_cosndiffepBC", NCentbins, hibinbins);

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

TH1D * hmass_MB_HFandpart_effcorrected[Nptbin];

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

//more delta phi bins
#define Nphibinmore 5
TH1D * h_phibins_v2 = new TH1D( "h_phibins_v2", "h_phibins_v2", Nphibinmore, 0, PI/2.);
TH1D * h_phibins_v3 = new TH1D( "h_phibins_v3", "h_phibins_v3", Nphibinmore, 0, PI/3.);

TH1D * hmass_MB_HFandpart_v2_morephibin[Nptbin][Nphibinmore];
TH1D * hmass_MB_HFandpart_v3_morephibin[Nptbin][Nphibinmore];

TH1D * hmass_MB_HFandpart_v2_morephibin_effcorrected[Nptbin][Nphibinmore];
TH1D * hmass_MB_HFandpart_v3_morephibin_effcorrected[Nptbin][Nphibinmore];

TH1D * hmass_Dtrig_combined_v2_morephibin[Nptbin][Nphibinmore];
TH1D * hmass_Dtrig_combined_v3_morephibin[Nptbin][Nphibinmore];

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

TProfile * h_mass_v2_SP_MB_HFandpart_effcorrected[Nptbin];
TProfile * h_mass_v3_SP_MB_HFandpart_effcorrected[Nptbin];

TProfile * h_mass_v1_SP_Dtrig_combined[Nptbin];
TProfile * h_mass_v2_SP_Dtrig_combined[Nptbin];
TProfile * h_mass_v3_SP_Dtrig_combined[Nptbin];
TProfile * h_mass_v4_SP_Dtrig_combined[Nptbin];

////for DCA cut sequence
//TH1D * hmass_MB_HFandpart_DCAsequence[NDCAcut][Nptbin];
//TProfile * h_mass_v2_SP_MB_HFandpart_DCAsequence[NDCAcut][Nptbin];
//TProfile * h_mass_v3_SP_MB_HFandpart_DCAsequence[NDCAcut][Nptbin];
//TH1D * hmass_MB_HFandpart_v2_morephibin_DCAsequence[NDCAcut][Nptbin][Nphibinmore];
//TH1D * hmass_MB_HFandpart_v3_morephibin_DCAsequence[NDCAcut][Nptbin][Nphibinmore];

#endif //  parameters_H
