#!/bin/bash
cd axis_cv
git pull
cd ..
cd axis_ptz
git pull
cd ..
cd build
cmake ..
make
