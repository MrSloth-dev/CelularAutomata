#include "automata.h"

int Front [ROWS][COLS] = {0};
int Back [ROWS][COLS] = {0};

int	mod(int a, int b)
{
	return ((a % b + b) % b);
}

int	main(int argc, char *argv[])
{
	int life;
	if (argc == 2)
		life = atoi(argv[1]);
	else
		exit(printf("Usage ./life <integer>\n 35 is a good number."));
	srand(time(NULL));
	for (int i = 0; i < life; i++)
	{
		int y = mod(rand(), ROWS);
		int x = mod(rand(), COLS);
		Front[y][x] = 1;
		Front[mod(y+1,ROWS)][mod(x+1,COLS)] = 1;
		Front[mod(y-1,ROWS)][mod(x+1,COLS)] = 1;
	}
	while (1) {
		Display(Front, Back);
		Calculate();
		memcpy(Front, Back, sizeof(Front));
		Dead();
	}
	return (0);
}

void	Dead(void)
{
	int alive = 0;
		for (int y = 0; y < ROWS; y++)
			for (int x = 0; x < COLS; x++)
				if (Front[y][x] == 1) alive++;
	if (!alive) exit (1);
}


void	Calculate(void)
{
		for (int y = 0; y < ROWS; y++) {
			for (int x = 0; x < COLS; x++) {
				int nbours = CountNeighbours(x, y);
				if (!Front[y][x] && nbours == 3)
					Back[y][x] = 1;
				else if (Front[y][x] && nbours < 2)
					Back[y][x] = 0;
				else if (Front[y][x] && nbours <= 3)
					Back[y][x] = 1;
				else
					Back[y][x] = 0;
			}
		}
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
				if (Front[y][x] == 1) count++;
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
			if (Front[i][j])
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	usleep(FRAME);
	printf("\e[1;1H\e[2J");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (Back[i][j])
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
}
