#include "fileHandler.h"

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

int headerCheck(ifstream &file, int n) {
	int x = 0;
	for (int i = 0; i < 2; i++) {
		file >> x;
		file.ignore();
		if (x != n) exit(1);
	}
	cout << "Arquivo carregado com sucesso!" << endl;
	file.close();
	return x;
}

int **malloc(int n) {
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

void deleteMatrix(int **v, int n) {
	for (int i = 0; i < n; i++) {
		delete[] v[i];
	}
	delete[] v;
}

void makeMatrix(ifstream &file, int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file >> v[i][j];
			file.ignore();
		}
	}
}

void writeFile(ofstream &output, int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			output << v[i][j] << " ";
		}
		output << endl;
	}
	cout << "Arquivo de saída salvo com sucesso!" << endl;
	output.close();
}