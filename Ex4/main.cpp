#include <iostream>
#include <string>
#include "hash_table.hpp"


int main(int argc, char const *argv[]) {
  cpd::HashTable<int> ht;

  for(int i = 0; i < 17; i++){
    ht.insert(i);
    for(auto& i : ht){
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
