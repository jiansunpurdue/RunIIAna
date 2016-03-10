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
#include <boost/filesystem.hpp>

#include <./../parameters.h>
#include <./../uti.h>
#include <./Plotoption_massfit.h>

#include <./FitFunction_expobkg.C>
#include <./FitFunction_poly3bkg.C>

//#include <./../EP_resolution.h>

namespace fs = boost::filesystem;

const int Rebin_mass = 1;
const int Rebin_vnmass = 6;

TF1 *  Func_Ratio_signal_foreground[Nptbin];

void MassFit_vnFitvsmass(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", TString EPorSP = "SP", int iptstart = 7, int iptend = 10, bool isPbPb = true, int centlow=30, int centhigh=50)
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
	Double_t signalweight( Double_t * x, Double_t *par);
	Double_t bkg_liner( Double_t * x, Double_t *par);
	Double_t fitfunction( Double_t * x, Double_t *par);
	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt_poly3bkg, bool Get_signal_bkg_ratio, TH1D * Ratio_signal_foreground[]);
	TF1 * Get_signal_foreground_ratio_poly3bkg(TH1D * histo, int ipt, TString MBorDtrig);
	void plot_signal_foreground(TH1D * ratio[], TF1 * ratio_function[], TString MBorDtrig, int iptstart, int iptend);
	void Add_ratiofunc_to_ratiohisto(TH1D * ratio[], TF1 * ratio_function[], TString MBorDtrig, int iptstart, int iptend);
	void Fit_vnvsmass(TH1D * histo[], TF1 * ratio_function[], TString MBorDtrig, int iptstart, int iptend, TH1D * vsig_fitted);

	//decide event plane resolution, applied when fill histogram
	//double resolution_EP_v1 = 1., resolution_EP_v2 = 1., resolution_EP_v3 = 1., resolution_EP_v4 = 1.;
	//int icentbin = Decide_centbin_for_EPresolution( centlow, centhigh);
	//if( icentbin != -99 )
	//{
	//	resolution_EP_v1 = EP_resolution_v1[icentbin];
	//	resolution_EP_v2 = EP_resolution_v2[icentbin];
	//	resolution_EP_v3 = EP_resolution_v3[icentbin];
	//	resolution_EP_v4 = EP_resolution_v4[icentbin];
	//}
	//cout << "EP resolution, v1: " << resolution_EP_v1 << " v2: " << resolution_EP_v2 << " v3: " << resolution_EP_v3 << " v4: " << resolution_EP_v4 << endl;

	TH1D * mc_matched_signal[Nptbin];
	TH1D * mc_matched_kpiswapped[Nptbin];
	TFile * inputmcfile = new TFile(Form("%s",inputmcfilename.c_str()));
	get_masshist(inputmcfile, mc_matched_signal, Nptbin, "mc_matched_signal_noweight");
	get_masshist(inputmcfile, mc_matched_kpiswapped, Nptbin, "mc_matched_kpiswapped_noweight");

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

		//h_mass_meanv1_MBorDtrig[ipt]->Scale(1.0/resolution_EP_v1);
		//h_mass_meanv2_MBorDtrig[ipt]->Scale(1.0/resolution_EP_v2);
		//h_mass_meanv3_MBorDtrig[ipt]->Scale(1.0/resolution_EP_v3);
		//h_mass_meanv4_MBorDtrig[ipt]->Scale(1.0/resolution_EP_v4);
	}

	// mass spectrum fit and get signal ratio bin by bin
	TH1D * dNdpt_poly3bkg = new TH1D( "dNdpt_poly3bkg", "dNdpt_poly3bkg", Nptbin, ptbins);
	TH1D * fitmean_poly3bkg = new TH1D( "fitmean_poly3bkg", "fitmean_poly3bkg", Nptbin, ptbins);
	TH1D * fitsigma_poly3bkg = new TH1D( "fitsigma_poly3bkg", "fitsigma_poly3bkg", Nptbin, ptbins);

	bool Get_signal_bkg_ratio = true;
	TH1D * Ratio_signal_foreground[Nptbin];
	book_masshist( Ratio_signal_foreground, ptbins, Nptbin, "Ratio_signal_foreground", Nmassbin/Rebin_mass, massmin, massmax);
	Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig+"vn", iptstart, iptend, isPbPb, centlow, centhigh, dNdpt_poly3bkg, Get_signal_bkg_ratio, Ratio_signal_foreground);
	//mass fit spectrum fit done

	//Get ratio function and add to ratio histos
	TF1 *  Func_Ratio_signal_foreground[Nptbin];
	for(int ipt = iptstart; ipt < iptend; ipt++)
		Func_Ratio_signal_foreground[ipt] = Get_signal_foreground_ratio_poly3bkg(hmass_MBorDtrig[ipt], ipt, MBorDtrig+"vn");
	Add_ratiofunc_to_ratiohisto(Ratio_signal_foreground, Func_Ratio_signal_foreground, MBorDtrig+"vn", iptstart, iptend);

	//fit vn vs mass
	TH1D * h_v1_pt = new TH1D("h_v1_pt", "h_v1_pt", Nptbin, ptbins);
	TH1D * h_v2_pt = new TH1D("h_v2_pt", "h_v2_pt", Nptbin, ptbins);
	TH1D * h_v3_pt = new TH1D("h_v3_pt", "h_v3_pt", Nptbin, ptbins);
	TH1D * h_v4_pt = new TH1D("h_v4_pt", "h_v4_pt", Nptbin, ptbins);

//	Fit_vnvsmass(h_mass_meanv1_MBorDtrig, Func_Ratio_signal_foreground, MBorDtrig+"v1", iptstart, iptend, h_v1_pt);
	Fit_vnvsmass(h_mass_meanv2_MBorDtrig, Func_Ratio_signal_foreground, MBorDtrig+"v2", iptstart, iptend, h_v2_pt);
	Fit_vnvsmass(h_mass_meanv3_MBorDtrig, Func_Ratio_signal_foreground, MBorDtrig+"v3", iptstart, iptend, h_v3_pt);
//	Fit_vnvsmass(h_mass_meanv4_MBorDtrig, Func_Ratio_signal_foreground, MBorDtrig+"v4", iptstart, iptend, h_v4_pt);

	TFile * output = new TFile(Form("rootfiles/Raw_spectrum_vnvsmass_%s_%s.root", EPorSP.Data(), (fs::basename(inputdatafilename)).c_str()),"RECREATE");

	dNdpt_poly3bkg->Write();
	fitmean_poly3bkg->Write();
	fitsigma_poly3bkg->Write();

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

void Fit_vnvsmass(TH1D * histo[], TF1 * ratio_function[], TString MBorDtrig, int iptstart, int iptend, TH1D * vsig_fitted)
{
	Double_t signalweight( Double_t * x, Double_t *par);
	Double_t bkg_liner( Double_t * x, Double_t *par);
	Double_t fitfunction( Double_t * x, Double_t *par);
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		Func_Ratio_signal_foreground[ipt] = ratio_function[ipt];
		TF1 * fit = new TF1(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),fitfunction, generalfitrange_masslow, generalfitrange_masshigh, 4);
		fit->SetLineColor(2);
		fit->FixParameter(0, ipt); 
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q m","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q m","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q m","",generalfitrange_masslow, generalfitrange_masshigh);
		vsig_fitted->SetBinContent(ipt+1, fit->GetParameter(1));
		vsig_fitted->SetBinError(ipt+1,fit->GetParError(1));
	}
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt_poly3bkg, bool Get_signal_bkg_ratio, TH1D * Ratio_signal_foreground[])
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{       
		TF1* signalfittedfunc;

		int iptmc;
		if( ipt > 3 ) 
			iptmc = ipt;
		else    
			iptmc = 4;

		signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt_poly3bkg->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt_poly3bkg->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}   
}

TF1 * Get_signal_foreground_ratio_poly3bkg(TH1D * histo, int ipt, TString MBorDtrig)
{
	TF1* Func_Ratio_signal_foreground = new TF1(Form("Func_Ratio_signal_foreground_%s_%d",MBorDtrig.Data(),ipt),"([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])))/([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])) + [7] + [8]*x + [9]*x*x + [10]*x*x*x)", generalfitrange_masslow, generalfitrange_masshigh);
	TF1* histofittedfunc = histo->GetFunction(Form("f_%s_%d", MBorDtrig.Data(), ipt));

	for( int ipar = 0; ipar < 11; ipar++ )
	{
		Func_Ratio_signal_foreground->SetParameter( ipar, histofittedfunc->GetParameter(ipar));
		Func_Ratio_signal_foreground->SetParError(ipar,histofittedfunc->GetParError(ipar));
	}

	return Func_Ratio_signal_foreground;
}

void Add_ratiofunc_to_ratiohisto(TH1D * ratio[], TF1 * ratio_function[], TString MBorDtrig, int iptstart, int iptend)
{
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		ratio_function[ipt]->SetLineColor(2.0);
		ratio[ipt]->GetListOfFunctions()->Add(ratio_function[ipt]);
	}
}

void plot_signal_foreground(TH1D * ratio[], TF1 * ratio_function[], TString MBorDtrig, int iptstart, int iptend)
{
	//signal foreground ratio plots, histo and function
	TCanvas * cfg_signal_foreground[Nptbin];
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		cfg_signal_foreground[ipt] = new TCanvas(Form("cfg_signal_foreground_%s_%d", MBorDtrig.Data(), ipt), Form("cfg_signal_foreground_%s_%d", MBorDtrig.Data(), ipt), 600, 600);
		ratio[ipt]->GetXaxis()->SetRangeUser(generalfitrange_masslow+0.0005, generalfitrange_masshigh-0.0005);
		ratio[ipt]->Draw();
		ratio_function[ipt]->SetLineColor(2.0);
		ratio_function[ipt]->Draw("same");
		ratio[ipt]->GetListOfFunctions()->Add(ratio_function[ipt]);
	}
}

Double_t signalweight( Double_t * x, Double_t *par)
{
	Double_t xx = x[0];
	return Func_Ratio_signal_foreground[int(par[0])]->Eval(xx);
}

Double_t bkg_liner( Double_t * x, Double_t *par)
{
	Double_t xx = x[0];
	Double_t arg = par[0] + par[1] * xx; 
	return arg;
}

Double_t fitfunction( Double_t * x, Double_t *par)
{
	return signalweight(x,par)*par[1] + (1 - signalweight(x,par)) * bkg_liner(x,&par[2]);
}
