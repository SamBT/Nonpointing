void plot_diphoton_variable(TString variable, TString axis_label, int rebin, double xmin, double xmax, double ratio_min, double ratio_max) {
  TFile *f15 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data15_HIGG1D1/output.root");
  TFile *f16 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_HIGG1D1/output.root");

  TH2F *h15 = (TH2F*)f15->Get("h_"+variable);
  h15->SetNameTitle("h15","h15");
  TH2F *h16 = (TH2F*)f16->Get("h_"+variable);
  h16->SetNameTitle("h16","h16");

  h15->Sumw2();
  h16->Sumw2();

  h15->Rebin(rebin);
  h16->Rebin(rebin);

  h15->Scale(1/h15->Integral());
  h16->Scale(1/h16->Integral());
  
  TH1D *ratio = (TH1D*)h15->Clone();
  ratio->Divide(h16);

  ratio->GetYaxis()->SetRangeUser(ratio_min,ratio_max);
  ratio->GetYaxis()->SetTitle("2015/2016");
  ratio->GetXaxis()->SetTitle(axis_label);
  ratio->GetYaxis()->SetNdivisions(8);
  ratio->GetXaxis()->SetLabelOffset(0.015);
  ratio->GetXaxis()->SetTitleSize(0.135);
  ratio->GetXaxis()->SetTitleOffset(1.15);
  ratio->GetXaxis()->SetLabelSize(0.12);
  ratio->GetYaxis()->SetLabelSize(0.1);
  ratio->GetYaxis()->SetLabelOffset(0.01);
  ratio->GetYaxis()->SetTitleSize(0.15);
  ratio->GetYaxis()->SetTitleOffset(0.30);
  ratio->GetXaxis()->SetRangeUser(xmin,xmax);

  h16->GetYaxis()->SetTitle("a.u.");

  h16->SetLineColor(2);
  h16->SetMarkerColor(2);

  TCanvas *c1 = new TCanvas();
  c1->Divide(1,2);
  c1->SetBottomMargin(0.2);
  c1->cd(1);
  c1->GetPad(1)->SetLogy();
  c1->GetPad(1)->SetPad(0.,0.25,1.,1);
  h16->GetXaxis()->SetRangeUser(xmin,xmax);
  h16->GetYaxis()->SetRangeUser(0.1*h16->GetBinContent(h16->FindLastBinAbove(0)),100*h16->GetMaximum());
  h16->Draw("histEsame");
  h15->Draw("histEsame");
  TString message = "Diphoton, p_{T} > 50 GeV, Barrel";
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.05);
  l.DrawLatex(0.2,0.85,message);
  TLegend leg(0.75,0.7,0.9,0.9);
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
  TString fname = "data_diphoton_" + variable + "_2015_16_comparison_SBT";
  c1->SaveAs(fname+".png");
  c1->SaveAs(fname+".pdf");
  c1->SaveAs(fname+".eps");
  c1->SaveAs(fname+".C");

}
  
  
