#include <iostream>
#include <vector>

#include "radixSort.h"

using namespace std;

int getMax(vector<int> vetor){
    int mx = vetor.at(0);
    for(unsigned int i=1; i<vetor.size(); i++)
        if(vetor.at(i) > mx)
            mx = vetor.at(i);
    return mx;
}

vector<int> radixSort(vector<int> vetor){
    int maior = getMax(vetor);
    int exp = 1;
    vector<int> aux = vetor;

    while (maior/exp > 0) {
        int bucket[10] = { 0 };

    	for (unsigned int i = 0; i < vetor.size(); i++)
    	    bucket[(vetor.at(i) / exp) % 10]++;

    	for (int i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

    	for (int i = vetor.size() - 1; i >= 0; i--)
    	    aux[--bucket[(vetor.at(i) / exp) % 10]] = vetor.at(i);

    	for (unsigned int i = 0; i < vetor.size(); i++)
    	    vetor[i] = aux[i];

    	exp *= 10;
    }

    return vetor;
}

