#!/bin/bash                            
jobname=$1
j=$2
treetype=$3
script=$4

date
mkdir -p  /project/projectdirs/atlas/sambt/analysis
rm -rf /project/projectdirs/atlas/sambt/analysis/analysis_${jobname}_${j}
mkdir /project/projectdirs/atlas/sambt/analysis/analysis_${jobname}_${j}
cd /project/projectdirs/atlas/sambt/analysis/analysis_${jobname}_${j}

shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS
localSetupROOT
cp /global/homes/s/sambt/workarea/RPV_2/bin/${script} .

mkdir files;
mkdir GRLs;
cp /global/homes/s/sambt/workarea/RPV_2/submit/${jobname}_${j}.txt ./files;
cp /global/homes/s/sambt/workarea/RPV_2/GRLs/GRL.xml ./GRLs

./${script} ${treetype} ${jobname}_${j}.txt
 
mkdir /project/projectdirs/atlas/sambt/BatchOutput/RPV/${jobname}/

mv HT_njet.root /project/projectdirs/atlas/sambt/BatchOutput/RPV/${jobname}/HT_njet_${jobname}_${j}.root

mv btag.txt /project/projectdirs/atlas/sambt/BatchOutput/RPV/${jobname}/btag_${j}.txt
mv bveto.txt /project/projectdirs/atlas/sambt/BatchOutput/RPV/${jobname}/bveto_${j}.txt

cd ;
rm -rf /project/projectdirs/atlas/sambt/analysis/analysis_${jobname}_${j} ;
date

