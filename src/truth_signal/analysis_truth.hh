#include "TGraphAsymmErrors.h"
#include "TEfficiency.h"
#include "TLatex.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TROOT.h"
#include "THStack.h"
#include "TString.h"
#include "TH1.h"
#include "TH2F.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "RooRealVar.h"
#include "RooExponential.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooAbsData.h"
#include "RooAbsRealLValue.h"
#include "RooAbsPdf.h"
#include "RooMinuit.h"
#include "RooCategory.h"
#include "RooDataSet.h"
#include "RooArgSet.h"
#include "RooDataHist.h"
#include "RooNLLVar.h"
#include "RooSimultaneous.h"
#include "RooExponential.h"
#include "RooGlobalFunc.h"
#include "RooCBShape.h"
#include "RooFormula.h"
#include "RooRandom.h"
#include "RooFitResult.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../aux/BH.hh"
#include "header.hh"
using namespace std;
using namespace RooFit;
#include <sys/stat.h>


BH *p;

void get_event(int i) {
  if ( p->LoadTree(i) < 0) { 
    cout<<"\nProblem in LoadTree."
        <<"\nEntry: "<<i<<endl;
    exit(0);
  }
  p->fChain->GetEntry(i);
}

double dsid_xsec(double dsid) {
  //xsec in nb
  double xsec = 1;
  //double thousands, hundreds;
  //if (dsid >= 1000000) {
  //thousands = dsid - 1000000*((int)dsid/1000000);
  //}
  //else {
  //thousands = dsid - 100000*((int)dsid/100000);
  //}
  //hundreds = thousands - 1000*((int)thousands/1000);
  //int num_hundreds = (int)hundreds/100;
  //int num_thousands = (int)thousands/1000;
  double mg, mx, thousands, hundreds, tens;
  int place, place2, number;
  place = (int)log10(dsid);
  number = (int)(dsid/pow(10,place));
  thousands = dsid - number*pow(10,place);
  place2 = (int)thousands/1000;
  hundreds = thousands - place2*1000;
  if ((int)(hundreds/100) == 0) {
    mg = 1000+place2*100;
    mx = hundreds*100;
  }
  if ((int)(hundreds/100) != 0) {
    mg = (int)(hundreds/100);
    mg = 100*mg;
    mx = (hundreds - mg)*100;
  }

  if (dsid == 403280) {mg = 1000; mx = 900;}
  if (dsid == 403281) {mg = 1300; mx = 100;}
  if (dsid == 403282) {mg = 1300; mx = 1200;}
  if (dsid == 403283) {mg = 1800; mx = 100;}
  if (dsid == 403284) {mg = 1800; mx = 1700;}
  if (dsid == 403285) {mg = 1800; mx = 100;}
  if (dsid == 403286) {mg = 1800; mx = 100;}

  if (mg == 800) xsec = 1.4891; //mg = 800
  if (mg == 900) xsec = 0.677478; //mg = 900
  if (mg == 1000) xsec = 0.325388; //mg = 1000
  if (mg == 1100) xsec = 0.163491; //mg = 1100
  if (mg == 1200) xsec = 0.0856418; //mg = 1200
  if (mg == 1300) xsec = 0.0460525; //mg = 1300 
  if (mg == 1400) xsec = 0.0252977; //mg = 1400 
  if (mg == 1500) xsec = 0.0141903; //mg = 1500 
  if (mg == 1600) xsec = 0.00810078; //mg = 1600 
  if (mg == 1700) xsec = 0.00470323; //mg = 1700 
  if (mg == 1800) xsec = 0.00276133; //mg = 1800 
  if (mg == 1900) xsec = 0.00163547; //mg = 1900 
  if (mg == 2000) xsec = 0.000981077; //mg = 2000 
  if (mg == 2100) xsec = 0.000591918; //mg = 2100 
  if (mg == 2200) xsec = 0.000359318; //mg = 2200 
  return xsec;
}

double significance( double s , double b)
{
  return sqrt(2*((s+b)*log(1+s/b)-s));
  // see eq 97 of  https://arxiv.org/pdf/1007.1727v3.pdf
}
