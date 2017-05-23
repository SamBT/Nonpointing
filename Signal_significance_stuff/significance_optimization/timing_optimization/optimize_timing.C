#include "optimize_timing.h"
vector<int> find_optimal_timing_binning(TH1F *hs, TH1F *hb, TH1F *hb_nw) {
	int nbins = hs->GetNbinsX();

	//Initializing all relevant variables/placeholder variables
	double combined_sig = 0;
	int t0, t1, t2, t3, t4, t3_best, t4_best, test1;
	double test2; 
	t0 = t1 = t2 = 0;
	t3 = t4 = 99999;
	double z0, z1, z2;
	z1 = z2 = 0;
	double sig0 = 0;
	double sig1 = 0;
	double sig2 = 0;
	double sig3 = 0;
	double sig4 = 0;

	//Calculating t0
	for (int i = 1; i <= nbins; i++){
		if (hb_nw->Integral(i,nbins) <= 10) continue;
		if (significance(hs->Integral(i,nbins),hb->Integral(i,nbins)) > sig0) {sig0 = significance(hs->Integral(i,nbins),hb->Integral(i,nbins)); t0 = i;}
	}
	//Use t0 to find t1, t2
	t1 = best_between(hs,hb,hb_nw,t0+1,nbins);
	t2 = best_between(hs,hb,hb_nw,1,t0-1);

	//If t2 is -inf, don't consider[t2,t0] a bin
	//Similar for if t1 = +inf
	vector<int> l1;
	if (t2 == 1 && t1 != nbins) {
		l1 = {1,t0,t1,nbins};
	}
	if (t2 == 1 && t1 == nbins) {
		l1 = {1,t0,nbins};
	}
	if (t2 != 1 && t1 == nbins) {
		l1 = {1,t2,t0,nbins};
	}
	if (t2 != 1 && t1 != nbins) {
		l1 = {1,t2,t0,t1,nbins};
	}

	sort(l1.begin(),l1.end());
	z0 = comb_sig(hs,hb,l1);
	z1 = 0;
	z2 = 0;
	vector<int> places;


	//Attempt to find bin subdivisions where significance is improved by at least 5%
	for (int j = 0; j < (l1.size() - 1); j++) {
		if (l1[j] == 1) test1 = best_between(hs,hb,hb_nw, l1[j], l1[j+1]-1);
		if (l1[j+1] == nbins) test1 = best_between(hs,hb,hb_nw,l1[j]+1,l1[j+1]);
		if (l1[j] != 1 && l1[j+1] != nbins) test1 = best_between(hs,hb,hb_nw,l1[j]+1,l1[j+1]-1);
		if (test1 == 1 || test1 == nbins) continue;
		places = l1;
		places.push_back(test1);
		sort(places.begin(),places.end());
		test2 = comb_sig(hs,hb,places);
		if (test2 > z1 && test2/z0 >= 1.05) {z1 = test2; t3 = test1;}
	}

	if (t3 != 99999) {
		vector<int> l2;
		l2 = l1;
		l2.push_back(t3);
		sort(l2.begin(),l2.end());
		z1 = comb_sig(hs,hb,l2);
		for (int k = 0; k < (l2.size() - 1); k++) {
			if (l2[k] == 1) test1 = best_between(hs,hb,hb_nw,l2[k],l2[k+1]-1);
			if (l2[k+1] == nbins) test1 = best_between(hs,hb,hb_nw,l2[k]+1,l2[k+1]);
			if (l2[k] != 1 && l2[k+1] != nbins) test1 = best_between(hs,hb,hb_nw,l2[k]+1,l2[k+1]-1);
			if (test1 == 1 || test1 == nbins) continue;
			places = l2;
			places.push_back(test1);
			sort(places.begin(),places.end());
			test2 = comb_sig(hs,hb,places);
			if (test2 > z2 && test2/z1 >= 1.05) {z2 = test2; t4 = test1;}
		}
	}
	
	//cout << "t0 = " << t0 << ", t1 = " << t1 << ", t2 = " << t2 << ", t3 = " << t3 << ", t4 = " << t4 << endl;
	vector<int> temp = {1,nbins,t0,t1,t2,t3,t4};
	vector<int> output = {1,nbins};
	for (int i = 2; i < temp.size(); i++) {
		if (temp[i] != 1 && temp[i] != nbins && temp[i] != 99999) output.push_back(temp[i]);
	}
	sort(output.begin(), output.end());
	return output;
}

TString optimize_timing(TString region, vector<double> zdca_bins, int run) {
	TString fname;
	fname.Form("../../EXOT6/%i.root",run);
	//fname.Form("../../sig_%i.root",run);
	TString hist = "h_timing_zdca_" + region;
	TString outfname;
	outfname.Form("optimal_timing_bins_%i",run);
	outfname = outfname + "_"+region+".txt";
	double nevents_SR, nevents_CR, nevents_SR_nw, nevents_CR_nw;
	
	TFile *fs = TFile::Open(fname);
	TFile *fb = TFile::Open("../../EXOT6/data.root");
	//TFile *fb = TFile::Open("../../output_data.root");


	TH2F *th2_b = (TH2F*)fb->Get("h_timing_zdca_CR");
	TH2F *th2_b_nowt = (TH2F*)fb->Get("h_timing_zdca_CR_nowt");
	TH2F *th2_s = (TH2F*)fs->Get(hist);
	TH1F *cutflow_bkg = (TH1F*)fb->Get("h_CF");
	TH1F *cutflow_bkg_nowt = (TH1F*)fb->Get("h_CF_nowt");

	nevents_CR = cutflow_bkg->GetBinContent(2);
	nevents_CR_nw = cutflow_bkg_nowt->GetBinContent(2);
	if (region == "SR1") {nevents_SR = cutflow_bkg->GetBinContent(3); nevents_SR_nw = cutflow_bkg_nowt->GetBinContent(3);}
	if (region == "SR2") {nevents_SR = cutflow_bkg->GetBinContent(4); nevents_SR_nw = cutflow_bkg_nowt->GetBinContent(4);}

	int nbins = zdca_bins.size();

	double combined_sig;
	TString message;
	TString outstring;
	TString dummy_msg;
	double dummy = 0;
	int highbin, lowbin;

	vector<int> outbins;

	outstring.Form("---------------------------------------- RUN %i",run);
	outstring = outstring + ", " + region + "  ----------------------------------------\n";
	cout << "run = " << run << ", region = " << region << endl;

	TString s_bin_yields = "Signal Bin Yields: {";
	TString b_bin_yields = "Background Bin Yields: {";

	TString latex;

	for (int i = 0; i < nbins - 1; i++) {
		lowbin = (int)(zdca_bins[i]/10) + 1;
		highbin = (int)(zdca_bins[i+1]/10) + 1;

		if (highbin > th2_s->GetNbinsY()) highbin = th2_s->GetNbinsY();

		TH1F *hs = (TH1F*)th2_s->ProjectionX("hs",lowbin,highbin);
		TH1F *hb = (TH1F*)th2_b->ProjectionX("hb",lowbin,highbin); 
		TH1F *hb_nw = (TH1F*)th2_b_nowt->ProjectionX("hb_nw",lowbin,highbin);

		hb->Scale(35/3.2); //Luminosity scaling
		hb->Scale(nevents_SR/nevents_CR); //Scaling to predicted bkg levels in signal region
		hb_nw->Scale(35/3.2);
		hb_nw->Scale(nevents_SR_nw/nevents_CR_nw);

		outbins = find_optimal_timing_binning(hs,hb,hb_nw);

		combined_sig = comb_sig(hs,hb,outbins);

		vector<double> outvals;

		if (region == "SR2") {
			latex.Form("%i & SR2 & [0,2000] & %.3f &",run,combined_sig);
		}
		if (region == "SR1") {
			latex.Form("%i & SR1 & [0,2000] & %.3f &",run,combined_sig);
		}


		for (int j = 0; j < outbins.size(); j++) {
			outvals.push_back(-21 + 0.2*(outbins[j] - 1));
		}

		TString bin_significance = "Bin-by-bin significance: {";

		for (int k = 0; k < outbins.size() - 1; k++) {
			if (outbins[k] != 1) dummy = significance(hs->Integral(outbins[k],outbins[k+1]),hb->Integral(outbins[k],outbins[k+1]));
			if (outbins[k] == 1) dummy = significance(hs->Integral(outbins[k],outbins[k+1]),hb->Integral(outbins[k],outbins[k+1]));
			dummy_msg.Form("%0.4f, ",dummy);
			bin_significance = bin_significance + dummy_msg;
			dummy_msg.Form("%.2f, ",hs->Integral(outbins[k],outbins[k+1]));
			s_bin_yields += dummy_msg;
			dummy_msg.Form("%.2f, ",hb->Integral(outbins[k],outbins[k+1]));
			b_bin_yields += dummy_msg;
			if (k == 0) {
				dummy_msg.Form("[%.2f,%.2f] & %.2f & %.2f & %.3f  \\\\ \n",-21 + 0.2*(outbins[k]-1),-21 + 0.2*(outbins[k+1]-1),hs->Integral(outbins[k],outbins[k+1]),hb->Integral(outbins[k],outbins[k+1]),significance(hs->Integral(outbins[k],outbins[k+1]),hb->Integral(outbins[k],outbins[k+1])));
				latex += dummy_msg;
			}
			if (k > 0) {
				dummy_msg.Form("& & & & [%.2f,%.2f] & %.2f & %.2f & %.3f  \\\\ \n",-21 + 0.2*(outbins[k]-1),-21 + 0.2*(outbins[k+1]-1),hs->Integral(outbins[k],outbins[k+1]),hb->Integral(outbins[k],outbins[k+1]),significance(hs->Integral(outbins[k],outbins[k+1]),hb->Integral(outbins[k],outbins[k+1])));
				latex += dummy_msg;
			}
		}
		latex += "\\hline \n";

		message.Form("ZDCA BIN: %.0f < ZDCA < %.0f, ",zdca_bins[i],zdca_bins[i+1]);
		TString f = "Timing Bin Edges: {";

		for (int k = 0; k < outvals.size();k++) {
			if (k+1 == outvals.size()) {
				f = f + to_string(round(outvals[k]*10)/10);
			}
			else {
				f = f + to_string(round(outvals[k]*10)/10) + ", ";
			}
		}

		bin_significance = bin_significance + "}\n\n";
		f = f + "}";

		s_bin_yields += "}\n";
		b_bin_yields += "}\n";

		TString g;
		g.Form(", Combined Signficance: %.4f\n",combined_sig);

		outstring = outstring + message + f + g + s_bin_yields + b_bin_yields + latex + bin_significance;
	}
	outstring = outstring + "--------------------------------------------------------------------------------------------------\n\n";
	ofstream ltx;
	ltx.open("latex.txt",std::ios_base::app);
	ltx << latex;

	return outstring;

}


void optimize_timing() {
	//int runs[] = {403280,403281,403282,403283,403284,403286};
	int runs[] = {403280,403281,403282,403283,403284,403285,403286};
	int size = sizeof(runs)/sizeof(*runs);
	TString hname;
	TString fname;
	vector<double> z_dca_bins = {0,40,80,120,160,200,9999999};
	vector<double> z_dca_bins_2 = {0,2000};

	map<int,TString> signal_info;
	signal_info[403280] = "m_{g} = 1000, m_{b} = 900, t = 100 ns";
	signal_info[403281] = "m_{g} = 1300, m_{b} = 100, t = 6 ns";
	signal_info[403282] = "m_{g} = 1300, m_{b} = 1200, t = 6 ns";
	signal_info[403283] = "m_{g} = 1800, m_{b} = 100, t = 2 ns";
	signal_info[403284] = "m_{g} = 1800, m_{b} = 1700, t = 2 ns";
	signal_info[403286] = "m_{g} = 1800, m_{b} = 1700, t = 6 ns";
	
	ofstream outfile;
	outfile.open("binning.txt");
	TString s1, s2;

	for (int i = 0; i < size; i++) {
		hname.Form("yields_%i",runs[i]);
		fname.Form("yield_table_%i",runs[i]);
		//s1 = optimize_timing("SR1",z_dca_bins_2,runs[i]);
		s2 = optimize_timing("SR2",z_dca_bins_2,runs[i]);
		//outfile << s1 << s2;
		outfile << s2;
	}
	outfile.close();
}