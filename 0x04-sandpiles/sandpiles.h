#ifndef _SANDPILES_H_
#define _SANDPILES_H_
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
int check_zero_grid(int grid1[3][3], int grid2[3][3]);
void toppling_v2(int grid[3][3]);
void check_grid(int grid[3][3]);

#endif /* _SANDPILES_H_ */
