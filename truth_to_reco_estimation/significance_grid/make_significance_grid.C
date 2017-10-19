void make_significance_grid(TString timing, double tau) {
  TFile *bkg_pred_di = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_HIGG1D1/output.root");
  TFile *bkg_pred_single = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_EXOT6/output.root");

  TH2F *bkg_di = (TH2F*)bkg_pred_di->Get("h_timing_ZDCA_est_SR_yield");
  TH2F *bkg_single = (TH2F*)bkg_pred_single->Get("h_timing_ZDCA_est_SR_yield");

  int mg, mx, dsid;
  TString sig_file;
  double scale_di, scale_single, mgtest, mxtest;

  TH2F *significance_grid_di = new TH2F("significance_grid_di","significance_grid_di",13,800,2100,20,100,2100);
  TH2F *significance_grid_single = new TH2F("significance_grid_single","significance_grid_single",13,800,2100,20,100,2100);

  TH2F *significance_grid_total = new TH2F("significance_grid_total","significance_grid_total",13,800,2100,20,100,2100);

  for (int i = 8; i <= 20; i++) {
    for (int j = 1; j < i; j++) {
      mg = 100*i;
      mx = 100*j;
      int mgbin = (mg - 800)/100 + 1;
      int mxbin = (mx - 100)/100 + 1;
      if (mg >= 1000) dsid = 100000*tau+10*(mg-1000)+(mx/100);
      if (mg < 1000) dsid = 100000*tau+mg+(mx/100);
      sig_file.Form("output_%i.root",dsid);
      TFile *f = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/combined/cutflows/"+timing+"/"+sig_file);
      TH2F *sig_di = (TH2F*)f->Get("h_timing_ZDCA_SR_di");
      TH2F *sig_single = (TH2F*)f->Get("h_timing_ZDCA_SR_single");
      
      ifstream scaling_di("/global/homes/s/sambt/workarea/nonpointing/truth_to_reco_estimation/truth_reco_scale_calc/output_diphoton_"+timing+"_interpolated.txt");
      while (!scaling_di.eof()) {
	scaling_di >> mgtest >> mxtest >> scale_di;
	if (mgtest == mg && mxtest == mx) break;
      }

      ifstream scaling_single("/global/homes/s/sambt/workarea/nonpointing/truth_to_reco_estimation/truth_reco_scale_calc/output_singlephoton_"+timing+"_interpolated.txt");
      while (!scaling_single.eof()) {
	scaling_single >> mgtest >> mxtest >> scale_single;
	if (mgtest == mg && mxtest == mx) break;
      }

      sig_di->Scale(scale_di);
      sig_single->Scale(scale_single);

      double significance_di, significance_single, combined_significance_di, combined_significance_single, combined_significance_total;
      combined_significance_di = 0; combined_significance_single = 0;
      double di_signal, di_data, single_signal, single_data;

      for (int k = 1; k <= sig_di->GetNbinsX(); k++) {
	for (int l = 1; l <= sig_di->GetNbinsY(); l++) {
	  di_signal = sig_di->GetBinContent(k,l);
	  di_data = bkg_di->GetBinContent(k,l);
	  single_signal = sig_single->GetBinContent(k,l);
	  single_data = bkg_single->GetBinContent(k,l);
	  
	  if (di_data > 0) significance_di = sqrt(2*((di_signal+di_data)*log(1+di_signal/di_data)-di_signal));
	  if (single_data > 0) significance_single = sqrt(2*((single_signal+single_data)*log(1+single_signal/single_data)-single_signal));

	  if (di_data == 0) significance_di = 0;
	  if (single_data == 0) significance_single = 0;

	  combined_significance_di += pow(significance_di,2);
	  combined_significance_single += pow(significance_single,2);

	}
      }
      
      combined_significance_di = sqrt(combined_significance_di);
      combined_significance_single = sqrt(combined_significance_single);
      combined_significance_total = sqrt( pow(combined_significance_di,2) + pow(combined_significance_single,2) );

      significance_grid_di->SetBinContent(mgbin,mxbin,combined_significance_di);
      significance_grid_single->SetBinContent(mgbin,mxbin,combined_significance_single);
      significance_grid_total->SetBinContent(mgbin,mxbin,combined_significance_total);
    }
  }
  
  significance_grid_di->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  significance_grid_di->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  significance_grid_di->SetMarkerSize(1.2);
  significance_grid_di->GetXaxis()->SetRangeUser(750,2150);
  significance_grid_di->GetYaxis()->SetRangeUser(50,2100);

  significance_grid_single->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  significance_grid_single->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  significance_grid_single->SetMarkerSize(1.2);
  significance_grid_single->GetXaxis()->SetRangeUser(750,2150);
  significance_grid_single->GetYaxis()->SetRangeUser(50,2100);

  significance_grid_total->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  significance_grid_total->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  significance_grid_total->SetMarkerSize(1.2);
  significance_grid_total->GetXaxis()->SetRangeUser(750,2150);
  significance_grid_total->GetYaxis()->SetRangeUser(50,2100);

  TCanvas *c1 = new TCanvas();
  significance_grid_di->Draw("text45");
  TString message = "Diphoton, Estimated Significance in SR";
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.9,message);
  message = "Signal Scaled to 32.8846 fb^{-1}";
  l.DrawLatex(0.2,0.85,message);
  message = "#tau = " + timing;
  l.DrawLatex(0.2,0.8,message);
  c1->SaveAs("diphoton_expected_SR_significance_truth_to_reco_6ns_SBT.png");
  c1->SaveAs("diphoton_expected_SR_significance_truth_to_reco_6ns_SBT.pdf");
  c1->SaveAs("diphoton_expected_SR_significance_truth_to_reco_6ns_SBT.eps");
  c1->SaveAs("diphoton_expected_SR_significance_truth_to_reco_6ns_SBT.C");

  TCanvas *c2 = new TCanvas();
  significance_grid_single->Draw("text45");
  message = "Singlephoton, Estimated Significance in SR";
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.9,message);
  message = "Signal Scaled to 32.8846 fb^{-1}";
  l.DrawLatex(0.2,0.85,message);
  message = "#tau = " +timing;
  l.DrawLatex(0.2,0.8,message);
  c2->SaveAs("singlephoton_expected_SR_significance_truth_to_reco_6ns_SBT.png");
  c2->SaveAs("singlephoton_expected_SR_significance_truth_to_reco_6ns_SBT.pdf");
  c2->SaveAs("singlephoton_expected_SR_significance_truth_to_reco_6ns_SBT.eps");
  c2->SaveAs("singlephoton_expected_SR_significance_truth_to_reco_6ns_SBT.C");

  TCanvas *c3 = new TCanvas();
  significance_grid_total->Draw("text45");
  message = "Total Estimated Significance in SR";
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.9,message);
  message = "Signal Scaled to 32.8846 fb^{-1}";
  l.DrawLatex(0.2,0.85,message);
  message = "#tau = " +timing;
  l.DrawLatex(0.2,0.8,message);
  c3->SaveAs("total_expected_SR_significance_truth_to_reco_6ns_SBT.png");
  c3->SaveAs("total_expected_SR_significance_truth_to_reco_6ns_SBT.pdf");
  c3->SaveAs("total_expected_SR_significance_truth_to_reco_6ns_SBT.eps");
  c3->SaveAs("total_expected_SR_significance_truth_to_reco_6ns_SBT.C");
  

}
    
