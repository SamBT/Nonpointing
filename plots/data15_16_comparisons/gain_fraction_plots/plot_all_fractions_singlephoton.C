#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot_all_fractions_singlephoton(TString variable, TString xlabel, int rebin) {
  TFile *f1 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data15_EXOT6/output.root");
  TFile *f2 = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_EXOT6/output.root");

  TH2F *h15 = (TH2F*)f1->Get("h_"+variable+"_gain");
  h15->SetNameTitle("h15","h15");
  TH2F *h16 = (TH2F*)f2->Get("h_"+variable+"_gain");
  h16->SetNameTitle("h16","h16");

  TH1D *ha15 = h15->ProjectionX("ha15",1,3);
  TH1D *hl15 = h15->ProjectionX("hl15",3,3);
  TH1D *hm15 = h15->ProjectionX("hm15",2,2);
  TH1D *hh15 = h15->ProjectionX("hh15",1,1);
  TH1D *ha16 = h16->ProjectionX("ha16",1,3);
  TH1D *hl16 = h16->ProjectionX("hl16",3,3);
  TH1D *hm16 = h16->ProjectionX("hm16",2,2);
  TH1D *hh16 = h16->ProjectionX("hh16",1,1);

  ha15->Rebin(rebin);
  hl15->Rebin(rebin);
  hm15->Rebin(rebin);
  hh15->Rebin(rebin);
  ha16->Rebin(rebin);
  hl16->Rebin(rebin);
  hm16->Rebin(rebin);
  hh16->Rebin(rebin);

  hl15->Divide(ha15);
  hm15->Divide(ha15);
  hh15->Divide(ha15);
  hl16->Divide(ha16);
  hm16->Divide(ha16);
  hh16->Divide(ha16);

  hl15->SetLineColor(1);
  hl15->SetMarkerColor(1);
  hm15->SetLineColor(2);
  hm15->SetMarkerColor(2);
  hh15->SetLineColor(3);
  hh15->SetMarkerColor(3);
  hl16->SetLineColor(4);
  hl16->SetMarkerColor(4);
  hm16->SetLineColor(6);
  hm16->SetMarkerColor(6);
  hh16->SetLineColor(7);
  hh16->SetMarkerColor(7);

  hm15->SetLineStyle(2);
  hh15->SetLineStyle(4);
  hl16->SetMarkerStyle(24);
  hm16->SetMarkerStyle(25);
  hh16->SetMarkerStyle(26);

  TCanvas *c = new TCanvas();
  c->SetRightMargin(0.10);
  hl15->GetXaxis()->SetRangeUser(0, hl15->GetXaxis()->GetBinCenter(hl15->FindLastBinAbove(0)));
  hl15->GetYaxis()->SetRangeUser(0,hl15->GetMaximum()*2);
  hl15->GetXaxis()->SetTitle(xlabel);
  hl15->GetYaxis()->SetTitle("Fraction of Total Events");
  hl15->Draw("hist");
  hm15->Draw("histsame");
  hh15->Draw("histsame");
  hl16->Draw("histpsame");
  hm16->Draw("histpsame");
  hh16->Draw("histpsame");
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.5,0.75,"Singlephoton, p_{T} > 150, Barrel");
  ATLASLabel(0.5,0.68,"Internal");
  TLegend leg(0.2,0.6,0.4,0.9);
  leg.AddEntry(hl15,"2015, Low","l");
  leg.AddEntry(hm15,"2015, Med","l");
  leg.AddEntry(hh15,"2015, High","l");
  leg.AddEntry(hl16,"2016, Low","p");
  leg.AddEntry(hm16,"2016, Med","p");
  leg.AddEntry(hh16,"2016, High","p");
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.Draw();
  TString outfname = "data_singlephoton_gain_fraction_vs_"+variable+"_15_16_comparison_SBT";
  c->SaveAs(outfname+".C");
  c->SaveAs(outfname+".pdf");
  c->SaveAs(outfname+".eps");
  c->SaveAs(outfname+".png");
}
  

  
