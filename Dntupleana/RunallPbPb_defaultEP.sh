#!/bin/sh

#hibin -0.5 19.5 0-10%
#hibin 19.5 59.5 10-30%
#hibin 59.5 99.5 30-50%
#hibin 99.5 139.5 50-70%

hibinlow=$1
hibinhigh=$2
jobindex=$3

#cp EvtPlaneList/HiEvtPlaneList_default.h HiEvtPlaneList.h

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias1_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 10000001 15 $hibinlow $hibinhigh 1 1 $jobindex

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias2_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 5000000 17 $hibinlow $hibinhigh 2 1 $jobindex

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias3_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 5000001 11 $hibinlow $hibinhigh 3 1 $jobindex

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias4_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 5000101 11 $hibinlow $hibinhigh 4 1 $jobindex

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias5_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 5000100 20 $hibinlow $hibinhigh 5 1 $jobindex

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias6_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 6000001 17 $hibinlow $hibinhigh 6 1 $jobindex

./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015/Dntuple_crab_PbPb_HIMinimumBias7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root 1 0 7000001 14 $hibinlow $hibinhigh 7 1 $jobindex

#./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_withQvector_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016/Dntuple_crab2_PbPb_HIHardProbes_Dtrig_ForestAOD_highpuritytk_D0_tkpt6p0eta1p5_goldenjson_02222016.root 1 0 2000001 3 $hibinlow $hibinhigh 16

#./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/Dntuple_withQvector_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016/Dntuple_crab2_PbPb_HIHardProbesPeripheral_Dtrig_ForestAOD_highpuritytk_D0_tkpt6p0eta1p5_goldenjson_02222016.root 1 0 1000010 1 $hibinlow $hibinhigh 17

#./Dividejob.sh /mnt/hadoop/store/group/hi/jisun/Run2015analysisfiles/ppRun2015/skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016.root 0 0 5000000 7 -0.5 199.5 99
