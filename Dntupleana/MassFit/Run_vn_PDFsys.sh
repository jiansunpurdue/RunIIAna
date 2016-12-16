#!/bin/sh

ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"
Doefficiencycorrection=0

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

InputDefault="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth_effcorrected${Doefficiencycorrection}.root"
InputPoly2bkg="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly2bkg_floatwidth_effcorrected${Doefficiencycorrection}.root"
InputExpobkg="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_expobkg_2nd_floatwidth_effcorrected${Doefficiencycorrection}.root"

InputDefault_deltaphibins="rootfiles_total/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_poly3bkg_effcorrected${Doefficiencycorrection}.root"
InputPoly2bkg_deltaphibins="rootfiles_total/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_poly2bkg_effcorrected${Doefficiencycorrection}.root"
InputExpobkg_deltaphibins="rootfiles_total/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_expobkg_2nd_effcorrected${Doefficiencycorrection}.root"

method="SP"
root -l -b -q 'Draw_vn_differentbkgPDF.C++("'$InputDefault'","'$InputPoly2bkg'","'$InputExpobkg'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

method="deltaphibins"
root -l -b -q 'Draw_vn_differentbkgPDF.C++("'$InputDefault_deltaphibins'","'$InputPoly2bkg_deltaphibins'","'$InputExpobkg_deltaphibins'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

done

#InputFloatwidth="rootfiles_total/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth.root"
#root -l -b -q 'Draw_vn_floatwidth.C++("'$InputDefault'","'$InputFloatwidth'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'
