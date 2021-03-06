#!/bin/sh

if [ "$#" -eq 10 ]
then
	INFILE=$1
	isPbPb=$2
	isMC=$3
	EvtPerJob=$4
	Njobs=$5
	hibin_low=$6
	hibin_high=$7
	PbPbMBPD=$8
	EPlistdefault=$9
	Jobindex=${10}
	echo 'EvtPerJob: ' $EvtPerJob
else
	echo "Wrong number of parameters. 10 expected, passed $#"
	exit
fi

for ((count=1; count <= $Njobs; count++))
do
 echo "Job $count"
 startevt=$(((count-1)*EvtPerJob))
 endevt=$((count*EvtPerJob))
 echo "from $startevt to $endevt"
# make the condor file
cat > condor_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.job <<EOF
#======================================================================
#
# condor_submit condor_job
#
#======================================================================
universe             = vanilla
executable           = run_anaDntuple_partevt.sh
Arguments = $INFILE $isPbPb $isMC $startevt $endevt $hibin_low $hibin_high $PbPbMBPD $EPlistdefault
initialdir           = /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src/RunIIAna/Dntupleana 
should_Transfer_Files = NO
Requirements   = Arch == "X86_64" && TARGET.UidDomain == "rcac.purdue.edu" && TARGET.Machine != "airplay-render1.rcac.purdue.edu" && TARGET.Machine != "airplay-render2.rcac.purdue.edu"
#======================================================================
output               = condor_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.out
error                = condor_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.err
log                  = condor_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.log
#======================================================================
Getenv               = True
#======================================================================

#======================================================================
+CMSJob = True
#+LENGTH="SHORT"

queue
EOF

condor_submit condor_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.job
echo "condor_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.job submitted"

done
