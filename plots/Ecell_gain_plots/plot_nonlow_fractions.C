#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot_nonlow_fractions(TString message, int rebin) {
  TFile *f1 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403280.root");
  TFile *f2 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403281.root");
  TFile *f3 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403282.root");
  TFile *f4 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403283.root");
  TFile *f5 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403284.root");
  TFile *f6 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403285.root");
  TFile *f7 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/403286.root");

  TFile *f8 = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/data/output_data.root");
  TH1F *htot_data = (TH1F*)f8->Get("h_Ecell_allgains");
  TH1F *hm_data = (TH1F*)f8->Get("h_Ecell_medgain");
  TH1F *hh_data = (TH1F*)f8->Get("h_Ecell_highgain");
  TH1F *hmh_data = hm_data;
  hmh_data->Add(hh_data);
  hmh_data->Rebin(rebin);
  htot_data->Rebin(rebin);
  hmh_data->Divide(htot_data);
  hmh_data->SetLineColor(2);

  TH1F *htot1 = (TH1F*)f1->Get("h_Ecell_allgains");
  TH1F *htot2 = (TH1F*)f2->Get("h_Ecell_allgains");
  TH1F *htot3 = (TH1F*)f3->Get("h_Ecell_allgains");
  TH1F *htot4 = (TH1F*)f4->Get("h_Ecell_allgains");
  TH1F *htot5 = (TH1F*)f5->Get("h_Ecell_allgains");
  TH1F *htot6 = (TH1F*)f6->Get("h_Ecell_allgains");
  TH1F *htot7 = (TH1F*)f7->Get("h_Ecell_allgains");

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

  TH1F *hmh = hm;
  hmh->Add(hh);

  hmh->Rebin(rebin);
  htot->Rebin(rebin);

  hmh->Divide(htot);

  TCanvas *c = new TCanvas();
  c->SetRightMargin(0.10);
  hmh->GetXaxis()->SetRangeUser(0, hmh->GetXaxis()->GetBinCenter(hmh->FindLastBinAbove(0)));
  hmh->GetYaxis()->SetRangeUser(0,hmh->GetMaximum()*2);
  hmh->GetXaxis()->SetTitle("Max Ecell Energy [GeV]");
  hmh->GetYaxis()->SetTitle("Fraction of Total Events");
  hmh->Draw("hist");
  hmh_data->Draw("histsame");
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.5,0.8,"All Reco Signal Points Combined");
  l.DrawLatex(0.5,0.75,message);
  ATLASLabel(0.5,0.68,"Internal");
  TLegend leg(0.2,0.65,0.4,0.85);
  leg.AddEntry(hmh,"Med + High, Signal","l");
  leg.AddEntry(hmh_data,"Med + High, Data","l");
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.Draw();
  TString outfname = "fraction_medplushigh_SBT";
  c->SaveAs(outfname+".C");
  c->SaveAs(outfname+".pdf");
  c->SaveAs(outfname+".eps");
  c->SaveAs(outfname+".png");
}
  

  
