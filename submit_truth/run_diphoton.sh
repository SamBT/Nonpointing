#!/bin/bash

jobname=$1

./submit_diphoton.sh 0 0 ${jobname} 0p5ns truth_signal_t0p5.txt
./submit_diphoton.sh 0 0 ${jobname} 2ns truth_signal_t2.txt
./submit_diphoton.sh 0 0 ${jobname} 6ns truth_signal_t6.txt
./submit_diphoton.sh 0 0 ${jobname} 10ns truth_signal_t10.txt
./submit_diphoton.sh 0 0 ${jobname} 100ns truth_signal_t100.txt