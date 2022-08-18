#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define QUEEN  7
#define EMPTY  0
int main(int argc, char* argv[])
{
	int boardSize,i,j,k,var,wrongMove,aux;
	if (atoi(argv[1]) < 4)
	{
		printf("Não pode ser um numero menor que 4\n");
		return 0;
	}
	boardSize = atoi(argv[1]);
	wrongMove = 0;.
	aux = 0;
	int board [boardSize][boardSize];
	
	for (i = 0; i < boardSize; i++)
	{
		for (j = 0; j < boardSize; j++)
		{
			board[i][j] = EMPTY;
		}
	}

	board[0][0] = QUEEN;
	
	j=0;
	for (i = 1; i < boardSize; i++)
	{/*começa a partir da segunda linha*/
		for (j = j; j < boardSize; j++)
		{
			if(board[i][j] == EMPTY)
			{
				var = i-1;
				k = 1;
				wrongMove = 0;
				while(var != -1)
				{/*Teste para conferir se há outra rainha acima ou nas diagonais*/
					if (j-k < 0)
					{
						if(board[var][j] == QUEEN || board[var][j+k] == QUEEN)
						{
							wrongMove = 1;
							break;
						}
					}
					else if (j+k > boardSize-1)
					{
						if(board[var][j] == QUEEN || board[var][j-k] == QUEEN)
						{
							wrongMove = 1;
							break;
						}
					}
					else if (j+k > boardSize-1 || j-k < 0)
					{
						if(board[var][j] == QUEEN || board[var][j-k] == QUEEN)
						{

							wrongMove = 1;
							break;
						}
					}
					else
					{
						if(board[var][j] == QUEEN || board[var][j-k] == QUEEN || board[var][j+k] == QUEEN)
						{
							wrongMove = 1;
							break;
						}
					}
					
					k++;
					var--;
				}
				if (wrongMove == 0)
				{
					board[i][j] = QUEEN;
					j=0;
					break;
				}
			}
		}
		if (wrongMove == 1)
		{
			aux = i-1;
			for (j = 0; j < boardSize; j++)
			{
				if (board[aux][j] == QUEEN)
				{
					board[aux][j] = EMPTY;
					j++;
					i -= 2;
					break;
				}
			}
		}
	}
	/*Resultado*/
	// for (i = 0; i < boardSize; i++)
	// {
	// 	for (j = 0; j < boardSize; j++)
	// 	{
	// 		printf(" %d ", board[i][j]);
	// 	}
	// 	printf("\n");
	// }
}

