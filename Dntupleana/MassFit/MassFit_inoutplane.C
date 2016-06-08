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

namespace fs = boost::filesystem;

void MassFit_inoutplane(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", int iptstart = 7, int iptend = 8, bool isPbPb = 1, int centlow=30, int centhigh=50, TString fitoption = "poly3bkg_floatwidth")
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, TString fitoption);
	void Fithisto_inoutplane( TH1D * histo[][Nphibin], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString vnname, TH1D * dNdpt_inplane, TH1D * dNdpt_outplane, TString fitoption);

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
	TH1D * hmass_MBorDtrig_v1[Nptbin][Nphibin];
	TH1D * hmass_MBorDtrig_v2[Nptbin][Nphibin];
	TH1D * hmass_MBorDtrig_v3[Nptbin][Nphibin];
	TH1D * hmass_MBorDtrig_v4[Nptbin][Nphibin];

	TFile * inputdatafile = new TFile(Form("%s",inputdatafilename.c_str()));
	if( MBorDtrig == "MBtrig" )
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_MB_HFandpart_trig");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v1, Nptbin, Nphibin, "hmass_MB_HFandpart_v1");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibin, "hmass_MB_HFandpart_v2");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibin, "hmass_MB_HFandpart_v3");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v4, Nptbin, Nphibin, "hmass_MB_HFandpart_v4");
	}
	else
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_Dtrig_combined");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v1, Nptbin, Nphibin, "hmass_Dtrig_combined_v1");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v2, Nptbin, Nphibin, "hmass_Dtrig_combined_v2");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v3, Nptbin, Nphibin, "hmass_Dtrig_combined_v3");
		get_hist_vn_inoutplane(inputdatafile, hmass_MBorDtrig_v4, Nptbin, Nphibin, "hmass_Dtrig_combined_v4");
	}

	TH1D * dNdpt = new TH1D( Form("dNdpt_%s", fitoption.Data()), Form("dNdpt_%s", fitoption.Data()), Nptbin, ptbins);
	//fit in and out plane mass
	TH1D * dNdpt_v1_inplane= new TH1D( Form("dNdpt_v1_inplane_%s", fitoption.Data()), Form("dNdpt_v1_inplane_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * dNdpt_v1_outplane= new TH1D( Form("dNdpt_v1_outplane_%s", fitoption.Data()), Form("dNdpt_v1_outplane_%s", fitoption.Data()), Nptbin, ptbins);

	TH1D * dNdpt_v2_inplane= new TH1D( Form("dNdpt_v2_inplane_%s", fitoption.Data()), Form("dNdpt_v2_inplane_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * dNdpt_v2_outplane= new TH1D( Form("dNdpt_v2_outplane_%s", fitoption.Data()), Form("dNdpt_v2_outplane_%s", fitoption.Data()), Nptbin, ptbins);

	TH1D * dNdpt_v3_inplane= new TH1D( Form("dNdpt_v3_inplane_%s", fitoption.Data()), Form("dNdpt_v3_inplane_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * dNdpt_v3_outplane= new TH1D( Form("dNdpt_v3_outplane_%s", fitoption.Data()), Form("dNdpt_v3_outplane_%s", fitoption.Data()), Nptbin, ptbins);

	TH1D * dNdpt_v4_inplane= new TH1D( Form("dNdpt_v4_inplane_%s", fitoption.Data()), Form("dNdpt_v4_inplane_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * dNdpt_v4_outplane= new TH1D( Form("dNdpt_v4_outplane_%s", fitoption.Data()), Form("dNdpt_v4_outplane_%s", fitoption.Data()), Nptbin, ptbins);

	//total fit
	Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, dNdpt, fitoption);
	////in and out plane fit
	Fithisto_inoutplane( hmass_MBorDtrig_v2, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, "v2", dNdpt_v2_inplane, dNdpt_v2_outplane, fitoption);
	Fithisto_inoutplane( hmass_MBorDtrig_v3, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig, iptstart, iptend, isPbPb, centlow, centhigh, "v3", dNdpt_v3_inplane, dNdpt_v3_outplane, fitoption);

	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_inoutplane_%s_%s.root",(fs::basename(inputdatafilename)).c_str(), fitoption.Data()),"RECREATE");

	dNdpt->Write();

	dNdpt_v1_inplane->Write();
	dNdpt_v1_outplane->Write();
	dNdpt_v2_inplane->Write();
	dNdpt_v2_outplane->Write();
	dNdpt_v3_inplane->Write();
	dNdpt_v3_outplane->Write();
	dNdpt_v4_inplane->Write();
	dNdpt_v4_outplane->Write();

	output->Close();

	return;
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, TString fitoption)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{       
		TF1* signalfittedfunc=NULL;

		int iptmc;
		if( ipt > 3 ) 
			iptmc = ipt;
		else    
			iptmc = 4;

        if( fitoption == "poly3bkg_floatwidth")
            signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "expobkg_2nd_floatwidth")
            signalfittedfunc = fit_histo_expobkg_2nd_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

        if( fitoption == "poly2bkg_floatwidth")
            signalfittedfunc = fit_histo_poly2bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}   
}

void Fithisto_inoutplane( TH1D * histo[][Nphibin], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString vnname, TH1D * dNdpt_inplane, TH1D * dNdpt_outplane, TString fitoption)
{
	for(int iphi = 0; iphi < Nphibin; iphi++)
	{
		TString inoroutplane = "in_plane";
		if( iphi == 1 )  inoroutplane = "out_plane";
		for(int ipt = iptstart; ipt < iptend; ipt++)
		{
			TF1* signalfittedfunc=NULL;
			double yield;
			double yieldErr;
			double histomassbinsize = histo[ipt][iphi]->GetBinWidth(10);

			int iptmc;
			if( ipt > 3 )
				iptmc = ipt;
			else
				iptmc = 4;

			if( fitoption == "poly3bkg_floatwidth")
				signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig+"_"+vnname+"_"+inoroutplane);

			if( fitoption == "expobkg_2nd_floatwidth")
				signalfittedfunc = fit_histo_expobkg_2nd_floatwidth( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig+"_"+vnname+"_"+inoroutplane);

			if( fitoption == "poly2bkg_floatwidth")
				signalfittedfunc = fit_histo_poly2bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt][iphi], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig+"_"+vnname+"_"+inoroutplane);

			yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
			yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);

			if( iphi == 0 )
			{
				dNdpt_inplane->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
				dNdpt_inplane->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
			}
			else
			{
				dNdpt_outplane->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
				dNdpt_outplane->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
			}
		}
	}

}

