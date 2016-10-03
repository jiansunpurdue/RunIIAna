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
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TMultiGraph.h>

#define NAlicepoints 6

TGraphErrors * gr_v2_Alice_stat[3];
TGraphErrors * gr_v2_Alice_sys[3];
TGraphAsymmErrors * gr_v2_Alice_sys_np[3];

void Set_Alice_result()
//void Alice_results()
{
	double pt_center_Alice[NAlicepoints] = { 2.5, 3.5, 5.0, 7.0, 10.0, 14.0};
	double error_pt_Alice[NAlicepoints] = { 0.5, 0.5, 1.0, 1.0, 2.0, 2.0};
	double error2_pt_Alice[NAlicepoints] = { 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
	
	double v2_cent0to10_Alice[NAlicepoints] = { 0.131, 0.086, 0.08, 0.098, -0.022, 0.251};
	double stat_v2_cent0to10_Alice[NAlicepoints] = { 0.053, 0.052, 0.05, 0.071, 0.064, 0.106};
	double sys_v2_cent0to10_Alice[NAlicepoints] = { 0.043, 0.019, 0.03, 0.039, 0.074, 0.043};
	double uppersys_np_v2_cent0to10_Alice[NAlicepoints] = { 0.075, 0.046, 0.04, 0.05, 0.0, 0.136};
	double lowersys_np_v2_cent0to10_Alice[NAlicepoints] = { 0.0, 0.0, 0.0, 0.0, -0.013, 0.0};

	gr_v2_Alice_stat[0] = new TGraphErrors( NAlicepoints, pt_center_Alice, v2_cent0to10_Alice, error_pt_Alice, stat_v2_cent0to10_Alice);
	gr_v2_Alice_sys[0] = new TGraphErrors( NAlicepoints, pt_center_Alice, v2_cent0to10_Alice, error2_pt_Alice, sys_v2_cent0to10_Alice);
	gr_v2_Alice_sys_np[0] = new TGraphAsymmErrors( NAlicepoints, pt_center_Alice, v2_cent0to10_Alice, error2_pt_Alice, error2_pt_Alice, lowersys_np_v2_cent0to10_Alice, uppersys_np_v2_cent0to10_Alice);

	double v2_cent10to30_Alice[NAlicepoints] = { 0.134, 0.139, 0.139, 0.115, -0.016, 0.047};
	double stat_v2_cent10to30_Alice[NAlicepoints] = { 0.057, 0.057, 0.053, 0.083, 0.08, 0.107};
	double sys_v2_cent10to30_Alice[NAlicepoints] = { 0.017, 0.047, 0.03, 0.053, 0.057, 0.052};
	double uppersys_np_v2_cent10to30_Alice[NAlicepoints] = { 0.067, 0.059, 0.063, 0.057, 0.0, 0.027};
	double lowersys_np_v2_cent10to30_Alice[NAlicepoints] = { 0.0, 0.0, 0.0, 0.0, -0.008};

	gr_v2_Alice_stat[1] = new TGraphErrors( NAlicepoints, pt_center_Alice, v2_cent10to30_Alice, error_pt_Alice, stat_v2_cent10to30_Alice);
	gr_v2_Alice_sys[1] = new TGraphErrors( NAlicepoints, pt_center_Alice, v2_cent10to30_Alice, error2_pt_Alice, sys_v2_cent10to30_Alice);
	gr_v2_Alice_sys_np[1] = new TGraphAsymmErrors( NAlicepoints, pt_center_Alice, v2_cent10to30_Alice, error2_pt_Alice, error2_pt_Alice, lowersys_np_v2_cent10to30_Alice, uppersys_np_v2_cent10to30_Alice);

	double v2_cent30to50_Alice[NAlicepoints] = { 0.164, 0.202, 0.211, 0.129, 0.421, -0.145};
	double stat_v2_cent30to50_Alice[NAlicepoints] = { 0.065, 0.058, 0.055, 0.084, 0.083, 0.131};
	double sys_v2_cent30to50_Alice[NAlicepoints] = { 0.058, 0.028, 0.021, 0.03, 0.054, 0.144};
	double uppersys_np_v2_cent30to50_Alice[NAlicepoints] = { 0.094, 0.109, 0.106, 0.066, 0.236, 0.0};
	double lowersys_np_v2_cent30to50_Alice[NAlicepoints] = { 0.0, 0.0, 0.0, 0.0, 0.0, -0.079};

	gr_v2_Alice_stat[2] = new TGraphErrors( NAlicepoints, pt_center_Alice, v2_cent30to50_Alice, error_pt_Alice, stat_v2_cent30to50_Alice);
	gr_v2_Alice_sys[2] = new TGraphErrors( NAlicepoints, pt_center_Alice, v2_cent30to50_Alice, error2_pt_Alice, sys_v2_cent30to50_Alice);
	gr_v2_Alice_sys_np[2] = new TGraphAsymmErrors( NAlicepoints, pt_center_Alice, v2_cent30to50_Alice, error2_pt_Alice, error2_pt_Alice, lowersys_np_v2_cent30to50_Alice, uppersys_np_v2_cent30to50_Alice);

	//set plotting style
	for( int ibin = 0; ibin < 3; ibin++ )
	{
		gr_v2_Alice_stat[ibin]->SetLineColor(1.0);
		gr_v2_Alice_stat[ibin]->SetMarkerColor(1.0);
		gr_v2_Alice_stat[ibin]->SetMarkerStyle(24);
		gr_v2_Alice_stat[ibin]->SetMarkerSize(1.0);
		
		gr_v2_Alice_sys[ibin]->SetLineColor(1.0);
		gr_v2_Alice_sys[ibin]->SetMarkerColor(1.0);
		gr_v2_Alice_sys[ibin]->SetMarkerStyle(24);
		gr_v2_Alice_sys[ibin]->SetMarkerSize(1.0);
		gr_v2_Alice_sys[ibin]->SetFillStyle(0);
		gr_v2_Alice_sys[ibin]->SetLineWidth(1);
		
		gr_v2_Alice_sys_np[ibin]->SetMarkerColor(1.0);
		gr_v2_Alice_sys_np[ibin]->SetMarkerStyle(24);
		gr_v2_Alice_sys_np[ibin]->SetMarkerSize(1.0);
		gr_v2_Alice_sys_np[ibin]->SetFillStyle(1001);
		gr_v2_Alice_sys_np[ibin]->SetLineColor(16);
		gr_v2_Alice_sys_np[ibin]->SetFillColor(16);
	}
}
//Prompt D^0 meson v2 as a function of pT for centrality 0-10%.  The first systematic uncertainty is from the data and the second from the B feed-down
//Location: Figure 8
//CENTRALITY : 0.0 - 10.0 pct
//RE : PB PB --> D0 X
//SQRT(S)/NUCLEON : 2760.0 GeV
//YRAP : -0.8 - 0.8
//x : PT IN GEV
//y : V2
//xdesc	x	xlow	xhigh	y	dy+	dy-	dy+	dy-	dy+	dy-	
//	2.494	2.0	3.0	0.131	+0.053	-0.053	+0.043	-0.043	+0.075	-0.0
//	3.506	3.0	4.0	0.086	+0.052	-0.052	+0.019	-0.019	+0.046	-0.0
//	4.848	4.0	6.0	0.08	+0.05	-0.05	+0.03	-0.03	+0.04	-0.0
//	6.861	6.0	8.0	0.098	+0.071	-0.071	+0.039	-0.039	+0.05	-0.0
//	9.609	8.0	12.0	-0.022	+0.064	-0.064	+0.074	-0.074	+0.0	-0.013
//	13.985	12.0	16.0	0.251	+0.106	-0.106	+0.043	-0.043	+0.136	-0.0
//
//Path: /HepData/8551/d2-x1-y1
//Prompt D^0 meson v2 as a function of pT for centrality 10-30%.  The first systematic uncertainty is from the data and the second from the B feed-down
//Location: Figure 8
//CENTRALITY : 10.0 - 30.0 pct
//RE : PB PB --> D0 X
//SQRT(S)/NUCLEON : 2760.0 GeV
//YRAP : -0.8 - 0.8
//x : PT IN GEV
//y : V2
//xdesc	x	xlow	xhigh	y	dy+	dy-	dy+	dy-	dy+	dy-	
//	2.564	2.0	3.0	0.134	+0.057	-0.057	+0.017	-0.017	+0.067	-0.0
//	3.519	3.0	4.0	0.139	+0.057	-0.057	+0.047	-0.047	+0.059	-0.0
//	4.876	4.0	6.0	0.139	+0.053	-0.053	+0.03	-0.03	+0.063	-0.0
//	6.934	6.0	8.0	0.115	+0.083	-0.083	+0.053	-0.053	+0.057	-0.0
//	9.381	8.0	12.0	-0.016	+0.08	-0.08	+0.057	-0.057	+0.0	-0.008
//	13.805	12.0	16.0	0.047	+0.107	-0.107	+0.052	-0.052	+0.027	-0.0
//
//Path: /HepData/8551/d3-x1-y1
//Prompt D^0 meson v2 as a function of pT for centrality 30-50%.  The first systematic uncertainty is from the data and the second from the B feed-down
//Location: Figure 8
//CENTRALITY : 30.0 - 50.0 pct
//RE : PB PB --> D0 X
//SQRT(S)/NUCLEON : 2760.0 GeV
//YRAP : -0.8 - 0.8
//x : PT IN GEV
//y : V2
//xdesc	x	xlow	xhigh	y	dy+	dy-	dy+	dy-	dy+	dy-	
//	2.499	2.0	3.0	0.164	+0.065	-0.065	+0.058	-0.058	+0.094	-0.0
//	3.458	3.0	4.0	0.202	+0.058	-0.058	+0.028	-0.028	+0.109	-0.0
//	4.859	4.0	6.0	0.211	+0.055	-0.055	+0.021	-0.021	+0.106	-0.0
//	6.802	6.0	8.0	0.129	+0.084	-0.084	+0.03	-0.03	+0.066	-0.0
//	9.792	8.0	12.0	0.421	+0.083	-0.083	+0.054	-0.054	+0.236	-0.0
//	13.469	12.0	16.0	-0.145	+0.131	-0.131	+0.144	-0.144	+0.0	-0.079
//
