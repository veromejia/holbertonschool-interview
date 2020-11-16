#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * @level: number of levels to draw
 */
void menger(int level)
{
	int column, row, size, isblank;

	if (level >= 0)
	{
		size = pow(3, level);
		for (row = 0; row < size; row++)
		{
			for (column = 0; column < size; column++)
			{
				isblank = is_blank(column, row);

				if (isblank == 1)
					printf("%c", ' ');
				else
					printf("%c", '#');

				isblank = 0;
			}

			printf("\n");
		}
	}
}

/**
 * is_blank - verify if the character should be blank
 * @c: column
 * @r: row
 * Return: one if is blank otherwise 0
 */

int is_blank(int c, int r)
{
	for (; c && r; c /= 3, r /= 3)
		if (c % 3 == 1 && r % 3 == 1)
			return (1);
	return (0);
}
