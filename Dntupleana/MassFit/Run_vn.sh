#!/bin/sh

DoMassFitEPformassvsvn=1
DoMassFitSPformassvsvn=1
DoMassFitEPforinoutplane=1
DoMassFitMorephibin=1

DODrawinoutplanevn=1
DODrawEPmassvsvn=1
DODrawSPmassvsvn=1
DODrawmorephibinvn=1
DOVnvsmasscomparison=1

DOVncomparison=1

ptbinstart=2
ptbinend=12
ptmin=0.0
ptmax=45.0
MBorDtrig="MBtrig"

InputMC="./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root"
#InputMC="./../rootfiles/anaDntuple_ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight_Cent-0to100_Evt0to-1.root"

InputMBdata0to100="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMBdata0to10="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMBdata10to30="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMBdata30to50="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMBdata50to70="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

InputMB0to100_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMB0to10_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMB10to30_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMB30to50_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMB50to70_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

InputMB0to100_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMB0to10_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMB10to30_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMB30to50_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMB50to70_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

InputMB0to100_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMB0to10_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMB10to30_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMB30to50_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMB50to70_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

InputMB0to100_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"
InputMB0to10_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to10.root"
InputMB10to30_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent10to30.root"
InputMB30to50_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root"
InputMB50to70_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent50to70.root"

FileVnMB0to100_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent0to100.root"
FileVnMB0to10_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent0to10.root"
FileVnMB10to30_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent10to30.root"
FileVnMB30to50_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent30to50.root"
FileVnMB50to70_inoutplane="rootfiles/vn_inoutplane_MBtrig_cent50to70.root"

FileVnMB0to100_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to100.root"
FileVnMB0to10_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to10.root"
FileVnMB10to30_morephibin="rootfiles/vn_morephibin_MBtrig_cent10to30.root"
FileVnMB30to50_morephibin="rootfiles/vn_morephibin_MBtrig_cent30to50.root"
FileVnMB50to70_morephibin="rootfiles/vn_morephibin_MBtrig_cent50to70.root"

FileVnMB0to100_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent0to100.root"
FileVnMB0to10_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent0to10.root"
FileVnMB10to30_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent10to30.root"
FileVnMB30to50_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent30to50.root"
FileVnMB50to70_EP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_EP_cent50to70.root"

FileVnMB0to100_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to100.root"
FileVnMB0to10_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent0to10.root"
FileVnMB10to30_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent10to30.root"
FileVnMB30to50_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent30to50.root"
FileVnMB50to70_SP_Vnvsmass="rootfiles/vn_vnvsmass_MBtrig_SP_cent50to70.root"


EPorSP="EP"
if [ $DoMassFitEPformassvsvn -eq 1 ]; then

root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to100'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,100)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70)'
fi

EPorSP="SP"
if [ $DoMassFitSPformassvsvn -eq 1 ]; then

#root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to100'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,100)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,10)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,10,30)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,30,50)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,50,70)'
fi

if [ $DoMassFitMorephibin -eq 1 ]; then
#
##root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata0to100'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,100)'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,10)'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,10,30)'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,30,50)'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,50,70)'
fi

if [ $DoMassFitEPforinoutplane -eq 1 ]; then
#
##root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata0to100'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,100)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata0to10'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,10)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata10to30'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,10,30)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata30to50'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,30,50)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata50to70'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,50,70)'
fi

if [ $DoMassFitEPformassvsvn -eq 1 ] || [ $DoMassFitSPformassvsvn -eq 1 ] || [ $DoMassFitEPforinoutplane -eq 1 ]; then
	mv Massfitplots/PbPb/*.pdf Plots_vn/Massfitforvn
fi

if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB0to10_drawvn_morephibin'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB10to30_drawvn_morephibin'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB30to50_drawvn_morephibin'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB50to70_drawvn_morephibin'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend')'
fi

if [ $DODrawinoutplanevn -eq 1 ]; then
#root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB0to100_drawvn_inoutplane'","'$MBorDtrig'",0,100,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB0to10_drawvn_inoutplane'","'$MBorDtrig'",0,10,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB10to30_drawvn_inoutplane'","'$MBorDtrig'",10,30,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB30to50_drawvn_inoutplane'","'$MBorDtrig'",30,50,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB50to70_drawvn_inoutplane'","'$MBorDtrig'",50,70,'$ptmin','$ptmax')'
mv Massfitplots/PbPb/*.pdf Plots_vn/fitmorephibin
fi

EPorSP="EP"
if [ $DODrawEPmassvsvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to100_drawvn_vnvsmass_EP'","'$MBorDtrig'",0,100,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to10_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB10to30_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB30to50_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB50to70_drawvn_vnvsmass_EP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax')'
fi

EPorSP="SP"
if [ $DODrawSPmassvsvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to100_drawvn_vnvsmass_SP'","'$MBorDtrig'",0,100,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to10_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",0,10,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB10to30_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",10,30,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB30to50_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",30,50,'$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB50to70_drawvn_vnvsmass_SP'","'$MBorDtrig'","'$EPorSP'",50,70,'$ptmin','$ptmax')'
fi

if [ $DOVnvsmasscomparison -eq 1 ]; then
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB0to10_drawvn_vnvsmass_EP'","'$InputMB0to10_drawvn_vnvsmass_SP'","'$MBorDtrig'",0,10,'$ptbinstart','$ptbinend')'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB10to30_drawvn_vnvsmass_EP'","'$InputMB10to30_drawvn_vnvsmass_SP'","'$MBorDtrig'",10,30,'$ptbinstart','$ptbinend')'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB30to50_drawvn_vnvsmass_EP'","'$InputMB30to50_drawvn_vnvsmass_SP'","'$MBorDtrig'",30,50,'$ptbinstart','$ptbinend')'
root -l -b -q 'Draw_vnvsmasscomparison_EPSP.C++("'$InputMB50to70_drawvn_vnvsmass_EP'","'$InputMB50to70_drawvn_vnvsmass_SP'","'$MBorDtrig'",50,70,'$ptbinstart','$ptbinend')'
fi

Drawchargedparticle=0
Drawvnvsmass=1
Drawinoutplane=0
if [ $DOVncomparison -eq 1 ]; then
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","'$MBorDtrig'",0,10,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","'$MBorDtrig'",10,30,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
fi

Drawchargedparticle=1
Drawvnvsmass=1
Drawinoutplane=0
if [ $DOVncomparison -eq 1 ]; then
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","'$MBorDtrig'",0,10,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","'$MBorDtrig'",10,30,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
fi

Drawchargedparticle=0
Drawvnvsmass=0
Drawinoutplane=1
if [ $DOVncomparison -eq 1 ]; then
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_morephibin'","'$FileVnMB0to10_inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","'$MBorDtrig'",0,10,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_morephibin'","'$FileVnMB10to30_inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","'$MBorDtrig'",10,30,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_morephibin'","'$FileVnMB30to50_inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","'$MBorDtrig'",30,50,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_morephibin'","'$FileVnMB50to70_inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","'$MBorDtrig'",50,70,'$ptmin','$ptmax', '$Drawvnvsmass', '$Drawinoutplane', '$Drawchargedparticle')'
fi

./cleanup.sh
