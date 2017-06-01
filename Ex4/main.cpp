#include <iostream>
#include <string>
#include "hash_table.hpp"


int main(int argc, char const *argv[]) {
  cpd::HashTable<int> ht;

  ht.insert(1);
  ht.insert(2);

  ht.begin();

  // ht.search("abc");
  // ht.search("a");

  // for(cpd::HashTable<std::string>::iterator it = ht.begin();it != ht.end();it++){
  //   std::cout << s << std::endl;
  // }
  return 0;
}
