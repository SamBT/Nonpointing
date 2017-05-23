void plot(TString rootfile, TString hname, TString signal_info, TString outfname) {
	TFile *f = TFile::Open(rootfile);
	TH2F *h = (TH2F*)f->Get(hname);

	h->GetXaxis()->SetTitle("p_{T} [GeV]");
	h->GetYaxis()->SetTitle("Missing E_{T} [GeV]");

	h->GetYaxis()->SetLabelSize(0.05);
	h->GetXaxis()->SetLabelSize(0.05);
	//h->SetMarkerSize(1);

	h->Sumw2();
	h->RebinX(4);
	h->RebinY(4);

	gStyle->SetPaintTextFormat("4.1f");

	TCanvas * c = new TCanvas();
 	c->SetBottomMargin(0.2);
 	h->Draw("box");

 	TLatex l;
 	l.SetNDC();
 	l.DrawLatex(0.2,0.9,signal_info);

 	TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  	c->SaveAs(outfname+feps);
  	c->SaveAs(outfname+fpng);
  	c->SaveAs(outfname+fpdf);

  	delete c;
}






void pt_met_plots() {
	vector<int> sig_runs = {403280,403281,403282,403283,403284,403285,403286};
	vector<vector<int>> sig_info = {{1000,900,100},{1300,100,6},{1300,1200,6},{1800,100,2},{1800,1700,2},{1800,100,6},{1800,1700,6}};
	TString fname, root, info;
	vector<int> tmp;

	for (int i = 0; i < sig_runs.size(); i++) {
		tmp = sig_info[i];
		fname.Form("diphoton_signal_pt_met_%i",sig_runs[i]);
		root.Form("/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/%i.root",sig_runs[i]);
		info.Form("m_{g} = %i, m_{#chi} = %i, #tau = %i",tmp[0],tmp[1],tmp[2]);
		plot(root, "h_pt_met",info,fname);
	}

}