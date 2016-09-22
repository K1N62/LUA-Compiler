#!/bin/bash

make

for i in `seq 1 6`; do
./bin/compiler -o tests/test$i/test$i.c tests/test$i/test$i.lua
g++ -o tests/test$i/test$i tests/test$i/test$i.c
make graph
mv *.pdf tests/test$1/
done
