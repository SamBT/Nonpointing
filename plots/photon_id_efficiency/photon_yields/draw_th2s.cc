#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot(TString type) {
	TString path = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/" + type;
	TFile *s1 = TFile::Open(path+"/signal/403280.root");
	TFile *s2 = TFile::Open(path+"/signal/403281.root");
	TFile *s3 = TFile::Open(path+"/signal/403282.root");
	TFile *s4 = TFile::Open(path+"/signal/403283.root");
	TFile *s5 = TFile::Open(path+"/signal/403284.root");
	TFile *s6 = TFile::Open(path+"/signal/403285.root");
	TFile *s7 = TFile::Open(path+"/signal/403286.root");

	TString loose = "h_ZDCA_timing_loose";
	TString reg = "h_ZDCA_timing";
	TString tight = "h_ZDCA_timing_tight";

	TH2F *ht1 = (TH2F*)s1->Get(tight);
	TH2F *ht2 = (TH2F*)s2->Get(tight);
	TH2F *ht3 = (TH2F*)s3->Get(tight);
	TH2F *ht4 = (TH2F*)s4->Get(tight);
	TH2F *ht5 = (TH2F*)s5->Get(tight);
	TH2F *ht6 = (TH2F*)s6->Get(tight);
	TH2F *ht7 = (TH2F*)s7->Get(tight);

	TH2F *hl1 = (TH2F*)s1->Get(loose);
	TH2F *hl2 = (TH2F*)s2->Get(loose);
	TH2F *hl3 = (TH2F*)s3->Get(loose);
	TH2F *hl4 = (TH2F*)s4->Get(loose);
	TH2F *hl5 = (TH2F*)s5->Get(loose);
	TH2F *hl6 = (TH2F*)s6->Get(loose);
	TH2F *hl7 = (TH2F*)s7->Get(loose);

	TH2F *h1 = (TH2F*)s1->Get(reg);
	TH2F *h2 = (TH2F*)s2->Get(reg);
	TH2F *h3 = (TH2F*)s3->Get(reg);
	TH2F *h4 = (TH2F*)s4->Get(reg);
	TH2F *h5 = (TH2F*)s5->Get(reg);
	TH2F *h6 = (TH2F*)s6->Get(reg);
	TH2F *h7 = (TH2F*)s7->Get(reg);
	
	TH2F *ht = ht1;
	ht->Sumw2();
	ht->Add(ht2);
	ht->Add(ht3);
	ht->Add(ht4);
	ht->Add(ht5);
	ht->Add(ht6);
	ht->Add(ht7);

	TH2F *hl = hl1;
	hl->Sumw2();
	hl->Add(hl2);
	hl->Add(hl3);
	hl->Add(hl4);
	hl->Add(hl5);
	hl->Add(hl6);
	hl->Add(hl7);

	TH2F *h = h1;
	h->Sumw2();
	h->Add(h2);
	h->Add(h3);
	h->Add(h4);
	h->Add(h5);
	h->Add(h6);
	h->Add(h7);

	ht->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
	ht->GetXaxis()->SetTitle("Timing [ns]");

	hl->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
	hl->GetXaxis()->SetTitle("Timing [ns]");

	h->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
	h->GetXaxis()->SetTitle("Timing [ns]");

	TCanvas *c1 = new TCanvas();
	c1->SetGridx();
	ht->SetMarkerSize(1.5);
	ht->GetYaxis()->SetTickSize(0.02);
	ht->GetXaxis()->SetNdivisions(12);
	ht->GetYaxis()->SetRangeUser(0,2000);
	gStyle->SetPaintTextFormat("4.0f");
  	ht->Draw("text45");
  	TLatex l;
  	l.SetNDC();
  	l.SetTextSize(0.04);
  	l.DrawLatex(0.7,0.85,"Tight Photon Yields");
  	if (type == "diphoton") l.DrawLatex(0.7,0.8,"Diphoton");
  	if (type == "singlephoton") l.DrawLatex(0.7,0.8,"Singlephoton");
  	ATLASLabel(0.7,0.75,"Internal");
  	TString output = "Tight_photon_yields_" + type + "_SBT";
  	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c1->SaveAs(output+feps);
  	c1->SaveAs(output+fpng);
  	c1->SaveAs(output+fpdf);

  	TCanvas *c2 = new TCanvas();
	c2->SetGridx();
	hl->SetMarkerSize(1.5);
	hl->GetYaxis()->SetTickSize(0.02);
	hl->GetXaxis()->SetNdivisions(12);
	hl->GetYaxis()->SetRangeUser(0,2000);
	gStyle->SetPaintTextFormat("4.0f");
  	hl->Draw("text45");
  	l.SetNDC();
  	l.SetTextSize(0.04);
  	l.DrawLatex(0.7,0.85,"Loose Photon Yields");
  	if (type == "diphoton") l.DrawLatex(0.7,0.8,"Diphoton");
  	if (type == "singlephoton") l.DrawLatex(0.7,0.8,"Singlephoton");
  	ATLASLabel(0.7,0.75,"Internal");
  	output = "Loose_photon_yields_" + type + "_SBT";
  	c2->SaveAs(output+feps);
  	c2->SaveAs(output+fpng);
  	c2->SaveAs(output+fpdf);

  	TCanvas *c3 = new TCanvas();
	c3->SetGridx();
	h->SetMarkerSize(1.5);
	h->GetYaxis()->SetTickSize(0.02);
	h->GetXaxis()->SetNdivisions(12);
	h->GetYaxis()->SetRangeUser(0,2000);
	gStyle->SetPaintTextFormat("4.0f");
  	h->Draw("text45");
  	l.SetNDC();
  	l.SetTextSize(0.04);
  	l.DrawLatex(0.7,0.85,"Photon Yields");
  	if (type == "diphoton") l.DrawLatex(0.7,0.8,"Diphoton");
  	if (type == "singlephoton") l.DrawLatex(0.7,0.8,"Singlephoton");
  	ATLASLabel(0.7,0.75,"Internal");
  	output = "Photon_yields_" + type + "_SBT";
  	c3->SaveAs(output+feps);
  	c3->SaveAs(output+fpng);
  	c3->SaveAs(output+fpdf);

}

void draw_th2s() {
	plot("diphoton");
	plot("singlephoton");
}