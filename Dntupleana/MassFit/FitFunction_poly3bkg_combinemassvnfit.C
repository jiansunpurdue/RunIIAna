#include <string>
#include <vector>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TF1.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>

#include "Fit/Fitter.h"
#include "Fit/BinData.h"
#include "Fit/Chi2FCN.h"
#include "TList.h"
#include "Math/WrappedMultiTF1.h"
#include "HFitInterface.h"

extern float ptbins[Nptbin+1];
extern const double generalfitrange_masslow;
extern const double generalfitrange_masshigh;

int iparmassfit[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int iparvnfit[14] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

struct GlobalChi2 {
	GlobalChi2(  ROOT::Math::IMultiGenFunction & f1,
			ROOT::Math::IMultiGenFunction & f2) :
		fChi2_1(&f1), fChi2_2(&f2) {}

	// parameter vector is first background (in common 1 and 2)
	// and then is signal (only in 2)
	double operator() (const double *par) const {
		double p1[11];
		for (int i = 0; i < 11; ++i) p1[i] = par[iparmassfit[i] ];

		double p2[14];
		for (int i = 0; i < 14; ++i) p2[i] = par[iparvnfit[i] ];

		return (*fChi2_1)(p1) + (*fChi2_2)(p2);
	}

	const  ROOT::Math::IMultiGenFunction * fChi2_1;
	const  ROOT::Math::IMultiGenFunction * fChi2_2;
};

TF1* fit_histo_poly3bkg( bool isPbPb, int centlow, int centhigh, TH1D * histo, TH1D * h_mc_matched_signal, TH1D * h_mc_matched_kpiswapped, int ipt, TString cfgname, bool SavePdfplot = true, bool get_sig_bkg_ratio = false, TH1D * Ratio_signal_foreground = NULL, TH1D * h_vnvsmass = NULL, TH1D * h_vnvspt = NULL, TString vnorder = "v2", TString EPorSP = "SP")
{
	Double_t setparam0=100.;
	Double_t setparam1=1.8648;
	Double_t setparam2=0.03;
	Double_t setparam3=0.005;
	Double_t setparam4=0.1;
	Double_t setparam6=0.1;
	Double_t fixparam1=1.8648;

	double fit_range_low = generalfitrange_masslow;
	double fit_range_high = generalfitrange_masshigh;
	double histomassbinsize = histo->GetBinWidth(10);

	float ptmin = ptbins[ipt];
	float ptmax = ptbins[ipt+1];

	TH1F* histo_copy_nofitfun = ( TH1F * ) histo->Clone("histo_copy_nofitfun");
	TH1F* histo_massfit = ( TH1F * ) histo->Clone("histo_massfit");

	TCanvas* cfg= new TCanvas(Form("cfg_poly3bkg_%s_%d",cfgname.Data(),ipt),Form("cfg_poly3bkg_%s_%d",cfgname.Data(),ipt),600,600);

    gPad->SetRightMargin(0.043);
    gPad->SetLeftMargin(0.18);
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.145);

	TF1* f = new TF1(Form("f_%s_%d",cfgname.Data(),ipt),"[0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])) + [7] + [8]*x + [9]*x*x + [10]*x*x*x", fit_range_low, fit_range_high);

	f->SetParLimits(8,-1000,1000);
	f->SetParLimits(3,0.001,0.05);
	f->SetParLimits(2,0.01,0.1);
	f->SetParLimits(6,0.02,0.2);
	f->SetParLimits(5,0,1);
	f->SetParLimits(4,0,1);

	f->SetParameter(0,setparam0);
	f->SetParameter(1,setparam1);
	f->SetParameter(2,setparam2);
	f->SetParameter(3,setparam3);
	f->SetParameter(4,setparam4);

	f->FixParameter(6,setparam6);
	f->FixParameter(5,1);
	f->FixParameter(1,fixparam1);
	f->FixParameter(7,0);
	f->FixParameter(8,0);
	f->FixParameter(9,0);
	f->FixParameter(10,0);

	h_mc_matched_signal->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"q","",fit_range_low,fit_range_high);
	h_mc_matched_signal->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"q","",fit_range_low,fit_range_high);
	f->ReleaseParameter(1);
	h_mc_matched_signal->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_signal->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_signal->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L m","",fit_range_low,fit_range_high);

	f->FixParameter(1,f->GetParameter(1));
	f->FixParameter(2,f->GetParameter(2));
	f->FixParameter(3,f->GetParameter(3));
	f->FixParameter(4,f->GetParameter(4));
	f->FixParameter(5,0);
	f->ReleaseParameter(6);
	f->SetParameter(6,setparam6);

	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L m","",fit_range_low,fit_range_high);

	f->FixParameter(5,h_mc_matched_signal->Integral(0,1000)/(h_mc_matched_kpiswapped->Integral(0,1000)+h_mc_matched_signal->Integral(0,1000)));
	f->FixParameter(6,f->GetParameter(6));
	f->ReleaseParameter(7);
	f->ReleaseParameter(8);
	f->ReleaseParameter(9);
	f->ReleaseParameter(10);

	f->SetLineColor(kRed);

	histo_massfit->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"q","",fit_range_low,fit_range_high);
	histo_massfit->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"q","",fit_range_low,fit_range_high);
	f->ReleaseParameter(1);
	histo_massfit->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	histo_massfit->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	histo_massfit->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	histo_massfit->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L m","",fit_range_low,fit_range_high);

	//begin combine fit
	TF1* fmass_combinemassvnfit = new TF1(Form("fmass_combinemassvnfit_%s_%d",cfgname.Data(),ipt),"[0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])) + [7] + [8]*x + [9]*x*x + [10]*x*x*x", fit_range_low, fit_range_high);

	TF1* fvn_combinemassvnfit = new TF1(Form("fvn_combinemassvnfit_%s_%d",cfgname.Data(),ipt),"( ([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])))/([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])) + [7] + [8]*x + [9]*x*x + [10]*x*x*x) ) * [11] + ( 1.0 - ( ([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])))/([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])) + [7] + [8]*x + [9]*x*x + [10]*x*x*x) ) ) * ( [12] + [13] * x)", fit_range_low, fit_range_high);

	ROOT::Math::WrappedMultiTF1 wfmass_combinemassvnfit(*fmass_combinemassvnfit,1);
	ROOT::Math::WrappedMultiTF1 wfvn_combinemassvnfit(*fvn_combinemassvnfit,1);

	ROOT::Fit::DataOptions opt;
	ROOT::Fit::DataRange range_massfit;
	// set the data range
	range_massfit.SetRange(fit_range_low,fit_range_high);
	ROOT::Fit::BinData datamass(opt,range_massfit);
	ROOT::Fit::FillData(datamass, histo);

	ROOT::Fit::DataRange range_vnfit;
	range_vnfit.SetRange(fit_range_low,fit_range_high);
	ROOT::Fit::BinData datavn(opt,range_vnfit);
	ROOT::Fit::FillData(datavn, h_vnvsmass);

	ROOT::Fit::Chi2Function chi2_B(datamass, wfmass_combinemassvnfit);
	ROOT::Fit::Chi2Function chi2_SB(datavn, wfvn_combinemassvnfit);

	GlobalChi2 globalChi2(chi2_B, chi2_SB);

	ROOT::Fit::Fitter fitter;

	const int Npar = 14;
	double par0[Npar];
	for( int ipar = 0; ipar < f->GetNpar(); ipar++ )
		par0[ipar] = f->GetParameter(ipar);
	par0[11] = 0.05;
	par0[12] = 0.05;
	par0[13] = 0.05;

	// create before the parameter settings in order to fix or set range on them
	fitter.Config().SetParamsSettings(Npar,par0);
	// fix parameter
	fitter.Config().ParSettings(2).Fix();
	fitter.Config().ParSettings(3).Fix();
	fitter.Config().ParSettings(4).Fix();
	fitter.Config().ParSettings(5).Fix();
	fitter.Config().ParSettings(6).Fix();
	// set limits on the third and 4-th parameter
	fitter.Config().ParSettings(1).SetLimits(1.7, 2.0);
	//fitter.Config().ParSettings(3).SetStepSize(5);

	fitter.Config().MinimizerOptions().SetPrintLevel(0);
	fitter.Config().SetMinimizer("Minuit2","Migrad");

	// fit FCN function directly
	// (specify optionally data size and flag to indicate that is a chi2 fit)
	fitter.FitFCN(Npar,globalChi2,0,datamass.Size()+datavn.Size(),true);
	ROOT::Fit::FitResult result = fitter.Result();
	result.Print(std::cout);

	fmass_combinemassvnfit->SetFitResult( result, iparmassfit);
	fmass_combinemassvnfit->SetRange(range_massfit().first, range_massfit().second);
	fmass_combinemassvnfit->SetLineColor(kRed);
	histo->GetListOfFunctions()->Add(fmass_combinemassvnfit);

	fvn_combinemassvnfit->SetFitResult( result, iparvnfit);
	fvn_combinemassvnfit->SetRange(range_vnfit().first, range_vnfit().second);
	fvn_combinemassvnfit->SetLineColor(6.0);
	fvn_combinemassvnfit->SetLineStyle(2);
	h_vnvsmass->GetListOfFunctions()->Add(fvn_combinemassvnfit);

	h_vnvspt->SetBinContent( ipt+1, fvn_combinemassvnfit->GetParameter(11));
	h_vnvspt->SetBinError( ipt+1, fvn_combinemassvnfit->GetParError(11));

	TCanvas* cfg_massfit_combinemassvn = new TCanvas(Form("cfg_poly3bkg_massfit_combinemassvn_%s_%d_%s_%s",cfgname.Data(),ipt,vnorder.Data(),EPorSP.Data()),Form("cfg_poly3bkg_massfit_combinemassvn_%s_%d_%s_%s",cfgname.Data(),ipt,vnorder.Data(),EPorSP.Data()),600,600);

    gPad->SetRightMargin(0.043);
    gPad->SetLeftMargin(0.18);
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.145);

	histo->SetXTitle("m_{#piK} (GeV/c^{2})");
	histo->SetYTitle("Entries / (5 MeV/c^{2})");
	histo->GetXaxis()->CenterTitle();
	histo->GetYaxis()->CenterTitle();
	//histo->SetAxisRange(0,histo->GetMaximum()*1.4*1.2,"Y");
	histo->GetXaxis()->SetRangeUser(fit_range_low+0.0001,fit_range_high-0.0001);
	histo->GetXaxis()->SetTitleOffset(1.3);
	histo->GetYaxis()->SetTitleOffset(1.8);
	histo->GetXaxis()->SetLabelOffset(0.007);
	histo->GetYaxis()->SetLabelOffset(0.007);
	histo->GetXaxis()->SetTitleSize(0.045);
	histo->GetYaxis()->SetTitleSize(0.045);
	histo->GetXaxis()->SetTitleFont(42);
	histo->GetYaxis()->SetTitleFont(42);
	histo->GetXaxis()->SetLabelFont(42);
	histo->GetYaxis()->SetLabelFont(42);
	histo->GetXaxis()->SetLabelSize(0.04);
	histo->GetYaxis()->SetLabelSize(0.04);
	histo->SetMarkerSize(0.8);
	histo->SetMarkerStyle(20);
	histo->SetStats(0);
	histo->Draw("e");
	
	TF1* background = new TF1(Form("background_%s_%d",cfgname.Data(),ipt),"[0]+[1]*x+[2]*x*x+[3]*x*x*x");
	background->SetParameter(0,fmass_combinemassvnfit->GetParameter(7));
	background->SetParameter(1,fmass_combinemassvnfit->GetParameter(8));
	background->SetParameter(2,fmass_combinemassvnfit->GetParameter(9));
	background->SetParameter(3,fmass_combinemassvnfit->GetParameter(10));
	background->SetLineColor(4);
	background->SetRange(fit_range_low,fit_range_high);
	background->SetLineStyle(2);

	TF1* mass = new TF1(Form("fmass_%s_%d",cfgname.Data(),ipt),"[0]*([5]*([4]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3])))");
	mass->SetParameters(fmass_combinemassvnfit->GetParameter(0),fmass_combinemassvnfit->GetParameter(1),fmass_combinemassvnfit->GetParameter(2),fmass_combinemassvnfit->GetParameter(3),fmass_combinemassvnfit->GetParameter(4),fmass_combinemassvnfit->GetParameter(5));
	mass->SetParError(0,fmass_combinemassvnfit->GetParError(0));
	mass->SetParError(1,fmass_combinemassvnfit->GetParError(1));
	mass->SetParError(2,fmass_combinemassvnfit->GetParError(2));
	mass->SetParError(3,fmass_combinemassvnfit->GetParError(3));
	mass->SetParError(4,fmass_combinemassvnfit->GetParError(4));
	mass->SetParError(5,fmass_combinemassvnfit->GetParError(5));
	mass->SetFillColor(kOrange-3);
	mass->SetFillStyle(3002);
	mass->SetLineColor(kOrange-3);
	mass->SetLineWidth(3);
	mass->SetLineStyle(2);

	TF1* massSwap = new TF1(Form("fmassSwap_%s_%d",cfgname.Data(),ipt),"[0]*(1-[2])*Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3])");
	massSwap->SetParameters(fmass_combinemassvnfit->GetParameter(0),fmass_combinemassvnfit->GetParameter(1),fmass_combinemassvnfit->GetParameter(5),fmass_combinemassvnfit->GetParameter(6));
	massSwap->SetParError(0,fmass_combinemassvnfit->GetParError(0));
	massSwap->SetParError(1,fmass_combinemassvnfit->GetParError(1));
	massSwap->SetParError(2,fmass_combinemassvnfit->GetParError(5));
	massSwap->SetParError(3,fmass_combinemassvnfit->GetParError(6));
	massSwap->SetFillColor(kGreen+4);
	massSwap->SetFillStyle(3005);
	massSwap->SetLineColor(kGreen+4);
	massSwap->SetLineWidth(3);
	massSwap->SetLineStyle(1);

	background->Draw("same");   
	mass->SetRange(fit_range_low,fit_range_high);	
	mass->Draw("same");
	massSwap->SetRange(fit_range_low,fit_range_high);
	massSwap->Draw("same");
	f->Draw("same");

	Double_t yield = mass->Integral(fit_range_low,fit_range_high)/histomassbinsize;
	Double_t yieldErr = mass->Integral(fit_range_low,fit_range_high)/histomassbinsize*mass->GetParError(0)/mass->GetParameter(0);

	TLegend* leg = new TLegend(0.65,0.58,0.82,0.88,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(histo,"Data","pl");
	leg->AddEntry(fmass_combinemassvnfit,"Fit","l");
	leg->AddEntry(mass,"D^{0}+#bar{D^{#lower[0.2]{0}}} Signal","f");
	leg->AddEntry(massSwap,"K-#pi swapped","f");
	leg->AddEntry(background,"Combinatorial","l");
	leg->Draw("same");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.05);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.18,0.93, "#font[61]{CMS} #scale[0.8]{Preliminary}");
	if( isPbPb )
		Tl.DrawLatex(0.61,0.93, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");
	else
		Tl.DrawLatex(0.65,0.93, "#scale[0.8]{pp #sqrt{s_{NN}} = 5.02 TeV}");

	TLatex* tex;

	if( isPbPb )
	{
		tex = new TLatex(0.22,0.83,"|y| < 1.0");
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();

		tex = new TLatex(0.22,0.78,Form("Cent. %d-%d%%", centlow, centhigh));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();

		tex = new TLatex(0.22,0.73,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();

		tex = new TLatex(0.22,0.68,Form("N_{sig}: %d #pm %d",int(yield),int(yieldErr)));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();
	}
	else
	{
		tex = new TLatex(0.22,0.83,"|y| < 1.0");
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();

		tex = new TLatex(0.22,0.78,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();

		tex = new TLatex(0.22,0.73,Form("N_{sig}: %d #pm %d",int(yield),int(yieldErr)));
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetLineWidth(2);
		tex->Draw();
	}

	histo_copy_nofitfun->Draw("esame");

	if( get_sig_bkg_ratio )
	{
		for(int ibin = 0; ibin < histo->GetNbinsX(); ibin++)
		{
			double foreground = 0.;
			double signal = 0.;
			double ratio = 0.;
			double ratioError = 999.;

			double massbinleftedge = massmin + histomassbinsize * ibin;
			double massbinrightedge = massmin + histomassbinsize * (ibin+1);

			if( massbinleftedge > (fit_range_low - 0.0002) && massbinrightedge < (fit_range_high + 0.0002) )
			{
				foreground = f->Integral(massbinleftedge, massbinrightedge)/histomassbinsize;
				//foregroundErr = f->IntegralError(massbinleftedge, massbinrightedge)/histomassbinsize;
				//foreground =  histo->Integral(ibin+1, ibin+1);
				signal = mass->Integral(massbinleftedge, massbinrightedge)/histomassbinsize + massSwap->Integral(massbinleftedge, massbinrightedge)/histomassbinsize;
				//signal = mass->Integral(massbinleftedge, massbinrightedge)/histomassbinsize;
				//signal = foreground - background->Integral(massbinleftedge, massbinrightedge)/histomassbinsize;
				//signalErr = signal * yieldErr/yield;
				if( foreground > 0 )
				{
					ratio = signal/foreground;
					ratioError = TMath::Sqrt( foreground * ratio * (1.0 - ratio) ) / foreground;
				}
				else
				{
					ratio = 0.5;
					ratioError = 0.5;
				}
			}
			else
			{
				ratio = 0.0;
				ratioError = 1.0;
			}

			Ratio_signal_foreground->SetBinContent(ibin+1, ratio);
			Ratio_signal_foreground->SetBinError(ibin+1, ratioError);
		}

		TF1* Func_Ratio_signal_foreground = new TF1(Form("Func_Ratio_signal_foreground_%s_%d",cfgname.Data(),ipt),"([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])))/([0]*([5]*([4]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[4])*TMath::Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3]))+(1-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6])) + [7] + [8]*x + [9]*x*x + [10]*x*x*x)", generalfitrange_masslow, generalfitrange_masshigh);
		for( int ipar = 0; ipar < 11; ipar++ )
		{
			Func_Ratio_signal_foreground->SetParameter( ipar, fmass_combinemassvnfit->GetParameter(ipar));
			Func_Ratio_signal_foreground->SetParError(ipar, fmass_combinemassvnfit->GetParError(ipar));
		}
		Func_Ratio_signal_foreground->SetLineColor(2.0);
		Ratio_signal_foreground->GetListOfFunctions()->Add(Func_Ratio_signal_foreground);
	}

	if(isPbPb && SavePdfplot)
		cfg_massfit_combinemassvn->SaveAs(Form("Plots_vn/combinemassvnfit/DMass_combinemassvnfit_isPbPb%d_%s_cent%dto%d_%d_%s_%s_poly3bkg.pdf", isPbPb, cfgname.Data(), centlow, centhigh, ipt, vnorder.Data(),EPorSP.Data()));

	TCanvas* cfg_vnfit_combinemassvn = new TCanvas(Form("cfg_poly3bkg_vnfit_combinemassvn_%s_%d_%s_%s",cfgname.Data(),ipt,vnorder.Data(),EPorSP.Data()),Form("cfg_poly3bkg_vnfit_combinemassvn_%s_%d_%s_%s",cfgname.Data(),ipt,vnorder.Data(),EPorSP.Data()),600,600);

	h_vnvsmass->GetYaxis()->SetRangeUser(-0.2, 0.6);
	if( vnorder == "v2") h_vnvsmass->GetYaxis()->SetTitle("v_{2}");
	if( vnorder == "v3") h_vnvsmass->GetYaxis()->SetTitle("v_{3}");
	h_vnvsmass->GetXaxis()->SetTitle("m_{#piK} (GeV/c^{2})");
	h_vnvsmass->GetXaxis()->SetTitleSize(0.05);
	h_vnvsmass->GetYaxis()->SetTitleSize(0.05);

	h_vnvsmass->SetMarkerColor(6.0);
	h_vnvsmass->SetLineColor(6.0);
	h_vnvsmass->SetMarkerStyle(22);
	h_vnvsmass->SetMarkerSize(1.3);
	h_vnvsmass->Draw();

    TLatex Tl2; 
    Tl2.SetNDC();
    Tl2.SetTextAlign(12);
    Tl2.SetTextSize(0.05);
    Tl2.SetTextFont(42);
    Tl2.DrawLatex(0.125,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
    Tl2.DrawLatex(0.57,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

    tex = new TLatex(0.18,0.83,"|y| < 1.0");
    tex->SetNDC();
    tex->SetTextFont(42);
    tex->SetTextSize(0.04);
    tex->SetLineWidth(2);
    tex->Draw();

    tex = new TLatex(0.18,0.78,Form("Cent. %d-%d%%", centlow, centhigh));
    tex->SetNDC();
    tex->SetTextFont(42);
    tex->SetTextSize(0.04);
    tex->SetLineWidth(2);
    tex->Draw();

    tex = new TLatex(0.18,0.73,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
    tex->SetNDC();
    tex->SetTextFont(42);
    tex->SetTextSize(0.04);
    tex->SetLineWidth(2);
    tex->Draw();

    if( vnorder == "v2" ) 
        tex = new TLatex(0.55,0.83,Form("v_{2}^{sig} = %.3f #pm %.3f",fvn_combinemassvnfit->GetParameter(11), fvn_combinemassvnfit->GetParError(11)));
    else if( vnorder == "v3" )
        tex = new TLatex(0.55,0.83,Form("v_{3}^{sig} = %.3f #pm %.3f",fvn_combinemassvnfit->GetParameter(11), fvn_combinemassvnfit->GetParError(11)));

    tex->SetNDC();
    tex->SetTextFont(42);
    tex->SetTextSize(0.04);
    tex->SetLineWidth(2);
    tex->Draw();
	
	if(isPbPb && SavePdfplot)
		cfg_vnfit_combinemassvn->SaveAs(Form("Plots_vn/combinemassvnfit/cfg_vnfit_combinemassvn_%s_cent%dto%d_%d_%s_%s_poly3bkg.pdf",cfgname.Data(),centlow,centhigh,ipt,vnorder.Data(),EPorSP.Data()));

	return mass;
}
