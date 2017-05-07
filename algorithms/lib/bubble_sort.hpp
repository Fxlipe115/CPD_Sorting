#ifndef BUBBLE_SORT_HPP
#	define BUBBLE_SORT_HPP

#include "sorting_alg.hpp"

class BubbleSort : public SortingAlg{
	private:
		unsigned int swaps;
	public:
		BubbleSort(std::vector<int>& list);
		void sort(std::vector<int> (*f)(int) = nullptr) override;
		void generateStats(std::string name) override;
};

#endif
