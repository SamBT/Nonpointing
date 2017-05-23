void plot(TString rootfile, int run, int isdata) {
	TFile *f = TFile::Open(rootfile);
	TString line;

	TH1F *h_CF = (TH1F*)f->Get("h_CF");

	ofstream ltx;
	ltx.open("diphoton.txt",std::ios_base::app);
	if (!isdata) {
		line.Form("%i & %4.1f & %4.1f & %4.1f & %4.1f & %4.1f & %4.1f \\\\ \n", run, h_CF->GetBinContent(1), h_CF->GetBinContent(2), h_CF->GetBinContent(3), h_CF->GetBinContent(4), h_CF->GetBinContent(5), h_CF->GetBinContent(6));
		ltx << line;
		ltx.close();
	}
	else {
		line.Form("Data 2015, 3.2fb^{-1} & %4.1f & %4.1f & %4.1f & %4.1f & %4.1f & %4.1f \\\\ \n", h_CF->GetBinContent(1), h_CF->GetBinContent(2), h_CF->GetBinContent(3), h_CF->GetBinContent(4), h_CF->GetBinContent(5), h_CF->GetBinContent(6));
		ltx << line;
		ltx.close();
	}

}

void cutflow_table_latex() {
	vector<TString> sig_runs = {"403280","403281","403282","403283","403284","403285","403286"};
	vector<int> runs = {403280,403281,403282,403283,403284,403285,403286};
	TString fname;
	TString data = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/data/output_data.root";
	TString sig = "/global/homes/s/sambt/workarea/nonpointing/analysis_output/diphoton/signal/";

	ofstream file1, file2;
	file1.open("diphoton.txt");
	file1 << "\\begin{tabular}{c|c|c|c|c|c|c} \n";
	file1 << "Run & Trigger & pt & Isolation & met & Barrel & CR \\\\ \n";
	file1 << "\\hline \n";
	file1.close();

	for (int i = 0; i < sig_runs.size(); i++) {
		fname = sig + sig_runs[i] + ".root";
		plot(fname,runs[i],0);
	}
	plot(data,1,1);
	
	file1.open("diphoton.txt",std::ios_base::app);
	file1 << "\\end{tabular} \n";
	file1.close();

}