#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot_gain_fraction(TString gain, TString message, int rebin) {
  TFile *f1 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403280.root");
  TFile *f2 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403281.root");
  TFile *f3 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403282.root");
  TFile *f4 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403283.root");
  TFile *f5 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403284.root");
  TFile *f6 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403285.root");
  TFile *f7 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403286.root");

  TString hname = "h_Ecell_"+gain;

  TH1F *htot1 = (TH1F*)f1->Get("h_Ecell_allgains");
  TH1F *htot2 = (TH1F*)f2->Get("h_Ecell_allgains");
  TH1F *htot3 = (TH1F*)f3->Get("h_Ecell_allgains");
  TH1F *htot4 = (TH1F*)f4->Get("h_Ecell_allgains");
  TH1F *htot5 = (TH1F*)f5->Get("h_Ecell_allgains");
  TH1F *htot6 = (TH1F*)f6->Get("h_Ecell_allgains");
  TH1F *htot7 = (TH1F*)f7->Get("h_Ecell_allgains");

  TH1F *h1 = (TH1F*)f1->Get(hname);
  TH1F *h2 = (TH1F*)f2->Get(hname);
  TH1F *h3 = (TH1F*)f3->Get(hname);
  TH1F *h4 = (TH1F*)f4->Get(hname);
  TH1F *h5 = (TH1F*)f5->Get(hname);
  TH1F *h6 = (TH1F*)f6->Get(hname);
  TH1F *h7 = (TH1F*)f7->Get(hname);

  cout << "1" << endl;

  TH1F *htot = htot1;
  htot->Add(htot2);
  htot->Add(htot3);
  htot->Add(htot4);
  htot->Add(htot5);
  htot->Add(htot6);
  htot->Add(htot7);

  TH1F *h = h1;
  h->Add(h2);
  h->Add(h3);
  h->Add(h4);
  h->Add(h5);
  h->Add(h6);
  h->Add(h7);

  h->Rebin(rebin);
  htot->Rebin(rebin);

  h->Divide(htot);

  cout << "2" << endl;

  TCanvas *c = new TCanvas();
  c->SetRightMargin(0.10);
  h->GetXaxis()->SetRangeUser(0, h->GetXaxis()->GetBinCenter(h->FindLastBinAbove(0)));
  h->GetYaxis()->SetRangeUser(0,h->GetMaximum()*2);
  h->GetXaxis()->SetTitle("Max Ecell Energy [GeV]");
  h->GetYaxis()->SetTitle("Fraction of Total Events");
  h->Draw("hist");
  cout << "3"  << endl;
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.5,0.8,"All Reco Signal Points Combined");
  l.DrawLatex(0.5,0.75,message);
  ATLASLabel(0.5,0.68,"Internal");
  TString outfname = "fraction_"+gain+"_SBT";
  c->SaveAs(outfname+".C");
  c->SaveAs(outfname+".pdf");
  c->SaveAs(outfname+".eps");
  c->SaveAs(outfname+".png");
}
  

  
