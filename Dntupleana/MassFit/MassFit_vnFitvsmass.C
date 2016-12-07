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

#include <./FitFunction_poly3bkg.C>
#include <./FitFunction_expobkg_2nd.C>
#include <./FitFunction_poly2bkg.C>
#include <./FitFunction_poly3bkg_floatwidth.C>
#include <./FitFunction_poly2bkg_floatwidth.C>
#include <./FitFunction_expobkg_2nd_floatwidth.C>

//#include <./../EP_resolution.h>

namespace fs = boost::filesystem;

const int Rebin_mass = 1;
const int Rebin_vnmass = 3;

#define Nvnmassbins 14
double massbin_rebinvnmass[Nvnmassbins+1] = { 1.7, 1.74, 1.78, 1.80, 1.82, 1.84, 1.85, 1.86, 1.865, 1.87, 1.88, 1.90, 1.92, 1.96, 2.00};

TF1 *  Func_Ratio_signal_foreground[Nptbin];

void MassFit_vnFitvsmass(string inputdatafilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015_Cent30to50.root", string inputmcfilename = "./../rootfiles/anaDntuple_Dntuple_crab_PbPbMC_Pythia8_prompt_D0pt0p0_5020GeV_evtgen130_GEN_SIM_PU_20160229_tk0p7eta1p5_03132016_Cent-0to100_Evt0to-1.root", TString MBorDtrig = "MBtrig", TString EPorSP = "SP", int iptstart = 4, int iptend = 5, bool isPbPb = true, int centlow=30, int centhigh=50, TString fitoption = "poly3bkg_floatwidth", bool doStatisticalerr_from_signalfractionfunc = false, int toyMCnumber = 1000)
{
	TH1::SetDefaultSumw2();
	Plotoption_massfit();
	Double_t signalweight( Double_t * x, Double_t *par);
	Double_t bkg_liner( Double_t * x, Double_t *par);
	Double_t fitfunction( Double_t * x, Double_t *par);
	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, bool Get_signal_bkg_ratio, TH1D * Ratio_signal_foreground[], TString fitoption, bool SavePdfplot = true);
	void Fit_vnvsmass(TH1D * histo[], TString MBorDtrig, int iptstart, int iptend, TH1D * vsig_fitted);
	void plot_signal_foreground(TH1D * ratio[], TString MBorDtrig, int iptstart, int iptend);
	void ToyMC_Get_Statisticalerr_from_signalfractionfunc( TFile * output, TH1D * hmass_MBorDtrig[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TH1D * h_v1_pt, TH1D * h_v2_pt, TH1D * h_v3_pt, TH1D * h_v4_pt, TH1D * h_mass_meanv1[], TH1D * h_mass_meanv2[], TH1D * h_mass_meanv3[], TH1D * h_mass_meanv4[], TString MBorDtrig, TString EPorSP, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString fitoption, int toyMCnumber );

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


    TProfile * h_mass_v1_MBorDtrig_Rebin[Nptbin];
    TProfile * h_mass_v2_MBorDtrig_Rebin[Nptbin];
    TProfile * h_mass_v3_MBorDtrig_Rebin[Nptbin];
    TProfile * h_mass_v4_MBorDtrig_Rebin[Nptbin];

	//Rebin
	for( int ipt = 0; ipt < Nptbin; ipt++ )
	{
		hmass_MBorDtrig[ipt]->Rebin(Rebin_mass);

//		h_mass_v1_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
//		h_mass_v2_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
//		h_mass_v3_MBorDtrig[ipt]->Rebin(Rebin_vnmass);
//		h_mass_v4_MBorDtrig[ipt]->Rebin(Rebin_vnmass);

        h_mass_v1_MBorDtrig_Rebin[ipt] = ( TProfile * ) h_mass_v1_MBorDtrig[ipt]->Rebin( Nvnmassbins, Form("h_mass_v1_MBorDtrig_Rebin_%d", ipt), massbin_rebinvnmass);
        h_mass_v2_MBorDtrig_Rebin[ipt] = ( TProfile * ) h_mass_v2_MBorDtrig[ipt]->Rebin( Nvnmassbins, Form("h_mass_v2_MBorDtrig_Rebin_%d", ipt), massbin_rebinvnmass);
        h_mass_v3_MBorDtrig_Rebin[ipt] = ( TProfile * ) h_mass_v3_MBorDtrig[ipt]->Rebin( Nvnmassbins, Form("h_mass_v3_MBorDtrig_Rebin_%d", ipt), massbin_rebinvnmass);
        h_mass_v4_MBorDtrig_Rebin[ipt] = ( TProfile * ) h_mass_v4_MBorDtrig[ipt]->Rebin( Nvnmassbins, Form("h_mass_v4_MBorDtrig_Rebin_%d", ipt), massbin_rebinvnmass);

	}

	//change profile to histogram
	TH1D * h_mass_meanv1_MBorDtrig[Nptbin];
	TH1D * h_mass_meanv2_MBorDtrig[Nptbin];
	TH1D * h_mass_meanv3_MBorDtrig[Nptbin];
	TH1D * h_mass_meanv4_MBorDtrig[Nptbin];

	for( int ipt = 0; ipt < Nptbin; ipt++ )
	{
		h_mass_meanv1_MBorDtrig[ipt] = h_mass_v1_MBorDtrig_Rebin[ipt]->ProjectionX(Form("h_mass_meanv1_MBorDtrig_%d",ipt),"e");
		h_mass_meanv2_MBorDtrig[ipt] = h_mass_v2_MBorDtrig_Rebin[ipt]->ProjectionX(Form("h_mass_meanv2_MBorDtrig_%d",ipt),"e");
		h_mass_meanv3_MBorDtrig[ipt] = h_mass_v3_MBorDtrig_Rebin[ipt]->ProjectionX(Form("h_mass_meanv3_MBorDtrig_%d",ipt),"e");
		h_mass_meanv4_MBorDtrig[ipt] = h_mass_v4_MBorDtrig_Rebin[ipt]->ProjectionX(Form("h_mass_meanv4_MBorDtrig_%d",ipt),"e");
	}

	// mass spectrum fit and get signal ratio bin by bin
	TH1D * dNdpt= new TH1D( Form("dNdpt_%s", fitoption.Data()), Form("dNdpt_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * fitmean= new TH1D( Form("fitmean_%s", fitoption.Data()), Form("fitmean_%s", fitoption.Data()), Nptbin, ptbins);
	TH1D * fitsigma= new TH1D( Form("fitsigma_%s", fitoption.Data()), Form("fitsigma_%s", fitoption.Data()), Nptbin, ptbins);

	//mass fit spectrum fit
	bool Get_signal_bkg_ratio = true;
	TH1D * Ratio_signal_foreground[Nptbin];
	book_masshist( Ratio_signal_foreground, ptbins, Nptbin, "Ratio_signal_foreground", Nmassbin/Rebin_mass, massmin, massmax);
	Fithistograms( hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, MBorDtrig+"vn", iptstart, iptend, isPbPb, centlow, centhigh, dNdpt, Get_signal_bkg_ratio, Ratio_signal_foreground, fitoption);
	//get signal background ratio function
	for( int ipt = iptstart; ipt < iptend; ipt++)
		Func_Ratio_signal_foreground[ipt] = Ratio_signal_foreground[ipt]->GetFunction(Form("Func_Ratio_signal_foreground_%s_%d", (MBorDtrig+"vn").Data(), ipt));

	//fit vn vs mass
	TH1D * h_v1_pt = new TH1D("h_v1_pt", "h_v1_pt", Nptbin, ptbins);
	TH1D * h_v2_pt = new TH1D("h_v2_pt", "h_v2_pt", Nptbin, ptbins);
	TH1D * h_v3_pt = new TH1D("h_v3_pt", "h_v3_pt", Nptbin, ptbins);
	TH1D * h_v4_pt = new TH1D("h_v4_pt", "h_v4_pt", Nptbin, ptbins);

	//	Fit_vnvsmass(h_mass_meanv1_MBorDtrig, MBorDtrig+"v1", iptstart, iptend, h_v1_pt);
	Fit_vnvsmass(h_mass_meanv2_MBorDtrig, MBorDtrig+"v2", iptstart, iptend, h_v2_pt);
	Fit_vnvsmass(h_mass_meanv3_MBorDtrig, MBorDtrig+"v3", iptstart, iptend, h_v3_pt);
	//	Fit_vnvsmass(h_mass_meanv4_MBorDtrig, MBorDtrig+"v4", iptstart, iptend, h_v4_pt);

	TFile * output = NULL;

	if( doStatisticalerr_from_signalfractionfunc )
	{
		output = new TFile(Form("rootfiles/Raw_spectrum_vnvsmass_%s_%s_%s_staterrsigfrfunc.root", EPorSP.Data(), (fs::basename(inputdatafilename)).c_str(), fitoption.Data()),"RECREATE");
		ToyMC_Get_Statisticalerr_from_signalfractionfunc( output, hmass_MBorDtrig, mc_matched_signal, mc_matched_kpiswapped, h_v1_pt, h_v2_pt, h_v3_pt, h_v4_pt, h_mass_meanv1_MBorDtrig, h_mass_meanv2_MBorDtrig, h_mass_meanv3_MBorDtrig, h_mass_meanv4_MBorDtrig, MBorDtrig, EPorSP, iptstart, iptend, isPbPb, centlow, centhigh, fitoption, toyMCnumber);
	}
	else
		output = new TFile(Form("rootfiles/Raw_spectrum_vnvsmass_%s_%s_%s.root", EPorSP.Data(), (fs::basename(inputdatafilename)).c_str(), fitoption.Data()),"RECREATE");

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

	//when random the mass spectrum, it is ONLY ok to close the output file if the signal fraction function is removed in line 403
	//don't understand why it is the case yet
	if(!doStatisticalerr_from_signalfractionfunc) output->Close();

	return;
}

void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, bool Get_signal_bkg_ratio, TH1D * Ratio_signal_foreground[], TString fitoption, bool SavePdfplot = true)
{
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{       
		TF1* signalfittedfunc = NULL;

		int iptmc = ipt;
//		if( ipt > 2 ) 
//			iptmc = ipt;
//		else    
//			iptmc = 3;

//		if( fitoption == "poly3bkg")
//			signalfittedfunc = fit_histo_poly3bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);
//
//		if( fitoption == "expobkg_2nd")
//			signalfittedfunc = fit_histo_expobkg_2nd( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);
//
//		if( fitoption == "poly2bkg")
//			signalfittedfunc = fit_histo_poly2bkg( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

		if( fitoption == "poly3bkg_floatwidth") // only default fit needs SavePdfplot for toyMC study
			signalfittedfunc = fit_histo_poly3bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, SavePdfplot, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

		if( fitoption == "poly2bkg_floatwidth")
			signalfittedfunc = fit_histo_poly2bkg_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, SavePdfplot, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

		if( fitoption == "expobkg_2nd_floatwidth")
			signalfittedfunc = fit_histo_expobkg_2nd_floatwidth( isPbPb, centlow, centhigh, histo[ipt], mc_matched_signal[iptmc], mc_matched_kpiswapped[iptmc], ipt, MBorDtrig, SavePdfplot, Get_signal_bkg_ratio, Ratio_signal_foreground[ipt]);

		double histomassbinsize = histo[ipt]->GetBinWidth(10);
		double yield = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize;
		double yieldErr = signalfittedfunc->Integral(massmin,massmax)/histomassbinsize * signalfittedfunc->GetParError(0)/signalfittedfunc->GetParameter(0);
		dNdpt->SetBinContent(ipt+1,yield/(ptbins[ipt+1]-ptbins[ipt]));
		dNdpt->SetBinError(ipt+1,yieldErr/(ptbins[ipt+1]-ptbins[ipt]));
	}   
}

void Fit_vnvsmass(TH1D * histo[], TString MBorDtrig, int iptstart, int iptend, TH1D * vsig_fitted)
{
	Double_t signalweight( Double_t * x, Double_t *par);
	Double_t bkg_liner( Double_t * x, Double_t *par);
	Double_t fitfunction( Double_t * x, Double_t *par);
	for(int ipt = iptstart; ipt < iptend; ipt++)
	{
		TF1 * fit = new TF1(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),fitfunction, generalfitrange_masslow, generalfitrange_masshigh, 4);
		fit->SetLineColor(2);
		fit->FixParameter(0, ipt); 
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		//histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		//histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		//histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q m","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"q m","",generalfitrange_masslow, generalfitrange_masshigh);
		histo[ipt]->Fit(Form("f_vn_mass_%s_%d", MBorDtrig.Data(), ipt),"m","",generalfitrange_masslow, generalfitrange_masshigh);
		vsig_fitted->SetBinContent(ipt+1, fit->GetParameter(1));
		vsig_fitted->SetBinError(ipt+1,fit->GetParError(1));
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

void plot_signal_foreground(TH1D * ratio[], TString MBorDtrig, int iptstart, int iptend)
{
	//signal foreground ratio plots, histo and function
	TCanvas * cfg_signal_foreground[Nptbin];
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		cfg_signal_foreground[ipt] = new TCanvas(Form("cfg_signal_foreground_%s_%d", MBorDtrig.Data(), ipt), Form("cfg_signal_foreground_%s_%d", MBorDtrig.Data(), ipt), 600, 600);
		ratio[ipt]->GetXaxis()->SetRangeUser(generalfitrange_masslow+0.0005, generalfitrange_masshigh-0.0005);
		ratio[ipt]->GetXaxis()->SetTitle("m_{#piK} (GeV/c^{2})");
		ratio[ipt]->GetYaxis()->SetTitle("Signal Fraction");
		ratio[ipt]->GetYaxis()->SetRangeUser(0, 1.0);
		ratio[ipt]->Draw();
	}
}

void ToyMC_Get_Statisticalerr_from_signalfractionfunc( TFile * output, TH1D * hmass_MBorDtrig[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TH1D * h_v1_pt, TH1D * h_v2_pt, TH1D * h_v3_pt, TH1D * h_v4_pt, TH1D * h_mass_meanv1[], TH1D * h_mass_meanv2[], TH1D * h_mass_meanv3[], TH1D * h_mass_meanv4[], TString MBorDtrig, TString EPorSP, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TString fitoption, int toyMCnumber )
{
	if(gRandom) delete gRandom;
	gRandom = new TRandom3(0);
	gRandom->SetSeed(0);

	void Fithistograms(TH1D * histo[], TH1D * mc_matched_signal[], TH1D * mc_matched_kpiswapped[], TString MBorDtrig, int iptstart, int iptend, bool isPbPb, int centlow, int centhigh, TH1D * dNdpt, bool Get_signal_bkg_ratio, TH1D * Ratio_signal_foreground[], TString fitoption, bool SavePdfplot = true);
	void Fit_vnvsmass(TH1D * histo[], TString MBorDtrig, int iptstart, int iptend, TH1D * vsig_fitted);

	//mass spectrum to random
	TH1D * hmass_MBorDtrig_toyMC[Nptbin];
	book_masshist( hmass_MBorDtrig_toyMC, ptbins, Nptbin, "hmass_MBorDtrig_toyMC", Nmassbin, massmin, massmax);

	TH1D * h_mass_meanv1_toyMC[Nptbin];
	TH1D * h_mass_meanv2_toyMC[Nptbin];
	TH1D * h_mass_meanv3_toyMC[Nptbin];
	TH1D * h_mass_meanv4_toyMC[Nptbin];

	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		h_mass_meanv2_toyMC[ipt] = (TH1D *) h_mass_meanv2[ipt]->Clone(Form("h_mass_meanv2_toyMC%d", ipt));
		h_mass_meanv3_toyMC[ipt] = (TH1D *) h_mass_meanv3[ipt]->Clone(Form("h_mass_meanv3_toyMC%d", ipt));
	}

	TH1D * Ratio_signal_foreground_toyMC[Nptbin];
	book_masshist( Ratio_signal_foreground_toyMC, ptbins, Nptbin, "Ratio_signal_foreground_toyMC", Nmassbin/Rebin_mass, massmin, massmax);

	//book histo to save vn from toy MC
	TH1D * h_v1_toyMC_oneptbin[Nptbin];
	TH1D * h_v2_toyMC_oneptbin[Nptbin];
	TH1D * h_v3_toyMC_oneptbin[Nptbin];
	TH1D * h_v4_toyMC_oneptbin[Nptbin];
	char h_title[1000];
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		float pt_low = ptbins[ipt];
		float pt_high = ptbins[ipt+1];
		sprintf(h_title, " %2.1f < p_{T} < %2.1f GeV/c", pt_low, pt_high);

		h_v1_toyMC_oneptbin[ipt] = new TH1D( Form("h_v1_toyMC_oneptbin_%d", ipt), h_title, 500, 
				h_v1_pt->GetBinContent(ipt+1) - 2.*h_v1_pt->GetBinError(ipt+1), h_v1_pt->GetBinContent(ipt+1) + 2*h_v1_pt->GetBinError(ipt+1));
		h_v2_toyMC_oneptbin[ipt] = new TH1D( Form("h_v2_toyMC_oneptbin_%d", ipt), h_title, 500, 
				h_v2_pt->GetBinContent(ipt+1) - 2.*h_v2_pt->GetBinError(ipt+1), h_v2_pt->GetBinContent(ipt+1) + 2*h_v2_pt->GetBinError(ipt+1));
		h_v3_toyMC_oneptbin[ipt] = new TH1D( Form("h_v3_toyMC_oneptbin_%d", ipt), h_title, 500, 
				h_v3_pt->GetBinContent(ipt+1) - 2.*h_v3_pt->GetBinError(ipt+1), h_v3_pt->GetBinContent(ipt+1) + 2*h_v3_pt->GetBinError(ipt+1));
		h_v4_toyMC_oneptbin[ipt] = new TH1D( Form("h_v4_toyMC_oneptbin_%d", ipt), h_title, 500, 
				h_v4_pt->GetBinContent(ipt+1) - 2.*h_v4_pt->GetBinError(ipt+1), h_v4_pt->GetBinContent(ipt+1) + 2*h_v4_pt->GetBinError(ipt+1));

		h_v1_toyMC_oneptbin[ipt]->Sumw2();
		h_v2_toyMC_oneptbin[ipt]->Sumw2();
		h_v3_toyMC_oneptbin[ipt]->Sumw2();
		h_v4_toyMC_oneptbin[ipt]->Sumw2();
	}

	TH1D * h_v2_pt_toyMC = new TH1D("h_v2_pt_toyMC", "h_v2_pt_toyMC", Nptbin, ptbins);
	TH1D * h_v3_pt_toyMC = new TH1D("h_v3_pt_toyMC", "h_v3_pt_toyMC", Nptbin, ptbins);

	// mass spectrum fit and get signal ratio bin by bin
	TH1D * dNdpt_toyMC = new TH1D( Form("dNdpt_toyMC_%s", fitoption.Data()), Form("dNdpt_toyMC_%s", fitoption.Data()), Nptbin, ptbins);

	for( int itoyMC = 0; itoyMC < toyMCnumber; itoyMC++ )
	{
		for( int ipt = iptstart; ipt < iptend; ipt++ )
		{
			for( int ibin = 0; ibin < hmass_MBorDtrig_toyMC[ipt]->GetNbinsX(); ibin++)
			{
				hmass_MBorDtrig_toyMC[ipt]->SetBinContent( ibin+1, gRandom->Gaus( hmass_MBorDtrig[ipt]->GetBinContent(ibin+1), hmass_MBorDtrig[ipt]->GetBinError(ibin+1) ) );
				hmass_MBorDtrig_toyMC[ipt]->SetBinError( ibin+1, hmass_MBorDtrig[ipt]->GetBinError(ibin+1) );
			}
			hmass_MBorDtrig_toyMC[ipt]->SetMaximum(hmass_MBorDtrig[ipt]->GetMaximum()/(1.4*1.2));
		}

		//mass fit spectrum fit
		bool Get_signal_bkg_ratio = true;
		Fithistograms( hmass_MBorDtrig_toyMC, mc_matched_signal, mc_matched_kpiswapped, Form("%svn_toyMC%d",MBorDtrig.Data(),itoyMC), iptstart, iptend, isPbPb, centlow, centhigh, dNdpt_toyMC, Get_signal_bkg_ratio, Ratio_signal_foreground_toyMC, fitoption, false);

		////get signal background ratio function
		for( int ipt = iptstart; ipt < iptend; ipt++)
		{
			if( Ratio_signal_foreground_toyMC[ipt]->GetListOfFunctions()->FindObject(Form("Func_Ratio_signal_foreground_%s_%d", Form("%svn_toyMC%d",MBorDtrig.Data(),itoyMC), ipt)) )
				Func_Ratio_signal_foreground[ipt] = (TF1 *) Ratio_signal_foreground_toyMC[ipt]->GetListOfFunctions()->FindObject(Form("Func_Ratio_signal_foreground_%s_%d", Form("%svn_toyMC%d",MBorDtrig.Data(),itoyMC), ipt));
			else
				cout << "Cannot get signal fraction function!!!!!!!!" << endl;
			//cout <<"!!!!!!!!!!!! parameters, ipt: " << ipt;
			//for( int ipar = 0; ipar < Func_Ratio_signal_foreground[ipt]->GetNpar(); ipar++ )
			//	cout << "   ipar: " << ipar << ", value: " << Func_Ratio_signal_foreground[ipt]->GetParameter(ipar);
			//cout << endl;
		}

		Fit_vnvsmass(h_mass_meanv2_toyMC, Form("%s_v2_toyMC%d", MBorDtrig.Data(), itoyMC), iptstart, iptend, h_v2_pt_toyMC);
		Fit_vnvsmass(h_mass_meanv3_toyMC, Form("%s_v3_toyMC%d", MBorDtrig.Data(), itoyMC), iptstart, iptend, h_v3_pt_toyMC);
		//		
		for( int ipt = iptstart; ipt < iptend; ipt++ )
		{
			h_v2_toyMC_oneptbin[ipt]->Fill( h_v2_pt_toyMC->GetBinContent(ipt+1) );
			h_v3_toyMC_oneptbin[ipt]->Fill( h_v3_pt_toyMC->GetBinContent(ipt+1) );
		}

		for( int ipt = iptstart; ipt < iptend; ipt++ )
		{
			hmass_MBorDtrig_toyMC[ipt]->GetListOfFunctions()->Remove(hmass_MBorDtrig_toyMC[ipt]->GetListOfFunctions()->FindObject(Form("f_%s_%d",Form("%svn_toyMC%d",MBorDtrig.Data(),itoyMC),ipt)));
			h_mass_meanv2_toyMC[ipt]->GetListOfFunctions()->Remove(h_mass_meanv2_toyMC[ipt]->GetListOfFunctions()->FindObject(Form("f_vn_mass_%s_%d", Form("%s_v2_toyMC%d", MBorDtrig.Data(), itoyMC),ipt)));
			h_mass_meanv3_toyMC[ipt]->GetListOfFunctions()->Remove(h_mass_meanv3_toyMC[ipt]->GetListOfFunctions()->FindObject(Form("f_vn_mass_%s_%d", Form("%s_v3_toyMC%d", MBorDtrig.Data(), itoyMC),ipt)));
			//Ratio_signal_foreground_toyMC[ipt]->GetListOfFunctions()->Remove(Ratio_signal_foreground_toyMC[ipt]->GetListOfFunctions()->FindObject(Form("Func_Ratio_signal_foreground_%s_%d", Form("%svn_toyMC%d",MBorDtrig.Data(),itoyMC), ipt)));
		}
	}

	output->cd();
	for( int ipt = iptstart; ipt < iptend; ipt++ )
	{
		Ratio_signal_foreground_toyMC[ipt]->Write();
		h_v2_toyMC_oneptbin[ipt]->Write();
		h_v3_toyMC_oneptbin[ipt]->Write();
	}

	return;
}
