void determine_truth_reco_scale_factors() {
  vector<int> dsids = {403280,403281,403282,403283,403284,403285,403286};

  ofstream output_s("output_singlephoton.txt");
  ofstream output_d("output_diphoton.txt");

  for (int i = 0; i < dsids.size(); i++) {
    TString fname;
    int dsid = dsids[i];
    fname.Form("hist_%i.root",dsid);
    
    TFile *f_reco = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/truth_to_reco_estimation/cutflow_and_acceptance/reco_signal/"+fname);
    TFile *f_truth = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/truth_to_reco_estimation/cutflow_and_acceptance/truth_level_herwig/"+fname);
    
    TString hname_s = "hs9_acc";
    TString hname_d = "hd6_acc";
    
    double dsid_test, mg, mx, tau;
    ifstream info("/global/homes/s/sambt/workarea/nonpointing/dsid_mg_mx_tau.txt");
    while (!info.eof()) {
      info >> dsid_test >> mg >> mx >> tau;
      if (dsid_test == dsid) break;
    }

    int mgbin = (mg-800)/100 + 1;
    int mxbin = (mx - 100)/100 + 1;

    TH2F *hs_r = (TH2F*)f_reco->Get(hname_s);
    TH2F *hs_t = (TH2F*)f_truth->Get(hname_s);

    hs_r->Divide(hs_t);
    output_s << dsid << "&" << mg << "&" << mx << "&" << tau << "&" << hs_r->GetBinContent(mgbin, mxbin) << "\n";
    
    TH2F *hd_r = (TH2F*)f_reco->Get(hname_d);
    TH2F *hd_t = (TH2F*)f_truth->Get(hname_d);

    hd_r->Divide(hd_t);
    output_d << dsid << "&" << mg << "&" << mx << "&" << tau << "&" << hd_r->GetBinContent(mgbin,mxbin) << "\n";
  }
  output_s.close();
  output_d.close();
}
    
    
  
