#ifndef anaDntuple_H
#define anaDntuple_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <boost/filesystem.hpp>
#include <complex>
#include <cmath>

#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include "TBranch.h"
#include "TMath.h"
#include "TF1.h"
#include "TLorentzVector.h"
#include <TCanvas.h>

#define MAX_XB       20000
#define MAX_GEN      6000

#define kMaxEvtPlanes 200

using namespace std;
namespace fs = boost::filesystem;
typedef complex<double> comp;

//ptweight or pthatweight for MC

class anaDntuple
{
	public:
		anaDntuple();
		virtual ~anaDntuple();
		void LoopOverFile( int startFile, int endFile, string filelist, bool isPbPb, bool isMCornot, double hibin_low = -0.5, double hibin_high = 199.5, int whichPbPbPD = 0, bool EPlistdefault = true); //if need to loop over files
		void ProcessPartialEvents( string inputfilename, bool isPbPb, bool isMCornot, int startevt = 0, int endevt = -1, double hibin_low = -0.5, double hibin_high = 199.5, int whichPbPbPD = 0, bool EPlistdefault = true);

	private:
		//basic functions
		void Init( string outfilename );
		void Histobookforanalysis();
		void GetMCPtWeightFunction( TTree * GenDtree );
		void SetEfficiencyCurve();
		void LoopOverEvt( TTree * intree, int startevt = 0, int endevt = -1 );
		void LoopOverDcandidates();
		void LoopOverGenDs();
		void Write();
		void PbPbTrigComb_PDs();
		void Combine_TrigPart_TrigVersion();
		void FillEvtTrighibin();
		void FillEPresohisto();
		void FillEPresohisto_SP(int EP, TProfile * h_QAB, TProfile * h_QAC, TProfile * h_QBC);
		void FillMBhisto(int icand, int iptbin);
		void FillMCMBhisto( int icand, int iptbin);
		void Dtrig_combination(int icand);
		void FillDtrighisto_PbPb(int icand, int iptbin);
		void FillDtrighisto_pp(int icand, int iptbin);
		void FillMCDtrighisto(int icand, int iptbin);
		void FillJettrighisto(int icand, int iptbin);
		float Calculatedeltaphi( int icand, int floworder);
		int  Decideinoutplane(float deltaphi, int floworder);
		int  Decidephibin_morephibin(float deltaphi, int floworder);
		void DecideEPSPresolutionandMeanQvector( int icand);

	private:
		bool isPbPbCollision;
		bool isMC;
		bool DefaultEPlist;
		int PbPbPD;
		TFile * outputfile;
		//centrality range to process
		double hibin_cut_low;
		double hibin_cut_high;
		int cent_low;
		int cent_high;
		double Evt_weight; //use pthatweight or not
		TF1 * MCPtWeidhtFunction;
		TF1 * EfficiencyCurve;
		float effcorrection;
		bool isGoodforv2;
		bool isGoodforv3;

	private:
		float dcanddeltaphiv1;
		float dcanddeltaphiv2;
		float dcanddeltaphiv3;
		float dcanddeltaphiv4;

		int dcandiphiv1;
		int dcandiphiv2;
		int dcandiphiv3;
		int dcandiphiv4;

		int dcandiphiv2_morephibin;
		int dcandiphiv3_morephibin;

		double cosnphi_mean_v2;
		double sinnphi_mean_v2;
		double cosnphi_mean_v3;
		double sinnphi_mean_v3;
		
		float EP_resolution_v1;
		float EP_resolution_v2;
		float EP_resolution_v3;
		float EP_resolution_v4;

		double SP_Qmag_v1;
		double SP_Qmag_v2;
		double SP_Qmag_v3;
		double SP_Qmag_v4;
		float SP_EP_resolution_v1;
		float SP_EP_resolution_v2;
		float SP_EP_resolution_v3;
		float SP_EP_resolution_v4;

		float DcandDCA;

	private:
		//version combined trig decision
		//for pp, only MB trig part* need to be combined
		//for PbPb, only HF2and for 0-100% and 30-100% need to be combined
		bool MBtrig_part_combined;
		bool MBtrig_cent30to100_part_combined;
		bool MBtrig_cent50to100_part_combined;
		bool MBtrig_cent70to100_part_combined;
		bool HLT_HIDmesonHITrackingGlobal_Dpt20_combined; //v1, v2
		bool HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_combined; //v1, v2, all cent0-10% gated D triggers are seeded by L1 MB
		bool HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_combined; //v1, v2, v3
		bool HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_combined; //v1, v2, v3
		bool HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_combined; //L1 seed same with Dpt20 trigger, //v1, v2
		bool HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_combined; //v1, v2

		bool Dtrig_combined;
		bool Dtrig_combined_Cent0_10;
		bool Dtrig_combined_Cent30_100;
		bool Dtrig_combined_Cent50_100;

		//combinations of real MB trigger decisions	
		bool temp_MBtrig_part_combined;
		bool temp_MBtrig_cent30to100_part_combined;
		bool temp_MBtrig_cent50to100_part_combined;
		bool temp_MBtrig_cent70to100_part_combined;

		//to save real MB trigger decision, used to remove overlap
		int temp_HLT_HIL1MinimumBiasHF1AND_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part1_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part2_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part3_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part4_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part5_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part6_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part7_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part8_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part9_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part10_v1; 
		int temp_HLT_HIL1MinimumBiasHF2AND_part11_v1; 
		int temp_HLT_HIL1Centralityext30100HFplusANDminusTH0_v1; 
		int temp_HLT_HIL1Centralityext50100HFplusANDminusTH0_v1; 
		int temp_HLT_HIL1Centralityext70100HFplusANDminusTH0_v1; 
		int temp_HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1; 
		int temp_HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1; 
		int temp_HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1; 
		int temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1; 
		int temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1; 
		int temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1; 
		int temp_HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1; 
		int temp_HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1; 

	private:
		//read tree functions
		void readtrees(bool isPbPb = true, bool isDkpi = true, bool detailedmoed = false);
		void readevttree(TTree * evttree, bool isPbPb = true);
		void readskimtree(TTree * skimtree);
		void readDntupletree(TTree * Dtree, bool isDkpi = true, bool detailedmoed = false);
		void readPbPbhlttree(TTree * PbPbhlttree);
		void readpphlttree(TTree * pphlttree);
		void readGenDtree(TTree * GenDtree);

	private:
		//input trees
		TTree * ntDkpi;
		TTree * ntHlt;
		TTree * ntSkim;
		TTree * ntHi;
		TTree * ntGen;

	private:
		//branches from event tree
		// Declaration of leaf types
		UInt_t          run;
		ULong64_t       evt;
		UInt_t          lumi;
		Float_t         vx;
		Float_t         vy;
		Float_t         vz;
		Int_t           hiBin;
		Float_t         hiHF;
		Float_t         hiHFplus;
		Float_t         hiHFminus;
		Float_t         hiHFplusEta4;
		Float_t         hiHFminusEta4;
		Float_t         hiZDC;
		Float_t         hiZDCplus;
		Float_t         hiZDCminus;
		Float_t         hiHFhit;
		Float_t         hiHFhitPlus;
		Float_t         hiHFhitMinus;
		Float_t         hiET;
		Float_t         hiEE;
		Float_t         hiEB;
		Float_t         hiEEplus;
		Float_t         hiEEminus;
		Int_t           hiNpix;
		Int_t           hiNpixelTracks;
		Int_t           hiNtracks;
		Int_t           hiNtracksPtCut;
		Int_t           hiNtracksEtaCut;
		Int_t           hiNtracksEtaPtCut;
		Int_t           hiNevtPlane;
		Float_t         hiEvtPlanes[kMaxEvtPlanes];   //[hiNevtPlane]	
		Float_t         hiEvtPlanesqx[kMaxEvtPlanes];   //[hiNevtPlane]	
		Float_t         hiEvtPlanesqy[kMaxEvtPlanes];   //[hiNevtPlane]	
		Float_t         pthatweight;
		Float_t         pthat;

		//branches from skim tree
		// Declaration of leaf types
		Int_t           pcollisionEventSelection;
		Int_t           pHBHENoiseFilterResultProducer;
		Int_t           HBHENoiseFilterResult;
		Int_t           HBHENoiseFilterResultRun1;
		Int_t           HBHENoiseFilterResultRun2Loose;
		Int_t           HBHENoiseFilterResultRun2Tight;
		Int_t           HBHEIsoNoiseFilterResult;
		Int_t           pprimaryVertexFilter;
		Int_t           phfCoincFilter1;
		Int_t           phfCoincFilter2;
		Int_t           phfCoincFilter3;
		Int_t           phfCoincFilter4;
		Int_t           phfCoincFilter5;
		Int_t           pclusterCompatibilityFilter;    

		Int_t           pPAprimaryVertexFilter;
		Int_t           pBeamScrapingFilter;
		Int_t           pVertexFilterCutG;
		Int_t           pVertexFilterCutGloose;
		Int_t           pVertexFilterCutGtight;
		Int_t           pVertexFilterCutGplus;
		Int_t           pVertexFilterCutE;
		Int_t           pVertexFilterCutEandG;

		//branches from Gen D tree
		int     Gsize;
		float   Gy[MAX_GEN];
		float   Geta[MAX_GEN];
		float   Gphi[MAX_GEN];
		float   Gpt[MAX_GEN];
		int     GpdgId[MAX_GEN];
		int     GcollisionId[MAX_GEN];//to tell if it is from pythia event or hydjet event, = 0 embedded pythia, > 0 Hydjet
		int     GisSignal[MAX_GEN];
		float   GBAncestorpt[MAX_GEN];
		int     GBAncestorpdgId[MAX_GEN];
		float   Gtk1pt[MAX_GEN];
		float   Gtk1eta[MAX_GEN];
		float   Gtk1y[MAX_GEN];
		float   Gtk1phi[MAX_GEN];
		float   Gtk2pt[MAX_GEN];
		float   Gtk2eta[MAX_GEN];
		float   Gtk2y[MAX_GEN];
		float   Gtk2phi[MAX_GEN];
		float   Gtk3pt[MAX_GEN];
		float   Gtk3eta[MAX_GEN];
		float   Gtk3y[MAX_GEN];
		float   Gtk3phi[MAX_GEN];
		float   Gtk4pt[MAX_GEN];
		float   Gtk4eta[MAX_GEN];
		float   Gtk4y[MAX_GEN];
		float   Gtk4phi[MAX_GEN];
		float   GRestk1pt[MAX_GEN];
		float   GRestk1eta[MAX_GEN];
		float   GRestk1y[MAX_GEN];
		float   GRestk1phi[MAX_GEN];
		float   GRestk2pt[MAX_GEN];
		float   GRestk2eta[MAX_GEN];
		float   GRestk2y[MAX_GEN];
		float   GRestk2phi[MAX_GEN];
		float   GRestk3pt[MAX_GEN];
		float   GRestk3eta[MAX_GEN];
		float   GRestk3y[MAX_GEN];
		float   GRestk3phi[MAX_GEN];
		float   GRestk4pt[MAX_GEN];
		float   GRestk4eta[MAX_GEN];
		float   GRestk4y[MAX_GEN];
		float   GRestk4phi[MAX_GEN];

		//branches from ntDkpi
		//EvtInfo
		int     RunNo;
		int     EvtNo;
		int     LumiNo;
		int     Dsize;
		float   PVx;
		float   PVy;
		float   PVz;
		float   PVxE;
		float   PVyE;
		float   PVzE;
		float   PVnchi2;
		float   PVchi2;
		float   BSx;
		float   BSy;
		float   BSz;
		float   BSxErr;
		float   BSyErr;
		float   BSzErr;
		float   BSdxdz;
		float   BSdydz;
		float   BSdxdzErr;
		float   BSdydzErr;
		float   BSWidthX;
		float   BSWidthXErr;
		float   BSWidthY;
		float   BSWidthYErr;
		//DInfo
		int     Dindex[MAX_XB];
		int     Dtype[MAX_XB];
		float   Dmass[MAX_XB];
		float   Dpt[MAX_XB];
		float   Deta[MAX_XB];
		float   Dphi[MAX_XB];
		float   Dy[MAX_XB];
		float   DvtxX[MAX_XB];
		float   DvtxY[MAX_XB];
		float   Dd0[MAX_XB];
		float   Dd0Err[MAX_XB];
		float   Ddxyz[MAX_XB];
		float   DdxyzErr[MAX_XB];
		float   Dchi2ndf[MAX_XB];
		float   Dchi2cl[MAX_XB];
		float   Ddtheta[MAX_XB];
		float   Dlxy[MAX_XB];
		float   Dalpha[MAX_XB];
		float   DsvpvDistance[MAX_XB];
		float   DsvpvDisErr[MAX_XB];
		float   DsvpvDistance_2D[MAX_XB];
		float   DsvpvDisErr_2D[MAX_XB];
		float   DtktkRes_chi2ndf[MAX_XB];
		float   DtktkRes_chi2cl[MAX_XB];
		float   DtktkRes_alpha[MAX_XB];
		float   DtktkRes_svpvDistance[MAX_XB];
		float   DtktkRes_svpvDisErr[MAX_XB];
		float   DlxyBS[MAX_XB];
		float   DlxyBSErr[MAX_XB];
		float   DMaxDoca[MAX_XB];
		bool    Dmaxpt[MAX_XB];
		bool    Dmaxprob[MAX_XB];
		bool    DmaxptMatched[MAX_XB];
		bool    DmaxprobMatched[MAX_XB];
		//DInfo.trkInfo
		int     Dtrk1Idx[MAX_XB];
		int     Dtrk2Idx[MAX_XB];
		int     Dtrk3Idx[MAX_XB];
		int     Dtrk4Idx[MAX_XB];
		float   Dtrk1Pt[MAX_XB];
		float   Dtrk2Pt[MAX_XB];
		float   Dtrk3Pt[MAX_XB];
		float   Dtrk4Pt[MAX_XB];
		float   Dtrk1Eta[MAX_XB];
		float   Dtrk2Eta[MAX_XB];
		float   Dtrk3Eta[MAX_XB];
		float   Dtrk4Eta[MAX_XB];
		float   Dtrk1Phi[MAX_XB];
		float   Dtrk2Phi[MAX_XB];
		float   Dtrk3Phi[MAX_XB];
		float   Dtrk4Phi[MAX_XB];
		float   Dtrk1PtErr[MAX_XB];
		float   Dtrk2PtErr[MAX_XB];
		float   Dtrk3PtErr[MAX_XB];
		float   Dtrk4PtErr[MAX_XB];
		float   Dtrk1EtaErr[MAX_XB];
		float   Dtrk2EtaErr[MAX_XB];
		float   Dtrk3EtaErr[MAX_XB];
		float   Dtrk4EtaErr[MAX_XB];
		float   Dtrk1PhiErr[MAX_XB];
		float   Dtrk2PhiErr[MAX_XB];
		float   Dtrk3PhiErr[MAX_XB];
		float   Dtrk4PhiErr[MAX_XB];
		float   Dtrk1Y[MAX_XB];
		float   Dtrk2Y[MAX_XB];
		float   Dtrk3Y[MAX_XB];
		float   Dtrk4Y[MAX_XB];
		float   Dtrk1Dxy[MAX_XB];
		float   Dtrk2Dxy[MAX_XB];
		float   Dtrk3Dxy[MAX_XB];
		float   Dtrk4Dxy[MAX_XB];
		float   Dtrk1D0Err[MAX_XB];
		float   Dtrk2D0Err[MAX_XB];
		float   Dtrk3D0Err[MAX_XB];
		float   Dtrk4D0Err[MAX_XB];
		float   Dtrk1PixelHit[MAX_XB];
		float   Dtrk2PixelHit[MAX_XB];
		float   Dtrk3PixelHit[MAX_XB];
		float   Dtrk4PixelHit[MAX_XB];
		float   Dtrk1StripHit[MAX_XB];
		float   Dtrk2StripHit[MAX_XB];
		float   Dtrk3StripHit[MAX_XB];
		float   Dtrk4StripHit[MAX_XB];
		float   Dtrk1nStripLayer[MAX_XB];
		float   Dtrk2nStripLayer[MAX_XB];
		float   Dtrk3nStripLayer[MAX_XB];
		float   Dtrk4nStripLayer[MAX_XB];
		float   Dtrk1nPixelLayer[MAX_XB];
		float   Dtrk2nPixelLayer[MAX_XB];
		float   Dtrk3nPixelLayer[MAX_XB];
		float   Dtrk4nPixelLayer[MAX_XB];
		float   Dtrk1Chi2ndf[MAX_XB];
		float   Dtrk2Chi2ndf[MAX_XB];
		float   Dtrk3Chi2ndf[MAX_XB];
		float   Dtrk4Chi2ndf[MAX_XB];
		float   Dtrk1MassHypo[MAX_XB];
		float   Dtrk2MassHypo[MAX_XB];
		float   Dtrk3MassHypo[MAX_XB];
		float   Dtrk4MassHypo[MAX_XB];
		float   Dtrk1MVAVal[MAX_XB];
		float   Dtrk2MVAVal[MAX_XB];
		float   Dtrk3MVAVal[MAX_XB];
		float   Dtrk4MVAVal[MAX_XB];
		int     Dtrk1Algo[MAX_XB];
		int     Dtrk2Algo[MAX_XB];
		int     Dtrk3Algo[MAX_XB];
		int     Dtrk4Algo[MAX_XB];
		bool    Dtrk1highPurity[MAX_XB];
		bool    Dtrk2highPurity[MAX_XB];
		bool    Dtrk3highPurity[MAX_XB];
		bool    Dtrk4highPurity[MAX_XB];
		int     Dtrk1Quality[MAX_XB];
		int     Dtrk2Quality[MAX_XB];
		int     Dtrk3Quality[MAX_XB];
		int     Dtrk4Quality[MAX_XB];
		//DInfo.tktkResInfo
		float   DtktkResmass[MAX_XB];
		float   DtktkRespt[MAX_XB];
		float   DtktkReseta[MAX_XB];
		float   DtktkResphi[MAX_XB];
		float   DRestrk1Pt[MAX_XB];
		float   DRestrk1Eta[MAX_XB];
		float   DRestrk1Phi[MAX_XB];
		float   DRestrk1Y[MAX_XB];
		float   DRestrk1Dxy[MAX_XB];
		float   DRestrk1D0Err[MAX_XB];
		float   DRestrk2Pt[MAX_XB];
		float   DRestrk2Eta[MAX_XB];
		float   DRestrk2Phi[MAX_XB];
		float   DRestrk2Y[MAX_XB];
		float   DRestrk2Dxy[MAX_XB];
		float   DRestrk2D0Err[MAX_XB];
		float   DRestrk3Pt[MAX_XB];
		float   DRestrk3Eta[MAX_XB];
		float   DRestrk3Phi[MAX_XB];
		float   DRestrk3Y[MAX_XB];
		float   DRestrk3Dxy[MAX_XB];
		float   DRestrk3D0Err[MAX_XB];
		float   DRestrk4Pt[MAX_XB];
		float   DRestrk4Eta[MAX_XB];
		float   DRestrk4Phi[MAX_XB];
		float   DRestrk4Y[MAX_XB];
		float   DRestrk4Dxy[MAX_XB];
		float   DRestrk4D0Err[MAX_XB];

		//Branches from gen tree
		//DInfo.genInfo
		float   Dgen[MAX_XB];
		int     DgennDa[MAX_XB];
		int     DgenIndex[MAX_XB];
		float   Dgenpt[MAX_XB];
		float   Dgeneta[MAX_XB];
		float   Dgenphi[MAX_XB];
		float   Dgeny[MAX_XB];
		int     DgencollisionId[MAX_XB];
		float   DgenBAncestorpt[MAX_XB];
		int     DgenBAncestorpdgId[MAX_XB];

		//branches from ntHlt
		//********************* for PbPb ************************
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt50_v1; //Dpt50 not used 
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt70_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v2;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1;
		Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl;

		Int_t           HLT_HIPuAK4CaloDJet60_Eta2p1_v1;
		Int_t           HLT_HIPuAK4CaloDJet60_Eta2p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloDJet80_Eta2p1_v1;
		Int_t           HLT_HIPuAK4CaloDJet80_Eta2p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet60_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet60_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1ForZS_v1;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1ForZS_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet100_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet100_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet110_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet110_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet120_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet120_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet150_Eta5p1_v1;
		Int_t           HLT_HIPuAK4CaloJet150_Eta5p1_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_Cent30_100_v1;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_Cent30_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet60_Eta5p1_Cent30_100_v1;
		Int_t           HLT_HIPuAK4CaloJet60_Eta5p1_Cent30_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1_Cent30_100_v1;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1_Cent30_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet100_Eta5p1_Cent30_100_v1;
		Int_t           HLT_HIPuAK4CaloJet100_Eta5p1_Cent30_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_Cent50_100_v1;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_Cent50_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet60_Eta5p1_Cent50_100_v1;
		Int_t           HLT_HIPuAK4CaloJet60_Eta5p1_Cent50_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1_Cent50_100_v1;
		Int_t           HLT_HIPuAK4CaloJet80_Eta5p1_Cent50_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet100_Eta5p1_Cent50_100_v1;
		Int_t           HLT_HIPuAK4CaloJet100_Eta5p1_Cent50_100_v1_Prescl;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_v2;
		Int_t           HLT_HIPuAK4CaloJet40_Eta5p1_v2_Prescl;

		Int_t           HLT_HIL1MinimumBiasHF2AND_part1_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part2_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part3_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part4_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part5_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part6_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part7_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part8_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part9_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part10_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part11_v1;
		Int_t           HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl;
		Int_t           HLT_HIL1MinimumBiasHF1AND_v1;
		Int_t           HLT_HIL1MinimumBiasHF1AND_v1_Prescl;

		//////////!!!!!!!!!!!!!!!!!!!
		Int_t           HLT_HIL1MinimumBiasHF2AND_v1; 
		Int_t           HLT_HIL1MinimumBiasHF2AND_v1_Prescl;

		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1_Prescl;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1_Prescl;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1_Prescl;
		Int_t           HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1;
		Int_t           HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1_Prescl;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1_Prescl;
		Int_t           HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1;
		Int_t           HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1_Prescl;
		Int_t           HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1;
		Int_t           HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1_Prescl;

		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1;
		Int_t           HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1_Prescl;
		Int_t           HLT_HIL1Centralityext30100HFplusANDminusTH0_v1;
		Int_t           HLT_HIL1Centralityext30100HFplusANDminusTH0_v1_Prescl;
		Int_t           HLT_HIL1Centralityext50100HFplusANDminusTH0_v1;
		Int_t           HLT_HIL1Centralityext50100HFplusANDminusTH0_v1_Prescl;
		Int_t           HLT_HIL1Centralityext70100HFplusANDminusTH0_v1; 
		Int_t           HLT_HIL1Centralityext70100HFplusANDminusTH0_v1_Prescl; 

		Int_t           L1_SingleS1Jet16_BptxAND;
		Int_t           L1_SingleS1Jet16_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet16_Centrality_ext30_100_BptxAND;
		Int_t           L1_SingleS1Jet16_Centrality_ext30_100_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet16_Centrality_ext50_100_BptxAND;
		Int_t           L1_SingleS1Jet16_Centrality_ext50_100_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet28_BptxAND;
		Int_t           L1_SingleS1Jet28_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet28_Centrality_ext30_100_BptxAND;
		Int_t           L1_SingleS1Jet28_Centrality_ext30_100_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet28_Centrality_ext50_100_BptxAND;
		Int_t           L1_SingleS1Jet28_Centrality_ext50_100_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet32_BptxAND;
		Int_t           L1_SingleS1Jet32_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet32_Centrality_ext30_100_BptxAND;
		Int_t           L1_SingleS1Jet32_Centrality_ext30_100_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet32_Centrality_ext50_100_BptxAND;
		Int_t           L1_SingleS1Jet32_Centrality_ext50_100_BptxAND_Prescl;    
		Int_t           L1_SingleS1Jet36_BptxAND;
		Int_t           L1_SingleS1Jet36_BptxAND_Prescl;    
		Int_t           L1_SingleS1Jet40_BptxAND;
		Int_t           L1_SingleS1Jet40_BptxAND_Prescl;
		Int_t           L1_SingleJet44_BptxAND;
		Int_t           L1_SingleJet44_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet44_Centrality_ext30_100_BptxAND;
		Int_t           L1_SingleS1Jet44_Centrality_ext30_100_BptxAND_Prescl;
		Int_t           L1_SingleS1Jet44_Centrality_ext50_100_BptxAND;
		Int_t           L1_SingleS1Jet44_Centrality_ext50_100_BptxAND_Prescl;
		Int_t           L1_Centrality_ext0_10_MinimumumBiasHF1_AND;
		Int_t           L1_Centrality_ext0_10_MinimumumBiasHF1_AND_Prescl;
		Int_t           L1_Centrality_ext0_5_MinimumumBiasHF1_AND;
		Int_t           L1_Centrality_ext0_5_MinimumumBiasHF1_AND_Prescl;
		Int_t           L1_Centrality_ext30_100_MinimumumBiasHF1_AND;
		Int_t           L1_Centrality_ext30_100_MinimumumBiasHF1_AND_Prescl;
		Int_t           L1_Centrality_ext30_50_MinimumumBiasHF1_AND;
		Int_t           L1_Centrality_ext30_50_MinimumumBiasHF1_AND_Prescl;
		Int_t           L1_Centrality_ext50_100_MinimumumBiasHF1_AND;
		Int_t           L1_Centrality_ext50_100_MinimumumBiasHF1_AND_Prescl;
		Int_t           L1_Centrality_ext70_100_MinimumumBiasHF1_AND;
		Int_t           L1_Centrality_ext70_100_MinimumumBiasHF1_AND_Prescl;

		//********************* for pp ************************
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt8_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt8_v1_Prescl;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt15_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt15_v1_Prescl;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt20_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt20_v1_Prescl;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt30_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt30_v1_Prescl;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt40_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt40_v1_Prescl;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt50_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt50_v1_Prescl;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt60_v1;
		Int_t           HLT_DmesonPPTrackingGlobal_Dpt60_v1_Prescl;

		Int_t           HLT_AK4PFDJet60_Eta2p1_v1;
		Int_t           HLT_AK4PFDJet60_Eta2p1_v1_Prescl;
		Int_t           HLT_AK4PFDJet80_Eta2p1_v1;
		Int_t           HLT_AK4PFDJet80_Eta2p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet40_Eta5p1_v1;
		Int_t           HLT_AK4CaloJet40_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet60_Eta5p1_v1;
		Int_t           HLT_AK4CaloJet60_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet80_Eta5p1_v1;
		Int_t           HLT_AK4CaloJet80_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet100_Eta5p1_v1;
		Int_t           HLT_AK4CaloJet100_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet110_Eta5p1_v1;
		Int_t           HLT_AK4CaloJet110_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet120_Eta5p1_v1;
		Int_t           HLT_AK4CaloJet120_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4CaloJet150_v1;
		Int_t           HLT_AK4CaloJet150_v1_Prescl;
		Int_t           HLT_AK4PFJet40_Eta5p1_v1;
		Int_t           HLT_AK4PFJet40_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4PFJet60_Eta5p1_v1;
		Int_t           HLT_AK4PFJet60_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4PFJet80_Eta5p1_v1;
		Int_t           HLT_AK4PFJet80_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4PFJet100_Eta5p1_v1;
		Int_t           HLT_AK4PFJet100_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4PFJet110_Eta5p1_v1;
		Int_t           HLT_AK4PFJet110_Eta5p1_v1_Prescl;
		Int_t           HLT_AK4PFJet120_Eta5p1_v1;
		Int_t           HLT_AK4PFJet120_Eta5p1_v1_Prescl;

		Int_t           HLT_L1MinimumBiasHF1OR_part0_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part0_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part1_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part1_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part2_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part2_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part3_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part3_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part4_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part4_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part5_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part5_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part6_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part6_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part7_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part7_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part8_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part8_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part9_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part9_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part10_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part10_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part11_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part11_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part12_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part12_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part13_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part13_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part14_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part14_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part15_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part15_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part16_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part16_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part17_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part17_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part18_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part18_v1_Prescl;
		Int_t           HLT_L1MinimumBiasHF1OR_part19_v1;
		Int_t           HLT_L1MinimumBiasHF1OR_part19_v1_Prescl;

		Int_t           L1_MinimumBiasHF1_OR;
		Int_t           L1_MinimumBiasHF1_OR_Prescl;
		Int_t           L1_SingleJet12_BptxAND;
		Int_t           L1_SingleJet12_BptxAND_Prescl;
		Int_t           L1_SingleJet16;
		Int_t           L1_SingleJet16_Prescl;
		Int_t           L1_SingleJet16_BptxAND;
		Int_t           L1_SingleJet16_BptxAND_Prescl;
		Int_t           L1_SingleJet200;
		Int_t           L1_SingleJet200_Prescl;
		Int_t           L1_SingleJet20_BptxAND;
		Int_t           L1_SingleJet20_BptxAND_Prescl;
		Int_t           L1_SingleJet24_BptxAND;
		Int_t           L1_SingleJet24_BptxAND_Prescl;
		Int_t           L1_SingleJet28_BptxAND;
		Int_t           L1_SingleJet28_BptxAND_Prescl;
		Int_t           L1_SingleJet32_BptxAND;
		Int_t           L1_SingleJet32_BptxAND_Prescl;
		Int_t           L1_SingleJet36;
		Int_t           L1_SingleJet36_Prescl;
		Int_t           L1_SingleJet36_BptxAND;
		Int_t           L1_SingleJet36_BptxAND_Prescl;
		Int_t           L1_SingleJet40_BptxAND;
		Int_t           L1_SingleJet40_BptxAND_Prescl;
		//    Int_t           L1_SingleJet44_BptxAND; //declare in PbPb
		//    Int_t           L1_SingleJet44_BptxAND_Prescl;
		Int_t           L1_SingleJet48_BptxAND;
		Int_t           L1_SingleJet48_BptxAND_Prescl;
};

void anaDntuple::readevttree(TTree * evttree, bool isPbPb)
{
	evttree->SetBranchAddress("run", &run);
	evttree->SetBranchAddress("evt", &evt);
	evttree->SetBranchAddress("lumi", &lumi);
	evttree->SetBranchAddress("vx", &vx);
	evttree->SetBranchAddress("vy", &vy);
	evttree->SetBranchAddress("vz", &vz);
	evttree->SetBranchAddress("hiBin", &hiBin);
	if(isMC) evttree->SetBranchAddress("pthatweight", &pthatweight);
	if(isMC) evttree->SetBranchAddress("pthat", &pthat);
	//   evttree->SetBranchAddress("hiHF", &hiHF);
	//   evttree->SetBranchAddress("hiHFplus", &hiHFplus);
	//   evttree->SetBranchAddress("hiHFminus", &hiHFminus);
	//   evttree->SetBranchAddress("hiHFplusEta4", &hiHFplusEta4);
	//   evttree->SetBranchAddress("hiHFminusEta4", &hiHFminusEta4);
	//   evttree->SetBranchAddress("hiZDC", &hiZDC);
	//   evttree->SetBranchAddress("hiZDCplus", &hiZDCplus);
	//   evttree->SetBranchAddress("hiZDCminus", &hiZDCminus);
	//   evttree->SetBranchAddress("hiHFhit", &hiHFhit);
	//   evttree->SetBranchAddress("hiHFhitPlus", &hiHFhitPlus);
	//   evttree->SetBranchAddress("hiHFhitMinus", &hiHFhitMinus);
	//   evttree->SetBranchAddress("hiET", &hiET);
	//   evttree->SetBranchAddress("hiEE", &hiEE);
	//   evttree->SetBranchAddress("hiEB", &hiEB);
	//   evttree->SetBranchAddress("hiEEplus", &hiEEplus);
	//   evttree->SetBranchAddress("hiEEminus", &hiEEminus);
	//   evttree->SetBranchAddress("hiNpix", &hiNpix);
	//   evttree->SetBranchAddress("hiNpixelTracks", &hiNpixelTracks);
	//   evttree->SetBranchAddress("hiNtracks", &hiNtracks);
	//   evttree->SetBranchAddress("hiNtracksPtCut", &hiNtracksPtCut);
	//   evttree->SetBranchAddress("hiNtracksEtaCut", &hiNtracksEtaCut);
	//   evttree->SetBranchAddress("hiNtracksEtaPtCut", &hiNtracksEtaPtCut);
	if( isPbPb )
	{
		evttree->SetBranchAddress("hiNevtPlane", &hiNevtPlane);
		evttree->SetBranchAddress("hiEvtPlanes", hiEvtPlanes);
		evttree->SetBranchAddress("hiEvtPlanesqx", hiEvtPlanesqx);
		evttree->SetBranchAddress("hiEvtPlanesqy", hiEvtPlanesqy);
	}
}

void anaDntuple::readskimtree(TTree * skimtree)
{
	if( isPbPbCollision )
	{
		skimtree->SetBranchAddress("pcollisionEventSelection", &pcollisionEventSelection);
		skimtree->SetBranchAddress("pHBHENoiseFilterResultProducer", &pHBHENoiseFilterResultProducer);
		skimtree->SetBranchAddress("HBHENoiseFilterResult", &HBHENoiseFilterResult);
		skimtree->SetBranchAddress("HBHENoiseFilterResultRun1", &HBHENoiseFilterResultRun1);
		skimtree->SetBranchAddress("HBHENoiseFilterResultRun2Loose", &HBHENoiseFilterResultRun2Loose);
		skimtree->SetBranchAddress("HBHENoiseFilterResultRun2Tight", &HBHENoiseFilterResultRun2Tight);
		skimtree->SetBranchAddress("HBHEIsoNoiseFilterResult", &HBHEIsoNoiseFilterResult);
		skimtree->SetBranchAddress("pprimaryVertexFilter", &pprimaryVertexFilter);
		skimtree->SetBranchAddress("phfCoincFilter1", &phfCoincFilter1);
		skimtree->SetBranchAddress("phfCoincFilter2", &phfCoincFilter2);
		skimtree->SetBranchAddress("phfCoincFilter3", &phfCoincFilter3);
		skimtree->SetBranchAddress("phfCoincFilter4", &phfCoincFilter4);
		skimtree->SetBranchAddress("phfCoincFilter5", &phfCoincFilter5);
		skimtree->SetBranchAddress("pclusterCompatibilityFilter", &pclusterCompatibilityFilter);
	}
	else
	{
		skimtree->SetBranchAddress("pPAprimaryVertexFilter", &pPAprimaryVertexFilter);
		skimtree->SetBranchAddress("pBeamScrapingFilter", &pBeamScrapingFilter);
		skimtree->SetBranchAddress("pVertexFilterCutG", &pVertexFilterCutG);
		skimtree->SetBranchAddress("pVertexFilterCutGloose", &pVertexFilterCutGloose);
		skimtree->SetBranchAddress("pVertexFilterCutGtight", &pVertexFilterCutGtight);
		skimtree->SetBranchAddress("pVertexFilterCutGplus", &pVertexFilterCutGplus);
		skimtree->SetBranchAddress("pVertexFilterCutE", &pVertexFilterCutE);
		skimtree->SetBranchAddress("pVertexFilterCutEandG", &pVertexFilterCutEandG);
		skimtree->SetBranchAddress("HBHENoiseFilterResultRun1", &HBHENoiseFilterResultRun1);
		skimtree->SetBranchAddress("HBHENoiseFilterResultRun2Loose", &HBHENoiseFilterResultRun2Loose);
		skimtree->SetBranchAddress("HBHENoiseFilterResultRun2Tight", &HBHENoiseFilterResultRun2Tight);
		skimtree->SetBranchAddress("HBHENoiseFilterResult", &HBHENoiseFilterResult);
		skimtree->SetBranchAddress("HBHEIsoNoiseFilterResult", &HBHEIsoNoiseFilterResult);
	}
}

void anaDntuple::readGenDtree(TTree * GenDtree)
{
	GenDtree->SetBranchAddress("Gsize", &Gsize);
	GenDtree->SetBranchAddress("Gy", Gy);
	GenDtree->SetBranchAddress("Geta", Geta);
	GenDtree->SetBranchAddress("Gphi", Gphi);
	GenDtree->SetBranchAddress("Gpt", Gpt);
	GenDtree->SetBranchAddress("GpdgId", GpdgId);
	GenDtree->SetBranchAddress("GcollisionId", GcollisionId);
	GenDtree->SetBranchAddress("GisSignal", GisSignal);
	GenDtree->SetBranchAddress("GBAncestorpt", GBAncestorpt);
	GenDtree->SetBranchAddress("GBAncestorpdgId", GBAncestorpdgId);
	GenDtree->SetBranchAddress("Gtk1pt", Gtk1pt);
	GenDtree->SetBranchAddress("Gtk1eta", Gtk1eta);
	GenDtree->SetBranchAddress("Gtk1y", Gtk1y);
	GenDtree->SetBranchAddress("Gtk1phi", Gtk1phi);
	GenDtree->SetBranchAddress("Gtk2pt", Gtk2pt);
	GenDtree->SetBranchAddress("Gtk2eta", Gtk2eta);
	GenDtree->SetBranchAddress("Gtk2y", Gtk2y);
	GenDtree->SetBranchAddress("Gtk2phi", Gtk2phi);
	GenDtree->SetBranchAddress("Gtk3pt", Gtk3pt);
	GenDtree->SetBranchAddress("Gtk3eta", Gtk3eta);
	GenDtree->SetBranchAddress("Gtk3y", Gtk3y);
	GenDtree->SetBranchAddress("Gtk3phi", Gtk3phi);
	GenDtree->SetBranchAddress("Gtk4pt", Gtk4pt);
	GenDtree->SetBranchAddress("Gtk4eta", Gtk4eta);
	GenDtree->SetBranchAddress("Gtk4y", Gtk4y);
	GenDtree->SetBranchAddress("Gtk4phi", Gtk4phi);
	GenDtree->SetBranchAddress("GRestk1pt", GRestk1pt);
	GenDtree->SetBranchAddress("GRestk1eta", GRestk1eta);
	GenDtree->SetBranchAddress("GRestk1y", GRestk1y);
	GenDtree->SetBranchAddress("GRestk1phi", GRestk1phi);
	GenDtree->SetBranchAddress("GRestk2pt", GRestk2pt);
	GenDtree->SetBranchAddress("GRestk2eta", GRestk2eta);
	GenDtree->SetBranchAddress("GRestk2y", GRestk2y);
	GenDtree->SetBranchAddress("GRestk2phi", GRestk2phi);
	GenDtree->SetBranchAddress("GRestk3pt", GRestk3pt);
	GenDtree->SetBranchAddress("GRestk3eta", GRestk3eta);
	GenDtree->SetBranchAddress("GRestk3y", GRestk3y);
	GenDtree->SetBranchAddress("GRestk3phi", GRestk3phi);
	GenDtree->SetBranchAddress("GRestk4pt", GRestk4pt);
	GenDtree->SetBranchAddress("GRestk4eta", GRestk4eta);
	GenDtree->SetBranchAddress("GRestk4y", GRestk4y);
	GenDtree->SetBranchAddress("GRestk4phi", GRestk4phi);
}

void anaDntuple::readDntupletree(TTree * Dtree, bool isDkpi, bool detailedmoed)
{
	Dtree->SetBranchAddress("RunNo", &RunNo);
	Dtree->SetBranchAddress("EvtNo", &EvtNo);
	Dtree->SetBranchAddress("LumiNo", &LumiNo);
	Dtree->SetBranchAddress("Dsize", &Dsize);
	Dtree->SetBranchAddress("PVx", &PVx);
	Dtree->SetBranchAddress("PVy", &PVy);
	Dtree->SetBranchAddress("PVz", &PVz);
	Dtree->SetBranchAddress("PVnchi2", &PVnchi2);
	Dtree->SetBranchAddress("BSx", &BSx);
	Dtree->SetBranchAddress("BSy", &BSy);
	Dtree->SetBranchAddress("BSz", &BSz);
	Dtree->SetBranchAddress("Dindex", Dindex);
	Dtree->SetBranchAddress("Dtype", Dtype);
	Dtree->SetBranchAddress("Dmass", Dmass);
	Dtree->SetBranchAddress("Dpt", Dpt);
	Dtree->SetBranchAddress("Deta", Deta);
	Dtree->SetBranchAddress("Dphi", Dphi);
	Dtree->SetBranchAddress("Dy", Dy);
	Dtree->SetBranchAddress("DvtxX", DvtxX);
	Dtree->SetBranchAddress("DvtxY", DvtxY);
	Dtree->SetBranchAddress("Dd0", Dd0);
	Dtree->SetBranchAddress("Dd0Err", Dd0Err);
	Dtree->SetBranchAddress("Ddxyz", Ddxyz);
	Dtree->SetBranchAddress("DdxyzErr", DdxyzErr);
	Dtree->SetBranchAddress("Dchi2ndf", Dchi2ndf);
	Dtree->SetBranchAddress("Dchi2cl", Dchi2cl);
	Dtree->SetBranchAddress("Ddtheta", Ddtheta);
	Dtree->SetBranchAddress("Dlxy", Dlxy);
	Dtree->SetBranchAddress("Dalpha", Dalpha);
	Dtree->SetBranchAddress("DsvpvDistance", DsvpvDistance);
	Dtree->SetBranchAddress("DsvpvDisErr", DsvpvDisErr);
	Dtree->SetBranchAddress("DsvpvDistance_2D", DsvpvDistance_2D);
	Dtree->SetBranchAddress("DsvpvDisErr_2D", DsvpvDisErr_2D);
	Dtree->SetBranchAddress("DtktkRes_chi2ndf", DtktkRes_chi2ndf);
	Dtree->SetBranchAddress("DtktkRes_chi2cl", DtktkRes_chi2cl);
	Dtree->SetBranchAddress("DtktkRes_alpha", DtktkRes_alpha);
	Dtree->SetBranchAddress("DtktkRes_svpvDistance", DtktkRes_svpvDistance);
	Dtree->SetBranchAddress("DtktkRes_svpvDisErr", DtktkRes_svpvDisErr);
	Dtree->SetBranchAddress("DlxyBS", DlxyBS);
	Dtree->SetBranchAddress("DlxyBSErr", DlxyBSErr);
	Dtree->SetBranchAddress("DMaxDoca", DMaxDoca);
//	Dtree->SetBranchAddress("Dmaxpt", Dmaxpt);
//	Dtree->SetBranchAddress("Dmaxprob", Dmaxprob);
//	Dtree->SetBranchAddress("DmaxptMatched", DmaxptMatched);
//	Dtree->SetBranchAddress("DmaxprobMatched", DmaxprobMatched);
	Dtree->SetBranchAddress("Dtrk1Pt", Dtrk1Pt);
	Dtree->SetBranchAddress("Dtrk2Pt", Dtrk2Pt);
	Dtree->SetBranchAddress("Dtrk1Eta", Dtrk1Eta);
	Dtree->SetBranchAddress("Dtrk2Eta", Dtrk2Eta);
	Dtree->SetBranchAddress("Dtrk1Phi", Dtrk1Phi);
	Dtree->SetBranchAddress("Dtrk2Phi", Dtrk2Phi);
	Dtree->SetBranchAddress("Dtrk1PtErr", Dtrk1PtErr);
	Dtree->SetBranchAddress("Dtrk2PtErr", Dtrk2PtErr);
	Dtree->SetBranchAddress("Dtrk1Dxy", Dtrk1Dxy);
	Dtree->SetBranchAddress("Dtrk2Dxy", Dtrk2Dxy);
	Dtree->SetBranchAddress("Dtrk1PixelHit", Dtrk1PixelHit);
	Dtree->SetBranchAddress("Dtrk2PixelHit", Dtrk2PixelHit);
	Dtree->SetBranchAddress("Dtrk1StripHit", Dtrk1StripHit);
	Dtree->SetBranchAddress("Dtrk2StripHit", Dtrk2StripHit);
	Dtree->SetBranchAddress("Dtrk1nPixelLayer", Dtrk1nPixelLayer);
	Dtree->SetBranchAddress("Dtrk2nPixelLayer", Dtrk2nPixelLayer);
	Dtree->SetBranchAddress("Dtrk1nStripLayer", Dtrk1nStripLayer);
	Dtree->SetBranchAddress("Dtrk2nStripLayer", Dtrk2nStripLayer);
	Dtree->SetBranchAddress("Dtrk1Chi2ndf", Dtrk1Chi2ndf);
	Dtree->SetBranchAddress("Dtrk2Chi2ndf", Dtrk2Chi2ndf);
	Dtree->SetBranchAddress("Dtrk1MassHypo", Dtrk1MassHypo);
	Dtree->SetBranchAddress("Dtrk2MassHypo", Dtrk2MassHypo);
	Dtree->SetBranchAddress("Dtrk1Algo", Dtrk1Algo);
	Dtree->SetBranchAddress("Dtrk2Algo", Dtrk2Algo);
	Dtree->SetBranchAddress("Dtrk1highPurity", Dtrk1highPurity);
	Dtree->SetBranchAddress("Dtrk2highPurity", Dtrk2highPurity);
	Dtree->SetBranchAddress("Dgen", Dgen);
	Dtree->SetBranchAddress("DgenIndex", DgenIndex);
	Dtree->SetBranchAddress("DgennDa", DgennDa);
	Dtree->SetBranchAddress("Dgenpt", Dgenpt);
	Dtree->SetBranchAddress("Dgeneta", Dgeneta);
	Dtree->SetBranchAddress("Dgenphi", Dgenphi);
	Dtree->SetBranchAddress("Dgeny", Dgeny);
	Dtree->SetBranchAddress("DgencollisionId", DgencollisionId);
	Dtree->SetBranchAddress("DgenBAncestorpt", DgenBAncestorpt);
	Dtree->SetBranchAddress("DgenBAncestorpdgId", DgenBAncestorpdgId);
}

void anaDntuple::readPbPbhlttree(TTree * PbPbhlttree)
{
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt50_v1", &HLT_HIDmesonHITrackingGlobal_Dpt50_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_v1", &HLT_HIDmesonHITrackingGlobal_Dpt60_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt70_v1", &HLT_HIDmesonHITrackingGlobal_Dpt70_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_v2);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl);

//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloDJet60_Eta2p1_v1", &HLT_HIPuAK4CaloDJet60_Eta2p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloDJet60_Eta2p1_v1_Prescl", &HLT_HIPuAK4CaloDJet60_Eta2p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloDJet80_Eta2p1_v1", &HLT_HIPuAK4CaloDJet80_Eta2p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloDJet80_Eta2p1_v1_Prescl", &HLT_HIPuAK4CaloDJet80_Eta2p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_v1", &HLT_HIPuAK4CaloJet40_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet40_Eta5p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet60_Eta5p1_v1", &HLT_HIPuAK4CaloJet60_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet60_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet60_Eta5p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet80_Eta5p1_v1", &HLT_HIPuAK4CaloJet80_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet80_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet80_Eta5p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet100_Eta5p1_v1", &HLT_HIPuAK4CaloJet100_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet100_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet100_Eta5p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet110_Eta5p1_v1", &HLT_HIPuAK4CaloJet110_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet110_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet110_Eta5p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet120_Eta5p1_v1", &HLT_HIPuAK4CaloJet120_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet120_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet120_Eta5p1_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet150_Eta5p1_v1", &HLT_HIPuAK4CaloJet150_Eta5p1_v1);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet150_Eta5p1_v1_Prescl", &HLT_HIPuAK4CaloJet150_Eta5p1_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_Cent30_100_v1", &HLT_HIPuAK4CaloJet40_Eta5p1_Cent30_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_Cent30_100_v1_Prescl", &HLT_HIPuAK4CaloJet40_Eta5p1_Cent30_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet60_Eta5p1_Cent30_100_v1", &HLT_HIPuAK4CaloJet60_Eta5p1_Cent30_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet60_Eta5p1_Cent30_100_v1_Prescl", &HLT_HIPuAK4CaloJet60_Eta5p1_Cent30_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet80_Eta5p1_Cent30_100_v1", &HLT_HIPuAK4CaloJet80_Eta5p1_Cent30_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet80_Eta5p1_Cent30_100_v1_Prescl", &HLT_HIPuAK4CaloJet80_Eta5p1_Cent30_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet100_Eta5p1_Cent30_100_v1", &HLT_HIPuAK4CaloJet100_Eta5p1_Cent30_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet100_Eta5p1_Cent30_100_v1_Prescl", &HLT_HIPuAK4CaloJet100_Eta5p1_Cent30_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_Cent50_100_v1", &HLT_HIPuAK4CaloJet40_Eta5p1_Cent50_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_Cent50_100_v1_Prescl", &HLT_HIPuAK4CaloJet40_Eta5p1_Cent50_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet60_Eta5p1_Cent50_100_v1", &HLT_HIPuAK4CaloJet60_Eta5p1_Cent50_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet60_Eta5p1_Cent50_100_v1_Prescl", &HLT_HIPuAK4CaloJet60_Eta5p1_Cent50_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet80_Eta5p1_Cent50_100_v1", &HLT_HIPuAK4CaloJet80_Eta5p1_Cent50_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet80_Eta5p1_Cent50_100_v1_Prescl", &HLT_HIPuAK4CaloJet80_Eta5p1_Cent50_100_v1_Prescl);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet100_Eta5p1_Cent50_100_v1", &HLT_HIPuAK4CaloJet100_Eta5p1_Cent50_100_v1);
//	//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet100_Eta5p1_Cent50_100_v1_Prescl", &HLT_HIPuAK4CaloJet100_Eta5p1_Cent50_100_v1_Prescl);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_v2", &HLT_HIPuAK4CaloJet40_Eta5p1_v2);
//	PbPbhlttree->SetBranchAddress("HLT_HIPuAK4CaloJet40_Eta5p1_v2_Prescl", &HLT_HIPuAK4CaloJet40_Eta5p1_v2_Prescl);

	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF1AND_v1", &HLT_HIL1MinimumBiasHF1AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF1AND_v1_Prescl", &HLT_HIL1MinimumBiasHF1AND_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_v1", &HLT_HIL1MinimumBiasHF2AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part1_v1", &HLT_HIL1MinimumBiasHF2AND_part1_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part2_v1", &HLT_HIL1MinimumBiasHF2AND_part2_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part3_v1", &HLT_HIL1MinimumBiasHF2AND_part3_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part4_v1", &HLT_HIL1MinimumBiasHF2AND_part4_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part5_v1", &HLT_HIL1MinimumBiasHF2AND_part5_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part6_v1", &HLT_HIL1MinimumBiasHF2AND_part6_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part7_v1", &HLT_HIL1MinimumBiasHF2AND_part7_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part8_v1", &HLT_HIL1MinimumBiasHF2AND_part8_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part9_v1", &HLT_HIL1MinimumBiasHF2AND_part9_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part10_v1", &HLT_HIL1MinimumBiasHF2AND_part10_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part11_v1", &HLT_HIL1MinimumBiasHF2AND_part11_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl);

	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1_Prescl", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1_Prescl", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part1_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1_Prescl", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part2_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1_Prescl", &HLT_HIL1Centralityext30100MinimumumBiasHF2AND_part3_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1", &HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1_Prescl", &HLT_HIL1Centralityext50100MinimumumBiasHF2AND_v1_Prescl);

	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1", &HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1_Prescl", &HLT_HIL1Centralityext30100MinimumumBiasHF1AND_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1", &HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1_Prescl", &HLT_HIL1Centralityext50100MinimumumBiasHF1AND_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1", &HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1_Prescl", &HLT_HIL1Centralityext70100MinimumumBiasHF1AND_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100HFplusANDminusTH0_v1", &HLT_HIL1Centralityext30100HFplusANDminusTH0_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext30100HFplusANDminusTH0_v1_Prescl", &HLT_HIL1Centralityext30100HFplusANDminusTH0_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext50100HFplusANDminusTH0_v1", &HLT_HIL1Centralityext50100HFplusANDminusTH0_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext50100HFplusANDminusTH0_v1_Prescl", &HLT_HIL1Centralityext50100HFplusANDminusTH0_v1_Prescl);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext70100HFplusANDminusTH0_v1", &HLT_HIL1Centralityext70100HFplusANDminusTH0_v1);
	PbPbhlttree->SetBranchAddress("HLT_HIL1Centralityext70100HFplusANDminusTH0_v1_Prescl", &HLT_HIL1Centralityext70100HFplusANDminusTH0_v1_Prescl);

	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet16_BptxAND", &L1_SingleS1Jet16_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet16_BptxAND_Prescl", &L1_SingleS1Jet16_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet16_Centrality_ext30_100_BptxAND", &L1_SingleS1Jet16_Centrality_ext30_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet16_Centrality_ext30_100_BptxAND_Prescl", &L1_SingleS1Jet16_Centrality_ext30_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet16_Centrality_ext50_100_BptxAND", &L1_SingleS1Jet16_Centrality_ext50_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet16_Centrality_ext50_100_BptxAND_Prescl", &L1_SingleS1Jet16_Centrality_ext50_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet28_BptxAND", &L1_SingleS1Jet28_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet28_BptxAND_Prescl", &L1_SingleS1Jet28_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet28_Centrality_ext30_100_BptxAND", &L1_SingleS1Jet28_Centrality_ext30_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet28_Centrality_ext30_100_BptxAND_Prescl", &L1_SingleS1Jet28_Centrality_ext30_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet28_Centrality_ext50_100_BptxAND", &L1_SingleS1Jet28_Centrality_ext50_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet28_Centrality_ext50_100_BptxAND_Prescl", &L1_SingleS1Jet28_Centrality_ext50_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet32_BptxAND", &L1_SingleS1Jet32_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet32_BptxAND_Prescl", &L1_SingleS1Jet32_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet32_Centrality_ext30_100_BptxAND", &L1_SingleS1Jet32_Centrality_ext30_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet32_Centrality_ext30_100_BptxAND_Prescl", &L1_SingleS1Jet32_Centrality_ext30_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet32_Centrality_ext50_100_BptxAND", &L1_SingleS1Jet32_Centrality_ext50_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet32_Centrality_ext50_100_BptxAND_Prescl", &L1_SingleS1Jet32_Centrality_ext50_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet36_BptxAND", &L1_SingleS1Jet36_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet36_BptxAND_Prescl", &L1_SingleS1Jet36_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet40_BptxAND", &L1_SingleS1Jet40_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet40_BptxAND_Prescl", &L1_SingleS1Jet40_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleJet44_BptxAND", &L1_SingleJet44_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleJet44_BptxAND_Prescl", &L1_SingleJet44_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet44_Centrality_ext30_100_BptxAND", &L1_SingleS1Jet44_Centrality_ext30_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet44_Centrality_ext30_100_BptxAND_Prescl", &L1_SingleS1Jet44_Centrality_ext30_100_BptxAND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet44_Centrality_ext50_100_BptxAND", &L1_SingleS1Jet44_Centrality_ext50_100_BptxAND);
	//	PbPbhlttree->SetBranchAddress("L1_SingleS1Jet44_Centrality_ext50_100_BptxAND_Prescl", &L1_SingleS1Jet44_Centrality_ext50_100_BptxAND_Prescl);
	//
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext0_10_MinimumumBiasHF1_AND", &L1_Centrality_ext0_10_MinimumumBiasHF1_AND);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext0_10_MinimumumBiasHF1_AND_Prescl", &L1_Centrality_ext0_10_MinimumumBiasHF1_AND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext30_100_MinimumumBiasHF1_AND", &L1_Centrality_ext30_100_MinimumumBiasHF1_AND);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext30_100_MinimumumBiasHF1_AND_Prescl", &L1_Centrality_ext30_100_MinimumumBiasHF1_AND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext30_50_MinimumumBiasHF1_AND", &L1_Centrality_ext30_50_MinimumumBiasHF1_AND);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext30_50_MinimumumBiasHF1_AND_Prescl", &L1_Centrality_ext30_50_MinimumumBiasHF1_AND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext50_100_MinimumumBiasHF1_AND", &L1_Centrality_ext50_100_MinimumumBiasHF1_AND);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext50_100_MinimumumBiasHF1_AND_Prescl", &L1_Centrality_ext50_100_MinimumumBiasHF1_AND_Prescl);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext70_100_MinimumumBiasHF1_AND", &L1_Centrality_ext70_100_MinimumumBiasHF1_AND);
	//	PbPbhlttree->SetBranchAddress("L1_Centrality_ext70_100_MinimumumBiasHF1_AND_Prescl", &L1_Centrality_ext70_100_MinimumumBiasHF1_AND_Prescl);
}

void anaDntuple::readpphlttree(TTree * pphlttree)
{
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt8_v1", &HLT_DmesonPPTrackingGlobal_Dpt8_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt8_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt8_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt15_v1", &HLT_DmesonPPTrackingGlobal_Dpt15_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt15_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt15_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt20_v1", &HLT_DmesonPPTrackingGlobal_Dpt20_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt20_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt20_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt30_v1", &HLT_DmesonPPTrackingGlobal_Dpt30_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt30_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt30_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt40_v1", &HLT_DmesonPPTrackingGlobal_Dpt40_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt40_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt40_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt50_v1", &HLT_DmesonPPTrackingGlobal_Dpt50_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt50_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt50_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt60_v1", &HLT_DmesonPPTrackingGlobal_Dpt60_v1);
	pphlttree->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt60_v1_Prescl", &HLT_DmesonPPTrackingGlobal_Dpt60_v1_Prescl);

	pphlttree->SetBranchAddress("HLT_AK4PFDJet60_Eta2p1_v1", &HLT_AK4PFDJet60_Eta2p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFDJet60_Eta2p1_v1_Prescl", &HLT_AK4PFDJet60_Eta2p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFDJet80_Eta2p1_v1", &HLT_AK4PFDJet80_Eta2p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFDJet80_Eta2p1_v1_Prescl", &HLT_AK4PFDJet80_Eta2p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet40_Eta5p1_v1", &HLT_AK4CaloJet40_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet40_Eta5p1_v1_Prescl", &HLT_AK4CaloJet40_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet60_Eta5p1_v1", &HLT_AK4CaloJet60_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet60_Eta5p1_v1_Prescl", &HLT_AK4CaloJet60_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet80_Eta5p1_v1", &HLT_AK4CaloJet80_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet80_Eta5p1_v1_Prescl", &HLT_AK4CaloJet80_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet100_Eta5p1_v1", &HLT_AK4CaloJet100_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet100_Eta5p1_v1_Prescl", &HLT_AK4CaloJet100_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet110_Eta5p1_v1", &HLT_AK4CaloJet110_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet110_Eta5p1_v1_Prescl", &HLT_AK4CaloJet110_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet120_Eta5p1_v1", &HLT_AK4CaloJet120_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet120_Eta5p1_v1_Prescl", &HLT_AK4CaloJet120_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet150_v1", &HLT_AK4CaloJet150_v1);
	pphlttree->SetBranchAddress("HLT_AK4CaloJet150_v1_Prescl", &HLT_AK4CaloJet150_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFJet40_Eta5p1_v1", &HLT_AK4PFJet40_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFJet40_Eta5p1_v1_Prescl", &HLT_AK4PFJet40_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFJet60_Eta5p1_v1", &HLT_AK4PFJet60_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFJet60_Eta5p1_v1_Prescl", &HLT_AK4PFJet60_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFJet80_Eta5p1_v1", &HLT_AK4PFJet80_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFJet80_Eta5p1_v1_Prescl", &HLT_AK4PFJet80_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFJet100_Eta5p1_v1", &HLT_AK4PFJet100_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFJet100_Eta5p1_v1_Prescl", &HLT_AK4PFJet100_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFJet110_Eta5p1_v1", &HLT_AK4PFJet110_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFJet110_Eta5p1_v1_Prescl", &HLT_AK4PFJet110_Eta5p1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_AK4PFJet120_Eta5p1_v1", &HLT_AK4PFJet120_Eta5p1_v1);
	pphlttree->SetBranchAddress("HLT_AK4PFJet120_Eta5p1_v1_Prescl", &HLT_AK4PFJet120_Eta5p1_v1_Prescl);

	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part0_v1", &HLT_L1MinimumBiasHF1OR_part0_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part0_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part0_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part1_v1", &HLT_L1MinimumBiasHF1OR_part1_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part1_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part1_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part2_v1", &HLT_L1MinimumBiasHF1OR_part2_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part2_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part2_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part3_v1", &HLT_L1MinimumBiasHF1OR_part3_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part3_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part3_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part4_v1", &HLT_L1MinimumBiasHF1OR_part4_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part4_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part4_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part5_v1", &HLT_L1MinimumBiasHF1OR_part5_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part5_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part5_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part6_v1", &HLT_L1MinimumBiasHF1OR_part6_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part6_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part6_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part7_v1", &HLT_L1MinimumBiasHF1OR_part7_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part7_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part7_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part8_v1", &HLT_L1MinimumBiasHF1OR_part8_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part8_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part8_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part9_v1", &HLT_L1MinimumBiasHF1OR_part9_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part9_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part9_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part10_v1", &HLT_L1MinimumBiasHF1OR_part10_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part10_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part10_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part11_v1", &HLT_L1MinimumBiasHF1OR_part11_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part11_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part11_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part12_v1", &HLT_L1MinimumBiasHF1OR_part12_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part12_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part12_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part13_v1", &HLT_L1MinimumBiasHF1OR_part13_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part13_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part13_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part14_v1", &HLT_L1MinimumBiasHF1OR_part14_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part14_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part14_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part15_v1", &HLT_L1MinimumBiasHF1OR_part15_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part15_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part15_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part16_v1", &HLT_L1MinimumBiasHF1OR_part16_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part16_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part16_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part17_v1", &HLT_L1MinimumBiasHF1OR_part17_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part17_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part17_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part18_v1", &HLT_L1MinimumBiasHF1OR_part18_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part18_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part18_v1_Prescl);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part19_v1", &HLT_L1MinimumBiasHF1OR_part19_v1);
	pphlttree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_part19_v1_Prescl", &HLT_L1MinimumBiasHF1OR_part19_v1_Prescl);

	pphlttree->SetBranchAddress("L1_MinimumBiasHF1_OR", &L1_MinimumBiasHF1_OR);
	pphlttree->SetBranchAddress("L1_MinimumBiasHF1_OR_Prescl", &L1_MinimumBiasHF1_OR_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet12_BptxAND", &L1_SingleJet12_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet12_BptxAND_Prescl", &L1_SingleJet12_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet16", &L1_SingleJet16);
	pphlttree->SetBranchAddress("L1_SingleJet16_Prescl", &L1_SingleJet16_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet16_BptxAND", &L1_SingleJet16_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet16_BptxAND_Prescl", &L1_SingleJet16_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet200", &L1_SingleJet200);
	pphlttree->SetBranchAddress("L1_SingleJet200_Prescl", &L1_SingleJet200_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet20_BptxAND", &L1_SingleJet20_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet20_BptxAND_Prescl", &L1_SingleJet20_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet24_BptxAND", &L1_SingleJet24_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet24_BptxAND_Prescl", &L1_SingleJet24_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet28_BptxAND", &L1_SingleJet28_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet28_BptxAND_Prescl", &L1_SingleJet28_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet32_BptxAND", &L1_SingleJet32_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet32_BptxAND_Prescl", &L1_SingleJet32_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet36", &L1_SingleJet36);
	pphlttree->SetBranchAddress("L1_SingleJet36_Prescl", &L1_SingleJet36_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet36_BptxAND", &L1_SingleJet36_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet36_BptxAND_Prescl", &L1_SingleJet36_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet40_BptxAND", &L1_SingleJet40_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet40_BptxAND_Prescl", &L1_SingleJet40_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet44_BptxAND", &L1_SingleJet44_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet44_BptxAND_Prescl", &L1_SingleJet44_BptxAND_Prescl);
	pphlttree->SetBranchAddress("L1_SingleJet48_BptxAND", &L1_SingleJet48_BptxAND);
	pphlttree->SetBranchAddress("L1_SingleJet48_BptxAND_Prescl", &L1_SingleJet48_BptxAND_Prescl);
}

#endif //  anaDntuple_H
