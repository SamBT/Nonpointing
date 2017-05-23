void plot( TString hname, TString hname2, TString filename, TString sampleA, TString sampleB, TString xtitle, TString ytitle, double xmin = 0 , double xmax = 1, int rebin = 1, int tightloose = -1)
{

  TFile* f = TFile::Open("output.root");

  TH1F* h_f = (TH1F*)f->Get(hname);
  TH1F* h_g = (TH1F*)f->Get(hname2);

  h_f->Sumw2();
  h_g->Sumw2();

  if(rebin !=1 ){

    h_f->Rebin(rebin);
    h_g->Rebin(rebin);
  }

  h_f->Scale( );
  h_g->Scale(h_f->Integral()/h_g->Integral() );

  TCanvas * c =new TCanvas();
  c->Divide(1,2);
  c->SetBottomMargin(0.2);
  c->cd(1);
  c->GetPad(1)->SetLogy();
  c->GetPad(1)->SetPad(0.,0.25,1.,1);


  h_f->GetXaxis()->SetRangeUser(xmin,xmax);
  if(hname!="h_BDTG")
    h_f->GetYaxis()->SetRangeUser(h_f->GetBinContent( h_f->FindLastBinAbove(0))*0.5,h_f->GetMaximum()*10);
  else {
    h_f->GetYaxis()->SetRangeUser(0,h_f->GetMaximum()*1.35);
    c->GetPad(1)->SetLogy(0);
  }

  h_f->GetYaxis()->SetTitle(ytitle);

  h_f->GetYaxis()->SetLabelSize(0.07);
  h_f->GetYaxis()->SetLabelOffset(0.01);
  h_f->GetYaxis()->SetTitleSize(0.08);
  h_f->GetYaxis()->SetTitleOffset(0.81);
  h_f->SetMarkerSize(1);
  h_f->SetMarkerStyle(24);

  h_f->Draw("axis");
  h_f->Draw("Esame");
  h_g->Draw("histsame");

  TLatex l;
  l.SetNDC();
  if (tightloose == 0) {
    l.DrawLatex(0.65,0.75,"Loose");
  }
  if (tightloose == 1){
    l.DrawLatex(0.65,0.75,"Tight");
  }


  TLegend leg(0.65,0.80,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.05);
  leg.SetShadowColor(0);
  leg.AddEntry(h_f,sampleA,"PL");
  leg.AddEntry(h_g,sampleB,"L");
  leg.Draw();

  c->cd(2);
  c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c->GetPad(2)->SetBottomMargin(0.3);
  c->GetPad(2)->SetGridy(1);



  TH1F* h_f_clone = (TH1F*) h_f->Clone();

  h_f_clone->Divide(h_g);
  h_f_clone->GetXaxis()->SetRangeUser(xmin, xmax);
  h_f_clone->GetXaxis()->SetTitle(xtitle);
  h_f_clone->GetYaxis()->SetRangeUser(0.,2.0);
  TString over = " / "; 
  h_f_clone->GetYaxis()->SetTitle(sampleA+over+sampleB);
  h_f_clone->GetYaxis()->SetNdivisions(8);

  h_f_clone->GetXaxis()->SetLabelSize(0.15);
  h_f_clone->GetXaxis()->SetLabelOffset(0.015);
  h_f_clone->GetXaxis()->SetTitleSize(0.125);
  h_f_clone->GetXaxis()->SetTitleOffset(1.15);

  h_f_clone->GetYaxis()->SetLabelSize(0.1);
  h_f_clone->GetYaxis()->SetLabelOffset(0.01);
  h_f_clone->GetYaxis()->SetTitleSize(0.18);
  h_f_clone->GetYaxis()->SetTitleOffset(0.35);

  h_f_clone->Draw("E0");


  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  c->SaveAs(filename+feps);
  c->SaveAs(filename+fpng);
  c->SaveAs(filename+fpdf);

  delete c ;

}


void convtype_plots(){

  plot("h_tight_z_conv0","h_tight_z_conv1","plot_Z_DCA_tight","Conv Type = 0","Conv Type > 0","Z_{DCA} [mm]","a.u.",-2000,2000.,10,1);
  plot("h_loose_z_conv0","h_loose_z_conv1","plot_Z_DCA_loose","Conv Type = 0","Conv Type > 0","Z_{DCA} [mm]","a.u.",-2000,2000.,10,0);
  plot("h_tight_t_conv0","h_tight_t_conv1","plot_t_tight","Conv Type = 0","Conv Type > 0","t [ns]","a.u.",-20,20.,1,1);
  plot("h_loose_t_conv0","h_loose_t_conv1","plot_t_loose","Conv Type = 0","Conv Type > 0","t [ns]","a.u.",-20,20.,1,0);
  //  plot("h_conv","h_conv","plot_conv","All","All","Conversion Types","a.u.",0,6.,1);



}
