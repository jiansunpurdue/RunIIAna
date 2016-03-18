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

#include <./../EP_resolution.h>

#define PI 3.14159265

void Draw_vn_inoutplane( TString inputfilename = "rootfiles/Raw_spectrum_inoutplane_anaDntuple_Dntuple_crab_PbPb_HIMinimumBias1to6_ForestAOD_D0_tkpt0p7eta1p5_goldenjson_01292016_Cent-0to100.root", TString trigname = "MBtrig", int cent_low = 0, int cent_high = 100, double ptlow = 1.5, double pthigh = 35.0)
{
	void Get_vn_inoutplane( TH1D * vn_inoutplane, TH1D * dNdpt_inplane, TH1D * dNdpt_outplane, double EPresolution, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0);
	TH1::SetDefaultSumw2();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

    //decide event plane resolution
    double resolution_EP_v1 = 1., resolution_EP_v2 = 1., resolution_EP_v3 = 1., resolution_EP_v4 = 1.;
    int icentbin = Decide_centbin_for_EPresolution( cent_low, cent_high);
    if( icentbin != -99 )
    {
        resolution_EP_v1 = (EPm_resolution_v1[icentbin] + EPp_resolution_v1[icentbin]) / 2.0;
        resolution_EP_v2 = (EPm_resolution_v2[icentbin] + EPp_resolution_v2[icentbin]) / 2.0;
        resolution_EP_v3 = (EPm_resolution_v3[icentbin] + EPp_resolution_v3[icentbin]) / 2.0;
        resolution_EP_v4 = (EPm_resolution_v4[icentbin] + EPp_resolution_v4[icentbin]) / 2.0;
    }
    cout << "EP resolution, v1: " << resolution_EP_v1 << " v2: " << resolution_EP_v2 << " v3: " << resolution_EP_v3 << " v4: " << resolution_EP_v4 << endl;

	TFile * inputdata = new TFile(inputfilename);

	TH1D * dNdpt_v1_inplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v1_inplane_poly3bkg");
	TH1D * dNdpt_v1_outplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v1_outplane_poly3bkg");
	TH1D * dNdpt_v2_inplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v2_inplane_poly3bkg");
	TH1D * dNdpt_v2_outplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v2_outplane_poly3bkg");
	TH1D * dNdpt_v3_inplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v3_inplane_poly3bkg");
	TH1D * dNdpt_v3_outplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v3_outplane_poly3bkg");
	TH1D * dNdpt_v4_inplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v4_inplane_poly3bkg");
	TH1D * dNdpt_v4_outplane_poly3bkg = (TH1D *) inputdata->Get("dNdpt_v4_outplane_poly3bkg");

	TH1D * v1_inoutplane = (TH1D *) dNdpt_v1_inplane_poly3bkg->Clone("v1_inoutplane");
	TH1D * v2_inoutplane = (TH1D *) dNdpt_v2_inplane_poly3bkg->Clone("v2_inoutplane");
	TH1D * v3_inoutplane = (TH1D *) dNdpt_v3_inplane_poly3bkg->Clone("v3_inoutplane");
	TH1D * v4_inoutplane = (TH1D *) dNdpt_v4_inplane_poly3bkg->Clone("v4_inoutplane");

	//Get_vn_inoutplane( v1_inoutplane, dNdpt_v1_inplane_poly3bkg, dNdpt_v1_outplane_poly3bkg, resolution_EP_v1, trigname, "v1", "v_{1}", cent_low, cent_high, ptlow, pthigh);
	Get_vn_inoutplane( v2_inoutplane, dNdpt_v2_inplane_poly3bkg, dNdpt_v2_outplane_poly3bkg, resolution_EP_v2, trigname, "v2", "v_{2}", cent_low, cent_high, ptlow, pthigh);
	Get_vn_inoutplane( v3_inoutplane, dNdpt_v3_inplane_poly3bkg, dNdpt_v3_outplane_poly3bkg, resolution_EP_v3, trigname, "v3", "v_{3}", cent_low, cent_high, ptlow, pthigh);
	//Get_vn_inoutplane( v4_inoutplane, dNdpt_v4_inplane_poly3bkg, dNdpt_v4_outplane_poly3bkg, resolution_EP_v4, trigname, "v4", "v_{4}", cent_low, cent_high, ptlow, pthigh);

	TFile * output = new TFile(Form("rootfiles/vn_inoutplane_%s_cent%dto%d.root", trigname.Data(), cent_low, cent_high),"RECREATE");
	v1_inoutplane->Write();
	v2_inoutplane->Write();
	v3_inoutplane->Write();
	v4_inoutplane->Write();
	output->Close();
}

void Get_vn_inoutplane( TH1D * vn_inoutplane, TH1D * dNdpt_inplane, TH1D * dNdpt_outplane, double EPresolution, TString trigname = "MBtrig", TString vnname = "v2", TString Ytitle = "v_{2}", int cent_low = 0, int cent_high = 100, double ptlow = 1.0, double pthigh = 35.0)
{
	double N_in, error_N_in;
	double N_out, error_N_out;
	double error_from_Nin, error_from_Nout;
	for(int ibin = 0; ibin < vn_inoutplane->GetNbinsX(); ibin++ )
	{
		N_in = dNdpt_inplane->GetBinContent(ibin+1);
		error_N_in = dNdpt_inplane->GetBinError(ibin+1);
		N_out = dNdpt_outplane->GetBinContent(ibin+1);
		error_N_out = dNdpt_outplane->GetBinError(ibin+1);

		if( vn_inoutplane->GetBinCenter( ibin+1 )  < ptlow || vn_inoutplane->GetBinCenter( ibin+1 ) > pthigh )  continue;

		if( N_in <= 0 || N_out <= 0 ) continue;

		vn_inoutplane->SetBinContent( ibin+1, (N_in - N_out)/(N_in + N_out) );
		error_from_Nin = ( 2.0 * N_out / ( ( N_in + N_out ) * ( N_in + N_out ) ) ) * ( 2.0 * N_out / ( ( N_in + N_out ) * ( N_in + N_out ) ) ) * error_N_in * error_N_in;
		error_from_Nout = ( 2.0 * N_in / ( ( N_in + N_out ) * ( N_in + N_out ) ) ) * ( 2.0 * N_in / ( ( N_in + N_out ) * ( N_in + N_out ) ) ) * error_N_out * error_N_out; 
		vn_inoutplane->SetBinError( ibin+1, TMath::Sqrt( error_from_Nin + error_from_Nout ));
	}
	vn_inoutplane->Scale(PI/4);
	vn_inoutplane->Scale(1.0/EPresolution);
	//TH1D * diff_inoutplane = (TH1D *) dNdpt_inplane->Clone("diff_inoutplane");
	//TH1D * sum_inoutplane = (TH1D *) dNdpt_inplane->Clone("sum_inoutplane");
	//diff_inoutplane->Add( dNdpt_inplane, dNdpt_outplane, 1, -1);
	//sum_inoutplane->Add( dNdpt_inplane, dNdpt_outplane, 1, 1);
	//vn_inoutplane->Divide( diff_inoutplane, sum_inoutplane, 1.0, 1.0);
	//vn_inoutplane->Scale(PI/4);
	//vn_inoutplane->Scale(1.0/EPresolution);

	TCanvas * cfg_vn = new TCanvas(Form("cfg_%s_%s", trigname.Data(), vnname.Data()));

	vn_inoutplane->GetXaxis()->SetRangeUser(ptlow+0.05, pthigh-0.05);
	vn_inoutplane->GetYaxis()->SetRangeUser(-0.2, 0.4);
	vn_inoutplane->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
	vn_inoutplane->GetYaxis()->SetTitle(Ytitle);

	vn_inoutplane->GetYaxis()->SetTitleSize(0.05);
	vn_inoutplane->GetXaxis()->SetTitleSize(0.05);

	vn_inoutplane->SetMarkerColor(2.0);
	vn_inoutplane->SetMarkerStyle(20);
	vn_inoutplane->SetMarkerSize(1.0);
	vn_inoutplane->SetLineColor(2.0);
	vn_inoutplane->Draw();

	TLatex Tl; 
	Tl.SetNDC();
	Tl.SetTextAlign(12);
	Tl.SetTextSize(0.04);
	Tl.SetTextFont(42);
	Tl.DrawLatex(0.125,0.96, "#scale[1.25]{CMS} Preliminary");
	Tl.DrawLatex(0.57,0.96, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLatex* tex;
	tex = new TLatex(0.20,0.83,"|y| < 1.0");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.20,0.78,Form("Cent. %d-%d%%", cent_low, cent_high));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

    TF1 * fun = new TF1("fun", "0.0", 0, 100);
    fun->SetLineColor(1.0);
    fun->SetLineStyle(3);
    fun->SetLineWidth(1);
    fun->Draw("same");

	cfg_vn->SaveAs(Form("Plots_vn/cfg_inoutplane_%s_%s_cent%dto%d.pdf", trigname.Data(), vnname.Data(), cent_low, cent_high));
	//cfg_vn->SaveAs(Form("Plots_vn/cfg_inoutplane_%s_%s_cent%dto%d.png", trigname.Data(), vnname.Data(), cent_low, cent_high));
}
