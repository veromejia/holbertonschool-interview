#include "sort.h"
/**
* swap - swaps two positions
* @a: first array
* @b: second array
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
* heap - makes array into a heap
* @array: ptr to int array
* @size: size of array
* @mp: max point
* @length: size of the array in heap_sort fn
*/
void heap(int *array, int size, int mp, int length)
{
	int max = mp;
	int left = (2 * mp) + 1;
	int right = (2 * mp) + 2;

	if (left < size && array[max] < array[left])
		max = left;

	if (right < size && array[max] < array[right])
		max = right;

	if (max != mp)
	{
		swap(&array[mp], &array[max]);
		print_array(array, length);
		heap(array, size, max, length);
	}
}

/**
* heap_sort - sort and array (heap method)
* @array: array to sort
* @size: size of array
*/
void heap_sort(int *array, size_t size)
{
	int idx;

	if (!size || !array)
		return;
	for (idx = (size / 2) - 1; idx >= 0; idx--)
		heap(array, size, idx, size);

	for (idx = size - 1; idx > 0; idx--)
	{
		if (array[0] >= array[idx])
		{
			swap(&array[0], &array[idx]);
			print_array(array, size);
		}
		heap(array, idx, 0, size);
	}
}
