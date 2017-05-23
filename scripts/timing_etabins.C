void timing_plots(TString file, TString hname1, TString hname2, TString leg1, TString leg2, double etalow = 0, double etahigh = 2.37, int rebin = 1) {
  TFile *f = TFile::Open(file);

  TH2F *ha = (TH2F*)f->Get(hname1);
  TH2F *hb = (TH2F*)f->Get(hname2);

  int binlow = (int)(etalow*100 + 1);
  int binhigh = (int)(etahigh*100 + 1);

  TH1F *h1 = (TH1F*)ha->ProjectionX("h1",binlow,binhigh);
  TH1F *h2 = (TH1F*)hb->ProjectionX("h2",binlow,binhigh);

  h1->Rebin(rebin);
  h2->Rebin(rebin);

  h1->GetXaxis()->SetRangeUser(-6,6);
  h2->GetXaxis()->SetRangeUser(-6,6);

  h1->Sumw2();
  h2->Sumw2();
  
  h1->Scale(1/h1->Integral());
  h2->Scale(1/h2->Integral());

  TCanvas * c =new TCanvas();
  c->Divide(1,2);
  c->SetBottomMargin(0.2);
  c->cd(1);
  c->GetPad(1)->SetLogy();
  c->GetPad(1)->SetPad(0.,0.25,1.,1);

  h1->GetYaxis()->SetTitle("a.u.");
  h1->GetYaxis()->SetLabelSize(0.07);
  h1->GetYaxis()->SetLabelOffset(0.01);
  h1->GetYaxis()->SetTitleSize(0.08);
  h1->GetYaxis()->SetTitleOffset(0.81);

  h2->SetMarkerSize(1);
  h2->SetMarkerStyle(24);

  h1->Draw("axis");
  h1->Draw("histsame");
  h2->Draw("Esame");

  TLegend leg(0.65,0.80,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.05);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,leg1,"L");
  leg.AddEntry(h2,leg2,"PL");
  leg.Draw();

  char message[100];
  if (etalow == 0) {
    sprintf(message,"0 < |#eta| < %3.2f",etahigh);
  }
  else {
    sprintf(message,"%3.2f < |#eta| < %3.2f",etalow,etahigh);
  }
  
  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.65,0.75,message);

  c->cd(2);
  c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c->GetPad(2)->SetBottomMargin(0.3);
  c->GetPad(2)->SetGridy(1);

  TH1F *h1_clone = (TH1F*)h1->Clone();

  h1_clone->Divide(h2);
  h1_clone->GetXaxis()->SetTitle("t [ns]");
  h1_clone->GetYaxis()->SetRangeUser(0.,2.0);
  h1_clone->GetYaxis()->SetTitle("Tight/Loose");
  h1_clone->GetYaxis()->SetNdivisions(8);

  h1_clone->GetXaxis()->SetLabelSize(0.15);
  h1_clone->GetXaxis()->SetLabelOffset(0.015);
  h1_clone->GetXaxis()->SetTitleSize(0.125);
  h1_clone->GetXaxis()->SetTitleOffset(1.15);

  h1_clone->GetYaxis()->SetLabelSize(0.1);
  h1_clone->GetYaxis()->SetLabelOffset(0.01);
  h1_clone->GetYaxis()->SetTitleSize(0.18);
  h1_clone->GetYaxis()->SetTitleOffset(0.35);

  h1_clone->Draw("E0");

  char fname[100];
  if (etalow == 0) {
    sprintf(fname, "timing_eta_0_%3.2f",etahigh);
  }
  else {
    sprintf(fname, "timing_eta_%3.2f_%3.2f",etalow,etahigh);
  }
  
  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(fname+feps);
  c->SaveAs(fname+fpng);
  c->SaveAs(fname+fpdf);
}

void timing_etabins() {
  timing_plots("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose",0,0.8,1);
  timing_plots("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose",0.8,1.37,1);
  timing_plots("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose",1.52,2,1);
  timing_plots("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose",2,2.37,1);
}
