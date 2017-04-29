#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

#include <limits>
using std::streamsize;
using std::numeric_limits;

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

	for (int count = 1; count < argc; count++) {
		string arg = argv[count];
		string arqDir = "data/input/A" + arg + "x" + arg + ".txt";
		ifstream file(arqDir);
		if (!file) {
			cerr << "Erro ao abrir arquivo" << endl;
			return 1;
		}
		string arquivo;
		int n = headerCheck(file, atoi(argv[count]));
		int **A = malloc(n);
		
		file.clear();
		file.seekg(0, file.beg);
		file.ignore(numeric_limits<streamsize>::max(), '\n');

		makeMatrix(file, A, n);
		arqDir = "data/output/A" + arg + "x" + arg + ".txt";
		ofstream output(arqDir);
		if (!output) {
			cerr << "Erro ao criar arquivo de saída" << endl;
			return 1;
		}

		writeFile(output, A, n);
		deleteMatrix(A, n);
		//char *arqDir = new char[18+(getSize(argv[2])*2)];
	}

	return 0;
}
