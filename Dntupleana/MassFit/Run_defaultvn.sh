#!/bin/sh

DoCombinemassvnfit=1
DoDrawcombindfitvn=1
DoCompare2stepfit_combinefit_vn=0

DoMassFitMorephibin=1
DODrawmorephibinvn=1
DOVncomparison=1

ptbinstart=2
ptbinend=11 #not included
ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
Fitoption="poly3bkg_floatwidth"
#Fitoption="expobkg_2nd_floatwidth"
#Fitoption="poly2bkg_floatwidth"

Doefficiencycorrection=0 #only if poly3bkg_floatwidth

InputMC="./../rootfiles/anaDntuple_ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight_Cent-0to100_Evt0to-1.root"

InputMBdata0to100="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMBdata0to10="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMBdata10to30="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMBdata30to50="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMBdata50to70="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

InputMB0to100_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB0to10_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB10to30_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB30to50_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB50to70_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to10_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent50to70_${Fitoption}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to100_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to100_${Fitoption}.root"
FileVnMB0to10_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to10_${Fitoption}.root"
FileVnMB10to30_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent10to30_${Fitoption}.root"
FileVnMB30to50_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50_${Fitoption}.root"
FileVnMB50to70_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent50to70_${Fitoption}.root"
#################### more phi bin method

InputMB0to100_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB0to10_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB10to30_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB30to50_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
InputMB50to70_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to100_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to100_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB0to10_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to10_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_morephibin="rootfiles/vn_morephibin_MBtrig_cent10to30_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_morephibin="rootfiles/vn_morephibin_MBtrig_cent30to50_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_morephibin="rootfiles/vn_morephibin_MBtrig_cent50to70_${Fitoption}_effcorrected${Doefficiencycorrection}.root"
#####################################
EPorSP="SP"

if [ $DoCombinemassvnfit -eq 1 ]; then

root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'",'$Doefficiencycorrection')'
fi

if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB0to10_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax',"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB10to30_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax',"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB30to50_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax',"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB50to70_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax',"'$Fitoption'",'$Doefficiencycorrection')'
fi

if [ $DoCompare2stepfit_combinefit_vn -eq 1 ]; then
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB0to10_SP_Vnvsmass'","'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB10to30_SP_Vnvsmass'","'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB30to50_SP_Vnvsmass'","'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB50to70_SP_Vnvsmass'","'$FileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax')'
fi

###################################
######## deltaphibins method

if [ $DoMassFitMorephibin -eq 1 ]; then
#
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'",'$Doefficiencycorrection')'
mv Massfitplots/PbPb/*.pdf Plots_vn/Massfitforvn
fi

if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB0to10_drawvn_morephibin'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend',"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB10to30_drawvn_morephibin'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend',"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB30to50_drawvn_morephibin'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend',"'$Fitoption'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB50to70_drawvn_morephibin'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend',"'$Fitoption'",'$Doefficiencycorrection')'
fi

###############################
########## comparison
Drawchargedparticle=0
if [ $DOVncomparison -eq 1 ] && [ $Doefficiencycorrection -eq 0 ]; then
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption'")'
fi
