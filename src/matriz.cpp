/**
* @file matriz.cpp
* @brief Funções interativas e recursivas para a multiplicação das matrizes
* @autor Rodrigo Rocha Moriyama <rodrigo.oi@hotmail.com> && Ariel de Oliveira Corrêa <ariel.oliveira01@gmail.com>
* @since 28/04/2017
* @last 01/05/2017
*/

#include "matriz.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

/** @brief Soma de duas matrizes
* @param M1 Matriz de entrada
* @param M2 Matriz de entrada
* @param n Tamanho das matrizes
* @return Matriz resultante da soma
*/
template<typename T>
T **SomaM(T **M1, T **M2, int n)
{
	int i,j;
	T **M3 = AlocMatriz<T>(n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}

	return M3;
}

/** @brief Multiplicação interativa das matrizes
* @param M1 Matriz de entrada
* @param M2 Matriz de entrada
* @param m Tamanho das matrizes de entrada
* @param M3 Matriz para resultado
* @return Matriz resultante da multiplicação
*/
template<typename T>
T **MultMatrizesI(T **M1, T **M2, int m) {
	T soma;
	T **M3;
	int i,k,j;

	M3 = AlocMatriz<T>(m);

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

template int **MultMatrizesI<int>(int **M1, int **M2, int m);


/** @brief União das submatrizes em uma única matriz
* @param M Matriz que irá receber as submatrizes
* @param M1 Submatriz de entrada
* @param M2 Submatriz de entrada
* @param M3 Submatriz de entrada
* @param M4 Submatriz de entrada
* @param n Tamanho das submatrizes
* @return Matriz resultante da união
*/
template<typename T>
T **UnirMatriz(T **M, T **M1, T **M2, T **M3, T **M4, int n) {
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

template int **UnirMatriz<int>(int **M, int **M1, int **M2, int **M3, int **M4, int n);

/** @brief Atribui valores as submatrizes da função recursiva
* @param M Matriz que possui os valores para as submatrizes
* @param M1 Submatriz de entrada
* @param M2 Submatriz de entrada
* @param M3 Submatriz de entrada
* @param M4 Submatriz de entrada
* @param n Tamanho da matriz
*/
template<typename T>
void AtribuirSubM(T **M, T **M1, T **M2, T **M3, T **M4, int n) {
	int i, j;
	int b = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M1[i][j] = M[i][j];
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M2[i][j] = M[i][n + b];
			b++;
		}
		b = 0;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M3[i][j] = M[i + n][j];
			b++;
		}
		b = 0;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M4[i][j] = M[i + n][n + b];
			b++;
		}
		b = 0;
	}
}

template void AtribuirSubM<int>(int **M, int **M1, int **M2, int **M3, int **M4, int n);

/* @brief Multiplicação recursiva
* @param M1 Matriz de entrada
* @param M2 Matriz de entrada
* @param M3 Matriz de entrada
* @param n Tamanho das matrizes
* @return Matriz resultante da multiplicação
*/
template<typename T>
T **MultMatrizesR(T **M1, T **M2, T **M3, int n) {
	if(n == 1)
	{
		M3[0][0] = M1[0][0] * M2[0][0];
		return M3;
	} 
	else
	{
		/** @brief Sub matrizes de M1 */
		T **M1_11 = AlocMatriz<T>(n/2);
		T **M1_12 = AlocMatriz<T>(n/2);
		T **M1_21 = AlocMatriz<T>(n/2);
		T **M1_22 = AlocMatriz<T>(n/2);
		AtribuirSubM<T>(M1, M1_11, M1_12, M1_21, M1_22, n/2);

		/** @brief Sub matrizes de M2 */
		T **M2_11 = AlocMatriz<T>(n/2);
		T **M2_12 = AlocMatriz<T>(n/2);
		T **M2_21 = AlocMatriz<T>(n/2);
		T **M2_22 = AlocMatriz<T>(n/2);
		AtribuirSubM<T>(M2, M2_11, M2_12, M2_21, M2_22, n/2);

		/** @brief Sub matrizes de M3 */
		T **M3_11 = AlocMatriz<T>(n/2);
		T **M3_12 = AlocMatriz<T>(n/2);
		T **M3_21 = AlocMatriz<T>(n/2);
		T **M3_22 = AlocMatriz<T>(n/2);

		/** @brief Matriz auxiliar para armazenar a multiplicação */
		T **P_1 = AlocMatriz<T>(n/2);
		T **P_2 = AlocMatriz<T>(n/2);
		T **P_3 = AlocMatriz<T>(n/2);
		T **P_4 = AlocMatriz<T>(n/2);
		T **P_5 = AlocMatriz<T>(n/2);
		T **P_6 = AlocMatriz<T>(n/2);
		T **P_7 = AlocMatriz<T>(n/2);
		T **P_8 = AlocMatriz<T>(n/2);

		MultMatrizesR<T>(M1_11, M2_11, P_1, n/2);
		MultMatrizesR<T>(M1_12, M2_21, P_2, n/2);
		MultMatrizesR<T>(M1_11, M2_12, P_3, n/2);
		MultMatrizesR<T>(M1_12, M2_22, P_4, n/2);
		MultMatrizesR<T>(M1_21, M2_11, P_5, n/2);
		MultMatrizesR<T>(M1_22, M2_21, P_6, n/2);
		MultMatrizesR<T>(M1_21, M2_12, P_7, n/2);
		MultMatrizesR<T>(M1_22, M2_22, P_8, n/2);

		/** @brief Atribuição dos valores nas submatrizes de M3 */
		M3_11 = SomaM<T>(P_1, P_2, n/2);
		M3_12 = SomaM<T>(P_3, P_4, n/2);
		M3_21 = SomaM<T>(P_5, P_6, n/2);
		M3_22 = SomaM<T>(P_7, P_8, n/2);

		M3 = UnirMatriz<T>(M3, M3_11, M3_12, M3_21, M3_22, n/2);
		
		deleteMatriz<T>(M1_11, n/2);
		deleteMatriz<T>(M1_12, n/2);
		deleteMatriz<T>(M1_21, n/2);
		deleteMatriz<T>(M1_22, n/2);

		deleteMatriz<T>(M2_11, n/2);
		deleteMatriz<T>(M2_12, n/2);
		deleteMatriz<T>(M2_21, n/2);
		deleteMatriz<T>(M2_22, n/2);

		deleteMatriz<T>(M3_11, n/2);
		deleteMatriz<T>(M3_12, n/2);
		deleteMatriz<T>(M3_21, n/2);
		deleteMatriz<T>(M3_22, n/2);

		deleteMatriz<T>(P_1, n/2);
		deleteMatriz<T>(P_2, n/2);
		deleteMatriz<T>(P_3, n/2);
		deleteMatriz<T>(P_4, n/2);
		deleteMatriz<T>(P_5, n/2);
		deleteMatriz<T>(P_6, n/2);
		deleteMatriz<T>(P_7, n/2);
		deleteMatriz<T>(P_8, n/2);

		return M3;
	}
}

template int **MultMatrizesR<int>(int **M1, int **M2, int **M3, int n);