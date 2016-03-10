#!/bin/sh
echo `hostname`
export SCRAM_ARCH=slc6_amd64_gcc491
source /apps/osg/cmssoft/cmsset_default.sh
export X509_USER_PROXY=/home/sun229/.myproxy
DIR="Dntupleskim"
cd /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch2/src 
eval `scramv1 runtime -sh`
cd $DIR

inputfile=$1
PbPbPD=$2
startevt=$3
endevt=$4
outputdir=$5

#g++ skimDntuple.C -Wno-write-strings $(root-config --cflags --libs) -Wall -O2 -o skimDntuple.exe

./skimDntuple.exe $inputfile $PbPbPD $startevt $endevt $outputdir
