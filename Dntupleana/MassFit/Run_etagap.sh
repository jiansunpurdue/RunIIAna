#!/bin/sh

Cent_lowedges=(0 10 30)
Cent_highedges=(10 30 50)

vnorder=("v2" "v3")

Trig="MBtrig"
Method="SP"

while ((i<3))
do
	Cent_low=${Cent_lowedges[i]}
	Cent_high=${Cent_highedges[i]}

	inputeta2p0="Files_etagapstudy/rootfiles_EPa/vn_combinedfit_vnvsmass_MBtrig_SP_cent${Cent_low}to${Cent_high}_poly3bkg_floatwidth_effcorrected0.root"
	inputeta2p5="Files_etagapstudy/rootfiles_EPb/vn_combinedfit_vnvsmass_MBtrig_SP_cent${Cent_low}to${Cent_high}_poly3bkg_floatwidth_effcorrected0.root"
	inputeta3p0="Files_etagapstudy/rootfiles_EPdefault/vn_combinedfit_vnvsmass_MBtrig_SP_cent${Cent_low}to${Cent_high}_poly3bkg_floatwidth_effcorrected0.root"
	inputeta3p5="Files_etagapstudy/rootfiles_EPd/vn_combinedfit_vnvsmass_MBtrig_SP_cent${Cent_low}to${Cent_high}_poly3bkg_floatwidth_effcorrected0.root"
	inputeta4p0="Files_etagapstudy/rootfiles_EPe/vn_combinedfit_vnvsmass_MBtrig_SP_cent${Cent_low}to${Cent_high}_poly3bkg_floatwidth_effcorrected0.root"
	inputeta4p5="Files_etagapstudy/rootfiles_EPf/vn_combinedfit_vnvsmass_MBtrig_SP_cent${Cent_low}to${Cent_high}_poly3bkg_floatwidth_effcorrected0.root"
	
	for vn in ${vnorder[@]}
	do
		Histotoget="h_v2_pt"
		if [ $vn = "v3" ]; then
			Histotoget="h_v3_pt"
		fi

		root -l -b -q 'Draw_vn_etagap.C++("'$Trig'","'$Method'","'$vn'","'$Histotoget'",'$Cent_low','$Cent_high',"'$inputeta2p0'","'$inputeta2p5'","'$inputeta3p0'","'$inputeta3p5'","'$inputeta4p0'","'$inputeta4p5'")'
	done

	i=$(($i+1))
done

./cleanup.sh
