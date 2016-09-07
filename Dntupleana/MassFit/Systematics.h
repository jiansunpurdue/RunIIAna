#include <string>
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include "./../Dcand_tk_cuts.h"
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>

using namespace std;

enum vnordercentralityandmethod   { v2cent0to10SP, v2cent10to30SP, v2cent30to50SP, v2cent50to70SP, 
	v3cent0to10SP, v3cent10to30SP, v3cent30to50SP, v3cent50to70SP,
	v2cent0to10deltaphibins, v2cent10to30deltaphibins, v2cent30to50deltaphibins, v2cent50to70deltaphibins,
	v3cent0to10deltaphibins, v3cent10to30deltaphibins, v3cent30to50deltaphibins, v3cent50to70deltaphibins};

map< string, int > vntypemethodtoindex;

//absolute systematic uncertainties
typedef std::array<double, Nptbin> Row;
std::array<Row, 16> sys_bkgmass;
std::array<Row, 16> sys_effcorr;
std::array<Row, 16> sys_tkcutva;
std::array<Row, 16> sys_bkgvn;
//draw separately
std::array<Row, 16> sys_Bfeeddown;

void Initialize_Sysvalues()
{
	//#define Nptbin 15
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0, 15.0, 20.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 7 8-20 GeV ptbin 8, 9, 10  20-40 GeV pt bin 11
	//
	// systematics B feeddown
	sys_Bfeeddown[v2cent0to10SP] =  { 0., 0., 0.00, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0., 0., 0.};
	sys_Bfeeddown[v2cent10to30SP] = { 0., 0., 0.05, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0., 0., 0.};
	sys_Bfeeddown[v2cent30to50SP] = { 0., 0., 0.05, 0.020, 0.020, 0.020, 0.020, 0.020, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	
	sys_Bfeeddown[v3cent0to10SP] =  { 0., 0., 0.00, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0., 0., 0.};
	sys_Bfeeddown[v3cent10to30SP] = { 0., 0., 0.05, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_Bfeeddown[v3cent30to50SP] = { 0., 0., 0.05, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};
	
	sys_Bfeeddown[v2cent0to10deltaphibins] =  { 0., 0., 0.00, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0.035, 0., 0., 0.};
	sys_Bfeeddown[v2cent10to30deltaphibins] = { 0., 0., 0.05, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0.015, 0., 0., 0.};
	sys_Bfeeddown[v2cent30to50deltaphibins] = { 0., 0., 0.05, 0.020, 0.020, 0.020, 0.020, 0.020, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	
	sys_Bfeeddown[v3cent0to10deltaphibins] =  { 0., 0., 0.00, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0.030, 0., 0., 0.};
	sys_Bfeeddown[v3cent10to30deltaphibins] = { 0., 0., 0.05, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_Bfeeddown[v3cent30to50deltaphibins] = { 0., 0., 0.05, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};

	//SP method, absolute error
	sys_bkgmass[v2cent0to10SP] = { 0., 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v2cent0to10SP] = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v2cent0to10SP] = { 0., 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};
	sys_bkgvn[v2cent0to10SP]   = { 0., 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	sys_bkgmass[v2cent10to30SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v2cent10to30SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v2cent10to30SP] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0., 0., 0.};
	sys_bkgvn[v2cent10to30SP]   = { 0., 0., 0.060, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};

	sys_bkgmass[v2cent30to50SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v2cent30to50SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v2cent30to50SP] = { 0., 0., 0.020, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0., 0., 0.};
	sys_bkgvn[v2cent30to50SP]   = { 0., 0., 0.030, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	//#define Nptbin 15
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0, 15.0, 20.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 7 8-20 GeV ptbin 8, 9, 10  20-40 GeV pt bin 11
	sys_bkgmass[v3cent0to10SP] = { 0., 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v3cent0to10SP] = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v3cent0to10SP] = { 0., 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0., 0., 0.};
	sys_bkgvn[v3cent0to10SP]   = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};

	sys_bkgmass[v3cent10to30SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v3cent10to30SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v3cent10to30SP] = { 0., 0., 0.040, 0.015, 0.015, 0.015, 0.015, 0.015, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};
	sys_bkgvn[v3cent10to30SP]   = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	sys_bkgmass[v3cent30to50SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v3cent30to50SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v3cent30to50SP] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_bkgvn[v3cent30to50SP] =   { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};

	//#define Nptbin 15
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0, 15.0, 20.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 7 8-20 GeV ptbin 8, 9, 10  20-40 GeV pt bin 11
	sys_bkgmass[v2cent0to10deltaphibins] = { 0., 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_effcorr[v2cent0to10deltaphibins] = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v2cent0to10deltaphibins] = { 0., 0., 0., 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};

	sys_bkgmass[v2cent10to30deltaphibins] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_effcorr[v2cent10to30deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_tkcutva[v2cent10to30deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	sys_bkgmass[v2cent30to50deltaphibins] = { 0., 0., 0.015, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_effcorr[v2cent30to50deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_tkcutva[v2cent30to50deltaphibins] = { 0., 0., 0.020, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	//#define Nptbin 15
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0, 15.0, 20.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 7 8-20 GeV ptbin 8, 9, 10  20-40 GeV pt bin 11
	sys_bkgmass[v3cent0to10deltaphibins] = { 0., 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_effcorr[v3cent0to10deltaphibins] = { 0., 0., 0., 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};
	sys_tkcutva[v3cent0to10deltaphibins] = { 0., 0., 0., 0.020, 0.020, 0.020, 0.020, 0.020, 0.030, 0.030, 0.030, 0.040, 0., 0., 0.};

	sys_bkgmass[v3cent10to30deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_effcorr[v3cent10to30deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_tkcutva[v3cent10to30deltaphibins] = { 0., 0., 0.040, 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0.020, 0.020, 0.020, 0., 0., 0.};

	sys_bkgmass[v3cent30to50deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_effcorr[v3cent30to50deltaphibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_tkcutva[v3cent30to50deltaphibins] = { 0., 0., 0.040, 0.010, 0.010, 0.010, 0.010, 0.010, 0.015, 0.015, 0.015, 0.015, 0., 0., 0.};
}

void Initialize_map()
{
	vntypemethodtoindex["v2cent0to10SP"] = v2cent0to10SP;
	vntypemethodtoindex["v2cent10to30SP"] = v2cent10to30SP;
	vntypemethodtoindex["v2cent30to50SP"] = v2cent30to50SP;
	vntypemethodtoindex["v2cent50to70SP"] = v2cent50to70SP;
	
	vntypemethodtoindex["v3cent0to10SP"] = v3cent0to10SP;
	vntypemethodtoindex["v3cent10to30SP"] = v3cent10to30SP;
	vntypemethodtoindex["v3cent30to50SP"] = v3cent30to50SP;
	vntypemethodtoindex["v3cent50to70SP"] = v3cent50to70SP;
	
	vntypemethodtoindex["v2cent0to10deltaphibins"] = v2cent0to10deltaphibins;
	vntypemethodtoindex["v2cent10to30deltaphibins"] = v2cent10to30deltaphibins;
	vntypemethodtoindex["v2cent30to50deltaphibins"] = v2cent30to50deltaphibins;
	vntypemethodtoindex["v2cent50to70deltaphibins"] = v2cent50to70deltaphibins;
	
	vntypemethodtoindex["v3cent0to10deltaphibins"] = v3cent0to10deltaphibins;
	vntypemethodtoindex["v3cent10to30deltaphibins"] = v3cent10to30deltaphibins;
	vntypemethodtoindex["v3cent30to50deltaphibins"] = v3cent30to50deltaphibins;
	vntypemethodtoindex["v3cent50to70deltaphibins"] = v3cent50to70deltaphibins;
}

	//#define Nptbin 14
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 8-25 GeV ptbin 7, 8, 9, 25-40 GeV pt bin 10
	//delta phi bins method

void Calculatetotalsys( int cent_low, int cent_high, double ptstart, double ptend, TString method, TString vnorder, TH1D * h_vn, TH1D * h_vn_sys, TH1D * h_vn_relativesys)
{
	Initialize_Sysvalues();
	Initialize_map();

	string vntype = Form( "%scent%dto%d%s", vnorder.Data(), cent_low, cent_high, method.Data());
	cout << "string name: "<< vntype << endl;
	cout << " vntypemethodtoindex[vntype]: " << vntypemethodtoindex[vntype] << endl;

	if( vntype != "v2cent0to10SP" && vntype != "v2cent10to30SP" && vntype != "v2cent30to50SP" && vntype != "v2cent50to70SP"
	 && vntype != "v3cent0to10SP" && vntype != "v3cent10to30SP" && vntype != "v3cent30to50SP" && vntype != "v3cent50to70SP"
	 && vntype != "v2cent0to10deltaphibins" && vntype != "v2cent10to30deltaphibins" && vntype != "v2cent30to50deltaphibins" && vntype != "v2cent50to70deltaphibins"
	 && vntype != "v3cent0to10deltaphibins" && vntype != "v3cent10to30deltaphibins" && vntype != "v3cent30to50deltaphibins" && vntype != "v3cent50to70deltaphibins"
	 )
	{
		cout << "Wrong type!!!!!!!!!, Error!!!!!!!!!!!!, error, fail, Fail!!!!!!!!!!!!!!!" << endl;
		exit(2);
	}

	int arrayindextouse = vntypemethodtoindex[vntype];

    //histogram bin from 1
	int ptbinstart = h_vn->FindBin( ptstart+0.5 ) - 1;
	int ptbinend = h_vn->FindBin( ptend-0.5 );

	for( int ipt = ptbinstart; ipt < ptbinend; ipt++ )
	{
		double vnvalue = h_vn->GetBinContent( ipt+1 );
		
		//convert absolute error to relative error
		double sys_relative_bkgmass = sys_bkgmass[arrayindextouse][ipt]/vnvalue;
		double sys_relative_effcorr = sys_effcorr[arrayindextouse][ipt]/vnvalue;
		double sys_relative_tkcutva = sys_tkcutva[arrayindextouse][ipt]/vnvalue;
		double sys_relative_bkgvn = sys_bkgvn[arrayindextouse][ipt]/vnvalue;

		cout << " ipt: " << ipt << " sys_bkgmass: " << sys_bkgmass[arrayindextouse][ipt] << " sys_effcorr: " << sys_effcorr[arrayindextouse][ipt] << " sys_tkcutva: " << sys_tkcutva[arrayindextouse][ipt]<< " sys_bkgvn: " << sys_bkgvn[arrayindextouse][ipt] << endl;

		//sum relative systematic uncertainties
		double totalrelativesys = TMath::Sqrt( sys_relative_bkgmass*sys_relative_bkgmass + sys_relative_effcorr* sys_relative_effcorr + sys_relative_tkcutva * sys_relative_tkcutva + sys_relative_bkgvn * sys_relative_bkgvn);

		h_vn_sys->SetBinContent( ipt+1, vnvalue);
		h_vn_sys->SetBinError( ipt+1, vnvalue * totalrelativesys);

		h_vn_relativesys->SetBinContent(ipt+1,totalrelativesys);
		h_vn_relativesys->SetBinError( ipt+1, 0);
	}
}

void Calculate_sys_Bfeeddown( int cent_low, int cent_high, double ptstart, double ptend, TString method, TString vnorder, TH1D * h_vn, TGraphAsymmErrors * gr_vn_sys_Bfeeddown)
{
	Initialize_Sysvalues();
	Initialize_map();

	string vntype = Form( "%scent%dto%d%s", vnorder.Data(), cent_low, cent_high, method.Data());
	cout << "string name: "<< vntype << endl;
	cout << " vntypemethodtoindex[vntype]: " << vntypemethodtoindex[vntype] << endl;

	if( vntype != "v2cent0to10SP" && vntype != "v2cent10to30SP" && vntype != "v2cent30to50SP" && vntype != "v2cent50to70SP"
	 && vntype != "v3cent0to10SP" && vntype != "v3cent10to30SP" && vntype != "v3cent30to50SP" && vntype != "v3cent50to70SP"
	 && vntype != "v2cent0to10deltaphibins" && vntype != "v2cent10to30deltaphibins" && vntype != "v2cent30to50deltaphibins" && vntype != "v2cent50to70deltaphibins"
	 && vntype != "v3cent0to10deltaphibins" && vntype != "v3cent10to30deltaphibins" && vntype != "v3cent30to50deltaphibins" && vntype != "v3cent50to70deltaphibins"
	 )
	{
		cout << "Wrong type!!!!!!!!!, Error!!!!!!!!!!!!, error, fail, Fail!!!!!!!!!!!!!!!" << endl;
		exit(2);
	}

	int arrayindextouse = vntypemethodtoindex[vntype];

    //histogram bin from 1
	int ptbinstart = h_vn->FindBin( ptstart+0.5 ) - 1;
	int ptbinend = h_vn->FindBin( ptend-0.5 );

	for( int ipt = ptbinstart; ipt < ptbinend; ipt++ )
	{
		double vnvalue = h_vn->GetBinContent( ipt+1 );
		double sys_notrelative_Bfeeddown = sys_Bfeeddown[arrayindextouse][ipt];

		cout << " ipt: " << ipt << " sys_Bfeeddown: " << sys_notrelative_Bfeeddown << endl;

		gr_vn_sys_Bfeeddown->GetY()[ipt] = vnvalue;
		gr_vn_sys_Bfeeddown->GetEYhigh()[ipt] = sys_notrelative_Bfeeddown;
		gr_vn_sys_Bfeeddown->GetEYlow()[ipt] = sys_notrelative_Bfeeddown;

		gr_vn_sys_Bfeeddown->GetEXhigh()[ipt] = 0.5;
		gr_vn_sys_Bfeeddown->GetEXlow()[ipt] = 0.5;
	}
}
