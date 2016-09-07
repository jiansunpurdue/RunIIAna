#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TMultiGraph.h>

TGraphAsymmErrors * gv2Dmeson5TeV_CUJET3[3];
TGraphAsymmErrors * gv2Dmeson5TeV_TAMU[3];

void Set_TAMU()
{
	TFile * inputTAMU = new TFile("TheoryCalculation/TAMU/PredictionsTAMU_Dv2_pt.root");
	gv2Dmeson5TeV_TAMU[0] = ( TGraphAsymmErrors * ) inputTAMU->Get("gv2Dmeson5TeV_TAMU_cent0to10");
	gv2Dmeson5TeV_TAMU[1] = ( TGraphAsymmErrors * ) inputTAMU->Get("gv2Dmeson5TeV_TAMU_cent10to30");
	gv2Dmeson5TeV_TAMU[2] = ( TGraphAsymmErrors * ) inputTAMU->Get("gv2Dmeson5TeV_TAMU_cent30to50");

	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gv2Dmeson5TeV_TAMU[ibin]->SetFillStyle(1001);
		//gv2Dmeson5TeV_TAMU[ibin]->SetFillStyle(3001);
		gv2Dmeson5TeV_TAMU[ibin]->SetFillColor(46);
		gv2Dmeson5TeV_TAMU[ibin]->SetLineColor(46);
		gv2Dmeson5TeV_TAMU[ibin]->SetLineWidth(2);
	}
}

void Set_CUJET3()
{
	TFile * inputCUJET3 = new TFile("TheoryCalculation/CUJet3p0/PredictionsCUJET3_Dv2_pt.root");
	gv2Dmeson5TeV_CUJET3[0] = ( TGraphAsymmErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET3_cent0to10");
	gv2Dmeson5TeV_CUJET3[1] = ( TGraphAsymmErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET3_cent10to30");
	gv2Dmeson5TeV_CUJET3[2] = ( TGraphAsymmErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET3_cent30to50");

	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gv2Dmeson5TeV_CUJET3[ibin]->SetLineColor(8);
		gv2Dmeson5TeV_CUJET3[ibin]->SetLineWidth(2);
		gv2Dmeson5TeV_CUJET3[ibin]->SetFillStyle(1001);
		gv2Dmeson5TeV_CUJET3[ibin]->SetFillColor(kGreen-10);
	}
}

void Set_theoryD()
{
	Set_CUJET3();
	Set_TAMU();
}
