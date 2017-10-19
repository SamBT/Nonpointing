#include "analysis.hh"
//#include "SUSYxsec.hh"
#include "DSinfo.hh"

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
  
  TChain *chain = new TChain("output");
  
  for (int k = 0; k < argc-1 ; k++) {
    chain -> Add(path[k]); // Add the root file to the TChain chain
    cout << " adding " << path[k] << endl;
  }
  
  p = new output(chain);
  
  
  int numev = p->fChain->GetEntries();

  vector<double> zdca_bins = {0,40,80,120,160,200,2000};
  vector<double> timing_bins = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};
  
  double lumi = 32.8446; //units of fb^-1

  TH1F *h_CF = new TH1F("h_CF","h_CF",40,0,40);
  TH1F *h_CF_unwt = new TH1F("h_CF_unwt","h_CF_unwt",40,0,40);

  TH1F *h_ZDCA_CR = new TH1F("h_ZDCA_CR","h_ZDCA_CR",6,0,6);
  TH1F *h_ZDCA_SR = new TH1F("h_ZDCA_SR","h_ZDCA_SR",6,0,6);
  TH2F *h_timing_ZDCA_est_SR_yield = new TH2F("h_timing_ZDCA_est_SR_yield","h_timing_ZDCA_est_SR_yield",6,0,6,6,0,6);
  TH1F *h_ZDCA_unwt_CR = new TH1F("h_ZDCA_unwt_CR","h_ZDCA_unwt_SR",6,0,6);
  TH1F *h_ZDCA_unwt_SR = new TH1F("h_ZDCA_unwt_SR","h_ZDCA_unwt_SR",6,0,6);
  TH2F *h_timing_ZDCA_unwt_est_SR_yield = new TH2F("h_timing_ZDCA_unwt_est_SR_yield","h_timing_ZDCA_unwt_est_SR_yield",6,0,6,6,0,6);

  TH2F *h_timing_ZDCA_SR = new TH2F("h_timing_ZDCA_SR","h_timing_ZDCA_SR",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_CR = new TH2F("h_timing_ZDCA_CR","h_timing_ZDCA_CR",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_unwt_SR = new TH2F("h_timing_ZDCA_unwt_SR","h_timing_ZDCA_unwt_SR",6,0,6,6,0,6);
  TH2F *h_timing_ZDCA_unwt_CR = new TH2F("h_timing_ZDCA_unwt_CR","h_timing_ZDCA_unwt_CR",6,0,6,6,0,6);

  TH2F *h_Ecell_gain = new TH2F("h_Ecell_gain","h_Ecell_gain",1000,0,1000,3,0,3);
  TH2F *h_E_gain = new TH2F("h_E_gain","h_E_gain",2000,0,2000,3,0,3);
  TH2F *h_pt_gain = new TH2F("h_pt_gain","h_pt_gain",2000,0,2000,3,0,3);

  TH1F *h_pointing = new TH1F("h_pointing","h_pointing",4000,-2000,2000);
  TH1F *h_abs_pointing = new TH1F("h_abs_pointing","h_abs_pointing",2000,0,2000);
  TH1F *h_timing = new TH1F("h_timing","h_timing",400,-20,20);
  TH1F *h_MET = new TH1F("h_MET","h_MET",2000,0,2000);

  TH1F *h_pointing_lowgainveto = new TH1F("h_pointing_lowgainveto","h_pointing_lowgainveto",4000,-2000,2000);
  TH1F *h_abs_pointing_lowgainveto = new TH1F("h_abs_pointing_lowgainveto","h_abs_pointing_lowgainveto",2000,0,2000);
  TH1F *h_timing_lowgainveto = new TH1F("h_timing_lowgainveto","h_timing_lowgainveto",400,-20,20);
  TH1F *h_MET_lowgainveto = new TH1F("h_MET_lowgainveto","h_MET_lowgainveto",2000,0,2000);

  TEfficiency *h_subleading_ZDCA_loose_eff = new TEfficiency("h_subleading_ZDCA_loose_eff","h_subleading_ZDCA_loose_eff",50,0,2000);
  TEfficiency *h_subleading_ZDCA_loose_eff_pt50 = new TEfficiency("h_subleading_ZDCA_loose_eff_pt50","h_subleading_ZDCA_loose_eff_pt50",50,0,2000);
  TEfficiency *h_subleading_ZDCA_loose_eff_pt100 = new TEfficiency("h_subleading_ZDCA_loose_eff_pt100","h_subleading_ZDCA_loose_eff_pt100",50,0,2000);
  TEfficiency *h_subleading_ZDCA_loose_eff_pt150 = new TEfficiency("h_subleading_ZDCA_loose_eff_pt150","h_subleading_ZDCA_loose_eff_pt150",50,0,2000);
  TEfficiency *h_subleading_ZDCA_loose_eff_pt200 = new TEfficiency("h_subleading_ZDCA_loose_eff_pt200","h_subleading_ZDCA_loose_eff_pt200",50,0,2000);
  
  h_timing_ZDCA_est_SR_yield->Sumw2();
  h_timing_ZDCA_unwt_est_SR_yield->Sumw2();

  get_event(0);
  //int runNumber = p->runNumber;
  int DSID = p->m_mcChannelNumber;
  bool isData = p->m_mcChannelNumber < 0 ;
  map<string,double> sample = DSinfo( p->m_mcChannelNumber );
  double xs = sample["xs"];
  int mg = sample["mg"];
  int mx = sample["mx"];
  double lifetime = sample["t"];
  int Nevents = 20000;
  TString cf, cf_unwt;
  cf.Form("h_CF_%i",DSID);
  cf_unwt.Form("h_CF_unwt_%i",DSID);
  TH1F *h_CF_run = new TH1F(cf,cf,40,0,40);
  TH1F *h_CF_unwt_run = new TH1F(cf_unwt,cf_unwt,40,0,40);
  
  //This is a combined analysis -- singlephoton for events with only one photon passing obj selection, diphoton for events with two photons passing obj selection. In the singlephoton case,
  //we allow events where one of the objects is not a photon, e.g. W + gamma
  
  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i) ;
    double wt =  1;

    if( !isData) wt = lumi*1000*xs/Nevents;
    if( !isData && p->m_mcChannelNumber >= 403280 && p->m_mcChannelNumber <= 403286) wt = lumi*1000*1000*p->wt_xs*p->wt_ge/p->wt_nEvents ;

    //Filling CF underflow with total Nevents
    h_CF->Fill(0.5,wt);
    h_CF_unwt->Fill(0.5);
    h_CF_run->Fill(0.5,wt);
    h_CF_unwt_run->Fill(0.5);
    
    //Object Definition requirements for the photons 
    bool passObj1, passObj2;
    bool singlephoton, diphoton; //flags that tell whether to do single or diphoton selection
    singlephoton = false; diphoton = false;
    passObj1 = false; passObj2 = false;
    double eta1, eta2, phi1, phi2, E1, E2, pt1, pt2, t1, t2;
    eta1 = p->ph_eta1; eta2 = p->ph_eta2; pt1 = p->ph_pt1; pt2 = p->ph_pt2; t1 = p->ph_t1; t2 = p->ph_t2;
    phi1 = p->ph_phi1; phi2 = p->ph_phi2; E1 = p->ph1_maxEcell_E/1000; E2 = p->ph2_maxEcell_E/1000;
    if (pt1 > 0 && (fabs(eta1) < 1.37 || (fabs(eta1) > 1.52 && fabs(eta1) < 2.37))) passObj1 = true;
    if (pt2 > 0 && (fabs(eta2) < 1.37 || (fabs(eta2)> 1.52 && fabs(eta2) < 2.37))) passObj2= true;
    if (passObj1 == false && passObj2 == false) continue; //If neither of photons are "true" photon objects, skip event

    double pointing1 = p->ph_calo_z1 - p->PV_z;
    double pointing2 = p->ph_calo_z2 - p->PV_z;

    if (passObj1 && !passObj2) singlephoton = true;
    if (passObj1 && passObj2) diphoton = true;

    double pt, timing, zdca, eta, phi, met, Ecell, gain, E;  //Initializing variables
    int pointing_bin, iso, timing_bin;
    met = p->m_met;

    if (singlephoton) {
      if (passObj1 == true && passObj2 == false) {
	pt = pt1;
	timing = t1;
	zdca = pointing1;
	eta = eta1;
	phi = p->ph_phi1;
	iso = p->ph_passIso1;
	Ecell = p->ph1_maxEcell_E;
	gain = p->ph1_maxEcell_gain;
	E = E1;
      }
      if (passObj1 == false && passObj2 == true) {
	pt = pt2;
	timing = t2;
	zdca = pointing2;
	eta = eta2;
	phi = p->ph_phi2;
	iso = p->ph_passIso2;
	Ecell = p->ph2_maxEcell_E;
	gain = p->ph2_maxEcell_gain;
	E = E2;
      }
      for (int r = 0; r < zdca_bins.size()-1; r++) {
	if (fabs(zdca) > zdca_bins[r] && fabs(zdca) < zdca_bins[r+1]) pointing_bin = r;
	if (timing > timing_bins[r] && timing < timing_bins[r]) timing_bin = r;
      }
      h_CF->Fill(1.5,wt);
      h_CF_unwt->Fill(1.5);
      h_CF_run->Fill(1.5,wt);
      h_CF_unwt_run->Fill(1.5);
      if (pt > 150) { 
	h_CF->Fill(2.5,wt);
	h_CF_unwt->Fill(2.5);
	h_CF_run->Fill(2.5,wt);
	h_CF_unwt_run->Fill(2.5);
	if (fabs(eta) < 1.37) {
	  h_CF->Fill(3.5,wt);
	  h_CF_unwt->Fill(3.5);
	  h_CF_run->Fill(3.5,wt);
	  h_CF_unwt_run->Fill(3.5);

	  h_timing->Fill(timing,wt);
	  h_pointing->Fill(zdca,wt);
	  h_abs_pointing->Fill(fabs(zdca),wt);
	  h_MET->Fill(met,wt);
	  if (gain != 2) {
	    h_timing_lowgainveto->Fill(timing,wt);
	    h_pointing_lowgainveto->Fill(zdca,wt);
	    h_abs_pointing_lowgainveto->Fill(fabs(zdca),wt);
	    h_MET_lowgainveto->Fill(met,wt);
	  }

	  h_Ecell_gain->Fill(Ecell/1000,gain,wt);
	  h_E_gain->Fill(E,gain,wt);
	  h_pt_gain->Fill(pt,gain,wt);
	  
	  if (met < 20 && iso) {h_ZDCA_CR->Fill(pointing_bin,wt); h_ZDCA_unwt_CR->Fill(pointing_bin,wt);h_timing_ZDCA_CR->Fill(timing_bin,pointing_bin,wt); h_timing_ZDCA_unwt_CR->Fill(timing_bin,pointing_bin,wt);}
	  if (met > 200 && iso && timing < 4) {h_ZDCA_SR->Fill(pointing_bin,wt); h_ZDCA_unwt_SR->Fill(pointing_bin,wt);h_timing_ZDCA_SR->Fill(timing_bin,pointing_bin,wt); h_timing_ZDCA_unwt_SR->Fill(timing_bin,pointing_bin,wt);}
	  
	  if (met < 20 && iso) {
	    h_timing_ZDCA_est_SR_yield->Fill(timing_bin,pointing_bin,wt*(h_ZDCA_SR->GetBinContent(pointing_bin+1)/h_ZDCA_CR->GetBinContent(pointing_bin+1)));
	    h_timing_ZDCA_unwt_est_SR_yield->Fill(timing_bin,pointing_bin,h_ZDCA_SR->GetBinContent(pointing_bin+1)/h_ZDCA_CR->GetBinContent(pointing_bin+1));
	  }
	  
	  if (met < 20) {h_CF->Fill(4.5,wt);h_CF_unwt->Fill(4.5);h_CF_run->Fill(4.5,wt);h_CF_unwt_run->Fill(4.5);}
	  if (!iso) continue;
	  if (met > 75 && timing < 4) {h_CF->Fill(5.5,wt);h_CF_unwt->Fill(5.5);h_CF_run->Fill(5.5,wt);h_CF_unwt_run->Fill(5.5);}
	  if (met > 75 && timing > 1.5) {h_CF->Fill(6.5,wt); h_CF_unwt->Fill(6.5);h_CF_run->Fill(6.5,wt);h_CF_unwt_run->Fill(6.5);}
	  if (met > 75 && timing > 2) {h_CF->Fill(7.5,wt); h_CF_unwt->Fill(7.5);h_CF_run->Fill(7.5,wt);h_CF_unwt_run->Fill(7.5);}
	  if (met > 200 && timing < 4) {h_CF->Fill(8.5,wt);h_CF_unwt->Fill(8.5);h_CF_run->Fill(8.5,wt);h_CF_unwt_run->Fill(8.5);}
	  if (met > 200 && timing > 1.5) {h_CF->Fill(9.5,wt); h_CF_unwt->Fill(9.5);h_CF_run->Fill(9.5,wt);h_CF_unwt_run->Fill(9.5);}
	  if (met > 200 && timing > 2) {h_CF->Fill(10.5,wt);h_CF_unwt->Fill(10.5);h_CF_run->Fill(10.5,wt);h_CF_unwt_run->Fill(10.5);}
	  if (met > 200 && timing > 2 && fabs(zdca) > 200) {h_CF->Fill(11.5,wt);h_CF_unwt->Fill(11.5);h_CF_run->Fill(11.5,wt);h_CF_unwt_run->Fill(11.5);}
	  if (met > 200 && timing > 2 && timing < 4) {h_CF->Fill(12.5,wt); h_CF_unwt->Fill(12.5);h_CF_run->Fill(12.5,wt);h_CF_unwt_run->Fill(12.5);}

	  if (gain != 2) {
	    if (met > 75 && timing < 4) {h_CF->Fill(13.5,wt);h_CF_unwt->Fill(13.5);h_CF_run->Fill(13.5,wt);h_CF_unwt_run->Fill(13.5);}
	    if (met > 75 && timing > 1.5) {h_CF->Fill(14.5,wt); h_CF_unwt->Fill(14.5);h_CF_run->Fill(14.5,wt);h_CF_unwt_run->Fill(14.5);}
	    if (met > 75 && timing > 2) {h_CF->Fill(15.5,wt); h_CF_unwt->Fill(15.5);h_CF_run->Fill(15.5,wt);h_CF_unwt_run->Fill(15.5);}
	    if (met > 200 && timing < 4) {h_CF->Fill(16.5,wt);h_CF_unwt->Fill(16.5);h_CF_run->Fill(16.5,wt);h_CF_unwt_run->Fill(16.5);}
	    if (met > 200 && timing > 1.5) {h_CF->Fill(17.5,wt); h_CF_unwt->Fill(17.5);h_CF_run->Fill(17.5,wt);h_CF_unwt_run->Fill(17.5);}
	    if (met > 200 && timing > 2) {h_CF->Fill(18.5,wt);h_CF_unwt->Fill(18.5);h_CF_run->Fill(18.5,wt);h_CF_unwt_run->Fill(18.5);}
	    if (met > 200 && timing > 2 && fabs(zdca) > 200) {h_CF->Fill(19.5,wt);h_CF_unwt->Fill(19.5);h_CF_run->Fill(19.5,wt);h_CF_unwt_run->Fill(19.5);}
	    if (met > 200 && timing > 2 && timing < 4) {h_CF->Fill(20.5,wt); h_CF_unwt->Fill(20.5);h_CF_run->Fill(20.5,wt);h_CF_unwt_run->Fill(20.5);}
	  }

	}
      }
    }

    if (diphoton) {
      iso = p->ph_passIso1 && p->ph_passIso2;
      //Choosing which photon to use
      if (fabs(eta1) < 1.37 && fabs(eta2) > 1.37) {
        pt = pt1;
        timing = t1;
        zdca = pointing1;
        eta = eta1;
        phi = p->ph_phi1;
	Ecell =p->ph1_maxEcell_E;
	gain = p->ph1_maxEcell_gain;
	E = E1;
      }
      else if (fabs(eta1) > 1.37 && fabs(eta2) < 1.37) {
        pt = pt2;
        timing = t2;
        zdca = pointing2;
        eta = eta2;
        phi = p->ph_phi2;
	Ecell =p->ph2_maxEcell_E;
	gain = p->ph2_maxEcell_gain;
	E = E2;
      }
      else {
        pt = p->ph_t1 > p->ph_t2 ? p->ph_pt1 : p->ph_pt2;
        timing = p->ph_t1 > p->ph_t2 ? p->ph_t1 : p->ph_t2;
        zdca = p->ph_t1 > p->ph_t2 ? pointing1 : pointing2;
        eta = p->ph_t1 > p->ph_t2 ? p->ph_eta1 : p->ph_eta2;
        phi = p->ph_t1 > p->ph_t2 ? p->ph_phi1 : p->ph_phi2;
	gain = p->ph_t1 > p->ph_t2 ? p->ph1_maxEcell_gain : p->ph2_maxEcell_gain;
	Ecell = p->ph_t1 > p->ph_t2 ? p->ph1_maxEcell_E : p->ph2_maxEcell_E;
	E = p->ph_t1 > p->ph_t2 ? E1 : E2;
      }
      //Doing cuts

      h_CF->Fill(1.5,wt);
      h_CF_unwt->Fill(1.5);
      h_CF_run->Fill(1.5,wt);
      h_CF_unwt_run->Fill(1.5);

      //Loose efficiency in subleading photon for events passing HLT_g140_loose
      if (!isData) {
	double dR21, dR22;
	dR21 = delta_R(eta2,phi2,p->truth_ph_eta1,p->truth_ph_phi2);
	dR22 = delta_R(eta2,phi2,p->truth_ph_eta2,p->truth_ph_phi2);
	if (p->HLT_g140_loose && fabs(eta2) < 1.37 && pt2 > 50 && (dR21 < 0.1 || dR22 < 0.1)) h_subleading_ZDCA_loose_eff->Fill(p->ph_isLoose2, fabs(pointing2));
      }
      else if (isData) {
	if (p->ph_isTight1 && p->ph_passIso1 && p->HLT_g140_loose && fabs(eta2) < 1.37) {
	  if (pt2 > 50) h_subleading_ZDCA_loose_eff_pt50->Fill(p->ph_isLoose2,fabs(pointing2));
	  if (pt2 > 100) h_subleading_ZDCA_loose_eff_pt100->Fill(p->ph_isLoose2,fabs(pointing2));
	  if (pt2 > 150) h_subleading_ZDCA_loose_eff_pt150->Fill(p->ph_isLoose2,fabs(pointing2));
	  if (pt2 > 200) h_subleading_ZDCA_loose_eff_pt200->Fill(p->ph_isLoose2,fabs(pointing2));
	}
      }

      if (pt1 < 50 || pt2 < 50) continue;

      h_CF->Fill(2.5,wt); //pt > 50 for both
      h_CF_unwt->Fill(2.5);
      h_CF_run->Fill(2.5,wt);
      h_CF_unwt_run->Fill(2.5);

      if (fabs(eta1) > 1.37 && fabs(eta2) > 1.37) continue;
      h_CF->Fill(3.5,wt); //at least one photon in barrel
      h_CF_unwt->Fill(3.5);
      h_CF_run->Fill(3.5,wt);
      h_CF_unwt_run->Fill(3.5);

      h_timing->Fill(timing,wt);
      h_pointing->Fill(zdca,wt);
      h_abs_pointing->Fill(fabs(zdca),wt);
      h_MET->Fill(met,wt);

      if (p->ph1_maxEcell_gain != 2 && p->ph2_maxEcell_gain != 2) {
	h_timing_lowgainveto->Fill(timing,wt);
	h_pointing_lowgainveto->Fill(zdca,wt);
	h_abs_pointing_lowgainveto->Fill(fabs(zdca),wt);
	h_MET_lowgainveto->Fill(met,wt);
      }

      h_Ecell_gain->Fill(Ecell/1000,gain,wt);
      h_E_gain->Fill(E,gain,wt);
      h_pt_gain->Fill(pt,gain,wt);

      for (int r = 0; r < zdca_bins.size()-1; r++) {
        if (fabs(zdca) > zdca_bins[r] && fabs(zdca) < zdca_bins[r+1]) pointing_bin = r;
	if (timing > timing_bins[r] && timing < timing_bins[r+1]) timing_bin = r;
      }

      if (met < 20 && iso) {h_ZDCA_CR->Fill(pointing_bin,wt); h_ZDCA_unwt_CR->Fill(pointing_bin,wt); h_timing_ZDCA_CR->Fill(timing_bin,pointing_bin,wt); h_timing_ZDCA_unwt_CR->Fill(timing_bin,pointing_bin,wt);}
      if (met > 75 && iso && timing < 4) {h_ZDCA_SR->Fill(pointing_bin,wt); h_ZDCA_unwt_SR->Fill(pointing_bin,wt);h_timing_ZDCA_SR->Fill(timing_bin,pointing_bin,wt); h_timing_ZDCA_unwt_SR->Fill(timing_bin,pointing_bin,wt);}

      if (met < 20 && iso) {
	h_timing_ZDCA_est_SR_yield->Fill(timing_bin,pointing_bin,wt*(h_ZDCA_SR->GetBinContent(pointing_bin+1)/h_ZDCA_CR->GetBinContent(pointing_bin+1)));
	h_timing_ZDCA_unwt_est_SR_yield->Fill(timing_bin,pointing_bin,h_ZDCA_SR->GetBinContent(pointing_bin+1)/h_ZDCA_CR->GetBinContent(pointing_bin+1));
      }
      
      if (met < 20 && iso) {h_CF->Fill(4.5,wt);h_CF_unwt->Fill(4.5);h_CF_run->Fill(4.5,wt);h_CF_unwt_run->Fill(4.5);}
      if (!p->ph_passIso1 || !p->ph_passIso2) continue;
      
      if (met > 75 && timing < 4) {h_CF->Fill(5.5,wt);h_CF_unwt->Fill(5.5);h_CF_run->Fill(5.5,wt);h_CF_unwt_run->Fill(5.5);}
      if (met > 75 && timing > 1.5) {h_CF->Fill(6.5,wt); h_CF_unwt->Fill(6.5); h_CF_run->Fill(6.5,wt); h_CF_unwt_run->Fill(6.5);}
      if (met > 75 && timing > 2) {h_CF->Fill(7.5,wt);h_CF_unwt->Fill(7.5); h_CF_run->Fill(7.5,wt); h_CF_unwt_run->Fill(7.5);}
      if (met > 75 && timing > 2 && fabs(zdca) > 200) {h_CF->Fill(8.5,wt);h_CF_unwt->Fill(8.5); h_CF_run->Fill(8.5,wt); h_CF_unwt_run->Fill(8.5);}
      if (met > 75 && timing > 2 && timing < 4) {h_CF->Fill(9.5,wt); h_CF_unwt->Fill(9.5); h_CF_run->Fill(9.5,wt); h_CF_unwt_run->Fill(9.5);}

      if (gain != 2) {
	if (met > 75 && timing < 4) {h_CF->Fill(10.5,wt);h_CF_unwt->Fill(10.5);h_CF_run->Fill(10.5,wt);h_CF_unwt_run->Fill(10.5);}
	if (met > 75 && timing > 1.5) {h_CF->Fill(11.5,wt); h_CF_unwt->Fill(11.5); h_CF_run->Fill(11.5,wt); h_CF_unwt_run->Fill(11.5);}
	if (met > 75 && timing > 2) {h_CF->Fill(12.5,wt);h_CF_unwt->Fill(12.5); h_CF_run->Fill(12.5,wt); h_CF_unwt_run->Fill(12.5);}
	if (met > 75 && timing > 2 && fabs(zdca) > 200) {h_CF->Fill(13.5,wt);h_CF_unwt->Fill(13.5); h_CF_run->Fill(13.5,wt); h_CF_unwt_run->Fill(13.5);}
	if (met > 75 && timing > 2 && timing < 4) {h_CF->Fill(14.5,wt); h_CF_unwt->Fill(14.5); h_CF_run->Fill(14.5,wt); h_CF_unwt_run->Fill(14.5);}
	}
    }
  }
  
  
  // Histograms need to be written into a TFile for further processing
  TFile f("output.root","recreate");
  h_CF->Write();
  h_CF_unwt->Write();
  h_CF_run->Write();
  h_CF_unwt_run->Write();
  h_ZDCA_CR->Write();
  h_ZDCA_SR->Write();
  h_timing_ZDCA_est_SR_yield->Write();
  h_ZDCA_unwt_CR->Write();
  h_ZDCA_unwt_SR->Write();
  h_timing_ZDCA_unwt_est_SR_yield->Write();
  h_Ecell_gain->Write();
  h_E_gain->Write();
  h_pt_gain->Write();
  h_pointing->Write();
  h_abs_pointing->Write();
  h_timing->Write();
  h_MET->Write();
  h_pointing_lowgainveto->Write();
  h_abs_pointing_lowgainveto->Write();
  h_timing_lowgainveto->Write();
  h_MET_lowgainveto->Write();
  h_timing_ZDCA_CR->Write();
  h_timing_ZDCA_SR->Write();
  h_timing_ZDCA_unwt_CR->Write();
  h_timing_ZDCA_unwt_SR->Write();
  h_subleading_ZDCA_loose_eff->Write();
  h_subleading_ZDCA_loose_eff_pt50->Write();
  h_subleading_ZDCA_loose_eff_pt100->Write();
  h_subleading_ZDCA_loose_eff_pt150->Write();
  h_subleading_ZDCA_loose_eff_pt200->Write();
  f.Close();
  
  return 0 ;
}







