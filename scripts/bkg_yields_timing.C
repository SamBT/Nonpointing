void plot(TString rootfile, TString hist, TString xtitle, TString ytitle, TString filename, int tightloose, double width = 0.1, double xmin = 0, double xmax = 20) {
  //Make distributions of Nevents Bkg (integral of timing distribution) showing how many events lie inside series of timing cuts (e.g. >0, >0.1, >0.2 etc.).  
  //Timing width (in ns) is taken as argument, histogram of nevents filled with successive integrals of timing dist using timing width to define lower bound of
  //integral.  
  TFile *f = TFile::Open(rootfile);
  
  TH1F *h = (TH1F*)f->Get(hist);

  int nbinsx = (int)20/width;

  int binwidth = (int) (width/0.1);
  cout << "width = " << width << endl;
  cout << "nbinsx = " << nbinsx << endl;
  cout << "binwidth = " << binwidth << endl;
  int lowbin = 200;
  int highbin = 200 + binwidth;
  
  double integral = 0;

  TH1F *bkg_nevents_t = new TH1F("bkg_nevents_t","bkg_nevents_t",nbinsx,0,20);

  
  for (int i = 1; i <= nbinsx; i++) {
    if (highbin > 400) highbin = 400;
    integral = h->Integral(lowbin,highbin);
    bkg_nevents_t->SetBinContent(i,integral);
    lowbin = highbin;
    highbin = highbin + binwidth;
  }

  bkg_nevents_t->GetYaxis()->SetTitle(ytitle);
  bkg_nevents_t->GetXaxis()->SetTitle(xtitle);
  bkg_nevents_t->GetYaxis()->SetLabelSize(0.05);
  bkg_nevents_t->GetYaxis()->SetLabelOffset(0.01);
  bkg_nevents_t->GetYaxis()->SetTitleSize(0.06);
  bkg_nevents_t->GetYaxis()->SetTitleOffset(0.81);
  //  bkg_nevents_t->GetXaxis()->SetLabelSize(0.15);
  bkg_nevents_t->GetXaxis()->SetLabelOffset(0.015);
  bkg_nevents_t->GetXaxis()->SetTitleSize(0.06);
  bkg_nevents_t->GetXaxis()->SetTitleOffset(1.15);

  TCanvas * c =new TCanvas();
  c->SetLogy();

  bkg_nevents_t->GetXaxis()->SetRangeUser(xmin,xmax);
  bkg_nevents_t->Draw("hist");

  TLatex l;
  l.SetNDC();
  if (tightloose == 0) {
    l.DrawLatex(0.60,0.75,"Leading Photon, Loose");
  }
  if (tightloose == 1){
    l.DrawLatex(0.60,0.75,"Leading Photon, Tight");
  }


  TLegend leg(0.60,0.80,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.05);
  leg.SetShadowColor(0);
  leg.AddEntry(bkg_nevents_t,"E_{T}^{miss} < 20 GeV","L");
  leg.Draw();

  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(filename+feps);
  c->SaveAs(filename+fpng);
  c->SaveAs(filename+fpdf);

  delete c ;
}

void bkg_yields_timing() {
  plot("output.root","h_leading_tight_t","t [ns]","# Photons with t_{#gamma} #geq t","photon_timing_tight_leading",1,0.1,0,5);
  plot("output.root","h_leading_loose_t","t [ns]","# Photons with t_{#gamma} #geq t","photon_timing_loose_leading",0,0.1,0,5);
}
  

 
    
    
  
