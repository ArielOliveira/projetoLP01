/**
* @file matriz.cpp
* @brief Funções interativas e recursivas para a multiplicação das matrizes
* @autor Rodrigo Rocha Moriyama <rodrigo.oi@hotmail.com>
* @since 28/04/2017
*/

#include "matriz.h" 

/** @brief Aloca os espaços da matriz dinamicamente */
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

/** @brief Multiplicação interativa */
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

