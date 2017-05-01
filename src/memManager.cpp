#include "memManager.h"

/** @brief Aloca os espaços da matriz dinamicamente 
* @param n Tamanho da Matriz Quadrada
* @return Matriz Alocada
*/
int **AlocMatriz(int n) {
	int **matrix = new int*[n];
	if (!matrix) {
		cerr << "Memória insuficiente" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		if (matrix[i] == NULL) {
				cerr << "Memória insuficiente" << endl;
				exit(1);
			}			
	} 
	return matrix;
}

void deleteMatriz(int **v, int n) {
	for (int i = 0; i < n; i++) {
		delete[] v[i];
	}
	delete[] v;
}