#!/bin/sh

ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"

#for algo in 1 2 3 4
for algo in 1 2 3
do

if [ "$algo" -eq 1 ]
then
	cent_low=0
	cent_high=10
fi

if [ "$algo" -eq 2 ]
then
	cent_low=10
	cent_high=30
fi

if [ "$algo" -eq 3 ]
then
	cent_low=30
	cent_high=50
fi

if [ "$algo" -eq 4 ]
then
	cent_low=50
	cent_high=70
fi

InputDefault="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth_effcorrected0.root"
Inputefficiencycorrected="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth_effcorrected1.root"
InputDefault_bkgvnpoly2="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth_poly2bkg_effcorrected0.root"

InputDefault_deltaphibins="rootfiles_total/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_poly3bkg_effcorrected0.root"
Inputefficiencycorrected_deltaphibins="rootfiles_total/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_poly3bkg_effcorrected1.root"

method="SP"
root -l -b -q 'Draw_vn_effcorrection.C++("'$InputDefault'","'$Inputefficiencycorrected'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'
root -l -b -q 'Draw_vn_bkgvnPDF.C++("'$InputDefault'","'$InputDefault_bkgvnpoly2'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

method="deltaphibins"
root -l -b -q 'Draw_vn_effcorrection.C++("'$InputDefault_deltaphibins'","'$Inputefficiencycorrected_deltaphibins'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

done
