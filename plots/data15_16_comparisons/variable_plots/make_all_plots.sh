#!/bin/bash

root -b -q "plot_diphoton_variable.C(\"MET\",\"E_{T}^{miss} [GeV]\",2,0,75,0.7,1.3)"
root -b -q "plot_diphoton_variable.C(\"pointing\",\"Z_{DCA} [mm]\",40,-1000,1000,0.7,1.3)"
root -b -q "plot_diphoton_variable.C(\"timing\",\"t_{#gamma} [ns]\",4,-10,10,0,2)"

root -b -q "plot_singlephoton_variable.C(\"MET\",\"E_{T}^{miss} [GeV]\",2,0,75,0.7,1.3)"
root -b -q "plot_singlephoton_variable.C(\"pointing\",\"Z_{DCA} [mm]\",40,-1000,1000,0.7,1.3)"
root -b -q "plot_singlephoton_variable.C(\"timing\",\"t_{#gamma} [ns]\",4,-10,10,0,2)"

mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/data15_16_comparison/variables_comparison/all_gains
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/data15_16_comparison/variables_comparison/all_gains/*

root -b -q "plot_diphoton_lowgainveto.C(\"MET\",\"E_{T}^{miss} [GeV]\",2,0,75,0.7,1.3)"
root -b -q "plot_diphoton_lowgainveto.C(\"pointing\",\"Z_{DCA} [mm]\",40,-1000,1000,0.7,1.3)"
root -b -q "plot_diphoton_lowgainveto.C(\"timing\",\"t_{#gamma} [ns]\",4,-10,10,0,2)"

root -b -q "plot_singlephoton_lowgainveto.C(\"MET\",\"E_{T}^{miss} [GeV]\",2,0,75,0.7,1.3)"
root -b -q "plot_singlephoton_lowgainveto.C(\"pointing\",\"Z_{DCA} [mm]\",40,-1000,1000,0.7,1.3)"
root -b -q "plot_singlephoton_lowgainveto.C(\"timing\",\"t_{#gamma} [ns]\",4,-10,10,0,2)"

mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/data15_16_comparison/variables_comparison/low_gain_veto
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/data15_16_comparison/variables_comparison/low_gain_veto/*