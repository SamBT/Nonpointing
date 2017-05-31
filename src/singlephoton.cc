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
		chain -> Add(path[k]);
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
 	TH1F* h_ph1_iso_dZ = new TH1F("h_ph1_iso_dZ","h_ph1_iso_dZ",400,-2000,2000);
 	TH1F* h_ph1_iso_t = new TH1F("h_ph1_iso_t","h_ph1_iso_t",400,-20,20);

	TH1F* h_ph1_noniso_z = new TH1F("h_ph1_noniso_z","h_ph1_noniso_z",400,-2000,2000);
 	TH1F* h_ph1_noniso_dZ = new TH1F("h_ph1_noniso_dZ","h_ph1_noniso_dZ",400,-2000,2000);
 	TH1F* h_ph1_noniso_t = new TH1F("h_ph1_noniso_t","h_ph1_noniso_t",400,-20,20);

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

	TH1F *h_pt_pass_trigger = new TH1F("h_pt_pass_trigger","h_pt_pass_trigger",2000,0,2000);
	TH1F *h_pt_for_trigger = new TH1F("h_pt_for_trigger","h_pt_for_trigger",2000,0,2000);
	TEfficiency *h_pt_trigger_eff = new TEfficiency("h_pt_trigger_eff","h_pt_trigger_eff",2000,0,2000);

		 //Timing and ZDCA bins to look at yields in various regions (CR/SR)
	double z[7] = { 0, 40 , 80 , 120 , 160 , 200 , 90000};
	double t[7] = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};

	for( int i = 0 ; i < numev ; i ++ ) {

	    get_event(i) ;
	    double wt =  1; 
	    if ( p->wt_xs!=0 ) wt = lumi*1000*1000*p->wt_xs*p->wt_ge/p->wt_nEvents ;



		h_CF -> Fill(-0.5,wt);
        if( p->HLT_g140_loose == 1  ) h_CF -> Fill( 0.5, wt);
        if( p->HLT_g140_loose == 1  && p->ph_pt1 > ptcut ) h_CF -> Fill( 1.5, wt);
        if( p->HLT_g140_loose == 1  && p->ph_pt1 > ptcut && p->ph_passIso1 ) h_CF -> Fill( 2.5, wt);
        if( p->HLT_g140_loose == 1  && p->ph_pt1 > ptcut && p->ph_passIso1 && p->m_met > metcut ) h_CF -> Fill( 3.5, wt);
        if( p->HLT_g140_loose == 1  && p->ph_pt1 > ptcut && p->ph_passIso1 && p->m_met > metcut && fabs(p->ph_eta1) < 1.37 ) h_CF -> Fill( 4.5, wt);
        if( p->HLT_g140_loose == 1  && p->ph_pt1 > ptcut &&                   p->m_met < 20     && fabs(p->ph_eta1) < 1.37 ) h_CF -> Fill( 5.5, wt);

        if (fabs(p->ph_eta1) < 1.37 && p->ph_passIso1) {
        	for (int k = 1; k <= h_pt_for_trigger->GetNbinsX(); k++) {
        		if (p->ph_pt1 > (k-1)*(2000/h_pt_for_trigger->GetNbinsX())) {
        			if (p->HLT_g140_loose) h_pt_pass_trigger->AddBinContent(k);
        			h_pt_trigger_eff->Fill(p->HLT_g140_loose,(k-1)*(2000/h_pt_for_trigger->GetNbinsX()));
        			h_pt_for_trigger->AddBinContent(k);
        		}
        	}
        }

		if( p->ph_pt1 < 50 || fabs( p -> ph_eta1 ) > 1.37 ) continue ; //Pt cut 50 for the photon id efficiency plots, use regular ptcut argument afterwards

		double pi = 3.14159;

    	double deta1 = p->ph_eta1 - p->truth_ph_eta1;
    	double deta2 = p->ph_eta1 - p->truth_ph_eta2;

    	double dphi1 = p->ph_phi1 - p->truth_ph_phi1;
    	double dphi2 = p->ph_phi1 - p->truth_ph_phi2;

    	if (dphi1 > pi) dphi1 = 2*pi - dphi1;
    	if (dphi2 > pi) dphi2 = 2*pi - dphi2;

    	double dR1 = sqrt(pow(deta1,2) + pow(dphi1,2));
    	double dR2 = sqrt(pow(deta2,2) + pow(dphi2,2));

    	double dZbin = -1;
    	for (int k = 0; k < len-1; k++) {
    		if (fabs(p->ph_calo_z1 - p->PV_z) > new_bins[k] && fabs(p->ph_calo_z1 - p->PV_z) < new_bins[k+1]) dZbin = k+0.5;
    	}

		//ZDCA/timing plots filled without weights for now -- using them to calculate efficiencies
		//Use only reco photons matched to truth photons by a dR < 0.1 matching
		h_CF->Fill(7.5);
		if (dR1 < 0.1 || dR2 < 0.1) {
			h_CF->Fill(6.5);
			h_ZDCA->Fill(dZbin);
			h_ZDCA_fine->Fill(fabs(p->ph_calo_z1 - p->PV_z));
			h_timing->Fill(p->ph_t1);
			h_ZDCA_timing->Fill(p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z));
			if (p->ph_isTight1) {
				h_ZDCA_tight->Fill(dZbin);
				h_ZDCA_tight_fine->Fill(fabs(p->ph_calo_z1 - p->PV_z));
				h_timing_tight->Fill(p->ph_t1);
				h_ZDCA_timing_tight->Fill(p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z));
			}
			if (p->ph_isLoose1) {
				h_ZDCA_timing_loose->Fill(p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z));
				h_ZDCA_loose->Fill(dZbin);
				h_ZDCA_loose_fine->Fill(fabs(p->ph_calo_z1 - p->PV_z));
				h_timing_loose->Fill(p->ph_t1);
			}
			if (p->ph_isLoose1) h_ZDCA_tight_eff->Fill(p->ph_isTight1,dZbin);
			if (p->ph_isLoose1) h_timing_tight_eff->Fill(p->ph_isTight1,p->ph_t1);
			if (p->ph_isLoose1) h_ZDCA_tight_eff_fine->Fill(p->ph_isTight1,fabs(p->ph_calo_z1 - p->PV_z));
			h_ZDCA_loose_eff->Fill(p->ph_isLoose1,dZbin);
			h_ZDCA_loose_eff_fine->Fill(p->ph_isLoose1,fabs(p->ph_calo_z1 - p->PV_z));
			h_timing_loose_eff->Fill(p->ph_isLoose1,p->ph_t1);
			if (p->ph_isLoose1) h_ZDCA_timing_tight_eff->Fill(p->ph_isTight1,p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z));
			h_ZDCA_timing_loose_eff->Fill(p->ph_isLoose1,p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z));
		}

		if (p->ph_pt1 < ptcut) continue;
		if( !p->HLT_g140_loose) continue ;

	    for( int a = 0 ; a < 15 ; a ++ ) {
			for( int b = 0 ; b < 15 ; b++ ) {
			    double pTcut = 40 + 10*a;
			    double METcut = 70 + 10*b ;
			    if(p->ph_pt1>pTcut && p->m_met>METcut) h_N->Fill(a+0.5,b+0.5,wt);
			}
		}

		if (p->ph_passIso1) {
			h_pt_met->Fill(p->ph_pt1,p->m_met,wt);
		}

        for( int k = 0 ; k < 6 ; k ++ ) {
			if( fabs( p->ph_calo_z1 - p->PV_z)  > z[k] &&  fabs( p->ph_calo_z1 - p->PV_z) < z[k+1] ) { 
			    if( p->m_met<20) {
			    	h_Z_CR -> Fill( k+0.5, wt ) ;
			    	// No isolation requirement is applied to the control region			       
			    }
			    if(p->m_met > metcut) {

			    	if( p->ph_passIso1 ) {
				    	h_Z_SR -> Fill( k+0.5, wt ) ;
				    	h_ph1_iso_z-> Fill( p->ph_calo_z1 ,wt );
				    	h_ph1_iso_dZ-> Fill( p->ph_calo_z1 - p->PV_z ,wt );
				    	h_ph1_iso_t -> Fill( p-> ph_t1, wt );
				 	}
			        else {
				    	h_ph1_noniso_z-> Fill( p->ph_calo_z1 ,wt );
				    	h_ph1_noniso_dZ-> Fill( p->ph_calo_z1 - p->PV_z ,wt );
				    	h_ph1_noniso_t -> Fill( p-> ph_t1, wt );
				    }
			    }
			}
        }


		if( p->wt_xs != 0 ) {
	    	h_pt -> Fill( p-> ph_pt1 , wt );
	    	h_eta -> Fill( p-> ph_eta1 , wt );
	    	h_met -> Fill( p-> m_met , wt );
	    	h_ph1_z -> Fill( p->ph_calo_z1 , wt);
	    	h_ph1_t -> Fill( p->ph_t1 , wt);
		    if( p-> m_met < metcut || !p->ph_passIso1 || !p->ph_passIso2 ) continue ;
		}
	    else {
			if( p->m_met > 20 ) continue ;
			h_pt -> Fill( p-> ph_pt1 , wt );
			h_eta -> Fill( p-> ph_eta1 , wt );
			h_met -> Fill( p-> m_met , wt );
			h_ph1_z -> Fill( p->ph_calo_z1 , wt);
			h_ph1_t -> Fill( p->ph_t1 , wt);
		}


		for( int k = 0 ; k < 6 ; k ++ ) {
			for( int l = 0 ; l < 6 ; l ++) {
			    if( fabs( p->ph_calo_z1 - p->PV_z)  > z[k] &&  fabs( p->ph_calo_z1 - p->PV_z) < z[k+1] && p->ph_t1>t[l] && p->ph_t1<t[l+1]) {
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
	h_ph1_iso_dZ->Write();
	h_ph1_iso_t->Write();
	h_ph1_noniso_z->Write();
	h_ph1_noniso_dZ->Write();
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
	h_pt_pass_trigger->Write();
	h_pt_trigger_eff->Write();
	h_pt_for_trigger->Write();
    f.Close();
	
	return 0 ;
}







