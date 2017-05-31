/*
Created by Haichen Wang November 8, 2012
 */

#include "analysis.hh"


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
		 
	TChain *chain = new TChain("output");
		 
	for (int k = 0; k < argc-3 ; k++) {
		chain -> Add(path[k]); // Add the root file to the TChain chain
	    cout << " adding " << path[k] << endl;
	}
		 
	p = new output(chain);


	int numev = p->fChain->GetEntries();

	double lumi = 35.0;
	TH1F* h_pt = new TH1F("h_pt","h_pt",100,0,2000);
	TH1F* h_eta = new TH1F("h_eta","h_eta",50,-2.5,2.5);
	TH1F* h_met = new TH1F("h_met","h_met",200,0,2000);

	TH1F* h_ph1_z = new TH1F("h_ph1_z","h_ph1_z",400,-2000,2000);
	TH1F* h_ph1_t = new TH1F("h_ph1_t","h_ph1_t",400,-20,20);

	TH1F* h_ph1_iso_z = new TH1F("h_ph1_iso_z","h_ph1_iso_z",400,-2000,2000);
	TH1F* h_ph1_iso_t = new TH1F("h_ph1_iso_t","h_ph1_iso_t",400,-20,20);

	TH1F* h_ph1_noniso_z = new TH1F("h_ph1_noniso_z","h_ph1_noniso_z",400,-2000,2000);
	TH1F* h_ph1_noniso_t = new TH1F("h_ph1_noniso_t","h_ph1_noniso_t",400,-20,20);

    TH1F* h_ph1_iso_dZ = new TH1F("h_ph1_iso_dZ","h_ph1_iso_dZ",400,-2000,2000);
    TH1F* h_ph1_noniso_dZ = new TH1F("h_ph1_noniso_dZ","h_ph1_noniso_dZ",400,-2000,2000);

	TH1F* h_CF = new TH1F("h_CF","h_CF",10,0,10);

	TH2F* h_yield = new TH2F("h_yield","h_yield",6,0,6,6,0,6);
	TH2F* h_yield_raw = new TH2F("h_yield_raw","h_yield_raw",6,0,6,6,0,6);

	TH1F* h_Z_CR = new TH1F("h_Z_CR","h_Z_CR",6,0,6);
	TH1F* h_Z_SR = new TH1F("h_Z_SR","h_Z_SR",6,0,6);

	TH2F* h_N = new TH2F("h_N","h_N",15,0,15,15,0,15);

	TH2F *h_pt_met = new TH2F("h_pt_met","h_pt_met",200,0,2000,200,0,2000);

	double new_bins[] = {0,20,40,60,80,100,120,140,160,180,200,800,1400,2000};
	int len = sizeof(new_bins)/sizeof(*new_bins);

	TH1F *h_ZDCA = new TH1F("h_ZDCA","h_ZDCA",len-1,0,len-1);
	TH1F *h_timing = new TH1F("h_timing","h_timing",12,-2,10);

	TH1F *h_ZDCA_tight = new TH1F("h_ZDCA_tight","h_ZDCA_tight",len-1,0,len-1);
	TH1F *h_timing_tight = new TH1F("h_timing_tight","h_timing_tight",12,-2,10);

	TH1F *h_ZDCA_loose = new TH1F("h_ZDCA_loose","h_ZDCA_loose",len-1,0,len-1);
	TH1F *h_timing_loose = new TH1F("h_timing_loose","h_timing_loose",12,-2,10);

	TEfficiency *h_ZDCA_tight_eff = new TEfficiency("h_ZDCA_tight_eff","h_ZDCA_tight_eff",len-1,0,len-1);
	TEfficiency *h_timing_tight_eff = new TEfficiency("h_timing_tight_eff","h_timing_tight_eff",12,-2,10);

	TEfficiency *h_ZDCA_loose_eff = new TEfficiency("h_ZDCA_loose_eff","h_ZDCA_loose_eff",len-1,0,len-1);
	TEfficiency *h_timing_loose_eff = new TEfficiency("h_timing_loose_eff","h_timing_loose_eff",12,-2,10);

	TH2F *h_ZDCA_timing = new TH2F("h_ZDCA_timing","h_ZDCA_timing",12,-2,10,25,0,2000);
	TH2F *h_ZDCA_timing_tight = new TH2F("h_ZDCA_timing_tight","h_ZDCA_timing_tight",12,-2,10,25,0,2000);
	TH2F *h_ZDCA_timing_loose = new TH2F("h_ZDCA_timing_loose","h_ZDCA_timing_loose",12,-2,10,25,0,2000);

	TEfficiency *h_ZDCA_timing_tight_eff = new TEfficiency("h_ZDCA_timing_tight_eff","h_ZDCA_timing_tight_eff",12,-2,10,25,0,2000);
	TEfficiency *h_ZDCA_timing_loose_eff = new TEfficiency("h_ZDCA_timing_loose_eff","h_ZDCA_timing_loose_eff",12,-2,10,25,0,2000);

	TH1F *h_ZDCA_fine = new TH1F("h_ZDCA_fine","h_ZDCA_fine",100,0,1000);
	TH1F *h_ZDCA_tight_fine = new TH1F("h_ZDCA_tight_fine","h_ZDCA_tight_fine",100,0,1000);
	TH1F *h_ZDCA_loose_fine = new TH1F("h_ZDCA_loose_fine","h_ZDCA_loose_fine",100,0,1000);
	TEfficiency *h_ZDCA_tight_eff_fine = new TEfficiency("h_ZDCA_tight_eff_fine","h_ZDCA_tight_eff_fine",100,0,1000);
	TEfficiency *h_ZDCA_loose_eff_fine = new TEfficiency("h_ZDCA_loose_eff_fine","h_ZDCA_loose_eff_fine",100,0,1000);

	TH1F *h_pt1_pass_trigger = new TH1F("h_pt1_pass_trigger","h_pt1_pass_trigger",2000,0,2000);
	TEfficiency *h_pt1_trigger_eff = new TEfficiency("h_pt1_trigger_eff","h_pt1_trigger_eff",2000,0,2000);
	TH1F *h_pt2_pass_trigger = new TH1F("h_pt2_pass_trigger","h_pt2_pass_trigger",2000,0,2000);
	TEfficiency *h_pt2_trigger_eff = new TEfficiency("h_pt2_trigger_eff","h_pt2_trigger_eff",2000,0,2000);
	TEfficiency *h_pt1_trigger_eff_pt2_50 = new TEfficiency("h_pt1_trigger_eff_pt2_50","h_pt1_trigger_eff_pt2_50",2000,0,2000);
	TEfficiency *h_pt2_trigger_eff_pt1_50 = new TEfficiency("h_pt2_trigger_eff_pt1_50","h_pt2_trigger_eff_pt1_50",2000,0,2000);

	double z[7] = { 0, 40 , 80 , 120 , 160 , 200 , 90000};
	double t[7] = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};

	for( int i = 0 ; i < numev ; i ++ ) {	
	    get_event(i) ;
	    double wt =  1;
	    if ( p->wt_xs!=0 ) wt = lumi*1000*1000*p->wt_xs*p->wt_ge/p->wt_nEvents ;
		h_CF -> Fill(-0.5,wt);

        if( p->HLT_g35_loose_g25_loose == 1  ) h_CF -> Fill( 0.5, wt);
        if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut ) h_CF -> Fill( 1.5, wt);
        if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 ) h_CF -> Fill( 2.5, wt);
        if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met > metcut ) h_CF -> Fill( 3.5, wt);
        if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met > metcut && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 4.5, wt);
        if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut &&                                     p->m_met < 20 && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 5.5, wt);


        double test_pt;
        if (p->HLT_g35_loose_g25_loose == 1 && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37) && p->ph_passIso1 && p->ph_passIso2) {
        	if (p->ph_t1 > p->ph_t2) test_pt = p->ph_pt1;
        	if (p->ph_t2 > p->ph_t1) test_pt = p->ph_pt2;
        	h_pt_met->Fill(test_pt,p->m_met,wt);
        }

        double dZsigned  =  p->ph_calo_z1 - p->PV_z ; 

	    double timing = p->ph_t1 ;
	    double caloZ = p->ph_calo_z1 ;
	    double phi = p->ph_phi1;
	    double eta = p->ph_eta1;
	    double pt = p->ph_pt1;
	    int tight = p->ph_isTight1;
	    int loose = p->ph_isLoose1;
	    int which_photon;
	    double dZbin1 = -1;
	    double dZbin2 = -1;
	    double dZ1 = fabs(p->ph_calo_z1 - p->PV_z);
	    double dZ2 = fabs(p->ph_calo_z2 - p->PV_z);
	    double t1 = p->ph_t1;
	    double t2 = p->ph_t2;
	    int tight1 = p->ph_isTight1;
	    int tight2 = p->ph_isTight2;
	    int loose1 = p->ph_isLoose1;
	    int loose2 = p->ph_isLoose2;


	    if( fabs(p->ph_eta1) <= 1.37 && fabs(p->ph_eta2) <= 1.37  ) {
			dZsigned = p->ph_t1 > p->ph_t2 ?  ( p->ph_calo_z1 - p->PV_z) :  ( p->ph_calo_z2 - p->PV_z) ;
			timing =  p->ph_t1 > p->ph_t2 ? p->ph_t1 : p->ph_t2 ;
			caloZ =  p->ph_t1 > p->ph_t2 ? p->ph_calo_z1 : p->ph_calo_z2 ;
			tight = p->ph_t1 > p->ph_t2 ? p->ph_isTight1 : p->ph_isTight2;
			loose = p->ph_t1 > p->ph_t2 ? p->ph_isLoose1 : p->ph_isLoose2;
			eta = p->ph_t1 > p->ph_t2 ? p->ph_eta1 : p->ph_eta2;
			phi = p->ph_t1 > p->ph_t2 ? p->ph_phi1 : p->ph_phi2;
			pt = p->ph_t1 > p->ph_t2 ? p->ph_pt1 : p->ph_pt2;
			which_photon = p->ph_t1 > p->ph_t2 ? 1 : 2;
		}
		else if ( fabs(p->ph_eta1) > 1.37 && fabs(p->ph_eta2) < 1.37  ) {
			dZsigned  = ( p->ph_calo_z2 - p->PV_z);
			timing = p->ph_t2 ;
			caloZ = p->ph_calo_z2 ;
			tight = p->ph_isTight2;
			eta = p->ph_eta2;
			phi = p->ph_phi2;
			pt = p->ph_pt2;
			which_photon = 2;
		}

		double dZ = fabs(dZsigned);

		//Trigger efficiency plots
		bool eta12 = fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37;
		if (p->ph_passIso1 && p->ph_passIso2 && eta12) {
			for (int m = 1; m <= h_pt1_pass_trigger->GetNbinsX(); m++) {
	        	if (p->ph_pt1 >= (m-1)*(2000/h_pt1_pass_trigger->GetNbinsX())) {
					if (p->HLT_g35_loose_g25_loose) h_pt1_pass_trigger->AddBinContent(m);
					h_pt1_trigger_eff->Fill(p->HLT_g35_loose_g25_loose,(m-1)*(2000/h_pt1_pass_trigger->GetNbinsX()));
				}
				if (p->ph_pt1 > 5000 && p->ph_pt2 >= (m-1)*(2000/h_pt2_pass_trigger->GetNbinsX())) {
					if (p->HLT_g35_loose_g25_loose) h_pt2_pass_trigger->AddBinContent(m);
					h_pt2_trigger_eff->Fill(p->HLT_g35_loose_g25_loose,(m-1)*(2000/h_pt2_pass_trigger->GetNbinsX()));
				}
			}
		}

		if( fabs(p->ph_eta1) > 1.37 && fabs(p->ph_eta2) > 1.37 ) continue ;

	    if( p->ph_pt2 < ptcut ) continue ; 

    	double pi = 3.14159;

    	double deta11 = p->ph_eta1 - p->truth_ph_eta1;
    	double deta12 = p->ph_eta1 - p->truth_ph_eta2;
    	double deta21 = p->ph_eta2 - p->truth_ph_eta1;
    	double deta22 = p->ph_eta2 - p->truth_ph_eta2;

    	double dphi11 = p->ph_phi1 - p->truth_ph_phi1;
    	double dphi12 = p->ph_phi1 - p->truth_ph_phi2;
    	double dphi21 = p->ph_phi2 - p->truth_ph_phi1;
    	double dphi22 = p->ph_phi2 - p->truth_ph_phi2;

    	if (dphi11 > pi) dphi11 = 2*pi - dphi11;
    	if (dphi12 > pi) dphi12 = 2*pi - dphi12;
    	if (dphi21 > pi) dphi21 = 2*pi - dphi21;
    	if (dphi22 > pi) dphi22 = 2*pi - dphi22;

    	double dR11 = sqrt(pow(deta11,2) + pow(dphi11,2));
    	double dR12 = sqrt(pow(deta12,2) + pow(dphi12,2));
    	double dR21 = sqrt(pow(deta21,2) + pow(dphi21,2));
    	double dR22 = sqrt(pow(deta22,2) + pow(dphi22,2));

    	for (int k = 0; k < len-1; k++) {
    		if (dZ1 > new_bins[k] && dZ1 < new_bins[k+1]) dZbin1 = k+0.5;
    		if (dZ2 > new_bins[k] && dZ2 < new_bins[k+1]) dZbin2 = k+0.5;
    	}


    	//ZDCA/timing plots filled without weights for now -- using them for efficiency plots, fill efficienceies with
    	//reco photons matched to truth level photons by a dR < 0.1 matching
    	h_CF->Fill(7.5);
    	h_CF->Fill(7.5); //Filling twice, once for each photon (want the total number of photons)
    	if (dR11 < 0.1 || dR12 < 0.1) {
    		h_CF->Fill(6.5);
    		h_ZDCA->Fill(dZbin1);
    		h_ZDCA_fine->Fill(dZ1);
			h_timing->Fill(t1);
			h_ZDCA_timing->Fill(t1,dZ1);
			if (tight1) {
				h_ZDCA_tight->Fill(dZbin1);
				h_ZDCA_tight_fine->Fill(dZ1);
				h_timing_tight->Fill(t1);
				h_ZDCA_timing_tight->Fill(t1,dZ1);
			}
			if (loose1) {
				h_ZDCA_timing_loose->Fill(t1,dZ1);
				h_ZDCA_loose->Fill(dZbin1);
				h_ZDCA_loose_fine->Fill(dZ1);
				h_timing_loose->Fill(t1);
			}
			if (loose1) h_ZDCA_tight_eff->Fill(tight1,dZbin1);
			if (loose1) h_timing_tight_eff->Fill(tight1,t1);
			if (loose1) h_ZDCA_tight_eff_fine->Fill(tight1,dZ1);
			h_ZDCA_loose_eff->Fill(loose1,dZbin1);
			h_ZDCA_loose_eff_fine->Fill(loose1,dZ1);
			h_timing_loose_eff->Fill(loose1,t1);
			if (loose1) h_ZDCA_timing_tight_eff->Fill(tight1,t1,dZ1);
			h_ZDCA_timing_loose_eff->Fill(loose1,t1,dZ1);
		}

		if (dR21 < 0.1 || dR22 < 0.1) {
    		h_CF->Fill(6.5);
    		h_ZDCA->Fill(dZbin2);
    		h_ZDCA_fine->Fill(dZ2);
			h_timing->Fill(t2);
			h_ZDCA_timing->Fill(t2,dZ2);
			if (tight2) {
				h_ZDCA_tight->Fill(dZbin2);
				h_ZDCA_tight_fine->Fill(dZ2);
				h_timing_tight->Fill(t2);
				h_ZDCA_timing_tight->Fill(t2,dZ2);
			}
			if (loose2) {
				h_ZDCA_timing_loose->Fill(t2,dZ2);
				h_ZDCA_loose->Fill(dZbin2);
				h_ZDCA_loose_fine->Fill(dZ2);
				h_timing_loose->Fill(t2);
			}
			if (loose2) h_ZDCA_tight_eff->Fill(tight2,dZbin2);
			if (loose2) h_timing_tight_eff->Fill(tight2,t2);
			if (loose2) h_ZDCA_tight_eff_fine->Fill(tight2,dZ2);
			h_ZDCA_loose_eff->Fill(loose2,dZbin2);
			h_ZDCA_loose_eff_fine->Fill(loose2,dZ2);
			h_timing_loose_eff->Fill(loose2,t2);
			if (loose2) h_ZDCA_timing_tight_eff->Fill(tight2,t2,dZ2);
			h_ZDCA_timing_loose_eff->Fill(loose2,t2,dZ2);
		}

		if(!p->HLT_g35_loose_g25_loose) continue ;

	    for( int a = 0 ; a < 15 ; a ++ ) {
			for( int b = 0 ; b < 15 ; b++ ) {
			    double pTcut = 40 + 10*a;
			    double METcut = 70 + 10*b ;
			    if(p->ph_pt1>pTcut && p->m_met>METcut) h_N->Fill(a+0.5,b+0.5,wt);
			}
		}

        for( int k = 0 ; k < 6 ; k ++ ) {
			if( dZ  > z[k] &&  dZ < z[k+1] ) { 
                if( p->m_met<20) {
                    h_Z_CR -> Fill( k+0.5, wt ) ;
                    // No isolation requirement is applied to the control region
                }
                if(p->m_met > metcut) {
			 		if( p->ph_passIso1 && p->ph_passIso2) {
				    	h_Z_SR -> Fill( k+0.5, wt ) ;
				    	h_ph1_iso_z-> Fill( caloZ ,wt );
				    	h_ph1_iso_dZ-> Fill( dZsigned ,wt );
				    	h_ph1_iso_t -> Fill( timing, wt );
				    }
				    else {
				    	h_ph1_noniso_z-> Fill( caloZ ,wt );
				    	h_ph1_noniso_dZ-> Fill( dZsigned ,wt );
				    	h_ph1_noniso_t -> Fill( timing, wt );
				 	}

                }
			}
        }

		if( p->wt_xs != 0 ) {
		    h_pt -> Fill( p-> ph_pt1 , wt );
		    h_eta -> Fill( p-> ph_eta1 , wt );
		    h_met -> Fill( p-> m_met , wt );
		    h_ph1_z -> Fill( caloZ , wt);
		    h_ph1_t -> Fill(timing , wt);
		    if( p-> m_met < metcut || !p->ph_passIso1 || !p->ph_passIso2 ) continue ;
		}
		else {
			if( p->m_met > 20 ) continue ;
			h_pt -> Fill( p-> ph_pt1 , wt );
			h_eta -> Fill( p-> ph_eta1 , wt );
			h_met -> Fill( p-> m_met , wt );
			h_ph1_z -> Fill( caloZ , wt);
			h_ph1_t -> Fill(timing , wt);
		}

		for( int k = 0 ; k < 6 ; k ++ ) {
			for( int l = 0 ; l < 6 ; l ++) {
			    if( dZ  > z[k] &&  dZ < z[k+1] &&timing>t[l] &&timing<t[l+1]) { 
				    if( p->wt_xs == 0 ) {
				    	h_yield -> Fill( l, k, wt*(h_Z_SR->GetBinContent(k+1) / h_Z_CR -> GetBinContent(k+1) ) );
				    	h_yield_raw -> Fill( l, k, wt );
				    }
				    else { 
				    	h_yield -> Fill( l, k, wt );
				    }
				}
			}
		}




	}


	// Histograms need to be written into a TFile for further processing
    TFile f("output.root","recreate");
	h_pt -> Write();
	h_eta -> Write();
	h_met -> Write();
	h_ph1_z -> Write();
	h_ph1_t -> Write();
	h_CF -> Write();
	h_N->Write();
	h_Z_CR ->Write();
	h_Z_SR ->Write();
	h_ph1_iso_z->Write();
	h_ph1_iso_t->Write();
    h_ph1_iso_dZ->Write();
    h_ph1_noniso_dZ->Write();
	h_ph1_noniso_z->Write();
	h_ph1_noniso_t->Write();
	h_yield->Write();
	h_yield_raw->Write();
	h_pt_met->Write();
	h_ZDCA->Write();
	h_ZDCA_fine->Write();
	h_timing->Write();
	h_ZDCA_tight->Write();
	h_ZDCA_tight_fine->Write();
	h_timing_tight->Write();
	h_ZDCA_loose->Write();
	h_ZDCA_loose_fine->Write();
	h_timing_loose->Write();
	h_ZDCA_tight_eff->Write();
	h_ZDCA_tight_eff_fine->Write();
	h_timing_tight_eff->Write();
	h_ZDCA_loose_eff->Write();
	h_ZDCA_loose_eff_fine->Write();
	h_timing_loose_eff->Write();
	h_ZDCA_timing->Write();
	h_ZDCA_timing_tight->Write();
	h_ZDCA_timing_loose->Write();
	h_ZDCA_timing_tight_eff->Write();
	h_ZDCA_timing_loose_eff->Write();
	h_pt1_pass_trigger->Write();
	h_pt1_trigger_eff->Write();
	h_pt2_pass_trigger->Write();
	h_pt2_trigger_eff->Write();
    f.Close();

	return 0 ;
}







