#!/bin/bash

rm *.tex
rm hist_*.root

touch cutflow_0p5ns.tex;
touch cutflow_2ns.tex;
touch cutflow_6ns.tex;
touch cutflow_10ns.tex;
touch cutflow_100ns.tex;

touch cutflow_unwt_0p5ns.tex;
touch cutflow_unwt_2ns.tex;
touch cutflow_unwt_6ns.tex;
touch cutflow_unwt_10ns.tex;
touch cutflow_unwt_100ns.tex;

cp template.root hist_0p5ns.root;
cp template.root hist_2ns.root;
cp template.root hist_6ns.root;
cp template.root hist_10ns.root;
cp template.root hist_100ns.root;

cp template.root hist_unwt_0p5ns.root;
cp template.root hist_unwt_2ns.root;
cp template.root hist_unwt_6ns.root;
cp template.root hist_unwt_10ns.root;
cp template.root hist_unwt_100ns.root;
