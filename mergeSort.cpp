#include <vector>

#include "mergeSort.h"

using namespace std;

vector<int> mergeSort(vector<int> vector2){
	vector<int> saida = vector2;

	mergeSorting(saida,0,saida.size()-1);
	return saida;
}

void merge(vector<int> &vector, int l, int m, int r){ 
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1], R[n2]; 

	for (i=0; i<n1; i++)
		L[i] = vector.at(l+i);

	for (j=0; j<n2; j++)
		R[j] = vector.at(m+1+j);

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]){
			vector[k] = L[i];
			i++;
		}
		else{
			vector[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		vector[k] = L[i];
		i++;
		k++;
	}

	while(j < n2){
		vector[k] = R[j];
		j++;
		k++;
	}
}

void mergeSorting(vector<int> &vector, int l, int r){
	if(l < r){
		int m = l+(r-l)/2;

		mergeSorting(vector, l, m);
		mergeSorting(vector, m+1, r);

		merge(vector, l, m, r);
	}
}