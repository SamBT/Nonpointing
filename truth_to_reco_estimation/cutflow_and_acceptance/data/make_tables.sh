#!/bin/bash 

./prepare_output_files.sh

root -b -q "cutflow_table_2015.C(1,0)"
root -b -q "cutflow_table_2015.C(0,0)"
root -b -q "cutflow_table_2015.C(0,1)"

root -b -q "cutflow_table_2016.C(1,0)"
root -b -q "cutflow_table_2016.C(0,0)"
root -b -q "cutflow_table_2016.C(0,1)"

root -b -q "acceptance_table_2015.C(1,0)"
root -b -q "acceptance_table_2015.C(0,0)"
root -b -q "acceptance_table_2015.C(0,1)"

root -b -q "acceptance_table_2016.C(1,0)"
root -b -q "acceptance_table_2016.C(0,0)"
root -b -q "acceptance_table_2016.C(0,1)"