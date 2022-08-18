#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef struct BALDES{
	int * vet;
	int tam;
}Baldes;

void funcao(int,int );
void imprime(int,int *);
void ordena(Baldes *);

int main(){
	srand(time(NULL));
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	funcao(10,2);	
	gettimeofday(&stop, NULL);
	printf("asuygfuyasf %f\n",(float)(stop.tv_usec - start.tv_usec)/(float)1000000);
	return 0;
}

void funcao(int tam_vetor, int num_baldes){
	int i,vetor[tam_vetor],auxMAIOR; 
	pthread_t thread[num_baldes];
	for (i = 0; i < tam_vetor; i++)
		vetor[i]=rand()%RAND_MAX;
	auxMAIOR=RAND_MAX/num_baldes;
	
	Baldes balde[num_baldes];
		
	switch(num_baldes){
		case 1:   
		{
			for(i=0;i<tam_vetor;i++){
				balde[0].vet[i]=vetor[i];
				balde[0].tam++;
			}
			break;
		}
		case 2: 
		{
			for(i=0;i<tam_vetor;i++){
				if(vetor[i] < auxMAIOR){
					balde[0].vet[balde[0].tam]=vetor[i];
					balde[0].tam++;
				}
				else{
					balde[1].vet[balde[1].tam]=vetor[i];
					balde[1].tam++;
				}
			}
			break;
		}
		case 4:
		{
			for(i=0;i<tam_vetor;i++){
				if(vetor[i] < auxMAIOR){
					balde[0].vet[balde[0].tam]=vetor[i];
					balde[0].tam++;
				}
				else if(vetor[i]>=auxMAIOR  && vetor[i]<auxMAIOR*2) {
					balde[1].vet[balde[1].tam]=vetor[i];
					balde[1].tam++;
				}
				else if(vetor[i]>=auxMAIOR*2  && vetor[i]<auxMAIOR*3){ 
					balde[2].vet[balde[2].tam]=vetor[i];
					balde[2].tam++;
				}
				else{
					balde[3].vet[balde[3].tam]=vetor[i];
					balde[3].tam++;
				}
			}
			break;
		}
		case 8:
		{
			for(i=0;i<tam_vetor;i++){
				if(vetor[i] < auxMAIOR) {
					balde[0].vet[balde[0].tam]=vetor[i];
					balde[0].tam++;
				}
				else if(vetor[i]>=auxMAIOR  && vetor[i]<auxMAIOR*2) {
					balde[1].vet[balde[1].tam]=vetor[i];
					balde[1].tam++;
				}
				else if(vetor[i]>=auxMAIOR*2  && vetor[i]<auxMAIOR*3){ 
					balde[2].vet[balde[2].tam]=vetor[i];
					balde[2].tam++;
				}
				else if(vetor[i]>=auxMAIOR*3  && vetor[i]<auxMAIOR*4){ 
					balde[3].vet[balde[3].tam]=vetor[i];
					balde[3].tam++;
				}
				else if(vetor[i]>=auxMAIOR*4  && vetor[i]<auxMAIOR*5){ 
					balde[4].vet[balde[4].tam]=vetor[i];
					balde[4].tam++;
				}
				else if(vetor[i]>=auxMAIOR*5  && vetor[i]<auxMAIOR*6){ 
					balde[5].vet[balde[5].tam]=vetor[i];
					balde[5].tam++;
				}
				else if(vetor[i]>=auxMAIOR*6  && vetor[i]<auxMAIOR*7){ 
					balde[6].vet[balde[6].tam]=vetor[i];
					balde[6].tam++;
				}
				else{
					balde[7].vet[balde[7].tam]=vetor[i];
					balde[7].tam++;
				}
			}
			break;
		}
	}
	for(i=0;i<num_baldes;i++)
		pthread_create(&thread[i], NULL, (void *) ordena, (void *) &balde[i]);
	for(i=0;i<num_baldes;i++)
		pthread_join(thread[i],NULL);
	// for(i=0;i<num_baldes;i++)
	// 	imprime(balde[i].tam,balde[i].vet);

}

void ordena(Baldes *vetor)
{
	int i,j,aux,menor; 
	
	for (i = 0; i < vetor->tam-1; i++){
		menor=i;
		for (j = i+1; j < vetor->tam; j++){
			if (vetor->vet[j]<vetor->vet[menor]){
				menor=j;
			}
		}
		if(i!=menor){
			aux=vetor->vet[i];
			vetor->vet[i]=vetor->vet[menor];
			vetor->vet[menor]=aux;
		}
	}
}

void imprime(int tam, int * vetor )
{
	int i;
	for(i=0;i<tam;i++){
		printf("%d \n",vetor[i]);
	}
}
