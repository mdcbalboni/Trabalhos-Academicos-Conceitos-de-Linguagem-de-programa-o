#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

void **calcMult();

/*comando para rodar com gprof
	gcc -pg -o bla -O0 MultMatSemLeak.c
	./bla
	gprof -b bla gmon.out
*/

/*comando para rodar avx
	gcc -pg -mavx -o bla -O0 MultMatSemLeakAVX.c
	./bla
	gprof -b bla gmon.out
*/

/*comando para rodar valgrind
	gcc -g -o bla -O0 MultMatSemLeak.c
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./bla
*/

int main(int argc, char *argv[ ])
{
	int i,j,n,aux,resto,k;
	n = atoi(argv[1]);
	float **mat1,**mat2,**mat3;

	srand(time(NULL));

	/*Como o malloc não tem o custo de zerar as posiçoes ele se torna mais rapido e como
	a duas primeiras matrizes logo abaixo recebem valores não é necessario zerar os valores
	Já a terceira matriz que recebe o resultado é operada com "+=" necessitando que o valor
	inicial seja 0.*/
	mat1 = malloc(sizeof(float*)*n);
	mat2 = malloc(sizeof(float*)*n);
	mat3 = calloc(n , sizeof(float*));
	for (i = 0; i < n; i++)
	{
		mat1[i] = malloc(sizeof(float*)*n);
		mat2[i] = malloc(sizeof(float*)*n);
		mat3[i] = calloc(n, sizeof(float*));
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			mat1[i][j] = rand()%RAND_MAX;
			mat2[i][j] = rand()%RAND_MAX;
		}
	}

	/*Transpondo a segunda matriz podemos nos aproveitar da ???? espacial, assim podendo 
	otimizar o uso da cache*/
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

	__m256 ymm0, ymm1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j+=8)
		{
			if(j+8 <= n)
			{/*Este if testa se ainda é possivel pegar mais oito valores da matriz, ele vem primeiro por ser o teste que acontece mais vezes*/
				for (k = 0; k < n; k++)
				{
					ymm0 = _mm256_loadu_ps(&mat1[i][j]);
					ymm1 = _mm256_loadu_ps(&mat2[k][j]);
					ymm0 = _mm256_mul_ps(ymm0, ymm1);
					mat3[i][k] += ymm0[0] + ymm0[1] + ymm0[2] + ymm0[3]+ ymm0[4]+ ymm0[5]+ ymm0[6] + ymm0[7];
				}
			}
			else
			{/*Se não for possivel pegar 8 valores calcula os restantes sequencialmente*/
				resto = n%8;
				for (aux=0; aux < resto; aux++)
				{
					for (k = 0; k < n; k++)
					{
						mat3[i][j+aux] += mat1[i][k] * mat2[k][j+aux];
					}
				}
			}
		}
	}

	/*Free em todas as matrizes para evitar vazamento de memória*/
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