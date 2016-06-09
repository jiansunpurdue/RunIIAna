#!/bin/sh

DoMassFitEPformassvsvn=0
DoMassFitSPformassvsvn=1
DoMassFitMorephibin=1
DoMassFitEPforinoutplane=0
DoStatisticalerr_from_signalfractionfunc_SP=0 #pretty time consuming, ~6 hours for one centrality bin
DoStatisticalerr_from_signalfractionfunc_EP=0 #pretty time consuming, ~6 hours for one centrality bin

Do_combinestaterror_sigfractionfunc_SP_poly3bkg=0 #just for SP and poly3 bkg, if false no error from sigfraction func

DODrawEPmassvsvn=0
DODrawSPmassvsvn=1
DODrawmorephibinvn=1
DODrawinoutplanevn=0
DOVnvsmasscomparison=0

DOVncomparison=0

ptbinstart=2
ptbinend=11 #not included
ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
#Fitoption="poly3bkg_floatwidth"
#Fitoption="expobkg_2nd_floatwidth"
Fitoption="poly2bkg_floatwidth"

InputMC="./../rootfiles/anaDntuple_ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight_Cent-0to100_Evt0to-1.root"

InputMBdata0to100="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMBdata0to10="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMBdata10to30="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMBdata30to50="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMBdata50to70="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

InputMB0to100_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_${Fitoption}.root"
InputMB0to10_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}.root"
InputMB10to30_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}.root"
InputMB30to50_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}.root"
InputMB50to70_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}.root"

InputMB0to100_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_${Fitoption}.root"
InputMB0to10_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}.root"
InputMB10to30_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}.root"
InputMB30to50_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}.root"
InputMB50to70_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}.root"

InputMB0to100_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_${Fitoption}.root"
InputMB0to10_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}.root"
InputMB10to30_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}.root"
InputMB30to50_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}.root"
InputMB50to70_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}.root"

InputMB0to100_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100_${Fitoption}.root"
InputMB0to10_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}.root"
InputMB10to30_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}.root"
InputMB30to50_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}.root"
InputMB50to70_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}.root"

#just files for poly3 bkg and SP
InputMB0to10_drawvn_vnvsmass_SP_randommass="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10_${Fitoption}_staterrsigfrfunc.root"
InputMB10to30_drawvn_vnvsmass_SP_randommass="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30_${Fitoption}_staterrsigfrfunc.root"
InputMB30to50_drawvn_vnvsmass_SP_randommass="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50_${Fitoption}_staterrsigfrfunc.root"
InputMB50to70_drawvn_vnvsmass_SP_randommass="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70_${Fitoption}_staterrsigfrfunc.root"


FileVnMB0to100_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent0to100_${Fitoption}.root"
FileVnMB0to10_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent0to10_${Fitoption}.root"
FileVnMB10to30_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent10to30_${Fitoption}.root"
FileVnMB30to50_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent30to50_${Fitoption}.root"
FileVnMB50to70_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent50to70_${Fitoption}.root"

FileVnMB0to100_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to100_${Fitoption}.root"
FileVnMB0to10_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to10_${Fitoption}.root"
FileVnMB10to30_morephibin="rootfiles/vn_morephibin_MBtrig_cent10to30_${Fitoption}.root"
FileVnMB30to50_morephibin="rootfiles/vn_morephibin_MBtrig_cent30to50_${Fitoption}.root"
FileVnMB50to70_morephibin="rootfiles/vn_morephibin_MBtrig_cent50to70_${Fitoption}.root"

FileVnMB0to100_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent0to100_${Fitoption}.root"
FileVnMB0to10_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent0to10_${Fitoption}.root"
FileVnMB10to30_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent10to30_${Fitoption}.root"
FileVnMB30to50_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent30to50_${Fitoption}.root"
FileVnMB50to70_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent50to70_${Fitoption}.root"

FileVnMB0to100_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to100_${Fitoption}.root"
FileVnMB0to10_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to10_${Fitoption}.root"
FileVnMB10to30_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent10to30_${Fitoption}.root"
FileVnMB30to50_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50_${Fitoption}.root"
FileVnMB50to70_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent50to70_${Fitoption}.root"


EPorSP="EP"
if [ $DoMassFitEPformassvsvn -eq 1 ]; then

#root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to100'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,100,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'")'
fi

EPorSP="SP"
if [ $DoMassFitSPformassvsvn -eq 1 ]; then

root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'")'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'")'
fi

echo "#############################################"
date
echo "statistics error from signal fraction start"

EPorSP="EP"
if [ $DoStatisticalerr_from_signalfractionfunc_EP -eq 1 ]; then

root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'",1)'
date
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'",1)'
date
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'",1)'
date
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'",1)'
date
fi

EPorSP="SP"
if [ $DoStatisticalerr_from_signalfractionfunc_SP -eq 1 ]; then

root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'",1)'
date
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'",1)'
date
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'",1)'
date
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'",1)'
date
fi

echo "statistics error from signal fraction end"
date
echo "*****************************************"

if [ $DoMassFitMorephibin -eq 1 ]; then
#
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'")'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'")'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'")'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'")'
fi

if [ $DoMassFitEPforinoutplane -eq 1 ]; then
#
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,10,"'$Fitoption'")'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,10,30,"'$Fitoption'")'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,30,50,"'$Fitoption'")'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,50,70,"'$Fitoption'")'
fi

if [ $DoMassFitEPformassvsvn -eq 1 ] || [ $DoMassFitSPformassvsvn -eq 1 ] || [ $DoMassFitEPforinoutplane -eq 1 ]; then
	mv Massfitplots/PbPb/*.pdf Plots_vn/Massfitforvn
fi

if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB0to10_drawvn_morephibin'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend',"'$Fitoption'")'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB10to30_drawvn_morephibin'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend',"'$Fitoption'")'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB30to50_drawvn_morephibin'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend',"'$Fitoption'")'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB50to70_drawvn_morephibin'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend',"'$Fitoption'")'
fi

if [ $DODrawinoutplanevn -eq 1 ]; then
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB0to10_drawvn_inoutplane'","'$MBorDtrig'",0,10,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB10to30_drawvn_inoutplane'","'$MBorDtrig'",10,30,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB30to50_drawvn_inoutplane'","'$MBorDtrig'",30,50,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB50to70_drawvn_inoutplane'","'$MBorDtrig'",50,70,'$ptmin','$ptmax',"'$Fitoption'")'
mv Massfitplots/PbPb/*.pdf Plots_vn/fitmorephibin
fi

EPorSP="EP"
if [ $DODrawEPmassvsvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to100_drawvn_vnvsmass_EP'","'$MBorDtrig'",0,100,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to10_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB10to30_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB30to50_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax',"'$Fitoption'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB50to70_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax',"'$Fitoption'")'
fi

EPorSP="SP"
if [ $DODrawSPmassvsvn -eq 1 ]; then
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to10_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax',"'$Fitoption'",'$Do_combinestaterror_sigfractionfunc_SP_poly3bkg',"'$InputMB0to10_drawvn_vnvsmass_SP_randommass'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB10to30_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax',"'$Fitoption'",'$Do_combinestaterror_sigfractionfunc_SP_poly3bkg',"'$InputMB10to30_drawvn_vnvsmass_SP_randommass'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB30to50_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax',"'$Fitoption'",'$Do_combinestaterror_sigfractionfunc_SP_poly3bkg',"'$InputMB30to50_drawvn_vnvsmass_SP_randommass'")'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB50to70_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax',"'$Fitoption'",'$Do_combinestaterror_sigfractionfunc_SP_poly3bkg',"'$InputMB50to70_drawvn_vnvsmass_SP_randommass'")'
fi

if [ $DOVnvsmasscomparison -eq 1 ]; then
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB0to10_drawvn_vnvsmass_EP'","'$InputMB0to10_drawvn_vnvsmass_SP'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend',"'$Fitoption'")'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB10to30_drawvn_vnvsmass_EP'","'$InputMB10to30_drawvn_vnvsmass_SP'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend',"'$Fitoption'")'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB30to50_drawvn_vnvsmass_EP'","'$InputMB30to50_drawvn_vnvsmass_SP'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend',"'$Fitoption'")'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB50to70_drawvn_vnvsmass_EP'","'$InputMB50to70_drawvn_vnvsmass_SP'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend',"'$Fitoption'")'
fi


Drawchargedparticle=0
DrawvnvsmassSP=1
DrawvnvsmassEP=0
Drawinoutplane=0
if [ $DOVncomparison -eq 1 ]; then
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","'$MBorDtrig'",0,10,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","'$MBorDtrig'",10,30,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
fi

Drawchargedparticle=1
DrawvnvsmassSP=1
DrawvnvsmassEP=0
Drawinoutplane=0
if [ $DOVncomparison -eq 1 ]; then
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","'$MBorDtrig'",0,10,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","'$MBorDtrig'",10,30,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
fi

Drawchargedparticle=0
DrawvnvsmassSP=0
DrawvnvsmassEP=0
Drawinoutplane=1
if [ $DOVncomparison -eq 1 ]; then
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","'$MBorDtrig'",0,10,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","'$MBorDtrig'",10,30,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$DrawvnvsmassSP', '$DrawvnvsmassEP', '$Drawinoutplane', '$Drawchargedparticle',"'$Fitoption'")'
fi

./cleanup.sh
