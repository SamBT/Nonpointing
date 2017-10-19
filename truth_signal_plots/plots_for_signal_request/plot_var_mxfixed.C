#include "AtlasLabels.C"
#include "AtlasLabels.h"
void plot_var_mxfixed(TString var, TString timing, double tau, int rebin, double xmin_lead, double xmax_lead, double xmin_sub, double xmax_sub) {
  double mx = 600;
  double mg1, mg2, mg3;
  mg1 = 1000; mg2 = 1400; mg3 = 1800;
  double dsid1,dsid2,dsid3;
  if (tau == 0.5) {
    dsid1 = 500000+10*(mg1-1000)+(mx/100);
    dsid2 = 500000+10*(mg2-1000)+(mx/100);
    dsid3 = 500000+10*(mg3-1000)+(mx/100);
  }
  else {
    dsid1 = 100000*tau+10*(mg1-1000)+(mx/100);
    dsid2 = 100000*tau+10*(mg2-1000)+(mx/100);
    dsid3 = 100000*tau+10*(mg3-1000)+(mx/100);
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
  mgmx.Form("m_{#tilde{#chi}} = %.0f GeV", mx);
  TString mgmxtag;
  mgmxtag.Form("mx%.0f_mgvaried",mx);
  TString tau_tag;
  tau_tag.Form("#tau = %4.1f ns",tau);

  if (var == "MET") {
    TH1F *met1 = (TH1F*)f1->Get("h_MET");
    TH1F *met2 = (TH1F*)f2->Get("h_MET");
    TH1F *met3 = (TH1F*)f3->Get("h_MET");
    met1->Rebin(rebin);
    met2->Rebin(rebin);
    met3->Rebin(rebin);
    met1->GetXaxis()->SetTitle("Missing E_{T} [GeV]");
    met1->GetYaxis()->SetTitle("a.u.");
    met1->GetYaxis()->SetRangeUser(0.1*met1->GetBinContent(met1->FindLastBinAbove(0)),10000*met1->GetMaximum());
    met1->GetXaxis()->SetRangeUser(xmin_lead,xmax_lead);
    TString filename = "plot_met_"+mgmxtag+"_"+timing+"_SBT";
    
    met2->SetLineColor(2);
    met3->SetLineColor(3);

    met1->Scale(1/met1->Integral());
    met2->Scale(1/met2->Integral());
    met3->Scale(1/met3->Integral());

    TCanvas *c = new TCanvas();
    c->SetLogy();
    met1->Draw("hist");
    met2->Draw("histsame");
    met3->Draw("histsame");
    TLatex l;
    l.SetNDC();
    l.DrawLatex(0.6,0.9,mgmx);
    l.DrawLatex(0.6,0.82,tau_tag);
    ATLASLabel(0.6,0.77,"Internal");
    TLegend leg(0.3,0.7,0.5,0.9);
    leg.SetLineColor(0);
    leg.SetFillStyle(0);    
    leg.SetTextSize(0.03);
    leg.SetShadowColor(0);
    leg.AddEntry(met1,"m_{#tilde{g}} = 1000 GeV","l");
    leg.AddEntry(met2,"m_{#tilde{g}} = 1400 GeV","l");
    leg.AddEntry(met3,"m_{#tilde{g}} = 1800 GeV","l");
    leg.Draw();
    c->SaveAs(filename+".png");
    c->SaveAs(filename+".pdf");
    c->SaveAs(filename+".eps");
    c->SaveAs(filename+".C");

  }
  else {
    TString leading, subleading;
    leading = "h_leading_"+var;
    subleading = "h_subleading_"+var;
    TH1F *lead1 = (TH1F*)f1->Get(leading);
    TH1F *sub1 = (TH1F*)f1->Get(subleading);
    TH1F *lead2 = (TH1F*)f2->Get(leading);
    TH1F *sub2 = (TH1F*)f2->Get(subleading);
    TH1F *lead3 = (TH1F*)f3->Get(leading);
    TH1F *sub3 = (TH1F*)f3->Get(subleading);
    lead1->Rebin(rebin);
    sub1->Rebin(rebin);
    lead2->Rebin(rebin);
    sub2->Rebin(rebin);
    lead3->Rebin(rebin);
    sub3->Rebin(rebin);
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
    TString file_leading = "plot_leading_"+var+"_"+mgmxtag+"_"+timing+"_SBT";
    TString file_sub = "plot_subleading_"+var+"_"+mgmxtag+"_"+timing+"_SBT";
    if (var == "pointing") {
      lead1->GetXaxis()->SetBinLabel(1,"0-20");
      lead1->GetXaxis()->SetBinLabel(2,"20-40");
      lead1->GetXaxis()->SetBinLabel(3,"40-60");
      lead1->GetXaxis()->SetBinLabel(4,"60-80");
      lead1->GetXaxis()->SetBinLabel(5,"80-100");
      lead1->GetXaxis()->SetBinLabel(6,"100-120");
      lead1->GetXaxis()->SetBinLabel(7,"120-140");
      lead1->GetXaxis()->SetBinLabel(8,"140-160");
      lead1->GetXaxis()->SetBinLabel(9,"160-180");
      lead1->GetXaxis()->SetBinLabel(10,"180-200");
      lead1->GetXaxis()->SetBinLabel(11,"200-2000");
      sub1->GetXaxis()->SetBinLabel(1,"0-20");
      sub1->GetXaxis()->SetBinLabel(2,"20-40");
      sub1->GetXaxis()->SetBinLabel(3,"40-60");
      sub1->GetXaxis()->SetBinLabel(4,"60-80");
      sub1->GetXaxis()->SetBinLabel(5,"80-100");
      sub1->GetXaxis()->SetBinLabel(6,"100-120");
      sub1->GetXaxis()->SetBinLabel(7,"120-140");
      sub1->GetXaxis()->SetBinLabel(8,"140-160");
      sub1->GetXaxis()->SetBinLabel(9,"160-180");
      sub1->GetXaxis()->SetBinLabel(10,"180-200");
      sub1->GetXaxis()->SetBinLabel(11,"200-2000");
    }
    
    TCanvas *c1 = new TCanvas();
    c1->SetLogy();
    lead1->GetYaxis()->SetRangeUser(0.1*lead1->GetBinContent(lead1->FindLastBinAbove(0)),100*lead1->GetMaximum());
    lead1->GetYaxis()->SetTitle("a.u.");
    lead1->GetXaxis()->SetRangeUser(xmin_lead,xmax_lead);
    if (var == "pt") lead1->GetXaxis()->SetTitle("Leading Photon p_{T} [GeV]");
    if (var == "eta") lead1->GetXaxis()->SetTitle("Leading Photon #eta");
    if (var == "timing") lead1->GetXaxis()->SetTitle("Leading Photon Timing [ns]");
    if (var == "pointing") lead1->GetXaxis()->SetTitle("Leading Photon Z_{DCA} [mm]");
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
    leg1.AddEntry(lead1,"m_{#tilde{g}} = 1000 GeV","l");
    leg1.AddEntry(lead2,"m_{#tilde{g}} = 1400 GeV","l");
    leg1.AddEntry(lead3,"m_{#tilde{g}} = 1800 GeV","l");
    leg1.Draw();
    c1->SaveAs(file_leading+".png");
    c1->SaveAs(file_leading+".pdf");
    c1->SaveAs(file_leading+".eps");
    c1->SaveAs(file_leading+".C");
    
    TCanvas *c2 = new TCanvas();
    c2->SetLogy();
    sub1->GetYaxis()->SetRangeUser(0.1*sub1->GetBinContent(sub1->FindLastBinAbove(0)),100*sub1->GetMaximum());
    sub1->GetYaxis()->SetTitle("a.u.");
    sub1->GetXaxis()->SetRangeUser(xmin_sub,xmax_sub);
    if (var == "pt") sub1->GetXaxis()->SetTitle("Sub-leading Photon p_{T} [GeV]");
    if (var == "eta") sub1->GetXaxis()->SetTitle("Sub-leading Photon #eta");
    if (var == "timing") sub1->GetXaxis()->SetTitle("Sub-leading Photon Timing [ns]");
    if (var == "pointing") sub1->GetXaxis()->SetTitle("Sub-leading Photon Z_{DCA} [mm]");
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
    leg2.AddEntry(sub1,"m_{#tilde{g}} = 1000 GeV","l");
    leg2.AddEntry(sub2,"m_{#tilde{g}} = 1400 GeV","l");
    leg2.AddEntry(sub3,"m_{#tilde{g}} = 1800 GeV","l");
    leg2.Draw();
    c2->SaveAs(file_sub+".png");
    c2->SaveAs(file_sub+".pdf");
    c2->SaveAs(file_sub+".eps");
    c2->SaveAs(file_sub+".C");

  }
}
  
