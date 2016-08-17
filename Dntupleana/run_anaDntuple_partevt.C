#include "anaDntuple.cc"

void run_anaDntuple_partevt(string intputfilename = "file:////mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Right_Dntuple_crab_PbPb_HIMinimumBias_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016/Dntuple_crab_PbPb_HIMinimumBias3_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016.root", bool isPbPb = true, bool isMC = false, int startevt = 0, int endevt = 1000000, double hibin_low = 59.5, double hibin_high = 99.5, int PbPbMBPD = 3, bool EPlistdefault = false)
//void run_anaDntuple_partevt(string intputfilename = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias3_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root", bool isPbPb = true, bool isMC = false, int startevt = 0, int endevt = 1000000, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 3, bool EPlistdefault = true)
//void run_anaDntuple_partevt(string intputfilename = "/depot/fqwang/data/sun229/Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight.root", bool isPbPb = true, bool isMC = true, int startevt = 0, int endevt = -1, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99, bool EPlistdefault = true)
//void run_anaDntuple_partevt(string intputfilename = "/depot/cms/users/sun229/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root", bool isPbPb = true, bool isMC = true, int startevt = 0, int endevt = -1, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99)
//void run_anaDntuple_partevt(string intputfilename = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/ppRun2015/skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016.root", bool isPbPb = false, bool isMC = false, int startevt = 0, int endevt = 100000, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99)
//void run_anaDntuple_partevt(string intputfilename = "/depot/cms/users/sun229/ntD_EvtBase_20160513_DfinderMC_pp_20160502_dPt0tkPt0p5_D0Dstar_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root", bool isPbPb = false, bool isMC = true, int startevt = 0, int endevt = -1, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99)
{
    anaDntuple *a = new anaDntuple;

    a->ProcessPartialEvents(intputfilename, isPbPb, isMC, startevt, endevt, hibin_low, hibin_high, PbPbMBPD, EPlistdefault);

    delete a; 
}
