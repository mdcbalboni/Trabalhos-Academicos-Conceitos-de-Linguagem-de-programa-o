#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcOrdenaC"

int main()
{
	int vetor[10],i;
	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		vetor[i]=rand()%10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ",vetor[i]);
	}

	ordena(vetor);

	printf("\n\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ",vetor[i]);
	}

	return 0;
}