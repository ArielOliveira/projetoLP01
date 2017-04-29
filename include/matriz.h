#ifndef MATRIZ_H
#define MATRIZ_H

int **AlocMatriz(int n);

void deleteMatrix(int **v, int n);

int **MultMatrizesI(int **M1, int **M2, int m);

int **MultMatrizesR(int **M1, int **M2, int **M3, int n);

#endif