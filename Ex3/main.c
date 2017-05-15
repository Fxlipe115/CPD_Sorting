#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Insertion Sort
void insertion_sort(int C[], int tam);

// Merge Sort
void merge_sort(int C[], int tam);

// Hybrid Sort
int HYBRID_LEAF;
void hybrid_sort(int C[], int tam);


void print_array(int C[], int tam) {
    printf("[");
    for (int i=0; i<tam-1; i++) {
        printf("%d, ", C[i]);
    }
    printf("%d]\n", C[tam-1]);
}

int is_sorted(int C[], int tam) {
  for (int i=1; i<tam; i++) {
    if ( C[i-1] > C[i])
      return 0;
  }
  return 1;
}

// Measures time of of function f_sort
int benchmark(void(*f_sort)(int[] , int ), int input[], int N , char* name){
    clock_t start, end;
    double time = 0;

    int* output = (int*) malloc(sizeof(int) * N) ;
    memcpy(output,input, sizeof(int) * N);

    start = clock();
    f_sort(output,N) ;
    end = clock();

    time = (end - start)/(double)CLOCKS_PER_SEC;

    if (!is_sorted(output,N)){
       fprintf(stderr,"ERROR in %s\n",name);
    }
    else{
       printf("%s,%d,%f\n", name, N , time);
    }

    if ( N < 100){
       printf("output : ");
       print_array(output,N);
    }

    free(output);

    return 0;
}


int main(int argc, char* argv[])
{
    if (argc < 3){
       printf("Usage %s N K\n",argv[0]);
       return 0;
    }

    int *input;
    int N = atoi(argv[1]);
    HYBRID_LEAF = atoi(argv[2]); //leaf size of mergeSort


    input = (int*) malloc(sizeof(int) * N) ;

    for (int i=0; i<N; i++){
       input[i]=rand() % N+1;
    }

    if ( N < 100){
       printf("Input : ");
       print_array(input,N);
    }


    // Mede tempo do insertion sort
    benchmark(insertion_sort,input,N,"InsertionSort");

    // TODO : Mede tempo do merge sort
   // benchmark(merge_sort,input,N,"MergeSort");

    // TODO: Mede tempo do merge sort hibrido
   // benchmark(hybrid_sort,input,N,"HybridSort");

    free(input);

    return 0;
}

