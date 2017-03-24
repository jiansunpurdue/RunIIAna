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

TGraphAsymmErrors * gv2Dmeson5TeV_TAMU[3];

//old calculations
//TGraphAsymmErrors * gv2Dmeson5TeV_CUJET3[3];
//new CUJET
TGraphErrors * gv2Dmeson5TeV_CUJET3[3];

TGraph * gv2Dmeson5TeV_LBT[3];
TGraph * gv3Dmeson5TeV_LBT[3];

TGraph * gv2Dmeson5TeV_LPang[3];

TGraph * gv2Dmeson5TeV_SUBATECH[3];
TGraph * gv3Dmeson5TeV_SUBATECH[3];

TGraph * gv2Dmeson5TeV_PHSD[3];
TGraph * gv3Dmeson5TeV_PHSD[3];

void Set_PHSD()
{
	TFile * inputTAMU = new TFile("TheoryCalculation/PHSD/PHSD_v2v3_interpolation_from0p5.root");
	gv2Dmeson5TeV_PHSD[0] = (TGraph *) inputTAMU->Get("gv2Dmeson5TeV_PHSD_cent0to10");
	gv2Dmeson5TeV_PHSD[1] = (TGraph *) inputTAMU->Get("gv2Dmeson5TeV_PHSD_cent10to30");
	gv2Dmeson5TeV_PHSD[2] = (TGraph *) inputTAMU->Get("gv2Dmeson5TeV_PHSD_cent30to50");
	gv3Dmeson5TeV_PHSD[0] = (TGraph *) inputTAMU->Get("gv3Dmeson5TeV_PHSD_cent0to10");
	gv3Dmeson5TeV_PHSD[1] = (TGraph *) inputTAMU->Get("gv3Dmeson5TeV_PHSD_cent10to30");
	gv3Dmeson5TeV_PHSD[2] = (TGraph *) inputTAMU->Get("gv3Dmeson5TeV_PHSD_cent30to50");

	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gv2Dmeson5TeV_PHSD[ibin]->SetLineWidth(2);
		gv2Dmeson5TeV_PHSD[ibin]->SetLineColor(kMagenta+1);
		gv2Dmeson5TeV_PHSD[ibin]->SetLineStyle(2);
		
		gv3Dmeson5TeV_PHSD[ibin]->SetLineWidth(2);
		gv3Dmeson5TeV_PHSD[ibin]->SetLineColor(kMagenta+1);
		gv3Dmeson5TeV_PHSD[ibin]->SetLineStyle(2);
	}
}

void Set_SUBATECH()
{
	gv2Dmeson5TeV_SUBATECH[0] = new TGraph("TheoryCalculation/SUBATECH_updated/5TeV0-10v2D_CMS.dat");
	gv2Dmeson5TeV_SUBATECH[1] = new TGraph("TheoryCalculation/SUBATECH_updated/5TeV10-30v2D_CMS.dat");
	gv2Dmeson5TeV_SUBATECH[2] = new TGraph("TheoryCalculation/SUBATECH_updated/5TeV30-50v2D_CMS.dat");
	gv2Dmeson5TeV_SUBATECH[0]->SetName("gv2Dmeson5TeV_SUBATECH_cent0to10");
	gv2Dmeson5TeV_SUBATECH[1]->SetName("gv2Dmeson5TeV_SUBATECH_cent10to30");
	gv2Dmeson5TeV_SUBATECH[2]->SetName("gv2Dmeson5TeV_SUBATECH_cent30to50");

	gv3Dmeson5TeV_SUBATECH[0] = new TGraph("TheoryCalculation/SUBATECH_updated/5TeV0-10v3D_CMS.dat");
	gv3Dmeson5TeV_SUBATECH[1] = new TGraph("TheoryCalculation/SUBATECH_updated/5TeV10-30v3D_CMS.dat");
	gv3Dmeson5TeV_SUBATECH[2] = new TGraph("TheoryCalculation/SUBATECH_updated/5TeV30-50v3D_CMS.dat");
	gv3Dmeson5TeV_SUBATECH[0]->SetName("gv3Dmeson5TeV_SUBATECH_cent0to10");
	gv3Dmeson5TeV_SUBATECH[1]->SetName("gv3Dmeson5TeV_SUBATECH_cent10to30");
	gv3Dmeson5TeV_SUBATECH[2]->SetName("gv3Dmeson5TeV_SUBATECH_cent30to50");

	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gv2Dmeson5TeV_SUBATECH[ibin]->SetLineWidth(2);
		gv2Dmeson5TeV_SUBATECH[ibin]->SetLineColor(67);
		gv2Dmeson5TeV_SUBATECH[ibin]->SetLineStyle(5);
		
		gv3Dmeson5TeV_SUBATECH[ibin]->SetLineWidth(2);
		gv3Dmeson5TeV_SUBATECH[ibin]->SetLineColor(67);
		gv3Dmeson5TeV_SUBATECH[ibin]->SetLineStyle(5);
	}
}

void Set_LPang()
{
	gv2Dmeson5TeV_LPang[0] = new TGraph("TheoryCalculation/Longgang/v2_D0_cent0to10.dat");
	gv2Dmeson5TeV_LPang[1] = new TGraph("TheoryCalculation/Longgang/v2_D0_cent10to30.dat");
	gv2Dmeson5TeV_LPang[2] = new TGraph("TheoryCalculation/Longgang/v2_D0_cent30to50.dat");
	gv2Dmeson5TeV_LPang[0]->SetName("gv2Dmeson5TeV_LPang_cent0to10");
	gv2Dmeson5TeV_LPang[1]->SetName("gv2Dmeson5TeV_LPang_cent10to30");
	gv2Dmeson5TeV_LPang[2]->SetName("gv2Dmeson5TeV_LPang_cent30to50");

	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gv2Dmeson5TeV_LPang[ibin]->SetLineWidth(1);
		//gv2Dmeson5TeV_LPang[ibin]->SetLineColor(kOrange-2);
		gv2Dmeson5TeV_LPang[ibin]->SetLineColor(kMagenta+2);
	}
}

void Set_LBT()
{
	gv2Dmeson5TeV_LBT[0] = new TGraph("TheoryCalculation/LBT/v2_cen-00-10.dat");
	gv2Dmeson5TeV_LBT[1] = new TGraph("TheoryCalculation/LBT/v2_cen-10-30.dat");
	gv2Dmeson5TeV_LBT[2] = new TGraph("TheoryCalculation/LBT/v2_cen-30-50.dat");
	gv2Dmeson5TeV_LBT[0]->SetName("gv2Dmeson5TeV_LBT_cent0to10");
	gv2Dmeson5TeV_LBT[1]->SetName("gv2Dmeson5TeV_LBT_cent10to30");
	gv2Dmeson5TeV_LBT[2]->SetName("gv2Dmeson5TeV_LBT_cent30to50");

	gv3Dmeson5TeV_LBT[0] = new TGraph("TheoryCalculation/LBT/v3_cen-00-10.dat");
	gv3Dmeson5TeV_LBT[1] = new TGraph("TheoryCalculation/LBT/v3_cen-10-30.dat");
	gv3Dmeson5TeV_LBT[2] = new TGraph("TheoryCalculation/LBT/v3_cen-30-50.dat");
	gv3Dmeson5TeV_LBT[0]->SetName("gv3Dmeson5TeV_LBT_cent0to10");
	gv3Dmeson5TeV_LBT[1]->SetName("gv3Dmeson5TeV_LBT_cent10to30");
	gv3Dmeson5TeV_LBT[2]->SetName("gv3Dmeson5TeV_LBT_cent30to50");

	for( int ibin = 0; ibin < 3; ibin++ )
	{
		//gv2Dmeson5TeV_LBT[ibin]->SetLineWidth(1);
		gv2Dmeson5TeV_LBT[ibin]->SetLineWidth(2);
		gv2Dmeson5TeV_LBT[ibin]->SetLineColor(4);
		gv2Dmeson5TeV_LBT[ibin]->SetLineStyle(9);
		
		//gv3Dmeson5TeV_LBT[ibin]->SetLineWidth(1);
		gv3Dmeson5TeV_LBT[ibin]->SetLineWidth(2);
		gv3Dmeson5TeV_LBT[ibin]->SetLineColor(4);
		gv3Dmeson5TeV_LBT[ibin]->SetLineStyle(9);
	}
}

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
		gv2Dmeson5TeV_TAMU[ibin]->SetFillColor(28);
		gv2Dmeson5TeV_TAMU[ibin]->SetLineColor(28);
		gv2Dmeson5TeV_TAMU[ibin]->SetLineWidth(2);
	}
}

//CUJET old
//void Set_CUJET3()
//{
//	TFile * inputCUJET3 = new TFile("TheoryCalculation/CUJet3p0/PredictionsCUJET3_Dv2_pt.root");
//	gv2Dmeson5TeV_CUJET3[0] = ( TGraphAsymmErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET3_cent0to10");
//	gv2Dmeson5TeV_CUJET3[1] = ( TGraphAsymmErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET3_cent10to30");
//	gv2Dmeson5TeV_CUJET3[2] = ( TGraphAsymmErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET3_cent30to50");
//
//	for( int ibin = 0; ibin < 3; ibin++ )
//	{
//		gv2Dmeson5TeV_CUJET3[ibin]->SetLineColor(8);
//		gv2Dmeson5TeV_CUJET3[ibin]->SetLineWidth(1);
//		gv2Dmeson5TeV_CUJET3[ibin]->SetFillStyle(1001);
//		gv2Dmeson5TeV_CUJET3[ibin]->SetFillColor(kGreen-10);
//	}
//}

//updated CUJET
void Set_CUJET3()
{
	TFile * inputCUJET3 = new TFile("TheoryCalculation/CUJET3_updated/CUJET_v2.root");
	
	gv2Dmeson5TeV_CUJET3[0] = ( TGraphErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET_cent0to10");
	gv2Dmeson5TeV_CUJET3[1] = ( TGraphErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET_cent10to30");
	gv2Dmeson5TeV_CUJET3[2] = ( TGraphErrors * ) inputCUJET3->Get("gv2Dmeson5TeV_CUJET_cent30to50");
	
	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gv2Dmeson5TeV_CUJET3[ibin]->SetLineColor(kGreen-10);
		gv2Dmeson5TeV_CUJET3[ibin]->SetLineWidth(0);
		gv2Dmeson5TeV_CUJET3[ibin]->SetFillStyle(3002);
		gv2Dmeson5TeV_CUJET3[ibin]->SetFillColor(kGreen-7);
		gv2Dmeson5TeV_CUJET3[ibin]->SetLineColor(kGreen-7);
		//gv2Dmeson5TeV_CUJET3[ibin]->SetFillColor(kGreen-10);
		//gv2Dmeson5TeV_CUJET3[ibin]->SetFillStyle(1001);
	}
}

void Set_theoryD()
{
	Set_CUJET3();
	Set_TAMU();
	Set_LBT();
	Set_LPang();
	Set_SUBATECH();
	Set_PHSD();
}
