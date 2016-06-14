#!/bin/sh

inputfile=$1

root -l -b -q 'EP_resolution_3subevent.C++("'$inputfile'")'
root -l -b -q 'SP_resolution_3subevent.C++("'$inputfile'")'
