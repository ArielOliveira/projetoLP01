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

/** @brief União das submatrizes em uma única matriz
* @param M Matriz que irá receber as submatrizes
* @param M1 Submatriz de entrada
* @param M2 Submatriz de entrada
* @param M3 Submatriz de entrada
* @param M4 Submatriz de entrada
* @param n Tamanho das submatrizes
* @return Matriz resultante da união
*/
int **UnirMatriz(int **M, int **M1, int **M2, int **M3, int **M4, int n)
{
	int i, j;
	int b = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][j] = M1[i][j];
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][n + b] = M2[i][j];
			b++;
		}
		b = 0;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i + n][j] = M3[i][j];
			b++;
		}
		b = 0;
	}

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
/** @brief Atribui valores as submatrizes da função recursiva
* @param M Matriz que possui os valores para as submatrizes
* @param M1 Submatriz de entrada
* @param M2 Submatriz de entrada
* @param M3 Submatriz de entrada
* @param M4 Submatriz de entrada
* @param n Tamanho da matriz
*/
void AtribuirSubM(int **M, int **M1, int **M2, int **M3, int **M4, int n)
{
	int i, j;
	int b = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][j] = M1[i][j];
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][n + b] = M2[i][j];
			b++;
		}
		b = 0;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i + n][j] = M3[i][j];
			b++;
		}
		b = 0;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i + n][n + b] = M4[i][j];
			b++;
		}
		b = 0;
	}
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
		M3[0][0] = M1[0][0] * M2[0][0];
		return M3;
	}
	else
	{
		/** @brief Sub matrizes de M1 */
		int **M1_11 = AlocMatriz(n/2);
		int **M1_12 = AlocMatriz(n/2);
		int **M1_21 = AlocMatriz(n/2);
		int **M1_22 = AlocMatriz(n/2);
		AtribuirSubM(M1, M1_11, M1_12, M1_21, M1_22, n/2);

		/** @brief Sub matrizes de M2 */
		int **M2_11 = AlocMatriz(n/2);
		int **M2_12 = AlocMatriz(n/2);
		int **M2_21 = AlocMatriz(n/2);
		int **M2_22 = AlocMatriz(n/2);
		AtribuirSubM(M2, M2_11, M2_12, M2_21, M2_22, n/2);

		/** @brief Sub matrizes de M3 */
		int **M3_11 = AlocMatriz(n/2);
		int **M3_12 = AlocMatriz(n/2);
		int **M3_21 = AlocMatriz(n/2);
		int **M3_22 = AlocMatriz(n/2);

		/** @brief Matriz auxiliar para armazenar a multiplicação */
		int **P_1 = AlocMatriz(n/2);
		int **P_2 = AlocMatriz(n/2);
		int **P_3 = AlocMatriz(n/2);
		int **P_4 = AlocMatriz(n/2);
		int **P_5 = AlocMatriz(n/2);
		int **P_6 = AlocMatriz(n/2);
		int **P_7 = AlocMatriz(n/2);
		int **P_8 = AlocMatriz(n/2);

		MultMatrizesR(M1_11, M2_11, P_1, n/2);
		MultMatrizesR(M1_12, M2_21, P_2, n/2);
		MultMatrizesR(M1_11, M2_12, P_3, n/2);
		MultMatrizesR(M1_12, M2_22, P_4, n/2);
		MultMatrizesR(M1_21, M2_11, P_5, n/2);
		MultMatrizesR(M1_22, M2_21, P_6, n/2);
		MultMatrizesR(M1_21, M2_12, P_7, n/2);
		MultMatrizesR(M1_22, M2_22, P_8, n/2);

		/** @brief Atribuição dos valores nas submatrizes de M3 */
		M3_11 = SomaM(P_1, P_2, n/2);
		M3_12 = SomaM(P_3, P_4, n/2);
		M3_21 = SomaM(P_5, P_6, n/2);
		M3_22 = SomaM(P_7, P_8, n/2);

		M3 = UnirMatriz(M3, M3_11, M3_12, M3_21, M3_22, n/2);

		return M3;
	}
}