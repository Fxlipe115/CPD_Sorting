#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include "quick_sort.hpp"

int findKeys(SortingAlg& keys, SortingAlg& padlocks, std::string name, bool random);

int main(int argc, char const *argv[]) {
  if(argc < 3){
    std::cerr << "Usage: " << "./main keysfile padlocksfile" << '\n';
  }else{
    std::ifstream keysfile(argv[1]);
    std::ifstream padlocksfile(argv[2]);
    std::vector<int> keys;
    std::vector<int> padlocks;

    std::string aux;
    while(std::getline(keysfile, aux)){
      std::cout << aux << '\n';
      keys.push_back(std::stoi(aux));
    }

    while(std::getline(padlocksfile, aux)){
      padlocks.push_back(std::stoi(aux));
    }


    std::vector<int> keys1(keys);
    std::vector<int> padlocks1(padlocks);
    QuickSort quickkeys1(keys1);
    QuickSort quickpadlocks1(padlocks1);
    findKeys(quickkeys1, quickpadlocks1, "quick_sort", false);

    std::vector<int> keys2(keys);
    std::vector<int> padlocks2(padlocks);
    QuickSort quickkeys2(keys2);
    QuickSort quickpadlocks2(padlocks2);
    findKeys(quickkeys2, quickpadlocks2, "quick_sort_ramdom", true);
  }
  return 0;
}

int findKeys(SortingAlg& keys, SortingAlg& padlocks, std::string name, bool random){
  clock_t start, end;

	start = clock();
  if(!random){
    keys.sort(partition);
    padlocks.sort(partition);
  }else{
    keys.sort(randPartition);
    padlocks.sort(randPartition);
  }
  end = clock();
  double t = (end - start)/(double)CLOCKS_PER_SEC;
  std::cout << t << '\n';
  return 0;
}
