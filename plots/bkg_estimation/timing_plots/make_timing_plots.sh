#!/bin/bash

root -b -q "plot_singlephoton_timing.C(1,\"0 < |Z_{DCA}| < 40 mm\",0,40)"
root -b -q "plot_singlephoton_timing.C(2,\"40 < |Z_{DCA}| < 80 mm\",40,80)"
root -b -q "plot_singlephoton_timing.C(3,\"80 < |Z_{DCA}| < 120 mm\",80,120)"
root -b -q "plot_singlephoton_timing.C(4,\"120 < |Z_{DCA}| < 1600 mm\",120,160)"
root -b -q "plot_singlephoton_timing.C(5,\"160 < |Z_{DCA}| < 200 mm\",160,200)"
root -b -q "plot_singlephoton_timing.C(6,\"200 < |Z_{DCA}| < 2000 mm\",200,2000)"

root -b -q "plot_diphoton_timing.C(1,\"0 < |Z_{DCA}| < 40 mm\",0,40)"
root -b -q "plot_diphoton_timing.C(2,\"40 < |Z_{DCA}| < 80 mm\",40,80)"
root -b -q "plot_diphoton_timing.C(3,\"80 < |Z_{DCA}| < 120 mm\",80,120)"
root -b -q "plot_diphoton_timing.C(4,\"120 < |Z_{DCA}| < 1600 mm\",120,160)"
root -b -q "plot_diphoton_timing.C(5,\"160 < |Z_{DCA}| < 200 mm\",160,200)"
root -b -q "plot_diphoton_timing.C(6,\"200 < |Z_{DCA}| < 2000 mm\",200,2000)"
