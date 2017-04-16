#include <fstream>
#include "bubble_sort.hpp"

BubbleSort::BubbleSort(std::vector<int>& list) : SortingAlg(list), swaps(0) {}

void BubbleSort::sort(std::vector<int> (*f)(int)){
	//recebe nulo por padrão
	int swp;
	bool changed = true;

	for(int i = 0, size = list.size(); i < size - 1 && changed; i++){
		changed = false;

		for(int j = 0; j < size - (i+1); j++){

			if(list[j] > list[j+1]){

				swp = list[j];
				list[j] = list[j+1];
				list[j+1] = swp;

				changed = true;
				swaps++;
			}
		}
	}
}

void BubbleSort::generateStats(std::string name){
	std::ofstream file(name + ".data");

	file << "# For array of size " << list.size() << std::endl;
	file << "# Using Bubble Sort" << std::endl;
	file << "# Total number of swaps = " << swaps << std::endl;

	file.close();
}
