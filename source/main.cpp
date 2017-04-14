#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "sorting_alg.hpp"
#include "bubble_sort.hpp"
#include "shell_sort.hpp"

void plotTime(SortingAlg& alg, std::string name, int N, std::vector<int> (*f)(int) = nullptr);

int main(){
  
  printf("# Algoritmo,N,Segundos\n");

  
  for ( int N = 10000 ; N <= 1000000 ; N += 10000){

    /* 1 - gerar array com N elementos  */
    std::vector<int> input;
    for (int i=0; i<N; i++)
      input.push_back(rand() % N+1);


    /* 2 - medir tempo do shell sort */
    std::vector<int> insSort(input);
	
	ShellSort shell1(insSort);
    
	//plotTime(shell1, "Shell1", N, seq1);
	
	
	
	std::vector<int> insSort2(input);
	
	ShellSort shell2(insSort2);
    
	//plotTime(shell2, "Shell2", N, seq2);
    

    /***********************************************/
    
    /* 2 - medir tempo bubble sort */
    std::vector<int> bbSort(input);
    
    BubbleSort bubble1(bbSort);
	
	plotTime(bubble1, "Bubble", N);    
  }

  return 0;
}

void plotTime(SortingAlg& alg, std::string name, int N, std::vector<int> (*f)(int)){
	clock_t start, end;
	
	start = clock();
    alg.sort(f);
    end = clock();
	
	std::ofstream file("data/" + name + "_time.plt", std::ofstream::out | std::ofstream::app);
	
	if(alg.isSorted()){
		//for redirecting to .csv file
		std::cout << name << "," << N << "," << std::fixed << std::setprecision(10) << (end - start)/(double)CLOCKS_PER_SEC << std::endl;
		//for use with gnuplot
		file << N << " " << std::fixed << std::setprecision(10) << (end - start)/(double)CLOCKS_PER_SEC << std::endl;
	}else{
		std::cerr << "Erro no " << name << std::endl;
	}
	
	file.close();
}