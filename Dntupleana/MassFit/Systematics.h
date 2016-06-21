#include <string>
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include "./../Dcand_tk_cuts.h"
using namespace std;

enum vnordercentralityandmethod   { v2cent0to10SP, v2cent10to30SP, v2cent30to50SP, v2cent50to70SP, 
	v3cent0to10SP, v3cent10to30SP, v3cent30to50SP, v3cent50to70SP,
	v2cent0to10phibins, v2cent10to30phibins, v2cent30to50phibins, v2cent50to70phibins,
	v3cent0to10phibins, v3cent10to30phibins, v3cent30to50phibins, v3cent50to70phibins};

//absolute systematic uncertainties
typedef std::array<double, Nptbin> Row;
std::array<Row, 16> sys_bkgmass;
std::array<Row, 16> sys_effcorr;
std::array<Row, 16> sys_bkgvn;

void Initialize_Sysvalues()
{

	//#define Nptbin 14
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 8-25 GeV ptbin 7, 8, 9, 25-40 GeV pt bin 10

	//SP method, absolute error
	sys_bkgmass[v2cent0to10SP] = { 0., 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v2cent0to10SP] = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_bkgvn[v2cent0to10SP]   = { 0., 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.035, 0., 0., 0.};

	sys_bkgmass[v2cent10to30SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v2cent10to30SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_bkgvn[v2cent10to30SP]   = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.025, 0., 0., 0.};

	sys_bkgmass[v2cent30to50SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v2cent30to50SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_bkgvn[v2cent30to50SP]   = { 0., 0., 0.003, 0.010, 0.010, 0.010, 0.010, 0.005, 0.005, 0.005, 0.025, 0., 0., 0.};

	//#define Nptbin 14
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 8-25 GeV ptbin 7, 8, 9, 25-40 GeV pt bin 10
	sys_bkgmass[v3cent0to10SP] = { 0., 0., 0., 0.002, 0.002, 0.002, 0.002, 0.001, 0.001, 0.001, 0.003, 0., 0., 0.};
	sys_effcorr[v3cent0to10SP] = { 0., 0., 0., 0.015, 0.015, 0.015, 0.015, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_bkgvn[v3cent0to10SP]   = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.010, 0.010, 0.010, 0.025, 0., 0., 0.};

	sys_bkgmass[v3cent10to30SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v3cent10to30SP] = { 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_bkgvn[v3cent10to30SP]   = { 0., 0., 0.050, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.030, 0., 0., 0.};

	sys_bkgmass[v3cent30to50SP] = { 0., 0., 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0., 0., 0.};
	sys_effcorr[v3cent30to50SP] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};
	sys_bkgvn[v3cent30to50SP] = { 0., 0., 0.010, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.040, 0., 0., 0.};

	//#define Nptbin 14
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 8-25 GeV ptbin 7, 8, 9, 25-40 GeV pt bin 10
	//delta phi bins method
	sys_bkgmass[v2cent0to10phibins] = { 0., 0., 0., 0.006, 0.006, 0.006, 0.006, 0.010, 0.010, 0.010, 0.040, 0., 0., 0.};
	sys_effcorr[v2cent0to10phibins] = { 0., 0., 0., 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0.005, 0., 0., 0.};

	sys_bkgmass[v2cent10to30phibins] = { 0., 0., 0.006, 0.004, 0.004, 0.004, 0.004, 0.004, 0.004, 0.004, 0.004, 0., 0., 0.};
	sys_effcorr[v2cent10to30phibins] = { 0., 0., 0.004, 0.004, 0.004, 0.004, 0.004, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	sys_bkgmass[v2cent30to50phibins] = { 0., 0., 0.020, 0.002, 0.002, 0.002, 0.002, 0.002, 0.002, 0.002, 0.004, 0., 0., 0.};
	sys_effcorr[v2cent30to50phibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.002, 0.002, 0.002, 0.002, 0., 0., 0.};

	//#define Nptbin 14
	//float ptbins[Nptbin+1]   =      { 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 6.0, 8.0, 10.0, 15.0, 25.0, 40.0, 60.0, 100.0, 200.0};
	// 1-2 GeV ptbin 2, 2-8 GeV ptbin 3, 4, 5, 6, 8-25 GeV ptbin 7, 8, 9, 25-40 GeV pt bin 10
	//delta phi bins method
	sys_bkgmass[v3cent0to10phibins] = { 0., 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_effcorr[v3cent0to10phibins] = { 0., 0., 0., 0.030, 0.030, 0.030, 0.030, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	sys_bkgmass[v3cent10to30phibins] = { 0., 0., 0.010, 0.005, 0.005, 0.005, 0.005, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
	sys_effcorr[v3cent10to30phibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};

	sys_bkgmass[v3cent30to50phibins] = { 0., 0., 0.004, 0.004, 0.004, 0.004, 0.004, 0.010, 0.010, 0.010, 0.015, 0., 0., 0.};
	sys_effcorr[v3cent30to50phibins] = { 0., 0., 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0., 0., 0.};
}

void Calculatetotalsys( int cent_low, int cent_high, int ptstart, int ptend, TString method, int vnorder, TH1D * h_vn, TH1D * h_vn_sys)
{
	sys_bkgmass[0][0] = 0;
	double totalrelativesys[Nptbin];
	int arraytouse = 999;
}
