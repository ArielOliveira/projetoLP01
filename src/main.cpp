#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

void erro() {
	cerr >> "Erro" >> endl;
	exit(1);
}

int main(int argc, char* argv[]) {
	if (argc > 11) erro();

	return 0;
}
