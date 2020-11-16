#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	check_grid(grid1);
}

/**
 * check_zero_grid - verify if all values in a grid are 0s
 * @grid1: first grid
 * @grid2: second grid
 * Return: 0 or 1
 */
int check_zero_grid(int grid1[3][3], int grid2[3][3])
{
	int sum1, sum2, i, j;

	sum1 = 0;
	sum2 = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum1 = sum1 + grid1[i][j];
			sum2 = sum2 + grid2[i][j];
		}
	}

	if (sum1 == 0 || sum2 == 0)
		return (0);
	return (1);

}

/**
 * toppling_v2 - reduce the grid
 * @grid: first grid
 */

void toppling_v2(int grid[3][3])
{
	int i, j;
	int copy[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			copy[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (copy[i][j] > 3)
			{
				grid[i][j] = grid[i][j] - 4;
				if (i > 0)
					grid[i - 1][j] = grid[i - 1][j] + 1;
				if (j < 2)
					grid[i][j + 1] = grid[i][j + 1] + 1;
				if (i < 2)
					grid[i + 1][j] = grid[i + 1][j] + 1;
				if (j > 0)
					grid[i][j - 1] = grid[i][j - 1] + 1;
			}
		}
	}
	check_grid(grid);
}

/**
 * check_grid - verify if grid1 is stable
 * @grid: first grid
 */
void check_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				print_grid(grid);
				toppling_v2(grid);
			}
		}
	}
}

/**
 * print_grid - print the grid1
 * @grid: first grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
