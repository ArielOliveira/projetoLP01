#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <iostream>
using std::cerr;
using std::endl;

/** @brief Aloca os espaços da matriz dinamicamente 
* @param n Tamanho da Matriz Quadrada
* @return Matriz Alocada
*/
int **AlocMatriz(int n);

void deleteMatriz(int **v, int n);

#endif