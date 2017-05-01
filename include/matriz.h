#ifndef MATRIZ_H
#define MATRIZ_H

#include "memManager.h"

template<typename T>
T **MultMatrizesI(T **M1, T **M2, int m);

template<typename T>
T **MultMatrizesR(T **M1, T **M2, T **M3, int n);

#endif