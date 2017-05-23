void create_rootfile_CR() {
	TFile *f1 = TFile::Open("../output_data.root");

	TH2F *h1 = (TH2F*)f1->Get("h_timing_zdca_yields_CR");

	h1->SetNameTitle("yields","yields");

	TFile f("data_yields_CR.root","recreate");
	h1->Write();
	f.Close();
}

void plot_CR(TString hname, TString fname, TString region, TString region_label, TString rootfile, TString message) {
	TFile *f = TFile::Open(rootfile);
	TH2F *h = (TH2F*)f->Get(hname);
	/*
	h->GetXaxis()->SetBinLabel(1,"t > 0 ns");
	h->GetXaxis()->SetBinLabel(2,"t > 1 ns");
	h->GetXaxis()->SetBinLabel(3,"t > 2 ns");
	h->GetXaxis()->SetBinLabel(4,"t > 3 ns");
	h->GetXaxis()->SetBinLabel(5,"t > 4 ns");
	h->GetXaxis()->SetBinLabel(6,"t > 5 ns");
	h->GetYaxis()->SetBinLabel(1,"0 < |Z_{DCA}| < 40 mm");
	h->GetYaxis()->SetBinLabel(2,"40 < |Z_{DCA}| < 80 mm");
	h->GetYaxis()->SetBinLabel(3,"80 < |Z_{DCA}| < 120 mm");
	h->GetYaxis()->SetBinLabel(4,"120 < |Z_{DCA}| < 160 mm");
	h->GetYaxis()->SetBinLabel(5,"160 < |Z_{DCA}| < 200 mm");
	h->GetYaxis()->SetBinLabel(6,"200 < |Z_{DCA}| < 2000 mm");
	*/
	h->GetYaxis()->SetRangeUser(0,7);


	h->GetYaxis()->SetLabelSize(0.035);
	h->GetXaxis()->SetLabelSize(0.05);
	h->SetMarkerSize(1.5);

	double lumi_scale = 35/3.2;

	h->Scale(lumi_scale);

	gStyle->SetPaintTextFormat("4.2f");

	TCanvas * c = new TCanvas();
 	c->SetBottomMargin(0.2);
 	h->Draw("text");

 	TLatex l;
 	l.SetNDC();
 	l.SetTextSize(0.04);
 	l.DrawLatex(0.55,0.90,message);
 	l.DrawLatex(0.55,0.85,region_label);

 	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(fname+"_"+region+feps);
  	c->SaveAs(fname+"_"+region+fpng);
  	c->SaveAs(fname+"_"+region+fpdf);

  	delete c;

}

void plot_SR(TString hname, TString fname, TString region, TString region_label, TString rootfile, TString message) {
	TFile *f = TFile::Open(rootfile);
	TFile *g = TFile::Open("../output_data.root");
	TH2F *h = (TH2F*)f->Get(hname);
	/*
	h->GetXaxis()->SetBinLabel(1,"t > 0 ns");
	h->GetXaxis()->SetBinLabel(2,"t > 1 ns");
	h->GetXaxis()->SetBinLabel(3,"t > 2 ns");
	h->GetXaxis()->SetBinLabel(4,"t > 3 ns");
	h->GetXaxis()->SetBinLabel(5,"t > 4 ns");
	h->GetXaxis()->SetBinLabel(6,"t > 5 ns");
	h->GetYaxis()->SetBinLabel(1,"0 < |Z_{DCA}| < 40 mm");
	h->GetYaxis()->SetBinLabel(2,"40 < |Z_{DCA}| < 80 mm");
	h->GetYaxis()->SetBinLabel(3,"80 < |Z_{DCA}| < 120 mm");
	h->GetYaxis()->SetBinLabel(4,"120 < |Z_{DCA}| < 160 mm");
	h->GetYaxis()->SetBinLabel(5,"160 < |Z_{DCA}| < 200 mm");
	h->GetYaxis()->SetBinLabel(6,"200 < |Z_{DCA}| < 2000 mm");
	*/

	h->GetYaxis()->SetRangeUser(0,7);

	TH1F *cf = (TH1F*)g->Get("h_CF");
	double nevents_SR = 0;
	double nevents_CR = 0;

	//Get number of events in desired signal region (SR1 or SR2) and from control regions
	if (region == "SR1") nevents_SR = cf->GetBinContent(3);
	if (region == "SR2") nevents_SR = cf->GetBinContent(4);
	nevents_CR = cf->GetBinContent(2);

	double scale = nevents_SR/nevents_CR;
	double lumi_scale = 35/3.2;

	h->Scale(lumi_scale);
	h->Scale(scale);

	h->GetYaxis()->SetLabelSize(0.035);
	h->GetXaxis()->SetLabelSize(0.05);
	h->SetMarkerSize(1.5);

	gStyle->SetPaintTextFormat("4.2f");

	TCanvas * c = new TCanvas();
 	c->SetBottomMargin(0.2);
 	h->Draw("text");

 	TLatex l;
 	l.SetNDC();
 	l.SetTextSize(0.04);
 	l.DrawLatex(0.55,0.90,message);
 	l.DrawLatex(0.55,0.85,region_label);

 	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(fname+"_"+region+feps);
  	c->SaveAs(fname+"_"+region+fpng);
  	c->SaveAs(fname+"_"+region+fpdf);

  	delete c;

  	TFile f1("estimated_data_bkg_yields_"+region+".root","recreate");
	h->Write();
	f1.Close();

}

void plot_yields() {
	plot_CR("yields","data_yield_table","CR","CR, Missing E_{T} < 20 GeV","data_yields_CR.root","Data 2015, Normalized to 35 fb^{-1}");
	plot_SR("yields","est_bkg_yield_table","SR1","SR1, Missing E_{T} > 20 GeV","data_yields_CR.root","Data 2015, Normalized to 35 fb^{-1}");
	plot_SR("yields","est_bkg_yield_table","SR2","SR2, Missing E_{T} > 70 GeV","data_yields_CR.root","Data 2015, Normalized to 35 fb^{-1}");
}

void CR_yields_SR_estimations() {
	create_rootfile_CR();
	plot_yields();
}