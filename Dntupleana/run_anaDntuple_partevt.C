#include "anaDntuple.cc"

void run_anaDntuple_partevt(string intputfilename = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_withQvector_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016/Dntuple_crab_PbPb_HIMinimumBias3_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016.root", bool isPbPb = true, bool isMC = false, int startevt = 0, int endevt = 1000000, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 3)
//void run_anaDntuple_partevt(string intputfilename = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/PbPbMC/ntD_EvtBase_20160303_Dfinder_20160302_PbPb_Pythia8_prompt_D0_dPt1tkPt1_pthatweight.root", bool isPbPb = true, bool isMC = true, int startevt = 0, int endevt = -1, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99)
//void run_anaDntuple_partevt(string intputfilename = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/ppMC/ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight.root", bool isPbPb = false, bool isMC = true, int startevt = 0, int endevt = -1, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99)
//void run_anaDntuple_partevt(string intputfilename = "/mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/ppRun2015/skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016.root", bool isPbPb = false, bool isMC = false, int startevt = 0, int endevt = 100000, double hibin_low = -0.5, double hibin_high = 199.5, int PbPbMBPD = 99)
{
    anaDntuple *a = new anaDntuple;

    a->ProcessPartialEvents(intputfilename, isPbPb, isMC, startevt, endevt, hibin_low, hibin_high, PbPbMBPD);

    delete a; 
}
