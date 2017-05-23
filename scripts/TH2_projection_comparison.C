void plot(TString file, TString hname1, TString hname2, TString leg1, TString leg2, TString message, TString xvar, TString yvar, TString fnamexvar,TString fnameyvar, double xmin, double xmax, double ymin = 0, double ymax = 2.37, double binscale = 100, int rebin = 1) {
  TFile *f = TFile::Open(file);

  TH2F *ha = (TH2F*)f->Get(hname1);
  TH2F *hb = (TH2F*)f->Get(hname2);

  int binlow = (int)(ymin*binscale + 1);
  int binhigh = (int)(ymax*binscale + 1);

  TH1F *h1 = (TH1F*)ha->ProjectionX("h1",binlow,binhigh);
  TH1F *h2 = (TH1F*)hb->ProjectionX("h2",binlow,binhigh);

  h1->Rebin(rebin);
  h2->Rebin(rebin);

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

  h1->GetYaxis()->SetRangeUser(h1->GetBinContent( h1->FindLastBinAbove(0))*0.5,h1->GetMaximum()*10);
  h1->GetYaxis()->SetTitle("a.u.");
  h1->GetYaxis()->SetLabelSize(0.07);
  h1->GetYaxis()->SetLabelOffset(0.01);
  h1->GetYaxis()->SetTitleSize(0.08);
  h1->GetYaxis()->SetTitleOffset(0.81);

  h2->SetMarkerSize(1);
  h2->SetMarkerStyle(24);

  h1->GetXaxis()->SetRangeUser(xmin,xmax);
  h2->GetXaxis()->SetRangeUser(xmin,xmax);

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

  char bounds[100];
  if (ymin == ymax) {
    if (ymin == 0) {
      sprintf(bounds,yvar+" = 0");
    }
    else {
      sprintf(bounds,yvar+" = %3.2f",ymin);
    }
  }
  else if (ymin == 0) {
    sprintf(bounds,"0 < "+yvar+" < %3.2f",ymax);
  }
  else {
    sprintf(bounds,"%3.2f < "+yvar+" < %3.2f",ymin,ymax);
  }
  
  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.65,0.75,bounds);

  TLatex l1;
  l1.SetNDC();
  l1.DrawLatex(0.65,0.7,message);

  c->cd(2);
  c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c->GetPad(2)->SetBottomMargin(0.3);
  c->GetPad(2)->SetGridy(1);

  TH1F *h1_clone = (TH1F*)h1->Clone();
  h1_clone->GetXaxis()->SetRangeUser(xmin,xmax);

  h1_clone->Divide(h2);
  h1_clone->GetXaxis()->SetTitle(xvar);
  h1_clone->GetYaxis()->SetRangeUser(0.,2.0);
  h1_clone->GetYaxis()->SetTitle(leg1+"/"+leg2);
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
  if (ymin == 0) {
    sprintf(fname, "plot_"+fnamexvar+"_"+fnameyvar+"_0_%3.2f",ymax);
  }
  else {
    sprintf(fname, "plot_"+fnamexvar+"_"+fnameyvar+"_%3.2f_%3.2f",ymin,ymax);
  }
  
  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(fname+feps);
  c->SaveAs(fname+fpng);
  c->SaveAs(fname+fpdf);
}

void TH2_projection_comparison() {
  //plot("output.root","h_tight_t_gain","h_loose_t_gain","Tight","Loose","","t [ns]","Gain","t","gain",-6,6,0,0,1,1);
  //plot("output.root","h_tight_t_gain","h_loose_t_gain","Tight","Loose","","t [ns]","Gain","t","gain",-6,6,1,1,1,1);
  //plot("output.root","h_tight_t_gain","h_loose_t_gain","Tight","Loose","","t [ns]","Gain","t","gain",-6,6,2,2,1,1);

  //plot("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose","","t [ns]","|#eta|","t","eta",-6,6,0,0.8,100,1);
  //plot("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose","","t [ns]","|#eta|","t","eta",-6,6,0.8,1.37,100,1);
  //plot("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose","","t [ns]","|#eta|","t","eta",-6,6,1.52,2,100,1);
  //plot("output.root","h_tight_t_abseta","h_loose_t_abseta","Tight","Loose","","t [ns]","|#eta|","t","eta",-6,6,2,2.37,100,1);

  //plot("output.root","h_tight_z_abseta","h_loose_z_abseta","Tight","Loose","","Z_DCA [mm]","|#eta|","z","eta",-2000,2000,0,0.8,100,10);
  //plot("output.root","h_tight_z_abseta","h_loose_z_abseta","Tight","Loose","","Z_DCA [mm]","|#eta|","z","eta",-2000,2000,0.8,1.37,100,10);
  //plot("output.root","h_tight_z_abseta","h_loose_z_abseta","Tight","Loose","","Z_DCA [mm]","|#eta|","z","eta",-2000,2000,1.52,2,100,10);
  //plot("output.root","h_tight_z_abseta","h_loose_z_abseta","Tight","Loose","","Z_DCA [mm]","|#eta|","z","eta",-2000,2000,2,2.37,100,10);

  plot("output.root","h_tight_z_gain","h_loose_z_gain","Tight","Loose","","Z_DCA [mm]","Gain","z","gain",-2000,2000,0,0,1,10);
  plot("output.root","h_tight_z_gain","h_loose_z_gain","Tight","Loose","","Z_DCA [mm]","Gain","z","gain",-2000,2000,1,1,1,10);
  plot("output.root","h_tight_z_gain","h_loose_z_gain","Tight","Loose","","Z_DCA [mm]","Gain","z","gain",-2000,2000,2,2,1,10);
}
