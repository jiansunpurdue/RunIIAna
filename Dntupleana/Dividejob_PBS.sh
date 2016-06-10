#!/bin/sh

if [ "$#" -eq 8 ]
then
	INFILE=$1
	isPbPb=$2
	isMC=$3
	EvtPerJob=$4
	Njobs=$5
	hibin_low=$6
	hibin_high=$7
	PbPbMBPD=$8
	echo 'EvtPerJob: ' $EvtPerJob
else
	echo "Wrong number of parameters. 8 expected, passed $#"
	exit
fi

for ((count=1; count <= $Njobs; count++))
do
 echo "Job $count"
 startevt=$(((count-1)*EvtPerJob))
 endevt=$((count*EvtPerJob))
 echo "from $startevt to $endevt"
# make the PBS file
cat > PBS_${PbPbMBPD}_${startevt}to${endevt}.sh <<EOF
#!/bin/sh

#PBS -l nodes=1,walltime=01:20:00,mem=2400MB
#PBS -N anaDntuple_${PbPbMBPD}_${startevt}to${endevt}
#PBS -o /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src/RunIIAna/Dntupleana/PBS_${PbPbMBPD}_${startevt}to${endevt}.log
#PBS -e /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src/RunIIAna/Dntupleana/PBS_${PbPbMBPD}_${startevt}to${endevt}.err
#PBS -r n
#PBS -V
#PBS -q cms-bradburn 

echo `hostname`
export SCRAM_ARCH=slc6_amd64_gcc491
source /apps/osg/cmssoft/cmsset_default.sh
export X509_USER_PROXY=/home/sun229/.myproxy
cd /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src 
eval `scramv1 runtime -sh`
cd RunIIAna/Dntupleana

root -l -b 'run_anaDntuple_partevt.C+("'$INFILE'", $isPbPb, $isMC, $startevt, $endevt, $hibin_low, $hibin_high, $PbPbMBPD)'

echo Done
EOF

chmod 744 PBS_${PbPbMBPD}_${startevt}to${endevt}.sh

qsub PBS_${PbPbMBPD}_${startevt}to${endevt}.sh
echo "PBS_${PbPbMBPD}_${startevt}to${endevt}.job submitted"

done
