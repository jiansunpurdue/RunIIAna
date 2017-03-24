void ReadFile (TString infile="phsd-interpolation.txt")
{
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

	double a,b,c,d,e,f,g;
	FILE *fp=fopen(infile.Data(),"r");
	FILE *fp2=fopen(infile.Data(),"r");

	int counter=0;
	while(fscanf(fp,"%lf %lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f,&g)!=EOF) {
		counter++;
		//cout<<a<<endl;
	}

	cout << "counter: " << counter << endl;
	const int size=counter;
	double pt[size],Dv2_cent0to10[size],Dv2_cent10to30[size],Dv2_cent30to50[size],Dv3_cent0to10[size],Dv3_cent10to30[size],Dv3_cent30to50[size];
	double zero[size];

	int counter2=0;
	while(fscanf(fp2,"%lf %lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f,&g)!=EOF) {
		pt[counter2]=a;
		Dv2_cent0to10[counter2]=b;
		Dv2_cent10to30[counter2]=c;
		Dv2_cent30to50[counter2]=d;
		Dv3_cent0to10[counter2]=e;
		Dv3_cent10to30[counter2]=f;
		Dv3_cent30to50[counter2]=g;
		zero[counter2]=0.;
		counter2++;
	}

  fclose(fp);  
  fclose(fp2);  

  TGraph * gv2Dmeson5TeV_PHSD_cent0to10 = new TGraph( size, pt, Dv2_cent0to10);
  TGraph * gv2Dmeson5TeV_PHSD_cent10to30 = new TGraph( size, pt, Dv2_cent10to30);
  TGraph * gv2Dmeson5TeV_PHSD_cent30to50 = new TGraph( size, pt, Dv2_cent30to50);
  gv2Dmeson5TeV_PHSD_cent0to10->SetName("gv2Dmeson5TeV_PHSD_cent0to10"); gv2Dmeson5TeV_PHSD_cent0to10->SetTitle("gv2Dmeson5TeV_PHSD_cent0to10");
  gv2Dmeson5TeV_PHSD_cent10to30->SetName("gv2Dmeson5TeV_PHSD_cent10to30"); gv2Dmeson5TeV_PHSD_cent10to30->SetTitle("gv2Dmeson5TeV_PHSD_cent10to30");
  gv2Dmeson5TeV_PHSD_cent30to50->SetName("gv2Dmeson5TeV_PHSD_cent30to50"); gv2Dmeson5TeV_PHSD_cent30to50->SetTitle("gv2Dmeson5TeV_PHSD_cent30to50");

  TGraph * gv3Dmeson5TeV_PHSD_cent0to10 = new TGraph( size, pt, Dv3_cent0to10);
  TGraph * gv3Dmeson5TeV_PHSD_cent10to30 = new TGraph( size, pt, Dv3_cent10to30);
  TGraph * gv3Dmeson5TeV_PHSD_cent30to50 = new TGraph( size, pt, Dv3_cent30to50);
  gv3Dmeson5TeV_PHSD_cent0to10->SetName("gv3Dmeson5TeV_PHSD_cent0to10"); gv3Dmeson5TeV_PHSD_cent0to10->SetTitle("gv3Dmeson5TeV_PHSD_cent0to10");
  gv3Dmeson5TeV_PHSD_cent10to30->SetName("gv3Dmeson5TeV_PHSD_cent10to30"); gv3Dmeson5TeV_PHSD_cent10to30->SetTitle("gv3Dmeson5TeV_PHSD_cent10to30");
  gv3Dmeson5TeV_PHSD_cent30to50->SetName("gv3Dmeson5TeV_PHSD_cent30to50"); gv3Dmeson5TeV_PHSD_cent30to50->SetTitle("gv3Dmeson5TeV_PHSD_cent30to50");

  TFile * output = new TFile("PHSD_v2v3.root","RECREATE");
  gv2Dmeson5TeV_PHSD_cent0to10->Write();
  gv2Dmeson5TeV_PHSD_cent10to30->Write();
  gv2Dmeson5TeV_PHSD_cent30to50->Write();
  gv3Dmeson5TeV_PHSD_cent0to10->Write();
  gv3Dmeson5TeV_PHSD_cent10to30->Write();
  gv3Dmeson5TeV_PHSD_cent30to50->Write();
  output->Close();
}
