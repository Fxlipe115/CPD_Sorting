#ifndef SORTING_ALG_HPP
#	define SORTING_ALG_HPP

#include <string>
#include <vector>

class SortingAlg{
	protected:
		std::vector<int> list;
	public:
		SortingAlg(std::vector<int>& list);
		virtual void sort(std::vector<int> (*f)(int) = nullptr) = 0;
		virtual void generateStats(std::string file) = 0;
		bool isSorted();
		std::vector<int> getList();
};

#endif