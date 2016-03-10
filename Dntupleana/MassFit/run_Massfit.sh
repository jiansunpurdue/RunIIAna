#!/bin/sh
#echo `hostname`
#export SCRAM_ARCH=slc6_amd64_gcc491
#source /apps/osg/cmssoft/cmsset_default.sh
#export X509_USER_PROXY=/home/sun229/.myproxy
#DIR="Dntupleana/MassFit"
#cd /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch2/src 
#eval `scramv1 runtime -sh`
#cd $DIR

inputdatafile=$1
inputmcfile=$2
iptstart=$3
iptend=$4
isPbPb=$5
centlow=$6
centhigh=$7

root -l -b <<EOF
.x MassFit.C+("$inputdatafile", "$inputmcfile", $iptstart, $iptend, $isPbPb, $centlow, $centhigh)
.q
EOF

