double significance(double s, double b) {
	return sqrt(2*((s+b)*log(1+s/b)-s));	
}

double comb_sig(TH1F *hs, TH1F *hb, vector<int> sigs) {
	int n = sigs.size() - 1;
	double s = 0;
	for (int i = 0; i < n; i++) {
		if (sigs[i] == 1) {
			if (hb->Integral(sigs[i],sigs[i+1]) == 0) continue;
			s += pow(significance(hs->Integral(sigs[i],sigs[i+1]),hb->Integral(sigs[i],sigs[i+1])), 2);
		}
		if (i+1 == n) { 
			if (hb->Integral(sigs[i]+1,sigs[i+1]) == 0) continue;
			s += pow(significance(hs->Integral(sigs[i],sigs[i+1]),hb->Integral(sigs[i],sigs[i+1])), 2);
		}
		if ( (i+1 !=n ) && (sigs[i] != 1)) {
			if (hb->Integral(sigs[i]+1,sigs[i+1]) == 0) continue;
			s += pow(significance(hs->Integral(sigs[i],sigs[i+1]),hb->Integral(sigs[i],sigs[i+1])), 2);
		}	
	}
	s = sqrt(s);
	return s;
}

int best_between(TH1F *hs, TH1F *hb, TH1F *hb_nw, int low, int high) {
	double s1, s2;
	s1 = 0;
	s2 = 0;
	double s = 0;
	double sig = 0;
	int bin = -1;
	for (int i = low; i <= high; i++) {
		if (hb_nw->Integral(low, i) <= 10 || hb_nw->Integral(i,high) <= 10) continue;
		s1 = significance(hs->Integral(low,i),hb->Integral(low, i));
		s2 = significance(hs->Integral(i,high),hb->Integral(i, high));
		s = sqrt(pow(s1,2) + pow(s2,2));
		if (s > sig) {sig = s; bin = i;}
	}
	if (bin == -1) bin = 99999;
	return bin;
}

int best_between_comb(TH1F *hs, TH1F *hb, int low, int high, vector<int> places) {
	double s1, s2;
	double s = 0;
	double sig = 0;
	int bin = -1;
	vector<int> test;
	for (int i = low; i <= high; i++) {
		test = places;
		test.push_back(i);
		sort(test.begin(),test.end());
		s = comb_sig(hs,hb,test);
		if (s > sig) {sig = s; bin = i;}
	}
	if (bin == -1) bin = low;
	return bin;
}