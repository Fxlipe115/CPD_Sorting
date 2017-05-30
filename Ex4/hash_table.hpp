#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <vector>
#include <list>

namespace cpd{

    class HashTable{
        private:
            std::vector<std::list<std::string>>;

            int hash(std::string);
        public:
            HashTable();
            HashTable(int size);
            void insert(std::string);
            void remove(std::string);
            void search(std::string);
    };

}

#endif
