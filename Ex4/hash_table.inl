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
  table[hash(item) % tableSize].push_back(item);
  occupancy++;
  if(occupancy > 3 * (int)(tableSize / 4)){
    resize();
  }
}

template <typename T>
void cpd::HashTable<T>::remove(iterator item){
  (*item).curBucket.erase((*item).curItem);
  occupancy--;
}

template <typename T>
typename cpd::HashTable<T>::iterator cpd::HashTable<T>::search(T item){
  typename Table::iterator bucket = table.begin() + (hash(item) % tableSize);

  typename Bucket::iterator it = std::find((*bucket).begin(),(*bucket).end(),item);

  if(it != (*bucket).end()){
    return iterator(*this, bucket, it);
  }else{
    return end();
  }
}

template <typename T>
typename cpd::HashTable<T>::iterator cpd::HashTable<T>::begin(){
  return iterator(*this, true);
}

template <typename T>
typename cpd::HashTable<T>::iterator cpd::HashTable<T>::end(){
  return iterator(*this, false);
}

//===============Iterator===============
template <typename T>
cpd::HashIter<T>::HashIter(HashTable<T>& ht, bool isBegin)
 : hashTable(ht){
  if(isBegin){ // begin iterator
    curBucket = hashTable.table.begin();
    bool flag = true;
    while(flag){
      if(curBucket != hashTable.table.end()){
        if((*curBucket).empty()){
          curBucket++;
        }else{ // found first non-empty bucket
          flag = false;
        }
      }else{ // empty table
        flag = false;
        curBucket--;
      }
      curItem = (*curBucket).begin();
    }
  }else{ // end iterator
    curBucket = --hashTable.table.end();
    curItem = (*curBucket).end();
  }
}

template <typename T>
cpd::HashIter<T>::HashIter(HashTable<T>& ht,
  typename HashTable<T>::Table::iterator bucket,
  typename HashTable<T>::Bucket::iterator item)
 : hashTable(ht), curBucket(bucket), curItem(item)
{}

template <typename T>
cpd::HashIter<T>::HashIter(HashIter<T>& hi) // copy constructor
 : hashTable(hi.hashTable),
   curBucket(hi.curBucket), curItem(hi,curItem)
{}

template <typename T>
bool cpd::HashIter<T>::operator==(const HashIter<T>& other){
  bool sameHashTable = this->hashTable == other.hashTable;
  bool sameItem = this->curItem == other.curItem;
  return sameHashTable && sameItem;
}

template <typename T>
bool cpd::HashIter<T>::operator!=(const HashIter<T>& other){
  return !(*this == other);
}

template <typename T>
T& cpd::HashIter<T>::operator*(){
  return *curItem;
}

template <typename T>
cpd::HashIter<T>& cpd::HashIter<T>::operator++(){ // prefix: ++iter
  ++curItem;
  if(curItem == curBucket.end()){
    ++curBucket;
    bool flag = true;
    while(flag){
      if(curBucket != hashTable.table.end()){
        if((*curBucket).empty()){
          curBucket++;
        }else{ // found non-empty bucket
          flag = false;
        }
      }else{ // end of table
        flag = false;
        curBucket--;
      }
      curItem = (*curBucket).begin();
    }
  }
  return *this;
}

template <typename T>
cpd::HashIter<T> cpd::HashIter<T>::operator++(int){ //postfix: iter++
  HashIter<T> clone(*this);
  ++curItem;
  if(curItem == curBucket.end()){
    ++curBucket;
    bool flag = true;
    while(flag){
      if(curBucket != hashTable.table.end()){
        if((*curBucket).empty()){
          curBucket++;
        }else{ // found non-empty bucket
          flag = false;
        }
      }else{ // end of table
        flag = false;
        curBucket--;
      }
      curItem = (*curBucket).begin();
    }
  }
  return clone;
}
