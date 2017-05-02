/**
* @file matriz.cpp
* @brief Programa que faz multiplicações de matrizes e gera estatísticas sobre o tempo de execução
* @autor Rodrigo Rocha Moriyama <rodrigo.oi@hotmail.com> && Ariel de Oliveira Corrêa <ariel.oliveira01@gmail.com>
* @since 28/04/2017
* @last 01/05/2017
*/

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

#include <cstdio>
using std::remove;


#include <limits>
using std::streamsize;
using std::numeric_limits;

#include <chrono>
using namespace std::chrono;

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

	file.close();

	return v;
}

template<typename T>
void performTest(string& arqDirTime, T **A, T **B, T **C, int n) {

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	C = MultMatrizesR(A, B, C, n);

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();

	ofstream arqTime(arqDirTime, std::ofstream::out | std::ofstream::app);
	if (!arqTime) {
		cerr << "Erro ao criar arquivo de saída" << endl;
		exit(1);
	}

	arqTime << duration;
	arqTime << endl;

	arqTime.close();
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

/**
* @brief Função que checa se um arquivo existe 
* @brief Retirado do stackoverflow
* @brief http://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
*/
inline bool fileExists(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

/**
* @brief Função que checa se um número x é potência de 2
* @brief Retirado do stackoverflow
* @brief http://stackoverflow.com/questions/600293/how-to-check-if-a-number-is-a-power-of-2
*/
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

	string arqDir;
	string arqDirTime;

	for (int count = 1; count < argc; count++) {
		
		int n = atoi(argv[count]);
		string arg = argv[count];		
		

		arqDir = "data/input/A" + arg + "x" + arg + ".txt"; // Linha contribuição do aluno Carlos Frederico Carvalheira
		int **A = performCreation<int>(arqDir, n);

		arqDir = "data/input/B" + arg + "x" + arg + ".txt"; // Linha contribuição do aluno Carlos Frederico Carvalheira
		int **B = performCreation<int>(arqDir, n);
	
		int **C = AlocMatriz<int>(n);
		arqDirTime = "data/output/CTempoRecursivo" + arg + "x" + arg + ".dat"; // Linha contribuição do aluno Carlos Frederico Carvalheira

		char *dir = new char[arqDirTime.size()];
		for (unsigned int count = 0; count < arqDirTime.size(); count++) {
			dir[count] = arqDirTime.at(count);
		}

		if (fileExists(arqDirTime)) {
			remove(dir);
		}
			
		for (int test = 0; test < 20; test++) {
			performTest<int>(arqDirTime, A, B, C, n);	
		}	

		delete[] dir;

		
		arqDir = "data/output/C" + arg + "x" + arg + ".txt"; // Linha contribuição do aluno Carlos Frederico Carvalheira
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
