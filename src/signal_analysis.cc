
/*
Created by Haichen Wang November 8, 2012
 */

#include "signal_analysis.hh"


int main (int argc, char **argv)
{
  gROOT->ProcessLine(".x rootlogon.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();

		 if (argc < 2)
		 {
		    printf("\nUsage: %s *.root\n\n",argv[0]);
		    exit(0);
		 }
		 
		 int const index = argc - 1;
		
		 TString path[index];
		 
		 for ( int j = 0; j < argc-1; j++)
		 {
			path[j] = (argv[j+1]);
		 }
		 
		 TChain *chain = new TChain("output");
		 
		 for (int k = 0; k < argc-1 ; k++)
		 {
		    chain -> Add(path[k]); // Add the root file to the TChain chain
		    cout << " adding " << path[k] << endl;
		 }
		 
		 p = new SinglePhoton(chain);


		 int numev = p->fChain->GetEntries();

		 // double lumi = 1.0;

		 /*
		 TH1F* h_tight_z1 = new TH1F("h_tight_z1","h_tight_z1",400,-2000,2000);
		 TH1F* h_tight_z2 = new TH1F("h_tight_z2","h_tight_z2",400,-2000,2000);

		 TH1F* h_loose_z1 = new TH1F("h_loose_z1","h_loose_z1",400,-2000,2000);
		 TH1F* h_loose_z2 = new TH1F("h_loose_z2","h_loose_z2",400,-2000,2000);
		 */

		 //		 TH2F* h_tight_z_t = new TH2F("h_tight_z_t","h_tight_z_t",400,-2000,2000,400,-20,20);

		 TH2F* h_tight_t_z = new TH2F("h_tight_t_z","h_tight_t_z",400,-20,20,400,-2000,2000);
		 TH2F* h_loose_t_z = new TH2F("h_loose_t_z","h_loose_t_z",400,-20,20,400,-2000,2000);

		 TH2F* h_tight_t_absz = new TH2F("h_tight_t_absz","h_tight_t_absz",400,-20,20,200,0,2000);
                 TH2F* h_loose_t_absz = new TH2F("h_loose_t_absz","h_loose_t_absz",400,-20,20,200,0,2000);

		 TH2F *h_tight_t_abseta = new TH2F("h_tight_t_abseta","h_tight_t_abseta",400,-20,20,250,0,2.5);
		 TH2F *h_loose_t_abseta = new TH2F("h_loose_t_abseta","h_loose_t_abseta",400,-20,20,250,0,2.5);

		 TH2F *h_tight_z_abseta = new TH2F("h_tight_z_abseta","h_tight_z_abseta",400,-2000,2000,250,0,2.5);
		 TH2F *h_loose_z_abseta = new TH2F("h_loose_z_abseta","h_loose_z_abseta",400,-2000,2000,250,0,2.5);

		 TH1F *h_tight_eta = new TH1F("h_tight_eta","h_tight_eta",600,-3,3);
		 TH1F *h_loose_eta = new TH1F("h_loose_eta","h_loose_eta",600,-3,3);

		 TH1F* h_tight_z = new TH1F("h_tight_z","h_tight_z",400,-2000,2000);
		 TH1F* h_loose_z = new TH1F("h_loose_z","h_loose_z",400,-2000,2000);

		 TH1F* h_tight_t = new TH1F("h_tight_t","h_tight_t",400,-20,20);
		 TH1F* h_loose_t = new TH1F("h_loose_t","h_loose_t",400,-20,20);

		 TH1F* h_tight_t1 = new TH1F("h_tight_t1","h_tight_t1",400,-20,20);
		 TH1F* h_loose_t1 = new TH1F("h_loose_t1","h_loose_t1",400,-20,20);

		 TH1F* h_tight_t2 = new TH1F("h_tight_t2","h_tight_t2",400,-20,20);
                 TH1F* h_loose_t2 = new TH1F("h_loose_t2","h_loose_t2",400,-20,20);

		 TH1F* h_tight_calo_z1 = new TH1F("h_tight_calo_z1","h_tight_calo_z1",400,-2000,2000);
		 TH1F* h_loose_calo_z1 = new TH1F("h_loose_calo_z1","h_loose_calo_z1",400,-2000,2000);

		 TH1F* h_tight_calo_z2 = new TH1F("h_tight_calo_z2","h_tight_calo_z2",400,-2000,2000);
                 TH1F* h_loose_calo_z2 = new TH1F("h_loose_calo_z2","h_loose_calo_z2",400,-2000,2000);

		 TH1F* h_missing_ET = new TH1F("h_missing_ET","h_missing_ET",2500,0,2500);

		 TH1F* h_tight_z_conv0 = new TH1F("h_tight_z_conv0","h_tight_z_conv0",400,-2000,2000);
		 TH1F* h_tight_z_conv1 = new TH1F("h_tight_z_conv1","h_tight_z_conv1",400,-2000,2000);
		 TH1F* h_loose_z_conv0 = new TH1F("h_loose_z_conv0","h_loose_z_conv0",400,-2000,2000);
         TH1F* h_loose_z_conv1 = new TH1F("h_loose_z_conv1","h_loose_z_conv1",400,-2000,2000);

		 TH1F *h_tight_t_conv0 = new TH1F("h_tight_t_conv0","h_tight_t_conv0",400,-20,20);
		 TH1F *h_tight_t_conv1 = new TH1F("h_tight_t_conv1","h_tight_t_conv1",400,-20,20);
		 TH1F *h_loose_t_conv0 = new TH1F("h_loose_t_conv0","h_loose_t_conv0",400,-20,20);
                 TH1F *h_loose_t_conv1 = new TH1F("h_loose_t_conv1","h_loose_t_conv1",400,-20,20);

		 TH1F *h_leading_tight_t = new TH1F("h_leading_tight_t","h_leading_tight_t",400,-20,20);
		 TH1F *h_leading_loose_t = new TH1F("h_leading_loose_t","h_leading_loose_t",400,-20,20);
		 TH1F *h_leading_tight_z = new TH1F("h_leading_tight_z","h_leading_tight_z",400,-2000,2000);
		 TH1F *h_leading_loose_z = new TH1F("h_leading_loose_z","h_leading_loose_z",400,-2000,2000);

		 TH2F *h_tight_z_conv = new TH2F("h_tight_z_conv","h_tight_z_conv",400,-2000,2000,6,0,6);
		 TH2F *h_loose_z_conv = new TH2F("h_loose_z_conv","h_loose_z_conv",400,-2000,2000,6,0,6);
		 
		 TH2F *h_tight_t_conv = new TH2F("h_tight_t_conv","h_tight_t_conv",400,-20,20,6,0,6);
		 TH2F *h_loose_t_conv = new TH2F("h_loose_t_conv","h_loose_t_conv",400,-20,20,6,0,6);

		 TH1F *h_tight_minus5t_z = new TH1F("h_tight_minus5t_z","h_tight_minus5t_z",400,-2000,2000);
		 TH1F *h_loose_minus5t_z = new TH1F("h_loose_minus5t_z","h_loose_minus5t_z",400,-2000,2000);

		 TH1F *h_tight_pm2t_z = new TH1F("h_tight_pm2t_z","h_tight_pm2t_z",400,-2000,2000);
		 TH1F *h_loose_pm2t_z =new TH1F("h_loose_pm2t_z","h_loose_pm2t_z",400,-2000,2000);

		 TH1F *h_pt1 = new TH1F("h_pt1","h_pt1",2000,0,2000);
		 TH1F *h_pt2 = new TH1F("h_pt2","h_pt2",2000,0,2000);

		 TH1F *h_tight_pt1 = new TH1F("h_tight_pt1","h_tight_pt1",2000,0,2000);
         TH1F *h_tight_pt2 = new TH1F("h_tight_pt2","h_tight_pt2",2000,0,2000);

		 TH1F *h_loose_pt1 = new TH1F("h_loose_pt1","h_loose_pt1",2000,0,2000);
         TH1F *h_loose_pt2 = new TH1F("h_loose_pt2","h_loose_pt2",2000,0,2000);

		 TH1F *h_single_tight_calo_z = new TH1F("h_single_tight_calo_z","h_single_tight_calo_z",400,-2000,2000);
		 TH1F *h_single_loose_calo_z =new TH1F("h_single_loose_calo_z","h_single_loose_calo_z",400,-2000,2000);


		 TH1F *h_eta1 = new TH1F("h_eta1","h_eta1",50,-2.5,2.5);
         TH1F *h_eta2 = new TH1F("h_eta2","h_eta2",50,-2.5,2.5);

		 TH1F *h_tight_eta1 = new TH1F("h_tight_eta1","h_tight_eta1",50,-2.5,2.5);
         TH1F *h_tight_eta2 = new TH1F("h_tight_eta2","h_tight_eta2",50,-2.5,2.5);
		 TH1F *h_loose_eta1 = new TH1F("h_loose_eta1","h_loose_eta1",50,-2.5,2.5);
         TH1F *h_loose_eta2 = new TH1F("h_loose_eta2","h_loose_eta2",50,-2.5,2.5);

         TH1F* h_conv = new TH1F("h_conv","h_conv",6,0,6);

		 TH1F* h_CF = new TH1F("h_CF","h_CF",20,0,20);
		 TH1F* h_CF_likedata = new TH1F("h_CF_likedata","h_CF_likedata",20,0,20); //Cutflow with same cuts as data

		 double timing_bins[] = {-4,0.5,1.1,1.3,1.5,1.8,10000};
		 int n_timing_bins = sizeof(timing_bins)/sizeof(*timing_bins) - 1;

		 double z_dca_bins[] = {0,40,80,120,160,200,9999999};
		 int n_zdca_bins = sizeof(z_dca_bins)/sizeof(*z_dca_bins) - 1;

		 TH2F *h_timing_zdca_yields = new TH2F("h_timing_zdca_yields","h_timing_zdca_yields",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);
		 TH2F *h_timing_zdca_yields_CR = new TH2F("h_timing_zdca_yields_CR","h_timing_zdca_yields_CR",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);
		 TH2F *h_timing_zdca_yields_SR1 = new TH2F("h_timing_zdca_yields_SR1","h_timing_zdca_yields_SR1",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);
		 TH2F *h_timing_zdca_yields_SR2 = new TH2F("h_timing_zdca_yields_SR2","h_timing_zdca_yields_SR2",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);

		 TString bin_name;

		 h_timing_zdca_yields->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields_CR->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields_SR1->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields_SR2->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields->GetYaxis()->SetTitle("Z_{DCA} [mm]");
		 h_timing_zdca_yields_CR->GetYaxis()->SetTitle("Z_{DCA} [mm]");
		 h_timing_zdca_yields_SR1->GetYaxis()->SetTitle("Z_{DCA} [mm]");
		 h_timing_zdca_yields_SR2->GetYaxis()->SetTitle("Z_{DCA} [mm]");

		 for (int k = 0; k < n_timing_bins; k++) {
		 	bin_name.Form("%.2f - %.2f",timing_bins[k],timing_bins[k+1]);
		 	if (k+1 == n_timing_bins) bin_name.Form("%.0f -",timing_bins[k]);
		 	h_timing_zdca_yields->GetXaxis()->SetBinLabel(k+1,bin_name);
		 	h_timing_zdca_yields_CR->GetXaxis()->SetBinLabel(k+1,bin_name);
		 	h_timing_zdca_yields_SR1->GetXaxis()->SetBinLabel(k+1,bin_name);
		 	h_timing_zdca_yields_SR2->GetXaxis()->SetBinLabel(k+1,bin_name);
		 }
		 for (int k = 0; k < n_zdca_bins; k++) {
		 	bin_name.Form("%.0f - %.0f",z_dca_bins[k],z_dca_bins[k+1]);
		 	if (k+1 == n_zdca_bins) bin_name.Form("%.0f -",z_dca_bins[k]);
		 	h_timing_zdca_yields->GetYaxis()->SetBinLabel(k+1,bin_name);
		 	h_timing_zdca_yields_CR->GetYaxis()->SetBinLabel(k+1,bin_name);
		 	h_timing_zdca_yields_SR1->GetYaxis()->SetBinLabel(k+1,bin_name);
		 	h_timing_zdca_yields_SR2->GetYaxis()->SetBinLabel(k+1,bin_name);
		 }

		 int t_bin = -999;
		 int z_bin = -999;

		 double t1 = 0;
		 double z_dca = 0;

		 TH2F *h_timing_zdca_CR = new TH2F("h_timing_zdca_CR","h_timing_zdca_CR",210,-21,21,200,0,2000);
		 TH2F *h_timing_zdca_SR1 = new TH2F("h_timing_zdca_SR1","h_timing_zdca_SR1",210,-21,21,200,0,2000);
		 TH2F *h_timing_zdca_SR2 = new TH2F("h_timing_zdca_SR2","h_timing_zdca_SR2",210,-21,21,200,0,2000);


		 for( int i = 0 ; i < numev ; i ++ )
		   {	
		     get_event(i) ;

		     // This code fills histograms after a simple preselection/
		     // The events selected by NonPointing package contains at least two loose photons

		     // m_weight is an event weight variable. For data it is set to 1. 
                     // For Monte Carlo, it takes care of xsection times weight from offline correction over sum of weighted number of events.
		     // this variable doesn't include luminosity
		     double wt = (35*1000*(1000.0)*p->wt_xs*p->wt_ge*p->wt_mc)/p->wt_nEvents;
		     h_CF->Fill(0.5,wt);

		     h_CF_likedata->Fill(0.5,wt);
	     	 if (p->m_met < 20) h_CF_likedata->Fill(1.5,wt);
		     if( p-> m_met > 20 ) h_CF_likedata->Fill(2.5,wt);
		     if (p->m_met > 70) h_CF_likedata->Fill(3.5,wt);

		     // mcChannelNumber is an identifier for a particular physics process that is simulated.
                     // if mcChannelNumber is 0 or negative, this sample is data. 

		     // m_met, the missing transverse energy 
		     //if( p-> m_met > 20 ) continue ; // blinding regions with potential signal contributions

		     // ph_isTight1(2) flag for tight photons
		     if(p->ph_isTight1){h_single_tight_calo_z->Fill(p->ph_calo_z1-p->PV_z,wt);  h_tight_z -> Fill( p->ph_z1 - p->PV_z, wt );}
		     // Note that Z_DCA is defined as photon vertex z minus primary vertex z 

		     // when isTight flag is false, the photon is a loose photon  
		     if(!p->ph_isTight1){h_single_loose_calo_z->Fill(p->ph_calo_z1 - p->PV_z,wt);  h_loose_z -> Fill( p->ph_z1 - p->PV_z, wt );}

		     if(p->ph_isTight1) h_tight_t -> Fill( p->ph_t1 , wt );
		     if(p->ph_isTight2) h_tight_t -> Fill( p->ph_t2 , wt );

		     if(!p->ph_isTight1) h_loose_t -> Fill( p->ph_t1 , wt );
		     if(!p->ph_isTight2) h_loose_t -> Fill( p->ph_t2 , wt );

		     h_missing_ET->Fill(p->m_met,wt);

		     h_pt1->Fill(p->ph_pt1,wt);
		     h_pt2->Fill(p->ph_pt2,wt);
		     h_eta1->Fill(p->ph_eta1,wt);
		     h_eta2->Fill(p->ph_eta2,wt);

		     t1 = p->ph_t1;
		     z_dca = fabs(p->ph_calo_z1 - p->PV_z);

			 for (int k = 0; k < n_timing_bins; k++) {
		     	if ( (t1 > timing_bins[k]) && (t1 < timing_bins[k+1]) ) {
		     		t_bin = k + 0.5;
		     	}
		     }

		     for (int j = 0; j < n_zdca_bins; j++) {
		     	if ( (z_dca > z_dca_bins[j]) && (z_dca < z_dca_bins[j+1]) ) {
		     		z_bin = j + 0.5;
		     	}
		     }


		     if (p->m_met < 20) {h_timing_zdca_yields_CR->Fill(t_bin,z_bin,wt); h_timing_zdca_CR->Fill(t1,z_dca,wt);}

		     if (p->HLT_g140_loose == 1) {
		       h_CF->Fill(1.5,wt);
		       if (p->ph_pt1 > 150 && p->ph_pt2 > 25) {
			 		h_CF->Fill(2.5,wt);
			 		if (p->m_met > 20) {h_timing_zdca_yields_SR1->Fill(t_bin,z_bin,wt); h_timing_zdca_SR1->Fill(t1,z_dca,wt);}
			 		if (p->m_met > 70) {h_timing_zdca_yields_SR2->Fill(t_bin,z_bin,wt); h_timing_zdca_SR2->Fill(t1,z_dca,wt);}
			 		if (p->m_met > 20) {
			   			h_CF->Fill(3.5,wt);
			   			if (p->m_met > 70) {
		  					h_CF->Fill(4.5,wt);
	     					if ( (p->ph_pt1 > 25) && (p->ph_pt2 > 25)) {
	       						h_CF->Fill(5.5,wt);
	     					}
	  					}
		 			}
		       }
		     }
		     t_bin = -999;
		     z_bin = -999;


		     //Fill tight/loose histograms for first
		     if (p->ph_isTight1) {
		       h_tight_eta1->Fill(p->ph_eta1,wt);
		       h_tight_pt1->Fill(p->ph_pt1,wt);
		       h_tight_t_z->Fill(p->ph_t1,p->ph_calo_z1 - p->PV_z,wt);
		       h_tight_t_absz->Fill(p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z),wt);
		       h_tight_eta->Fill(p->ph_eta1,wt);
		       //		       h_tight_gain->Fill(p->ph_gain1);
		       h_tight_t_abseta->Fill(p->ph_t1,fabs(p->ph_eta1),wt);
		       h_tight_z_abseta->Fill(p->ph_calo_z1 - p->PV_z,fabs(p->ph_eta1),wt);
		       //  h_tight_t_gain->Fill(p->ph_t1,p->ph_gain1,wt);
		       //h_tight_z_gain->Fill(p->ph_calo_z1 - p->PV_z,p->ph_gain1,wt);
		       h_leading_tight_t->Fill(p->ph_t1,wt);
		       h_leading_tight_z->Fill(p->ph_calo_z1 - p->PV_z,wt);
		       h_tight_z_conv->Fill(p->ph_calo_z1 - p->PV_z,p->ph_convType1,wt);
		       h_tight_t_conv->Fill(p->ph_t1,p->ph_convType1,wt);
		       h_tight_t1->Fill(p->ph_t1,wt);
		       h_tight_calo_z1->Fill(p->ph_calo_z1,wt);
		       if (p->ph_convType1 == 0) {
			 h_tight_z_conv0->Fill(p->ph_calo_z1 - p->PV_z, wt);
			 h_tight_t_conv0->Fill(p->ph_t1,wt);
		       }
		       if (p->ph_convType1 > 0) {
			 h_tight_z_conv1->Fill(p->ph_z1- p->PV_z, wt);
			 h_tight_t_conv1->Fill(p->ph_t1,wt);
		       }
		       if ( (p->ph_t1 < -3) && (p->ph_t1 > -6) ) {
			 h_tight_minus5t_z->Fill(p->ph_z1- p->PV_z, wt);
		       }
		       if ( (p->ph_t1 < 2) && (p->ph_t1 > -2) ) {
                         h_tight_pm2t_z->Fill(p->ph_z1- p->PV_z, wt);
                       }
		     }

		     if(!p->ph_isTight1) {
		       h_loose_eta1->Fill(p->ph_eta1,wt);
		       h_loose_pt1->Fill(p->ph_pt1,wt);
		       h_loose_t_z->Fill(p->ph_t1,p->ph_calo_z1 - p->PV_z,wt);
		       h_loose_t_absz->Fill(p->ph_t1,fabs(p->ph_calo_z1 - p->PV_z),wt);
		       h_loose_eta->Fill(p->ph_eta1,wt);
                       //h_loose_gain->Fill(p->ph_gain1);
		       h_loose_t_abseta->Fill(p->ph_t1,fabs(p->ph_eta1),wt);
		       h_loose_z_abseta->Fill(p->ph_calo_z1 - p->PV_z,fabs(p->ph_eta1),wt);
		       //h_loose_t_gain->Fill(p->ph_t1,p->ph_gain1,wt);
		       //h_loose_z_gain->Fill(p->ph_calo_z1 - p->PV_z,p->ph_gain1,wt);
		       h_leading_loose_t->Fill(p->ph_t1,wt);
		       h_leading_loose_z->Fill(p->ph_calo_z1 - p->PV_z,wt);
		       h_loose_z_conv->Fill(p->ph_calo_z1 - p->PV_z,p->ph_convType1,wt);
		       h_loose_t_conv->Fill(p->ph_t1,p->ph_convType1,wt);
		       h_loose_t1->Fill(p->ph_t1,wt);
		       h_loose_calo_z1->Fill(p->ph_calo_z1,wt);
		       if (p->ph_convType1 == 0){
                         h_loose_z_conv0->Fill(p->ph_calo_z1 - p->PV_z, wt);
                         h_loose_t_conv0->Fill(p->ph_t1,wt);
		       }
                       if (p->ph_convType1 > 0) {
                         h_loose_z_conv1->Fill(p->ph_z1- p->PV_z, wt);
                         h_loose_t_conv1->Fill(p->ph_t1,wt);
		       }
		       if ( (p->ph_t1 < -3) && (p->ph_t1 > -6) ) {
                         h_loose_minus5t_z->Fill(p->ph_z1- p->PV_z, wt);
                       }
		       if ( (p->ph_t1 < 2) && (p->ph_t1 > -2) ) {
                         h_loose_pm2t_z->Fill(p->ph_z1- p->PV_z, wt);
                       }
                     }

		     if (p->ph_isTight2) {
		       h_tight_eta2->Fill(p->ph_eta2,wt);
		       h_tight_pt2->Fill(p->ph_pt2);
		       h_tight_t_z->Fill(p->ph_t2,p->ph_z2 - p->PV_z,wt);
		       h_tight_t_absz->Fill(p->ph_t2,fabs(p->ph_z2 - p->PV_z),wt);
		       h_tight_eta->Fill(p->ph_eta2,wt);
                       //h_tight_gain->Fill(p->ph_gain2);
		       h_tight_t_abseta->Fill(p->ph_t2,fabs(p->ph_eta2),wt);
		       h_tight_z_abseta->Fill(p->ph_z2 - p->PV_z,fabs(p->ph_eta2),wt);
		       //h_tight_t_gain->Fill(p->ph_t2,p->ph_gain2,wt);
		       //h_tight_z_gain->Fill(p->ph_z2 - p->PV_z,p->ph_gain2,wt);
		       h_tight_z_conv->Fill(p->ph_z2 - p->PV_z,p->ph_convType2,wt);
		       h_tight_t_conv->Fill(p->ph_t2,p->ph_convType2,wt);
		       h_tight_t2->Fill(p->ph_t2,wt);
                       h_tight_calo_z2->Fill(p->ph_calo_z2,wt);
                       if (p->ph_convType2 == 0) {
                         h_tight_z_conv0->Fill(p->ph_z2 - p->PV_z, wt);
                         h_tight_t_conv0->Fill(p->ph_t2,wt);
                       }
                       if (p->ph_convType2 > 0) {
                         h_tight_z_conv1->Fill(p->ph_z2 - p->PV_z, wt);
                         h_tight_t_conv1->Fill(p->ph_t2,wt);
                       }
		       if ( (p->ph_t2 < -3) && (p->ph_t2 > -6) ) {
                         h_tight_minus5t_z->Fill(p->ph_z2- p->PV_z, wt);
		       }
		       if ( (p->ph_t2 < 2) && (p->ph_t2 > -2) ) {
                         h_tight_pm2t_z->Fill(p->ph_z2- p->PV_z, wt);
                       }
                     }

                     if(!p->ph_isTight2) {
		       h_loose_eta2->Fill(p->ph_eta2,wt);
		       h_loose_pt2->Fill(p->ph_pt2,wt);
		       h_loose_t_z->Fill(p->ph_t2,p->ph_z2 - p->PV_z,wt);
		       h_loose_t_absz->Fill(p->ph_t2,fabs(p->ph_z2 - p->PV_z),wt);
		       h_loose_eta->Fill(p->ph_eta2,wt);
                       //h_loose_gain->Fill(p->ph_gain2);
                       h_loose_t_abseta->Fill(p->ph_t2,fabs(p->ph_eta2),wt);
		       h_loose_z_abseta->Fill(p->ph_z2 - p->PV_z,fabs(p->ph_eta2),wt);
                       //h_loose_t_gain->Fill(p->ph_t2,p->ph_gain2,wt);
                       //h_loose_z_gain->Fill(p->ph_z2 - p->PV_z,p->ph_gain2,wt);
		       h_loose_z_conv->Fill(p->ph_z2 - p->PV_z,p->ph_convType2,wt);
                       h_loose_t_conv->Fill(p->ph_t2,p->ph_convType2,wt);
		       h_loose_t2->Fill(p->ph_t2,wt);
                       h_loose_calo_z2->Fill(p->ph_calo_z2,wt);
                       if (p->ph_convType2 == 0){
                         h_loose_z_conv0->Fill(p->ph_z2 - p->PV_z, wt);
                         h_loose_t_conv0->Fill(p->ph_t2,wt);
                       }
                       if (p->ph_convType2 > 0) {
                         h_loose_z_conv1->Fill(p->ph_z2 - p->PV_z, wt);
                         h_loose_t_conv1->Fill(p->ph_t2,wt);
                       }
		       if ( (p->ph_t2 < -3) && (p->ph_t2 > -6) ) {
                         h_loose_minus5t_z->Fill(p->ph_z2- p->PV_z, wt);
                       }
		       if ( (p->ph_t2 < 2) && (p->ph_t2 > -2) ) {
                         h_loose_pm2t_z->Fill(p->ph_z2- p->PV_z, wt);
                       }
                     }

		     // use all photons to fill the following two histograms.
		     h_conv -> Fill( p->ph_convType1 , wt);
		     h_conv -> Fill( p->ph_convType2 , wt);
		     /*

		      
                       
		       unconverted = 0 : unconverted photon
		       singleSi = 1 : one track only, with Si hits
		       singleTRT = 2 : one track only, no Si hits (TRT only)
		       doubleSi = 3 : two tracks, both with Si hits
		       doubleTRT = 4 : two tracks, none with Si hits (TRT only)
		       doubleSiTRT = 5 : two tracks, only one with Si hits
                       https://twiki.cern.ch/twiki/bin/view/AtlasProtected/EGammaD3PDtoxAOD#Photon_conversion_type
		     */

		   }


		 // Histograms need to be written into a TFile for further processing
                 TFile f("output_signal.root","recreate");
		 h_tight_t->Write();
		 h_loose_t->Write();
		 

		 h_tight_z->Write();
		 h_loose_z->Write();

		 h_conv->Write();
		 
		 h_tight_z_conv0->Write();
		 h_tight_z_conv1->Write();
		 h_loose_z_conv0->Write();
		 h_loose_z_conv1->Write();

		 h_tight_t_conv0->Write();
         h_tight_t_conv1->Write();
         h_loose_t_conv0->Write();
         h_loose_t_conv1->Write();

		 h_tight_z_conv->Write();
		 h_loose_z_conv->Write();
		 h_tight_t_conv->Write();
		 h_loose_t_conv->Write();
		 
		 h_tight_minus5t_z->Write();
		 h_loose_minus5t_z->Write();
		 h_tight_pm2t_z->Write();
		 h_loose_pm2t_z->Write();

		 h_leading_tight_t->Write();
		 h_leading_tight_z->Write();
		 h_leading_loose_t->Write();
		 h_leading_loose_z->Write();

		 h_tight_t_abseta->Write();
		 h_loose_t_abseta->Write();
		 h_tight_eta->Write();
		 h_loose_eta->Write();
		 
		 h_tight_z_abseta->Write();
		 h_loose_z_abseta->Write();
		 
		 h_tight_t_z->Write();
		 h_loose_t_z->Write();
		 h_tight_t_absz->Write();
		 h_loose_t_absz->Write();

		 h_tight_t1->Write();
		 h_tight_t2->Write();
		 h_loose_t1->Write();
		 h_loose_t2->Write();
		 h_tight_calo_z1->Write();
		 h_tight_calo_z2->Write();
		 h_loose_calo_z1->Write();
		 h_loose_calo_z2->Write();
		 
		 h_missing_ET->Write();
		 h_CF->Write();

		 h_pt1->Write();
		 h_pt2->Write();
		 h_tight_pt1->Write();
		 h_tight_pt2->Write();
		 h_loose_pt1->Write();
		 h_loose_pt2->Write();
		 h_eta1->Write();
		 h_eta2->Write();
		 h_tight_eta1->Write();
		 h_tight_eta2->Write();
		 h_loose_eta1->Write();
		 h_loose_eta2->Write();

		 h_single_tight_calo_z->Write();
		 h_single_loose_calo_z->Write();
		 
		 h_timing_zdca_yields->Write();
		 h_timing_zdca_yields_CR->Write();
		 h_timing_zdca_yields_SR1->Write();
		 h_timing_zdca_yields_SR2->Write();
		 h_CF_likedata->Write();

		 h_timing_zdca_CR->Write(); 
		 h_timing_zdca_SR1->Write();
		 h_timing_zdca_SR2->Write();

         f.Close();


		 return 0 ;
}







