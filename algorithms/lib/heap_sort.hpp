#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "sorting_alg.hpp"
#include <vector>

class HeapSort : public SortingAlg{
	private:

	public:
		HeapSort(std::vector<int>& list);
		void sort(std::vector<int> (*f)(std::vector<int>&) = nullptr) override;
		void generateStats(std::string name) override;
};

#endif
