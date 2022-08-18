#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define QUEEN  7
#define EMPTY  0
int main(int argc, char* argv[])
{
	int boardSize,i,j,k,queensQty,var,wrongMove,ok,aux,notHere;
	boardSize = 4;
	queensQty = 0;
	wrongMove = 0;
	ok = 0;
	aux = 0;
	notHere = 0;
	int board [boardSize][boardSize];
	time_t t;
	srand((unsigned) time(&t));

	// printf("%d",boardSize);
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			board[i][j] = EMPTY;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %d ", board[i][j]);
		}
		printf("\n");
	}

	/*Começa com uma posição aleatória para a primeira rainha na primeira linha*/
	board[0][rand()%3] = QUEEN;
	while(queensQty != boardSize)
	{/*Enquanto o número de rainhas posicionadas for menor que o tamanho do tabuleiro continua o programa.*/
		for (i = 1; i < boardSize; i++)
		{/*começa a partir da segunda linha*/
			for (j = 0; j < boardSize; j++)
			{
				if(board[i][j] == EMPTY)
				{
					var = i-1;
					k = 1;
					while(var != -1)
					{/*Teste para conferir se há outra rainha acima ou na diagonal*/
						if (board[var][j] == QUEEN || board[var][j-k] == QUEEN || board[var][j+k] == QUEEN)
						{
							wrongMove = 1;
							break;
						}
						k++;
						var--;
					}
					if (wrongMove == 0)
					{
						board[i][j] = QUEEN;
						break;
					}
				}
			}
			if (wrongMove == 1)
			{//se chegar aqui com wrongMove == 1 significa que deu ruim e precisa trocar de posição a rainha de cima.
				aux = i-1;
				while(ok != 1)
				{
					for (j = 0; j < boardSize; j++)
					{
						if (board[aux][j] == QUEEN && board[aux][j+1] == EMPTY)
						{
							board[aux][j] = EMPTY;
							board[aux][j+1] = QUEEN;
							var = aux;
							k = 1;
							while(var != -1)
							{/*Teste para conferir se há outra rainha acima ou na diagonal*/
								if (board[var][j] == QUEEN || board[var][j-k] == QUEEN || board[var][j+k] == QUEEN)
								{
									notHere = 1;
									break;
								}
								k++;
								var--;
							}
						}
					}
					if (notHere == 0)
					{
						break;
					}
					aux --;
				}
				wrongMove = 0;
				i -= 2;
			}
		}
	}
}

