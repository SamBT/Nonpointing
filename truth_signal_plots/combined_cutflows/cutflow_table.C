void cutflow_table(TString timing, TString file, double dsid, double tau, int begin, int end) {
  ofstream t1, t2;
  TString t1_name = "cutflow_"+timing+".tex";
  TString t2_name = "cutflow_unwt_"+timing+".tex";
  t1.open(t1_name,std::ios_base::app);
  t2.open(t2_name,std::ios_base::app);

  if (begin == 1) {
    t1 << "\\documentclass[8pt]{extarticle}\n";
    t1 << "\\usepackage[a3paper, landscape, margin=0.1in]{geometry}\n";
    t1 << "\\usepackage{longtable}\n";
    t1 << "\\usepackage{multirow}\n";
    t1 << "\\begin{document}\n";
    t1 << "\\begin{longtable}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}" << endl;
    t1 << "\\hline \n";
    t1 << "$m_{\\tilde{g}}$ & $m_{\\tilde{\\chi}_1^0}$ & $\\tau_{\\tilde{\\chi}_1^0}$ & Total & \\multicolumn{12}{|c|}{Singlephoton} & \\multicolumn{9}{|c|}{Diphoton} \\\\ \n";
    t1 << "\\hline \n";
    t1 << " & & & & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 150$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 200$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 50$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} \\\\ \n";
    t1 << "\\hline \n";
    t2 << "\\documentclass[8pt]{extarticle}\n";
    t2 << "\\usepackage[a3paper, landscape, margin=0.1in]{geometry}\n";
    t2 << "\\usepackage{longtable}\n";
    t2 << "\\usepackage{multirow}\n";
    t2 << "\\begin{document}\n";
    t2 << "\\begin{longtable}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}" << endl;
    t2 << "\\hline \n";
    t2 << "$m_{\\tilde{g}}$ & $m_{\\tilde{\\chi}_1^0}$ & $\\tau_{\\tilde{\\chi}_1^0}$ & Total & \\multicolumn{12}{|c|}{Singlephoton} & \\multicolumn{9}{|c|}{Diphoton} \\\\ \n";
    t2 << "\\hline \n"; 
    t2 << " & & & & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 150$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 200$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 50$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} \\\\ \n";
    t2 << "\\hline \n";
}
else if (end == 1) {
	t1 << "\\end{longtable} \n";
	t1 << "\\end{document} \n";
	t2 << "\\end{longtable} \n";
	t2 << "\\end{document} \n";
}
else {
	double mg, mx, thousands, hundreds, tens;
	int place, place2, number;
	place = (int)log10(dsid);
	number = (int)(dsid/pow(10,place));
	thousands = dsid - number*pow(10,place);
	place2 = (int)thousands/1000;
	hundreds = thousands - place2*1000;
	if ((int)(hundreds/100) == 0) {
		mg = 1000+place2*100;
		mx = hundreds*100;
	}
	if ((int)(hundreds/100) != 0) {
		mg = (int)(hundreds/100);
		mg = 100*mg;
		mx = (hundreds - mg)*100;
	}
	TFile *f = TFile::Open(file);
	TH1F *hs = (TH1F*)f->Get("h_CF_single");
	TH1F *hd = (TH1F*)f->Get("h_CF_di");
	TH1F *hsn = (TH1F*)f->Get("h_CF_unwt_single");
	TH1F *hdn = (TH1F*)f->Get("h_CF_unwt_di");
	t1 << std::fixed << std::setprecision(0) << mg << "&" << mx << "&" << std::fixed << std::setprecision(1) << tau << "&" << std::fixed << std::setprecision(2) << hs->GetBinContent(0) << "&" << hs->GetBinContent(2) << "&" << hs->GetBinContent(3) << "&" << hs->GetBinContent(4) << "&" << hs->GetBinContent(5) << "&" << hs->GetBinContent(6) << "&" << hs->GetBinContent(7) << "&" << hs->GetBinContent(8) << "&" << hs->GetBinContent(9) << "&" << hs->GetBinContent(10) << "&" << hs->GetBinContent(11) << "&" << hs->GetBinContent(12) << "&" << hs->GetBinContent(13) << "&" << hd->GetBinContent(2) << "&" << hd->GetBinContent(3) << "&" << hd->GetBinContent(4) << "&" << hd->GetBinContent(5) << "&" << hd->GetBinContent(6) << "&" << hd->GetBinContent(7) << "&" << hd->GetBinContent(8) << "&" << hd->GetBinContent(9) << "&" << hd->GetBinContent(10) << "\\\\ \n";
	t1 << "\\hline \n";
	t2 << std::fixed << std::setprecision(0) << mg << "&" << mx << "&" << std::fixed << std::setprecision(1) << tau << "&" << std::fixed << std::setprecision(2) << hsn->GetBinContent(0) << "&" << hsn->GetBinContent(2) << "&" << hsn->GetBinContent(3) << "&" << hsn->GetBinContent(4) << "&" << hsn->GetBinContent(5) << "&" << hsn->GetBinContent(6) << "&" << hsn->GetBinContent(7) << "&" << hsn->GetBinContent(8) << "&" << hsn->GetBinContent(9) << "&" << hsn->GetBinContent(10) << "&" << hsn->GetBinContent(11) << "&" << hsn->GetBinContent(12) << "&" << hsn->GetBinContent(13) << "&" << hdn->GetBinContent(2) << "&" << hdn->GetBinContent(3) << "&" << hdn->GetBinContent(4) << "&" << hdn->GetBinContent(5) << "&" << hdn->GetBinContent(6) << "&" << hdn->GetBinContent(7) << "&" << hdn->GetBinContent(8) << "&" << hdn->GetBinContent(9) << "&" << hdn->GetBinContent(10) << "\\\\ \n";
	t2 << "\\hline \n";

	TString root, root_unwt, hnames, hnamed;
	root = "hist_"+timing+".root";
	root_unwt = "hist_unwt_"+timing+".root";
	for (int i = 1; i <= 20; i++) {
	  TFile f1(root,"update");
	  hnames.Form("hs%i",i);
	  hnamed.Form("hd%i",i);
	  TH2F *hss = (TH2F*)f1.Get(hnames);
	  TH2F *hdd = (TH2F*)f1.Get(hnamed);
	  TH2F *hss_acc = (TH2F*)f1.Get(hnames+"_acc");
	  TH2F *hdd_acc = (TH2F*)f1.Get(hnamed+"_acc");
	  hss->Fill(mg,mx,hs->GetBinContent(i));
	  hdd->Fill(mg,mx,hd->GetBinContent(i));
	  hss_acc->Fill(mg,mx,hs->GetBinContent(i)/hs->GetBinContent(0));
	  hdd_acc->Fill(mg,mx,hd->GetBinContent(i)/hd->GetBinContent(0));
	  hss->Write("",TObject::kOverwrite);
	  hdd->Write("",TObject::kOverwrite);
	  hss_acc->Write("",TObject::kOverwrite);
	  hdd_acc->Write("",TObject::kOverwrite);
	  f1.Close();
	
	  TFile f2(root_unwt,"update");
	  TH2F *hss2 = (TH2F*)f2.Get(hnames);
	  TH2F *hdd2 = (TH2F*)f2.Get(hnamed);
	  TH2F *hss2_acc = (TH2F*)f2.Get(hnames+"_acc");
          TH2F *hdd2_acc = (TH2F*)f2.Get(hnamed+"_acc");
	  hss2->Fill(mg,mx,hsn->GetBinContent(i));
	  hdd2->Fill(mg,mx,hdn->GetBinContent(i));
	  hss2_acc->Fill(mg,mx,hsn->GetBinContent(i)/hsn->GetBinContent(0));
          hdd2_acc->Fill(mg,mx,hdn->GetBinContent(i)/hdn->GetBinContent(0));
	  hss2->Write("",TObject::kOverwrite);
	  hdd2->Write("",TObject::kOverwrite);
	  hss2_acc->Write("",TObject::kOverwrite);
          hdd2_acc->Write("",TObject::kOverwrite);
	  f2.Close();
	}
}

}

  
  
