#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <time.h>
#include "quick_sort.hpp"

int findKeys(SortingAlg& keys, SortingAlg& padlocks, std::string name, bool random);
int mapper(std::string str);
std::string demapper(int val);


int main(int argc, char const *argv[]) {
  if(argc < 3){
    std::cerr << "Usage: " << "./main keysfile padlocksfile" << '\n';
  }else{
    srand(time(NULL));

    std::ifstream keysfile(argv[1]);
    std::ifstream padlocksfile(argv[2]);
    std::vector<int> keys;
    std::vector<int> padlocks;

    std::string aux;
    while(std::getline(keysfile, aux)){
      keys.push_back(mapper(aux));
    }
    keysfile.close();

    while(std::getline(padlocksfile, aux)){
      padlocks.push_back(mapper(aux));
    }
    padlocksfile.close();

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
  double t;

  //----- sort keys -----
	start = clock();
  if(!random){
    keys.sort(partition);
  }else{
    keys.sort(randPartition);
  }
  end = clock();
  t = (end - start)/(double)CLOCKS_PER_SEC;
  std::cout << name << " took " << std::setprecision(10) << t << "s to sort keys.\n";

  //----- sort padlocks -----
  start = clock();
  if(!random){
    padlocks.sort(partition);
  }else{
    padlocks.sort(randPartition);
  }
  end = clock();
  t = (end - start)/(double)CLOCKS_PER_SEC;
  std::cout << name << " took " << std::setprecision(10) << t << "s to sort padlocks.\n";

  //----- check for pairs -----
  int numPair = 0;
  int i = 0, j = 0;
  bool stop = false;
  std::vector<std::string> pairs;

  int aSize = keys.getList().size();
  int bSize = padlocks.getList().size();
  while(!stop){
    if(aSize > i && bSize > j){
      int a = keys.getList()[i];
      int b = padlocks.getList()[j];
      if(a == b){
        numPair++;
        i++;
        j++;
        pairs.push_back(demapper(a));
      }else if(a < b){
        i++;
      }else{//a > b
        j++;
      }
    }else{
      stop = true;
    }
  }

  std::cout << numPair << " key/padlock pairs were found." << '\n';
  for(std::string x : pairs){
    std::cout << x << ", ";
  }
  std::cout << "\b" << '\n';

  return 0;
}

int mapper(std::string str){
  int codif = 0;
  int val = 0;
  for(int i = 0, size = str.length(); i < size; i++){
    if(isalpha(str.at(i))){
      if(isupper(str.at(i))){
        val = str.at(i) - 55;
      }else{//is lower
        val = str.at(i) - 61;
      }
    }else{//is number
      val = str.at(i) - '0';
    }
    codif += val * pow(62, i);
  }
  return codif;
}

std::string demapper(int val){
  std::string decodif;
  for(int i = 0; i < 5; i++){
    int mod = val % 62;

    if(mod < 10){
      decodif.push_back(mod + '0');
    }else if(mod < 36){
      decodif.push_back(mod + 55);
    }else{
      decodif.push_back(mod + 61);
    }
    val /= 62;
  }
  return decodif;
}
