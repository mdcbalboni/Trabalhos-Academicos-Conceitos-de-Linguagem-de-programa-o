#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **calcMult();

/*códigos para rodar com gprof
	gcc -pg -o bla -o2 MultMat.c
	./bla
	gprof -b bla gmon.out
*/

int main()
{
	int i,j,n,m,z;
	n = 1000;
	m = 1500;
	z = 1200;
	int **mat1,**mat2,**mat3;

	srand(time(NULL));

	/*ALOCAÇÃO DAS MATRIZES*/
	mat1 = calloc(n , sizeof(int*));
	for (i = 0; i < n; i++)
	{
		mat1[i] = calloc(m , sizeof(int*));
	}

	mat2 = calloc(m , sizeof(int*));
	for (i = 0; i < m; i++)
	{
		mat2[i] = calloc(z, sizeof(int*));
	}

	mat3 = calloc(n , sizeof(int*));
	for (i = 0; i < n; i++)
	{
		mat3[i] = calloc(z, sizeof(int*));
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			mat1[i][j] = rand()%10;
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < z; j++)
		{
			mat2[i][j] = rand()%10;
		}
	}

	// printf("matriz 1\n");
	// for (i = 0; i < n; i++)
	// {
	// 	for (j = 0; j < m; j++)
	// 	{
	// 		printf("%d ", mat1[i][j]);
	// 	}
	// 	printf("\n");
	// }

	// printf("matriz 2\n");
	// for (i = 0; i < m; i++)
	// {
	// 	for (j = 0; j < z; j++)
	// 	{
	// 		printf("%d ", mat2[i][j]);
	// 	}
	// 	printf("\n");
	// }

	mat3=calcMult(mat1, mat2, n, m, z);

	// printf("matriz resultante\n");
	// for (i = 0; i < n; i++)
	// {
	// 	for (j = 0; j < z; j++)
	// 	{
	// 		printf("%d ", mat3[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (i = 0; i < n; i++)
	{
		free(mat1[i]);
	}
	free(mat1);
	for (i = 0; i < m; i++)
	{
		free(mat2[i]);
	}
	free(mat2);
	for (i = 0; i < n; i++)
	{
		free(mat3[i]);
	}
	free(mat3);
	

	return 0;
}

int **calcMult (int **A, int **B, int n, int m, int z)
{
	int i,j,k,**resultado;
	
	resultado = calloc(n , sizeof(int*));
	for (i = 0; i < n; i++)
	{
		resultado[i] = calloc(z, sizeof(int*));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < z; j++)
		{
			resultado[i][j] = 0;
			for (k = 0; k < m; k++)
			{	
				resultado[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	 return resultado;

}
