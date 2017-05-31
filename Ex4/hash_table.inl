#include <cmath>
#include <algorithm>

//===============HashTable===============
template <typename T>
cpd::HashTable<T>::HashTable()
   : table(initialSize,Bucket()), tableSize(initialSize), occupancy(0)
{}

template <typename T>
void cpd::HashTable<T>::resize(){
  int newSize = tableSize * 2 + 1;
  Table aux(table); // copy of current table

  table.clear();
  table.resize(newSize,Bucket());

  for(auto& bucket : aux){
    for(auto& i : bucket){
      insert(i);
    }
  }
}

template <typename T>
void cpd::HashTable<T>::shrinkToFit(){
  //TODO
}

template <typename T>
unsigned long cpd::HashTable<T>::hash(std::string value){
  unsigned long hashValue = (int)(value[0]);
  int len = value.size();
  int i = 0;

  for(auto& c : value){
    hashValue += (int)pow((int)c,i) % (int)(pow(2,len)+1);
    i++;
  }

  return hashValue;
}

template <typename T>
unsigned long cpd::HashTable<T>::hash(int value){
  return hash(std::to_string(value));
}

template <typename T>
int cpd::HashTable<T>::getSize(){
  return tableSize;
}

template <typename T>
int cpd::HashTable<T>::getOccupancy(){
  return occupancy;
}

template <typename T>
void cpd::HashTable<T>::insert(T item){
  table[hash(item)].push_back(item);
  occupancy++;
  if(occupancy > 3 * (int)(tableSize / 4)){
    resize();
  }
}

template <typename T>
void cpd::HashTable<T>::remove(T item){ //TODO change argument to iterator
  Bucket& bucket = table[hash(item)];

  typename Bucket::iterator it = std::find(bucket.begin(),bucket.end(),item);

  if(it != bucket.end()){
    bucket.erase(it);

    occupancy--;
  }
}

template <typename T>
bool cpd::HashTable<T>::search(T item){ //TODO change return to iterator
  Bucket& bucket = table[hash(item)];

  typename Bucket::iterator it = std::find(bucket.begin(),bucket.end(),item);

  return (it != bucket.end());
}


//===============Iterator===============
template <typename T>
cpd::HashIter<T>::HashIter(HashTable<T>& ht, int offset)
 : hashTable(ht), offset(offset)
{}

template <typename T>
cpd::HashIter<T>::HashIter(HashIter<T>& hi) // copy constructor
 : hashTable(hi.hashTable), offset(hi.offset)
{}

template <typename T>
bool cpd::HashIter<T>::operator==(const HashIter<T> &other){
  bool sameHashTable = this->hashTable == other.hashTable;
  bool sameOffset = this->offset == other.offset;
  return sameHashTable && sameOffset;
}

template <typename T>
bool cpd::HashIter<T>::operator!=(const HashIter<T> &other){
  return !(*this == other);
}

template <typename T>
T& cpd::HashIter<T>::operator*(){
  //========================
  //TODO
  //========================
  return hashTable[offset];
}

template <typename T>
cpd::HashIter<T>& cpd::HashIter<T>::operator++(){ // prefix: ++iter
  ++offset;
  return *this;
}

template <typename T>
cpd::HashIter<T> cpd::HashIter<T>::operator++(int){ //postfix: iter++
  HashIter<T> clone(*this);
  ++offset;
  return clone;
}
