#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TProfile.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TRandom3.h>
#include <boost/filesystem.hpp>

#include <./../parameters.h>
#include <./../uti.h>
#include <./Plotoption_massfit.h>

#include <./FitFunction_poly3bkg_combinemassvnfit.C>

//#include <./../EP_resolution.h>

namespace fs = boost::filesystem;

const int Rebin_mass = 1;
const int Rebin_vnmass = 3;

TF1 *  Func_Ratio_signal_foreground[Nptbin];

void MassFit_combmassvnFit(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", TString EPorSP = "SP", int iptstart = 4, int iptend = 5, bool isPbPb = true, int centlow=30, int centhigh=50, TString fitoption = "poly3bkg")
{
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	gStyle->SetTextFont(42);
	gStyle->SetTextSize(0.05);
	gStyle->SetTitleX(.0f);

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

	TH1D * hmass_MBorDtrig[Nptbin];
	TProfile * h_mass_v1_MBorDtrig[Nptbin];
	TProfile * h_mass_v2_MBorDtrig[Nptbin];
	TProfile * h_mass_v3_MBorDtrig[Nptbin];
	TProfile * h_mass_v4_MBorDtrig[Nptbin];

	TFile * inputdatafile = new TFile(Form("%s",inputdatafilename.c_str()));
	if( MBorDtrig == "MBtrig" )
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_MB_HFandpart_trig");
		if( EPorSP == "EP" )
		{
			get_TProfile_mass_vn(inputdatafile, h_mass_v1_MBorDtrig, Nptbin, "h_mass_v1_MB_HFandpart");
			get_TProfile_mass_vn(inputdatafile, h_mass_v2_MBorDtrig, Nptbin, "h_mass_v2_MB_HFandpart");
			get_TProfile_mass_vn(inputdatafile, h_mass_v3_MBorDtrig, Nptbin, "h_mass_v3_MB_HFandpart");
			get_TProfile_mass_vn(inputdatafile, h_mass_v4_MBorDtrig, Nptbin, "h_mass_v4_MB_HFandpart");
		}
		else if ( EPorSP == "SP" )
		{
			get_TProfile_mass_vn(inputdatafile, h_mass_v1_MBorDtrig, Nptbin, "h_mass_v1_SP_MB_HFandpart");
			get_TProfile_mass_vn(inputdatafile, h_mass_v2_MBorDtrig, Nptbin, "h_mass_v2_SP_MB_HFandpart");
			get_TProfile_mass_vn(inputdatafile, h_mass_v3_MBorDtrig, Nptbin, "h_mass_v3_SP_MB_HFandpart");
			get_TProfile_mass_vn(inputdatafile, h_mass_v4_MBorDtrig, Nptbin, "h_mass_v4_SP_MB_HFandpart");
		}
	}
	else
	{
		get_masshist(inputdatafile, hmass_MBorDtrig, Nptbin, "hmass_Dtrig_combined");
		if( EPorSP == "EP" )
		{
			get_TProfile_mass_vn(inputdatafile, h_mass_v1_MBorDtrig, Nptbin, "h_mass_v1_Dtrig_combined");
			get_TProfile_mass_vn(inputdatafile, h_mass_v2_MBorDtrig, Nptbin, "h_mass_v2_Dtrig_combined");
			get_TProfile_mass_vn(inputdatafile, h_mass_v3_MBorDtrig, Nptbin, "h_mass_v3_Dtrig_combined");
			get_TProfile_mass_vn(inputdatafile, h_mass_v4_MBorDtrig, Nptbin, "h_mass_v4_Dtrig_combined");
		}
		else if ( EPorSP == "SP" )
		{
			get_TProfile_mass_vn(inputdatafile, h_mass_v1_MBorDtrig, Nptbin, "h_mass_v1_SP_Dtrig_combined");
			get_TProfile_mass_vn(inputdatafile, h_mass_v2_MBorDtrig, Nptbin, "h_mass_v2_SP_Dtrig_combined");
			get_TProfile_mass_vn(inputdatafile, h_mass_v3_MBorDtrig, Nptbin, "h_mass_v3_SP_Dtrig_combined");
			get_TProfile_mass_vn(inputdatafile, h_mass_v4_MBorDtrig, Nptbin, "h_mass_v4_SP_Dtrig_combined");
		}
	}

	//Rebin
	for( int ipt = 0; ipt < Nptbin; ipt++ )
	{
		hmass_MBorDtrig[ipt]->Rebin(Rebin_mass);
		h_mass_v1_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
		h_mass_v2_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
		h_mass_v3_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
		h_mass_v4_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
	}

	//change profile to histogram
	TH1D * h_mass_meanv1_MBorDtrig[Nptbin];
	TH1D * h_mass_meanv2_MBorDtrig[Nptbin];
	TH1D * h_mass_meanv3_MBorDtrig[Nptbin];
	TH1D * h_mass_meanv4_MBorDtrig[Nptbin];

	for( int ipt = 0; ipt < Nptbin; ipt++ )
	{
		h_mass_meanv1_MBorDtrig[ipt] = h_mass_v1_MBorDtrig[ipt]->ProjectionX(Form("h_mass_meanv1_MBorDtrig_%d",ipt),"e");
		h_mass_meanv2_MBorDtrig[ipt] = h_mass_v2_MBorDtrig[ipt]->ProjectionX(Form("h_mass_meanv2_MBorDtrig_%d",ipt),"e");
		h_mass_meanv3_MBorDtrig[ipt] = h_mass_v3_MBorDtrig[ipt]->ProjectionX(Form("h_mass_meanv3_MBorDtrig_%d",ipt),"e");
		h_mass_meanv4_MBorDtrig[ipt] = h_mass_v4_MBorDtrig[ipt]->ProjectionX(Form("h_mass_meanv4_MBorDtrig_%d",ipt),"e");
	}

	// mass spectrum fit and get signal ratio bin by bin
	TH1D * dNdpt= new TH1D( Form("dNdpt_%s", fitoption.Data()), Form("dNdpt_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * fitmean= new TH1D( Form("fitmean_%s", fitoption.Data()), Form("fitmean_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * fitsigma= new TH1D( Form("fitsigma_%s", fitoption.Data()), Form("fitsigma_%s", fitoption.Data()), Nptbin, ptbins);

	//vn histogram 
	TH1D * h_v1_pt = new TH1D("h_v1_pt", "h_v1_pt", Nptbin, ptbins);
	TH1D * h_v2_pt = new TH1D("h_v2_pt", "h_v2_pt", Nptbin, ptbins);
	TH1D * h_v3_pt = new TH1D("h_v3_pt", "h_v3_pt", Nptbin, ptbins);
	TH1D * h_v4_pt = new TH1D("h_v4_pt", "h_v4_pt", Nptbin, ptbins);

	//mass fit spectrum fit
	bool Get_signal_bkg_ratio = true;
	TH1D * Ratio_signal_foreground[Nptbin];
	book_masshist( Ratio_signal_foreground, ptbins, Nptbin, "Ratio_signal_foreground", Nmassbin/Rebin_mass, massmin, massmax);

	for(int ipt = iptstart; ipt < iptend; ipt++)
	{       
		TF1* signalfittedfunc = NULL;
		bool SavePdfplot = false;

		int iptmc;
		if( ipt > 3 ) 
			iptmc = ipt;
		else    
			iptmc = 4;

		hmass_MBorDtrig[ipt]->SetAxisRange(0,hmass_MBorDtrig[ipt]->GetMaximum()*1.4*1.2,"Y");

		if( fitoption == "poly3bkg")
		{
			signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, hmass_MBorDtrig[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig+"vn", SavePdfplot, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt], h_mass_v2_MBorDtrig[ipt], h_v2_pt, "v2", EPorSP);
			signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, hmass_MBorDtrig[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig+"vn", SavePdfplot, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt], h_mass_v3_MBorDtrig[ipt], h_v3_pt, "v3", EPorSP);
		}

	//	if( fitoption == "expobkg_2nd")
	//		signalfittedfunc = fit_histo_expobkg_2nd( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

	//	if( fitoption == "poly2bkg")
	//		signalfittedfunc = fit_histo_poly2bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

	//	if( fitoption == "poly3bkg_floatwidth")
	//		signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

		double histomassbinsize = hmass_MBorDtrig[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}   

	//get signal background ratio function
	for( int ipt = iptstart; ipt < iptend; ipt++)
		Func_Ratio_signal_foreground[ipt] = Ratio_signal_foreground[ipt]->GetFunction(Form("Func_Ratio_signal_foreground_%s_%d", (MBorDtrig+"vn").Data(), ipt));
	
	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_combinemassvnfit_%s_%s_%s.root", EPorSP.Data(), (fs::basename(inputdatafilename)).c_str(), fitoption.Data()),"RECREATE");

	output->cd();
	dNdpt->Write();
	fitmean->Write();
	fitsigma->Write();

	h_v1_pt->Write();
	h_v2_pt->Write();
	h_v3_pt->Write();
	h_v4_pt->Write();

	for( int ipt = iptstart; ipt < iptend; ipt++)
		Ratio_signal_foreground[ipt]->Write();

	for( int ipt = iptstart; ipt < iptend; ipt++)
	{
		h_mass_meanv1_MBorDtrig[ipt]->Write();
		h_mass_meanv2_MBorDtrig[ipt]->Write();
		h_mass_meanv3_MBorDtrig[ipt]->Write();
		h_mass_meanv4_MBorDtrig[ipt]->Write();
	}

	output->Close();

	return;
}