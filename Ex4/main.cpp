#include <iostream>
#include <fstream>
#include <string>
#include "hash_table.hpp"


int main(int argc, char const *argv[]) {
  cpd::HashTable<std::string> ht;

  std::ifstream names("nomes.txt");
  std::string input;

  while(names){
    std::getline(names,input);
    if(names){
      ht.insert(input);
    }
  }

  std::cout << "Collisions: " << ht.getCollisions() << "\n";
  std::cout << "Occupancy: " << ht.getOccupancy() << "\n";
  for(auto& x : ht){
    std::cout << x << "\n";
  }

  return 0;
}
