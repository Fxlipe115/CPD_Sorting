#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>

int binary_search (std::vector<int>& a,int key,int low=0,int high=-1);
void binary_insertion_sort(std::vector<int>& C,int low,int high);
void mergeSort(std::vector<int>& l,int k=0);
void mergeSort(std::vector<int>& l,int k,int low,int high);

#endif
