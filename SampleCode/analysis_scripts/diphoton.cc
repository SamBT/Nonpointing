/*
Created by Haichen Wang November 8, 2012
 */

#include "plotoutput.hh"


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
		 double ptcut = atof(argv[1]);
		 double metcut = atof(argv[2]);

		 cout << metcut << " " << ptcut<<endl;
		 
		 int const index = argc - 3;
		
		 TString path[index];
		 
		 for ( int j = 0; j < argc-3; j++)
		 {
			path[j] = (argv[j+3]);
		 }
		 
		 TChain *chain = new TChain("output");
		 
		 for (int k = 0; k < argc-3 ; k++)
		 {
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


		 double z[7] = { 0, 40 , 80 , 120 , 160 , 200 , 90000};
			 //  double t[7] = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};
		 double t[7] = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};

		 //		 double t[7] = { 0.0 , 0.4, 0.8, 1.2, 1.6, 2.0, 90000};

		 for( int i = 0 ; i < numev ; i ++ )
		   {	
		     get_event(i) ;
		     double wt =  1; if ( p->wt_xs!=0 ) wt = lumi*1000*1000*p->wt_xs*p->wt_ge/p->wt_nEvents ;

			 h_CF -> Fill(-0.5,wt);

                         if( p->HLT_g35_loose_g25_loose == 1  ) h_CF -> Fill( 0.5, wt);
                         if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut ) h_CF -> Fill( 1.5, wt);
                         if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 ) h_CF -> Fill( 2.5, wt);
                         if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met > metcut ) h_CF -> Fill( 3.5, wt);
                         if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met > metcut && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 4.5, wt);
                         if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut &&                                     p->m_met < 20     && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 5.5, wt);
			 //                         if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met < 20     ) h_CF -> Fill( 4.5, wt);

			 /*
                         if( p->m_met > metcut  ) h_CF -> Fill( 0.5, wt);
                         if( p->m_met > metcut && p->ph_pt2 > ptcut ) h_CF -> Fill( 1.5, wt);
                         if( p->m_met > metcut && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 ) h_CF -> Fill( 2.5, wt);
                         if( p->m_met > metcut && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->HLT_g35_loose_g25_loose == 1 ) h_CF -> Fill( 3.5, wt);
                         if( p->m_met < 20     && p->ph_pt2 > ptcut                                     && p->HLT_g35_loose_g25_loose == 1 ) h_CF -> Fill( 4.5, wt);
			 */

		     if(!p->HLT_g35_loose_g25_loose) continue ;

		     if( p->ph_pt2 < ptcut ) continue ; 

		     if( fabs(p->ph_eta1) > 1.37 && fabs(p->ph_eta2) > 1.37 ) continue ;

		     for( int a = 0 ; a < 15 ; a ++ )
		       {
			 for( int b = 0 ; b < 15 ; b++ )
			   {
			     double pTcut = 40 + 10*a;
			     double METcut = 70 + 10*b ;
			     if(p->ph_pt1>pTcut && p->m_met>METcut)
			       h_N->Fill(a+0.5,b+0.5,wt);
			   }
		       }


		     double dZsigned  =  p->ph_calo_z1 - p->PV_z ; 

		     double timing = p->ph_t1 ;
		     double caloZ = p->ph_calo_z1 ;

		     if( fabs(p->ph_eta1) <= 1.37 && fabs(p->ph_eta2) <= 1.37  )
		       {
			 dZsigned = p->ph_t1 > p->ph_t2 ?  ( p->ph_calo_z1 - p->PV_z) :  ( p->ph_calo_z2 - p->PV_z) ;
			 timing =  p->ph_t1 > p->ph_t2 ? p->ph_t1 : p->ph_t2 ;
			 caloZ =  p->ph_t1 > p->ph_t2 ? p->ph_calo_z1 : p->ph_calo_z2 ;
		       }
		     else if ( fabs(p->ph_eta1) > 1.37 && fabs(p->ph_eta2) < 1.37  ) 
		       {
			 dZsigned  = ( p->ph_calo_z2 - p->PV_z) ;
			 timing = p->ph_t2 ;
			 caloZ = p->ph_calo_z2 ;
		       }

		     double dZ = fabs(dZsigned);

                     for( int k = 0 ; k < 6 ; k ++ )
                       {

			 if( dZ  > z[k] &&  dZ < z[k+1] )
			   { 

                             if( p->m_met<20) {h_Z_CR -> Fill( k+0.5, wt ) ;
                               // No isolation requirement is applied to the control region
                             }
                             if(p->m_met > metcut)
                               {

				 if( p->ph_passIso1 && p->ph_passIso2)
				   {
				     h_Z_SR -> Fill( k+0.5, wt ) ;
				     h_ph1_iso_z-> Fill( caloZ ,wt );
				     h_ph1_iso_dZ-> Fill( dZsigned ,wt );
				     h_ph1_iso_t -> Fill( timing, wt );
				   }
				 else
				   {
				     h_ph1_noniso_z-> Fill( caloZ ,wt );
				     h_ph1_noniso_dZ-> Fill( dZsigned ,wt );
				     h_ph1_noniso_t -> Fill( timing, wt );
				   }

                               }

			   }

                       }


		     //		     if( !p->ph_passIso1 || !p->ph_passIso2 ) continue ; 




		     //		    		     if( p->ph_pt1 < 150 ) continue ;
		     if( p->wt_xs != 0 ){
		     
		     h_pt -> Fill( p-> ph_pt1 , wt );
		     h_eta -> Fill( p-> ph_eta1 , wt );
		     h_met -> Fill( p-> m_met , wt );
		     h_ph1_z -> Fill( caloZ , wt);
		     h_ph1_t -> Fill(timing , wt);
		       if( p-> m_met < metcut || !p->ph_passIso1 || !p->ph_passIso2 ) continue ;
		     }
		     else 
		       {
			 if( p->m_met > 20 ) continue ;
			 h_pt -> Fill( p-> ph_pt1 , wt );
			 h_eta -> Fill( p-> ph_eta1 , wt );
			 h_met -> Fill( p-> m_met , wt );
			 h_ph1_z -> Fill( caloZ , wt);
			 h_ph1_t -> Fill(timing , wt);

		       }



		     for( int k = 0 ; k < 6 ; k ++ )
		       {
			 for( int l = 0 ; l < 6 ; l ++)
			   {
			     //			     cout << dZ << " " << timing << endl;


			       if( dZ  > z[k] &&  dZ < z[k+1] &&timing>t[l] &&timing<t[l+1])
				 { 
				   if( p->wt_xs == 0 ){
				     h_yield -> Fill( l, k, wt*(h_Z_SR->GetBinContent(k+1) / h_Z_CR -> GetBinContent(k+1) ) );
				     h_yield_raw -> Fill( l, k, wt );
				   }
				   else 
				     h_yield -> Fill( l, k, wt );

				   //	   cout << "Filling bin k = " << k << " and bin l " << l << endl;
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
                 f.Close();


		 return 0 ;
}







