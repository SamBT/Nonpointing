#!/bin/bash

#pass integer 1 to run everything
#pass integer 0 to just run signal
argt=$1

if [ "$argt" == "1" ] 
    then 
        echo 'ding'
        ./bin/diphoton 50 75 diphoton_files/data.root
        mv output.root analysis_output/diphoton/data/output_data.root
fi
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403280.root
mv output.root analysis_output/diphoton/signal/403280.root
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403281.root
mv output.root analysis_output/diphoton/signal/403281.root
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403282.root
mv output.root analysis_output/diphoton/signal/403282.root
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403283.root
mv output.root analysis_output/diphoton/signal/403283.root
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403284.root
mv output.root analysis_output/diphoton/signal/403284.root
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403285.root
mv output.root analysis_output/diphoton/signal/403285.root
./bin/diphoton 50 75 diphoton_files/HIGG1D1_403286.root
mv output.root analysis_output/diphoton/signal/403286.root
