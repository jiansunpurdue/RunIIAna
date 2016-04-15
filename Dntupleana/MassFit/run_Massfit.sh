#!/bin/sh
#echo `hostname`

inputdatafile=$1
inputmcfile=$2
MBorDtrig=$3
iptstart=$4
iptend=$5
isPbPb=$6
centlow=$7
centhigh=$8

root -l -b -q 'MassFit.C++("'$inputdatafile'", "'$inputmcfile'", "'$MBorDtrig'", '$iptstart', '$iptend', '$isPbPb', '$centlow', '$centhigh')'

./cleanup.sh
