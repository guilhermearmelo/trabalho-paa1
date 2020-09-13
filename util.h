#include <vector>

using namespace std;

void ordenar(vector<int> vetor, string entrada);
void ordenar(vector<int> vetor, string entrada, string alg);
void gravarResultados(double sortTime, string entrada, string alg);
void gravarResultados(double insertionTime, double radixTime, double mergeTime, string entrada);
void gravarSaidas(vector<int> vetor, string entrada, string alg);
void gravarSaidas(vector<int> i, vector<int> r, vector<int> m, string entrada);
vector<int> atribuirEntrada(string arquivo);
void gerarEntradas();
void mostrarVector(vector<int> &vectorDesordenado);
void inserirEntrada(vector<int> &vectorDesordenado, int TAMANHO_ENTRADA);