#ifndef MATRIZ_H
#define MATRIZ_H

int **AlocMatriz(int n);

int **MultMatrizesI(int **M1, int **M2, int m);

int **SomaM(int **M1, int **M2, int n);

int **UnirMatriz(int **M, int **M1, int **M2, int **M3, int **M4, int n);

void AtribuirSubM(int **M, int **M1, int **M2, int **M3, int **M4, int n);

int **MultMatrizesR(int **M1, int **M2, int **M3, int n);

#endif