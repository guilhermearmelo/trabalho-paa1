#include <vector>

#include "insertionSort.h"

using namespace std;

vector<int> insertionSort(vector<int> vector){

	int key, j;
    
    for (unsigned int i = 1; i < vector.size(); i++){
        key = vector.at(i);
        j = i - 1;
        
        while (j>=0 && vector.at(j)>key){
        	vector[j+1] = vector.at(j);
            j = j - 1;
        }
        vector[j+1] = key;
    }
    return vector;
}