#!/bin/bash

mkdir -p build

# build exec for cpp

cd build
cmake ../
make -j


# build exec for python

# cd build
# cmake ../ -DPYTHON=true
# make -j

./lifelong --inputFile ../example_problems/warehouse.domain/warehouse_small_10.json -o ../../PlanViz/example/test.json
cd /home/maria/UJI_multirobot/PlanViz/script
python3 plan_viz.py --map ../example/warehouse_small.map --plan ../build/test.json --grid --aid --static --ca