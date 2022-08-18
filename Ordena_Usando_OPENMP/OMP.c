#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	srand(time(NULL));
	int arraySize = 16;
	int nmbBuckets = 4;
	int i,j,array[arraySize],rndMax,matrix[nmbBuckets][arraySize],sizes[nmbBuckets]; 
	for (i = 0; i < arraySize; i++)
		array[i]=rand()%RAND_MAX;

	rndMax=RAND_MAX/nmbBuckets;
	
	for(i=0;i<nmbBuckets;i++)
		sizes[i] = 0;
	
	if (nmbBuckets == 1)   
	{
		for(i=0;i<arraySize;i++)
		{
			matrix[0][i] = array[i];
			sizes[0]++;
		}
	}
	else if(nmbBuckets == 2) 
	{
		for(i=0;i<arraySize;i++)
		{
			if(array[i] < rndMax)
			{
				matrix[0][sizes[0]] = array[i];
				sizes[0]++;
			}
			else
			{
				matrix[1][sizes[1]] = array[i];
				sizes[1]++;
			}
		}
	}
	else if(nmbBuckets == 4) 
	{
		for(i=0;i<arraySize;i++)
		{
			if(array[i] < rndMax)
			{
				matrix[0][sizes[0]] = array[i];
				sizes[0]++;
			}
			else if(array[i]>=rndMax  && array[i]<rndMax*2)
			{
				matrix[1][sizes[1]] = array[i];
				sizes[1]++;
			}
			else if(array[i]>=rndMax*2  && array[i]<rndMax*3)
			{
				matrix[2][sizes[2]] = array[i];
				sizes[2]++;
			}
			else
			{
				matrix[3][sizes[3]] = array[i];
				sizes[3]++;
			}
		}
	}
	else if(nmbBuckets == 8) 
	{
		for(i=0;i<arraySize;i++)
		{
			if(array[i] < rndMax) 
			{
				matrix[0][sizes[0]] = array[i];
				sizes[0]++;	
			}
			else if(array[i]>=rndMax  && array[i]<rndMax*2) 
			{
				matrix[1][sizes[1]] = array[i];
				sizes[1]++;	
			}
			else if(array[i]>=rndMax*2  && array[i]<rndMax*3)
			{
			 	matrix[2][sizes[2]] = array[i];
				sizes[2]++;
			}
			else if(array[i]>=rndMax*3  && array[i]<rndMax*4)
			{
			 	matrix[3][sizes[3]] = array[i];
				sizes[3]++;
			}
			else if(array[i]>=rndMax*4  && array[i]<rndMax*5)
			{
			 	matrix[4][sizes[4]] = array[i];
				sizes[4]++;
			}
			else if(array[i]>=rndMax*5  && array[i]<rndMax*6)
			{
			 	matrix[5][sizes[5]] = array[i];
				sizes[5]++;
			}
			else if(array[i]>=rndMax*6  && array[i]<rndMax*7)
			{
			 	matrix[6][sizes[6]] = array[i];
				sizes[6]++;
			}
			else
			{
				matrix[7][sizes[7]] = array[i];
				sizes[7]++;	
			}
		}
	}

	#pragma omp parallel num_threads(nmbBuckets)
	{
		int i,j,aux,menor,id; 
		id=omp_get_thread_num();
		for (i = 0; i < sizes[id]-1; i++)
		{
			menor=i;
			for (j = i+1; j < sizes[id]; j++)
			{
				if (matrix[id][j]<matrix[id][menor])
				{
					menor=j;
				}
			}
			if(i!=menor)
			{
				aux=matrix[id][i];
				matrix[id][i]=matrix[id][menor];
				matrix[id][menor]=aux;
			}
		}
	}

	// for (i = 0; i < nmbBuckets; i++)
	// {
	// 	for(j=0;j<sizes[i];j++)
	// 		printf("fim: %d \n",matrix[i][j]);
	// }

	return 0;
}