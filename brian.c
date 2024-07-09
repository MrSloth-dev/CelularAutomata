#include "automata.h"

extern int Front[ROWS][COLS];
extern int Back[ROWS][COLS];

void	Calculate(void)
{
		for (int y = 0; y < ROWS; y++) {
			for (int x = 0; x < COLS; x++) {
				int nbours = CountNeighbours(x, y);
				if (Front[y][x] == 2)
					Back[y][x] = 1;
				if (Front[y][x] == 1)
					Back[y][x] = 0;
				else if (!Front[y][x] && nbours == 2)
					Back[y][x] = 2;
			}
		}
}
