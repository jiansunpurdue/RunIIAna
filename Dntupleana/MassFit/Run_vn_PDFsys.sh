#!/bin/sh

ptmin=0.0
ptmax=40.0
MBorDtrig="MBtrig"

for algo in 1 2 3 4
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

InputDefault="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth.root"
InputPoly2bkg="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly2bkg_floatwidth.root"
InputExpobkg="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_expobkg_2nd_floatwidth.root"

InputDefault_deltaphibins="rootfiles/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_poly3bkg_floatwidth.root"
InputPoly2bkg_deltaphibins="rootfiles/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_poly2bkg_floatwidth.root"
InputExpobkg_deltaphibins="rootfiles/vn_morephibin_MBtrig_cent${cent_low}to${cent_high}_expobkg_2nd_floatwidth.root"

method="SP"
root -l -b -q 'Draw_vn_differentbkgPDF.C++("'$InputDefault'","'$InputPoly2bkg'","'$InputExpobkg'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

method="deltaphibins"
root -l -b -q 'Draw_vn_differentbkgPDF.C++("'$InputDefault_deltaphibins'","'$InputPoly2bkg_deltaphibins'","'$InputExpobkg_deltaphibins'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

done

#InputFloatwidth="rootfiles/vn_combinedfit_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth.root"
#root -l -b -q 'Draw_vn_floatwidth.C++("'$InputDefault'","'$InputFloatwidth'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

./cleanup.sh
