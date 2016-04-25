#!/bin/sh

DoCombinemassvnfit=1 # now just work for Fitoption="poly3bkg"

ptbinstart=2
ptbinend=12
ptmin=0.0
ptmax=45.0
MBorDtrig="MBtrig"
Fitoption="poly3bkg"

InputMC="./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root"

InputMBdata0to100="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMBdata0to10="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMBdata10to30="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMBdata30to50="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMBdata50to70="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"


EPorSP="SP"
if [ $DoCombinemassvnfit -eq 1 ]; then

root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'")'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'")'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'")'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'")'
fi

./cleanup.sh
