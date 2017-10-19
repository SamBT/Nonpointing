/*
  Created by Haichen Wang November 8, 2012
*/

#include "analysis_truth.hh"


int main (int argc, char **argv) {
  gROOT->ProcessLine(".x rootlogon.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  if (argc < 2) {
    printf("\nUsage: %s *.root\n\n",argv[0]);
    exit(0);
  }
  
  double ptcut = atof(argv[1]);
  double metcut = atof(argv[2]);
  
  cout << "met cut = " << metcut << ", pt cut =  " << ptcut<<endl;
  
  int const index = argc - 3;
  
  TString path[index];
  
  for ( int j = 0; j < argc-3; j++) {
    path[j] = (argv[j+3]);
  }
  
  TChain *chain = new TChain("BH");
  
  for (int k = 0; k < argc-3 ; k++) {
    chain -> Add(path[k]); // Add the root file to the TChain chain
    cout << " adding " << path[k] << endl;
  }
  
  p = new BH(chain);
  
  
  int numev = p->fChain->GetEntries();
  
  double lumi = 35; //units of fb^-1
  TH1F *h_bino_lifetime = new TH1F("h_bino_lifetime","h_bino_lifetime",5000,0,500);
  TH1F *h_CF = new TH1F("h_CF","h_CF",20,0,20);
  TH1F *h_CF_unwt = new TH1F("h_CF_unwt","h_CF_unwt",20,0,20);
  TH1F *h_bino_vertex = new TH1F("h_bino_vertex","h_bino_vertex",1500,0,15000);
  TH1F *h_leading_pt = new TH1F("h_leading_pt","h_leading_pt",2000,0,2000);
  TH1F *h_leading_eta = new TH1F("h_leading_eta","h_leading_eta",500,-2.5,2.5);
  TH1F *h_leading_timing = new TH1F("h_leading_timing","h_leading_timing",200,0,20);
  TH1F *h_leading_pointing = new TH1F("h_leading_pointing","h_leading_pointing",2000,0,2000);
  TH1F *h_subleading_pt = new TH1F("h_subleading_pt","h_subleading_pt",2000,0,2000);
  TH1F *h_subleading_eta = new TH1F("h_subleading_eta","h_subleading_eta",500,-2.5,2.5);
  TH1F *h_subleading_timing = new TH1F("h_subleading_timing","h_subleading_timing",200,0,20);
  TH1F *h_subleading_pointing = new TH1F("h_subleading_pointing","h_subleading_pointing",2000,0,2000);
  TH1F *h_MET = new TH1F("h_MET","h_MET",2000,0,2000);
  TH1F *h_ph1_mass = new TH1F("h_ph1_mass","h_ph1_mass",200,0,200);
  TH1F *h_ph2_mass = new TH1F("h_ph2_mass","h_ph2_mass",200,0,200);
  
  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i) ;
    double wt = lumi*(1000*dsid_xsec(p->RunNumber))/numev;

    double bino2_decay_time = (1e9)*p->tru_v2_d2_r*0.001/(p->tru_b2_vbyc*299792458.)*sqrt(1-(p->tru_b2_vbyc)*(p->tru_b2_vbyc));
    double bino1_decay_time = (1e9)*p->tru_v2_d1_r*0.001/(p->tru_b1_vbyc*299792458.)*sqrt(1-(p->tru_b1_vbyc)*(p->tru_b1_vbyc));
    h_bino_lifetime->Fill(bino1_decay_time, wt);
    h_bino_lifetime->Fill(bino2_decay_time, wt);
    h_bino_vertex->Fill(p->tru_v2_d1_r,wt);
    h_bino_vertex->Fill(p->tru_v2_d2_r,wt);
    

    h_CF->Fill(0.5,wt);
    h_CF_unwt->Fill(0.5);

    if (p->tru_ph1_timing < 0 && p->tru_ph2_timing < 0) continue;
    //Object Definition requirements for one of the photons
    bool passObj1, passObj2;
    passObj1 = false; passObj2 = false;
    double eta1, eta2, phi1, phi2, E1, E2, pt1, pt2, t1, t2, t1_tof, t2_tof;
    eta1 = p->tru_ph1_eta; eta2 = p->tru_ph2_eta; pt1 = p->tru_ph1_pt; pt2 = p->tru_ph2_pt; t1 = p->tru_ph1_timing; t2 = p->tru_ph2_timing; t1_tof = p->tru_ph1_tof; t2_tof = p->tru_ph2_tof;
    phi1 = p->tru_ph1_phi; phi2= p->tru_ph2_phi; E1 = p->tru_ph1_E; E2= p->tru_ph2_E;
    //TLorentzVector ph1, ph2;
    //    ph1.SetPtEtaPhiE(pt1,eta1,phi1,E1);
    //ph2.SetPtEtaPhiE(pt2,eta2,phi2,E2);
    //h_ph1_mass->Fill(ph1.M(), wt);
    //h_ph2_mass->Fill(ph2.M(), wt);
    //if (p->tru_ph1_pdgid != 22 && p->tru_ph2_pdgid != 22) continue;
    if (t1_tof > 0 && pt1 > 25 && p->tru_ph1_pdgid == 22 && (fabs(eta1) < 1.37 || (fabs(eta1) > 1.52 && fabs(eta1) < 2.37))) passObj1 = true;
    if (t2_tof > 0 && pt2 > 25 && p->tru_ph2_pdgid == 22 && (fabs(eta2) < 1.37 || (fabs(eta2) > 1.52 && fabs(eta2) < 2.37))) passObj2 = true;
    if (passObj1 == false && passObj2 == false) continue;
    if (p->tru_ph1_pdgid != 22 || p->tru_ph2_pdgid != 22) continue;
    if (passObj1 == true && passObj2 == false) {
      h_leading_pt->Fill(p->tru_ph1_pt,wt);
      h_leading_eta->Fill(p->tru_ph1_eta,wt);
      h_leading_timing->Fill(p->tru_ph1_timing,wt);
      h_leading_pointing->Fill(p->tru_ph1_pointing,wt);
    }
    else if (passObj1 == false && passObj2 == true) {
      h_leading_pt->Fill(p->tru_ph2_pt,wt);
      h_leading_eta->Fill(p->tru_ph2_eta,wt);
      h_leading_timing->Fill(p->tru_ph2_timing,wt);
      h_leading_pointing->Fill(p->tru_ph2_pointing,wt);
    }
    else {
      int leading = p->tru_ph1_pt > p->tru_ph2_pt ? 1 : 2;
      if (leading == 1) {
        h_leading_pt->Fill(p->tru_ph1_pt,wt);
        h_leading_eta->Fill(p->tru_ph1_eta,wt);
        h_leading_timing->Fill(p->tru_ph1_timing,wt);
        h_leading_pointing->Fill(p->tru_ph1_pointing,wt);
        h_subleading_pt->Fill(p->tru_ph2_pt,wt);
        h_subleading_eta->Fill(p->tru_ph2_eta,wt);
        h_subleading_timing->Fill(p->tru_ph2_timing,wt);
        h_subleading_pointing->Fill(p->tru_ph2_pointing,wt);
      }
      if (leading == 2) {
        h_leading_pt->Fill(p->tru_ph2_pt,wt);
        h_leading_eta->Fill(p->tru_ph2_eta,wt);
        h_leading_timing->Fill(p->tru_ph2_timing,wt);
        h_leading_pointing->Fill(p->tru_ph2_pointing,wt);
        h_subleading_pt->Fill(p->tru_ph1_pt,wt);
        h_subleading_eta->Fill(p->tru_ph1_eta,wt);
        h_subleading_timing->Fill(p->tru_ph1_timing,wt);
        h_subleading_pointing->Fill(p->tru_ph1_pointing,wt);
      }
    }
    h_MET->Fill(p->tru_MET,wt);

    double pt, timing, zdca, eta, phi, met;    
    met = p->tru_MET;
    if (passObj1 == true && passObj2 == false) {
      pt = pt1;
      timing = t1;
      zdca = p->tru_ph1_pointing;
      eta = eta1;
      phi = p->tru_ph1_phi;
    }
    else if (passObj1 == false && passObj2 == true) {
      pt = pt2;
      timing = t2;
      zdca = p->tru_ph2_pointing;
      eta = eta2;
      phi = p->tru_ph2_phi;
    }
    else {
      pt = p->tru_ph1_pt > p->tru_ph2_pt ? p->tru_ph1_pt : p->tru_ph2_pt;
      timing = p->tru_ph1_pt > p->tru_ph2_pt ? p->tru_ph1_timing : p->tru_ph2_timing;
      zdca = p->tru_ph1_pt > p->tru_ph2_pt ? p->tru_ph1_pointing : p->tru_ph2_pointing;
      eta = p->tru_ph1_pt > p->tru_ph2_pt ? p->tru_ph1_eta : p->tru_ph2_eta;
      phi = p->tru_ph1_pt > p->tru_ph2_pt ? p->tru_ph1_phi : p->tru_ph2_phi;
    }

    if (pt > 150) { 
      h_CF->Fill(1.5,wt);
      h_CF_unwt->Fill(1.5);
      if (fabs(eta) < 1.37) {
	h_CF->Fill(2.5,wt);
	h_CF_unwt->Fill(2.5);
	if (met < 20) {h_CF->Fill(3.5,wt);h_CF_unwt->Fill(3.5);}
	if (met > 75) {h_CF->Fill(4.5,wt);h_CF_unwt->Fill(4.5);}
	if (met > 75 && timing > 1.5) {h_CF->Fill(5.5,wt); h_CF_unwt->Fill(5.5);}
	if (met > 75 && timing > 2) {h_CF->Fill(6.5,wt); h_CF_unwt->Fill(6.5);}
	if (met > 200) {h_CF->Fill(7.5,wt);h_CF_unwt->Fill(7.5);}
	if (met > 200 && timing > 1.5) {h_CF->Fill(8.5,wt); h_CF_unwt->Fill(8.5);}
	if (met > 200 && timing > 2) {h_CF->Fill(9.5,wt);h_CF_unwt->Fill(9.5);}
	if (met > 200 && timing > 2 && fabs(zdca) > 200) {h_CF->Fill(10.5,wt);h_CF_unwt->Fill(10.5);}
	if (met > 200 && timing < 4) {h_CF->Fill(11.5,wt); h_CF_unwt->Fill(11.5);}
	
      }
    }

  }
  
  
  // Histograms need to be written into a TFile for further processing
  TFile f("output.root","recreate");
  h_bino_lifetime->Write();
  h_CF->Write();
  h_CF_unwt->Write();
  h_bino_vertex->Write();
  h_leading_pt->Write();
  h_leading_eta->Write();
  h_leading_timing->Write();
  h_leading_pointing->Write();
  h_subleading_pt->Write();
  h_subleading_eta->Write();
  h_subleading_timing->Write();
  h_subleading_pointing->Write();
  h_MET->Write();
  h_ph1_mass->Write();
  h_ph2_mass->Write();
  f.Close();
  
  return 0 ;
}







