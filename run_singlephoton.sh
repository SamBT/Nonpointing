#!/bin/bash

#pass integer 1 to run everything
#pass integer 0 to just run signal
argt=$1

if [ "$type" == "1" ] 
    then 
        ./bin/singlephoton 150 75 singlephoton_files/data.root
	mv output.root analysis_output/singlephoton/data/output_data.root
fi
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403280.root
mv output.root analysis_output/singlephoton/signal/403280.root
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403281.root
mv output.root analysis_output/singlephoton/signal/403281.root
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403282.root
mv output.root analysis_output/singlephoton/signal/403282.root
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403283.root
mv output.root analysis_output/singlephoton/signal/403283.root
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403284.root
mv output.root analysis_output/singlephoton/signal/403284.root
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403285.root
mv output.root analysis_output/singlephoton/signal/403285.root
./bin/singlephoton 150 75 singlephoton_files/EXOT6_403286.root
mv output.root analysis_output/singlephoton/signal/403286.root