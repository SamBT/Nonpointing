void significance(TString bkg, TString signal, TString histname, int zbinlow, int zbinhigh) {
  TFile *s = TFile::Open(signal);
  TFile *b = TFile::Open(bkg);
  
  TH2F *hs1 = (TH2F*)s->Get(histname);
  TH2F *hb1 = (TH2F*)b->Get(histname);

  TH1F *hs = hs1->ProjectionX(zbinlow, zbinhigh);
  TH1F *hb = hb1->ProjectionX(zbinlow, zbinhigh);

  double yields[200];

  double bkg_yield = 0;
  double signal_yield = 0;

  for (int k = 1; k <= 200; k++) {
    bkg_yield = hb->Integral(200+k,400);
    signal_yield = hs->Integral(200+k,400);
    yields[k-1] = signal_yield/sqrt(bkg_yield);
  }

  

  
