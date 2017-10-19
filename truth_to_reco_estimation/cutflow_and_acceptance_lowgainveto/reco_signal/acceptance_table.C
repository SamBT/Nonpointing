void acceptance_table() {
  ofstream t1, t2;
  TString t1_name = "acceptance_lowgainveto.tex";
  TString t2_name = "acceptance_unwt_lowgainveto.tex";
  t1.open(t1_name,std::ios_base::app);
  t2.open(t2_name,std::ios_base::app);

  t1 << "\\documentclass[8pt]{extarticle}\n";
  t1 << "\\usepackage[a3paper, landscape, margin=0.1in]{geometry}\n";
  t1 << "\\usepackage{longtable}\n";
  t1 << "\\usepackage{multirow}\n";
  t1 << "\\begin{document}\n";
  t1 << "\\begin{longtable}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}" << endl;
  t1 << "\\hline \n";
  t1 << "$m_{\\tilde{g}}$ & $m_{\\tilde{\\chi}_1^0}$ & $\\tau_{\\tilde{\\chi}_1^0}$ & \\multicolumn{11}{|c|}{Singlephoton} & \\multicolumn{8}{|c|}{Diphoton} \\\\ \n";
  t1 << "\\hline \n";
  t1 << " & & &  \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 150$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 200$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 50$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} \\\\ \n";
  t1 << "\\hline \n";
  t2 << "\\documentclass[8pt]{extarticle}\n";
  t2 << "\\usepackage[a3paper, landscape, margin=0.1in]{geometry}\n";
  t2 << "\\usepackage{longtable}\n";
  t2 << "\\usepackage{multirow}\n";
  t2 << "\\begin{document}\n";
  t2 << "\\begin{longtable}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}" << endl;
  t2 << "\\hline \n";
  t2 << "$m_{\\tilde{g}}$ & $m_{\\tilde{\\chi}_1^0}$ & $\\tau_{\\tilde{\\chi}_1^0}$ & \\multicolumn{11}{|c|}{Singlephoton} & \\multicolumn{8}{|c|}{Diphoton} \\\\ \n";
  t2 << "\\hline \n"; 
  t2 << " & & & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 150$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 1.5$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 200$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 200$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $p_T$ \\\\ $> 50$\\end{tabular} & Barrel & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $< 20$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss}$ \\\\ $> 75$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 1.5$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\end{tabular} & \\begin{tabular}{@{}c@{}} $E_T^{miss} > 75$ \\\\ $+ \\tau > 2$ \\\\ $+Z_{DCA} > 200$\\end{tabular} & \\begin{tabular}{@{}c@{}} $E_{T}^{miss} > 75$ \\\\ $+ 2 < \\tau < 4$ \\end{tabular} \\\\ \n";
  t2 << "\\hline \n";

  vector<int> dsids = {403280, 403281, 403282, 403283, 403284, 403285, 403286};

  for (int i = 0; i < dsids.size(); i++) {
    double mg, mx, tau, dsid_test;
    int dsid = dsids[i];
    int binx, biny;
    TString fname;
    fname.Form("hist_%i.root",dsid);
    TFile *f = TFile::Open(fname);
    TString fname_unwt;
    fname_unwt.Form("hist_unwt_%i.root",dsid);
    TFile *f1 = TFile::Open(fname_unwt);

    ifstream info("/global/homes/s/sambt/workarea/nonpointing/dsid_mg_mx_tau.txt");
    while (!info.eof()) {
      info >> dsid_test >> mg >> mx >> tau;
      if (dsid_test == dsid) break;
    }
    
    TH2F *hs2 = (TH2F*)f->Get("hs2_acc");
    TH2F *hs3 = (TH2F*)f->Get("hs3_acc");
    TH2F *hs4 = (TH2F*)f->Get("hs4_acc");
    TH2F *hs5 = (TH2F*)f->Get("hs5_acc");
    TH2F *hs6 = (TH2F*)f->Get("hs6_acc");
    TH2F *hs7 = (TH2F*)f->Get("hs7_acc");
    TH2F *hs8 = (TH2F*)f->Get("hs8_acc");
    TH2F *hs9 = (TH2F*)f->Get("hs9_acc");
    TH2F *hs10 = (TH2F*)f->Get("hs10_acc");
    TH2F *hs11 = (TH2F*)f->Get("hs11_acc");
    TH2F *hs12 = (TH2F*)f->Get("hs12_acc");
    TH2F *hs13 = (TH2F*)f->Get("hs13_acc");
    TH2F *hs14 = (TH2F*)f->Get("hs14_acc");
    TH2F *hs15 = (TH2F*)f->Get("hs15_acc");
    TH2F *hs16 = (TH2F*)f->Get("hs16_acc");
    TH2F *hs17 = (TH2F*)f->Get("hs17_acc");
    TH2F *hs18 = (TH2F*)f->Get("hs18_acc");
    TH2F *hs19 = (TH2F*)f->Get("hs19_acc");
    TH2F *hs20 = (TH2F*)f->Get("hs20_acc");
    TH2F *hs21 = (TH2F*)f->Get("hs21_acc");
    TH2F *hd2 = (TH2F*)f->Get("hd2_acc");
    TH2F *hd3 = (TH2F*)f->Get("hd3_acc");
    TH2F *hd4 = (TH2F*)f->Get("hd4_acc");
    TH2F *hd5 = (TH2F*)f->Get("hd5_acc");
    TH2F *hd6 = (TH2F*)f->Get("hd6_acc");
    TH2F *hd7 = (TH2F*)f->Get("hd7_acc");
    TH2F *hd8 = (TH2F*)f->Get("hd8_acc");
    TH2F *hd9 = (TH2F*)f->Get("hd9_acc");
    TH2F *hd10 = (TH2F*)f->Get("hd10_acc");
    TH2F *hd11 = (TH2F*)f->Get("hd11_acc");
    TH2F *hd12 = (TH2F*)f->Get("hd12_acc");
    TH2F *hd13 = (TH2F*)f->Get("hd13_acc");
    TH2F *hd14 = (TH2F*)f->Get("hd14_acc");
    TH2F *hd15 = (TH2F*)f->Get("hd15_acc");
    
    
    TH2F *hsn2 = (TH2F*)f->Get("hs2_acc");
    TH2F *hsn3 = (TH2F*)f->Get("hs3_acc");
    TH2F *hsn4 = (TH2F*)f->Get("hs4_acc");
    TH2F *hsn5 = (TH2F*)f->Get("hs5_acc");
    TH2F *hsn6 = (TH2F*)f->Get("hs6_acc");
    TH2F *hsn7 = (TH2F*)f->Get("hs7_acc");
    TH2F *hsn8 = (TH2F*)f->Get("hs8_acc");
    TH2F *hsn9 = (TH2F*)f->Get("hs9_acc");
    TH2F *hsn10 = (TH2F*)f->Get("hs10_acc");
    TH2F *hsn11 = (TH2F*)f->Get("hs11_acc");
    TH2F *hsn12 = (TH2F*)f->Get("hs12_acc");
    TH2F *hsn13 = (TH2F*)f->Get("hs13_acc");
    TH2F *hsn14 = (TH2F*)f->Get("hs14_acc");
    TH2F *hsn15 = (TH2F*)f->Get("hs15_acc");
    TH2F *hsn16 = (TH2F*)f->Get("hs16_acc");
    TH2F *hsn17 = (TH2F*)f->Get("hs17_acc");
    TH2F *hsn18 = (TH2F*)f->Get("hs18_acc");
    TH2F *hsn19 = (TH2F*)f->Get("hs19_acc");
    TH2F *hsn20 = (TH2F*)f->Get("hs20_acc");
    TH2F *hsn21 = (TH2F*)f->Get("hs21_acc");
    TH2F *hdn2 = (TH2F*)f->Get("hd2_acc");
    TH2F *hdn3 = (TH2F*)f->Get("hd3_acc");
    TH2F *hdn4 = (TH2F*)f->Get("hd4_acc");
    TH2F *hdn5 = (TH2F*)f->Get("hd5_acc");
    TH2F *hdn6 = (TH2F*)f->Get("hd6_acc");
    TH2F *hdn7 = (TH2F*)f->Get("hd7_acc");
    TH2F *hdn8 = (TH2F*)f->Get("hd8_acc");
    TH2F *hdn9 = (TH2F*)f->Get("hd9_acc");
    TH2F *hdn10 = (TH2F*)f->Get("hd10_acc");
    TH2F *hdn11 = (TH2F*)f->Get("hd11_acc");
    TH2F *hdn12 = (TH2F*)f->Get("hd12_acc");
    TH2F *hdn13 = (TH2F*)f->Get("hd13_acc");
    TH2F *hdn14 = (TH2F*)f->Get("hd14_acc");
    TH2F *hdn15 = (TH2F*)f->Get("hd15_acc");
    
    binx = ((mg-800)/100)+1;
    biny = ((mx-100)/100)+1;      
    
    t1 << std::fixed << std::setprecision(0) << mg << "&" << mx << "&" << std::fixed << std::setprecision(1) << tau << "&" << std::fixed << std::setprecision(3) << hs3->GetBinContent(binx,biny) << "&" << hs4->GetBinContent(binx,biny) << "&" << hs5->GetBinContent(binx,biny) << "&" << hs14->GetBinContent(binx,biny) << "&" << hs15->GetBinContent(binx,biny) << "&" << hs16->GetBinContent(binx,biny) << "&" << hs17->GetBinContent(binx,biny) << "&" << hs18->GetBinContent(binx,biny) << "&" << hs19->GetBinContent(binx,biny) << "&" << hs20->GetBinContent(binx,biny) << "&" << hs21->GetBinContent(binx,biny) << "&" << hd3->GetBinContent(binx,biny) << "&" << hd4->GetBinContent(binx,biny) << "&" << hd5->GetBinContent(binx,biny) << "&" << hd11->GetBinContent(binx,biny) << "&" << hd12->GetBinContent(binx,biny) << "&" << hd13->GetBinContent(binx,biny) << "&" << hd14->GetBinContent(binx,biny) << "&" << hd15->GetBinContent(binx,biny) << "\\\\ \n";
    t1 << "\\hline \n";
    t2 << std::fixed << std::setprecision(0) << mg << "&" << mx << "&" << std::fixed << std::setprecision(1) << tau << "&" << std::fixed << std::setprecision(3) << hsn3->GetBinContent(binx,biny) << "&" << hsn4->GetBinContent(binx,biny) << "&" << hsn5->GetBinContent(binx,biny) << "&" << hsn14->GetBinContent(binx,biny) << "&" << hsn15->GetBinContent(binx,biny) << "&" << hsn16->GetBinContent(binx,biny) << "&" << hsn17->GetBinContent(binx,biny) << "&" << hsn18->GetBinContent(binx,biny) << "&" << hsn19->GetBinContent(binx,biny) << "&" << hsn20->GetBinContent(binx,biny) << "&" << hsn21->GetBinContent(binx,biny) << "&" << hdn3->GetBinContent(binx,biny) << "&" << hdn4->GetBinContent(binx,biny) << "&" << hdn5->GetBinContent(binx,biny) << "&" << hdn11->GetBinContent(binx,biny) << "&" << hdn12->GetBinContent(binx,biny) << "&" << hdn13->GetBinContent(binx,biny) << "&" << hdn14->GetBinContent(binx,biny) << "&" << hdn15->GetBinContent(binx,biny) << "\\\\ \n";
    t2 << "\\hline \n";
  }
  
  t1 << "\\end{longtable} \n";
  t1 << "\\end{document} \n";
  t2 << "\\end{longtable} \n";
  t2 << "\\end{document} \n";
  
}

  
  
