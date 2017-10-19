#!/bin/bash
jobname=$1
filelist=$2
j=1

while read line;
do
    sbatch analysis_data_combined.sh ${jobname} ${line} ${j}
    j=`expr $j + 1`
done<$filelist












