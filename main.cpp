#include <iostream>
#include <vector>
#include <time.h>
#include <string>

#include "insertionSort.h"
#include "radixSort.h"
#include "mergeSort.h"
#include "util.h"

using namespace std;

int main (int argc, char **argv){

	// Formas de execuçao
	// $ executavel gerar
	// $ executavel tam100_instancia01.txt
	// $ executavel tam100_instancia01.txt merge

	vector<int> vectorDesordenado;

	string s = argv[1];

	switch(argc){
		case 2:
			if(s == "gerar"){
				gerarEntradas();
			} else{
				vectorDesordenado = atribuirEntrada(s);
				if(vectorDesordenado.size() == 0){
					cout << "Erro ao ler entrada!" << endl;
				} else{
					ordenar(vectorDesordenado, s);
				}
			}
			break;
		case 3:
			vectorDesordenado = atribuirEntrada(s);
			if(vectorDesordenado.size() == 0){
				cout << "Erro ao ler entrada!" << endl;
			} else{
				string alg = argv[2]; // {insertion, merge, radix}
				ordenar(vectorDesordenado, s, alg);
			}

			break;
		default:
			break;
	}

	return 0;
}