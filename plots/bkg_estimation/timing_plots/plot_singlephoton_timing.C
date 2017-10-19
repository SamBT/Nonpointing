void plot_singlephoton_timing(int zbin, TString zdca_bin, int zlow, int zhigh) {
  TFile *f15 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data15_EXOT6/output.root");
  TFile *f16 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_EXOT6/output.root");

  TH2F *y15 = (TH2F*)f15->Get("h_timing_ZDCA_est_SR_yield");
  y15->SetNameTitle("y15","y15");
  TH2F *y16 = (TH2F*)f16->Get("h_timing_ZDCA_est_SR_yield");
  y16->SetNameTitle("y16","y16");

  y15->Sumw2();
  y16->Sumw2();
  
  TH1D *h15 = y15->ProjectionX("h15",zbin,zbin);
  h15->SetNameTitle("h15","h15");
  TH1D *h16 = y16->ProjectionX("h16",zbin,zbin);
  h16->SetNameTitle("h16","h16");
  
  h15->Sumw2();
  h16->Sumw2();

  h15->Scale(32.8846/3.2);

  TH1D *ratio = (TH1D*)h15->Clone();
  ratio->Divide(h16);

  ratio->GetYaxis()->SetRangeUser(0,2);
  ratio->GetYaxis()->SetTitle("2015/2016");
  ratio->GetYaxis()->SetNdivisions(8);
  ratio->GetXaxis()->SetLabelOffset(0.015);
  ratio->GetXaxis()->SetTitleSize(0.125);
  ratio->GetXaxis()->SetTitleOffset(1.15);
  ratio->GetYaxis()->SetLabelSize(0.1);
  ratio->GetYaxis()->SetLabelOffset(0.01);
  ratio->GetYaxis()->SetTitleSize(0.12);
  ratio->GetYaxis()->SetTitleOffset(0.25);

  ratio->GetXaxis()->SetBinLabel(1,"-4 - 0.5");
  ratio->GetXaxis()->SetBinLabel(2,"0.5 - 1.1");
  ratio->GetXaxis()->SetBinLabel(3,"1.1 - 1.3");
  ratio->GetXaxis()->SetBinLabel(4,"1.3 - 1.5");
  ratio->GetXaxis()->SetBinLabel(5,"1.5 - 1.8");
  ratio->GetXaxis()->SetBinLabel(6,"1.8 - ");
  ratio->GetXaxis()->SetTitle("t_{#gamma} [ns]");
  ratio->GetXaxis()->SetLabelSize(0.15);

  h16->GetXaxis()->SetBinLabel(1,"-4 - 0.5");
  h16->GetXaxis()->SetBinLabel(2,"0.5 - 1.1");
  h16->GetXaxis()->SetBinLabel(3,"1.1 - 1.3");
  h16->GetXaxis()->SetBinLabel(4,"1.3 - 1.5");
  h16->GetXaxis()->SetBinLabel(5,"1.5 - 1.8");
  h16->GetXaxis()->SetBinLabel(6,"1.8 - ");
  h16->GetYaxis()->SetTitle("Events");
  h16->GetXaxis()->SetLabelSize(0.05);

  h16->SetLineColor(2);
  h16->SetMarkerColor(2);

  TCanvas *c1 = new TCanvas();
  c1->Divide(1,2);
  c1->SetBottomMargin(0.2);
  c1->cd(1);
  c1->GetPad(1)->SetLogy();
  c1->GetPad(1)->SetPad(0.,0.25,1.,1);
  h16->GetYaxis()->SetRangeUser(0.1,100*h16->GetMaximum());
  h16->Draw("histE");
  h15->Draw("histEsame");
  TString message = "Data, Singlephoton, Projected Timing Distribution in SR";
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.9,message);
  message = "2015 Data Scaled to 32.8846 fb^{-1}";
  l.DrawLatex(0.2,0.85,message);
  l.DrawLatex(0.2,0.8,zdca_bin);
  TLegend leg(0.6,0.7,0.8,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(h15,"2015 Data","l");
  leg.AddEntry(h16,"2016 Data","l");
  leg.Draw();
  c1->cd(2);
  c1->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c1->GetPad(2)->SetBottomMargin(0.3);
  c1->GetPad(2)->SetGridy(1);
  ratio->Draw("histE");
  TString fname;
  fname.Form("data_projected_singlephoton_SR_timing_z%i_%i_SBT",zlow,zhigh);
  c1->SaveAs(fname+".png");
  c1->SaveAs(fname+".pdf");
  c1->SaveAs(fname+".eps");
  c1->SaveAs(fname+".C");

}
  
  
