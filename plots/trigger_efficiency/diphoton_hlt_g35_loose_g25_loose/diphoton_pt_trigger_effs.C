#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot(TString type, TString var) {
	TString path = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/" + type;
	TFile *s1 = TFile::Open(path+"/signal/403280.root");
	TFile *s2 = TFile::Open(path+"/signal/403281.root");
	TFile *s3 = TFile::Open(path+"/signal/403282.root");
	TFile *s4 = TFile::Open(path+"/signal/403283.root");
	TFile *s5 = TFile::Open(path+"/signal/403284.root");
	TFile *s6 = TFile::Open(path+"/signal/403285.root");
	TFile *s7 = TFile::Open(path+"/signal/403286.root");

	TString trig = "h_" + var + "_pass_trigger";
	TString ratio = "h_" + var + "_trigger_eff";

	TH1F *ht1 = (TH1F*)s1->Get(trig);
	TH1F *ht2 = (TH1F*)s2->Get(trig);
	TH1F *ht3 = (TH1F*)s3->Get(trig);
	TH1F *ht4 = (TH1F*)s4->Get(trig);
	TH1F *ht5 = (TH1F*)s5->Get(trig);
	TH1F *ht6 = (TH1F*)s6->Get(trig);
	TH1F *ht7 = (TH1F*)s7->Get(trig);

	TEfficiency *eff1 = (TEfficiency*)s1->Get(ratio);
	TEfficiency *eff2 = (TEfficiency*)s2->Get(ratio);
	TEfficiency *eff3 = (TEfficiency*)s3->Get(ratio);
	TEfficiency *eff4 = (TEfficiency*)s4->Get(ratio);
	TEfficiency *eff5 = (TEfficiency*)s5->Get(ratio);
	TEfficiency *eff6 = (TEfficiency*)s6->Get(ratio);
	TEfficiency *eff7 = (TEfficiency*)s7->Get(ratio);

	TH1F *ht = ht1;
	ht->Sumw2();
	ht->Add(ht2);
	ht->Add(ht3);
	ht->Add(ht4);
	ht->Add(ht5);
	ht->Add(ht6);
	ht->Add(ht7);

	TEfficiency *eff = eff1;
	eff->Add(*eff2);
	eff->Add(*eff3);
	eff->Add(*eff4);
	eff->Add(*eff5);
	eff->Add(*eff6);
	eff->Add(*eff7);

	ht->GetYaxis()->SetTitle("Efficiency");
	if (var == "pt1") ht->GetXaxis()->SetTitle("Lower p_{T1} Threshold");
	if (var == "pt2") ht->GetXaxis()->SetTitle("Lower p_{T2} Threshold");
	if (var == "pt1") ht->GetXaxis()->SetRangeUser(0,80);
	if (var == "pt2") ht->GetXaxis()->SetRangeUser(0,80);
	if (var == "pt2") ht->GetYaxis()->SetRangeUser(0.99,1);
	if (var == "pt1") ht->GetYaxis()->SetRangeUser(0.41,0.44);
	ht->SetLineColor(0);
	ht->SetMarkerColor(0);

	TCanvas *c = new TCanvas();
  	ht->Draw("histE");
  	eff->Draw("E0same");

  	TLatex l;
  	l.SetNDC();
  	l.DrawLatex(0.65,0.85,type);
  	l.DrawLatex(0.65,0.80,"Inclusive p_{T} bins");
  	ATLASLabel(0.65,0.75,"Internal");

  	TString output = type + "_" + var + "_trigger_efficiency_SBT";
  	TString feps = ".eps", fpng = ".png", fpdf = ".pdf", fC = ".C";
  	c->SaveAs(output+feps);
  	c->SaveAs(output+fpng);
  	c->SaveAs(output+fpdf);
  	c->SaveAs(output+fC);
}

void diphoton_pt_trigger_effs() {
	plot("diphoton","pt1");
	plot("diphoton","pt2");
}
