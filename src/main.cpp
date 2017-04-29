#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

#include <string>

#include <cstdlib>
using std::exit;


#include "fileHandler.h"

void errorArgOverflow() {
	cerr << "Erro: Mais de 10 argumentos" << endl;
	exit(1);
}

void errorNoArg() {
	cerr << "Erro: O programa necessita de pelo menos um argumento para execução" << endl;
	cerr << "Exemplo: ./multimat 2" << endl;
	cerr << "	 ./multimat 2 4 8 16" << endl;
	exit(1);
}

void errorInvalidArg() {
	cerr << "Erro: Argumento Inválido" << endl;
	exit(1);
}

bool isPowerOfTwo(int x) {
    return (x > 1) && (x <= 1024) && ((x & (x - 1)) == 0);
}

int getSize(char* v) {
	int i;
	for (i = 0; v[i] != '\0'; i++) {}
	return i;
}

int main(int argc, char* argv[]) {
	if (argc < 2) errorNoArg();
	if (argc > 11) errorArgOverflow();
	for (int i = 1; i < argc; i++) {
		if (!isPowerOfTwo(atoi(argv[i]))) errorInvalidArg();
	}
	string arg = argv[1];
	string arqDir = "data/input/A" + arg + "x" + arg + ".txt";

	ifstream file(arqDir);
	if (!file) {
		cerr << "Erro ao abrir arquivo" << endl;
		return 1;
	}

	int n = headerCheck(file, atoi(argv[1]));
	int **A = malloc(n);
	makeMatrix(file, A, n);
	//char *arqDir = new char[18+(getSize(argv[2])*2)];

	return 0;
}
