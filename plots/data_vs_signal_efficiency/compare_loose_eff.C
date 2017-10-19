void compare_loose_eff() {
  TFile *fsig = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/new_signal/diphoton/combined.root");
  TFile *fdata = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_HIGG1D1/output.root");
  
  TEfficiency *sig = (TEfficiency*)fsig->Get("h_subleading_ZDCA_loose_eff");
  sig->SetNameTitle("sig","sig");
  TEfficiency *data = (TEfficiency*)fdata->Get("h_subleading_ZDCA_loose_eff");
  data->SetNameTitle("data","data");

  TH1F *sig_effs = (TH1F*)sig->GetCopyTotalHisto();
  TH1F *data_effs = (TH1F*)data->GetCopyTotalHisto();
  sig_effs->Reset();
  data_effs->Reset();
  sig_effs->Sumw2();
  data_effs->Sumw2();

  data_effs->SetLineColor(1);
  data_effs->SetMarkerColor(1);
  sig_effs->SetLineColor(2);
  sig_effs->SetMarkerColor(2);
  data_effs->SetLineWidth(2);
  sig_effs->SetLineWidth(2);
  
  for (int i = 1; i <= sig_effs->GetNbinsX(); i++) {
    sig_effs->SetBinContent(i,sig->GetEfficiency(i));
    data_effs->SetBinContent(i,data->GetEfficiency(i));
  }
  
  TH1F *ratio = (TH1F*)data_effs->Clone();
  ratio->Divide(sig_effs);
  ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  ratio->GetYaxis()->SetTitle("Data/MC");
  ratio->GetXaxis()->SetTitle("|Z_{DCA}| [mm]");
  ratio->GetYaxis()->SetNdivisions(8);
  ratio->GetXaxis()->SetLabelOffset(0.015);
  ratio->GetXaxis()->SetTitleSize(0.135);
  ratio->GetXaxis()->SetTitleOffset(1.15);
  ratio->GetXaxis()->SetLabelSize(0.12);
  ratio->GetYaxis()->SetLabelSize(0.1);
  ratio->GetYaxis()->SetLabelOffset(0.01);
  ratio->GetYaxis()->SetTitleSize(0.15);
  ratio->GetYaxis()->SetTitleOffset(0.30);

  sig_effs->GetYaxis()->SetTitle("Efficiency");
  sig_effs->GetYaxis()->SetTitleSize(0.07);
  sig_effs->GetYaxis()->SetTitleOffset(0.8);
  sig_effs->GetYaxis()->SetRangeUser(0,1.1);

  TCanvas *c1 = new TCanvas();
  c1->Divide(1,2);
  c1->SetBottomMargin(0.2);
  c1->cd(1);
  c1->GetPad(1)->SetPad(0.,0.25,1.,1);
  sig_effs->Draw("histE");
  data_effs->Draw("histEsame");
  TString message = "Diphoton, Events Passing HLT_g140_loose";
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.05);
  l.DrawLatex(0.2,0.9,message);
  message = "Sub-leading photon loose ID efficiency";
  l.DrawLatex(0.2,0.85,message);
  TLegend leg(0.75,0.7,0.9,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(sig_effs,"Combined Signal","l");
  leg.AddEntry(data_effs,"2016 Data","l");
  leg.Draw();
  c1->cd(2);
  c1->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c1->GetPad(2)->SetBottomMargin(0.3);
  c1->GetPad(2)->SetGridy(1);
  ratio->Draw("histE");
  TString fname = "signal_vs_data_subleading_loose_eff";
  c1->SaveAs(fname+".png");
  c1->SaveAs(fname+".pdf");
  c1->SaveAs(fname+".C");
}
