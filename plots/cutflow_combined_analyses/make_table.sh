#!/bin/bash

root -b -q "cutflow_table.C(0,1,0)";
for file in `ls /project/projectdirs/atlas/sambt/BatchOutput/nonpointing/reco_signal/combined/HIGG1D1_derivation`;
do
    dsid=`echo $file | cut -d "." -f 1 | cut -d "_" -f 2`;
    root -b -q "cutflow_table.C($dsid,0,0)";
done
root -b -q "cutflow_table.C(0,0,1)";