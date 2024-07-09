#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define ROWS 40
#define COLS 150
#define FRAME 40 * 1000

typedef int Frame[ROWS][COLS];

typedef enum {
	ON = 2,
	OFF = 0,
	DYING = 1
} CellState;

void	Display(int Front[ROWS][COLS], int Back[ROWS][COLS]);
void	Calculate(void);
int	mod(int a, int b);
void	Dead(void);
int	CountNeighbours(int cx , int cy);
#endif //AUTOMATA_H_
