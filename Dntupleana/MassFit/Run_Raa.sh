#!/bin/sh

DoMassFit=1
DoEfficiencyandCorrectedSpectrum=1
DoRaaCrosssection=1

MBorDtrig="MBtrig"
iptstart=1
iptend=11
ptmin=1.0
ptmax=35.0

InputppMBdata="./../rootfiles/anaDntuple_skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016.root"
InputPbPbMBdata="./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"

InputppMC="./../rootfiles/anaDntuple_ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight_Cent-0to100_Evt0to-1.root"
InputPbPbMC="./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root"

ppdataMBRaw="rootfiles/Raw_spectrum_anaDntuple_skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016.root"
PbPbdataMBRaw="rootfiles/Raw_spectrum_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent-0to100.root"

ppdatacorrected="rootfiles/EfficiencyandCorrectedSpectrum_PbPb0_MBtrig_cent0to100.root"
PbPbdatacorrected="rootfiles/EfficiencyandCorrectedSpectrum_PbPb1_MBtrig_cent0to100.root"

if [ $DoMassFit -eq 1 ]; then
	root -l -b -q 'MassFit.C++("'$InputppMBdata'","'$InputppMC'","'$MBorDtrig'",'$iptstart','$iptend',0,0,100)'
	root -l -b -q 'MassFit.C++("'$InputPbPbMBdata'","'$InputPbPbMC'","'$MBorDtrig'",'$iptstart','$iptend',1,0,100)'
	mv Massfitplots/*/*.pdf Plots_RAA/MassFitforRAA/
fi

if [ $DoEfficiencyandCorrectedSpectrum -eq 1 ]; then
	root -l -b -q 'EfficiencyandCorrectedSpectrum.C++("'$InputppMC'","'$ppdataMBRaw'",0,"'$MBorDtrig'",0,100,'$ptmin','$ptmax')'
	root -l -b -q 'EfficiencyandCorrectedSpectrum.C++("'$InputPbPbMC'","'$PbPbdataMBRaw'",1,"'$MBorDtrig'",0,100,'$ptmin','$ptmax')'
fi

if [ $DoRaaCrosssection -eq 1 ]; then
	root -l -b -q 'RaaCalculation.C++("'$ppdatacorrected'", "'$PbPbdatacorrected'", "'$MBorDtrig'", 0, 100, '$ptmin','$ptmax')'
fi

./cleanup.sh
