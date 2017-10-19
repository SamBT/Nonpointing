#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot_all_fractions(TString message, int rebin) {
  TFile *f1 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403280.root");
  TFile *f2 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403281.root");
  TFile *f3 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403282.root");
  TFile *f4 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403283.root");
  TFile *f5 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403284.root");
  TFile *f6 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403285.root");
  TFile *f7 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403286.root");

  TFile *f8 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/data/output_data.root");
  TH1F *htot_data = (TH1F*)f8->Get("h_Ecell_allgains");
  TH1F *hl_data = (TH1F*)f8->Get("h_Ecell_lowgain");
  TH1F *hm_data = (TH1F*)f8->Get("h_Ecell_medgain");
  TH1F *hh_data = (TH1F*)f8->Get("h_Ecell_highgain");
  htot_data->Sumw2();
  hl_data->Sumw2();
  hm_data->Sumw2();
  hh_data->Sumw2();
  htot_data->Rebin(rebin);
  hl_data->Rebin(rebin);
  hm_data->Rebin(rebin);
  hh_data->Rebin(rebin);
  hl_data->Divide(htot_data);
  hm_data->Divide(htot_data);
  hh_data->Divide(htot_data);
  hl_data->SetLineColor(4);
  hm_data->SetLineColor(5);
  hh_data->SetLineColor(6);
  hl_data->SetMarkerStyle(24);
  hm_data->SetMarkerStyle(25);
  hh_data->SetMarkerStyle(26);
  hl_data->SetMarkerColor(4);
  hm_data->SetMarkerColor(5);
  hh_data->SetMarkerColor(6);

  TH1F *htot1 = (TH1F*)f1->Get("h_Ecell_allgains");
  TH1F *htot2 = (TH1F*)f2->Get("h_Ecell_allgains");
  TH1F *htot3 = (TH1F*)f3->Get("h_Ecell_allgains");
  TH1F *htot4 = (TH1F*)f4->Get("h_Ecell_allgains");
  TH1F *htot5 = (TH1F*)f5->Get("h_Ecell_allgains");
  TH1F *htot6 = (TH1F*)f6->Get("h_Ecell_allgains");
  TH1F *htot7 = (TH1F*)f7->Get("h_Ecell_allgains");

  TH1F *hl1 = (TH1F*)f1->Get("h_Ecell_lowgain");
  TH1F *hl2 = (TH1F*)f2->Get("h_Ecell_lowgain");
  TH1F *hl3 = (TH1F*)f3->Get("h_Ecell_lowgain");
  TH1F *hl4 = (TH1F*)f4->Get("h_Ecell_lowgain");
  TH1F *hl5 = (TH1F*)f5->Get("h_Ecell_lowgain");
  TH1F *hl6 = (TH1F*)f6->Get("h_Ecell_lowgain");
  TH1F *hl7 = (TH1F*)f7->Get("h_Ecell_lowgain");

  TH1F *hm1 = (TH1F*)f1->Get("h_Ecell_medgain");
  TH1F *hm2 = (TH1F*)f2->Get("h_Ecell_medgain");
  TH1F *hm3 = (TH1F*)f3->Get("h_Ecell_medgain");
  TH1F *hm4 = (TH1F*)f4->Get("h_Ecell_medgain");
  TH1F *hm5 = (TH1F*)f5->Get("h_Ecell_medgain");
  TH1F *hm6 = (TH1F*)f6->Get("h_Ecell_medgain");
  TH1F *hm7 = (TH1F*)f7->Get("h_Ecell_medgain");

  TH1F *hh1 = (TH1F*)f1->Get("h_Ecell_highgain");
  TH1F *hh2 = (TH1F*)f2->Get("h_Ecell_highgain");
  TH1F *hh3 = (TH1F*)f3->Get("h_Ecell_highgain");
  TH1F *hh4 = (TH1F*)f4->Get("h_Ecell_highgain");
  TH1F *hh5 = (TH1F*)f5->Get("h_Ecell_highgain");
  TH1F *hh6 = (TH1F*)f6->Get("h_Ecell_highgain");
  TH1F *hh7 = (TH1F*)f7->Get("h_Ecell_highgain");

  TH1F *htot = htot1;
  htot->Add(htot2);
  htot->Add(htot3);
  htot->Add(htot4);
  htot->Add(htot5);
  htot->Add(htot6);
  htot->Add(htot7);

  TH1F *hl = hl1;
  hl->Add(hl2);
  hl->Add(hl3);
  hl->Add(hl4);
  hl->Add(hl5);
  hl->Add(hl6);
  hl->Add(hl7);

  TH1F *hm = hm1;
  hm->Add(hm2);
  hm->Add(hm3);
  hm->Add(hm4);
  hm->Add(hm5);
  hm->Add(hm6);
  hm->Add(hm7);

  TH1F *hh = hh1;
  hh->Add(hh2);
  hh->Add(hh3);
  hh->Add(hh4);
  hh->Add(hh5);
  hh->Add(hh6);
  hh->Add(hh7);

  hl->Rebin(rebin);
  hm->Rebin(rebin);
  hh->Rebin(rebin);
  htot->Rebin(rebin);

  hl->Divide(htot);
  hm->Divide(htot);
  hh->Divide(htot);

  hl->SetLineColor(1);
  hm->SetLineColor(2);
  hh->SetLineColor(3);

  hl->SetLineStyle(1);
  hm->SetLineStyle(2);
  hh->SetLineStyle(4);

  TCanvas *c = new TCanvas();
  c->SetRightMargin(0.10);
  hl->GetXaxis()->SetRangeUser(0, hl->GetXaxis()->GetBinCenter(hl->FindLastBinAbove(0)));
  hl->GetYaxis()->SetRangeUser(0,hl->GetMaximum()*2);
  hl->GetXaxis()->SetTitle("Max Ecell Energy [GeV]");
  hl->GetYaxis()->SetTitle("Fraction of Total Events");
  hl->Draw("hist");
  hm->Draw("histsame");
  hh->Draw("histsame");
  hl_data->Draw("histpsame");
  hm_data->Draw("histpsame");
  hh_data->Draw("histpsame");
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.5,0.8,"All Reco Signal Points Combined");
  l.DrawLatex(0.5,0.75,message);
  ATLASLabel(0.5,0.68,"Internal");
  TLegend leg(0.2,0.6,0.4,0.9);
  leg.AddEntry(hl,"Low Gain Signal","l");
  leg.AddEntry(hm,"Med Gain Signal","l");
  leg.AddEntry(hh,"High Gain Signal","l");
  leg.AddEntry(hl_data,"Low Gain Data","e");
  leg.AddEntry(hm_data,"Med Gain Data","e");
  leg.AddEntry(hh_data,"High Gain Data","e");
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.Draw();
  TString outfname = "fraction_all_SBT";
  c->SaveAs(outfname+".C");
  c->SaveAs(outfname+".pdf");
  c->SaveAs(outfname+".eps");
  c->SaveAs(outfname+".png");
}
  

  
