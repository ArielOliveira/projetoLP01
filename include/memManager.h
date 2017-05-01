#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <iostream>
using std::cerr;
using std::endl;

/** @brief Aloca os espaços da matriz dinamicamente 
* @param n Tamanho da Matriz Quadrada
* @return Matriz Alocada
*/
template<typename T>
T **AlocMatriz(int n);

template<typename T>
void deleteMatriz(T **v, int n);

#endif