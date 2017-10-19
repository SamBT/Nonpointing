#!/bin/bash
jobname=$1
file=$2
dsid=$3


date
mkdir /project/projectdirs/atlas/sambt/jobs
rm -rf /project/projectdirs/atlas/sambt/jobs/nonpointing/data_runs/analysis_combined_${jobname}_${dsid}
mkdir /project/projectdirs/atlas/sambt/jobs/nonpointing/data_runs/analysis_combined_${jobname}_${dsid}
cd /project/projectdirs/atlas/sambt/jobs/nonpointing/data_runs/analysis_combined_${jobname}_${dsid}

shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS -q # make these commands quiet
localSetupROOT -q 

cp /global/homes/s/sambt/workarea/nonpointing/bin/combined .

./combined $file; 

mkdir /project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/${jobname}

mv output.root /project/projectdirs/atlas/sambt/BatchOutput/nonpointing/data/combined_analyses/${jobname}/output_${dsid}.root

cd ;
rm -rf  /project/projectdirs/atlas/sambt/jobs/nonpointing/data_runs/analysis_combined_${jobname}_${dsid} ;
date
