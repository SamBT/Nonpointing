#!/bin/bash

rm *.tex
rm hist_*.root

touch cutflow.tex
touch cutflow_unwt.tex

touch acceptance.tex
touch acceptance_unwt.tex

cp template.root hist_403280.root;
cp template.root hist_403281.root;
cp template.root hist_403282.root;
cp template.root hist_403283.root;
cp template.root hist_403284.root;
cp template.root hist_403285.root;
cp template.root hist_403286.root;

cp template.root hist_unwt_403280.root;
cp template.root hist_unwt_403281.root;
cp template.root hist_unwt_403282.root;
cp template.root hist_unwt_403283.root;
cp template.root hist_unwt_403284.root;
cp template.root hist_unwt_403285.root;
cp template.root hist_unwt_403286.root;
