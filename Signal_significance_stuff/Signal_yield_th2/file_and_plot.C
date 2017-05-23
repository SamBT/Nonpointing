void create_rootfile_CR() {
	TFile *f1 = TFile::Open("../sig_403280.root");
	TFile *f2 = TFile::Open("../sig_403281.root");
	TFile *f3 = TFile::Open("../sig_403282.root");
	TFile *f4 = TFile::Open("../sig_403283.root");
	TFile *f5 = TFile::Open("../sig_403284.root");
	TFile *f6 = TFile::Open("../sig_403286.root");

	TH2F *h1 = (TH2F*)f1->Get("h_timing_zdca_yields_CR");
	TH2F *h2 = (TH2F*)f2->Get("h_timing_zdca_yields_CR");
	TH2F *h3 = (TH2F*)f3->Get("h_timing_zdca_yields_CR");
	TH2F *h4 = (TH2F*)f4->Get("h_timing_zdca_yields_CR");
	TH2F *h5 = (TH2F*)f5->Get("h_timing_zdca_yields_CR");
	TH2F *h6 = (TH2F*)f6->Get("h_timing_zdca_yields_CR");

	h1->SetNameTitle("yields_403280","yields_403280");
	h2->SetNameTitle("yields_403281","yields_403281");
	h3->SetNameTitle("yields_403282","yields_403282");
	h4->SetNameTitle("yields_403283","yields_403283");
	h5->SetNameTitle("yields_403284","yields_403284");
	h6->SetNameTitle("yields_403286","yields_403286");

	TFile f("sig_yields_CR.root","recreate");
	h1->Write();
	h2->Write();
	h3->Write();
	h4->Write();
	h5->Write();
	h6->Write();
	f.Close();
}

void create_rootfile_SR1() {
	TFile *f1 = TFile::Open("../sig_403280.root");
	TFile *f2 = TFile::Open("../sig_403281.root");
	TFile *f3 = TFile::Open("../sig_403282.root");
	TFile *f4 = TFile::Open("../sig_403283.root");
	TFile *f5 = TFile::Open("../sig_403284.root");
	TFile *f6 = TFile::Open("../sig_403286.root");

	TH2F *h1 = (TH2F*)f1->Get("h_timing_zdca_yields_SR1");
	TH2F *h2 = (TH2F*)f2->Get("h_timing_zdca_yields_SR1");
	TH2F *h3 = (TH2F*)f3->Get("h_timing_zdca_yields_SR1");
	TH2F *h4 = (TH2F*)f4->Get("h_timing_zdca_yields_SR1");
	TH2F *h5 = (TH2F*)f5->Get("h_timing_zdca_yields_SR1");
	TH2F *h6 = (TH2F*)f6->Get("h_timing_zdca_yields_SR1");

	h1->SetNameTitle("yields_403280","yields_403280");
	h2->SetNameTitle("yields_403281","yields_403281");
	h3->SetNameTitle("yields_403282","yields_403282");
	h4->SetNameTitle("yields_403283","yields_403283");
	h5->SetNameTitle("yields_403284","yields_403284");
	h6->SetNameTitle("yields_403286","yields_403286");

	TFile f("sig_yields_SR1.root","recreate");
	h1->Write();
	h2->Write();
	h3->Write();
	h4->Write();
	h5->Write();
	h6->Write();
	f.Close();
}

void create_rootfile_SR2() {
	TFile *f1 = TFile::Open("../sig_403280.root");
	TFile *f2 = TFile::Open("../sig_403281.root");
	TFile *f3 = TFile::Open("../sig_403282.root");
	TFile *f4 = TFile::Open("../sig_403283.root");
	TFile *f5 = TFile::Open("../sig_403284.root");
	TFile *f6 = TFile::Open("../sig_403286.root");

	TH2F *h1 = (TH2F*)f1->Get("h_timing_zdca_yields_SR2");
	TH2F *h2 = (TH2F*)f2->Get("h_timing_zdca_yields_SR2");
	TH2F *h3 = (TH2F*)f3->Get("h_timing_zdca_yields_SR2");
	TH2F *h4 = (TH2F*)f4->Get("h_timing_zdca_yields_SR2");
	TH2F *h5 = (TH2F*)f5->Get("h_timing_zdca_yields_SR2");
	TH2F *h6 = (TH2F*)f6->Get("h_timing_zdca_yields_SR2");

	h1->SetNameTitle("yields_403280","yields_403280");
	h2->SetNameTitle("yields_403281","yields_403281");
	h3->SetNameTitle("yields_403282","yields_403282");
	h4->SetNameTitle("yields_403283","yields_403283");
	h5->SetNameTitle("yields_403284","yields_403284");
	h6->SetNameTitle("yields_403286","yields_403286");

	TFile f("sig_yields_SR2.root","recreate");
	h1->Write();
	h2->Write();
	h3->Write();
	h4->Write();
	h5->Write();
	h6->Write();
	f.Close();
}

void plot(TString hname, TString fname, TString region, TString region_label, TString rootfile, TString message) {
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

	h->GetYaxis()->SetLabelSize(0.05);
	h->GetXaxis()->SetLabelSize(0.05);
	h->SetMarkerSize(1.5);

	gStyle->SetPaintTextFormat("4.3f");

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

void plot_yields() {
	int runs[] = {403280,403281,403282,403283,403284,403286};
	int size = sizeof(runs)/sizeof(*runs);
	TString hname;
	TString fname;

	map<int,TString> signal_info;
	signal_info[403280] = "m_{g} = 1000, m_{b} = 900, t = 100 ns";
	signal_info[403281] = "m_{g} = 1300, m_{b} = 100, t = 6 ns";
	signal_info[403282] = "m_{g} = 1300, m_{b} = 1200, t = 6 ns";
	signal_info[403283] = "m_{g} = 1800, m_{b} = 100, t = 2 ns";
	signal_info[403284] = "m_{g} = 1800, m_{b} = 1700, t = 2 ns";
	signal_info[403286] = "m_{g} = 1800, m_{b} = 1700, t = 6 ns";


	for (int i = 0; i < size; i++) {
		hname.Form("yields_%i",runs[i]);
		fname.Form("yield_table_%i",runs[i]);
		plot(hname,fname,"CR","CR, Missing E_{T} < 20 GeV","sig_yields_CR.root",signal_info[runs[i]]);
		plot(hname,fname,"SR1","SR1, Missing E_{T} > 20 GeV","sig_yields_SR1.root",signal_info[runs[i]]);
		plot(hname,fname,"SR2","SR2, Missing E_{T} > 70 GeV","sig_yields_SR2.root",signal_info[runs[i]]);
	}
}

void file_and_plot() {
	create_rootfile_CR();
	create_rootfile_SR1();
	create_rootfile_SR2();
	plot_yields();
}
