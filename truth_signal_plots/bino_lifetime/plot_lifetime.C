#include "AtlasLabels.C"
#include "AtlasLabels.h"
void plot_lifetime(TString file, double lifetime) {
  TFile *f = TFile::Open(file);
  TH1F *h = (TH1F*)f->Get("h_bino_lifetime");
  
  TCanvas *c = new TCanvas();
  c->SetLogy();
  h->GetXaxis()->SetRangeUser(0,3*lifetime);
  h->Draw("hist");
  h->Fit("expo","","",0,3*lifetime);
  double p0 = h->GetFunction("expo")->GetParameter(0);
  double p1 = h->GetFunction("expo")->GetParameter(1);
  TString message2;
  message2.Form("Fit Ce^{-t/#tau}, C = %4.3f, -1/#tau = %4.3f",p0,p1);
  TLatex l;
  l.SetTextSize(0.04);
  l.SetNDC();
  TString message;
  message.Form("#tau_{exp} = %4.1f ns", lifetime);
  l.DrawLatex(0.5,0.8,message);
  l.DrawLatex(0.5,0.75,message2);
  TString message3;
  message3.Form("#tau_{fit} = %4.3f ns",-1/p1);
  l.DrawLatex(0.5,0.7,message3);
  TString outname;
  if (lifetime < 1) outname.Form("bino_lifetime_t%1.1f",lifetime);
  else outname.Form("bino_lifetime_t%.0f",lifetime);
  c->SaveAs(outname+"_SBT.png");
  c->SaveAs(outname+"_SBT.pdf");
  c->SaveAs(outname+"_SBT.eps");
  c->SaveAs(outname+"_SBT.C");
}
