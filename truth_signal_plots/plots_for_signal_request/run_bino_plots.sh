#!/bin/bash

root -b -q "bino_plots_mgfixed.C(\"0p5ns\",0.5,20,0,5,0,10000,2,10)"
root -b -q "bino_plots_mgfixed.C(\"2ns\",2,20,0,10,0,10000,2,10)"
root -b -q "bino_plots_mgfixed.C(\"6ns\",6,20,0,15,0,10000,2,10)"
root -b -q "bino_plots_mgfixed.C(\"10ns\",10,20,0,20,0,10000,,4,10)"
root -b -q "bino_plots_mgfixed.C(\"100ns\",100,20,0,200,0,10000,20,10)"

root -b -q "bino_plots_mxfixed.C(\"0p5ns\",0.5,20,0,5,0,10000,2,10)"
root -b -q "bino_plots_mxfixed.C(\"2ns\",2,20,0,10,0,10000,2,10)"
root -b -q "bino_plots_mxfixed.C(\"6ns\",6,20,0,15,0,10000,2,10)"
root -b -q "bino_plots_mxfixed.C(\"10ns\",10,20,0,20,0,10000,4,10)"
root -b -q "bino_plots_mxfixed.C(\"100ns\",100,20,0,200,0,10000,20,10)"