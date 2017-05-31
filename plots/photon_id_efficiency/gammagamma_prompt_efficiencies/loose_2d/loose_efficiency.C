#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot(TString type) {
	TString path = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/" + type;
	TFile *s1 = TFile::Open(path+"/gammagamma_prompt/gammagamma_prompt.root");

	TString loose = "h_ZDCA_timing_loose";
	TString ratio = "h_ZDCA_timing_loose_eff";

	TH2F *ht1 = (TH2F*)s1->Get(loose);
	TEfficiency *eff1 = (TEfficiency*)s1->Get(ratio);
	TH2F *ht = ht1;
	ht->Sumw2();
	TEfficiency *eff = eff1;

	ht->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");
	ht->GetXaxis()->SetTitle("Timing [ns]");

	ht->GetYaxis()->SetRangeUser(0.1*ht->GetBinContent(ht->FindLastBinAbove(0)),10*ht->GetMaximum());

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