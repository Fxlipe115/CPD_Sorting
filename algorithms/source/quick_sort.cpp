#include "quick_sort.hpp"
#include <algorithm>
#include <fstream>
#include <cstdlib>

QuickSort::QuickSort(std::vector<int>& list) : SortingAlg(list), totalSwaps(0), recursiveCalls(0) {}

void QuickSort::sort(std::vector<int> (*f)(std::vector<int>&)){
  if(f != nullptr){
    quick_sort_rec(0, list.size()-1, f);
  }
}

void QuickSort::generateStats(std::string name){
  std::ofstream file(name + ".data");

  int maxRatio = *std::max_element(ratio.begin(), ratio.end());
  int minRatio = *std::min_element(ratio.begin(), ratio.end());
  float avgRatio = 0;
  for(int i : ratio){
    avgRatio += i;
  }
  avgRatio /= ratio.size();

  file << "Total number of swaps: " << totalSwaps << std::endl;
  file << "Total number of recursive calls: " << recursiveCalls << std::endl;
  file << "Max left/right elements ratio: " << maxRatio << std::endl;
  file << "Min left/right elements ratio: " << minRatio << std::endl;
  file << "Average left/right elements ratio: " << avgRatio << std::endl;

  file.close();
}

void QuickSort::quick_sort_rec(int left, int right, std::vector<int> (*f)(std::vector<int>&)){
  recursiveCalls++;

	int pivot; // índice do pivô
	if (right > left) {
    //joga valores pra lista pq não tem como passar por parâmetro
    list.push_back(right);
    list.push_back(left);

    std::vector<int> v = f(list);
		pivot = v[0];
    totalSwaps += v[1];
    ratio.push_back(v[2]);

		quick_sort_rec (left, pivot-1, f);
		quick_sort_rec (pivot+1, right, f);
  	}
}

std::vector<int> partition(std::vector<int>& C){
  //desfaz a gambiarra anterior
  int left = C[C.size()-1];
  C.pop_back();
  int right = C[C.size()-1];
  C.pop_back();

  int swaps = 0;
  int chave = C[right];
  int i = (left - 1);
  int j;

  for (j = left; j <= right- 1; j++){
    if (C[j] <= chave){
      i++;
      std::swap(C[i], C[j]);
      swaps++;
    }
  }
  std::swap(C[i + 1], C[right]);
  swaps++;

  int ratio = abs((i+1-right)-(i+1-left));
  std::vector<int> pivot = {i+1,swaps,ratio};
	return pivot;
}

std::vector<int> randPartition(std::vector<int>& C){
  //desfaz a gambiarra anterior
  int left = C[C.size()-1];
  C.pop_back();
  int right = C[C.size()-1];
  C.pop_back();

  int swaps = 0;
  int i = left-1, j;
  int chave = (rand() % (right+1-left)) + left;
  std::swap(C[right], C[chave]);
  swaps++;
  chave = C[right];
  for (j = left; j <= right- 1; j++){
    if (C[j] <= chave){
      i++;
      std::swap(C[i], C[j]);
      swaps++;
    }
  }
  std::swap(C[i + 1], C[right]);
  swaps++;

  int ratio = abs((i+1-right)-(i+1-left));
  std::vector<int> pivot = {i+1,swaps,ratio};
	return pivot;
}
