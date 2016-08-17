void ReadFile (TString infile="CUJET3_D0_v2pT_30-50.dat",int cent_low = 30, int cent_high = 50)
{
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

	double a,b,c,d;
	FILE *fp=fopen(infile.Data(),"r");
	FILE *fp2=fopen(infile.Data(),"r");

	int counter=0;
	while(fscanf(fp,"%lf %lf %lf %lf",&a,&b,&c,&d)!=EOF) {
		counter++;
		//cout<<a<<endl;
	}
	const int size=counter;
	double pt[size],Dv2center[size],Dv2_error_low[size],Dv2_error_high[size];
	double zero[size];
	double width[size];

	int counter2=0;
	while(fscanf(fp2,"%lf %lf %lf %lf",&a,&b,&c,&d)!=EOF) {
		pt[counter2]=a;
		Dv2center[counter2]=b;
		Dv2_error_low[counter2]=b-c;
		Dv2_error_high[counter2]=d-b;
		zero[counter2]=0.;
		width[counter2]=0.1;
		counter2++;
	}

  fclose(fp);  
  fclose(fp2);  
  
  TGraphAsymmErrors* gv2Dmeson5TeV_CUJET3 = new TGraphAsymmErrors(size,pt,Dv2center,width,width,Dv2_error_low,Dv2_error_high);
  gv2Dmeson5TeV_CUJET3->SetName(Form("gv2Dmeson5TeV_CUJET3_cent%dto%d", cent_low, cent_high));
  gv2Dmeson5TeV_CUJET3->SetTitle(Form("gv2Dmeson5TeV_CUJET3_cent%dto%d", cent_low, cent_high));

  gv2Dmeson5TeV_CUJET3->SetLineColor(8);
  gv2Dmeson5TeV_CUJET3->SetLineWidth(2);
  gv2Dmeson5TeV_CUJET3->SetFillStyle(1001);
  gv2Dmeson5TeV_CUJET3->SetFillColor(kGreen-10);
    
  TCanvas* canvas = new TCanvas("canvas","",600,600);
  canvas->cd();
  TH2F* hempty=new TH2F("hempty","",50,0,110,60,-0.01,0.12);
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
  gv2Dmeson5TeV_CUJET3->Draw("4same");
  gv2Dmeson5TeV_CUJET3->Draw("CXsame");

  canvas->SaveAs(Form("plots/cfg_v2Dmeson5TeV_CUJET3_cent%dto%d.pdf",cent_low, cent_high));
    
  TFile*foutput=new TFile(Form("PredictionsCUJET3_Dv2_pt_cent%dto%d.root",cent_low, cent_high),"recreate");
  gv2Dmeson5TeV_CUJET3->Write();
  foutput->Close();
}
