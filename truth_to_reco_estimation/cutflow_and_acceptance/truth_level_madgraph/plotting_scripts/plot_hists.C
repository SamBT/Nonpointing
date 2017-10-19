#include "AtlasLabels.C"
#include "AtlasLabels.h"
void plot_hists(TString timing, double tau, int hsbin, int hdbin, TString single_selection, TString di_selection) {
  TString name1, name2;
  name1 = "hist_"+timing+".root";
  name2 = "hist_unwt_"+timing+".root";
  TFile *f1 = TFile::Open(name1);
  TFile *f2 = TFile::Open(name2);

  TString hsbin_name, hdbin_name;
  hsbin_name.Form("hs%i",hsbin);
  hdbin_name.Form("hd%i",hdbin);

  TH2F *hs1 = (TH2F*)f1->Get(hsbin_name);
  TH2F *hd1 = (TH2F*)f1->Get(hdbin_name);
  TH2F *hs2 = (TH2F*)f2->Get(hsbin_name);
  TH2F *hd2 = (TH2F*)f2->Get(hdbin_name);

  TCanvas *c1 = new TCanvas();
  hs1->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  hs1->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  hs1->GetYaxis()->SetRangeUser(100,2050);
  hs1->GetXaxis()->SetRangeUser(750,2200);
  hs1->SetMarkerSize(1.5);
  gStyle->SetPaintTextFormat("4.1f");
  TLatex l;
  l.SetNDC();
  TString s;
  s.Form("Single Photon, #tau = %.1f, ",tau);
  s += single_selection;
  l.SetTextSize(0.03);
  l.DrawLatex(0.2,0.85,s);
  TString s2;
  s2 = "cutflow_weighted_"+timing+"_single_SBT";
  c1->SaveAs(s2+".png");
  c1->SaveAs(s2+".pdf");
  c1->SaveAs(s2+".eps");
  c1->SaveAs(s2+".C");
  
  TCanvas *c2 =new TCanvas();
  hd1->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  hd1->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  hd1->GetYaxis()->SetRangeUser(100,2050);
  hd1->GetXaxis()->SetRangeUser(750,2200);
  hd1->SetMarkerSize(1.5);
  gStyle->SetPaintTextFormat("4.1f");
  hd1->Draw("text45");
  l.SetNDC();
  s.Form("Diphoton, #tau = %.1f, ",tau);
  s += di_selection;
  l.SetTextSize(0.03);
  l.DrawLatex(0.2,0.85,s);
  s2 = "cutflow_weighted_"+timing+"_di_SBT";
  c2->SaveAs(s2+".png");
  c2->SaveAs(s2+".pdf");
  c2->SaveAs(s2+".eps");
  c2->SaveAs(s2+".C");
  
  TCanvas *c3 =new TCanvas();
  hs2->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  hs2->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  hs2->GetYaxis()->SetRangeUser(100,2050);
  hs2->GetXaxis()->SetRangeUser(750,2200);
  hs2->SetMarkerSize(1.5);
  gStyle->SetPaintTextFormat("4.1f");
  hs2->Draw("text45");
  l.SetNDC();
  s.Form("Single Photon, #tau = %.1f, ", tau);
  s += single_selection;
  l.SetTextSize(0.03);
  l.DrawLatex(0.2,0.85,s);
  s2 = "cutflow_unwt_"+timing+"_single_SBT";
  c3->SaveAs(s2+".png");
  c3->SaveAs(s2+".pdf");
  c3->SaveAs(s2+".eps");
  c3->SaveAs(s2+".C");

  TCanvas *c4 =new TCanvas();
  hd2->GetXaxis()->SetTitle("m_{#tilde{g}} [GeV]");
  hd2->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
  hd2->GetYaxis()->SetRangeUser(100,2050);
  hd2->GetXaxis()->SetRangeUser(750,2200);
  hd2->SetMarkerSize(1.5);
  gStyle->SetPaintTextFormat("4.1f");
  hd2->Draw("text45");
  l.SetNDC();
  s.Form("Diphoton, #tau = %.1f, ", tau);
  s += di_selection;
  l.SetTextSize(0.03);
  l.DrawLatex(0.2,0.85,s);
  s2 = "cutflow_unwt_"+timing+"_di_SBT";
  c4->SaveAs(s2+".png");
  c4->SaveAs(s2+".pdf");
  c4->SaveAs(s2+".eps");
  c4->SaveAs(s2+".C");
  
}
