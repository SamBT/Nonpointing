void scale_factor_grid() {

  TH2F *scales_diphoton = new TH2F("scales_diphoton","scales_diphoton",13,800,2100,20,100,2100);
  TH2F *scales_singlephoton = new TH2F("scales_singlephoton","scales_singlephoton",13,800,2100,20,100,2100);

  double scale;
  int mg, mx, mglast, mxlast;
  mglast = 0; mxlast = 0;
  
  ifstream fd("output_diphoton_6ns_interpolated.txt");
  while (!fd.eof()) {
    fd >> mg >> mx >> scale;
    if (mg == mglast && mx == mxlast) break;
    scales_diphoton->Fill(mg,mx,scale);
    mglast = mg;
    mxlast = mx;
  }

  mglast = 0; mxlast = 0;

  ifstream fs("output_singlephoton_6ns_interpolated.txt");
  while (!fs.eof()) {
    fs >> mg >> mx >> scale;
    if (mg == mglast && mx == mxlast) break;
    scales_singlephoton->Fill(mg,mx,scale);
    mglast = mg;
    mxlast = mx;
  }

  scales_diphoton->GetXaxis()->SetRangeUser(750,2150);
  scales_diphoton->GetYaxis()->SetRangeUser(50,2150);
  scales_singlephoton->GetXaxis()->SetRangeUser(750,2150);
  scales_singlephoton->GetYaxis()->SetRangeUser(50,2150);

  gStyle->SetPaintTextFormat("4.3f");

  TCanvas *c1 = new TCanvas();
  scales_diphoton->SetMarkerSize(1.3);
  scales_diphoton->Draw("text45");
  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.2,0.9,"Diphoton Reco/Truth Acceptance Ratios");
  l.DrawLatex(0.2,0.8,"#tau = 6ns");
  c1->SaveAs("diphoton_reco_truth_acceptance_ratios.png");
  c1->SaveAs("diphoton_reco_truth_acceptance_ratios.pdf");
  c1->SaveAs("diphoton_reco_truth_acceptance_ratios.eps");
  c1->SaveAs("diphoton_reco_truth_acceptance_ratios.C");

  TCanvas *c2 =new TCanvas();
  scales_singlephoton->SetMarkerSize(1.3);
  scales_singlephoton->Draw("text45");
  l.SetNDC();
  l.DrawLatex(0.2,0.9,"Singlephoton Reco/Truth Acceptance Ratios");
  l.DrawLatex(0.2,0.8,"#tau = 6ns");
  c2->SaveAs("singlephoton_reco_truth_acceptance_ratios.png");
  c2->SaveAs("singlephoton_reco_truth_acceptance_ratios.pdf");
  c2->SaveAs("singlephoton_reco_truth_acceptance_ratios.eps");
  c2->SaveAs("singlephoton_reco_truth_acceptance_ratios.C");

  TCanvas *c3 = new TCanvas();
  scales_diphoton->SetMarkerSize(1);
  scales_diphoton->Draw("box");
  l.SetNDC();
  l.DrawLatex(0.2,0.9,"Diphoton Reco/Truth Acceptance Ratios");
  l.DrawLatex(0.2,0.8,"#tau = 6ns");
  c3->SaveAs("diphoton_reco_truth_acceptance_ratios_box.png");
  c3->SaveAs("diphoton_reco_truth_acceptance_ratios_box.pdf");
  c3->SaveAs("diphoton_reco_truth_acceptance_ratios_box.eps");
  c3->SaveAs("diphoton_reco_truth_acceptance_ratios_box.C");

  TCanvas *c4 =new TCanvas();
  scales_singlephoton->SetMarkerSize(1);
  scales_singlephoton->Draw("box");
  l.SetNDC();
  l.DrawLatex(0.2,0.9,"Singlephoton Reco/Truth Acceptance Ratios");
  l.DrawLatex(0.2,0.8,"#tau = 6ns");
  c4->SaveAs("singlephoton_reco_truth_acceptance_ratios_box.png");
  c4->SaveAs("singlephoton_reco_truth_acceptance_ratios_box.pdf");
  c4->SaveAs("singlephoton_reco_truth_acceptance_ratios_box.eps");
  c4->SaveAs("singlephoton_reco_truth_acceptance_ratios_box.C");
}
