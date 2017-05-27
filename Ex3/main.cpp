#include "merge_sort.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <iomanip>

int main(){
	
	std::cout << "# Size | Merge Sort | Hybrid Sort | Insertion Sort" << std::endl;
	
	for(int i = 100; i <= 1000; i+=50){
		
		std::vector<int> v;
		for(int j = 0; j < i; j++){
			v.push_back(rand()%(i*10));
		}

		std::vector<int> v0(v);
		std::vector<int> v1(v);
		std::vector<int> v2(v);

		
		clock_t start, end;

		double tMerge = 0;
		for(int j = 0; j < 1000; j++){
			start = clock();
			mergeSort(v0);
			end = clock();
			tMerge += (end - start)/(double)CLOCKS_PER_SEC;
		}
		tMerge /= 1000;
		
		double tHybrid = 0;
		for(int j = 0; j < 1000; j++){
			start = clock();
			mergeSort(v1,10);
			end = clock();
			tHybrid += (end - start)/(double)CLOCKS_PER_SEC;
		}
		tHybrid /= 1000;
		
		double tInsertion = 0;
		for(int j = 0; j < 1000; j++){
			start = clock();
			mergeSort(v2,i);
			end = clock();
			tInsertion += (end - start)/(double)CLOCKS_PER_SEC;
		}
		tInsertion /= 1000;

		std::cout << i << " ";
		std::cout << std::fixed << std::setprecision(10) << tMerge << " ";
		std::cout << std::fixed << std::setprecision(10) << tHybrid << " ";
		std::cout << std::fixed << std::setprecision(10) << tInsertion << std::endl;
	}
	
    return 0;
}
