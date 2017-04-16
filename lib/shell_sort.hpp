#ifndef SHELL_SORT_HPP
#	define SHELL_SORT_HPP

#include "sorting_alg.hpp"
#include <vector>

class ShellSort : public SortingAlg{
	private:
		int iterations;
		std::vector<int> segments;
		std::vector<int> swaps;
		unsigned int totalSwaps;
	public:
		ShellSort(std::vector<int>& list);
		void sort(std::vector<int> (*f)(int) = nullptr) override;
		void generateStats(std::string name) override;
};

std::vector<int> seq1(int h);
std::vector<int> seq2(int h);

#endif
