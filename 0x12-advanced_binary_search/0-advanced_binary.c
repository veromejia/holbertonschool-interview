#include "search_algos.h"
/**
 * binary_search - recursive binary search algorithm
 * @array: pointer to array to search
 * @value: the value to search for
 * @l: left index
 * @r: right index
 * Return: The index where the value was located for the first
 * time, or -1
 */
int binary_search(int *array, int l, int r, int value)
{
	int i, mid;

	mid = l + (r - l) / 2;
	if (l == r)
	{
		if (value < array[l] || value > array[r])
		{
			printf("Searching in array: %d\n", array[mid]);
			return (-1);
		}
		return (l);
	}
	printf("Searching in array:");
	for (i = l; i <= r; i++)
	{
		if (i != r)
			printf(" %d,", array[i]);
		else
			printf(" %d\n", array[i]);
	}

	if (array[mid] < value)
		return (binary_search(array, mid + 1, r, value));
	else
		return (binary_search(array, l, mid, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value:  is the value to search for
 * Return: the index where value is located
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
