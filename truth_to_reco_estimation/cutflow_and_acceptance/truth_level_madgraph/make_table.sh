#!/bin/bash

subdir=$1
tau=$2

dir=/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/combined/cutflows

root -b -q "cutflow_table.C(\"$subdir\",\"dummy\",0,0,1,0)";
for file in `ls ${dir}/${subdir}/`;
do
    dsid=`echo $file | cut -d "_" -f 2 | cut -d "." -f 1`;
    root -b -q "cutflow_table.C(\"$subdir\",\"${dir}/${subdir}/$file\",$dsid,$tau,0,0)";
done
root -b -q "cutflow_table.C(\"$subdir\",\"dummy\",0,0,0,1)";