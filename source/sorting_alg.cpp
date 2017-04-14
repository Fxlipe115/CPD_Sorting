#include "sorting_alg.hpp"

SortingAlg::SortingAlg(std::vector<int>& list) : list(list) {}

bool SortingAlg::isSorted(){
	for (int i = 1, size = list.size(); i < size; i++) {
		if ( list[i-1] > list[i])
			return false;
		}
	return true;
}

std::vector<int> SortingAlg::getList(){
	return list;
}