#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordena(int,int *);
void funcao(int,int );
void imprime(int,int *);
pthread_mutex_t mutexTEX;

typedef struct BUCKETS
{
	int * values;
	int tam;
}Buckets;



int main()
{
	
	srand(time(NULL));
	 //funcao(10,1);
	//funcao(10,2);
	 //funcao(10,4);
	 funcao(100000,8);

	// pthread_mutex_init(&mutexTEX, NULL);
	
	// pthread_create(&thread[0], NULL, (void *) ???, (void *) ???);
	// pthread_join(thread[0],NULL);
	
	return 0;
}

void funcao(int arraySize, int nmbBuckets)
{
	int i,array[arraySize],auxMAIOR; 
	//pthread_t thread[nmbBuckets];
	for (i = 0; i < arraySize; i++)
		array[i]=rand()%RAND_MAX;
	auxMAIOR=RAND_MAX/nmbBuckets;
	//aux = arraySize/nmbBuckets;
	Buckets bcks[nmbBuckets];
	
	//Alocando os baldes
	for(i=0;i<nmbBuckets;i++){
		bcks[i].values = calloc(arraySize,sizeof(int));
		bcks[i].tam=0;
	}
		//deu.
		
	
	switch(nmbBuckets)
	{
		case 1:   
		{
		  // SEM THREADS, caso com 1 bucket
				//"FUNCIONANDO"
			for(i=0;i<arraySize;i++){
				bcks[0].values[i]=array[i];
			}
			ordena(arraySize,bcks[0].values);
			imprime(arraySize,bcks[0].values);
			break;
		}
		case 2: 
		{
		// 2 buckets
		 //"FUNCIONANDO"
		//	printf("ENTREI\n");
			
			
			for(i=0;i<arraySize;i++)
				if(array[i] < auxMAIOR)
				{
					bcks[0].values[bcks[0].tam]=array[i];
					bcks[0].tam++;
				}
				else
				{
					bcks[1].values[bcks[1].tam]=array[i];
					bcks[1].tam++;
				}
	

				//bcks[0].values[i]=array[i];
			//}
			for(i=0;i<nmbBuckets;i++)
			{
				ordena(bcks[i].tam,bcks[i].values);
				imprime(bcks[i].tam,bcks[i].values);
			}
		break;
	}
		case 4:
		{
			// 4 buckets
			// "FUNCIONANDO"
			for(i=0;i<arraySize;i++)
				if(array[i] < auxMAIOR) //CERTO
				{
					bcks[0].values[bcks[0].tam]=array[i];
					bcks[0].tam++;
				}
				else if(array[i]>=auxMAIOR  && array[i]<auxMAIOR*2) //
				{
					bcks[1].values[bcks[1].tam]=array[i];
					bcks[1].tam++;
				}
				else if(array[i]>=auxMAIOR*2  && array[i]<auxMAIOR*3)
				{ //
					bcks[2].values[bcks[2].tam]=array[i];
					bcks[2].tam++;
				}else{
					bcks[3].values[bcks[3].tam]=array[i];
					bcks[3].tam++;
			}
			for(i=0;i<nmbBuckets;i++)
			{
				ordena(bcks[i].tam,bcks[i].values);
				imprime(bcks[i].tam,bcks[i].values);
			}
		break;
		}
		case 8:
		{
			// 8 buckets
			// "FUNCIONANDO"
			for(i=0;i<arraySize;i++)
				if(array[i] < auxMAIOR) 
				{
					bcks[0].values[bcks[0].tam]=array[i];
					bcks[0].tam++;
				}
				else if(array[i]>=auxMAIOR  && array[i]<auxMAIOR*2) 
				{
					bcks[1].values[bcks[1].tam]=array[i];
					bcks[1].tam++;
				}
				else if(array[i]>=auxMAIOR*2  && array[i]<auxMAIOR*3)
				{ //
					bcks[2].values[bcks[2].tam]=array[i];
					bcks[2].tam++;
				}
				else if(array[i]>=auxMAIOR*3  && array[i]<auxMAIOR*4)
				{ //
					bcks[3].values[bcks[3].tam]=array[i];
					bcks[3].tam++;
				}
					else if(array[i]>=auxMAIOR*4  && array[i]<auxMAIOR*5)
				{ //
					bcks[4].values[bcks[4].tam]=array[i];
					bcks[4].tam++;
				}
					else if(array[i]>=auxMAIOR*5  && array[i]<auxMAIOR*6)
				{ //
					bcks[5].values[bcks[5].tam]=array[i];
					bcks[5].tam++;
				}
					else if(array[i]>=auxMAIOR*6  && array[i]<auxMAIOR*7)
				{ //
					bcks[6].values[bcks[6].tam]=array[i];
					bcks[6].tam++;
				}else{
					bcks[7].values[bcks[7].tam]=array[i];
					bcks[7].tam++;
			}
			for(i=0;i<nmbBuckets;i++)
			{
				ordena(bcks[i].tam,bcks[i].values);
		//		imprime(bcks[i].tam,bcks[i].values);
			}
		break;
		
		}
	}



}

void ordena(int arraySize, int * array)
{
	int i,j,aux,menor; 
	//imprime(arraySize,array);
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

void imprime(int tam, int * a )
{
	int i;
		for(i=0;i<tam;i++){
			printf("%d \n",a[i]);
		}
}

