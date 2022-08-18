#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordena(int,int);

pthread_mutex_t mutexTEX;

typedef struct BUCKETS
{
	int * values;
}Buckets;

int main()
{
	
	srand(time(NULL));

	funcao(10,1);
	// funcao(10,2);
	// funcao(10,4);
	// funcao(10,8);

	// pthread_mutex_init(&mutexTEX, NULL);
	
	// pthread_create(&thread[0], NULL, (void *) ???, (void *) ???);
	// pthread_join(thread[0],NULL);
	
	return 0;
}

void funcao(int arraySize, int nmbBuckets)
{
	int i,j,aux,menor,array[arraySize]; 
	pthread_t thread[nmbBuckets];
	Buckets bcks[nmbBuckets];
	switch(nmbBuckets)
	{
		case 1:
			for (i = 0; i < arraySize; i++)
				array[i]=rand()%RAND_MAX;

			aux = arraySize/nmbBuckets;
			for (i = 0; i < nmbBuckets; i++)
			{
				bcks[i].values = calloc(1,sizeof(int));
			}
			
			ordena(arraySize,bcks[0].values)

			for (i = 0; i < arraySize; i++)
				printf("array: %d\n",array[i]);
	}

	// for (i = 0; i < arraySize; i++)
	// 	printf("array: %d - - array/nmbBuckets: %d - - array/aux %d\n",array[i], array[i]%nmbBuckets, array[i]%aux);
}

void ordena(int arraySize, int * array)
{
	int i,j,aux,menor; 
	for (i = 0; i < arraySize-1; i++)
	{
		menor=i;
		for (j = i+1; j < arraySize; j++)
		{
			if (array[j]<array[menor])
			{
				menor=j;
			}
		}
		if(i!=menor)
		{
			aux=array[i];
			array[i]=array[menor];
			array[menor]=aux;
		}
	}
}