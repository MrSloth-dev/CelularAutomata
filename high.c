#include "automata.h"

extern int Front[ROWS][COLS];
extern int Back[ROWS][COLS];

void	Calculate(void)
{
		for (int y = 0; y < ROWS; y++) {
			for (int x = 0; x < COLS; x++) {
				int nbours = CountNeighbours(x, y);
				if (Front[y][x] && (nbours == 3 || nbours == 2))
					Back[y][x] = ON;
				else if (Front[y][x])
					Back[y][x] = OFF;
				else if (!Front[y][x] && (nbours == 3 || nbours == 6))
					Back[y][x] = ON;
			}
		}
}
