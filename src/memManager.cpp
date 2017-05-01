/** @file memManager.cpp
* @brief Funções que alocam e desalocam espaços da memória utilizados pelas matrizes
* @autor Rodrigo Rocha Moriyama <rodrigo.oi@hotmail.com> && Ariel de Oliveira Corrêa <ariel.oliveira01@gmail.com>
* @since 28/04/2017
* @last 01/05/2017
*/

#include "memManager.h"

/** @brief Aloca os espaços da matriz dinamicamente 
* @param n Tamanho da Matriz Quadrada
* @return Matriz Alocada
*/
template<typename T>
T **AlocMatriz(int n) {
	T **matrix = new T*[n];
	if (!matrix) {
		cerr << "Memória insuficiente" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		matrix[i] = new T[n];
		if (matrix[i] == NULL) {
				cerr << "Memória insuficiente" << endl;
				exit(1);
			}			
	} 
	return matrix;
}

template int** AlocMatriz<int>(int n);

/** @brief Desaloca os espaços da matriz
* @param v Matriz de entrada
* @param n Tamanho da matriz
*/
template<typename T>
void deleteMatriz(T **v, int n) {
	for (int i = 0; i < n; i++) {
		delete[] v[i];
	}
	delete[] v;
}

template void deleteMatriz<int>(int **v, int n);