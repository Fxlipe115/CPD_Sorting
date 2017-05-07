#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>    // std::swap

clock_t start_clock, end_clock;

void print_array(int C[], int tam) {
	printf("[");
	for (int i=0; i<tam-1; i++) {
		printf("%d, ", C[i]);
	}
	printf("%d]", C[tam-1]);
}


int partition(int C[], int left, int right) {
	int chave, i, j;
	chave = C[right]; i = left; j = right;
	for (;;) {
		while(C[i] < chave) i++ ;
		while(C[--j] > chave) j--;
		if (i >= j) break;
		std::swap (C[i], C[j]);
	}
	std::swap (C[i], C[right]);
	return i;
}

void quick_sort_rec (int C[], int left, int right) { 
	int pivot; // índice do pivô
	if (right > left) {
		pivot = partition (C, left, right);
		quick_sort_rec (C, left, pivot-1); 
		quick_sort_rec (C, pivot+1, right);
	} 
}

void quick_sort (int C[], int tam, int print_ok) {
	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}
	start_clock = clock ();
	quick_sort_rec(C, 0, tam-1);
	end_clock = clock();
	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nQuick Sort time = %f seconds", 
		(end_clock - start_clock)/(double)CLOCKS_PER_SEC );	
}

#define SIZE 100000

int main(int argc, const char * argv[]){
	int arr1[10]={12,2,5,4,8,7,6,9,1,15};
	int arr2[10]={1,2,3,4,5,6,7,8,9,10};
	int arr3[10]={10,9,8,7,6,5,4,3,2,1};
	int arr4[SIZE];
	int arr5[SIZE];
	int arr6[SIZE];

	quick_sort(arr1, 10, 1);
	quick_sort(arr2, 10, 1);
	quick_sort(arr3, 10, 1);

	printf("\nWorst case");
	for (int i=0; i<SIZE; i++) arr4[i]=SIZE-i;
	quick_sort(arr4, SIZE, 0);

	for (int j=0; j<10; j++) {
		for (int i=0; i<SIZE; i++) arr4[i]=rand()%SIZE+1;	
		quick_sort(arr4, SIZE, 0);
	}
    return 0;
}
