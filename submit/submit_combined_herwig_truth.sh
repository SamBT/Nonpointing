#!/bin/bash
jobname=$1
filelist=$2
j=1

while read line;
do
    dsid=`echo $line | cut -d "/" -f 8 | cut -d "." -f 1 | cut -d "_" -f 2`
    qsub -l cvmfs=1 -l h_vmem=8G analysis_combined_herwig_truth.sh ${jobname} ${line} ${dsid}
done<$filelist












