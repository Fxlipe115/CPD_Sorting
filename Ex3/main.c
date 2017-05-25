#include "merge_sort.hpp"
#include <cstdlib>
#include <iostream>

int main(){
    std::vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(rand()%100);
    }

    std::vector<int> v0(v);
    std::vector<int> v1(v);
    std::vector<int> v2(v);

    mergeSort(v0);
    mergeSort(v1,100);
    mergeSort(v2,10);

    for(int& i : v0){
        std::cout << " " << i;
    }
    std::cout << std::endl;

    for(int& i : v1){
        std::cout << " " << i;
    }
    std::cout << std::endl;

    for(int& i : v2){
        std::cout << " " << i;
    }
    std::cout << std::endl;

    return 0;
}
