#include "AtlasLabels.C"
#include "AtlasLabels.h"
void bino_plots_mgfixed(TString timing, double tau, int rebin, double xmin_lead, double xmax_lead, double xmin_sub, double xmax_sub, int rebin1, int rebin2) {
  double mg = 1200;
  double mx1, mx2, mx3;
  mx1 = 200; mx2 = 600; mx3 = 1000;
  double dsid1,dsid2,dsid3;
  if (mg >= 1000) {
    if (tau == 0.5) {
      dsid1 = 500000+10*(mg-1000)+(mx1/100);
      dsid2 = 500000+10*(mg-1000)+(mx2/100);
      dsid3 = 500000+10*(mg-1000)+(mx3/100);
    }
    else {
      dsid1 = 100000*tau+10*(mg-1000)+(mx1/100);
      dsid2 = 100000*tau+10*(mg-1000)+(mx2/100);
      dsid3 = 100000*tau+10*(mg-1000)+(mx3/100);
    }
  }
  else {
    if (tau == 0.5) {
      dsid1 = 500000+mg+(mx1/100);
      dsid2 = 500000+mg+(mx2/100);
      dsid3 = 500000+mg+(mx3/100);
    }
    else {
      dsid1 = 100000*tau+mg+(mx1/100);
      dsid2 = 100000*tau+mg+(mx2/100);
      dsid3 = 100000*tau+mg+(mx3/100);
    }
  }
  int lookup1 = (int)dsid1; int lookup2 = (int)dsid2; int lookup3 = (int)dsid3;
  TString substr1, substr2, substr3;
  substr1.Form("/output_%i.root",lookup1); substr2.Form("/output_%i.root",lookup2); substr3.Form("/output_%i.root",lookup3);
  TString file1 = "/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/diphoton/cutflows/"+timing+substr1;
  TString file2 = "/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/diphoton/cutflows/"+timing+substr2;
  TString file3 = "/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/diphoton/cutflows/"+timing+substr3;
  TFile *f1 = TFile::Open(file1);
  TFile *f2 = TFile::Open(file2);
  TFile *f3 = TFile::Open(file3);
  TString mgmx;
  mgmx.Form("m_{#tilde{g}} = %.0f GeV", mg);
  TString mgmxtag;
  mgmxtag.Form("mg%.0f_mxvaried",mg);
  TString tau_tag;
  tau_tag.Form("#tau = %4.1f ns",tau);

  TString leading, subleading;
  leading = "h_bino_lifetime";
  subleading = "h_bino_vertex";
  TH1F *lead1 = (TH1F*)f1->Get(leading);
  TH1F *sub1 = (TH1F*)f1->Get(subleading);
  TH1F *lead2 = (TH1F*)f2->Get(leading);
  TH1F *sub2 = (TH1F*)f2->Get(subleading);
  TH1F *lead3 = (TH1F*)f3->Get(leading);
  TH1F *sub3 = (TH1F*)f3->Get(subleading);
  lead1->Rebin(rebin1);
  sub1->Rebin(rebin2);
  lead2->Rebin(rebin1);
  sub2->Rebin(rebin2);
  lead3->Rebin(rebin1);
  sub3->Rebin(rebin2);
  lead2->SetLineColor(2);
  sub2->SetLineColor(2);
  lead3->SetLineColor(3);
  sub3->SetLineColor(3);
  lead1->Scale(1/lead1->Integral());
  lead2->Scale(1/lead2->Integral());
  lead3->Scale(1/lead3->Integral());
  sub1->Scale(1/sub1->Integral());
  sub2->Scale(1/sub2->Integral());
  sub3->Scale(1/sub3->Integral());
  TString file_leading = "plot_bino_lifetime_"+mgmxtag+"_"+timing+"_SBT";
  TString file_sub = "plot_bino_decay_radius_"+mgmxtag+"_"+timing+"_SBT";
  
  TCanvas *c1 = new TCanvas();
  c1->SetLogy();
  lead1->GetYaxis()->SetRangeUser(0.1*lead1->GetBinContent(lead1->FindLastBinAbove(0)),100*lead1->GetMaximum());
  lead1->GetYaxis()->SetTitle("Events");
  lead1->GetXaxis()->SetRangeUser(xmin_lead,xmax_lead);
  lead1->GetXaxis()->SetTitle("Bino Lifetime [ns]");
  lead1->Draw("hist");
  lead2->Draw("histsame");
  lead3->Draw("histsame");
  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.6,0.9,mgmx);
  l.DrawLatex(0.6,0.77,tau_tag);
  ATLASLabel(0.6,0.82,"Internal");
  TLegend leg1(0.3,0.7,0.5,0.9);
  leg1.SetLineColor(0);
  leg1.SetFillStyle(0);
  leg1.SetTextSize(0.03);
  leg1.SetShadowColor(0);
  leg1.AddEntry(lead1,"m_{#tilde{#chi}} = 200 GeV","l");
  leg1.AddEntry(lead2,"m_{#tilde{#chi}} = 600 GeV","l");
  leg1.AddEntry(lead3,"m_{#tilde{#chi}} = 1000 GeV","l");
  leg1.Draw();
  c1->SaveAs(file_leading+".png");
  c1->SaveAs(file_leading+".pdf");
  c1->SaveAs(file_leading+".eps");
  c1->SaveAs(file_leading+".C");
  
  TCanvas *c2 = new TCanvas();
  c2->SetLogy();
  sub1->GetYaxis()->SetRangeUser(0.1*sub1->GetBinContent(sub1->FindLastBinAbove(0)),100*sub1->GetMaximum());
  sub1->GetYaxis()->SetTitle("Events");
  sub1->GetXaxis()->SetRangeUser(xmin_sub,xmax_sub);
  sub1->GetXaxis()->SetTitle("Bino Decay Vertex Radius [mm]");
  sub1->Draw("hist");
  sub2->Draw("histsame");
  sub3->Draw("histsame");
  l.SetNDC();
  l.DrawLatex(0.6,0.9,mgmx);
  l.DrawLatex(0.6,0.77,tau_tag);
  ATLASLabel(0.6,0.82,"Internal");
  TLegend leg2(0.3,0.7,0.5,0.9);
  leg2.SetLineColor(0);
  leg2.SetFillStyle(0);
  leg2.SetTextSize(0.03);
  leg2.SetShadowColor(0);
  leg2.AddEntry(sub1,"m_{#tilde{#chi}} = 200 GeV","l");
  leg2.AddEntry(sub2,"m_{#tilde{#chi}} = 600 GeV","l");
  leg2.AddEntry(sub3,"m_{#tilde{#chi}} = 1000 GeV","l");
  leg2.Draw();
  c2->SaveAs(file_sub+".png");
  c2->SaveAs(file_sub+".pdf");
  c2->SaveAs(file_sub+".eps");
  c2->SaveAs(file_sub+".C");
  
}
  
