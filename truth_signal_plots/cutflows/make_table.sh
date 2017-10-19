#!/bin/bash

subdir=$1
tau=$2

diphoton=/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/diphoton/cutflows;
singlephoton=/project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/singlephoton/cutflows;

root -b -q "cutflow_table.C(\"$subdir\",\"dummy\",\"dummy\",0,0,1,0)";
for file in `ls ${diphoton}/${subdir}/`;
do
    dsid=`echo $file | cut -d "_" -f 2 | cut -d "." -f 1`;
    root -b -q "cutflow_table.C(\"$subdir\",\"${singlephoton}/${subdir}/$file\",\"${diphoton}/${subdir}/$file\",$dsid,$tau,0,0)";
done
root -b -q "cutflow_table.C(\"$subdir\",\"dummy\",\"dummy\",0,0,0,1)";