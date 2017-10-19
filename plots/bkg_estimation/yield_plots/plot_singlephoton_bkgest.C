void plot_singlephoton_bkgest() {
  TFile *f15 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data15_EXOT6/output.root");
  TFile *f16 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_EXOT6/output.root");
  
  TH2F *y15 = (TH2F*)f15->Get("h_timing_ZDCA_est_SR_yield");
  TH2F *y16 = (TH2F*)f16->Get("h_timing_ZDCA_est_SR_yield");

  y15->GetXaxis()->SetBinLabel(1,"-4 - 0.5");
  y15->GetXaxis()->SetBinLabel(2,"0.5 - 1.1");
  y15->GetXaxis()->SetBinLabel(3,"1.1 - 1.3");
  y15->GetXaxis()->SetBinLabel(4,"1.3 - 1.5");
  y15->GetXaxis()->SetBinLabel(5,"1.5 - 1.8");
  y15->GetXaxis()->SetBinLabel(6,"1.8 - ");
  y15->GetYaxis()->SetBinLabel(1,"0 - 40");
  y15->GetYaxis()->SetBinLabel(2,"40 - 80");
  y15->GetYaxis()->SetBinLabel(3,"80 - 120");
  y15->GetYaxis()->SetBinLabel(4,"120 - 160");
  y15->GetYaxis()->SetBinLabel(5,"160 - 200");
  y15->GetYaxis()->SetBinLabel(6,"200- ");
  y15->GetXaxis()->SetTitle("t_{#gamma} [ns]");
  y15->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
  y15->GetYaxis()->SetLabelSize(0.05);
  y15->GetXaxis()->SetLabelSize(0.05);
  y15->SetMarkerSize(1.5);
  y15->GetYaxis()->SetRangeUser(0,7);

  y16->GetXaxis()->SetBinLabel(1,"-4 - 0.5");
  y16->GetXaxis()->SetBinLabel(2,"0.5 - 1.1");
  y16->GetXaxis()->SetBinLabel(3,"1.1 - 1.3");
  y16->GetXaxis()->SetBinLabel(4,"1.3 - 1.5");
  y16->GetXaxis()->SetBinLabel(5,"1.5 - 1.8");
  y16->GetXaxis()->SetBinLabel(6,"1.8 - ");
  y16->GetYaxis()->SetBinLabel(1,"0 - 40");
  y16->GetYaxis()->SetBinLabel(2,"40 - 80");
  y16->GetYaxis()->SetBinLabel(3,"80 - 120");
  y16->GetYaxis()->SetBinLabel(4,"120 - 160");
  y16->GetYaxis()->SetBinLabel(5,"160 - 200");
  y16->GetYaxis()->SetBinLabel(6,"200- ");
  y16->GetXaxis()->SetTitle("t_{#gamma} [ns]");
  y16->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
  y16->GetYaxis()->SetLabelSize(0.05);
  y16->GetXaxis()->SetLabelSize(0.05);
  y16->SetMarkerSize(1.5);
  y16->GetYaxis()->SetRangeUser(0,7);

  y15->Scale(32.8846/3.2);

  TCanvas *c1 = new TCanvas();
  y15->Draw("text");
  TString message = "Data 2015, Singlephoton, Projected Yield in SR, Scaled to 32.8846 fb^{-1}";
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.9,message);
  c1->SaveAs("data15_projected_singlephoton_SR_yield_SBT.png");
  c1->SaveAs("data15_projected_singlephoton_SR_yield_SBT.pdf");
  c1->SaveAs("data15_projected_singlephoton_SR_yield_SBT.eps");
  c1->SaveAs("data15_projected_singlephoton_SR_yield_SBT.C");

  TCanvas *c2 = new TCanvas();
  y16->Draw("text");
  message = "Data 2016, Singlephoton, Projected Yield in SR";
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.9,message);
  c2->SaveAs("data16_projected_singlephoton_SR_yield_SBT.png");
  c2->SaveAs("data16_projected_singlephoton_SR_yield_SBT.pdf");
  c2->SaveAs("data16_projected_singlephoton_SR_yield_SBT.eps");
  c2->SaveAs("data16_projected_singlephoton_SR_yield_SBT.C");

}
  
  
