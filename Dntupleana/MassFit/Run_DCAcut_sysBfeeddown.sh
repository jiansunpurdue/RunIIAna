#!/bin/sh

DoComparisonSP_DCAcut=1
DoComparisonphibins_DCAcut=1


Input_SP_noDCAcut_cent0to10="rootfiles_total_noDCAcut_eta1p2/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_poly3bkg_floatwidth_effcorrected0.root"
Input_SP_noDCAcut_cent10to30="rootfiles_total_noDCAcut_eta1p2/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_poly3bkg_floatwidth_effcorrected0.root"
Input_SP_noDCAcut_cent30to50="rootfiles_total_noDCAcut_eta1p2/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root"

Input_SP_DCAcut_cent0to10="rootfiles_total_eta1p2/vn_combinedfit_vnvsmass_MBtrig_SP_cent0to10_poly3bkg_floatwidth_effcorrected0.root"
Input_SP_DCAcut_cent10to30="rootfiles_total_eta1p2/vn_combinedfit_vnvsmass_MBtrig_SP_cent10to30_poly3bkg_floatwidth_effcorrected0.root"
Input_SP_DCAcut_cent30to50="rootfiles_total_eta1p2/vn_combinedfit_vnvsmass_MBtrig_SP_cent30to50_poly3bkg_floatwidth_effcorrected0.root"

Input_fractionchange_ratio_cent0to10="promptD0_totaluncertainties/Fractionchange_ratioband_cent0to10.root"
Input_fractionchange_ratio_cent10to30="promptD0_totaluncertainties/Fractionchange_ratioband_cent10to30.root"
Input_fractionchange_ratio_cent30to50="promptD0_totaluncertainties/Fractionchange_ratioband_cent30to50.root"

ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"

input_v2_1name="h_v2_pt"
input_v3_1name="h_v3_pt"
input_v2_2name="h_v2_pt"
input_v3_2name="h_v3_pt"
cfgname="SPDCAcut"

if [ $DoComparisonSP_DCAcut -eq 1 ]; then
root -l -b -q 'Draw_vn_2comparison_sysBfeeddown.C++("'$Input_SP_noDCAcut_cent0to10'","'$Input_SP_DCAcut_cent0to10'","'$input_v2_1name'","'$input_v3_1name'","'$input_v2_2name'","'$input_v3_2name'","w/o DCA Cut","DCA < 0.008 cm","'$cfgname'","'$MBorDtrig'",0,10,'$ptmin','$ptmax',"'$Input_fractionchange_ratio_cent0to10'")'
root -l -b -q 'Draw_vn_2comparison_sysBfeeddown.C++("'$Input_SP_noDCAcut_cent10to30'","'$Input_SP_DCAcut_cent10to30'","'$input_v2_1name'","'$input_v3_1name'","'$input_v2_2name'","'$input_v3_2name'","w/o DCA Cut","DCA < 0.008 cm","'$cfgname'","'$MBorDtrig'",10,30,'$ptmin','$ptmax',"'$Input_fractionchange_ratio_cent10to30'")'
root -l -b -q 'Draw_vn_2comparison_sysBfeeddown.C++("'$Input_SP_noDCAcut_cent30to50'","'$Input_SP_DCAcut_cent30to50'","'$input_v2_1name'","'$input_v3_1name'","'$input_v2_2name'","'$input_v3_2name'","w/o DCA Cut","DCA < 0.008 cm","'$cfgname'","'$MBorDtrig'",30,50,'$ptmin','$ptmax',"'$Input_fractionchange_ratio_cent30to50'")'
fi

Input_phibins_noDCAcut_cent0to10="rootfiles_total_noDCAcut_eta1p2/vn_morephibin_MBtrig_cent0to10_poly3bkg_effcorrected0.root"
Input_phibins_noDCAcut_cent10to30="rootfiles_total_noDCAcut_eta1p2/vn_morephibin_MBtrig_cent10to30_poly3bkg_effcorrected0.root"
Input_phibins_noDCAcut_cent30to50="rootfiles_total_noDCAcut_eta1p2/vn_morephibin_MBtrig_cent30to50_poly3bkg_effcorrected0.root"

Input_phibins_DCAcut_cent0to10="rootfiles_total_eta1p2/vn_morephibin_MBtrig_cent0to10_poly3bkg_effcorrected0.root"
Input_phibins_DCAcut_cent10to30="rootfiles_total_eta1p2/vn_morephibin_MBtrig_cent10to30_poly3bkg_effcorrected0.root"
Input_phibins_DCAcut_cent30to50="rootfiles_total_eta1p2/vn_morephibin_MBtrig_cent30to50_poly3bkg_effcorrected0.root"

input_v2_1name="v2_morephibin"
input_v3_1name="v3_morephibin"
input_v2_2name="v2_morephibin"
input_v3_2name="v3_morephibin"
cfgname="phibinsDCAcut"

if [ $DoComparisonphibins_DCAcut -eq 1 ]; then
root -l -b -q 'Draw_vn_2comparison_sysBfeeddown.C++("'$Input_phibins_noDCAcut_cent0to10'","'$Input_phibins_DCAcut_cent0to10'","'$input_v2_1name'","'$input_v3_1name'","'$input_v2_2name'","'$input_v3_2name'","w/o DCA Cut","DCA < 0.008 cm","'$cfgname'","'$MBorDtrig'",0,10,'$ptmin','$ptmax',"'$Input_fractionchange_ratio_cent0to10'")'
root -l -b -q 'Draw_vn_2comparison_sysBfeeddown.C++("'$Input_phibins_noDCAcut_cent10to30'","'$Input_phibins_DCAcut_cent10to30'","'$input_v2_1name'","'$input_v3_1name'","'$input_v2_2name'","'$input_v3_2name'","w/o DCA Cut","DCA < 0.008 cm","'$cfgname'","'$MBorDtrig'",10,30,'$ptmin','$ptmax',"'$Input_fractionchange_ratio_cent10to30'")'
root -l -b -q 'Draw_vn_2comparison_sysBfeeddown.C++("'$Input_phibins_noDCAcut_cent30to50'","'$Input_phibins_DCAcut_cent30to50'","'$input_v2_1name'","'$input_v3_1name'","'$input_v2_2name'","'$input_v3_2name'","w/o DCA Cut","DCA < 0.008 cm","'$cfgname'","'$MBorDtrig'",30,50,'$ptmin','$ptmax',"'$Input_fractionchange_ratio_cent30to50'")'
fi
