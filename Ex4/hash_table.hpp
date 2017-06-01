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

      HashTable();
      int getSize();
      int getOccupancy();
      void insert(T item);
      void remove(iterator item); //TODO change argument to iterator
      iterator search(T item); //TODO change return to iterator
  };

    //===============Iterator===============
  template <typename T>
  class HashIter{
    private:
      HashTable<T>& hashTable;
      typename HashTable<T>::Table::iterator curBucket;
      typename HashTable<T>::Bucket::iterator curItem;
    public:
      HashIter(HashTable<T>& ht, int offset);
      HashIter(HashTable<T>& ht,
        typename HashTable<T>::Table::iterator bucket,
        typename HashTable<T>::Bucket::iterator item);
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
