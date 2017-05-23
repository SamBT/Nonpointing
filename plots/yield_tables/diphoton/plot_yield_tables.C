void plot(TString hname, TString fname, TString region, TString rootfile) {
	TFile *f = TFile::Open(rootfile);
	TH2F *h = (TH2F*)f->Get(hname);
	
	h->GetXaxis()->SetBinLabel(1,"-4 - 0.5");
	h->GetXaxis()->SetBinLabel(2,"0.5 - 1.1");
	h->GetXaxis()->SetBinLabel(3,"1.1 - 1.3");
	h->GetXaxis()->SetBinLabel(4,"1.3 - 1.5");
	h->GetXaxis()->SetBinLabel(5,"1.5 - 1.8");
	h->GetXaxis()->SetBinLabel(6,"1.8 - ");
	h->GetYaxis()->SetBinLabel(1,"0 - 40");
	h->GetYaxis()->SetBinLabel(2,"40 - 80");
	h->GetYaxis()->SetBinLabel(3,"80 - 120");
	h->GetYaxis()->SetBinLabel(4,"120 - 160");
	h->GetYaxis()->SetBinLabel(5,"160 - 200");
	h->GetYaxis()->SetBinLabel(6,"200- ");
	
	h->GetXaxis()->SetTitle("t_{#gamma} [ns]");
	h->GetYaxis()->SetTitle("|Z_{DCA}| [mm]");

	h->GetYaxis()->SetRangeUser(0,7);

	h->GetYaxis()->SetLabelSize(0.05);
	h->GetXaxis()->SetLabelSize(0.05);
	h->SetMarkerSize(1.5);

	double wt = 1;

	TH1F *cf = (TH1F*)f->Get("h_CF");

	double n_SR = cf->GetBinContent(5);
	double n_CR = cf->GetBinContent(6);

	if (region == "SR") {
		wt = 35/3.2;
	}
	h->Scale(wt);

	TString message;
	if (region == "SR") message = "Projected yields in SR, Data 2015 Scaled to 35fb^{-1}";
	if (region == "CR") message = "Yields in CR, Data 2015 3.2fb^{-1}";

	gStyle->SetPaintTextFormat("4.1f");

	TCanvas * c = new TCanvas();
 	c->SetBottomMargin(0.2);
 	h->Draw("text");

 	TLatex l;
 	l.SetNDC();
 	l.DrawLatex(0.2,0.9,message);

 	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(fname+"_"+region+feps);
  	c->SaveAs(fname+"_"+region+fpng);
  	c->SaveAs(fname+"_"+region+fpdf);

  	delete c;

}

void plot_yield_tables() {
	vector<int> sig_runs = {403280,403281,403282,403283,403284,403285,403286};
	TString fname;
	TString data_di = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/data/output_data.root";

	plot("h_yield","data_projected_diphoton","SR",data_di);
	plot("h_yield_raw","data_diphoton","CR",data_di);

}