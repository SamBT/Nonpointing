#!/bin/bash
file=$1;
treetype=$2;
jobname=$3;
script=$4

j=0
while read line
do
j=$[1+$j];
k=$[$j/5];

echo $line >> ${jobname}_${k}.txt; 


done<${file}

j=0;
for j in `seq 0 $k`;
 do  qsub -l cvmfs=1 -l h_vmem=2G -l projectio=1 general_analysis.sh ${jobname} $j ${treetype} ${script};
done 

echo "finished job submission " $[$j+1] " jobs submitted. "











