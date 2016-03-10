#!/bin/sh

if [ "$#" -eq 5 ]
then
	INFILE=$1
	PbPbPD=$2
	EvtPerJob=$3
	Njobs=$4
	outputdir=$5
	echo 'EvtPerJob: ' $EvtPerJob
else
	echo "Wrong number of parameters. 5 expected, passed $#"
	exit
fi

if [ ! -d $outputdir ]; then
	mkdir $outputdir
fi

#g++ skimDntuple.C -Wno-write-strings $(root-config --cflags --libs) -Wall -O2 -o skimDntuple.exe

for ((count=1; count <= $Njobs; count++))
do
 echo "Job $count"
 startevt=$(((count-1)*EvtPerJob))
 endevt=$((count*EvtPerJob))
 echo "from $startevt to $endevt"
# make the condor file
cat > condor_${startevt}to${endevt}.job <<EOF
#======================================================================
#
# condor_submit condor_job
#
#======================================================================
universe             = vanilla
executable           = run_skimDntuple.sh 
Arguments = $INFILE $PbPbPD $startevt $endevt $outputdir
initialdir           = /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch2/src/Dntupleskim 
should_Transfer_Files = NO
Requirements   = Arch == "X86_64" && TARGET.UidDomain == "rcac.purdue.edu" && TARGET.Machine != "airplay-render1.rcac.purdue.edu" && TARGET.Machine != "airplay-render2.rcac.purdue.edu"
#======================================================================
output               = condor_${startevt}to${endevt}.out
error                = condor_${startevt}to${endevt}.err
log                  = condor_${startevt}to${endevt}.log
#======================================================================
Getenv               = True
#======================================================================

#======================================================================
+CMSJob = True
#+LENGTH="SHORT"

queue
EOF

condor_submit condor_${startevt}to${endevt}.job
echo "condor_${startevt}to${endevt}.job submitted"

done
