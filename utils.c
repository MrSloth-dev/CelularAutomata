
#include "automata.h"

extern int Front[ROWS][COLS];
extern int Back[ROWS][COLS];

int	mod(int a, int b)
{
	return ((a % b + b) % b);
}

void	Dead(void)
{
	int alive = 0;
		for (int y = 0; y < ROWS; y++)
			for (int x = 0; x < COLS; x++)
				if (Front[y][x] == ON) alive++;
	if (!alive) exit (1);
}

int	CountNeighbours(int cx , int cy)
{
	int	count = 0;
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx != 0 || dy != 0 )
			{
				int x = mod(cx + dx, COLS);
				int y = mod(cy + dy, ROWS);
				if (Front[y][x] == ON) count++;
			}
		}
	}
	return (count);
}
void	Display(int Front[ROWS][COLS], int Back[ROWS][COLS])
{
	usleep(FRAME);
	printf("\e[1;1H\e[2J");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (Front[i][j] == ON)
				printf("\033[1;36m#\033[0m");
			else if (Front[i][j] == DYING)
				printf("\033[1;31m#\033[0m");
			else
				printf("\033[1;37m.\033[0m");
		}
		printf("\n");
	}
	usleep(FRAME);
	printf("\e[1;1H\e[2J");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (Back[i][j] == ON)
				printf("\033[1;36m#\033[0m");
			else if (Back[i][j] == DYING)
				printf("\033[1;31m#\033[0m");
			else
				printf("\033[1;37m.\033[0m");
		}
		printf("\n");
	}
}
