#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "sorting_alg.hpp"
#include <vector>

class QuickSort : public SortingAlg{
	private:
		std::vector<int> ratio;
		unsigned int totalSwaps;
    int recursiveCalls;
    void quick_sort_rec(int left, int right, std::vector<int> (*f)(std::vector<int>&));
	public:
		QuickSort(std::vector<int>& list);
		void sort(std::vector<int> (*f)(std::vector<int>&) = nullptr) override;
		void generateStats(std::string name) override;
};

std::vector<int> partition(std::vector<int>& C);

std::vector<int> randPartition(std::vector<int>& C);

#endif
