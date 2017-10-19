#!/bin/bash

root -b -q "plot_hists.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_text/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_text/t_greater2/*

root -b -q "plot_hists_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color/t_greater2/*

root -b -q "plot_hists_contour.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_contour.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_contour.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_contour.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_contour.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_contour/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_contour/t_greater2/*

root -b -q "plot_hists_cont_and_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_cont_and_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_cont_and_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_cont_and_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_hists_cont_and_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color_contour/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color_contour/t_greater2/*

##############

root -b -q "plot_hists.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_text/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_text/t_greater2_less4/*

root -b -q "plot_hists_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color/t_greater2_less4/*

root -b -q "plot_hists_contour.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_contour.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_contour.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_contour.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_contour.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_contour/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_contour/t_greater2_less4/*

root -b -q "plot_hists_cont_and_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_cont_and_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_cont_and_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_cont_and_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_hists_cont_and_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color_contour/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/cutflow_color_contour/t_greater2_less4/*

##############


root -b -q "plot_acceptance.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_text/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_text/t_greater2/*

root -b -q "plot_acceptance_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color/t_greater2/*

root -b -q "plot_acceptance_contour.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_contour.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_contour.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_contour.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_contour.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_contour/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_contour/t_greater2/*

root -b -q "plot_acceptance_cont_and_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, t_{#gamma} > 2ns\",\"E_{T}^{miss} > 75 GeV, t_{#gamma} > 2ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color_contour/t_greater2/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color_contour/t_greater2/*

##############                                                                                                                                                                                                                              

root -b -q "plot_acceptance.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_text/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_text/t_greater2_less4/*

root -b -q "plot_acceptance_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color/t_greater2_less4/*

root -b -q "plot_acceptance_contour.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_contour.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_contour.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_contour.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_contour.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_contour/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_contour/t_greater2_less4/*

root -b -q "plot_acceptance_cont_and_col.C(\"0p5ns\",0.5,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"2ns\",2,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"6ns\",6,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"10ns\",10,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
root -b -q "plot_acceptance_cont_and_col.C(\"100ns\",100,11,8,\"E_{T}^{miss} > 200 GeV, 2 < t_{#gamma} < 4ns\",\"E_{T}^{miss} > 75 GeV, 2 < t_{#gamma} < 4ns\")"
mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color_contour/t_greater2_less4/
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/truth_signal_plots/combined_singlephoton_diphoton_analysis/acceptance_color_contour/t_greater2_less4/*