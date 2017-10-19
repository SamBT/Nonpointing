#!/bin/bash

#mg=$1
#mx=$2

#fixed mg, varied mx
root -b -q "plot_var_mgfixed.C(\"pt\",\"0p5ns\",0.5,20,0,1000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"pt\",\"2ns\",2,20,0,1000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"pt\",\"6ns\",6,20,0,1000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"pt\",\"10ns\",10,20,0,1000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"pt\",\"100ns\",100,20,0,1000,0,1000)"

root -b -q "plot_var_mgfixed.C(\"eta\",\"0p5ns\",0.5,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mgfixed.C(\"eta\",\"2ns\",2,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mgfixed.C(\"eta\",\"6ns\",6,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mgfixed.C(\"eta\",\"10ns\",10,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mgfixed.C(\"eta\",\"100ns\",100,10,-2.5,2.5,-2.5,2.5)"

root -b -q "plot_var_mgfixed.C(\"timing\",\"0p5ns\",0.5,10,0,10,0,10)"
root -b -q "plot_var_mgfixed.C(\"timing\",\"2ns\",2,10,0,10,0,10)"
root -b -q "plot_var_mgfixed.C(\"timing\",\"6ns\",6,10,0,10,0,10)"
root -b -q "plot_var_mgfixed.C(\"timing\",\"10ns\",10,10,0,10,0,10)"
root -b -q "plot_var_mgfixed.C(\"timing\",\"100ns\",100,10,0,10,0,10)"

root -b -q "plot_var_mgfixed.C(\"pointing\",\"0p5ns\",0.5,1,0,11,0,11)"
root -b -q "plot_var_mgfixed.C(\"pointing\",\"2ns\",2,1,0,11,0,11)"
root -b -q "plot_var_mgfixed.C(\"pointing\",\"6ns\",6,1,0,11,0,11)"
root -b -q "plot_var_mgfixed.C(\"pointing\",\"10ns\",10,1,0,11,0,11)"
root -b -q "plot_var_mgfixed.C(\"pointing\",\"100ns\",100,1,0,11,0,11)"

root -b -q "plot_var_mgfixed.C(\"MET\",\"0p5ns\",0.5,50,0,2000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"MET\",\"2ns\",2,50,0,2000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"MET\",\"6ns\",6,50,0,2000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"MET\",\"10ns\",10,50,0,2000,0,1000)"
root -b -q "plot_var_mgfixed.C(\"MET\",\"100ns\",100,50,0,2000,0,1000)"

#fixed mx, varied mg
root -b -q "plot_var_mxfixed.C(\"pt\",\"0p5ns\",0.5,20,0,1000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"pt\",\"2ns\",2,20,0,1000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"pt\",\"6ns\",6,20,0,1000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"pt\",\"10ns\",10,20,0,1000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"pt\",\"100ns\",100,20,0,1000,0,1000)"

root -b -q "plot_var_mxfixed.C(\"eta\",\"0p5ns\",0.5,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mxfixed.C(\"eta\",\"2ns\",2,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mxfixed.C(\"eta\",\"6ns\",6,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mxfixed.C(\"eta\",\"10ns\",10,10,-2.5,2.5,-2.5,2.5)"
root -b -q "plot_var_mxfixed.C(\"eta\",\"100ns\",100,10,-2.5,2.5,-2.5,2.5)"

root -b -q "plot_var_mxfixed.C(\"timing\",\"0p5ns\",0.5,10,0,10,0,10)"
root -b -q "plot_var_mxfixed.C(\"timing\",\"2ns\",2,10,0,10,0,10)"
root -b -q "plot_var_mxfixed.C(\"timing\",\"6ns\",6,10,0,10,0,10)"
root -b -q "plot_var_mxfixed.C(\"timing\",\"10ns\",10,10,0,10,0,10)"
root -b -q "plot_var_mxfixed.C(\"timing\",\"100ns\",100,10,0,10,0,10)"

root -b -q "plot_var_mxfixed.C(\"pointing\",\"0p5ns\",0.5,1,0,11,0,11)"
root -b -q "plot_var_mxfixed.C(\"pointing\",\"2ns\",2,1,0,11,0,11)"
root -b -q "plot_var_mxfixed.C(\"pointing\",\"6ns\",6,1,0,11,0,11)"
root -b -q "plot_var_mxfixed.C(\"pointing\",\"10ns\",10,1,0,11,0,11)"
root -b -q "plot_var_mxfixed.C(\"pointing\",\"100ns\",100,1,0,11,0,11)"

root -b -q "plot_var_mxfixed.C(\"MET\",\"0p5ns\",0.5,50,0,2000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"MET\",\"2ns\",2,50,0,2000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"MET\",\"6ns\",6,50,0,2000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"MET\",\"10ns\",10,50,0,2000,0,1000)"
root -b -q "plot_var_mxfixed.C(\"MET\",\"100ns\",100,50,0,2000,0,1000)"


