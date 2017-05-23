#include "optimize.h"
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

int best_between_zdca(TH2F *th2_s, TH2F *th2_b, TH2F *th2_b_nowt, int low, int high) {
	double sig0,sig1,sig2,sig3,sig4,sig5;
	int out = -1;
	TH1F *h1, *h2, *h3, *h4, *h5, *h6;
	vector<int> v1, v2;
	double comb1, comb2, test, comb;
	comb = 0;

	for (int i = low; i <= high; i++) {
		h1 = (TH1F*)th2_s->ProjectionX("h1",low,i);
		h2 = (TH1F*)th2_b->ProjectionX("h2",low,i);
		h3 = (TH1F*)th2_b_nowt->ProjectionX("h3",low,i);
		h4 = (TH1F*)th2_s->ProjectionX("h4",i,high);
		h5 = (TH1F*)th2_b->ProjectionX("h5",i,high);
		h6 = (TH1F*)th2_b_nowt->ProjectionX("h6",i,high);
		v1 = find_optimal_timing_binning(h1,h2,h3);
		v2 = find_optimal_timing_binning(h4,h5,h6);
		comb1 = comb_sig(h1,h2,v1);
		comb2 = comb_sig(h4,h5,v2);
		test = sqrt(pow(comb1,2)+pow(comb2,2));
		if (test > comb) {comb = test; out = i;}
	}
	return out;
}

double comb_sig_zdca(TH2F *th2_s, TH2F *th2_b, TH2F* th2_b_nowt, vector<int> bins) {
	TH1F *hs, *hb, *hbnw;
	double out = 0;
	vector<int> bins1;
	for (int i = 0; i < (bins.size()-1); i++) {
		hs = (TH1F*)th2_s->ProjectionX("hs",bins[i],bins[i+1]);
		hb = (TH1F*)th2_b->ProjectionX("hs",bins[i],bins[i+1]);
		hbnw = (TH1F*)th2_b_nowt->ProjectionX("hbnw",bins[i],bins[i+1]);
		bins1 = find_optimal_timing_binning(hs,hb,hbnw);
		out += pow(comb_sig(hs,hb,bins1),2);
	}
	out = sqrt(out);
	return out;	
}

vector<vector<int>> optimize_zdca_timing(TString region, int run) {
	TString fname;
	fname.Form("/global/homes/s/sambt/workarea/nonpointing/analysis_output/signal/%i.root",run);
	TString hist = "h_timing_zdca_" + region;
	TString outfname;
	outfname.Form("optimal_timing_bins_%i",run);
	outfname = outfname + "_"+region+".txt";
	double nevents_SR, nevents_CR, nevents_SR_nw, nevents_CR_nw;
	
	TFile *fs = TFile::Open(fname);
	TFile *fb = TFile::Open("/global/homes/s/sambt/workarea/nonpointing/analysis_output/data/output_data.root");

	TH2F *th2_b = (TH2F*)fb->Get("h_timing_zdca_CR");
	TH2F *th2_b_nowt = (TH2F*)fb->Get("h_timing_zdca_CR_nowt");
	TH2F *th2_s = (TH2F*)fs->Get(hist);
	TH1F *cutflow_bkg = (TH1F*)fb->Get("h_CF");
	TH1F *cutflow_bkg_nowt = (TH1F*)fb->Get("h_CF_nowt");

	nevents_CR = cutflow_bkg->GetBinContent(2);
	nevents_CR_nw = cutflow_bkg_nowt->GetBinContent(2);
	if (region == "SR1") {nevents_SR = cutflow_bkg->GetBinContent(3); nevents_SR_nw = cutflow_bkg_nowt->GetBinContent(3);}
	if (region == "SR2") {nevents_SR = cutflow_bkg->GetBinContent(4); nevents_SR_nw = cutflow_bkg_nowt->GetBinContent(4);}

	th2_b->Scale(35/3.2);
	th2_b->Scale(nevents_SR/nevents_CR);
	th2_b_nowt->Scale(35/3.2);
	th2_b_nowt->Scale(nevents_SR_nw/nevents_CR_nw);

	int nbins_zdca = th2_s->GetNbinsY();
	int z0,z1,z2,z3,z4;
	z3 = z4 = -1;
	double sig0,sig1,sig2,sig3,sig4,sig5;
	sig0 = sig1 = sig2 = sig3 = sig4 = sig5 = 0;
	TH1F *h1, *h2, *h3, *h4, *h5, *h6;
	vector<int> v1, v2;
	double comb1, comb2, test, comb;
	comb = 0;

	for (int i = 1; i <= nbins_zdca; i++) {
		h1 = (TH1F*)th2_s->ProjectionX("h1",1,i);
		h2 = (TH1F*)th2_b->ProjectionX("h2",1,i);
		h3 = (TH1F*)th2_b_nowt->ProjectionX("h3",1,i);
		h4 = (TH1F*)th2_s->ProjectionX("h4",i,nbins_zdca);
		h5 = (TH1F*)th2_b->ProjectionX("h5",i,nbins_zdca);
		h6 = (TH1F*)th2_b_nowt->ProjectionX("h6",i,nbins_zdca);
		v1 = find_optimal_timing_binning(h1,h2,h3);
		v2 = find_optimal_timing_binning(h4,h5,h6);
		comb1 = comb_sig(h1,h2,v1);
		comb2 = comb_sig(h4,h5,v2);
		test = sqrt(pow(comb1,2)+pow(comb2,2));
		if (test > comb) {comb = test; z0 = i;}
		}

	z1 = best_between_zdca(th2_s, th2_b, th2_b_nowt, z0+1, nbins_zdca);
	z2 = best_between_zdca(th2_s,th2_b,th2_b_nowt,1,z0-1);

	vector<int> l1;
	if (z2 == 1 && z1 != nbins_zdca) {
		l1 = {1,z0,z1,nbins_zdca};
	}
	if (z2 == 1 && z1 == nbins_zdca) {
		l1 = {1,z0,nbins_zdca};
	}
	if (z2 != 1 && z1 == nbins_zdca) {
		l1 = {1,z2,z0,nbins_zdca};
	}
	if (z2 != 1 && z1 != nbins_zdca) {
		l1 = {1,z2,z0,z1,nbins_zdca};
	}

	sort(l1.begin(),l1.end());
	comb = comb_sig_zdca(th2_s,th2_b,th2_b_nowt,l1);
	vector<int> places;
	int test1;

	for (int j = 0; j < (l1.size() - 1); j++) {
		if (l1[j] == 1) test1 = best_between_zdca(th2_s,th2_b,th2_b_nowt, l1[j], l1[j+1]-1);
		if (l1[j+1] == nbins_zdca) test1 = best_between_zdca(th2_s,th2_b,th2_b_nowt,l1[j]+1,l1[j+1]);
		if (l1[j] != 1 && l1[j+1] != nbins_zdca) test1 = best_between_zdca(th2_s,th2_b,th2_b_nowt,l1[j]+1,l1[j+1]-1);
		if (test1 == 1 || test1 == nbins_zdca) continue;
		places = l1;
		places.push_back(test1);
		sort(places.begin(),places.end());
		test = comb_sig_zdca(th2_s,th2_b,th2_b_nowt,places);
		if (test/comb >= 1.05) {z3 = test1;}
	}

	if (z3 != -1) {
		vector<int> l2 = l1;
		if (z3 != 1 && z3 != nbins_zdca) {
			l2.push_back(z3);
		}
		sort(l2.begin(),l2.end());
		comb = comb_sig_zdca(th2_s,th2_b,th2_b_nowt,l2);
		for (int k = 0; k < (l2.size() - 1); k++) {
			if (l2[k] == 1) test1 = best_between_zdca(th2_s,th2_b,th2_b_nowt,l2[k],l2[k+1]-1);
			if (l2[k+1] == nbins_zdca) test1 = best_between_zdca(th2_s,th2_b,th2_b_nowt,l2[k]+1,l2[k+1]);
			if (l2[k] != 1 && l2[k+1] != nbins_zdca) test1 = best_between_zdca(th2_s,th2_b,th2_b_nowt,l2[k]+1,l2[k+1]-1);
			if (test1 == 1 || test1 == nbins_zdca) continue;
			places = l2;
			places.push_back(test1);
			sort(places.begin(),places.end());
			test = comb_sig_zdca(th2_s,th2_b,th2_b_nowt,places);
			if (test/comb >= 1.05) {z4 = test1;}
		}
	}

	vector<int> bins = l1;
	if (z3 != -1) bins.push_back(z3);
	if (z4 != -1) bins.push_back(z4);
	sort(bins.begin(),bins.end());

	cout << "z0 = " << z0 << ", z1 = " << z1 << ", z2 = " << z2 << ", z3 = " << z3 << ", z4 = " << z4 << endl;

	vector<int> zdca_bin;
	vector<int> t_bin;

	vector<vector<int>> output;

	TH1F *hs, *hb, *hbnw;

	for (int l = 0; l < (bins.size() -1); l++) {
		zdca_bin = {bins[l],bins[l+1]};
		hs = (TH1F*)th2_s->ProjectionX("hs",bins[l],bins[l+1]);
		hb = (TH1F*)th2_b->ProjectionX("hb",bins[l],bins[l+1]);
		hbnw = (TH1F*)th2_b_nowt->ProjectionX("hbnw",bins[l],bins[l+1]);
		t_bin = find_optimal_timing_binning(hs,hb,hbnw);
		for (int i = 0; i < t_bin.size(); i++) {
			zdca_bin.push_back(t_bin[i]);
		}
		output.push_back(zdca_bin);
	}

	return output;
}


void optimize() {
	
	int runs[] = {403280,403281,403282,403283,403284,403285,403286};
	int size = sizeof(runs)/sizeof(*runs);

	map<int,TString> signal_info;
	signal_info[403280] = "m_{g} = 1000, m_{b} = 900, t = 100 ns";
	signal_info[403281] = "m_{g} = 1300, m_{b} = 100, t = 6 ns";
	signal_info[403282] = "m_{g} = 1300, m_{b} = 1200, t = 6 ns";
	signal_info[403283] = "m_{g} = 1800, m_{b} = 100, t = 2 ns";
	signal_info[403284] = "m_{g} = 1800, m_{b} = 1700, t = 2 ns";
	signal_info[403286] = "m_{g} = 1800, m_{b} = 1700, t = 6 ns";
	
	ofstream outfile;
	outfile.open("binning.txt");
	vector<vector<int>> s1, s2;

	TString message, r1;

	for (int i = 0; i < size; i++) {
		s1 = optimize_zdca_timing("SR1",runs[i]);
		s2 = optimize_zdca_timing("SR2",runs[i]);
		r1.Form("-------------------------------RUN = %i, SR1-------------------------------\n",runs[i]);
		message = r1;
		vector<int> v1, v2;
		for (int k = 0; k < s1.size(); k++) {
			v1 = s1[k];
			message += "ZDCA BIN: ";
			r1.Form("%d < ZDCA < %d, timing bins = {",10*(v1[0]-1),10*(v1[1]-1));
			message += r1;
			for (int j = 2; j < v1.size(); j++) {
				//cout << "edge " << j-1 << " = " < 
				r1.Form("%3.1f, ",-21 + 0.2*(v1[j]-1));
				message += r1;
			}
			message += "}\n";
		}
		r1.Form("-------------------------------RUN = %i, SR2-------------------------------\n",runs[i]);
		message += r1;
		for (int k = 0; k < s2.size(); k++) {
			v2 = s2[k];
			message += "ZDCA BIN: ";
			r1.Form("%d < ZDCA < %d, timing bins = {",10*(v2[0]-1),10*(v2[1]-1));
			message += r1;
			for (int j = 2; j < v2.size(); j++) {
				r1.Form("%3.1f, ",-21 + 0.2*(v2[j]-1));
				message += r1;
			}
			message += "}\n";
		}
		message += "\n\n";
		outfile << message;
	}
	outfile.close();
}