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


#include "memManager.h"
#include "fileHandler.h"
#include "matriz.h"

template<typename T>
T **performCreation(string &arqDir, int n) {
	ifstream file(arqDir);
		if (!file) {
			cerr << "Erro ao abrir arquivo" << endl;
			exit(1);
		}

	if (!headerCheck(file, n)) {
		cerr << "Erro de integridade do arquivo" << endl;
		exit(1);
	}

	file.clear();
	file.seekg(0, file.beg);
	file.ignore(numeric_limits<streamsize>::max(), '\n');

	T **v = AlocMatriz<T>(n);
	makeMatrix(file, v, n);

	return v;
}

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

	cout << "Carregando arquivos...!" << endl;

	for (int count = 1; count < argc; count++) {
		
		int n = atoi(argv[count]);
		string arg = argv[count];
		string arqDir;
		
		arqDir = "data/input/A" + arg + "x" + arg + ".txt";
		int **A = performCreation<int>(arqDir, n);

		arqDir = "data/input/B" + arg + "x" + arg + ".txt";
		int **B = performCreation<int>(arqDir, n);

		int **C = AlocMatriz<int>(n);
		C = MultMatrizesR(A, B, C, n);
		
		arqDir = "data/output/C" + arg + "x" + arg + ".txt";
		ofstream output(arqDir);
		if (!output) {
			cerr << "Erro ao criar arquivo de saída" << endl;
			return 1;
		}
		writeFile(output, C, n);
		
		
		deleteMatriz<int>(A, n);
		deleteMatriz<int>(B, n);

		cout << endl;
	}

	cout << "Arquivos carregados e escritos com sucesso!" << endl;	

	return 0;
}
