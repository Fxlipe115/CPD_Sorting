#!/bin/sh

# Roda os experimentos e cria um arquivo .csv
echo "Algo,N,time,k" > out.csv
for i in $(seq 100 50 1000) ; do 
./build/HybridSort $i 64;
done >> out.csv

# Plota os graficos usando o script R
Rscript plot.R
