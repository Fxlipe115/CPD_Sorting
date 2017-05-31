#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <vector>
#include <list>

namespace cpd{

  template <typename T> class HashIter;

  //===============HashTable===============
  template <typename T>
  class HashTable{
    private:
      typedef std::vector<std::list<T>> Table;
      typedef std::list<T> Bucket;
      const int initialSize = 17;
      Table table;
      int tableSize;
      int occupancy;

      void resize();
      void shrinkToFit();
      // hash functions for supported types
      unsigned long hash(std::string value);
      unsigned long hash(int value);
    public:
      HashTable();
      int getSize();
      int getOccupancy();
      void insert(T item);
      void remove(T item); //TODO change argument to iterator
      bool search(T item); //TODO change return to iterator

      // for use of iterator
      friend class HashIter<T>;
      typedef HashIter<T> iterator;
      typedef ptrdiff_t difference_type;
      typedef size_t size_type;
      typedef T value_type;
      typedef T* pointer;
      typedef T& reference;
      iterator begin(){return iterator(*this, 0);};
      iterator end(){return iterator(*this, occupancy);};
  };

    //===============Iterator===============
  template <typename T>
  class HashIter{
    private:
      HashTable<T>& hashTable;
      int offset;
    public:
      HashIter(HashTable<T>& ht, int offset);
      HashIter(HashIter<T>& hi); // copy constructor
      bool operator==(const HashIter<T>& other);
      bool operator!=(const HashIter<T>& other);
      T& operator*();
      HashIter<T>& operator++(); // prefix: ++iter
      HashIter<T> operator++ (int); //postfix: iter++
  };
}

#include "hash_table.inl"

#endif
