#include "automata.h"

int Front [ROWS][COLS] = {0};
int Back [ROWS][COLS] = {0};

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
		Front[y][x] = ON;
		Front[mod(y+1,ROWS)][mod(x+1,COLS)] = ON;
		Front[mod(y-1,ROWS)][mod(x+1,COLS)] = ON;
	}
	while (1) {
		Display(Front, Back);
		Calculate();
		memcpy(Front, Back, sizeof(Front));
		Dead();
	}
	return (0);
}


