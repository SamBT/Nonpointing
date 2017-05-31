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
	TString ratio = "h_ZDCA_timing_loose_eff";

	TH2F *ht1 = (TH2F*)s1->Get(loose);
	TH2F *ht2 = (TH2F*)s2->Get(loose);
	TH2F *ht3 = (TH2F*)s3->Get(loose);
	TH2F *ht4 = (TH2F*)s4->Get(loose);
	TH2F *ht5 = (TH2F*)s5->Get(loose);
	TH2F *ht6 = (TH2F*)s6->Get(loose);
	TH2F *ht7 = (TH2F*)s7->Get(loose);

	TEfficiency *eff1 = (TEfficiency*)s1->Get(ratio);
	TEfficiency *eff2 = (TEfficiency*)s2->Get(ratio);
	TEfficiency *eff3 = (TEfficiency*)s3->Get(ratio);
	TEfficiency *eff4 = (TEfficiency*)s4->Get(ratio);
	TEfficiency *eff5 = (TEfficiency*)s5->Get(ratio);
	TEfficiency *eff6 = (TEfficiency*)s6->Get(ratio);
	TEfficiency *eff7 = (TEfficiency*)s7->Get(ratio);

	TH2F *ht = ht1;
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

	ht->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
	ht->GetXaxis()->SetTitle("Timing [ns]");

	ht->GetYaxis()->SetRangeUser(0.1*ht->GetBinContent(ht->FindLastBinAbove(0)),10*ht->GetMaximum());

	//eff->Scale(100) //convert to percentages	

	TCanvas *c = new TCanvas();

	int bin = -100;
	double percent = 0;

	for (int i = 1; i <= ht->GetNbinsX(); i++) {
		for (int j = 1; j <= ht->GetNbinsY(); j++) {
			bin = eff->GetGlobalBin(i,j);
			percent = eff->GetEfficiency(bin);
			ht->SetBinContent(i,j,percent*100);
		}
	}

	c->SetGridx();
	ht->SetMarkerSize(1.5);
	ht->GetYaxis()->SetTickSize(0.02);
	ht->GetXaxis()->SetNdivisions(12);
	ht->GetYaxis()->SetRangeUser(0,2000);
	gStyle->SetPaintTextFormat("4.0f");
  	ht->Draw("text45");

  	TLatex l;
  	l.SetNDC();
  	l.SetTextSize(0.04);
  	l.DrawLatex(0.7,0.85,"Loose Cut Efficiency");
  	if (type == "diphoton") l.DrawLatex(0.7,0.8,"Diphoton");
  	if (type == "singlephoton") l.DrawLatex(0.7,0.8,"Singlephoton");
  	ATLASLabel(0.7,0.75,"Internal");

  	TLegend leg(0.65,0.80,0.895,0.89);
  	leg.SetLineColor(0);
  	leg.SetFillStyle(0);
  	leg.SetTextSize(0.05);
  	leg.SetShadowColor(0);

  	TString output = "Loose_cut_z_t_efficiency_" + type + "_SBT";
  	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(output+feps);
  	c->SaveAs(output+fpng);
  	c->SaveAs(output+fpdf);

}

void loose_efficiency() {
	plot("diphoton");
	plot("singlephoton");
}