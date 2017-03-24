#include <iostream>
using namespace std;

void ReadFile (TString infile="CUJET_5.02TeV_D0_v2.dat")
{
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

	double a,b,c,d,e,f,g;
	FILE *fp=fopen(infile.Data(),"r");
	FILE *fp2=fopen(infile.Data(),"r");

	int counter=0;
	while(fscanf(fp,"%lf %lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f,&g)!=EOF) {
		counter++;
	}

	cout << "counter: " << counter << endl;
	const int size=counter;
	double pt[size];
	double Dv2_cent0to10[size], Dv2_cent0to10_error[size], Dv2_cent10to30[size], Dv2_cent10to30_error[size];
	double Dv2_cent30to50[size], Dv2_cent30to50_error[size];
	double width[size];

	int counter2=0;
	while(fscanf(fp2,"%lf %lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f,&g)!=EOF) {
		pt[counter2]=a;
		Dv2_cent0to10[counter2]=(b+c)/2.;
		Dv2_cent0to10_error[counter2] = b - (b+c)/2.;
		Dv2_cent10to30[counter2]=(d+e)/2.;
		Dv2_cent10to30_error[counter2] = d - (d+e)/2.;
		Dv2_cent30to50[counter2]=(f+g)/2.;
		Dv2_cent30to50_error[counter2] = f - (f+g)/2.;
		width[counter2]=0.1;
		counter2++;
		if(a > 30.) cout << "pt: " << a << endl;
	}

  fclose(fp);  
  fclose(fp2);  

  TGraphErrors * gv2Dmeson5TeV_CUJET_cent0to10 = new TGraphErrors( size, pt, Dv2_cent0to10, width, Dv2_cent0to10_error);
  TGraphErrors * gv2Dmeson5TeV_CUJET_cent10to30 = new TGraphErrors( size, pt, Dv2_cent10to30, width, Dv2_cent10to30_error);
  TGraphErrors * gv2Dmeson5TeV_CUJET_cent30to50 = new TGraphErrors( size, pt, Dv2_cent30to50, width, Dv2_cent30to50_error);
  gv2Dmeson5TeV_CUJET_cent0to10->SetName("gv2Dmeson5TeV_CUJET_cent0to10"); gv2Dmeson5TeV_CUJET_cent0to10->SetTitle("gv2Dmeson5TeV_CUJET_cent0to10");
  gv2Dmeson5TeV_CUJET_cent10to30->SetName("gv2Dmeson5TeV_CUJET_cent10to30"); gv2Dmeson5TeV_CUJET_cent10to30->SetTitle("gv2Dmeson5TeV_CUJET_cent10to30");
  gv2Dmeson5TeV_CUJET_cent30to50->SetName("gv2Dmeson5TeV_CUJET_cent30to50"); gv2Dmeson5TeV_CUJET_cent30to50->SetTitle("gv2Dmeson5TeV_CUJET_cent30to50");

  TFile * output = new TFile("CUJET_v2.root","RECREATE");
  gv2Dmeson5TeV_CUJET_cent0to10->Write();
  gv2Dmeson5TeV_CUJET_cent10to30->Write();
  gv2Dmeson5TeV_CUJET_cent30to50->Write();
  output->Close();
}
