void etaplots() {
  TFile *f = TFile::Open("output.root");

  TH1F *h1 = (TH1F*)f->Get("h_tight_eta");
  TH1F *h2 = (TH1F*)f->Get("h_loose_eta");

  //Rebin histos, change number if necessary
  h1->Rebin(10);
  h2->Rebin(10);

  h1->Sumw2();
  h2->Sumw2();
  
  h1->Scale(1/h1->Integral());
  h2->Scale(1/h2->Integral());

  h1->GetYaxis()->SetRangeUser(h1->GetBinContent( h1->FindLastBinAbove(0))*0.5,h1->GetMaximum()*10);

  h1->GetYaxis()->SetTitle("a.u.");
  h1->GetYaxis()->SetLabelSize(0.07);
  h1->GetYaxis()->SetLabelOffset(0.01);
  h1->GetYaxis()->SetTitleSize(0.08);
  h1->GetYaxis()->SetTitleOffset(0.81);

  h2->SetMarkerSize(1);
  h2->SetMarkerStyle(24);

  TCanvas * c =new TCanvas();
  c->Divide(1,2);
  c->SetBottomMargin(0.2);
  c->cd(1);
  c->GetPad(1)->SetLogy();
  c->GetPad(1)->SetPad(0.,0.25,1.,1);

  h1->Draw("axis");
  h1->Draw("histsame");
  h2->Draw("Esame");

  TLegend leg(0.65,0.80,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.05);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,"Tight","L");
  leg.AddEntry(h2,"Loose","PL");
  leg.Draw();

  c->cd(2);
  c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c->GetPad(2)->SetBottomMargin(0.3);
  c->GetPad(2)->SetGridy(1);

  TH1F *h1_clone = (TH1F*)h1->Clone();

  h1_clone->Divide(h2);
  //  h1_clone->GetXaxis()->SetRangeUser(xmin, xmax);
  h1_clone->GetXaxis()->SetTitle("#eta");
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

  TString filename = "Eta_tight_loose_comparison";
  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(filename+feps);
  c->SaveAs(filename+fpng);
  c->SaveAs(filename+fpdf);


}
  

  
  
