#!/bin/bash
ptcut=$1
metcut=$2
jobname=$3
file=$4
dsid=$5
lifetime=$6



date
mkdir /project/projectdirs/atlas/sambt/jobs
rm -rf /project/projectdirs/atlas/sambt/jobs/nonpointing/analysis_singlephoton_${jobname}_${dsid}
mkdir /project/projectdirs/atlas/sambt/jobs/nonpointing/analysis_singlephoton_${jobname}_${dsid}
cd /project/projectdirs/atlas/sambt/jobs/nonpointing/analysis_singlephoton_${jobname}_${dsid}

shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS -q # make these commands quiet
localSetupROOT -q 

cp /global/homes/s/sambt/workarea/nonpointing/bin/singlephoton_truth .

./singlephoton_truth ptcut metcut $file; 

mkdir /project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/singlephoton/${jobname}
mkdir /project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/singlephoton/${jobname}/${lifetime}

mv output.root /project/projectdirs/atlas/sambt/BatchOutput/nonpointing/truth_signal/singlephoton/${jobname}/${lifetime}/output_${dsid}.root

cd ;
rm -rf  /project/projectdirs/atlas/sambt/jobs/nonpointing/analysis_singlephoton_${jobname}_${dsid} ;
date
