#ifndef SORTING_ALG_HPP
#	define SORTING_ALG_HPP

#include <string>
#include <vector>

class SortingAlg{
	protected:
		std::vector<int> list;
	public:
		SortingAlg(std::vector<int>& list);
		virtual void sort(std::vector<int> (*f)(std::vector<int>&) = nullptr) = 0;
		virtual void generateStats(std::string name) = 0;
		bool isSorted();
		std::vector<int> getList();
};

#endif
