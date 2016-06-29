#!/bin/sh
echo `hostname`
export SCRAM_ARCH=slc6_amd64_gcc491
source /apps/osg/cmssoft/cmsset_default.sh
export X509_USER_PROXY=/home/sun229/.myproxy
DIR="RunIIAna/Dntupleana"
cd /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch3/src 
eval `scramv1 runtime -sh`
cd $DIR

intputfilename=$1
isPbPb=$2
isMC=$3
startevt=$4
endevt=$5
hibin_low=$6
hibin_high=$7
PbPbMBPD=$8
EPlistdefault=$9

root -l -b<<EOF
.x run_anaDntuple_partevt.C+("$intputfilename", $isPbPb, $isMC, $startevt, $endevt, $hibin_low, $hibin_high, $PbPbMBPD, $EPlistdefault)
.q
EOF

