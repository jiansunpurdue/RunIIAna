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
#include <boost/filesystem.hpp>

#include <./../parameters.h>
#include <./../uti.h>
#include <./Plotoption_massfit.h>

#include <./FitFunction_poly3bkg_floatwidth.C>
#include <./FitFunction_expobkg_2nd_floatwidth.C>
#include <./FitFunction_poly2bkg_floatwidth.C>

#include <./FitFunction_poly3bkg.C>
#include <./FitFunction_expobkg_2nd.C>
#include <./FitFunction_poly2bkg.C>

namespace fs = boost::filesystem;

void MassFit_morephibin(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", int iptstart = 4, int iptend = 5, bool isPbPb = 1, int centlow=30, int centhigh=50, TString fitoption = "poly3bkg", bool effcorrected = false)
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, TString fitoption);
	void Fithisto_morephibin( TH1D * histo[][Nphibinmore], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString vnname, TH1D * dNdpt_phibins_in_oneptbin[], TString fitoption, bool effcorrected);

	//get MC histo
	TH1D * mc_matched_signal[Nptbin];
	TH1D * mc_matched_kpiswapped[Nptbin];
	TFile * inputmcfile = new TFile(Form("%s",inputmcfilename.c_str()));
    if( MBorDtrig == "MBtrig" )
    {   
        get_masshist(inputmcfile, mc_matched_signal, Nptbin, "mc_matched_signal_ptweight");
        get_masshist(inputmcfile, mc_matched_kpiswapped, Nptbin, "mc_matched_kpiswapped_ptweight");
    }   
    else if( MBorDtrig == "Dtrig")
    {   
        get_masshist(inputmcfile, mc_matched_signal, Nptbin, "Dtrig_mc_matched_signal_ptweight");
        get_masshist(inputmcfile, mc_matched_kpiswapped, Nptbin, "Dtrig_mc_matched_kpiswapped_ptweight");
    }   

	//get data histo
	TH1D * hmass_MBorDtrig[Nptbin];
	TH1D * hmass_MBorDtrig_v1[Nptbin][Nphibinmore];
	TH1D * hmass_MBorDtrig_v2[Nptbin][Nphibinmore];
	TH1D * hmass_MBorDtrig_v3[Nptbin][Nphibinmore];
	TH1D * hmass_MBorDtrig_v4[Nptbin][Nphibinmore];

	TFile * inputdatafile = new TFile(Form("%s",inputdatafilename.c_str()));
	if( MBorDtrig == "MBtrig" )
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_MB_HFandpart_trig");
		if( !effcorrected )
		{
			get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v2_morephibin");
			get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v3_morephibin");
		}
		else
		{
			get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v2_morephibin_effcorrected");
			get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v3_morephibin_effcorrected");
		}
	}
	else
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_Dtrig_combined");
		//get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v1, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v1_morephibin");
		get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v2_morephibin");
		get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v3_morephibin");
		//get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v4, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v4_morephibin");
	}

    TH1D * dNdpt = new TH1D( Form("dNdpt_%s", fitoption.Data()), Form("dNdpt_%s", fitoption.Data()), Nptbin, ptbins);
	//total fit
	Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, dNdpt, fitoption);

	////pt and phi bins fit
	TH1D * dNdpt_v2_phibins_in_oneptbin[Nptbin];
	TH1D * dNdpt_v3_phibins_in_oneptbin[Nptbin];
	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_phibins_in_oneptbin[ipt] = new TH1D( Form("dNdpt_v2_%s_phibins_in_oneptbin_%d", fitoption.Data(), ipt), Form("dNdpt_v2_%s_phibins_in_oneptbin_%d", fitoption.Data(), ipt), Nphibinmore, 0, PI/2.);
		dNdpt_v3_phibins_in_oneptbin[ipt] = new TH1D( Form("dNdpt_v3_%s_phibins_in_oneptbin_%d", fitoption.Data(), ipt), Form("dNdpt_v3_%s_phibins_in_oneptbin_%d", fitoption.Data(), ipt), Nphibinmore, 0, PI/3.);
		dNdpt_v2_phibins_in_oneptbin[ipt]->Sumw2();
		dNdpt_v3_phibins_in_oneptbin[ipt]->Sumw2();
	}
	Fithisto_morephibin( hmass_MBorDtrig_v2, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, "v2", dNdpt_v2_phibins_in_oneptbin, fitoption, effcorrected);
	Fithisto_morephibin( hmass_MBorDtrig_v3, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, "v3", dNdpt_v3_phibins_in_oneptbin, fitoption, effcorrected);

	////bkg dNdpt
	TH1D * dNdpt_v2_phibins_in_oneptbin_bkg[Nptbin];
	TH1D * dNdpt_v3_phibins_in_oneptbin_bkg[Nptbin];
	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_phibins_in_oneptbin_bkg[ipt] = new TH1D( Form("dNdpt_v2_%s_phibins_in_oneptbin_bkg_%d", fitoption.Data(), ipt), Form("dNdpt_v2_%s_phibins_in_oneptbin_bkg_%d", fitoption.Data(), ipt), Nphibinmore, 0, PI/2.);
		dNdpt_v3_phibins_in_oneptbin_bkg[ipt] = new TH1D( Form("dNdpt_v3_%s_phibins_in_oneptbin_bkg_%d", fitoption.Data(), ipt), Form("dNdpt_v3_%s_phibins_in_oneptbin_bkg_%d", fitoption.Data(), ipt), Nphibinmore, 0, PI/3.);
		dNdpt_v2_phibins_in_oneptbin_bkg[ipt]->Sumw2();
		dNdpt_v3_phibins_in_oneptbin_bkg[ipt]->Sumw2();
	}
	for(int ipt = iptstart; ipt < iptend; ipt++ )
	{
		float ptmin = ptbins[ipt];
		float ptmax = ptbins[ipt+1];

		for(int iphi = 0; iphi < Nphibinmore; iphi++)
		{
			double dNdptbkg_v2 = hmass_MBorDtrig_v2[ipt][iphi]->GetEntries()/(ptmax-ptmin) - dNdpt_v2_phibins_in_oneptbin[ipt]->GetBinContent(iphi+1);;
			double dNdptbkg_v3 = hmass_MBorDtrig_v3[ipt][iphi]->GetEntries()/(ptmax-ptmin) - dNdpt_v2_phibins_in_oneptbin[ipt]->GetBinContent(iphi+1);;

			dNdpt_v2_phibins_in_oneptbin_bkg[ipt]->SetBinContent( iphi+1, dNdptbkg_v2);
			dNdpt_v3_phibins_in_oneptbin_bkg[ipt]->SetBinContent( iphi+1, dNdptbkg_v3);

			//approximate, actually wrong
			dNdpt_v2_phibins_in_oneptbin_bkg[ipt]->SetBinError( iphi+1, TMath::Sqrt(dNdptbkg_v2/(ptmax-ptmin)));
			dNdpt_v3_phibins_in_oneptbin_bkg[ipt]->SetBinError( iphi+1, TMath::Sqrt(dNdptbkg_v3/(ptmax-ptmin)));
		}
	}

	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_morephibin_%s_%s_effcorrected%d.root",(fs::basename(inputdatafilename)).c_str(), fitoption.Data(), effcorrected),"RECREATE");

	dNdpt->Write();

	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_phibins_in_oneptbin[ipt]->Write();
		dNdpt_v3_phibins_in_oneptbin[ipt]->Write();
	}

	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_phibins_in_oneptbin_bkg[ipt]->Write();
		dNdpt_v3_phibins_in_oneptbin_bkg[ipt]->Write();
	}

	output->Close();

	return;
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, TString fitoption)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{       
		TF1* signalfittedfunc = NULL;

		int iptmc = ipt;
//		if( ipt > 2 ) 
//			iptmc = ipt;
//		else    
//			iptmc = 3;

        if( fitoption == "poly3bkg_floatwidth")
            signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "expobkg_2nd_floatwidth")
            signalfittedfunc = fit_histo_expobkg_2nd_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "poly2bkg_floatwidth")
            signalfittedfunc = fit_histo_poly2bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "poly3bkg")
            signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "expobkg_2nd")
            signalfittedfunc = fit_histo_expobkg_2nd( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "poly2bkg")
            signalfittedfunc = fit_histo_poly2bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}   
}

void Fithisto_morephibin( TH1D * histo[][Nphibinmore], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString vnname, TH1D * dNdpt_phibins_in_oneptbin[], TString fitoption, bool effcorrected)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		for(int iphi = 0; iphi < Nphibinmore; iphi++)
		{
			TF1* signalfittedfunc=NULL;
			int iptmc;
			if( ipt > 2 )
				iptmc = ipt;
			else
				iptmc = 3;

			TString cfgname = Form("%s_%s_phibin%d_effcorrected%d", MBorDtrig.Data(), vnname.Data(), iphi, effcorrected);
			//cout << " cfgname: " << cfgname << endl;

			if( fitoption == "poly3bkg_floatwidth")
				signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, cfgname, true, false, NULL, effcorrected);

			if( fitoption == "expobkg_2nd_floatwidth")
				signalfittedfunc = fit_histo_expobkg_2nd_floatwidth( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, cfgname);

			if( fitoption == "poly2bkg_floatwidth")
				signalfittedfunc = fit_histo_poly2bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, cfgname);

			if( fitoption == "poly3bkg")
				signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, cfgname, true, false, NULL, effcorrected);

			if( fitoption == "expobkg_2nd")
				signalfittedfunc = fit_histo_expobkg_2nd( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, cfgname);

			if( fitoption == "poly2bkg")
				signalfittedfunc = fit_histo_poly2bkg( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, cfgname);

			double histomassbinsize = histo[ipt][iphi]->GetBinWidth(10);
			double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
			double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);

			dNdpt_phibins_in_oneptbin[ipt]->SetBinContent( iphi+1, yield/(ptbins[ipt+1]-ptbins[ipt]));
			dNdpt_phibins_in_oneptbin[ipt]->SetBinError( iphi+1, yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
		}
	}
}
