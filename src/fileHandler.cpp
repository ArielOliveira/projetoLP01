#include "fileHandler.h"

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

bool headerCheck(ifstream &file, int n) {
	int x = 0;
	for (int i = 0; i < 2; i++) {
		file >> x;
		file.ignore();
		if (x != n) return false;
	}
	return true;
}

void makeMatrix(ifstream &file, int **v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file >> v[i][j];
			file.ignore();
		}
	}
	file.close();
}

void writeFile(ofstream &output, int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			output << v[i][j] << " ";
		}
		output << endl;
	}
	output.close();
}