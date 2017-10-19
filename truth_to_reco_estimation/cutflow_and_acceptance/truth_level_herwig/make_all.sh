#!/bin/bash

root -b -q "cutflow_table.C(0,1,0)"
root -b -q "cutflow_table.C(403280,0,0)"
root -b -q "cutflow_table.C(403281,0,0)"
root -b -q "cutflow_table.C(403282,0,0)"
root -b -q "cutflow_table.C(403283,0,0)"
root -b -q "cutflow_table.C(403284,0,0)"
root -b -q "cutflow_table.C(403285,0,0)"
root -b -q "cutflow_table.C(403286,0,0)"
root -b -q "cutflow_table.C(0,0,1)"

root -b -q acceptance_table.C