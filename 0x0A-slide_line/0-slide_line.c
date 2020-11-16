#include "slide_line.h"

/**
 * slide_line - function that slides and merges an array of integers
 * @line: integer array to slide
 * @size: size of the array
 * @direction: macro of which direction to slide numbers
 * Return:  return 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		slide_left(line, size);
	return (1);
}

/**
 * slide_left - slides and merges an array of integers to the left
 * @line: integer array to slide
 * @size: size of the array
 */
void slide_left(int *line, size_t size)
{
	size_t i, prev = 0, j = 0;

	for (i = 1; i < size; i++)
	{
		if (line[i])
		{
			if (line[prev])
			{
				if (line[prev] == line[i])
				{
					line[prev++] *= 2;
					line[i] = 0;
				}
			}
			prev = i;
		}

	}

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			j++;
		else if (j)
			line[i - j] = line[i];
	}
	for (i = size - j; i < size; i++)
		line[i] = 0;
}

/**
 * slide_right - slides and merges an array of integers to the right
 * @line: integer array to slide
 * @size: size of the array
 */
void slide_right(int *line, size_t size)
{
	ssize_t i, prev = size - 1, zeroes = 0;

	for (i = size - 2; i >= 0; i--)
	{
		if (line[i])
		{
			if (line[prev])
			{
				if (line[prev] == line[i])
				{
					line[prev--] *= 2;
					line[i] = 0;
				}
			}
			prev = i;
		}
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			zeroes++;
		else if (zeroes)
			line[i + zeroes] = line[i];
	}
	for (i = zeroes - 1; i >= 0; i--)
		line[i] = 0;
}
