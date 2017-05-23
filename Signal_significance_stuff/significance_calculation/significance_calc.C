

double significance(double s, double b) {
	return sqrt(2*((s+b)*log(1+s/b)-s));
	// taken from eq 97 of https://arxiv.org/pdf/1007.1727v3.pdf	
}

void plot_sig_table(TString fname_s,TString fname_b,TString hname_s,TString hname_b,TString region,TString outfile,TString region_label,TString message, TString fname) {
	TFile *fs = TFile::Open(fname_s);
	TFile *fb = TFile::Open(fname_b);

	TH2F *hs = (TH2F*)fs->Get(hname_s);
	TH2F *hb = (TH2F*)fb->Get(hname_b);

	int nbinsx = hs->GetNbinsX();
	int nbinsy = hs->GetNbinsY();

	if (hb->GetNbinsX() != nbinsx || hb->GetNbinsY() != nbinsy) {
		cout << "TH2s don't have the same dimensions" << endl;
		return;
	}

	fname = fname+"_"+region;

	TH2F *sig = (TH2F*)hs->Clone();
	sig->SetNameTitle(fname,fname);

	double s = 0;

	for (int x = 1;  x <= nbinsx; x++) {
		for (int y = 1; y <= nbinsy; y++) {
			sig->SetBinContent(x,y,0);
			s = significance(hs->GetBinContent(x,y),hb->GetBinContent(x,y));
			if (hb->GetBinContent(x,y) == 0) continue;
			sig->SetBinContent(x,y,s);
		}
	}

	sig->GetYaxis()->SetRangeUser(0,nbinsy+1);

	/*
	sig->GetXaxis()->SetBinLabel(1,"t > 0 ns");
	sig->GetXaxis()->SetBinLabel(2,"t > 1 ns");
	sig->GetXaxis()->SetBinLabel(3,"t > 2 ns");
	sig->GetXaxis()->SetBinLabel(4,"t > 3 ns");
	sig->GetXaxis()->SetBinLabel(5,"t > 4 ns");
	sig->GetXaxis()->SetBinLabel(6,"t > 5 ns");
	sig->GetYaxis()->SetBinLabel(1,"0 < |Z_{DCA}| < 40 mm");
	sig->GetYaxis()->SetBinLabel(2,"40 < |Z_{DCA}| < 80 mm");
	sig->GetYaxis()->SetBinLabel(3,"80 < |Z_{DCA}| < 120 mm");
	sig->GetYaxis()->SetBinLabel(4,"120 < |Z_{DCA}| < 160 mm");
	sig->GetYaxis()->SetBinLabel(5,"160 < |Z_{DCA}| < 200 mm");
	sig->GetYaxis()->SetBinLabel(6,"200 < |Z_{DCA}| < 2000 mm");
	*/	
	
	sig->GetYaxis()->SetLabelSize(0.05);
	sig->GetXaxis()->SetLabelSize(0.05);
	sig->SetMarkerSize(1.5);

	gStyle->SetPaintTextFormat("4.3f");

	TCanvas * c = new TCanvas();
 	c->SetBottomMargin(0.2);
 	sig->Draw("text");

 	TLatex l;
 	l.SetNDC();
 	l.SetTextSize(0.04);
 	l.DrawLatex(0.55,0.90,message);
 	l.DrawLatex(0.55,0.85,region_label);

 	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(fname+feps);
  	c->SaveAs(fname+fpng);
  	c->SaveAs(fname+fpdf);


	TFile f(outfile,"recreate");
	sig->Write();
	f.Close();
}

void significance_calc() {
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
		fname.Form("significance_table_%i",runs[i]);
		plot_sig_table("../Signal_yield_th2/sig_yields_SR1.root","../Data_yield_th2s/estimated_data_bkg_yields_SR1.root",hname,"yields","SR1","significance_tables_SR1.root","SR1, Missing ET > 20 GeV",signal_info[runs[i]],fname);
		plot_sig_table("../Signal_yield_th2/sig_yields_SR2.root","../Data_yield_th2s/estimated_data_bkg_yields_SR2.root",hname,"yields","SR2","significance_tables_SR2.root","SR2, Missing ET > 70 GeV",signal_info[runs[i]],fname);
	}
}