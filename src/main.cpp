#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

void errorArgOverflow() {
	cerr << "Erro: Mais de 10 argumentos" << endl;
	exit(1);
}

void erroNoArg() {
	cerr << "Erro: O programa necessita de pelo menos um argumento para execução" << endl;
	cerr << "Exemplo: ./multimat 2" << endl;
	cerr << "	 ./multimat 2 4 8 16" << endl;
	exit(1);
}

int main(int argc, char* argv[]) {
	if (argc < 2) erroNoArg();
	if (argc > 11) errorArgOverflow();

	return 0;
}
