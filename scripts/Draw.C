void plot( TString hname, TString hname2, TString filename, TString sampleA, TString sampleB, TString xtitle, TString ytitle, TString message, double xmin = 0 , double xmax = 1, int rebin = 1)
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


  TLegend leg(0.65,0.80,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.05);
  leg.SetShadowColor(0);
  leg.AddEntry(h_f,sampleA,"PL");
  leg.AddEntry(h_g,sampleB,"L");
  leg.Draw();

  TLatex l;
  l.SetNDC();
  l.DrawLatex(0.65,0.75,message);

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


void Draw(){

  plot("h_tight_z","h_loose_z","plot_z","Tight","Loose","Z_DCA","a.u.","",-2000,2000,10);
  //plot("h_tight_gain","h_loose_gain","plot_gain","Tight","Loose","Gain","a.u","",0,3,1);
  //plot("h_loose_minus5t_z","h_loose_pm2t_z","plot_Z_DCA_loose_timing","-6 < t < -3","-2 < t < 2","Z_{DCA} [mm]","a.u.","Loose",-1000,1000,4);
  //plot("h_tight_minus5t_z","h_tight_pm2t_z","plot_Z_DCA_tight_timing","-6 < t < -3","-2 < t < 2","Z_{DCA} [mm]","a.u.","Tight",-1000,1000,4);
  // plot("h_tight_t","h_loose_t","plot_t","Tight","Loose","t [ns]","a.u.",-20,20.,1);
  // plot("h_conv","h_conv","plot_conv","All","All","Conversion Types","a.u.",0,6.,1);



}
