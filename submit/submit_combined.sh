#!/bin/bash
jobname=$1
filelist=$2
j=1

while read line;
do
    dsid=`echo $line | cut -d "/" -f 9 | cut -d "." -f 1 | cut -d "_" -f 2`
    sbatch analysis_combined.sh ${jobname} ${line} ${dsid}
done<$filelist












