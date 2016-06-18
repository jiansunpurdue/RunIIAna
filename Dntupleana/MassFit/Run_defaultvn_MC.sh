#!/bin/sh

isMC=1

DoCombinemassvnfit=1
DoDrawcombindfitvn=1

DoMassFitMorephibin=1
DODrawmorephibinvn=1
DOVncomparison=1

ptbinstart=5
ptbinend=11 #not included
ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
Fitoption_SP="poly3bkg_floatwidth_poly2bkg"
#Fitoption_SP="expobkg_2nd_floatwidth"
#Fitoption_SP="poly2bkg_floatwidth"

Fitoption_DeltaPhibin="poly3bkg"
#Fitoption_DeltaPhibin="poly3bkg_floatwidth"
#Fitoption_DeltaPhibin="expobkg_2nd"
#Fitoption_DeltaPhibin="poly2bkg"

Doefficiencycorrection=0 #only if poly3bkg_floatwidth

InputMC="./../rootfiles_MCvn_nopthatweight/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent-0to100_Evt0to-1.root"

InputMBdata0to5="./../rootfiles_MCvn_nopthatweight/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent-0to5.root"
InputMBdata5to20="./../rootfiles_MCvn_nopthatweight/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent5to20.root"
InputMBdata20to40="./../rootfiles_MCvn_nopthatweight/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent20to40.root"
InputMBdata40to60="./../rootfiles_MCvn_nopthatweight/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent40to60.root"
InputMBdata60to80="./../rootfiles_MCvn_nopthatweight/anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent60to80.root"

InputMB0to5_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent-0to5_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB5to20_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent5to20_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB20to40_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent20to40_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB40to60_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent40to60_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
InputMB60to80_drawvn_combinemassvnfit_SP="rootfiles/Raw_spectrum_combinemassvnfit_SP_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent60to80_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to5_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to5_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB5to20_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent5to20_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB20to40_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent20to40_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB40to60_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent40to60_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
FileVnMB60to80_SP_combinedfit="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent60to80_${Fitoption_SP}_effcorrected${Doefficiencycorrection}.root"
#################### more phi bin method

InputMB0to5_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent-0to5_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB5to20_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent5to20_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB20to40_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent20to40_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB40to60_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent40to60_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
InputMB60to80_drawvn_morephibin="rootfiles/Raw_spectrum_morephibin_anaDntuple_Dntuple_crab_PbPb_Pythia8_prompt_D0pt0p0_AllPthat_Hydjet_MB_tkpt0p5eta1p5_Dy1p1_06092016_Pthatweight_Cent60to80_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"

FileVnMB0to5_morephibin="rootfiles/vn_morephibin_MBtrig_cent0to5_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB5to20_morephibin="rootfiles/vn_morephibin_MBtrig_cent5to20_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB20to40_morephibin="rootfiles/vn_morephibin_MBtrig_cent20to40_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB40to60_morephibin="rootfiles/vn_morephibin_MBtrig_cent40to60_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
FileVnMB60to80_morephibin="rootfiles/vn_morephibin_MBtrig_cent60to80_${Fitoption_DeltaPhibin}_effcorrected${Doefficiencycorrection}.root"
#####################################
EPorSP="SP"

if [ $DoCombinemassvnfit -eq 1 ]; then

root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata0to5'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,0,5,"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata5to20'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,5,20,"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata20to40'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,20,40,"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata40to60'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,40,60,"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_combmassvnFit.C++("'$InputMBdata60to80'","'$InputMC'","'$MBorDtrig'","'$EPorSP'",'$ptbinstart','$ptbinend',true,60,80,"'$Fitoption_SP'",'$Doefficiencycorrection')'
fi

if [ $DoDrawcombindfitvn -eq 1 ]; then
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB0to5_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",0,5,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB5to20_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",5,20,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB20to40_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",20,40,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB40to60_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",40,60,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
root -l -b -q 'Draw_vn_combinedfit.C++("'$InputMB60to80_drawvn_combinemassvnfit_SP'","'$MBorDtrig'","'$EPorSP'",60,80,'$ptmin','$ptmax',"'$Fitoption_SP'",'$Doefficiencycorrection')'
fi

###################################
######## deltaphibins method

if [ $DoMassFitMorephibin -eq 1 ]; then
#
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata0to5'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,0,5,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata5to20'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,5,20,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata20to40'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,20,40,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata40to60'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,40,60,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
root -l -b -q 'MassFit_morephibin.C++("'$InputMBdata60to80'","'$InputMC'","'$MBorDtrig'",'$ptbinstart','$ptbinend',true,60,80,"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection')'
mv Massfitplots/PbPb/*.pdf Plots_vn/Massfitforvn
fi

if [ $DODrawmorephibinvn -eq 1 ]; then
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB0to5_drawvn_morephibin'","'$MBorDtrig'",0,5,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection','$isMC')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB5to20_drawvn_morephibin'","'$MBorDtrig'",5,20,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection','$isMC')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB20to40_drawvn_morephibin'","'$MBorDtrig'",20,40,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection','$isMC')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB40to60_drawvn_morephibin'","'$MBorDtrig'",40,60,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection','$isMC')'
root -l -b -q 'Draw_vn_morephibin.C++("'$InputMB60to80_drawvn_morephibin'","'$MBorDtrig'",60,80,'$ptbinstart','$ptbinend',"'$Fitoption_DeltaPhibin'",'$Doefficiencycorrection','$isMC')'
fi

###############################
########## comparison
Drawchargedparticle=0
if [ $DOVncomparison -eq 1 ] && [ $Doefficiencycorrection -eq 0 ]; then
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB0to5_morephibin'","'$FileVnMB0to5_SP_combinedfit'","'$MBorDtrig'",0,5,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB5to20_morephibin'","'$FileVnMB5to20_SP_combinedfit'","'$MBorDtrig'",5,20,'$ptmin','$ptmax','$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB20to40_morephibin'","'$FileVnMB20to40_SP_combinedfit'","'$MBorDtrig'",20,40,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB40to60_morephibin'","'$FileVnMB40to60_SP_combinedfit'","'$MBorDtrig'",40,60,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
root -l -b -q 'Draw_vn_comparison_default.C++("'$FileVnMB60to80_morephibin'","'$FileVnMB60to80_SP_combinedfit'","'$MBorDtrig'",60,80,'$ptmin','$ptmax', '$Drawchargedparticle',"'$Fitoption_SP'_'$Fitoption_DeltaPhibin'")'
fi
