#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define ROWS 32
#define COLS 100
#define FRAME 10 * 1000

void	Display(int Front[ROWS][COLS], int Back[ROWS][COLS]);
int	CountNeighbours(int cx , int cy);
void	Calculate(void);
void	Dead(void);
#endif //AUTOMATA_H_
