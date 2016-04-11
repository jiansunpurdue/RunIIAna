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

#include <./FitFunction_expobkg_2nd.C>
#include <./FitFunction_poly3bkg.C>

namespace fs = boost::filesystem;

void MassFit_morephibin(string inputdatafilename = "./../anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", int iptstart = 2, int iptend = 11, bool isPbPb = 1, int centlow=30, int centhigh=50)
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt_poly3bkg);
	void Fithisto_morephibin( TH1D * histo[][Nphibinmore], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString vnname, TH1D * dNdpt_poly3bkg_phibins_in_oneptbin[]);

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
		//get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v1, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v1_morephibin");
		get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v2_morephibin");
		get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v3_morephibin");
		//get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v4, Nptbin, Nphibinmore, "hmass_MB_HFandpart_v4_morephibin");
	}
	else
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_Dtrig_combined");
		//get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v1, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v1_morephibin");
		get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v2_morephibin");
		get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v3_morephibin");
		//get_hist_vn_morephibin(inputdatafile, hmass_MBorDtrig_v4, Nptbin, Nphibinmore, "hmass_Dtrig_combined_v4_morephibin");
	}

	TH1D * dNdpt_poly3bkg = new TH1D( "dNdpt_poly3bkg", "dNdpt_poly3bkg", Nptbin, ptbins);
	//fit in and out plane mass

	//total fit
	Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, dNdpt_poly3bkg);

	////pt and phi bins fit
	TH1D * dNdpt_v2_poly3bkg_phibins_in_oneptbin[Nptbin];
	TH1D * dNdpt_v3_poly3bkg_phibins_in_oneptbin[Nptbin];
	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_poly3bkg_phibins_in_oneptbin[ipt] = new TH1D( Form("dNdpt_v2_poly3bkg_phibins_in_oneptbin_%d", ipt), Form("dNdpt_v2_poly3bkg_phibins_in_oneptbin_%d", ipt), Nphibinmore, 0, PI/2.);
		dNdpt_v3_poly3bkg_phibins_in_oneptbin[ipt] = new TH1D( Form("dNdpt_v3_poly3bkg_phibins_in_oneptbin_%d", ipt), Form("dNdpt_v3_poly3bkg_phibins_in_oneptbin_%d", ipt), Nphibinmore, 0, PI/3.);
		dNdpt_v2_poly3bkg_phibins_in_oneptbin[ipt]->Sumw2();
		dNdpt_v3_poly3bkg_phibins_in_oneptbin[ipt]->Sumw2();
	}
	Fithisto_morephibin( hmass_MBorDtrig_v2, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, "v2", dNdpt_v2_poly3bkg_phibins_in_oneptbin);
	Fithisto_morephibin( hmass_MBorDtrig_v3, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, "v3", dNdpt_v3_poly3bkg_phibins_in_oneptbin);

	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_morephibin_%s.root",(fs::basename(inputdatafilename)).c_str()),"RECREATE");

	dNdpt_poly3bkg->Write();

	for(int ipt = 0; ipt < Nptbin; ipt++ )
	{
		dNdpt_v2_poly3bkg_phibins_in_oneptbin[ipt]->Write();
		dNdpt_v3_poly3bkg_phibins_in_oneptbin[ipt]->Write();
	}

	output->Close();

	return;
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt_poly3bkg)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{       
		TF1* signalfittedfunc;

		int iptmc;
		if( ipt > 3 ) 
			iptmc = ipt;
		else    
			iptmc = 4;

		signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt_poly3bkg->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt_poly3bkg->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}   
}

void Fithisto_morephibin( TH1D * histo[][Nphibinmore], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString vnname, TH1D * dNdpt_poly3bkg_phibins_in_oneptbin[])
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		for(int iphi = 0; iphi < Nphibinmore; iphi++)
		{
			TF1* signalfittedfunc;
			int iptmc;
			if( ipt > 3 )
				iptmc = ipt;
			else
				iptmc = 4;

			TString phibin = Form("phibin%d", iphi);
			//cout << " phibin: " << phibin << endl;

			signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig+"_"+vnname+"_"+phibin);
			double histomassbinsize = histo[ipt][iphi]->GetBinWidth(10);
			double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
			double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);

			dNdpt_poly3bkg_phibins_in_oneptbin[ipt]->SetBinContent( iphi+1, yield/(ptbins[ipt+1]-ptbins[ipt]));
			dNdpt_poly3bkg_phibins_in_oneptbin[ipt]->SetBinError( iphi+1, yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
		}
	}
}
