#!/bin/sh

DoMassFitEPformassvsvn=1
DoMassFitSPformassvsvn=1
DoMassFitEPforinoutplane=1
DODrawinoutplanevn=1
DODrawEPmassvsvn=1
DODrawSPmassvsvn=1
DOVncomparison=1

InputMC="./../rootfiles/anaDntuple_ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight_Cent-0to100_Evt0to-1.root"

InputMBdata0to100="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to100.root"
InputMBdata0to10="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to10.root"
InputMBdata10to30="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent10to30.root"
InputMBdata30to50="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root"
InputMBdata50to70="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent50to70.root"

InputMB0to100_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to100.root"
InputMB0to10_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to10.root"
InputMB10to30_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent10to30.root"
InputMB30to50_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root"
InputMB50to70_drawvn_inoutplane="rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent50to70.root"

InputMB0to100_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to100.root"
InputMB0to10_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to10.root"
InputMB10to30_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent10to30.root"
InputMB30to50_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root"
InputMB50to70_drawvn_vnvsmass_EP="rootfiles/Raw_spectrum_vnvsmass_EP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent50to70.root"

InputMB0to100_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to100.root"
InputMB0to10_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent-0to10.root"
InputMB10to30_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent10to30.root"
InputMB30to50_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root"
InputMB50to70_drawvn_vnvsmass_SP="rootfiles/Raw_spectrum_vnvsmass_SP_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent50to70.root"

FileVnMB0to100_Inoutplane="rootfiles/vn_inoutplane_MBtrig_cent0to100.root"
FileVnMB0to10_Inoutplane="rootfiles/vn_inoutplane_MBtrig_cent0to10.root"
FileVnMB10to30_Inoutplane="rootfiles/vn_inoutplane_MBtrig_cent10to30.root"
FileVnMB30to50_Inoutplane="rootfiles/vn_inoutplane_MBtrig_cent30to50.root"
FileVnMB50to70_Inoutplane="rootfiles/vn_inoutplane_MBtrig_cent50to70.root"

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

root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to100'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,0,100)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,0,10)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,10,30)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,30,50)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,50,70)'
fi

EPorSP="SP"
if [ $DoMassFitSPformassvsvn -eq 1 ]; then

#root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to100'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,0,100)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata0to10'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,0,10)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata10to30'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,10,30)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata30to50'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,30,50)'
root -l -b -q 'MassFit_vnFitvsmass.C++("'$InputMBdata50to70'","'$InputMC'","MBtrig","'$EPorSP'",2,14,true,50,70)'
fi

if [ $DoMassFitEPforinoutplane -eq 1 ]; then
#
##root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata0to100'","'$InputMC'","MBtrig",2,14,true,0,100)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata0to10'","'$InputMC'","MBtrig",2,14,true,0,10)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata10to30'","'$InputMC'","MBtrig",2,14,true,10,30)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata30to50'","'$InputMC'","MBtrig",2,14,true,30,50)'
root -l -b -q 'MassFit_inoutplane.C++("'$InputMBdata50to70'","'$InputMC'","MBtrig",2,14,true,50,70)'
fi

if [ $DoMassFitEPformassvsvn -eq 1 ] || [ $DoMassFitSPformassvsvn -eq 1 ] || [ $DoMassFitEPforinoutplane -eq 1 ]; then
	mv Massfitplots/PbPb/*.pdf Plots_vn/Massfitforvn
fi

if [ $DODrawinoutplanevn -eq 1 ]; then
#root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB0to100_drawvn_inoutplane'","MBtrig",0,100,1.5,35.0)'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB0to10_drawvn_inoutplane'","MBtrig",0,10,1.5,35.0)'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB10to30_drawvn_inoutplane'","MBtrig",10,30,1.5,35.0)'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB30to50_drawvn_inoutplane'","MBtrig",30,50,1.5,35.0)'
root -l -b -q 'Draw_vn_inoutplane.C++("'$InputMB50to70_drawvn_inoutplane'","MBtrig",50,70,1.5,35.0)'
fi

EPorSP="EP"
if [ $DODrawEPmassvsvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to100_drawvn_vnvsmass_EP'","MBtrig",0,100,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to10_drawvn_vnvsmass_EP'","MBtrig","'$EPorSP'",0,10,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB10to30_drawvn_vnvsmass_EP'","MBtrig","'$EPorSP'",10,30,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB30to50_drawvn_vnvsmass_EP'","MBtrig","'$EPorSP'",30,50,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB50to70_drawvn_vnvsmass_EP'","MBtrig","'$EPorSP'",50,70,1.5,35.0)'
fi

EPorSP="SP"
if [ $DODrawSPmassvsvn -eq 1 ]; then
#root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to100_drawvn_vnvsmass_SP'","MBtrig",0,100,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB0to10_drawvn_vnvsmass_SP'","MBtrig","'$EPorSP'",0,10,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB10to30_drawvn_vnvsmass_SP'","MBtrig","'$EPorSP'",10,30,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB30to50_drawvn_vnvsmass_SP'","MBtrig","'$EPorSP'",30,50,1.5,35.0)'
root -l -b -q 'Draw_vn_vnvsmass.C++("'$InputMB50to70_drawvn_vnvsmass_SP'","MBtrig","'$EPorSP'",50,70,1.5,35.0)'
fi

if [ $DOVncomparison -eq 1 ]; then
#root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to100_Inoutplane'","'$FileVnMB0to100_EP_Vnvsmass'","'$FileVnMB0to100_SP_Vnvsmass'","MBtrig",0,100,1.5,35.0)'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB0to10_Inoutplane'","'$FileVnMB0to10_EP_Vnvsmass'","'$FileVnMB0to10_SP_Vnvsmass'","MBtrig",0,10,1.5,35.0)'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB10to30_Inoutplane'","'$FileVnMB10to30_EP_Vnvsmass'","'$FileVnMB10to30_SP_Vnvsmass'","MBtrig",10,30,1.5,35.0)'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB30to50_Inoutplane'","'$FileVnMB30to50_EP_Vnvsmass'","'$FileVnMB30to50_SP_Vnvsmass'","MBtrig",30,50,1.5,35.0)'
root -l -b -q 'Draw_vn_comparison.C++("'$FileVnMB50to70_Inoutplane'","'$FileVnMB50to70_EP_Vnvsmass'","'$FileVnMB50to70_SP_Vnvsmass'","MBtrig",50,70,1.5,35.0)'
fi

./cleanup.sh
