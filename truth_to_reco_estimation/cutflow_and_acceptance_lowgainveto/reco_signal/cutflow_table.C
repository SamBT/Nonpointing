void cutflow_table(double dsid, int begin, int end) {
  ofstream t1, t2;
  TString t1_name = "cutflow_lowgainveto.tex";
  TString t2_name = "cutflow_unwt_lowgainveto.tex";
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
    t1 << " & & & & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 150$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau < 4$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau < 4$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 200$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 50$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau < 4$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} \\\\ \n";
    t1 << "\\hline \n";
    t2 << "\\documentclass[8pt]{extarticle}\n";
    t2 << "\\usepackage[a3paper, landscape, margin=0.1in]{geometry}\n";
    t2 << "\\usepackage{longtable}\n";
    t2 << "\\usepackage{multirow}\n";
    t2 << "\\begin{document}\n";
    t2 << "\\begin{longtable}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}" << endl;
    t2 << "\\hline \n";
    t2 << "$m_{\\tilde{g}}$ & $m_{\\tilde{\\chi}_1^0}$ & $\\tau_{\\tilde{\\chi}_1^0}$ & Total &\\multicolumn{12}{|c|}{Singlephoton} & \\multicolumn{9}{|c|}{Diphoton} \\\\ \n";
    t2 << "\\hline \n"; 
    t2 << " & & & & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 150$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau < 4$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau < 4$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 200$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} & Initial & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 50$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau < 4$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} \\\\ \n";
    t2 << "\\hline \n";
}
else if (end == 1) {
	t1 << "\\end{longtable} \n";
	t1 << "\\end{document} \n";
	t2 << "\\end{longtable} \n";
	t2 << "\\end{document} \n";
}
else {
  double dsid_test, mg, mx, tau;
  ifstream info("/global/homes/s/sambt/workarea/nonpointing/dsid_mg_mx_tau.txt");
  while (!info.eof()) {
    info >> dsid_test >> mg >> mx >> tau;
    if (dsid_test == dsid) break;
  }

  int dsid_int = (int)dsid;

  TString rootname;
  rootname.Form("output_%i.root",dsid_int);
  TFile *fs = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/reco_signal/combined/EXOT6/"+rootname);
  TFile *fd = TFile::Open("/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/reco_signal/combined/HIGG1D1/"+rootname);
  TH1F *hs = (TH1F*)fs->Get("h_CF_single");
  TH1F *hd = (TH1F*)fd->Get("h_CF_di");
  TH1F *hsn = (TH1F*)fs->Get("h_CF_unwt_single");
  TH1F *hdn = (TH1F*)fd->Get("h_CF_unwt_di");
  t1 << std::fixed << std::setprecision(0) << mg << "&" << mx << "&" << std::fixed << std::setprecision(1) << tau << "&" << std::fixed << std::setprecision(2) << hs->GetBinContent(1) << "&" << hs->GetBinContent(2) << "&" << hs->GetBinContent(3) << "&" << hs->GetBinContent(4) << "&" << hs->GetBinContent(5) << "&" << hs->GetBinContent(14) << "&" << hs->GetBinContent(15) << "&" << hs->GetBinContent(16) << "&" << hs->GetBinContent(17) << "&" << hs->GetBinContent(18) << "&" << hs->GetBinContent(19) << "&" << hs->GetBinContent(20) << "&" << hs->GetBinContent(21) << "&" << hd->GetBinContent(2) << "&" << hd->GetBinContent(3) << "&" << hd->GetBinContent(4) << "&" << hd->GetBinContent(5) << "&" << hd->GetBinContent(11) << "&" << hd->GetBinContent(12) << "&" << hd->GetBinContent(13) << "&" << hd->GetBinContent(14) << "&" << hd->GetBinContent(15) << "\\\\ \n";
  t1 << "\\hline \n";
  t2 << std::fixed << std::setprecision(0) << mg << "&" << mx << "&" << std::fixed << std::setprecision(1) << tau << "&" << std::fixed << std::setprecision(2) << hsn->GetBinContent(1) << "&" << hsn->GetBinContent(2) << "&" << hsn->GetBinContent(3) << "&" << hsn->GetBinContent(4) << "&" << hsn->GetBinContent(5) << "&" << hsn->GetBinContent(14) << "&" << hsn->GetBinContent(15) << "&" << hsn->GetBinContent(16) << "&" << hsn->GetBinContent(17) << "&" << hsn->GetBinContent(18) << "&" << hsn->GetBinContent(19) << "&" << hsn->GetBinContent(20) << "&" << hsn->GetBinContent(21) << "&" << hdn->GetBinContent(2) << "&" << hdn->GetBinContent(3) << "&" << hdn->GetBinContent(4) << "&" << hdn->GetBinContent(5) << "&" << hdn->GetBinContent(11) << "&" << hdn->GetBinContent(12) << "&" << hdn->GetBinContent(13) << "&" << hdn->GetBinContent(14) << "&" << hdn->GetBinContent(15) << "\\\\ \n";
  t2 << "\\hline \n";
  
  TString root, root_unwt, hnames, hnamed;
  root.Form("hist_%i.root",dsid_int);
  root_unwt.Form("hist_unwt_%i.root",dsid_int);
  for (int i = 1; i <= 25; i++) {
    TFile f1(root,"update");
    hnames.Form("hs%i",i);
    hnamed.Form("hd%i",i);
    TH2F *hss = (TH2F*)f1.Get(hnames);
    TH2F *hdd = (TH2F*)f1.Get(hnamed);
    TH2F *hss_acc = (TH2F*)f1.Get(hnames+"_acc");
    TH2F *hdd_acc = (TH2F*)f1.Get(hnamed+"_acc");
    hss->Fill(mg,mx,hs->GetBinContent(i));
    hdd->Fill(mg,mx,hd->GetBinContent(i));
    hss_acc->Fill(mg,mx,hs->GetBinContent(i)/hs->GetBinContent(1));
    hdd_acc->Fill(mg,mx,hd->GetBinContent(i)/hd->GetBinContent(1));
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
    hss2_acc->Fill(mg,mx,hsn->GetBinContent(i)/hsn->GetBinContent(1));
    hdd2_acc->Fill(mg,mx,hdn->GetBinContent(i)/hdn->GetBinContent(1));
    hss2->Write("",TObject::kOverwrite);
    hdd2->Write("",TObject::kOverwrite);
    hss2_acc->Write("",TObject::kOverwrite);
    hdd2_acc->Write("",TObject::kOverwrite);
    f2.Close();
  }
 }
  
}


  
