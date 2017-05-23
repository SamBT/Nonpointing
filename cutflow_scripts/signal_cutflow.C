{
	TFile *f1 = TFile::Open("sig_403280.root");
	TFile *f2 = TFile::Open("sig_403281.root");
	TFile *f3 = TFile::Open("sig_403282.root");
	TFile *f4 = TFile::Open("sig_403283.root");
	TFile *f5 = TFile::Open("sig_403284.root");
	TFile *f6 = TFile::Open("sig_403286.root");

	TH1F *h1 = (TH1F*)f1->Get("h_CF");
	TH1F *h2 = (TH1F*)f2->Get("h_CF");
	TH1F *h3 = (TH1F*)f3->Get("h_CF");
	TH1F *h4 = (TH1F*)f4->Get("h_CF");
	TH1F *h5 = (TH1F*)f5->Get("h_CF");
	TH1F *h6 = (TH1F*)f6->Get("h_CF");

	ofstream out;
	out.open("signal_cutflow.csv");

	out << "Gluino (GeV), Bino (GeV), t (ns), Initial, g140_loose, g140 efficiency, pt > 150 GeV, pt>150 efficiency, Missing ET > 20 GeV, met > 20 efficiency, Missing ET > 70 GeV, met > 70 efficiency,2 photons pT > 25 GeV, 2 photons efficiency \n";

	out << "1200,900,100," << h1->GetBinContent(1) << "," << h1->GetBinContent(2) << "," << h1->GetBinContent(2)/h1->GetBinContent(1) <<"," << h1->GetBinContent(3) << "," << h1->GetBinContent(3)/h1->GetBinContent(2) << "," << h1->GetBinContent(4) << "," << h1->GetBinContent(4)/h1->GetBinContent(3) << "," << h1->GetBinContent(5) << "," << h1->GetBinContent(5)/h1->GetBinContent(4) << "," << h1->GetBinContent(6) << "," << h1->GetBinContent(6)/h1->GetBinContent(5) << "\n";

	out << "1300,100,6," <<  h2->GetBinContent(1) << "," << h2->GetBinContent(2) << "," << h2->GetBinContent(2)/h2->GetBinContent(1) <<"," << h2->GetBinContent(3) << "," << h2->GetBinContent(3)/h2->GetBinContent(2) << "," << h2->GetBinContent(4) << "," << h2->GetBinContent(4)/h2->GetBinContent(3) << "," << h2->GetBinContent(5) << "," << h2->GetBinContent(5)/h2->GetBinContent(4) << "," << h2->GetBinContent(6) << "," << h2->GetBinContent(6)/h2->GetBinContent(5) << "\n";

	out << "1300,1200,6," <<  h3->GetBinContent(1) << "," << h3->GetBinContent(2) << "," << h3->GetBinContent(2)/h3->GetBinContent(1) <<"," << h3->GetBinContent(3) << "," << h3->GetBinContent(3)/h3->GetBinContent(2) << "," << h3->GetBinContent(4) << "," << h3->GetBinContent(4)/h3->GetBinContent(3) << "," << h3->GetBinContent(5) << "," << h3->GetBinContent(5)/h3->GetBinContent(4) << "," << h3->GetBinContent(6) << "," << h3->GetBinContent(6)/h3->GetBinContent(5) << "\n";

	out << "1800,100,2," <<  h4->GetBinContent(1) << "," << h4->GetBinContent(2) << "," << h4->GetBinContent(2)/h4->GetBinContent(1) <<"," << h4->GetBinContent(3) << "," << h4->GetBinContent(3)/h4->GetBinContent(2) << "," << h4->GetBinContent(4) << "," << h4->GetBinContent(4)/h4->GetBinContent(3) << "," << h4->GetBinContent(5) << "," << h4->GetBinContent(5)/h4->GetBinContent(4) << "," << h4->GetBinContent(6) << "," << h4->GetBinContent(6)/h4->GetBinContent(5) << "\n";

	out << "1800,1700,2," <<  h5->GetBinContent(1) << "," << h5->GetBinContent(2) << "," << h5->GetBinContent(2)/h5->GetBinContent(1) <<"," << h5->GetBinContent(3) << "," << h5->GetBinContent(3)/h5->GetBinContent(2) << "," << h5->GetBinContent(4) << "," << h5->GetBinContent(4)/h5->GetBinContent(3) << "," << h5->GetBinContent(5) << "," << h5->GetBinContent(5)/h5->GetBinContent(4) << "," << h5->GetBinContent(6) << "," << h5->GetBinContent(6)/h5->GetBinContent(5) << "\n";

	out << "1800,1700,6," <<  h6->GetBinContent(1) << "," << h6->GetBinContent(2) << "," << h6->GetBinContent(2)/h6->GetBinContent(1) <<"," << h6->GetBinContent(3) << "," << h6->GetBinContent(3)/h6->GetBinContent(2) << "," << h6->GetBinContent(4) << "," << h6->GetBinContent(4)/h6->GetBinContent(3) << "," << h6->GetBinContent(5) << "," << h6->GetBinContent(5)/h6->GetBinContent(4) << "," << h6->GetBinContent(6) << "," << h6->GetBinContent(6)/h6->GetBinContent(5) << "\n";

	out.close();


}
