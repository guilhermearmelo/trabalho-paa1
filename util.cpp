#include <vector>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "util.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "radixSort.h"

using namespace std;

void ordenar(vector<int> vetor, string entrada){
	clock_t startTimeInsertion = clock();
	vector<int> ordenadoInsertion = insertionSort(vetor);
	double insertionTime = double( clock() - startTimeInsertion ) / (double)CLOCKS_PER_SEC;

	clock_t startTimeRadix = clock();
	vector<int> ordenadoRadix = radixSort(vetor);
	double radixTime = double( clock() - startTimeRadix ) / (double)CLOCKS_PER_SEC;

	clock_t startTimeMerge = clock();
	vector<int> ordenadoMerge = mergeSort(vetor);
	double mergeTime = double( clock() - startTimeMerge ) / (double)CLOCKS_PER_SEC;

	gravarSaidas(ordenadoInsertion,ordenadoRadix,ordenadoMerge,entrada);
	gravarResultados(insertionTime,radixTime,mergeTime,entrada);
}

void ordenar(vector<int> vetor, string entrada, string alg){
	if(alg == "insertion"){
		clock_t startTimeInsertion = clock();
		vector<int> ordenadoInsertion = insertionSort(vetor);
		double insertionTime = double( clock() - startTimeInsertion ) / (double)CLOCKS_PER_SEC;
		gravarSaidas(ordenadoInsertion,entrada,alg);
		gravarResultados(insertionTime, entrada, alg);
	} else if(alg == "merge"){
		clock_t startTimeMerge = clock();
		vector<int> ordenadoMerge = mergeSort(vetor);
		double mergeTime = double( clock() - startTimeMerge ) / (double)CLOCKS_PER_SEC;
		gravarSaidas(ordenadoMerge,entrada,alg);
		gravarResultados(mergeTime, entrada, alg);
	} else if(alg == "radix"){
		clock_t startTimeRadix = clock();
		vector<int> ordenadoRadix = radixSort(vetor);
		double radixTime = double( clock() - startTimeRadix ) / (double)CLOCKS_PER_SEC;
		gravarSaidas(ordenadoRadix,entrada,alg);
		gravarResultados(radixTime, entrada, alg);
	} else{
		cout << "Erro nos parâmetros de entrada!" << endl;
	}
}

void gravarResultados(double sortTime, string entrada, string alg){
	ofstream myfile;

	myfile.open("./saidas/resultados_"+alg+"_"+entrada);
	if(alg == "insertion") myfile << "Insertionsort:" << sortTime << " segundos" << "\n";
	if(alg == "merge")     myfile << "Mergesort:    " << sortTime << " segundos" << "\n";
	if(alg == "radix")     myfile << "Radixsort:    " << sortTime << " segundos" << "\n";
	myfile.close();
}

void gravarResultados(double insertionTime, double radixTime, double mergeTime, string entrada){
	ofstream myfile;

	myfile.open("./saidas/resultados_"+entrada);
	myfile << "Insertionsort:" << insertionTime << " segundos" << "\n";
	myfile << "Mergesort:    " << mergeTime     << " segundos" << "\n";
	myfile << "Radixsort:    " << radixTime     << " segundos" << "\n";
	myfile.close();
}

void gravarSaidas(vector<int> vetor, string entrada, string alg){
	ofstream myfile;

	if(alg == "insertion"){
		myfile.open("./saidas/insertion_"+entrada);
		for(unsigned int k=0; k<vetor.size(); k++){
			myfile << vetor[k];
			if(k+1<vetor.size()) myfile << "\n";
		}
		myfile.close();
	} else if(alg == "merge"){
		myfile.open("./saidas/merge_"+entrada);
		for(unsigned int k=0; k<vetor.size(); k++){
			myfile << vetor[k];
			if(k+1<vetor.size()) myfile << "\n";
		}
		myfile.close();
	} else if(alg == "radix"){
		myfile.open("./saidas/radix_"+entrada);
		for(unsigned int k=0; k<vetor.size(); k++){
			myfile << vetor[k];
			if(k+1<vetor.size()) myfile << "\n";
		}
		myfile.close();
	}
}

void gravarSaidas(vector<int> i, vector<int> r, vector<int> m, string entrada){
	ofstream myfile_i;
	ofstream myfile_r;
	ofstream myfile_m;

	myfile_i.open("./saidas/insertion_"+entrada);
	for(unsigned int k=0; k<i.size(); k++){
		myfile_i << i[k];
		if(k+1<i.size()) myfile_i << "\n";
	}
	myfile_i.close();

	myfile_r.open("./saidas/radix_"+entrada);
	for(unsigned int k=0; k<r.size(); k++){
		myfile_r << r[k];
		if(k+1<r.size()) myfile_r << "\n";
	}
	myfile_r.close();

	myfile_m.open("./saidas/merge_"+entrada);
	for(unsigned int k=0; k<m.size(); k++){
		myfile_m << m[k];
		if(k+1<m.size()) myfile_m << "\n";
	}
	myfile_m.close();
}

vector<int> atribuirEntrada(string arquivo){
	ifstream file;
	file.open(arquivo);

	vector<int> vector;
	string numString;

	while (getline(file, numString)){
        vector.push_back(stoi(numString));
    }

    file.close();
    return vector;
}

void gerarEntradas(){
	ofstream myfile;
	clock_t startTime = clock();

	int tam[] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

	srand (time(NULL));
	
	for(unsigned int a=0; a<sizeof(tam)/sizeof(int); a++){
		cout << "Gerando instancias de tamanho " << setw(10) << left << tam[a] << "[";	
		for(int instancia=1; instancia<=20; instancia++){
			if(instancia<10)
				myfile.open("tam"+ to_string(tam[a])+"_instancia0"+to_string(instancia)+".txt");
			else
				myfile.open("tam"+ to_string(tam[a])+"_instancia"+to_string(instancia)+".txt");
			cout << ".";
			for(int i=0;i<tam[a];i++){
				int numeroAleatorio = rand()%30000;
				myfile << numeroAleatorio;
				if(i+1<tam[a]) myfile << "\n";
			}
			myfile.close();
		}
		cout << "]" << endl;
	}
	cout << "Entradas geradas em: ";
	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC << " segundos." << endl;
}

void mostrarVector(vector<int> &vectorDesordenado){
	for (vector<int>::const_iterator i = vectorDesordenado.begin(); i != vectorDesordenado.end(); ++i)
    	cout << *i << ' ';
    cout << endl;
}

void inserirEntrada(vector<int> &vectorDesordenado, int TAMANHO_ENTRADA){
	srand (time(NULL));
	for(int i=0;i<TAMANHO_ENTRADA;i++){
		int numeroAleatorio = rand()%100000;
		vectorDesordenado.push_back(numeroAleatorio);
	}
}