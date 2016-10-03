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
# make the PBS file
cat > PBS_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.sh <<EOF
#!/bin/sh

#PBS -l nodes=1,walltime=01:30:00,mem=2400MB
#PBS -N anaDntuple_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}
#PBS -o /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src/RunIIAna/Dntupleana/PBS_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.log
#PBS -e /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src/RunIIAna/Dntupleana/PBS_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.err
#PBS -r n
#PBS -V
#PBS -q fqwang 

echo \`hostname\`
export SCRAM_ARCH=slc6_amd64_gcc491
source /apps/osg/cmssoft/cmsset_default.sh
export X509_USER_PROXY=/home/sun229/.myproxy
cd /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src/RunIIAna/Dntupleana 
eval \`scramv1 runtime -sh\`

root -l -b -q 'run_anaDntuple_partevt.C+("'$INFILE'", $isPbPb, $isMC, $startevt, $endevt, $hibin_low, $hibin_high, $PbPbMBPD, $EPlistdefault)'

echo Done
EOF

chmod 744 PBS_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.sh

qsub PBS_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.sh
echo "PBS_${PbPbMBPD}_${startevt}to${endevt}_${Jobindex}.sh submitted"

done
