void multiple_comparisons() {
  TFile *fsig = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/new_signal/diphoton/combined.root");
  TFile *fdata = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_HIGG1D1/output.root");
  
  TEfficiency *sig = (TEfficiency*)fsig->Get("h_subleading_ZDCA_loose_eff");
  sig->SetNameTitle("sig","sig");
  TEfficiency *data50 = (TEfficiency*)fdata->Get("h_subleading_ZDCA_loose_eff_pt50");
  data50->SetNameTitle("data50","data50");
  TEfficiency *data100 = (TEfficiency*)fdata->Get("h_subleading_ZDCA_loose_eff_pt100");
  data100->SetNameTitle("data100","data100");
  TEfficiency *data200 = (TEfficiency*)fdata->Get("h_subleading_ZDCA_loose_eff_pt200");
  data200->SetNameTitle("data200","data200");

  double nbins = sig->GetCopyTotalHisto()->GetNbinsX();
  double xmin = sig->GetCopyTotalHisto()->GetXaxis()->GetXmin();
  double xmax = sig->GetCopyTotalHisto()->GetXaxis()->GetXmax();
  TH1F *sig_effs = new TH1F("sig_effs","sig_effs",nbins,xmin,xmax);
  TH1F *data50_effs = new TH1F("data50_effs","data50_effs",nbins,xmin,xmax);
  TH1F *data100_effs = new TH1F("data100_effs","data100_effs",nbins,xmin,xmax);
  TH1F *data200_effs = new TH1F("data200_effs","data200_effs",nbins,xmin,xmax);
  sig_effs->Sumw2();
  data50_effs->Sumw2();
  data100_effs->Sumw2();
  data200_effs->Sumw2();

  data50_effs->SetLineColor(2);
  data50_effs->SetMarkerColor(2);
  data100_effs->SetLineColor(3);
  data100_effs->SetMarkerColor(3);
  data200_effs->SetLineColor(4);
  data200_effs->SetMarkerColor(4);
  
  for (int i = 1; i <= nbins; i++) {
    sig_effs->SetBinContent(i,sig->GetEfficiency(i));
    data50_effs->SetBinContent(i,data50->GetEfficiency(i));
    data100_effs->SetBinContent(i,data100->GetEfficiency(i));
    data200_effs->SetBinContent(i,data200->GetEfficiency(i));
  }
  
  TH1F *ratio50 = (TH1F*)data50_effs->Clone();
  TH1F *ratio100 = (TH1F*)data100_effs->Clone();
  TH1F *ratio200 = (TH1F*)data200_effs->Clone();
  ratio50->Divide(sig_effs);
  ratio100->Divide(sig_effs);
  ratio200->Divide(sig_effs);
  
  ratio50->GetYaxis()->SetRangeUser(0.5,1.5);
  ratio50->GetYaxis()->SetTitle("Data/MC");
  ratio50->GetXaxis()->SetTitle("|Z_{DCA}| [mm]");
  ratio50->GetYaxis()->SetNdivisions(8);
  ratio50->GetXaxis()->SetLabelOffset(0.015);
  ratio50->GetXaxis()->SetTitleSize(0.135);
  ratio50->GetXaxis()->SetTitleOffset(1.15);
  ratio50->GetXaxis()->SetLabelSize(0.12);
  ratio50->GetYaxis()->SetLabelSize(0.1);
  ratio50->GetYaxis()->SetLabelOffset(0.01);
  ratio50->GetYaxis()->SetTitleSize(0.15);
  ratio50->GetYaxis()->SetTitleOffset(0.30);

  sig_effs->GetYaxis()->SetTitle("Efficiency");
  //sig_effs->GetYaxis()->SetTitleSize(0.07);
  //sig_effs->GetYaxis()->SetTitleOffset(0.8);
  sig_effs->GetYaxis()->SetRangeUser(0,1.5);

  TCanvas *c1 = new TCanvas();
  c1->Divide(1,2);
  c1->SetBottomMargin(0.2);
  c1->cd(1);
  c1->GetPad(1)->SetPad(0.,0.25,1.,1);
  sig_effs->Draw("histE");
  data50_effs->Draw("histEsame");
  data100_effs->Draw("histEsame");
  data200_effs->Draw("histEsame");
  TString message = "Diphoton, Events Passing HLT_g140_loose";
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.05);
  l.DrawLatex(0.2,0.9,message);
  message = "Sub-leading photon loose ID efficiency";
  l.DrawLatex(0.2,0.85,message);
  TLegend leg(0.65,0.7,0.85,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(sig_effs,"Combined Signal","l");
  leg.AddEntry(data50_effs,"2016 Data, p_{T} > 50 GeV","l");
  leg.AddEntry(data100_effs,"2016 Data, p_{T} > 100 GeV","l");
  leg.AddEntry(data200_effs,"2016 Data, p_{T} > 200 GeV","l");
  leg.Draw();
  c1->cd(2);
  c1->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c1->GetPad(2)->SetBottomMargin(0.3);
  c1->GetPad(2)->SetGridy(1);
  ratio50->Draw("histE");
  ratio100->Draw("histEsame");
  ratio200->Draw("histEsame");
  TString fname = "signal_vs_data_subleading_loose_eff_vary_ptcut";
  c1->SaveAs(fname+".png");
  c1->SaveAs(fname+".pdf");
  c1->SaveAs(fname+".C");
}
