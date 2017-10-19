void interpolate_ratio_mg_mx() {
  double mgs[] = {1300,1800,1800};
  double mxs[] = {100,100,1700};
  //  double diphoton_vals[] = {0.605993,0.479244,0.84197};
  // double singlephoton_vals[] = {0.2748,0.173031,0.542227};
  double diphoton_vals[] = {0.606049,0.479223,0.841991};
  double singlephoton_vals[] = {0.274821,0.173021,0.542241};

  double mg_for_line[] = {1800,1300}; //We are parametrizing val(mg)/val(mg = 1300) = a*mg + b with mx fixed, so the first point is 1 at (1300,100) and then second is ratio of val at (1800,100) to (1300,100)
  //  double ratio_by_mg_di[] = {1,0.605993/0.479244};
  //double ratio_by_mg_single[] = {1, 0.2748/0.173031};
  double ratio_by_mg_di[] = {1, 0.606049/0.479223};
  double ratio_by_mg_single[] = {1, 0.274821/0.173021};

  double mx_for_line[] = {100,1700};
  //  double ratio_by_mx_di[] = {1,0.84197/0.479244};
  //  double ratio_by_mx_single[] = {1,0.542227/0.173031};
  double ratio_by_mx_di[] = {1, 0.841991/0.479223};
  double ratio_by_mx_single[] = {1, 0.542241/0.173021};

  TGraph di_mg(2,mg_for_line,ratio_by_mg_di);
  TGraph single_mg(2,mg_for_line,ratio_by_mg_single);
  
  TGraph di_mx(2,mx_for_line,ratio_by_mx_di);
  TGraph single_mx(2,mx_for_line,ratio_by_mx_single);

  ofstream di("output_diphoton_6ns_interpolated.txt");
  ofstream single("output_singlephoton_6ns_interpolated.txt");

  double mg, mx, val_d, val_s;

  for (int i = 8; i <= 20; i++) {
    for (int j = 1; j <= i; j++) {
      mg = 100*i;
      mx = 100*j;

      //      if (mg == 1300 && mx == 1200) {
      //	cout << "diphoton mg interp = " << di_mg.Eval(mg)*0.479244 << endl;
      //	cout << "singlephoton mg interp = " << single_mg.Eval(mg)*0.173031 << endl;
      // }

      //      val_d = (di_mg.Eval(mg)*0.479244)*di_mx.Eval(mx);
      //val_s = (single_mg.Eval(mg)*0.173031)*single_mx.Eval(mx);
      val_d = (di_mg.Eval(mg)*0.479223)*di_mx.Eval(mx);
      val_s = (single_mg.Eval(mg)*0.173021)*single_mx.Eval(mx);
      
      di << mg << " " << mx << " " << val_d << "\n";
      single << mg << " " << mx << " " << val_s << "\n";
    }
  }

}
      
      
