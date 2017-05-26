#include "merge_sort.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

int binary_search (std::vector<int>& a,int key,int low,int high){
    if(high == -1)
        high = a.size() - 1;
    int mid;
    if (low == high)
            return low;
    mid = low + ((high-low)/2);
    if (key > a[mid])
            return binary_search(a,key,mid+1,high);
    else if (key < a [mid])
            return binary_search(a,key,low, mid);
    return mid;
}

void binary_insertion_sort(std::vector<int>& C,int low,int high){
    int tam = high - low + 1;
    int i, j, chave;
    int ins;
    for (j=low+1; j<low+tam; j++) {
            ins = binary_search(C,C[j],low,j);
            chave = C[j];
            for (int k=j-1; k>=ins; k--) {
                    C[k+1] = C[k];
            }
            C[ins]=chave;
    }
}

void insertion_sort(std::vector<int> C) {
    int tam = C.size();
    int i, j, chave;
    for (j=1; j<tam; j++) {
            chave = C[j];
            i = j-1;
            while ((i>=0) && C[i]>chave) {
                    C[i+1] = C[i];
                    i--;
            }
            C[i+1]=chave;
    }
}

void mergeSort(std::vector<int>& l,int k){
    mergeSort(l,k,0,l.size()-1);
}

void mergeSort(std::vector<int>& l,int k,int low,int high){
    int size = high - low + 1;
    if(size <= k){
        binary_insertion_sort(l,low,high);
    }else if(size > 1){
        int middle = size / 2;
        mergeSort(l,k,low,middle+low-1);
        mergeSort(l,k,low+middle,high);

        std::vector<int> aux(size,0);

        std::merge(l.begin()+low,l.begin()+low+middle,l.begin()+low+middle,l.begin()+high+1,aux.begin());
        
        for(int i = 0, j = low; i < size; i++, j++){
            l[j] = aux[i];
        }
    }
}
