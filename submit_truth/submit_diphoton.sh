#!/bin/bash
ptcut=$1
metcut=$2
jobname=$3
timing=$4
filelist=$5

while read line;
do
    dsid=`echo $line | cut -d "/" -f 9 | cut -d "." -f 1 | cut -d "_" -f 2`
    qsub -l cvmfs=1 -l h_vmem=8G analysis_diphoton.sh ${ptcut} ${metcut} ${jobname} ${line} ${dsid} ${timing}
done<$filelist












