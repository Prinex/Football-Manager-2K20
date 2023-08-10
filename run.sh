#!/bin/sh

./buildPrj.sh

cd build
make
cd ./bin/
echo "Running..."
start Football-Manager-2K20.exe
