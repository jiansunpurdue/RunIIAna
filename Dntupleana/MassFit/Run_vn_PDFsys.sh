#!/bin/sh

cent_low=50
cent_high=70

ptmin=0.0
ptmax=45.0
MBorDtrig="MBtrig"
method="SP"

InputDefault="rootfiles/vn_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg.root"
InputPoly2bkg="rootfiles/vn_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly2bkg.root"
InputExpobkg="rootfiles/vn_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_expobkg_2nd.root"
InputFloatwidth="rootfiles/vn_vnvsmass_MBtrig_SP_cent${cent_low}to${cent_high}_poly3bkg_floatwidth.root"

root -l -b -q 'Draw_vn_differentbkgPDF.C++("'$InputDefault'","'$InputPoly2bkg'","'$InputExpobkg'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

root -l -b -q 'Draw_vn_floatwidth.C++("'$InputDefault'","'$InputFloatwidth'","'$method'","'$MBorDtrig'",'$cent_low','$cent_high','$ptmin','$ptmax')'

./cleanup.sh
