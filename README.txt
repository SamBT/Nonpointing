

mkdir run ;
cd run ;
cp /projecta/projectdirs/atlas/haichen/nonpointing/example/analysis.tar.gz .
cp /projecta/projectdirs/atlas/haichen/nonpointing/example/testdata_1093ipb.root .

tar zxvf analysis.tar.gz;

# compiling analysis.cc(hh) in the src directory
make analysis ;

# take a look at ./src/analysis.cc
# it makes some simple selection on the events and photons, then fill histograms and write them into a root file. 
# you should understand everything in analysis.cc(hh), then start modifying it 
# everytime analysis.cc/hh is modified, compile the code by
make analysis;

# an executable should be created in ./bin, and a .o file is created in ./lib

# execute the code by

./bin/analysis testdata_1093ipb.root

# output.root should be created.

root -b -q Draw.C ;

# Draw.C is a simple macro to make some plots using histograms saved in output.root
