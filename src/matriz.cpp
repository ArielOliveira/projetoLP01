/**
* @file matriz.cpp
* @brief Funções interativas e recursivas para a multiplicação das matrizes
* @autor Rodrigo Rocha Moriyama <rodrigo.oi@hotmail.com>
* @since 28/04/2017
*/

#include "matriz.h"
#include <iostream>

/** @brief Aloca os espaços da matriz dinamicamente 
* @param n Tamanho da Matriz Quadrada
* @return Matriz Alocada
*/

int **AlocMatriz(int n)
{
	int **M = new int*[n];
	int i;
	
	for (i = 0; i < n; i++)
	{
		M[i] = new int[n];
	}

	return M;
}

/** @brief Multiplicação interativa das matrizes
* @param M1 Matriz de entrada
* @param M2 Matriz de entrada
* @param m Tamanho das matrizes de entrada
* @param M3 Matriz para resultado
* @return Matriz resultante da multiplicação
*/
int **MultMatrizesI(int **M1, int **M2, int m)
{
	int soma;
	int **M3;
	int i,k,j;

	M3 = AlocMatriz(m);
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
		{
			soma = 0;
			for(k = 0; k < m; k++)
			{
				soma = soma + (M1[i][k] * M2[k][j]);
				M3[i][j] = soma;
			}
		}
	}
	return M3;
}

/** @brief Soma de duas matrizes
* @param M1 Matriz de entrada
* @param M2 Matriz de entrada
* @param n Tamanho das matrizes
* @return Matriz resultante da soma
*/
int **SomaM(int **M1, int **M2, int n)
{
	int i,j;
	int **M3 = AlocMatriz(n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}

	return M3;
}

int **UnirMatriz(int **M, int **M1, int **M2, int **M3, int **M4, int n)
{
	int i, j;
	int b = 0;

	//Função para M1 que representa M3_11
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][j] = M1[i][j];
		}
	}

	//Função para M2 que representa M3_12
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][n + b] = M2[i][j];
			b++;
		}
		b = 0;
	}

	//Função para M3 que representa M3_21
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i + n][j] = M3[i][j];
			b++;
		}
		b = 0;
	}

	//Função para M4 que representa M3_22
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i + n][n + b] = M4[i][j];
			b++;
		}
		b = 0;
	}

	return M;
}


/* @brief Multiplicação recursiva
* @param M1 Matriz de entrada
* @param M2 Matriz de entrada
* @param M3 Matriz de entrada
* @param n Tamanho das matrizes
* @return Matriz resultante da multiplicação
*/
int **MultMatrizesR(int **M1, int **M2, int **M3, int n)
{
	if(n == 1)
	{
		M3[1][1] = M1[1][1] * M2[1][1];
		return M3;
	}
	else
	{
		// Sub matrizes de M1
		int **M1_11 = AlocMatriz(n/2);
		int **M1_12 = AlocMatriz(n/2);
		int **M1_21 = AlocMatriz(n/2);
		int **M1_22 = AlocMatriz(n/2);

		// Sub matrizes de M2
		int **M2_11 = AlocMatriz(n/2);
		int **M2_12 = AlocMatriz(n/2);
		int **M2_21 = AlocMatriz(n/2);
		int **M2_22 = AlocMatriz(n/2);

		// Sub matrizes de M3
		int **M3_11 = AlocMatriz(n/2);
		int **M3_12 = AlocMatriz(n/2);
		int **M3_21 = AlocMatriz(n/2);
		int **M3_22 = AlocMatriz(n/2);

		// Matriz auxiliar para armazenar a multiplicação
		int **P_1 = AlocMatriz(n/2);
		int **P_2 = AlocMatriz(n/2);
		int **P_3 = AlocMatriz(n/2);
		int **P_4 = AlocMatriz(n/2);
		int **P_5 = AlocMatriz(n/2);
		int **P_6 = AlocMatriz(n/2);
		int **P_7 = AlocMatriz(n/2);
		int **P_8 = AlocMatriz(n/2);

		//Multiplicação recursiva
		MultMatrizesR(M1_11, M2_11, P_1, n/2);
		MultMatrizesR(M1_12, M2_21, P_2, n/2);
		MultMatrizesR(M1_11, M2_12, P_3, n/2);
		MultMatrizesR(M1_12, M2_22, P_4, n/2);
		MultMatrizesR(M1_21, M2_11, P_5, n/2);
		MultMatrizesR(M1_22, M2_21, P_6, n/2);
		MultMatrizesR(M1_21, M2_12, P_7, n/2);
		MultMatrizesR(M1_22, M2_22, P_8, n/2);

		//Atribuição dos valores na matriz M3
		M3_11 = SomaM(P_1, P_2, n/2);
		M3_12 = SomaM(P_3, P_4, n/2);
		M3_21 = SomaM(P_5, P_6, n/2);
		M3_22 = SomaM(P_7, P_8, n/2);

		M3 = UnirMatriz(M3_11, M3_12, M3_21, M3_22, M3, n/2);

		return M3;
	}
}



void IniM(int **x, int y)
{
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < y; j++)
		{
			x[i][j] = 2;
		}
	}
}


int main()
{
	int **A = AlocMatriz(4);
	int **B = AlocMatriz(4);
	int **C = AlocMatriz(4);

	IniM(A, 4);
	IniM(B, 4);

	MultMatrizesR(A, B, C, 4);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			std::cout << C[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}