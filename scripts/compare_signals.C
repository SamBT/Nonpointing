void plot( TString hname, TString filename, TString xtitle, TString ytitle, TString message, double xmin = 0 , double xmax = 1, int rebin = 1)
{

  TFile* f1 = TFile::Open("sig_403280.root");
  TFile *f2 = TFile::Open("sig_403281.root");
  TFile *f3 = TFile::Open("sig_403282.root");
  TFile *f4 = TFile::Open("sig_403283.root");
  TFile *f5 = TFile::Open("sig_403284.root");
  TFile *f6 = TFile::Open("sig_403286.root");

  TH1F* h1 = (TH1F*)f1->Get(hname);
  TH1F* h2 = (TH1F*)f2->Get(hname);
  TH1F* h3 = (TH1F*)f3->Get(hname);
  TH1F* h4 = (TH1F*)f4->Get(hname);
  TH1F* h5 = (TH1F*)f5->Get(hname);
  TH1F* h6 = (TH1F*)f6->Get(hname);

  h1->Sumw2();
  h2->Sumw2();
  h3->Sumw2();
  h4->Sumw2();
  h5->Sumw2();
  h6->Sumw2();

  if(rebin !=1 ){

    h1->Rebin(rebin);
    h2->Rebin(rebin);
    h3->Rebin(rebin);
    h4->Rebin(rebin);
    h5->Rebin(rebin);
    h6->Rebin(rebin);
  }

  if (h1->Integral() != 0) h1->Scale(1/h1->Integral());
  if (h2->Integral() != 0) h2->Scale(1/h2->Integral());
  if (h3->Integral() != 0) h3->Scale(1/h3->Integral());
  if (h4->Integral() != 0) h4->Scale(1/h4->Integral());
  if (h5->Integral() != 0) h5->Scale(1/h5->Integral());
  if (h6->Integral() != 0) h6->Scale(1/h6->Integral());

  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(3);
  h4->SetLineColor(4);
  h5->SetLineColor(5);
  h6->SetLineColor(6);

  h1->SetMarkerColor(1);
  h2->SetMarkerColor(2);
  h3->SetMarkerColor(3);
  h4->SetMarkerColor(4);
  h5->SetMarkerColor(5);
  h6->SetMarkerColor(6);

  h1->SetLineStyle(1);
  h2->SetLineStyle(2);
  h3->SetLineStyle(3);
  h4->SetLineStyle(4);
  h5->SetLineStyle(5);
  h6->SetLineStyle(6);

  TCanvas * c =new TCanvas();
  c->Divide(1,2);
  c->SetBottomMargin(0.2);
  c->cd(1);
  c->GetPad(1)->SetLogy();
  c->GetPad(1)->SetPad(0.,0.25,1.,1);

  double ymax = 0;
  if (h1->GetMaximum() > ymax) ymax = h1->GetMaximum();
  if (h2->GetMaximum() > ymax) ymax = h2->GetMaximum();
  if (h3->GetMaximum() > ymax) ymax = h3->GetMaximum();
  if (h4->GetMaximum() > ymax) ymax = h4->GetMaximum();
  if (h5->GetMaximum() > ymax) ymax = h5->GetMaximum();
  if (h6->GetMaximum() > ymax) ymax = h6->GetMaximum();

  double ymin = 1000;
  if (h1->GetBinContent(h1->FindFirstBinAbove(0)) < ymin) ymin = h1->GetBinContent(h1->FindFirstBinAbove(0));
  if (h2->GetBinContent(h2->FindFirstBinAbove(0)) < ymin) ymin = h2->GetBinContent(h2->FindFirstBinAbove(0));
  if (h3->GetBinContent(h3->FindFirstBinAbove(0)) < ymin) ymin = h3->GetBinContent(h3->FindFirstBinAbove(0));
  if (h4->GetBinContent(h4->FindFirstBinAbove(0)) < ymin) ymin = h4->GetBinContent(h4->FindFirstBinAbove(0));
  if (h5->GetBinContent(h5->FindFirstBinAbove(0)) < ymin) ymin = h5->GetBinContent(h5->FindFirstBinAbove(0));
  if (h6->GetBinContent(h6->FindFirstBinAbove(0)) < ymin) ymin = h6->GetBinContent(h6->FindFirstBinAbove(0));

  cout << "ymin = " << ymin << endl;



  h1->GetXaxis()->SetRangeUser(xmin,xmax);
  h1->GetYaxis()->SetRangeUser(ymin,ymax*50);

  //  c->GetPad(1)->SetLogy(0);

  h1->GetYaxis()->SetTitle(ytitle);

  h1->GetYaxis()->SetLabelSize(0.07);
  h1->GetYaxis()->SetLabelOffset(0.01);
  h1->GetYaxis()->SetTitleSize(0.08);
  h1->GetYaxis()->SetTitleOffset(0.81);
  h1->SetMarkerSize(1);
  h1->SetMarkerStyle(24);

  h1->Draw("axis");
  h1->Draw("histsame");
  h2->Draw("histsame");
  h3->Draw("histsame");
  h4->Draw("histsame");
  h5->Draw("histsame");
  h6->Draw("histsame");

  
  TLegend leg(0.60,0.65,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,"m_{g} = 1000 GeV, m_{b} = 900 GeV, 100ns","L");
  leg.AddEntry(h2,"m_{g} = 1300 GeV, m_{b} = 100 GeV, 6ns","L");
  leg.AddEntry(h3,"m_{g} = 1300 GeV, m_{b} = 1200 GeV, 6ns","L");
  leg.AddEntry(h4,"m_{g} = 1800 GeV, m_{b} = 100 GeV, 2ns","L");
  leg.AddEntry(h5,"m_{g} = 1800 GeV, m_{b} = 1700 GeV, 2ns","L");
  leg.AddEntry(h6,"m_{g} = 1800 GeV, m_{b} = 1700 GeV, 6ns","L");
  leg.Draw();

  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.2,0.85,message);

  c->cd(2);
  c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c->GetPad(2)->SetBottomMargin(0.3);
  c->GetPad(2)->SetGridy(1);



  TH1F* h2_clone = (TH1F*) h2->Clone();
  TH1F* h3_clone = (TH1F*) h3->Clone();
  TH1F* h4_clone = (TH1F*) h4->Clone();
  TH1F* h5_clone = (TH1F*) h5->Clone();
  TH1F* h6_clone = (TH1F*) h6->Clone();

  if (h1->Integral() != 0) {
    h2_clone->Divide(h1);
    h3_clone->Divide(h1);
    h4_clone->Divide(h1);
    h5_clone->Divide(h1);
    h6_clone->Divide(h1);
  }
  else {
    h2_clone->Scale(0);
    h3_clone->Scale(0);
    h4_clone->Scale(0);
    h5_clone->Scale(0);
    h6_clone->Scale(0);
  }

  h2_clone->GetXaxis()->SetRangeUser(xmin, xmax);
  h2_clone->GetXaxis()->SetTitle(xtitle);
  h2_clone->GetYaxis()->SetRangeUser(0.,2.0);
  TString over = " / "; 
  h2_clone->GetYaxis()->SetTitle("./403280");
  h2_clone->GetYaxis()->SetNdivisions(8);

  h2_clone->GetXaxis()->SetLabelSize(0.15);
  h2_clone->GetXaxis()->SetLabelOffset(0.015);
  h2_clone->GetXaxis()->SetTitleSize(0.125);
  h2_clone->GetXaxis()->SetTitleOffset(1.15);

  h2_clone->GetYaxis()->SetLabelSize(0.1);
  h2_clone->GetYaxis()->SetLabelOffset(0.01);
  h2_clone->GetYaxis()->SetTitleSize(0.18);
  h2_clone->GetYaxis()->SetTitleOffset(0.35);

  h2_clone->Draw("E0");
  h3_clone->Draw("E0same");
  h4_clone->Draw("E0same");
  h5_clone->Draw("E0same");
  h6_clone->Draw("E0same");


  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(filename+feps);
  c->SaveAs(filename+fpng);
  c->SaveAs(filename+fpdf);

  delete c ;

}

void plot_noratio( TString hname, TString filename, TString xtitle, TString ytitle, TString message, double xmin = 0 , double xmax = 1, int rebin = 1)
{

  TFile* f1 = TFile::Open("sig_403280.root");
  TFile *f2 = TFile::Open("sig_403281.root");
  TFile *f3 = TFile::Open("sig_403282.root");
  TFile *f4 = TFile::Open("sig_403283.root");
  TFile *f5 = TFile::Open("sig_403284.root");
  TFile *f6 = TFile::Open("sig_403286.root");

  TH1F* h1 = (TH1F*)f1->Get(hname);
  TH1F* h2 = (TH1F*)f2->Get(hname);
  TH1F* h3 = (TH1F*)f3->Get(hname);
  TH1F* h4 = (TH1F*)f4->Get(hname);
  TH1F* h5 = (TH1F*)f5->Get(hname);
  TH1F* h6 = (TH1F*)f6->Get(hname);

  h1->Sumw2();
  h2->Sumw2();
  h3->Sumw2();
  h4->Sumw2();
  h5->Sumw2();
  h6->Sumw2();

  if(rebin !=1 ){

    h1->Rebin(rebin);
    h2->Rebin(rebin);
    h3->Rebin(rebin);
    h4->Rebin(rebin);
    h5->Rebin(rebin);
    h6->Rebin(rebin);
  }

  if (h1->Integral() != 0) h1->Scale(1/h1->Integral());
  if (h2->Integral() != 0) h2->Scale(1/h2->Integral());
  if (h3->Integral() != 0) h3->Scale(1/h3->Integral());
  if (h4->Integral() != 0) h4->Scale(1/h4->Integral());
  if (h5->Integral() != 0) h5->Scale(1/h5->Integral());
  if (h6->Integral() != 0) h6->Scale(1/h6->Integral());

  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(3);
  h4->SetLineColor(4);
  h5->SetLineColor(5);
  h6->SetLineColor(6);

  h1->SetMarkerColor(1);
  h2->SetMarkerColor(2);
  h3->SetMarkerColor(3);
  h4->SetMarkerColor(4);
  h5->SetMarkerColor(5);
  h6->SetMarkerColor(6);

  h1->SetLineStyle(1);
  h2->SetLineStyle(2);
  h3->SetLineStyle(3);
  h4->SetLineStyle(4);
  h5->SetLineStyle(5);
  h6->SetLineStyle(6);

  TCanvas * c = new TCanvas();
  c->SetBottomMargin(0.2);
  c->SetLogy();

  double ymax = 0;
  if (h1->GetMaximum() > ymax) ymax = h1->GetMaximum();
  if (h2->GetMaximum() > ymax) ymax = h2->GetMaximum();
  if (h3->GetMaximum() > ymax) ymax = h3->GetMaximum();
  if (h4->GetMaximum() > ymax) ymax = h4->GetMaximum();
  if (h5->GetMaximum() > ymax) ymax = h5->GetMaximum();
  if (h6->GetMaximum() > ymax) ymax = h6->GetMaximum();

  double ymin = 1000;
  if (h1->GetBinContent(h1->FindFirstBinAbove(0)) < ymin) ymin = h1->GetBinContent(h1->FindFirstBinAbove(0));
  if (h2->GetBinContent(h2->FindFirstBinAbove(0)) < ymin) ymin = h2->GetBinContent(h2->FindFirstBinAbove(0));
  if (h3->GetBinContent(h3->FindFirstBinAbove(0)) < ymin) ymin = h3->GetBinContent(h3->FindFirstBinAbove(0));
  if (h4->GetBinContent(h4->FindFirstBinAbove(0)) < ymin) ymin = h4->GetBinContent(h4->FindFirstBinAbove(0));
  if (h5->GetBinContent(h5->FindFirstBinAbove(0)) < ymin) ymin = h5->GetBinContent(h5->FindFirstBinAbove(0));
  if (h6->GetBinContent(h6->FindFirstBinAbove(0)) < ymin) ymin = h6->GetBinContent(h6->FindFirstBinAbove(0));

  h1->GetXaxis()->SetRangeUser(xmin,xmax);
  h1->GetYaxis()->SetRangeUser(ymin,ymax*50);
  h1->GetYaxis()->SetTitle(ytitle);
  h1->GetXaxis()->SetTitle(xtitle);

  h1->GetYaxis()->SetLabelSize(0.07);
  h1->GetYaxis()->SetLabelOffset(0.01);
  h1->GetYaxis()->SetTitleSize(0.08);
  h1->GetYaxis()->SetTitleOffset(0.81);
  h1->SetMarkerSize(1);
  h1->SetMarkerStyle(24);

  h1->Draw("axis");
  h1->Draw("histsame");
  h2->Draw("histsame");
  h3->Draw("histsame");
  h4->Draw("histsame");
  h5->Draw("histsame");
  h6->Draw("histsame");
  
  TLegend leg(0.60,0.65,0.88,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.02);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,"m_{g} = 1000 GeV, m_{b} = 900 GeV, 100ns","L");
  leg.AddEntry(h2,"m_{g} = 1300 GeV, m_{b} = 100 GeV, 6ns","L");
  leg.AddEntry(h3,"m_{g} = 1300 GeV, m_{b} = 1200 GeV, 6ns","L");
  leg.AddEntry(h4,"m_{g} = 1800 GeV, m_{b} = 100 GeV, 2ns","L");
  leg.AddEntry(h5,"m_{g} = 1800 GeV, m_{b} = 1700 GeV, 2ns","L");
  leg.AddEntry(h6,"m_{g} = 1800 GeV, m_{b} = 1700 GeV, 6ns","L");
  leg.Draw();

  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.2,0.85,message);

  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(filename+feps);
  c->SaveAs(filename+fpng);
  c->SaveAs(filename+fpdf);

  delete c ;

}


void compare_signals(){
  //plot("h_tight_t1","Signal_tight_t1_comparisons","t_{1} [ns]","a.u.","Tight",-5,15,10);
  //plot("h_loose_t1","Signal_loose_t1_comparisons","t_{1} [ns]","a.u.","Loose",-5,15,10);
  //plot("h_tight_calo_z1","Signal_tight_calo_z1_comparisons","Calo Z_{1} [mm]","a.u.","Tight",-2000,2000,10);
  //plot("h_loose_calo_z1","Signal_loose_calo_z1_comparisons","Calo Z_{1} [mm]","a.u.","Loose",-2000,2000,10);
  //plot("h_missing_ET","Signal_ET_comparisons","Missing E_{T} [GeV]","a.u.","",0,5000,100);

  plot_noratio("h_tight_pt1","Signal_tight_pt1_comparisons","p_{T} [GeV]","a.u","Tight",0,2000,100);
  plot_noratio("h_loose_pt1","Signal_loose_pt1_comparisons","p_{T} [GeV]","a.u","Loose",0,2000,100);
  plot_noratio("h_tight_eta1","Signal_tight_eta1_comparisons","#eta","a.u","Tight",-2.5,2.5,2);
  plot_noratio("h_loose_eta1","Signal_loose_eta1_comparisons","#eta","a.u","Loose",-2.5,2.5,2);
  plot_noratio("h_single_tight_calo_z","Signal_tight_ZDCA_comparisons","Z_DCA [mm]","a.u","Tight",-2000,2000,10);
  plot_noratio("h_single_loose_calo_z","Signal_loose_ZDCA_comparisons","Z_DCA [mm]","a.u","Loose",-2000,2000,10);

}


