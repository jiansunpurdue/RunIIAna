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

extern float ptbins[Nptbin+1];
extern const double generalfitrange_masslow;
extern const double generalfitrange_masshigh;

TF1* fit_histo_poly2bkg_floatwidth( bool isPbPb, int centlow, int centhigh, TH1D * histo, TH1D * h_mc_matched_signal, TH1D * h_mc_matched_kpiswapped, int ipt, TString cfgname, bool get_sig_bkg_ratio = false, TH1D * Ratio_signal_foreground = NULL)
{
	Double_t setparam0=100.;
	Double_t setparam1=1.8648;
	Double_t setparam2=0.03;
	Double_t setparam3=0.005;
	Double_t setparam4=0.1;
	Double_t setparam7=0.1;
	Double_t fixparam1=1.8648;

	double fit_range_low = generalfitrange_masslow;
	double fit_range_high = generalfitrange_masshigh;
	double histomassbinsize = histo->GetBinWidth(10);

	float ptmin = ptbins[ipt];
	float ptmax = ptbins[ipt+1];

	TH1F* histo_copy_nofitfun = ( TH1F * ) histo->Clone("histo_copy_nofitfun");
	TCanvas* cfg= new TCanvas(Form("cfg_poly2bkg_floatwidth_%s_%d",cfgname.Data(),ipt),Form("cfg_poly2bkg_floatwidth_%s_%d",cfgname.Data(),ipt),600,600);

	TF1* f = new TF1(Form("f_%s_%d",cfgname.Data(),ipt),"[0]*([5]*([4]*TMath::Gaus(x,[1],[2]*(1.0 +[6]))/(sqrt(2*3.14159)*[2]*(1.0 +[6]))+(1-[4])*TMath::Gaus(x,[1],[3]*(1.0 +[6]))/(sqrt(2*3.14159)*[3]*(1.0 +[6])))+(1-[5])*TMath::Gaus(x,[1],[7])/(sqrt(2*3.14159)*[7])) + [8] + [9]*x + [10]*x*x", fit_range_low, fit_range_high);


	f->SetParLimits(9,-1000,1000);
	f->SetParLimits(3,0.001,0.05);
	f->SetParLimits(2,0.01,0.1);
	f->SetParLimits(7,0.02,0.2);
	f->SetParLimits(5,0,1);
	f->SetParLimits(4,0,1);

	f->SetParameter(0,setparam0);
	f->SetParameter(1,setparam1);
	f->SetParameter(2,setparam2);
	f->SetParameter(3,setparam3);
	f->SetParameter(4,setparam4);

	f->FixParameter(7,setparam7);
	f->FixParameter(5,1);
	f->FixParameter(1,fixparam1);
	f->FixParameter(8,0);
	f->FixParameter(9,0);
	f->FixParameter(10,0);
	f->FixParameter(6,0);

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
	f->ReleaseParameter(7);
	f->SetParameter(7,setparam7);

	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	h_mc_matched_kpiswapped->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L m","",fit_range_low,fit_range_high);

	f->FixParameter(5,h_mc_matched_signal->Integral(0,1000)/(h_mc_matched_kpiswapped->Integral(0,1000)+h_mc_matched_signal->Integral(0,1000)));
	f->FixParameter(7,f->GetParameter(7));
	f->ReleaseParameter(8);
	f->ReleaseParameter(9);
	f->ReleaseParameter(10);

	f->SetLineColor(kRed);

	histo->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"q","",fit_range_low,fit_range_high);
	histo->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"q","",fit_range_low,fit_range_high);
	f->ReleaseParameter(1);
	////Release Parameter 6 to float signal width
	f->ReleaseParameter(6);
	f->SetParameter(6,0);
	f->SetParLimits(6,-1.0,1.0);
	histo->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	histo->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	histo->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L q","",fit_range_low,fit_range_high);
	histo->Fit(Form("f_%s_%d",cfgname.Data(),ipt),"L m","",fit_range_low,fit_range_high);

	TF1* background = new TF1(Form("background_%s_%d",cfgname.Data(),ipt),"[0]+[1]*x+[2]*x*x");
	background->SetParameter(0,f->GetParameter(8));
	background->SetParameter(1,f->GetParameter(9));
	background->SetParameter(2,f->GetParameter(10));
	background->SetLineColor(4);
	background->SetRange(fit_range_low,fit_range_high);
	background->SetLineStyle(2);

	TF1* mass = new TF1(Form("fmass_%s_%d",cfgname.Data(),ipt),"[0]*([5]*([4]*Gaus(x,[1],[2]*(1.0 +[6]))/(sqrt(2*3.14159)*[2]*(1.0 +[6]))+(1-[4])*Gaus(x,[1],[3]*(1.0 +[6]))/(sqrt(2*3.14159)*[3]*(1.0 +[6]))))");
	mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(3),f->GetParameter(4),f->GetParameter(5),f->GetParameter(6));
	mass->SetParError(0,f->GetParError(0));
	mass->SetParError(1,f->GetParError(1));
	mass->SetParError(2,f->GetParError(2));
	mass->SetParError(3,f->GetParError(3));
	mass->SetParError(4,f->GetParError(4));
	mass->SetParError(5,f->GetParError(5));
	mass->SetParError(6,f->GetParError(6));
	mass->SetFillColor(kOrange-3);
	mass->SetFillStyle(3002);
	mass->SetLineColor(kOrange-3);
	mass->SetLineWidth(3);
	mass->SetLineStyle(2);

	TF1* massSwap = new TF1(Form("fmassSwap_%s_%d",cfgname.Data(),ipt),"[0]*(1-[2])*Gaus(x,[1],[3])/(sqrt(2*3.14159)*[3])");
	massSwap->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(5),f->GetParameter(7));
	massSwap->SetParError(0,f->GetParError(0));
	massSwap->SetParError(1,f->GetParError(1));
	massSwap->SetParError(2,f->GetParError(5));
	massSwap->SetParError(3,f->GetParError(7));
	massSwap->SetFillColor(kGreen+4);
	massSwap->SetFillStyle(3005);
	massSwap->SetLineColor(kGreen+4);
	massSwap->SetLineWidth(3);
	massSwap->SetLineStyle(1);

	histo->SetXTitle("m_{#piK} (GeV/c^{2})");
	histo->SetYTitle("Entries / (5 MeV/c^{2})");
	histo->GetXaxis()->CenterTitle();
	histo->GetYaxis()->CenterTitle();
	histo->SetAxisRange(0,histo->GetMaximum()*1.4*1.2,"Y");
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
	leg->AddEntry(f,"Fit","l");
	leg->AddEntry(mass,"D^{0}+#bar{D^{#lower[0.2]{0}}} Signal","f");
	leg->AddEntry(massSwap,"K-#pi swapped","f");
	leg->AddEntry(background,"Combinatorial","l");
	leg->Draw("same");

	TLatex Tl;
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.05);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.18,0.965, "#font[61]{CMS} #scale[0.8]{Preliminary}");
	if( isPbPb )
		Tl.DrawLatex(0.61,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");
	else
		Tl.DrawLatex(0.65,0.965, "#scale[0.8]{pp #sqrt{s_{NN}} = 5.02 TeV}");

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
				//foreground =  histo->Integral(ibin, ibin);
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

		TF1* Func_Ratio_signal_foreground = new TF1(Form("Func_Ratio_signal_foreground_%s_%d",cfgname.Data(),ipt),"([0]*([5]*([4]*TMath::Gaus(x,[1],[2]*(1.0 +[6]))/(sqrt(2*3.14159)*[2]*(1.0 +[6]))+(1-[4])*TMath::Gaus(x,[1],[3]*(1.0 +[6]))/(sqrt(2*3.14159)*[3]*(1.0 +[6])))+(1-[5])*TMath::Gaus(x,[1],[7])/(sqrt(2*3.14159)*[7])))/([0]*([5]*([4]*TMath::Gaus(x,[1],[2]*(1.0 +[6]))/(sqrt(2*3.14159)*[2]*(1.0 +[6]))+(1-[4])*TMath::Gaus(x,[1],[3]*(1.0 +[6]))/(sqrt(2*3.14159)*[3]*(1.0 +[6])))+(1-[5])*TMath::Gaus(x,[1],[7])/(sqrt(2*3.14159)*[7])) + [8] + [9]*x + [10]*x*x)", generalfitrange_masslow, generalfitrange_masshigh);
		for( int ipar = 0; ipar < 11; ipar++ )
		{
			Func_Ratio_signal_foreground->SetParameter( ipar, f->GetParameter(ipar));
			Func_Ratio_signal_foreground->SetParError(ipar, f->GetParError(ipar));
		}
		Func_Ratio_signal_foreground->SetLineColor(2.0);
		Ratio_signal_foreground->GetListOfFunctions()->Add(Func_Ratio_signal_foreground);
	}

	if(isPbPb)
	{
		cfg->SaveAs(Form("Massfitplots/PbPb/DMass_isPbPb%d_%s_cent%dto%d_%d_poly2bkg_floatwidth.pdf", isPbPb, cfgname.Data(), centlow, centhigh, ipt));
		//cfg->SaveAs(Form("Massfitplots/PbPb/DMass_isPbPb%d_%s_cent%dto%d_%d_poly2bkg_floatwidth.png", isPbPb, cfgname.Data(), centlow, centhigh, ipt));
	}
	else
	{
		cfg->SaveAs(Form("Massfitplots/pp/DMass_isPbPb%d_%s_cent%dto%d_%d_poly2bkg_floatwidth.pdf", isPbPb, cfgname.Data(), centlow, centhigh, ipt));
		//cfg->SaveAs(Form("Massfitplots/pp/DMass_isPbPb%d_%s_cent%dto%d_%d_poly2bkg_floatwidth.png", isPbPb, cfgname.Data(), centlow, centhigh, ipt));
	}

	return mass;
}
