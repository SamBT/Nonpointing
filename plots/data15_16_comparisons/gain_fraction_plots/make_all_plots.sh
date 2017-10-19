#!/bin/bash

root -b -q "plot_all_fractions_diphoton.C(\"Ecell\",\"Ecell Energy [GeV]\",40)"
root -b -q "plot_all_fractions_diphoton.C(\"E\",\"Photon Energy [GeV]\",40)"
root -b -q "plot_all_fractions_diphoton.C(\"pt\",\"p_{T} [GeV]\",40)"

root -b -q "plot_all_fractions_singlephoton.C(\"Ecell\",\"Ecell Energy [GeV]\",40)"
root -b -q "plot_all_fractions_singlephoton.C(\"E\",\"Photon Energy [GeV]\",40)"
root -b -q "plot_all_fractions_singlephoton.C(\"pt\",\"p_{T} [GeV]\",40)"

mv *SBT* /project/projectdirs/atlas/www/sambt/nonpointing_photon/data15_16_comparison/gain_fraction_plots
chmod 777 /project/projectdirs/atlas/www/sambt/nonpointing_photon/data15_16_comparison/gain_fraction_plots/*
