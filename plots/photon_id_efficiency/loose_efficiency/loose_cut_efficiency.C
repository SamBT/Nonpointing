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

	TString loose = "h_" + var + "_loose";
	TString reg = "h_" + var;
	TString ratio = "h_" + var + "_loose_eff";

	TH1F *ht1 = (TH1F*)s1->Get(loose);
	TH1F *ht2 = (TH1F*)s2->Get(loose);
	TH1F *ht3 = (TH1F*)s3->Get(loose);
	TH1F *ht4 = (TH1F*)s4->Get(loose);
	TH1F *ht5 = (TH1F*)s5->Get(loose);
	TH1F *ht6 = (TH1F*)s6->Get(loose);
	TH1F *ht7 = (TH1F*)s7->Get(loose);

	TH1F *hl1 = (TH1F*)s1->Get(reg);
	TH1F *hl2 = (TH1F*)s2->Get(reg);
	TH1F *hl3 = (TH1F*)s3->Get(reg);
	TH1F *hl4 = (TH1F*)s4->Get(reg);
	TH1F *hl5 = (TH1F*)s5->Get(reg);
	TH1F *hl6 = (TH1F*)s6->Get(reg);
	TH1F *hl7 = (TH1F*)s7->Get(reg);

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

	TH1F *hl = hl1;
	hl->Sumw2();
	hl->Add(hl2);
	hl->Add(hl3);
	hl->Add(hl4);
	hl->Add(hl5);
	hl->Add(hl6);
	hl->Add(hl7);

	
	TEfficiency *eff = eff1;
	eff->Add(*eff2);
	eff->Add(*eff3);
	eff->Add(*eff4);
	eff->Add(*eff5);
	eff->Add(*eff6);
	eff->Add(*eff7);

	if (var == "ZDCA") {
		ht->GetXaxis()->SetBinLabel(1,"0-20");
		ht->GetXaxis()->SetBinLabel(2,"20-40");
		ht->GetXaxis()->SetBinLabel(3,"40-60");
		ht->GetXaxis()->SetBinLabel(4,"60-80");
		ht->GetXaxis()->SetBinLabel(5,"80-100");
		ht->GetXaxis()->SetBinLabel(6,"100-120");
		ht->GetXaxis()->SetBinLabel(7,"120-140");
		ht->GetXaxis()->SetBinLabel(8,"140-160");
		ht->GetXaxis()->SetBinLabel(9,"160-180");
		ht->GetXaxis()->SetBinLabel(10,"180-200");
		ht->GetXaxis()->SetBinLabel(11,"200-800");
		ht->GetXaxis()->SetBinLabel(12,"800-1400");
		ht->GetXaxis()->SetBinLabel(13,"1400-2000");
		
		hl->GetXaxis()->SetBinLabel(1,"0-20");
		hl->GetXaxis()->SetBinLabel(2,"20-40");
		hl->GetXaxis()->SetBinLabel(3,"40-60");
		hl->GetXaxis()->SetBinLabel(4,"60-80");
		hl->GetXaxis()->SetBinLabel(5,"80-100");
		hl->GetXaxis()->SetBinLabel(6,"100-120");
		hl->GetXaxis()->SetBinLabel(7,"120-140");
		hl->GetXaxis()->SetBinLabel(8,"140-160");
		hl->GetXaxis()->SetBinLabel(9,"160-180");
		hl->GetXaxis()->SetBinLabel(10,"180-200");
		hl->GetXaxis()->SetBinLabel(11,"200-800");
		hl->GetXaxis()->SetBinLabel(12,"800-1400");
		hl->GetXaxis()->SetBinLabel(13,"1400-2000");
	}

	ht->GetYaxis()->SetTitle("Events");

	hl->SetLineColor(2);
	hl->SetMarkerColor(2);

	ht->GetYaxis()->SetRangeUser(0.1*ht->GetBinContent(ht->FindLastBinAbove(0)),100*ht->GetMaximum());
	hl->GetYaxis()->SetRangeUser(0.1*hl->GetBinContent(hl->FindLastBinAbove(0)),100*hl->GetMaximum());
	if (var == "timing") ht->GetXaxis()->SetRangeUser(-2,10);

	TCanvas *c = new TCanvas();
  	c->Divide(1,2);
  	c->SetBottomMargin(0.2);
  	c->cd(1);
  	c->GetPad(1)->SetLogy();
  	c->GetPad(1)->SetPad(0.,0.25,1.,1);

  	hl->Draw("histE");
  	ht->Draw("histEsame");


  	TLegend leg(0.65,0.80,0.895,0.89);
  	leg.SetLineColor(0);
  	leg.SetFillStyle(0);
  	leg.SetTextSize(0.05);
  	leg.SetShadowColor(0);
  	leg.AddEntry(ht,"Loose","L");
  	leg.AddEntry(hl,"All","L");
  	leg.Draw();

  	TLatex l;
  	l.SetNDC();
  	l.DrawLatex(0.65,0.75,type);
  	l.DrawLatex(0.65,0.70,"Loose Cut Efficiency");
  	ATLASLabel(0.65,0.65,"Internal");


  	c->cd(2);
  	c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  	c->GetPad(2)->SetBottomMargin(0.3);
  	c->GetPad(2)->SetGridy(1);

  	TH1F *test = (TH1F*)ht->Clone();
  	test->SetLineColor(0);

  	//test->GetYaxis()->SetRangeUser(0.95,1.05);
  	test->GetYaxis()->SetRangeUser(0,2);
  	if (var == "ZDCA") test->GetXaxis()->SetTitle("Z_{DCA} [mm]");
  	if (var == "timing") test->GetXaxis()->SetTitle("Timing [ns]");
  	test->GetYaxis()->SetTitle("Loose/All");
  	test->GetYaxis()->SetNdivisions(8);

  	test->GetXaxis()->SetLabelSize(0.15);
  	test->GetXaxis()->SetLabelOffset(0.015);
  	test->GetXaxis()->SetTitleSize(0.125);
  	test->GetXaxis()->SetTitleOffset(1.15);

  	test->GetYaxis()->SetLabelSize(0.1);
  	test->GetYaxis()->SetLabelOffset(0.01);
  	test->GetYaxis()->SetTitleSize(0.18);
  	test->GetYaxis()->SetTitleOffset(0.35);

  	test->Draw("hist");
  	eff->Draw("E0same");

  	TString output = "Loose_cut_" + var + "_" + type + "_efficiency_SBT";
  	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(output+feps);
  	c->SaveAs(output+fpng);
  	c->SaveAs(output+fpdf);
}

void loose_cut_efficiency() {
	plot("diphoton","ZDCA");
	plot("diphoton","timing");
	plot("singlephoton","ZDCA");
	plot("singlephoton","timing");
}