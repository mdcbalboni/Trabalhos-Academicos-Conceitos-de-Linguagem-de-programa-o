#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void **calcMult();

/*códigos para rodar com gprof
	gcc -pg -o bla -O0 MultMatSemLeak.c
	./bla
	gprof -b bla gmon.out
*/

/*
	gcc -g -o bla -O0 MultMatSemLeak.c
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./bla
*/

int main(int argc, char *argv[ ])
{
	int i,j,n,aux;
	if (argv[1] == NULL)
	{
		n = 1;
	}else{
		n = atoi(argv[1]);
	}
	int **mat1,**mat2,**mat3;

	srand(time(NULL));

	/*ALOCAÇÃO DAS MATRIZES*/
	mat1 = calloc(n, sizeof(int*));
	mat2 = calloc(n, sizeof(int*));
	mat3 = calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
	{
		mat1[i] = calloc(n, sizeof(int*));
		mat2[i] = calloc(n, sizeof(int*));
		mat3[i] = calloc(n, sizeof(int*));
	}



	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			mat1[i][j] = rand()%RAND_MAX;
			mat2[i][j] = rand()%RAND_MAX;
		}
	}

// 	printf("matriz 1\n");
// 	for (i = 0; i < n; i++)
// 	{
// 		for (j = 0; j < n; j++)
// 		{
// 			printf("%d ", mat1[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	printf("matriz 2\n");
// 	for (i = 0; i < n; i++)
// 	{
// 		for (j = 0; j < n; j++)
// 		{
// 			printf("%d ", mat2[i][j]);
// 		}
// 		printf("\n");
// 	}

	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (j != i)
			{
				aux = mat2[i][j];
				mat2[i][j] = mat2[j][i];
				mat2[j][i] = aux;
		  	}
		}
	}	

	

	calcMult(mat1, mat2, mat3, n);

	// printf("matriz resultante\n");
	// for (i = 0; i < n; i++)
	// {
	// 	for (j = 0; j < n; j++)
	// 	{
	// 		printf(" %d ", mat3[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (i = 0; i < n; i++)
	{
		free(mat1[i]);
	}
	free(mat1);
	for (i = 0; i < n; i++)
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

void **calcMult (int **A, int **B, int **C, int n)
{
	int i,j,k,aux,resto	;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			C[i][j] = 0;
			// C[i][j+1] = 0;
			// C[i][j+2] = 0;
			// C[i][j+3] = 0;
			// C[i][j+4] = 0;
			// C[i][j+5] = 0;
			// C[i][j+6] = 0;
			// C[i][j+7] = 0;
			// C[i][j+8] = 0;
			// C[i][j+9] = 0;
			// C[i][j+10] = 0;
			// C[i][j+11] = 0;
			// C[i][j+12] = 0;
			// C[i][j+13] = 0;
			// C[i][j+14] = 0;
			// C[i][j+15] = 0;
			// if(j+4 < n)
			// {
				for (k = 0; k < n; k++)
				{	
					C[i][j] += A[i][k] * B[j][k];
					// C[i][j+1] += A[i][k] * B[j+1][k];
					// C[i][j+2] += A[i][k] * B[j+2][k];
					// C[i][j+3] += A[i][k] * B[j+3][k];
					// C[i][j+4] += A[i][k] * B[j+4][k];
					// C[i][j+5] += A[i][k] * B[j+5][k];
					// C[i][j+6] += A[i][k] * B[j+6][k];
					// C[i][j+7] += A[i][k] * B[j+7][k];
					// C[i][j+8] += A[i][k] * B[k][j+8];
					// C[i][j+9] += A[i][k] * B[k][j+9];
					// C[i][j+10] += A[i][k] * B[k][j+10];
					// C[i][j+11] += A[i][k] * B[k][j+11];
					// C[i][j+12] += A[i][k] * B[k][j+12];
					// C[i][j+13] += A[i][k] * B[k][j+13];
					// C[i][j+14] += A[i][k] * B[k][j+14];
					// C[i][j+15] += A[i][k] * B[k][j+15];
				}
			// }
			// else
			// {
			// 	resto = n%4;
			// 	aux = 0;
			// 	for (aux=0; aux < resto; aux++)
			// 	{
			// 		for (k = 0; k < n; k++)
			// 		{
			// 			C[i][j+aux] += A[i][k] * B[j+aux][k];
			// 		}
			// 	}
			// }
		}
	}

}	