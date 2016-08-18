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

#include <./DataPoints_HIN_15_014.C>

TGraphErrors * grSteveSPv2_chargeparticle = NULL;
TGraphErrors * grSteveSPv2_sys_chargeparticle = NULL;
TGraphErrors * grSteveSPv3_chargeparticle = NULL;
TGraphErrors * grSteveSPv3_sys_chargeparticle = NULL;

void SetChargedparticle_vn()
{
	DataPoints();

	grSteveSPv2[8]->SetMarkerStyle(33);
	grSteveSPv2[8]->SetMarkerColor(1.0);
	grSteveSPv2[8]->SetLineColor(1.0);
	grSteveSPv2[8]->SetMarkerSize(1);

	grSteveSPv2[9]->SetMarkerStyle(33);
	grSteveSPv2[9]->SetMarkerColor(1.0);
	grSteveSPv2[9]->SetLineColor(1.0);
	grSteveSPv2[9]->SetMarkerSize(1);

	grSteveSPv2[10]->SetMarkerStyle(33);
	grSteveSPv2[10]->SetMarkerColor(1.0);
	grSteveSPv2[10]->SetLineColor(1.0);
	grSteveSPv2[10]->SetMarkerSize(1);

	grSteveSPv2sys[8]->SetFillStyle(0);
	//grSteveSPv2sys[8]->SetFillColor(16);
	grSteveSPv2sys[8]->SetLineColor(1);

	grSteveSPv2sys[9]->SetFillStyle(0);
	//grSteveSPv2sys[9]->SetFillColor(16);
	grSteveSPv2sys[9]->SetLineColor(1);

	grSteveSPv2sys[10]->SetFillStyle(0);
	//grSteveSPv2sys[10]->SetFillColor(16);
	grSteveSPv2sys[10]->SetLineColor(1);

	grSteveSPv2[8]->SetName("grSteveSPv2_cent0to10");
	grSteveSPv2[9]->SetName("grSteveSPv2_cent10to30");
	grSteveSPv2[10]->SetName("grSteveSPv2_cent30to50");

	grSteveSPv2sys[8]->SetName("grSteveSPv2_sys_cent0to10");
	grSteveSPv2sys[9]->SetName("grSteveSPv2_sys_cent10to30");
	grSteveSPv2sys[10]->SetName("grSteveSPv2_sys_cent30to50");

	for( int ibin = 0; ibin < grSteveSPv2sys[8]->GetN(); ibin++)
	{   
		grSteveSPv2sys[8]->GetEX()[ibin] = 0.5;
		grSteveSPv2sys[9]->GetEX()[ibin] = 0.5;
		grSteveSPv2sys[10]->GetEX()[ibin] = 0.5;
	}   

	grSteveSPv3[8]->SetMarkerStyle(33);
	grSteveSPv3[8]->SetMarkerColor(1.0);
	grSteveSPv3[8]->SetLineColor(1.0);
	grSteveSPv3[8]->SetMarkerSize(1);

	grSteveSPv3[9]->SetMarkerStyle(33);
	grSteveSPv3[9]->SetMarkerColor(1.0);
	grSteveSPv3[9]->SetLineColor(1.0);
	grSteveSPv3[9]->SetMarkerSize(1);

	grSteveSPv3[10]->SetMarkerStyle(33);
	grSteveSPv3[10]->SetMarkerColor(1.0);
	grSteveSPv3[10]->SetLineColor(1.0);
	grSteveSPv3[10]->SetMarkerSize(1);

	grSteveSPv3sys[8]->SetFillStyle(0);
	//grSteveSPv3sys[8]->SetFillColor(16);
	grSteveSPv3sys[8]->SetLineColor(1);

	grSteveSPv3sys[9]->SetFillStyle(0);
	//grSteveSPv3sys[9]->SetFillColor(16);
	grSteveSPv3sys[9]->SetLineColor(1);

	grSteveSPv3sys[10]->SetFillStyle(0);
	//grSteveSPv3sys[10]->SetFillColor(16);
	grSteveSPv3sys[10]->SetLineColor(1);

	for( int ibin = 0; ibin < grSteveSPv3sys[8]->GetN(); ibin++)
	{
		grSteveSPv3sys[8]->GetEX()[ibin] = 0.5;
		grSteveSPv3sys[9]->GetEX()[ibin] = 0.5;
		grSteveSPv3sys[10]->GetEX()[ibin] = 0.5;
	}

	grSteveSPv3[8]->SetName("grSteveSPv3_sys_cent0to10");
	grSteveSPv3[9]->SetName("grSteveSPv3_sys_cent10to30");
	grSteveSPv3[10]->SetName("grSteveSPv3_sys_cent30to50");

	grSteveSPv3sys[8]->SetName("grSteveSPv3_sys_cent0to10");
	grSteveSPv3sys[9]->SetName("grSteveSPv3_sys_cent10to30");
	grSteveSPv3sys[10]->SetName("grSteveSPv3_sys_cent30to50");
}

void Getchargedparticle( int cent_low, int cent_high )
{
	SetChargedparticle_vn();

	if( cent_low == 0 && cent_high == 10 )
	{
		grSteveSPv2_chargeparticle = (TGraphErrors *) grSteveSPv2[8]->Clone("grSteveSPv2_chargeparticle");
		grSteveSPv2_sys_chargeparticle = (TGraphErrors *) grSteveSPv2sys[8]->Clone("grSteveSPv2_sys_chargeparticle");
		grSteveSPv3_chargeparticle = (TGraphErrors *) grSteveSPv3[8]->Clone("grSteveSPv3_chargeparticle");
		grSteveSPv3_sys_chargeparticle = (TGraphErrors *) grSteveSPv3sys[8]->Clone("grSteveSPv3_sys_chargeparticle");
		grSteveSPv2_chargeparticle->SetName("grSteveSPv2_chargeparticle");
		grSteveSPv2_sys_chargeparticle->SetName("grSteveSPv2_sys_chargeparticle");
		grSteveSPv3_chargeparticle->SetName("grSteveSPv3_chargeparticle");
		grSteveSPv3_sys_chargeparticle->SetName("grSteveSPv3_sys_chargeparticle");
	}

	if( cent_low == 10 && cent_high == 30 )
	{
		grSteveSPv2_chargeparticle = (TGraphErrors *) grSteveSPv2[9]->Clone("grSteveSPv2_chargeparticle");
		grSteveSPv2_sys_chargeparticle = (TGraphErrors *) grSteveSPv2sys[9]->Clone("grSteveSPv2_sys_chargeparticle");
		grSteveSPv3_chargeparticle = (TGraphErrors *) grSteveSPv3[9]->Clone("grSteveSPv3_chargeparticle");
		grSteveSPv3_sys_chargeparticle = (TGraphErrors *) grSteveSPv3sys[9]->Clone("grSteveSPv3_sys_chargeparticle");
		grSteveSPv2_chargeparticle->SetName("grSteveSPv2_chargeparticle");
		grSteveSPv2_sys_chargeparticle->SetName("grSteveSPv2_sys_chargeparticle");
		grSteveSPv3_chargeparticle->SetName("grSteveSPv3_chargeparticle");
		grSteveSPv3_sys_chargeparticle->SetName("grSteveSPv3_sys_chargeparticle");
	}

	if( cent_low == 30 && cent_high == 50 )
	{
		grSteveSPv2_chargeparticle = (TGraphErrors *) grSteveSPv2[10]->Clone("grSteveSPv2_chargeparticle");
		grSteveSPv2_sys_chargeparticle = (TGraphErrors *) grSteveSPv2sys[10]->Clone("grSteveSPv2_sys_chargeparticle");
		grSteveSPv3_chargeparticle = (TGraphErrors *) grSteveSPv3[10]->Clone("grSteveSPv3_chargeparticle");
		grSteveSPv3_sys_chargeparticle = (TGraphErrors *) grSteveSPv3sys[10]->Clone("grSteveSPv3_sys_chargeparticle");
		grSteveSPv2_chargeparticle->SetName("grSteveSPv2_chargeparticle");
		grSteveSPv2_sys_chargeparticle->SetName("grSteveSPv2_sys_chargeparticle");
		grSteveSPv3_chargeparticle->SetName("grSteveSPv3_chargeparticle");
		grSteveSPv3_sys_chargeparticle->SetName("grSteveSPv3_sys_chargeparticle");
	}
}
