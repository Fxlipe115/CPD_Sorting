#include <fstream>
#include "shell_sort.hpp"

ShellSort::ShellSort(std::vector<int>& list) : SortingAlg(list) {}

void ShellSort::sort(std::vector<int> (*f)(int)){
	//recebe função de atualização do h como parâmetro
	if(f != nullptr){
		int i, j, chave;
		int h=1;
		int iterSwap = 0;

		while (h < (int)list.size()){
			h = (*f)(h)[0];
		}

		while (h > 1) { // reduz tamanho h
			iterations++;
			iterSwap = 0;
			
			h /= (*f)(h)[1];
			for (i = h; i < (int)list.size(); i++) { // ordena segmentos
				chave = list[i];
				j = i-h;
				while ((j>=0) && list[j]>chave) {
					list[j+h] = list[j];
					j-= h;
					iterSwap++;
				}
				list[j+h]=chave;
			}
			swaps.push_back(iterSwap);
			segments.push_back(h);
		}
	}
}

void ShellSort::generateStats(std::string file){
	
}

std::vector<int> seq1(int h){
	std::vector<int> vector = {3*h + 1, 3};
	return vector;
}

std::vector<int> seq2(int h){
	std::vector<int> vector = {h * 2, 2};
	return vector;
}