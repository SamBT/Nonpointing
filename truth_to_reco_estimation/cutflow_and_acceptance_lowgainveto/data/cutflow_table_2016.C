void cutflow_table_2016(int begin, int end) {
  ofstream t1;
  TString t1_name = "cutflow_data16_lowgainveto.tex";
  t1.open(t1_name,std::ios_base::app);

  if (begin == 1) {
    t1 << "\\documentclass[10pt]{extarticle}\n";
    t1 << "\\usepackage[a3paper, landscape, margin=0.1in]{geometry}\n";
    t1 << "\\usepackage{longtable}\n";
    t1 << "\\usepackage{multirow}\n";
    t1 << "\\begin{document}\n";
    t1 << "\\begin{longtable}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}" << endl;
    t1 << "\\hline \n";
    t1 << "Run Number & Lumi ($pb^{-1}$) & \\multicolumn{8}{|c|}{Singlephoton} & \\multicolumn{8}{|c|}{Diphoton} \\\\ \n";
    t1 << "\\hline \n";
    t1 << " & & Total & Total/Lumi & Trigger/Lumi & $p_{T} > 150$ & Barrel & $E_{T}^{miss} < 20$ & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ \\tau < 4$ \\end{tabular} & Total & Total/Lumi & Trigger/Lumi & $p_{T} > 50$ & Barrel & $E_{T}^{miss} < 20$ & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ \\tau < 4$ \\end{tabular} \\\\ \n";
    t1 << "\\hline \n";
}
else if (end == 1) {
	t1 << "\\end{longtable} \n";
	t1 << "\\end{document} \n";
}
else {
  int run_num;
  double lumi, lumi_tot;
  lumi_tot = 0;
  TString hname;
  TFile *fs = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_EXOT6/output.root");
  TFile *fd = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/data16_HIGG1D1/output.root");
  ifstream info("runNum_lumi_16_tmp.txt");
  while (!info.eof()) {
    info >> run_num >> lumi;

    cout << "run = " <<run_num << endl;

    hname.Form("h_CF_%i",run_num);

    TH1F *hs = (TH1F*)fs->Get(hname);
    TH1F *hd = (TH1F*)fd->Get(hname);

    t1 << std::fixed << std::setprecision(0) << run_num << "&" << std::fixed << std::setprecision(2) << lumi << "&" << std::setprecision(0) << hs->GetBinContent(1) << "&" << std::setprecision(3) << hs->GetBinContent(1)/lumi << "&" << hs->GetBinContent(2)/lumi << "&" << std::fixed << std::setprecision(0) << hs->GetBinContent(3) << "&" << hs->GetBinContent(4) << "&" << hs->GetBinContent(5) << "&" << hs->GetBinContent(14) << "&" << hd->GetBinContent(1) << "&" << std::fixed << std::setprecision(3) << hd->GetBinContent(1)/lumi << "&" << hd->GetBinContent(2)/lumi << "&" << std::fixed << std::setprecision(0) << hd->GetBinContent(3) << "&" << hd->GetBinContent(4) << "&" << hd->GetBinContent(5) << "&" << hd->GetBinContent(11) << " \\\\ \n";
    t1 << "\\hline \n";
  }
 }
}


  
