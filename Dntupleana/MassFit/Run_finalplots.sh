#!/bin/sh

DoDrawcombindfitvn=1

DODrawmorephibinvn=1

DOVncomparison=1

ptbinstart=2
ptbinend=11 #not included
ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
Fitoption_SP="poly3bkg_floatwidth"

Fitoption_DeltaPhibin="poly3bkg"

Doefficiencycorrection=0 #only if poly3bkg_floatwidth

InputMB0to10_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB10to30_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB30to50_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB50to70_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to10_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent50to70_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
#################### more phi bin method

FileVnMB0to10_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to10_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_morephibin="rootfiles/vn_morephibin_MBtrig_cent10to30_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_morephibin="rootfiles/vn_morephibin_MBtrig_cent30to50_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_morephibin="rootfiles/vn_morephibin_MBtrig_cent50to70_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"

FinalFileVnMB0to10_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent0to10_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB10to30_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent10to30_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB30to50_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent30to50_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB50to70_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent50to70_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
#####################################
EPorSP="SP"

if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB0to10_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB10to30_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB30to50_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB50to70_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
fi

###################################
######## deltaphibins method

if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB0to10_morephibin'","'$MBorDtrig'",0,10,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB10to30_morephibin'","'$MBorDtrig'",10,30,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB30to50_morephibin'","'$MBorDtrig'",30,50,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'")'
#root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB50to70_morephibin'","'$MBorDtrig'",50,70,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'")'
fi

###############################
########## comparison
Drawchargedparticle=0
if [ $DOVncomparison -eq 1 ] && [ $Doefficiencycorrection -eq 0 ]; then
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB0to10_morephibin'","'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB10to30_morephibin'","'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB30to50_morephibin'","'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
#root -l -b -q 'Draw_vn_finalcomparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
fi
