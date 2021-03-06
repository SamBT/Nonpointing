#include "AtlasLabels.h"
#include "AtlasLabels.C"
void plot(TString type, TString var) {
	TString path = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/" + type;
	TFile *s1 = TFile::Open(path+"/gammagamma_prompt/gammagamma_prompt.root");

	TString tight = "h_" + var + "_tight";
	TString loose = "h_" + var + "_loose";
	TString ratio = "h_" + var + "_tight_eff";

	TH1F *ht1 = (TH1F*)s1->Get(tight);

	TH1F *hl1 = (TH1F*)s1->Get(loose);

	TEfficiency *eff1 = (TEfficiency*)s1->Get(ratio);

	TH1F *cf1 = (TH1F*)s1->Get("h_CF");

	TH1F *cf = cf1;

	cout << "Total loose ID photons, " << type <<", = " << cf->GetBinContent(7) << endl;
	cout << "Initial photons, " << type << ", = " << cf->GetBinContent(8) << endl;

	TH1F *ht = ht1;
	ht->Sumw2();

	TH1F *hl = hl1;
	hl->Sumw2();
	
	TEfficiency *eff = eff1;

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
  	leg.AddEntry(ht,"Tight","L");
  	leg.AddEntry(hl,"Loose","L");
  	leg.Draw();

  	TLatex l;
  	l.SetNDC();
  	l.DrawLatex(0.65,0.75,type);
  	l.DrawLatex(0.65,0.70,"Tight Cut Efficiency");
  	ATLASLabel(0.65,0.65,"Internal");

  	c->cd(2);
  	c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  	c->GetPad(2)->SetBottomMargin(0.3);
  	c->GetPad(2)->SetGridy(1);

  	TH1F *test = (TH1F*)ht->Clone();
  	test->Reset();
  	test->SetLineColor(0);

  	test->GetYaxis()->SetRangeUser(eff->GetEfficiency(eff->GetGlobalBin(1))-0.1,eff->GetEfficiency(eff->GetGlobalBin(1))+0.1);
  	//if (var == "ZDCA") test->GetYaxis()->SetRangeUser(0,2);
  	if (var == "ZDCA") test->GetXaxis()->SetTitle("Z_{DCA} [mm]");
  	if (var == "timing") test->GetXaxis()->SetTitle("Timing [ns]");
  	test->GetYaxis()->SetTitle("Tight/Loose");
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

  	TString output = "Tight_vs_loose_" + var + "_" + type;
  	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(output+feps);
  	c->SaveAs(output+fpng);
  	c->SaveAs(output+fpdf);
}

void tight_v_loose() {
	plot("diphoton","ZDCA");
	plot("diphoton","timing");
	plot("singlephoton","ZDCA");
	plot("singlephoton","timing");
}