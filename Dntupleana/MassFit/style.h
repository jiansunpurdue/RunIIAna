/*
 * =====================================================================================
 *
 *       Filename:  style.h
 *
 *    Description:  useful script
 *
 *        Version:  1.0
 *        Created:  11/12/2012 10:23:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quan Wang, 
 *   Organization:  
 *
 * =====================================================================================
 */
 
#include "TStyle.h"
 void makeMultiPanelCanvas(TCanvas*& canv, const Int_t columns,
                          const Int_t rows, const Float_t leftOffset=0.,
                          const Float_t bottomOffset=0.,
                          const Float_t leftMargin=0.2,
                          const Float_t bottomMargin=0.2,
                          const Float_t edge=0.05,
						  const Float_t topMargin=0.2) {
   if (canv==0) {
      Error("makeMultiPanelCanvas","Got null canvas.");
      return;
   }
   canv->Clear();

   TPad* pad[columns][rows];
   
   Float_t Xlow[columns];
   Float_t Xup[columns];
   Float_t Ylow[rows];
   Float_t Yup[rows];
   Float_t PadWidth =
      (1.0-leftOffset)/((1.0/(1.0-leftMargin)) +
			   (1.0/(1.0-edge))+(Float_t)columns-2.0);
   Float_t PadHeight =
      (1.0-bottomOffset)/((1.0/(1.0-bottomMargin)) +
			  (1.0/(1.0-edge))+(Float_t)rows-2.0);
//   cout << "PadWidth = " << PadWidth << "\t" << "PadHeight = " << PadHeight << endl;
   Xlow[0] = leftOffset;
   Xup[0] = leftOffset + PadWidth/(1.0-leftMargin);
   Xup[columns-1] = 1;
   Xlow[columns-1] = 1.0-PadWidth/(1.0-edge);
   
   Yup[0] = 1;
   Ylow[0] = 1.0-PadHeight/(1.0-edge);
   Ylow[rows-1] = bottomOffset;
   Yup[rows-1] = bottomOffset + PadHeight/(1.0-bottomMargin);
   
   for(Int_t i=1;i<columns-1;i++) {
      Xlow[i] = Xup[0] + (i-1)*PadWidth;
      Xup[i] = Xup[0] + (i)*PadWidth;
   }
   Int_t ct = 0;
   for(Int_t i=rows-2;i>0;i--) {
      Ylow[i] = Yup[rows-1] + ct*PadHeight;
      Yup[i] = Yup[rows-1] + (ct+1)*PadHeight;
      ct++;
   }

//   for ( int i = 0; i < columns; i++ ) {
//	   for ( j = 0; j < rows; j++ ) {
//		   cout << "Xlow[" << i << "] = " << Xlow[i] << "\t" << "Ylow[" << j << "] = " << Ylow[j] << "\t" << "Xup[" << i << "] = " << Xup[i] << "\t" << "Yup[" << j << "] = " << Yup[j] << endl;
//	   }
//   }
   TString padName;
   for(Int_t i=0;i<columns;i++) {
      for(Int_t j=0;j<rows;j++) {
         canv->cd();
         padName = Form("p_%d_%d",i,j);
         pad[i][j] = new TPad(padName.Data(),padName.Data(),
			      Xlow[i],Ylow[j],Xup[i],Yup[j]);
         if(i==0) pad[i][j]->SetLeftMargin(leftMargin);
         else pad[i][j]->SetLeftMargin(0);

         if(i==(columns-1)) pad[i][j]->SetRightMargin(edge);
         else pad[i][j]->SetRightMargin(0);

         if(j==0) pad[i][j]->SetTopMargin(topMargin);
         else pad[i][j]->SetTopMargin(0);
	 
         if(j==(rows-1)) pad[i][j]->SetBottomMargin(bottomMargin);
         else pad[i][j]->SetBottomMargin(0);
	 
         pad[i][j]->Draw();
         pad[i][j]->cd();
         pad[i][j]->SetNumber(columns*j+i+1);
      }
   }
}

TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

void SetStyle() {

  TH1::SetDefaultSumw2();
  gROOT->SetStyle("Plain");

  TStyle *MITStyle = new TStyle("MIT-Style","The Perfect Style for Plots ;-)");
  gStyle = MITStyle;

  gStyle->SetTitleSize(14,"t");//  gStyle->SetTitleX(0.8);
  gStyle->SetTitleW(0.3);

  // Canvas

  MITStyle->SetCanvasColor     (0);
  MITStyle->SetCanvasBorderSize(10);
  MITStyle->SetCanvasBorderMode(0);

  MITStyle->SetCanvasDefH      (500);
  MITStyle->SetCanvasDefW      (550);
  //  MITStyle->SetCanvasDefX      (100);
  //  MITStyle->SetCanvasDefY      (100);

  // Pads

  MITStyle->SetPadColor       (0);
  //  MITStyle->SetPadBorderSize  (10);
  MITStyle->SetPadBorderMode  (0);
  MITStyle->SetPadBottomMargin(0.16);
  MITStyle->SetPadTopMargin   (0.06);
  MITStyle->SetPadLeftMargin  (0.1);
  MITStyle->SetPadRightMargin (0.14);
  MITStyle->SetPadGridX       (0);
  MITStyle->SetPadGridY       (0);
  MITStyle->SetPadTickX       (1);
  MITStyle->SetPadTickY       (1);

  // Frames

  MITStyle->SetFrameFillStyle ( 0);
  MITStyle->SetFrameFillColor ( 0);
  MITStyle->SetFrameLineColor ( 1);
  MITStyle->SetFrameLineStyle ( 0);
  MITStyle->SetFrameLineWidth ( 1);
  //  MITStyle->SetFrameBorderSize(10);
  MITStyle->SetFrameBorderMode( 0);

  // Histograms

  MITStyle->SetHistLineColor(1);
  MITStyle->SetHistLineStyle(0);
//  MITStyle->SetHistLineWidth(3);
  MITStyle->SetNdivisions(505,"X");
  MITStyle->SetNdivisions(505,"Y");
  MITStyle->SetNdivisions(505,"Z");

  // Functions

  MITStyle->SetFuncColor(1);
  MITStyle->SetFuncStyle(0);
  MITStyle->SetFuncWidth(2);

  // Various

//  MITStyle->SetMarkerStyle(20);
//  MITStyle->SetMarkerColor(kBlack);
  MITStyle->SetMarkerSize (2);

//  MITStyle->SetTitleSize  (0.1,"t");

  MITStyle->SetTitleSize  (14,"X");
  MITStyle->SetTitleOffset(1.0,"X");
  MITStyle->SetTitleFont  (43,"X");
  MITStyle->SetLabelOffset(0.005,"X");
  MITStyle->SetLabelSize  (14,"X");
  MITStyle->SetLabelFont  (43   ,"X");

  MITStyle->SetTitleSize  (14,"Y");
  MITStyle->SetTitleOffset(1.0,"Y");
  MITStyle->SetTitleFont  (43,"Y");
  MITStyle->SetLabelOffset(0.005,"Y");
  MITStyle->SetLabelSize  (14,"Y");
  MITStyle->SetLabelFont  (43   ,"Y");

  MITStyle->SetTitleSize  (0.06,"Z");
  MITStyle->SetTitleOffset(1.640,"Z");
  MITStyle->SetTitleFont  (43,"Z");
  MITStyle->SetLabelOffset(0.005,"Z");
  MITStyle->SetLabelSize  (14,"Z");
  MITStyle->SetLabelFont  (43   ,"Z");

  MITStyle->SetStripDecimals(kFALSE);
  MITStyle->SetTitleBorderSize(0);
  MITStyle->SetTitleFillColor(0);
  //  MITStyle->SetTitleAlign(6);

  MITStyle->SetTextSize   (20);
  MITStyle->SetTextFont   (43);

  MITStyle->SetStatFont   (43);
  MITStyle->SetOptStat    (0);

  MITStyle->SetLegendBorderSize(0);
//  MITStyle->SetEndErrorSize(0);
//  MITStyle->SetErrorX(0);

  MITStyle->SetPalette    (1,0);
  return;
}
void InitHist(TH1        *hist,
	      const char *xtit,
	      const char *ytit  = "Number of Entries",
	      EColor      color = kBlack)
{
  hist->SetXTitle(xtit);
  hist->SetYTitle(ytit);
  hist->SetLineColor(color);
  hist->SetTitleSize  (14,"X");
  hist->SetTitleSize  (14,"Y");
  hist->SetTitleSize  (14,"Z");
  hist->SetTitleOffset(2,"Y");
  hist->SetTitleOffset(2,"X");
  hist->SetTitleOffset(2,"Z");
  hist->SetLabelOffset(0.008,"Y");
  hist->SetLabelFont  (43   ,"Y");
  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(color);
  hist->SetMarkerSize (0.6);
  // Strangely enough this cannot be set anywhere else??
  hist->GetXaxis()->SetLabelSize(14);
  hist->GetYaxis()->SetLabelSize(10);
  hist->GetYaxis()->SetTitleFont(43);
  hist->GetXaxis()->CenterTitle();
  hist->GetYaxis()->CenterTitle();
  hist->SetTitle("");  
  return;
}

TCanvas* MakeCanvas(const char* name, const char *title, int x = 0, int y = 0)
{
  // Start with a canvas
  TCanvas *canvas = 0;
  if ( x == 0 ) canvas = new TCanvas(name,title);
  else canvas = new TCanvas(name,title, x, y);
  // General overall stuff
  canvas->SetFillColor      (0);
  canvas->SetBorderMode     (0);
  canvas->SetBorderSize     (10);
  // Set margins to reasonable defaults
  canvas->SetLeftMargin     (0.15);
  canvas->SetRightMargin    (0.06);
  canvas->SetTopMargin      (0.08);
  canvas->SetBottomMargin   (0.15);
  // Setup a frame which makes sense
  canvas->SetFrameFillStyle (0);
  canvas->SetFrameLineStyle (0);
  canvas->SetFrameBorderMode(0);
  canvas->SetFrameBorderSize(10);
  canvas->SetFrameFillStyle (0);
  canvas->SetFrameLineStyle (0);
  canvas->SetFrameBorderMode(0);
  canvas->SetFrameBorderSize(10);

  return canvas;
}

void Style()
{
	gStyle->SetCanvasColor(10);
	gStyle->SetPadColor(10);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gStyle->SetFillColor(0);
	gStyle->SetTitleColor(kBlack);
	gStyle->SetStatColor(0);
	gStyle->SetHistFillColor(0);
	gStyle->SetFrameFillColor(0);
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetFrameBorderMode(0);
	gStyle->SetPadBorderMode(0);
	gStyle->SetOptStat(0);
	gStyle->SetOptFit();
	gStyle->SetLabelSize(14,"X");
	gStyle->SetLabelSize(14,"Y");
	gStyle->SetLineWidth(1);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetMarkerSize(2);
	gStyle->SetLabelColor(kBlack);
}

void myStyle(Int_t lStat=0)
{
	//Set gStyle
	int font = 43;
	// From plain
	gStyle->SetFrameBorderMode(0);
	gStyle->SetFrameFillColor(0);
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetPadBorderMode(0);
	gStyle->SetPadColor(10);
	gStyle->SetCanvasColor(10);
	gStyle->SetTitleFillColor(10);
	gStyle->SetTitleBorderSize(1);
	gStyle->SetStatColor(10);
	gStyle->SetStatBorderSize(1);
	gStyle->SetLegendBorderSize(1);
	//
	gStyle->SetDrawBorder(0);
	gStyle->SetTextFont(font);
	gStyle->SetStatFont(font);
	gStyle->SetStatFontSize(0.05);
	gStyle->SetStatX(0.97);
	gStyle->SetStatY(0.98);
	gStyle->SetStatH(0.03);
	gStyle->SetStatW(0.3);
	gStyle->SetTickLength(0.02,"y");
	gStyle->SetEndErrorSize(3);
	gStyle->SetLabelSize(14,"xyz");
	gStyle->SetLabelFont(font,"xyz"); 
	gStyle->SetLabelOffset(0.01,"xyz");
	gStyle->SetTitleFont(font,"xyz");  
	gStyle->SetTitleOffset(1.0,"xyz");  
	gStyle->SetTitleSize(14,"xyz");  
	gStyle->SetMarkerSize(1); 
	gStyle->SetPalette(1,0); 
	if (lStat){
		gStyle->SetOptTitle(1);
		gStyle->SetOptStat(1111);
		gStyle->SetOptFit(1111);
	}
	else {
		gStyle->SetOptTitle(0);
		gStyle->SetOptStat(0);
		gStyle->SetOptFit(0);
	}

}

void grStyle(TGraphErrors* gr, int mkstyle, int color, double mksize=1)
{
	gr->SetMarkerStyle(mkstyle);
	gr->SetMarkerColor(color);
	gr->SetLineColor(color);
	gr->SetMarkerSize(mksize);
}

// tdrGrid: Turns the grid lines on (true) or off (false)

void tdrGrid(bool gridOn) {
  tdrStyle->SetPadGridX(gridOn);
  tdrStyle->SetPadGridY(gridOn);
}

// fixOverlay: Redraws the axis

void fixOverlay() {
  gPad->RedrawAxis();
}

void setTDRStyle() {

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

// For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

// For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

// For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
//  tdrStyle->SetErrorMarker(20);
  tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);

//For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

//For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(43);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

// Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.16);
  tdrStyle->SetPadRightMargin(0.02);

// For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(43);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

// For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(43, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.25);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(43, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

// For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

// Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

// Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();

}

void CanvasPartition(TCanvas *C,const Int_t Nx,const Int_t Ny,
                     Float_t lMargin, Float_t rMargin,
                     Float_t bMargin, Float_t tMargin)
{
   if (!C) return;

   // Setup Pad layout:
   Float_t vSpacing = 0.0;
   Float_t vStep  = (1.- bMargin - tMargin - (Ny-1) * vSpacing) / Ny;

   Float_t hSpacing = 0.0;
   Float_t hStep  = (1.- lMargin - rMargin - (Nx-1) * hSpacing) / Nx;

   Float_t vposd,vposu,vmard,vmaru,vfactor;
   Float_t hposl,hposr,hmarl,hmarr,hfactor;

   for (Int_t i=0;i<Nx;i++) {

      if (i==0) {
         hposl = 0.0;
         hposr = lMargin + hStep;
         hfactor = hposr-hposl;
         hmarl = lMargin / hfactor;
         hmarr = 0.0;
      } else if (i == Nx-1) {
         hposl = hposr + hSpacing;
         hposr = hposl + hStep + rMargin;
         hfactor = hposr-hposl;
         hmarl = 0.0;
         hmarr = rMargin / (hposr-hposl);
      } else {
         hposl = hposr + hSpacing;
         hposr = hposl + hStep;
         hfactor = hposr-hposl;
         hmarl = 0.0;
         hmarr = 0.0;
      }

      for (Int_t j=0;j<Ny;j++) {

         if (j==0) {
            vposd = 0.0;
            vposu = bMargin + vStep;
            vfactor = vposu-vposd;
            vmard = bMargin / vfactor;
            vmaru = 0.0;
         } else if (j == Ny-1) {
            vposd = vposu + vSpacing;
            vposu = vposd + vStep + tMargin;
            vfactor = vposu-vposd;
            vmard = 0.0;
            vmaru = tMargin / (vposu-vposd);
         } else {
            vposd = vposu + vSpacing;
            vposu = vposd + vStep;
            vfactor = vposu-vposd;
            vmard = 0.0;
            vmaru = 0.0;
         }

         C->cd(0);

         char name[16];
         sprintf(name,"pad_%i_%i",i,j);
         TPad *pad = (TPad*) gROOT->FindObject(name);
         if (pad) delete pad;
         pad = new TPad(name,"",hposl,vposd,hposr,vposu);
         pad->SetLeftMargin(hmarl);
         pad->SetRightMargin(hmarr);
         pad->SetBottomMargin(vmard);
         pad->SetTopMargin(vmaru);

         pad->SetFrameBorderMode(0);
         pad->SetBorderMode(0);
         pad->SetBorderSize(0);

         pad->Draw();
	 pad->SetNumber(Ny*j+i+1);
      }
   }
}
