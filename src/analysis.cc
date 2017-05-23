#include "analysis.hh"


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
		 
		 p = new output(chain);


		 int numev = p->fChain->GetEntries();

		 double lumi = 1.0;

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

		 double timing_bins[] = {-4,0.5,1.1,1.3,1.5,1.8,10000};
		 int n_timing_bins = sizeof(timing_bins)/sizeof(*timing_bins) - 1;

		 double z_dca_bins[] = {0,40,80,120,160,200,9999999};
		 int n_zdca_bins = sizeof(z_dca_bins)/sizeof(*z_dca_bins) - 1;


		 TH2F *h_timing_zdca_yields = new TH2F("h_timing_zdca_yields","h_timing_zdca_yields",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);
		 TH2F *h_timing_zdca_yields_CR = new TH2F("h_timing_zdca_yields_CR","h_timing_zdca_yields_CR",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);
		 TH2F *h_timing_zdca_yields_SR1 = new TH2F("h_timing_zdca_yields_SR1","h_timing_zdca_yields_SR1",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);
		 TH2F *h_timing_zdca_yields_SR2 = new TH2F("h_timing_zdca_yields_SR2","h_timing_zdca_yields_SR2",n_timing_bins,0,n_timing_bins,n_zdca_bins,0,n_zdca_bins);

		 h_timing_zdca_yields->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields_CR->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields_SR1->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields_SR2->GetXaxis()->SetTitle("t [ns]");
		 h_timing_zdca_yields->GetYaxis()->SetTitle("Z_{DCA} [mm]");
		 h_timing_zdca_yields_CR->GetYaxis()->SetTitle("Z_{DCA} [mm]");
		 h_timing_zdca_yields_SR1->GetYaxis()->SetTitle("Z_{DCA} [mm]");
		 h_timing_zdca_yields_SR2->GetYaxis()->SetTitle("Z_{DCA} [mm]");

		 TString bin_name;
		 for (int k = 0; k < n_timing_bins; k++) {
		 	bin_name.Form("%.2f - %.2f",timing_bins[k],timing_bins[k+1]);
		 	if (k+1 == n_timing_bins) bin_name.Form("%.0f -",timing_bins[k]);
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

		 TH1F* h_CF = new TH1F("h_CF","h_CF",20,0,20);
		 TH1F* h_CF_nowt = new TH1F("h_CF_nowt","h_CF_nowt",20,0,20);
		 
		 double t1 = 0;
		 double z_dca = 0;

		 int t_bin = -999;
		 int z_bin = -999;

		 TH2F *h_timing_zdca_CR = new TH2F("h_timing_zdca_CR","h_timing_zdca_CR",210,-21,21,200,0,2000);
		 TH2F *h_timing_zdca_SR1 = new TH2F("h_timing_zdca_SR1","h_timing_zdca_SR1",210,-21,21,200,0,2000);
		 TH2F *h_timing_zdca_SR2 = new TH2F("h_timing_zdca_SR2","h_timing_zdca_SR2",210,-21,21,200,0,2000);

		 TH2F *h_timing_zdca_CR_nowt = new TH2F("h_timing_zdca_CR_nowt","h_timing_zdca_CR_nowt",210,-21,21,200,0,2000);
		 TH2F *h_timing_zdca_SR1_nowt = new TH2F("h_timing_zdca_SR1_nowt","h_timing_zdca_SR1_nowt",210,-21,21,200,0,2000);
		 TH2F *h_timing_zdca_SR2_nowt = new TH2F("h_timing_zdca_SR2_nowt","h_timing_zdca_SR2_nowt",210,-21,21,200,0,2000);


		 TH1F* h_conv = new TH1F("h_conv","h_conv",6,0,6);
		 for( int i = 0 ; i < numev ; i ++ )
		   {	
		     get_event(i) ;
		     
		     // This code fills histograms after a simple preselection/
		     // The events selected by NonPointing package contains at least two loose photons

		     // m_weight is an event weight variable. For data it is set to 1. 
                     // For Monte Carlo, it takes care of xsection times weight from offline correction over sum of weighted number of events.
		     // this variable doesn't include luminosity
		     double wt = p->m_weight;

		     // mcChannelNumber is an identifier for a particular physics process that is simulated.
                     // if mcChannelNumber is 0 or negative, this sample is data. 
		     if( p->m_mcChannelNumber > 0 ) wt *= lumi;

		     t1 = p->ph_t1;
		     z_dca = fabs(p->ph_z1 - p->PV_z);



		     for (int k = 0; k < n_timing_bins; k++) {
		     	if ( (t1 > timing_bins[k]) && (t1 < timing_bins[k+1]) ) {
		     		t_bin = k + 0.5;
		     	}
		     }

		     for (int k = 0; k < n_zdca_bins; k++) {
		     	if ( (z_dca > z_dca_bins[k]) && (z_dca < z_dca_bins[k+1]) ) {
		     		z_bin = k + 0.5;
		     	}
		     }

	     	 h_CF->Fill(0.5,wt);
	     	 h_CF_nowt->Fill(0.5);

	     	 if (p->m_met < 20) {h_CF->Fill(1.5,wt); h_CF_nowt->Fill(1.5);}//CR
	     	 if ( (p->m_met > 20) && (p->ph_pt1 > 150) ) {h_CF->Fill(2.5,wt);h_CF_nowt->Fill(2.5);} //SR1
	     	 if ( (p->m_met > 70) && (p->ph_pt1 > 150) ) {h_CF->Fill(3.5,wt);h_CF_nowt->Fill(3.5);} //SR2
		     // m_met, the missing transverse energy 
		     if( p-> m_met > 20 ) continue ; // blinding regions with potential signal contributions

		     if (p->m_met < 20) {h_timing_zdca_yields_CR->Fill(t_bin,z_bin,wt); h_timing_zdca_CR->Fill(t1,z_dca,wt);h_timing_zdca_CR_nowt->Fill(t1,z_dca);} //Control Region
		     if (p->m_met > 20 && p->ph_pt1 > 150) {h_timing_zdca_yields_SR1->Fill(t_bin,z_bin,wt); h_timing_zdca_SR1->Fill(t1,z_dca,wt);h_timing_zdca_SR1_nowt->Fill(t1,z_dca);} // SR1 -- not filled now for data
		     if (p->m_met > 70 && p->ph_pt1 > 150) {h_timing_zdca_yields_SR2->Fill(t_bin,z_bin,wt); h_timing_zdca_SR2->Fill(t1,z_dca,wt);h_timing_zdca_SR2_nowt->Fill(t1,z_dca);} // SR2 -- not filled now for data

		     t_bin = -999;
		     z_bin = -999;


		     // ph_isTight1(2) flag for tight photons
		     if (p->ph_isTight1) h_tight_z -> Fill( p->ph_z1 - p->PV_z, wt );
		     // Note that Z_DCA is defined as photon vertex z minus primary vertex z 
		     if(p->ph_isTight2) h_tight_z -> Fill( p->ph_z2 - p->PV_z , wt );

		     // when isTight flag is false, the photon is a loose photon  
		     if(!p->ph_isTight1) h_loose_z -> Fill( p->ph_z1 - p->PV_z, wt );
		     if(!p->ph_isTight2) h_loose_z -> Fill( p->ph_z2 - p->PV_z, wt );


		     if(p->ph_isTight1) h_tight_t -> Fill( p->ph_t1 , wt );
		     if(p->ph_isTight2) h_tight_t -> Fill( p->ph_t2 , wt );

		     if(!p->ph_isTight1) h_loose_t -> Fill( p->ph_t1 , wt );
		     if(!p->ph_isTight2) h_loose_t -> Fill( p->ph_t2 , wt );


		     //Fill tight/loose histograms for first
		     if (p->ph_isTight1) {
		       h_tight_t_z->Fill(p->ph_t1,p->ph_z1 - p->PV_z,wt);
		       h_tight_t_absz->Fill(p->ph_t1,fabs(p->ph_z1 - p->PV_z),wt);
		       h_tight_eta->Fill(p->ph_eta1,wt);
		       h_tight_t_abseta->Fill(p->ph_t1,fabs(p->ph_eta1),wt);
		       h_tight_z_abseta->Fill(p->ph_z1 - p->PV_z,fabs(p->ph_eta1),wt);
		       h_leading_tight_t->Fill(p->ph_t1,wt);
		       h_leading_tight_z->Fill(p->ph_z1 - p->PV_z,wt);
		       h_tight_z_conv->Fill(p->ph_z1 - p->PV_z,p->ph_convType1,wt);
		       h_tight_t_conv->Fill(p->ph_t1,p->ph_convType1,wt);
		       if (p->ph_convType1 == 0) {
			 	h_tight_z_conv0->Fill(p->ph_z1 - p->PV_z, wt);
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
		       h_loose_t_z->Fill(p->ph_t1,p->ph_z1 - p->PV_z,wt);
		       h_loose_t_absz->Fill(p->ph_t1,fabs(p->ph_z1 - p->PV_z),wt);
		       h_loose_eta->Fill(p->ph_eta1,wt);
		       h_loose_t_abseta->Fill(p->ph_t1,fabs(p->ph_eta1),wt);
		       h_loose_z_abseta->Fill(p->ph_z1 - p->PV_z,fabs(p->ph_eta1),wt);
		       h_leading_loose_t->Fill(p->ph_t1,wt);
		       h_leading_loose_z->Fill(p->ph_z1 - p->PV_z,wt);
		       h_loose_z_conv->Fill(p->ph_z1 - p->PV_z,p->ph_convType1,wt);
		       h_loose_t_conv->Fill(p->ph_t1,p->ph_convType1,wt);
		       if (p->ph_convType1 == 0){
                         h_loose_z_conv0->Fill(p->ph_z1 - p->PV_z, wt);
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
		       h_tight_t_z->Fill(p->ph_t2,p->ph_z2 - p->PV_z,wt);
		       h_tight_t_absz->Fill(p->ph_t2,fabs(p->ph_z2 - p->PV_z),wt);
		       h_tight_eta->Fill(p->ph_eta2,wt);
		       h_tight_t_abseta->Fill(p->ph_t2,fabs(p->ph_eta2),wt);
		       h_tight_z_abseta->Fill(p->ph_z2 - p->PV_z,fabs(p->ph_eta2),wt);
		       h_tight_z_conv->Fill(p->ph_z2 - p->PV_z,p->ph_convType2,wt);
		       h_tight_t_conv->Fill(p->ph_t2,p->ph_convType2,wt);
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
		       h_loose_t_z->Fill(p->ph_t2,p->ph_z2 - p->PV_z,wt);
		       h_loose_t_absz->Fill(p->ph_t2,fabs(p->ph_z2 - p->PV_z),wt);
		       h_loose_eta->Fill(p->ph_eta2,wt);
               h_loose_t_abseta->Fill(p->ph_t2,fabs(p->ph_eta2),wt);
		       h_loose_z_abseta->Fill(p->ph_z2 - p->PV_z,fabs(p->ph_eta2),wt);
		       h_loose_z_conv->Fill(p->ph_z2 - p->PV_z,p->ph_convType2,wt);
               h_loose_t_conv->Fill(p->ph_t2,p->ph_convType2,wt);
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
                 TFile f("output.root","recreate");
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
		 //h_tight_gain->Write();
		 //h_loose_gain->Write();

		 h_tight_z_abseta->Write();
		 h_loose_z_abseta->Write();
		 //h_tight_t_gain->Write();
		 //h_loose_t_gain->Write();
		 //h_tight_z_gain->Write();
		 //h_loose_z_gain->Write();

		 h_tight_t_z->Write();
		 h_loose_t_z->Write();
		 h_tight_t_absz->Write();
		 h_loose_t_absz->Write();

		 h_timing_zdca_yields->Write();
		 h_timing_zdca_yields_CR->Write();
		 h_timing_zdca_yields_SR1->Write();
		 h_timing_zdca_yields_SR2->Write();
		 h_CF->Write();
		 h_CF_nowt->Write();

		 h_timing_zdca_CR->Write(); 
		 h_timing_zdca_SR1->Write();
		 h_timing_zdca_SR2->Write();

		 h_timing_zdca_CR_nowt->Write();
		 h_timing_zdca_SR1_nowt->Write();
		 h_timing_zdca_SR2_nowt->Write();

                 f.Close();


		 return 0 ;
}







