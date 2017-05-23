void plot(TString type) {
	TString path = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/" + type;
	TFile *s1 = TFile::Open(path+"/signal/403280.root");
	TFile *s2 = TFile::Open(path+"/signal/403281.root");
	TFile *s3 = TFile::Open(path+"/signal/403282.root");
	TFile *s4 = TFile::Open(path+"/signal/403283.root");
	TFile *s5 = TFile::Open(path+"/signal/403284.root");
	TFile *s6 = TFile::Open(path+"/signal/403285.root");
	TFile *s7 = TFile::Open(path+"/signal/403286.root");

	TString tight = "h_ZDCA_timing_tight";
	TString ratio = "h_ZDCA_timing_eff";

	TH2F *ht1 = (TH2F*)s1->Get(tight);
	TH2F *ht2 = (TH2F*)s2->Get(tight);
	TH2F *ht3 = (TH2F*)s3->Get(tight);
	TH2F *ht4 = (TH2F*)s4->Get(tight);
	TH2F *ht5 = (TH2F*)s5->Get(tight);
	TH2F *ht6 = (TH2F*)s6->Get(tight);
	TH2F *ht7 = (TH2F*)s7->Get(tight);

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

	TCanvas *c = new TCanvas();

	c->SetGrid();
	ht->GetYaxis()->SetLabelSize(0.02);
	ht->GetXaxis()->SetLabelSize(0.02);
	ht->GetXaxis()->SetNdivisions(12);
	ht->GetYaxis()->SetNdivisions(25);
	gStyle->SetPaintTextFormat("4.2f");
  	ht->Draw("axis");
  	eff->Draw("text");


  	TLegend leg(0.65,0.80,0.895,0.89);
  	leg.SetLineColor(0);
  	leg.SetFillStyle(0);
  	leg.SetTextSize(0.05);
  	leg.SetShadowColor(0);

  	TString output = "Tight_v_loose_z_t_efficiency_" + type + "_SBT";
  	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(output+feps);
  	c->SaveAs(output+fpng);
  	c->SaveAs(output+fpdf);
}

void tight_v_loose_2d() {
	plot("diphoton");
	plot("singlephoton");
}