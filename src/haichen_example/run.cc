/*
Created by Haichen Wang November 8, 2012
 */

#include "plotoutput.hh"

#include "DSinfo.hh"

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

		 /*loading job configuration*/
		 ifstream file_to_read("job.config");
		 // the job config file has two columns, the first is variable name, and the second variable values
		 // this information will be loaded to a map<string,double>
		 if(file_to_read.is_open() != 1 )
		   {
		     cout << "The job.config file doesn't exist" << endl;
		     exit(1);
		   }
		 map<string,double> config ;

		 while(!file_to_read.eof())
		   {
		     string tmp_name ;
		     double tmp_value ;
		     file_to_read >> tmp_name >> tmp_value ;
		     config[tmp_name] = tmp_value ;
		     cout << tmp_name << " " <<   config[tmp_name] << endl;
		   }

		 cout << config["metcut"] << " " << config["ptcut"]<<endl;
		 /*END loading job configuration*/
		 
		 /* Adding input root files to a chain */
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
		 /* END Adding input root files to a chain */


		 /* Parameters, configuraiton */
		 int numev = p->fChain->GetEntries();
		 double lumi = 32.9;

		 get_event(0) ;
		 int DSID = p->m_mcChannelNumber;
		 bool isData = p->m_mcChannelNumber < 0 ;
		 map<string,double> sample = DSinfo( p->m_mcChannelNumber );
		 double xs = sample["xs"];
		 int mg = sample["mg"];
		 int mx = sample["mx"];
		 double lifetime = sample["t"];
		 if(config["debug"]==0) cout << "Sample info " << p->m_mcChannelNumber << " xs (pb) " << xs << " mg, mx (GeV) " << mg << " , " << mx << " lifetime (ns) " << lifetime  << endl; 
		 int Nevents = 20000 ;

		 double ptcut = 0 ;
		 if(config["anaflag"]==1) ptcut = config["ptcut1"];
		 if(config["anaflag"]==2) ptcut = config["ptcut2"];

		 double z[7] = { 0, 40 , 80 , 120 , 160 , 200 , 90000};
		 double t[7] = { -4, 0.5 , 1.1, 1.3, 1.5, 1.8, 90000};

		 /* END Parameters, configuraiton */



		 /* Histogram declaration */

		 // analysis 
		 TH1F* h_CF = new TH1F("h_CF","h_CF",10,0,10);
		 TH2F* h_yield = new TH2F("h_yield","h_yield",6,0,6,6,0,6);
		 TH2F* h_yield_raw = new TH2F("h_yield_raw","h_yield_raw",6,0,6,6,0,6);
		 TH1F* h_Z_CR = new TH1F("h_Z_CR","h_Z_CR",6,0,6);
		 TH1F* h_Z_SR = new TH1F("h_Z_SR","h_Z_SR",6,0,6);


		 // event level quantity
		 TH1F* h_met = new TH1F("h_met","h_met",200,0,2000);
		 TH1F* h_z = new TH1F("h_z","h_z",400,-2000,2000);
		 TH1F* h_t = new TH1F("h_t","h_t",400,-20,20);


		 // object level quantity

		 TH1F* h1_pt = new TH1F("h1_pt","h1_pt",100,0,2000);
		 TH1F* h1_eta = new TH1F("h1_eta","h1_eta",50,-2.5,2.5);
		 TH1F* h1_z = new TH1F("h1_z","h1_z",400,-2000,2000);
		 TH1F* h1_t = new TH1F("h1_t","h1_t",400,-20,20);

		 TH1F* h2_pt = new TH1F("h2_pt","h2_pt",100,0,2000);
		 TH1F* h2_eta = new TH1F("h2_eta","h2_eta",50,-2.5,2.5);
		 TH1F* h2_z = new TH1F("h2_z","h2_z",400,-2000,2000);
		 TH1F* h2_t = new TH1F("h2_t","h2_t",400,-20,20);









		 TH2F* h_N = new TH2F("h_N","h_N",15,0,15,15,0,15);
		 /*END Histogram declaration */





		 cout << " total number of events to be processed " << numev << endl;
		 for( int i = 0 ; i < numev ; i ++ )
		   {	
		     get_event(i) ;
		     if( i%10000 == 0 ) cout << " processed " << i << " events " << endl;

		     double wt =  1; 
		     if( !isData && p->m_mcChannelNumber >= 403280 && p->m_mcChannelNumber <= 403286) wt = lumi*1000*1000*p->wt_xs*p->wt_ge/p->wt_nEvents ;
		     if( !isData) wt = lumi*1000*xs/Nevents;
		     if(config["debug"]) cout << "event weight = " << wt << endl;

		     /* block of cutflow */

		     // initial
		     // trigger
		     // both loose 
		     // both pT 
		     // both isolated
		     // met
		     // one central
		     // CR
		     if( config["anaflag"] == 2){
		     h_CF -> Fill(-0.5,wt);
		     if( p->HLT_g35_loose_g25_loose == 1 ) h_CF -> Fill( 0.5, wt);
		     else continue ; // this check also serves as a preselection 
		     if( p->HLT_g35_loose_g25_loose == 1  && p->ph_isLoose1 && p->ph_isLoose2 ) h_CF -> Fill( 1.5, wt);
		     if( p->HLT_g35_loose_g25_loose == 1  && p->ph_isLoose1 && p->ph_isLoose2  && p->ph_pt2 > ptcut ) h_CF -> Fill( 2.5, wt);
		     if( p->HLT_g35_loose_g25_loose == 1  && p->ph_isLoose1 && p->ph_isLoose2  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 ) h_CF -> Fill( 3.5, wt);
		     if( p->HLT_g35_loose_g25_loose == 1  && p->ph_isLoose1 && p->ph_isLoose2  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met > config["metcut"] ) h_CF -> Fill( 4.5, wt);
		     if( p->HLT_g35_loose_g25_loose == 1  && p->ph_isLoose1 && p->ph_isLoose2  && p->ph_pt2 > ptcut && p->ph_passIso1 && p->ph_passIso2 && p->m_met > config["metcut"] && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 5.5, wt);
		     if( p->HLT_g35_loose_g25_loose == 1  && p->ph_pt2 > ptcut &&                                     p->m_met < config["CRmet"]     && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 6.5, wt);
		     }
		     if( config["anaflag"] == 1){
		     h_CF -> Fill(-0.5,wt);
		     bool passdiphoton = p->HLT_g35_loose_g25_loose == 1  && p->ph_isLoose1 && p->ph_isLoose2 && p->ph_passIso1 && p->ph_passIso2 && p->ph_pt2 > config["ptcut1"] ;

		     if( p->HLT_g140_loose == 1 && (!passdiphoton) ) h_CF -> Fill( 0.5, wt);
		     else continue ; // this check also serves as a preselection 
		     if( p->HLT_g140_loose == 1  && p->ph_isLoose1 ) h_CF -> Fill( 1.5, wt);
		     if( p->HLT_g140_loose == 1  && p->ph_isLoose1 && p->ph_pt1 > ptcut ) h_CF -> Fill( 2.5, wt);
		     if( p->HLT_g140_loose == 1  && p->ph_isLoose1 && p->ph_pt1 > ptcut && p->ph_passIso1  ) h_CF -> Fill( 3.5, wt);
		     if( p->HLT_g140_loose == 1  && p->ph_isLoose1 && p->ph_pt1 > ptcut && p->ph_passIso1  && p->m_met > config["metcut"] ) h_CF -> Fill( 4.5, wt);
		     if( p->HLT_g140_loose == 1  && p->ph_isLoose1 && p->ph_pt1 > ptcut && p->ph_passIso1  && p->m_met > config["metcut"] && fabs(p->ph_eta1) < 1.37 ) h_CF -> Fill( 5.5, wt);
		     if( p->HLT_g140_loose == 1  && p->ph_isLoose1 && p->ph_pt1 > ptcut &&                                     p->m_met < config["CRmet"]     && (fabs(p->ph_eta1) < 1.37 || fabs(p->ph_eta2) < 1.37)) h_CF -> Fill( 6.5, wt);
		     }


		     /* Basic selection */

		     bool isolation = false ;
		     bool preselection = false ;
		     if( config["anaflag"] == 2 ){
		       if( p->ph_pt2 < ptcut ) continue ;
		       if( fabs(p->ph_eta1) > 1.37 && fabs(p->ph_eta2) > 1.37 ) continue ;
		       if( !p->ph_isLoose1 || !p->ph_isLoose2 ) continue ;
		       isolation = p->ph_passIso1 && p->ph_passIso2 ;
		     }
		     else if( config["anaflag"] == 1 ){
                       if( p->ph_pt1 < ptcut ) continue ;
                       if( fabs(p->ph_eta1) > 1.37 ) continue ;
		       if( !p->ph_isLoose1 ) continue ;
		       isolation = p->ph_passIso1 ;
		     }

		     bool CR = p->m_met < config["CRmet"] && isolation ;
		     bool SR = p->m_met > config["metcut"] && isolation ;

		     /* END Basic selection */

		     /* Determining photon used for the analysis */

		     // by default, use leading photon, and switch if needed
		     double dZsigned  =  p->ph_calo_z1 - p->PV_z ; 
		     double timing = p->ph_t1 ;
		     double caloZ = p->ph_calo_z1 ;

                     if( config["anaflag"] == 2 ){
		       // In the case of two photon, resolve the ambiguity
  		       if( fabs(p->ph_eta1) <= 1.37 && fabs(p->ph_eta2) <= 1.37  )
			 { 
			   // if both are central, pick the photon with larger timing value
			 dZsigned = p->ph_t1 > p->ph_t2 ?  ( p->ph_calo_z1 - p->PV_z) :  ( p->ph_calo_z2 - p->PV_z) ;
			 timing =  p->ph_t1 > p->ph_t2 ? p->ph_t1 : p->ph_t2 ;
			 caloZ =  p->ph_t1 > p->ph_t2 ? p->ph_calo_z1 : p->ph_calo_z2 ;
			 }
		       else if ( fabs(p->ph_eta1) > 1.37 && fabs(p->ph_eta2) < 1.37  )
			 {
			   // if subleading is central while leading is endcap, then use subleading
			 dZsigned  = ( p->ph_calo_z2 - p->PV_z) ;
			 timing = p->ph_t2 ;
			 caloZ = p->ph_calo_z2 ;
			 }
		     }

		     double dZ = fabs(dZsigned);

                     /* END Determining photon used for the analysis */

		     /* Plotting block */
                     for( int k = 0 ; k < 6 ; k ++ )
                       { // loop over 6 pointint categories

			 if( dZ  >= z[k] &&  dZ < z[k+1] )
			   { 

                             if( SR )
			       { 
				 h_Z_SR -> Fill( k+0.5, wt ) ;
			       }

                             if( CR )
                               {
				 h_Z_CR -> Fill( k+0.5, wt ) ;

                               }

			     if( isolation )
			       {

				 h_met -> Fill( p -> m_met , wt );
				 h_z -> Fill( dZ , wt ) ;
				 h_t -> Fill( timing, wt ) ;
				 h1_pt -> Fill( p->ph_pt1, wt );
				 h1_eta -> Fill( p->ph_eta1, wt );
				 h1_t -> Fill( p->ph_t1, wt );
				 h1_z -> Fill( p->ph_z1 - p->PV_z , wt );
				 h2_pt -> Fill( p->ph_pt2, wt );
				 h2_eta -> Fill( p->ph_eta2, wt );
				 h2_t -> Fill( p->ph_t2, wt );
				 h2_z -> Fill( p->ph_z2 - p-> PV_z, wt );
			       }
			   }

                       }
                     /* END Plotting block */



		     if( CR ){

		       for( int k = 0 ; k < 6 ; k ++ )
			 {
			 for( int l = 0 ; l < 6 ; l ++)
			   {
			       if( dZ  >= z[k] &&  dZ < z[k+1] && timing >= t[l] && timing < t[l+1])
				 { 
				   if( isData ){
				     h_yield -> Fill( l, k, wt*(h_Z_SR->GetBinContent(k+1) / h_Z_CR -> GetBinContent(k+1) ) );
				     h_yield_raw -> Fill( l, k, wt );
				   }
				   else 
				     h_yield -> Fill( l, k, wt );
				 }
			   }
		       }

		     }




		   }


		 // Histograms need to be written into a TFile for further processing
		 char filename[60] ;
		 sprintf(filename,"output_%d.root", DSID);
                 TFile f(filename,"recreate");
		 h1_pt -> Write();
		 h1_eta -> Write();
		 h1_z -> Write();
		 h1_t -> Write();

		 h2_pt -> Write();
		 h2_eta -> Write();
		 h2_z -> Write();
		 h2_t -> Write();

		 h_met -> Write();
		 h_t -> Write();
		 h_z -> Write();

		 h_CF -> Write();
		 h_N->Write();
		 h_Z_CR ->Write();
		 h_Z_SR ->Write();

		 h_yield->Write();
		 h_yield_raw->Write();
                 f.Close();


		 return 0 ;
}







