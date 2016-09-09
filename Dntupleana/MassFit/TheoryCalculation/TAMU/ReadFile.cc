void ReadFile (TString infile="Pb_Pb_5p02TeV_D_meson_v2_cent10to30.txt",int cent_low = 10, int cent_high = 30)
{
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

	double a,b,c;
	FILE *fp=fopen(infile.Data(),"r");
	FILE *fp2=fopen(infile.Data(),"r");

	int counter=0;
	while(fscanf(fp,"%lf %lf %lf",&a,&b,&c)!=EOF) {
		counter++;
		//cout<<a<<endl;
	}
	const int size=counter;
	double pt[size],Dv2center[size],Dv2_error_low[size],Dv2_error_high[size];
	double zero[size];
	double width[size];

	int counter2=0;
	while(fscanf(fp2,"%lf %lf %lf",&a,&b,&c)!=EOF) {
		pt[counter2]=a;
		if( b > c ) 
		{
			double tmp = b;
			b = c;
			c = tmp;
		}
		Dv2center[counter2]=(b+c)/2.0;
		Dv2_error_low[counter2]=(b+c)/2.0-b;
		Dv2_error_high[counter2]=c-(b+c)/2.0;
		zero[counter2]=0.;
		width[counter2]=0.1;
		counter2++;
	}

  fclose(fp);  
  fclose(fp2);  
  
  TGraphAsymmErrors* gv2Dmeson5TeV_TAMU = new TGraphAsymmErrors(size,pt,Dv2center,width,width,Dv2_error_low,Dv2_error_high);
  gv2Dmeson5TeV_TAMU->SetName(Form("gv2Dmeson5TeV_TAMU_cent%dto%d", cent_low, cent_high));
  gv2Dmeson5TeV_TAMU->SetTitle(Form("gv2Dmeson5TeV_TAMU_cent%dto%d", cent_low, cent_high));

  //gv2Dmeson5TeV_TAMU->SetFillStyle(3001);
  //gv2Dmeson5TeV_TAMU->SetFillColor(6);
  //gv2Dmeson5TeV_TAMU->SetLineColor(6);
  gv2Dmeson5TeV_TAMU->SetFillStyle(1001);
  gv2Dmeson5TeV_TAMU->SetFillColor(46);
  gv2Dmeson5TeV_TAMU->SetLineColor(46);
  gv2Dmeson5TeV_TAMU->SetLineWidth(2);
    
  TCanvas* canvas = new TCanvas("canvas","",600,600);
  canvas->cd();
  TH2F* hempty=new TH2F("hempty","",50,0,8,60,-0.12,0.18);
  hempty->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hempty->GetYaxis()->CenterTitle();
  hempty->GetYaxis()->SetTitle("v_{2}");
  hempty->GetXaxis()->SetTitleOffset(1.1);
  hempty->GetYaxis()->SetTitleOffset(1.3);
  hempty->GetXaxis()->SetTitleSize(0.05);
  hempty->GetYaxis()->SetTitleSize(0.05);
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.05);
  hempty->GetYaxis()->SetLabelSize(0.05);  
  hempty->Draw();
  //gv2Dmeson5TeV_TAMU->Draw("4same");
  gv2Dmeson5TeV_TAMU->Draw("3same");
  gv2Dmeson5TeV_TAMU->Draw("CXsame");

  canvas->SaveAs(Form("plots/cfg_v2Dmeson5TeV_TAMU_cent%dto%d.pdf",cent_low, cent_high));
    
  TFile*foutput=new TFile(Form("PredictionsTAMU_Dv2_pt_cent%dto%d.root",cent_low, cent_high),"recreate");
  gv2Dmeson5TeV_TAMU->Write();
  foutput->Close();
}
