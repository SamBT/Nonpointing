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
  
  int const index = argc - 1;
  
  TString path[index];
  
  for ( int j = 0; j < argc-1; j++) {
    path[j] = (argv[j+1]);
  }
  
  TChain *chain = new TChain("BH");
  
  for (int k = 0; k < argc-1 ; k++) {
    chain -> Add(path[k]); // Add the root file to the TChain chain
    cout << " adding " << path[k] << endl;
  }
  
  p = new BH(chain);
  
  
  int numev = p->fChain->GetEntries();

  vector<double> zdca_bins = {0,40,80,120,160,200,2000};
  vector<double> timing_bins = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};
  
  double lumi = 32.8446; //units of fb^-1
  TH1F *h_bino_lifetime = new TH1F("h_bino_lifetime","h_bino_lifetime",5000,0,500);
  TH1F *h_CF_single = new TH1F("h_CF_single","h_CF_single",40,0,40);
  TH1F *h_CF_unwt_single = new TH1F("h_CF_unwt_single","h_CF_unwt_single",40,0,40);
  TH1F *h_CF_di = new TH1F("h_CF_di","h_CF_di",40,0,40);
  TH1F *h_CF_unwt_di = new TH1F("h_CF_unwt_di","h_CF_unwt_di",40,0,40);
  TH1F *h_bino_vertex = new TH1F("h_bino_vertex","h_bino_vertex",1500,0,15000);
  TH1F *h_MET = new TH1F("h_MET","h_MET",2000,0,2000);

  TH1F *h_ZDCA_CR_di = new TH1F("h_ZDCA_CR_di","h_ZDCA_CR_di",6,0,6);
  TH1F *h_ZDCA_SR_di = new TH1F("h_ZDCA_SR_di","h_ZDCA_SR_di",6,0,6);
  TH1F *h_ZDCA_unwt_CR_di = new TH1F("h_ZDCA_unwt_CR_di","h_ZDCA_unwt_CR_di",6,0,6);
  TH1F *h_ZDCA_unwt_SR_di = new TH1F("h_ZDCA_unwt_SR_di","h_ZDCA_unwt_SR_di",6,0,6);

  TH2F *h_timing_ZDCA_SR_di = new TH2F("h_timing_ZDCA_SR_di","h_timing_ZDCA_SR_di",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_CR_di = new TH2F("h_timing_ZDCA_CR_di","h_timing_ZDCA_CR_di",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_unwt_SR_di = new TH2F("h_timing_ZDCA_unwt_SR_di","h_timing_ZDCA_unwt_SR_di",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_unwt_CR_di = new TH2F("h_timing_ZDCA_unwt_CR_di","h_timing_ZDCA_unwt_CR_di",6,0,6,6,0,6);

  TH1F *h_ZDCA_CR_single = new TH1F("h_ZDCA_CR_single","h_ZDCA_CR_single",6,0,6);
  TH1F *h_ZDCA_SR_single = new TH1F("h_ZDCA_SR_single","h_ZDCA_SR_single",6,0,6);
  TH1F *h_ZDCA_unwt_CR_single = new TH1F("h_ZDCA_unwt_CR_single","h_ZDCA_unwt_CR_single",6,0,6);
  TH1F *h_ZDCA_unwt_SR_single = new TH1F("h_ZDCA_unwt_SR_single","h_ZDCA_unwt_SR_single",6,0,6);

  TH2F *h_timing_ZDCA_SR_single = new TH2F("h_timing_ZDCA_SR_single","h_timing_ZDCA_SR_single",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_CR_single = new TH2F("h_timing_ZDCA_CR_single","h_timing_ZDCA_CR_single",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_unwt_SR_single = new TH2F("h_timing_ZDCA_unwt_SR_single","h_timing_ZDCA_unwt_SR_single",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_unwt_CR_single = new TH2F("h_timing_ZDCA_unwt_CR_single","h_timing_ZDCA_unwt_CR_single",6,0,6,6,0,6);
  
  //This is a combined analysis -- singlephoton for events with only one photon passing obj selection, diphoton for events with two photons passing obj selection. In the singlephoton case,
  //we allow events where one of the objects is not a photon, e.g. W + gamma
  
  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i) ;
    double wt = lumi*(1000*dsid_xsec(p->RunNumber))/numev;

    double bino2_decay_time = (1e9)*p->tru_v2_d2_r*0.001/(p->tru_b2_vbyc*299792458.)*sqrt(1-(p->tru_b2_vbyc)*(p->tru_b2_vbyc));
    double bino1_decay_time = (1e9)*p->tru_v1_d2_r*0.001/(p->tru_b1_vbyc*299792458.)*sqrt(1-(p->tru_b1_vbyc)*(p->tru_b1_vbyc));
    h_bino_lifetime->Fill(bino1_decay_time, wt);
    h_bino_lifetime->Fill(bino2_decay_time, wt);
    h_bino_vertex->Fill(p->tru_v2_d1_r,wt);
    h_bino_vertex->Fill(p->tru_v2_d2_r,wt);

    h_CF_single->Fill(0.5,wt);
    h_CF_unwt_single->Fill(0.5);
    h_CF_di->Fill(0.5,wt);
    h_CF_unwt_di->Fill(0.5);

    
    //if (p->tru_ph1_pdgid != 22 || p->tru_ph2_pdgid != 22) continue; //Veto any events where one or both of the "photons" are not photons (i.e. bino decays to W, Z, or Higgs)
    //For singlephoton, we are now allowing events where one of the objects is not a photon on the level of pdgid (i.e. it is a W or something)
    
    //Object Definition requirements for the photons 
    bool passObj1, passObj2;
    bool singlephoton, diphoton; //flags that tell whether to do single or diphoton selection
    singlephoton = false; diphoton = false;
    passObj1 = false; passObj2 = false;
    double eta1, eta2, phi1, phi2, E1, E2, pt1, pt2, t1, t2, t1_tof, t2_tof;
    eta1 = p->tru_ph1_eta; eta2 = p->tru_ph2_eta; pt1 = p->tru_ph1_pt; pt2 = p->tru_ph2_pt; t1 = p->tru_ph1_timing; t2 = p->tru_ph2_timing; t1_tof = p->tru_ph1_tof; t2_tof = p->tru_ph2_tof;
    phi1 = p->tru_ph1_phi; phi2 = p->tru_ph2_phi; E1 = p->tru_ph1_E; E2 = p->tru_ph2_E;
    if (t1_tof > 0 && pt1 > 25 && p->tru_ph1_pdgid == 22 && (fabs(eta1) < 1.37 || (fabs(eta1) > 1.52 && fabs(eta1) < 2.37))) passObj1 = true;
    if (t2_tof > 0 && pt2 > 25 && p->tru_ph2_pdgid == 22 && (fabs(eta2) < 1.37 || (fabs(eta2)> 1.52 && fabs(eta2) < 2.37))) passObj2= true;
    if (passObj1 == false && passObj2 == false) continue; //If neither of photons are "true" photon objects, skip event
    
    h_MET->Fill(p->tru_MET,wt);

    if (passObj1 == false || passObj2 == false) diphoton = false;  //Diphoton selection requires two true photon objects
    if (passObj1 && passObj2) diphoton = true; //Do diphoton analysis only if both photons pass object selection
    if ( (passObj1 && !passObj2) || (!passObj1 && passObj2) ) singlephoton = true; //Singlephoton events only where there's exactly one photon passing object selection 

    double pt, timing, zdca, eta, phi, met;  //Initializing variables
    int pointing_bin, timing_bin;
    met = p->tru_MET;

    if (singlephoton) {
      if (passObj1 == true && passObj2 == false) {
	pt = pt1;
	timing = t1;
	zdca = p->tru_ph1_pointing;
	eta = eta1;
	phi = p->tru_ph1_phi;
      }
      if (passObj1 == false && passObj2 == true) {
	pt = pt2;
	timing = t2;
	zdca = p->tru_ph2_pointing;
	eta = eta2;
	phi = p->tru_ph2_phi;
      }
      for (int r = 0; r < zdca_bins.size()-1; r++) {
        if (fabs(zdca) > zdca_bins[r] && fabs(zdca) < zdca_bins[r+1]) pointing_bin = r;
        if (timing > timing_bins[r] && timing < timing_bins[r]) timing_bin = r;
      }
      h_CF_single->Fill(1.5,wt);
      h_CF_unwt_single->Fill(1.5);
      if (pt > 150) { 
	h_CF_single->Fill(2.5,wt);
	h_CF_unwt_single->Fill(2.5);
	if (fabs(eta) < 1.37) {
	  h_CF_single->Fill(3.5,wt);
	  h_CF_unwt_single->Fill(3.5);

	  if (met < 20) {h_CF_single->Fill(4.5,wt);h_CF_unwt_single->Fill(4.5);}

	  if (met < 20) {h_ZDCA_CR_single->Fill(pointing_bin,wt); h_ZDCA_unwt_CR_single->Fill(pointing_bin,wt);h_timing_ZDCA_CR_single->Fill(timing_bin,pointing_bin,wt); h_timing_ZDCA_unwt_CR_single->Fill(timing_bin,pointing_bin,wt);}
          if (met > 200 && timing < 4) {h_ZDCA_SR_single->Fill(pointing_bin,wt); h_ZDCA_unwt_SR_single->Fill(pointing_bin,wt);h_timing_ZDCA_SR_single->Fill(timing_bin,pointing_bin,wt); h_timing_ZDCA_unwt_SR_single->Fill(timing_bin,pointing_bin,wt);}

	  if (met > 75 && timing < 4) {h_CF_single->Fill(5.5,wt);h_CF_unwt_single->Fill(5.5);}
	  if (met > 75 && timing > 1.5) {h_CF_single->Fill(6.5,wt); h_CF_unwt_single->Fill(6.5);}
	  if (met > 75 && timing > 2) {h_CF_single->Fill(7.5,wt); h_CF_unwt_single->Fill(7.5);}
	  if (met > 200 && timing < 4) {h_CF_single->Fill(8.5,wt);h_CF_unwt_single->Fill(8.5);}
	  if (met > 200 && timing > 1.5) {h_CF_single->Fill(9.5,wt); h_CF_unwt_single->Fill(9.5);}
	  if (met > 200 && timing > 2) {h_CF_single->Fill(10.5,wt);h_CF_unwt_single->Fill(10.5);}
	  if (met > 200 && timing > 2 && fabs(zdca) > 200) {h_CF_single->Fill(11.5,wt);h_CF_unwt_single->Fill(11.5);}
	  if (met > 200 && timing > 2 && timing < 4) {h_CF_single->Fill(12.5,wt); h_CF_unwt_single->Fill(12.5);}
        
	}
      }
    }

    if (diphoton) {
      h_CF_di->Fill(1.5,wt);
      h_CF_unwt_di->Fill(1.5);
      if (pt1 < 50 || pt2 < 50) continue;
      h_CF_di->Fill(2.5,wt); //pt > 50 for both
      h_CF_unwt_di->Fill(2.5);
      if (fabs(eta1) > 1.37 && fabs(eta2) > 1.37) continue;
      h_CF_di->Fill(3.5,wt); //at least one photon in barrel
      h_CF_unwt_di->Fill(3.5);
      if (fabs(eta1) < 1.37 && fabs(eta2) > 1.37) {
	pt = pt1;
	timing = t1;
	zdca = p->tru_ph1_pointing;
	eta = eta1;
	phi = p->tru_ph1_phi;
      }
      else if (fabs(eta1) > 1.37 && fabs(eta2) < 1.37) {
	pt = pt2;
	timing = t2;
	zdca = p->tru_ph2_pointing;
	eta = eta2;
	phi = p->tru_ph2_phi;
      }
      else {
	pt = p->tru_ph1_timing > p->tru_ph2_timing ? p->tru_ph1_pt : p->tru_ph2_pt;
	timing = p->tru_ph1_timing > p->tru_ph2_timing ? p->tru_ph1_timing : p->tru_ph2_timing;
	zdca = p->tru_ph1_timing > p->tru_ph2_timing ? p->tru_ph1_pointing : p->tru_ph2_pointing;
	eta = p->tru_ph1_timing > p->tru_ph2_timing ? p->tru_ph1_eta : p->tru_ph2_eta;
	phi = p->tru_ph1_timing > p->tru_ph2_timing ? p->tru_ph1_phi : p->tru_ph2_phi;
      }

      for (int r = 0; r < zdca_bins.size()-1; r++) {
        if (fabs(zdca) > zdca_bins[r] && fabs(zdca) < zdca_bins[r+1]) pointing_bin = r;
        if (timing > timing_bins[r] && timing < timing_bins[r+1]) timing_bin = r;
      }

      if (met < 20) {h_ZDCA_CR_di->Fill(pointing_bin,wt); h_ZDCA_unwt_CR_di->Fill(pointing_bin,wt); h_timing_ZDCA_CR_di->Fill(timing_bin, pointing_bin,wt); h_timing_ZDCA_unwt_CR_di->Fill(timing_bin,pointing_bin,wt);}
      if (met > 75 && timing < 4) {h_ZDCA_SR_di->Fill(pointing_bin,wt); h_ZDCA_unwt_SR_di->Fill(pointing_bin,wt);h_timing_ZDCA_SR_di->Fill(timing_bin,pointing_bin,wt);h_timing_ZDCA_unwt_SR_di->Fill(timing_bin,pointing_bin,wt);}
      
      if (met < 20) {h_CF_di->Fill(4.5,wt);h_CF_unwt_di->Fill(4.5);}
      if (met > 75 && timing < 4) {h_CF_di->Fill(5.5,wt);h_CF_unwt_di->Fill(5.5);}
      if (met > 75 && timing > 1.5) {h_CF_di->Fill(6.5,wt); h_CF_unwt_di->Fill(6.5);}
      if (met > 75 && timing > 2) {h_CF_di->Fill(7.5,wt);h_CF_unwt_di->Fill(7.5);}
      if (met > 75 && timing > 2 && fabs(zdca) > 200) {h_CF_di->Fill(8.5,wt);h_CF_unwt_di->Fill(8.5);}
      if (met > 75 && timing > 2 && timing < 4) {h_CF_di->Fill(9.5,wt); h_CF_unwt_di->Fill(9.5);}
    }
  
}
  
  
  // Histograms need to be written into a TFile for further processing
  TFile f("output.root","recreate");
  h_bino_lifetime->Write();
  h_CF_single->Write();
  h_CF_unwt_single->Write();
  h_CF_di->Write();
  h_CF_unwt_di->Write();
  h_bino_vertex->Write();
  h_MET->Write();
  h_ZDCA_CR_di->Write();
  h_ZDCA_SR_di->Write();
  h_ZDCA_unwt_CR_di->Write();
  h_ZDCA_unwt_SR_di->Write();
  h_timing_ZDCA_CR_di->Write();
  h_timing_ZDCA_SR_di->Write();
  h_timing_ZDCA_unwt_CR_di->Write();
  h_timing_ZDCA_unwt_SR_di->Write();
  h_ZDCA_CR_single->Write();
  h_ZDCA_SR_single->Write();
  h_ZDCA_unwt_CR_single->Write();
  h_ZDCA_unwt_SR_single->Write();
  h_timing_ZDCA_CR_single->Write();
  h_timing_ZDCA_SR_single->Write();
  h_timing_ZDCA_unwt_CR_single->Write();
  h_timing_ZDCA_unwt_SR_single->Write();
  f.Close();
  
  return 0 ;
}







