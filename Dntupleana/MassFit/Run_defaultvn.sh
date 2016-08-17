#!/bin/sh

DoCombinemassvnfit=0
DoDrawcombindfitvn=1
DoCompare2stepfit_combinefit_vn=0

DoMassFitMorephibin=0
DODrawmorephibinvn=1

DOVncomparison=1

ptbinstart=2
ptbinend=12 #not included
ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
Fitoption_SP="poly3bkg_floatwidth"
#Fitoption_SP="expobkg_2nd_floatwidth"
#Fitoption_SP="poly2bkg_floatwidth"
#Fitoption_SP="poly3bkg_floatwidth_poly2bkg"

Fitoption_DeltaPhibin="poly3bkg"
#Fitoption_DeltaPhibin="expobkg_2nd"
#Fitoption_DeltaPhibin="poly2bkg"
#Fitoption_DeltaPhibin="poly3bkg_floatwidth"

Doefficiencycorrection=0 #only if poly3bkg_floatwidth

InputMC="./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent-0to100_Evt0to-1.root"

InputMBdata0to100="./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100.root"
InputMBdata0to10="./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to10.root"
InputMBdata10to30="./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent10to30.root"
InputMBdata30to50="./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent30to50.root"
InputMBdata50to70="./../rootfiles_v2v3etaEP_default_DCAcut0p008/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent50to70.root"

InputMB0to100_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB0to10_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to10_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB10to30_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent10to30_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB30to50_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent30to50_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB50to70_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent50to70_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to10_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent50to70_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to100_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to100_${Fitoption_SP}.root"
FileVnMB0to10_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to10_${Fitoption_SP}.root"
FileVnMB10to30_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent10to30_${Fitoption_SP}.root"
FileVnMB30to50_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50_${Fitoption_SP}.root"
FileVnMB50to70_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent50to70_${Fitoption_SP}.root"

DoEPCombinemassvnfit=0
DoEPDrawcombindfitvn=0
Fitoption_EP="poly3bkg_floatwidth"

DOVnvsmasscomparison=0

InputMB0to100_drawvn_combinemassvnfit_EP="rootfiles/Raw_spectrum_combinemassvnfit_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
InputMB0to10_drawvn_combinemassvnfit_EP="rootfiles/Raw_spectrum_combinemassvnfit_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to10_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
InputMB10to30_drawvn_combinemassvnfit_EP="rootfiles/Raw_spectrum_combinemassvnfit_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent10to30_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
InputMB30to50_drawvn_combinemassvnfit_EP="rootfiles/Raw_spectrum_combinemassvnfit_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent30to50_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
InputMB50to70_drawvn_combinemassvnfit_EP="rootfiles/Raw_spectrum_combinemassvnfit_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent50to70_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to10_EP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_EP_cent0to10_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_EP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_EP_cent10to30_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_EP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_EP_cent30to50_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_EP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_EP_cent50to70_${Fitoption_EP}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to100_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent0to100_${Fitoption_EP}.root"
FileVnMB0to10_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent0to10_${Fitoption_EP}.root"
FileVnMB10to30_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent10to30_${Fitoption_EP}.root"
FileVnMB30to50_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent30to50_${Fitoption_EP}.root"
FileVnMB50to70_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent50to70_${Fitoption_EP}.root"
#################### more phi bin method

InputMB0to100_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to100_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB0to10_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent-0to10_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB10to30_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent10to30_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB30to50_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent30to50_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB50to70_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_Cent50to70_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to100_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to100_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB0to10_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to10_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB10to30_morephibin="rootfiles/vn_morephibin_MBtrig_cent10to30_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB30to50_morephibin="rootfiles/vn_morephibin_MBtrig_cent30to50_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB50to70_morephibin="rootfiles/vn_morephibin_MBtrig_cent50to70_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
#####################################
EPorSP="SP"

if [ $DoCombinemassvnfit -eq 1 ]; then

root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption_SP'",'$Doefficiencycorrection')'
#root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption_SP'",'$Doefficiencycorrection')'
fi

if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB0to10_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB10to30_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB30to50_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
#root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB50to70_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
fi

if [ $DoCompare2stepfit_combinefit_vn -eq 1 ]; then
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB0to10_SP_Vnvsmass'","'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB10to30_SP_Vnvsmass'","'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB30to50_SP_Vnvsmass'","'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax')'
#root -l -b -q 'Draw_vn_2stepfit_combinefit.C++("'$FileVnMB50to70_SP_Vnvsmass'","'$FileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax')'
fi

EPorSP="EP"

if [ $DoEPCombinemassvnfit -eq 1 ]; then

root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption_EP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption_EP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption_EP'",'$Doefficiencycorrection')'
#root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption_EP'",'$Doefficiencycorrection')'
fi

if [ $DoEPDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB0to10_drawvn_combinemassvnfit_EP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax',"'$Fitoption_EP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB10to30_drawvn_combinemassvnfit_EP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax',"'$Fitoption_EP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB30to50_drawvn_combinemassvnfit_EP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax',"'$Fitoption_EP'",'$Doefficiencycorrection')'
#root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB50to70_drawvn_combinemassvnfit_EP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax',"'$Fitoption_EP'",'$Doefficiencycorrection')'
fi

if [ $DOVnvsmasscomparison -eq 1 ]; then
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB0to10_drawvn_combinemassvnfit_EP'","'$InputMB0to10_drawvn_combinemassvnfit_SP'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend',"'$Fitoption_SP'")'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB10to30_drawvn_combinemassvnfit_EP'","'$InputMB10to30_drawvn_combinemassvnfit_SP'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend',"'$Fitoption_SP'")'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB30to50_drawvn_combinemassvnfit_EP'","'$InputMB30to50_drawvn_combinemassvnfit_SP'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend',"'$Fitoption_SP'")'
#root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB50to70_drawvn_combinemassvnfit_EP'","'$InputMB50to70_drawvn_combinemassvnfit_SP'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend',"'$Fitoption'")'
fi

###################################
######## deltaphibins method

if [ $DoMassFitMorephibin -eq 1 ]; then
#
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
#root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
mv Massfitplots/PbPb/*.pdf Plots_vn/Massfitforvn
fi

if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB0to10_drawvn_morephibin'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB10to30_drawvn_morephibin'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB30to50_drawvn_morephibin'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
#root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB50to70_drawvn_morephibin'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
fi

###############################
########## comparison
Drawchargedparticle=0
if [ $DOVncomparison -eq 1 ] && [ $Doefficiencycorrection -eq 0 ]; then
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_SP_combinedfit'","'$MBorDtrig'",0,10,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_SP_combinedfit'","'$MBorDtrig'",10,30,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_SP_combinedfit'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
#root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_SP_combinedfit'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
fi
