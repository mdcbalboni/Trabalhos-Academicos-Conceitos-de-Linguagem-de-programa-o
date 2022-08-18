#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ordena(int vetor[])
{
	int i,j,aux,menor;
	for (i = 0; i < 9; i++)
	{
		menor=i;
		for (j = i+1; j < 10; j++)
		{
			if (vetor[j]<vetor[menor])
			{
				menor=j;
			}
		}
		if(i!=menor)
		{
			aux=vetor[i];
			vetor[i]=vetor[menor];
			vetor[menor]=aux;
		}
	}
}