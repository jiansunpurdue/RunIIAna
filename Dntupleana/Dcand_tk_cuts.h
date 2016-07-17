#ifndef Dcand_tk_cuts_H
#define Dcand_tk_cuts_H

#define Nptbin 14

//MB binning
float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};
//will change to this bining
//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 20.0, 40.0, 60.0, 100.0, 200.0};

float vertex3dcut_PbPb[Nptbin] =   {6.0, 6.0, 6.0, 5.86, 5.86, 4.86, 4.54, 4.42, 4.06, 3.5, 3.0, 3.0,  3.0,  3.0};
float vertexprobcut_PbPb[Nptbin] = {0.25, 0.25, 0.25, 0.224, 0.224, 0.170, 0.125, 0.091, 0.069, 0.054, 0.05, 0.05, 0.05, 0.05};
float alphacut_PbPb[Nptbin]  = {0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12};
float DlxyBScut_PbPb_MB = -1.5;
float DlxyBScut_PbPb_Dtrig = 1.5;

float vertex3dcut_pp[Nptbin]  =  {3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
float vertexprobcut_pp[Nptbin] = { 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
float alphacut_pp[Nptbin]  =   {0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12};
float DlxyBScut_pp_MB = -1.5;
float DlxyBScut_pp_Dtrig = 1.5;

////DCA cut for default histogram
float DcandDCA_cut_default = 0.008;
//DCA sequence cut
//#define NDCAcut 7 
//float DcandDCA_cut_sequence[NDCAcut] = { 99999., 0.04, 0.03, 0.02, 0.01, 0.008, 0.005};

//vertex vz cut
#define vz_cut 15.0

//track cuts
//PbPb
#define MBTkptcut_PbPb 0.7
#define Tketacut_PbPb 1.2
//#define Tketacut_PbPb 1.5
#define TrigTkptcut_PbPb 8.5
//pp
#define MBTkptcut_pp 0.7
#define Tketacut_pp 1.2
//#define Tketacut_pp 1.5
#define TrigTkptcut_pp 3.0

//D rapidity and track eta cuts
#define Drapiditycut 1.0
#define TkPtresolution_MB 0.1
#define TkHitCut_MB 10.5 //>=
#define Tknorchi2overlayers_MB 0.15 //no cut //<

#define TkPtresolution_Trig 0.1
#define TkHitCut_Trig 10.5 //>=
#define Tknorchi2overlayers_Trig 0.15 //<
#define TkAlgoCut_Trig 7.5 //<=

#endif //  Dcand_tk_cuts_H
