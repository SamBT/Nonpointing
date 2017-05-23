void plot(TString file, TString filename, TString var, int tightloose, TString xtitle, TString ytitle, double xmin = 0, double xmax = 1, int rebin = 1) {
  TFile *f = TFile::Open(file);
  TString hname;

  if (tightloose == 0) hname = "h_loose_"+var+"_conv";
  if (tightloose == 1) hname = "h_tight_"+var+"_conv";
  
  TH2F *h = (TH2F*)f->Get(hname);
  
  TH1F *conv0 = (TH1F*)h->ProjectionX("conv0",1,2);
  TH1F *conv1 = (TH1F*)h->ProjectionX("conv1",2,3);
  TH1F *conv2 = (TH1F*)h->ProjectionX("conv2",3,4);
  TH1F *conv3 = (TH1F*)h->ProjectionX("conv3",4,5);
  TH1F *conv4 = (TH1F*)h->ProjectionX("conv4",5,6);
  TH1F *conv5 = (TH1F*)h->ProjectionX("conv5",6,7);

  conv0->Sumw2();
  conv1->Sumw2();
  conv2->Sumw2();
  conv3->Sumw2();
  conv4->Sumw2();
  conv5->Sumw2();
  
  if (tightloose == 0) {
    cout << "Loose" << endl;
    cout << "conv0 = " << conv0->Integral(140,170) << endl;
    cout << "conv1 = " << conv1->Integral(140,170) << endl;
    cout << "conv2 = " << conv2->Integral(140,170) << endl;
    cout << "conv3 = " << conv3->Integral(140,170) << endl;
    cout << "conv4 = " << conv4->Integral(140,170) << endl;
    cout << "conv5 = " << conv5->Integral(140,170) << endl;
  }

  if (tightloose == 1) {
    cout << "Tight" << endl;
    cout << "conv0 = " << conv0->Integral(140,170) << endl;
    cout << "conv1 = " << conv1->Integral(140,170) << endl;
    cout << "conv2 = " << conv2->Integral(140,170) << endl;
    cout << "conv3 = " << conv3->Integral(140,170) << endl;
    cout << "conv4 = " << conv4->Integral(140,170) << endl;
    cout << "conv5 = " << conv5->Integral(140,170) << endl;
  }

  if (rebin != 1) {
    conv0->Rebin(rebin);
    conv1->Rebin(rebin);
    conv2->Rebin(rebin);
    conv3->Rebin(rebin);
    conv4->Rebin(rebin);
    conv5->Rebin(rebin);
  }
  
  conv1->Scale(conv0->Integral()/conv1->Integral());
  conv2->Scale(conv0->Integral()/conv2->Integral());
  conv3->Scale(conv0->Integral()/conv3->Integral());
  conv4->Scale(conv0->Integral()/conv4->Integral());
  conv5->Scale(conv0->Integral()/conv5->Integral());

  conv1->SetLineColor(2);
  conv2->SetLineColor(3);
  conv3->SetLineColor(4);
  conv4->SetLineColor(6);
  conv5->SetLineColor(7);

  conv1->SetMarkerColor(2);
  conv2->SetMarkerColor(3);
  conv3->SetMarkerColor(4);
  conv4->SetMarkerColor(6);
  conv5->SetMarkerColor(7);

  conv0->GetXaxis()->SetRangeUser(xmin,xmax);

  TCanvas * c =new TCanvas();
  c->Divide(1,2);
  c->SetBottomMargin(0.2);
  c->cd(1);
  c->GetPad(1)->SetLogy();
  c->GetPad(1)->SetPad(0.,0.25,1.,1);

  conv0->GetYaxis()->SetRangeUser(conv0->GetBinContent( conv0->FindLastBinAbove(0))*0.5,conv0->GetMaximum()*10);

  conv0->GetYaxis()->SetTitle(ytitle);

  conv0->GetYaxis()->SetLabelSize(0.07);
  conv0->GetYaxis()->SetLabelOffset(0.01);
  conv0->GetYaxis()->SetTitleSize(0.08);
  conv0->GetYaxis()->SetTitleOffset(0.81);
  conv0->SetMarkerSize(1);
  conv0->SetMarkerStyle(24);

  conv0->Draw("axis");
  conv0->Draw("Esame");
  conv1->Draw("histsame");
  conv2->Draw("histsame");
  conv3->Draw("histsame");
  conv4->Draw("histsame");
  conv5->Draw("histsame");
  conv0->Draw("Esame");

  TLatex l;
  l.SetNDC();
  if (tightloose == 0) {
    l.DrawLatex(0.65,0.65,"Loose");
  }
  if (tightloose == 1){
    l.DrawLatex(0.65,0.65,"Tight");
  }

  TLegend leg(0.65,0.70,0.895,0.89);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  leg.AddEntry(conv0,"Conv Type = 0","L");
  leg.AddEntry(conv1,"Conv Type = 1","L");
  leg.AddEntry(conv2,"Conv Type = 2","L");
  leg.AddEntry(conv3,"Conv Type = 3","L");
  leg.AddEntry(conv4,"Conv Type = 4","L");
  leg.AddEntry(conv5,"Conv Type = 5","L");
  leg.Draw();

  c->cd(2);
  c->GetPad(2)->SetPad(0.,0.05,1,0.365);
  c->GetPad(2)->SetBottomMargin(0.3);
  c->GetPad(2)->SetGridy(1);

  TH1F *conv1_c = (TH1F*)conv1->Clone();
  TH1F *conv2_c = (TH1F*)conv2->Clone();
  TH1F *conv3_c = (TH1F*)conv3->Clone();
  TH1F *conv4_c = (TH1F*)conv4->Clone();
  TH1F *conv5_c = (TH1F*)conv5->Clone();

  conv1_c->Divide(conv0);
  conv2_c->Divide(conv0);
  conv3_c->Divide(conv0);
  conv4_c->Divide(conv0);
  conv5_c->Divide(conv0);

  conv1_c->GetXaxis()->SetRangeUser(xmin, xmax);
  conv1_c->GetXaxis()->SetTitle(xtitle);
  conv1_c->GetYaxis()->SetTitle("./Conv = 0");
  conv1_c->GetYaxis()->SetNdivisions(8);

  conv1_c->GetXaxis()->SetLabelSize(0.15);
  conv1_c->GetXaxis()->SetLabelOffset(0.015);
  conv1_c->GetXaxis()->SetTitleSize(0.125);
  conv1_c->GetXaxis()->SetTitleOffset(1.15);

  conv1_c->GetYaxis()->SetLabelSize(0.1);
  conv1_c->GetYaxis()->SetLabelOffset(0.01);
  conv1_c->GetYaxis()->SetTitleSize(0.18);
  conv1_c->GetYaxis()->SetTitleOffset(0.35);

  conv1_c->Draw("E0");
  conv2_c->Draw("E0same");
  conv3_c->Draw("E0same");
  conv4_c->Draw("E0same");
  conv5_c->Draw("E0same");
  
  TString feps = ".eps", fpng = ".png", fpdf = ".pdf";
  
  c->SaveAs(filename+feps);
  c->SaveAs(filename+fpng);
  c->SaveAs(filename+fpdf);

  delete c ;

}

void convtype_comparisons() {
  //  plot("output.root","loose_z_convtypes","z",0,"Z_{DCA} [mm]","a.u.",-2000,2000,10);
  // plot("output.root","tight_z_convtypes","z",1,"Z_{DCA} [mm]","a.u.",-2000,2000,10);
  plot("output.root","loose_t_convtypes","t",0,"t [ns]","a.u.",-8,8,1);
  plot("output.root","tight_t_convtypes","t",1,"t [ns]","a.u.",-8,8,1);
}
