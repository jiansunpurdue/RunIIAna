#!/bin/sh

DoDrawcombindfitvn=1

DODrawmorephibinvn=1

DOVncomparison=1

Drawtheory=1

ptbinstart=2
ptbinend=12 #not included
ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
Fitoption_SP="poly3bkg_floatwidth"

Fitoption_DeltaPhibin="poly3bkg"
#Fitoption_DeltaPhibin="poly3bkg_floatwidth"

Doefficiencycorrection=0 #only if poly3bkg_floatwidth

File_promptfraction_cent0to10="promptD0_totaluncertainties/Fractionchange_ratioband_cent0to10.root"
File_promptfraction_cent10to30="promptD0_totaluncertainties/Fractionchange_ratioband_cent10to30.root"
File_promptfraction_cent30to50="promptD0_totaluncertainties/Fractionchange_ratioband_cent30to50.root"

FileVnMB0to10_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent50to70_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"

FinalFileVnMB0to10_SP_combinedfit="rootfiles/vn_finalcombinedfit_vnvsmass_MBtrig_SP_cent0to10_${Fitoption_SP}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB10to30_SP_combinedfit="rootfiles/vn_finalcombinedfit_vnvsmass_MBtrig_SP_cent10to30_${Fitoption_SP}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB30to50_SP_combinedfit="rootfiles/vn_finalcombinedfit_vnvsmass_MBtrig_SP_cent30to50_${Fitoption_SP}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB50to70_SP_combinedfit="rootfiles/vn_finalcombinedfit_vnvsmass_MBtrig_SP_cent50to70_${Fitoption_SP}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
#################### more phi bin method

FileVnMB0to10_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to10_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_morephibin="rootfiles/vn_morephibin_MBtrig_cent10to30_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_morephibin="rootfiles/vn_morephibin_MBtrig_cent30to50_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_morephibin="rootfiles/vn_morephibin_MBtrig_cent50to70_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"

FinalFileVnMB0to10_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent0to10_${Fitoption_DeltaPhibin}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB10to30_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent10to30_${Fitoption_DeltaPhibin}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB30to50_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent30to50_${Fitoption_DeltaPhibin}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
FinalFileVnMB50to70_morephibin="rootfiles/vn_finalmorephibin_MBtrig_cent50to70_${Fitoption_DeltaPhibin}_Bfeeddownsys_Alice0_data1_effcorrected${Doefficiencycorrection}.root"
#####################################
#
#Drawchargedparticle=0
#DrawBfeeddownsys_Alice=0
#DrawBfeeddownsys_data=0
#if [ $DoDrawcombindfitvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
#root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
#root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
#fi
#
#Drawchargedparticle=0
#DrawBfeeddownsys_Alice=1
#DrawBfeeddownsys_data=0
#if [ $DoDrawcombindfitvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
#root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
#root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
#fi
#
Drawchargedparticle=1
DrawBfeeddownsys_Alice=0
DrawBfeeddownsys_data=0
if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
fi

Drawchargedparticle=1
DrawBfeeddownsys_Alice=1
DrawBfeeddownsys_data=0
if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
fi

Drawchargedparticle=1
DrawBfeeddownsys_Alice=0
DrawBfeeddownsys_data=1
if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
root -l -b -q 'Draw_vn_finalcombinedfit.C++("'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data','$Drawtheory')'
fi

###################################
######## deltaphibins method

DrawBfeeddownsys_Alice=0
DrawBfeeddownsys_data=0
if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB0to10_morephibin'","'$MBorDtrig'",0,10,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB10to30_morephibin'","'$MBorDtrig'",10,30,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB30to50_morephibin'","'$MBorDtrig'",30,50,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
fi

DrawBfeeddownsys_Alice=0
DrawBfeeddownsys_data=1
if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB0to10_morephibin'","'$MBorDtrig'",0,10,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'","'$File_promptfraction_cent0to10'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB10to30_morephibin'","'$MBorDtrig'",10,30,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'","'$File_promptfraction_cent10to30'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
root -l -b -q 'Draw_vn_finalmorephibin.C++("'$FileVnMB30to50_morephibin'","'$MBorDtrig'",30,50,'$ptmin','$ptmax',"'$Fitoption_DeltaPhibin'","'$File_promptfraction_cent30to50'",'$DrawBfeeddownsys_Alice','$DrawBfeeddownsys_data')'
fi

###############################
########## comparison
Drawchargedparticle=0
if [ $DOVncomparison -eq 1 ] && [ $Doefficiencycorrection -eq 0 ]; then
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB0to10_morephibin'","'$FinalFileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB10to30_morephibin'","'$FinalFileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB30to50_morephibin'","'$FinalFileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
#root -l -b -q 'Draw_vn_finalcomparison.C++("'$FileVnMB50to70_morephibin'","'$FinalFileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
fi
Drawchargedparticle=1
if [ $DOVncomparison -eq 1 ] && [ $Doefficiencycorrection -eq 0 ]; then
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB0to10_morephibin'","'$FinalFileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB10to30_morephibin'","'$FinalFileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_finalcomparison.C++("'$FinalFileVnMB30to50_morephibin'","'$FinalFileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
#root -l -b -q 'Draw_vn_finalcomparison.C++("'$FileVnMB50to70_morephibin'","'$FinalFileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
fi
