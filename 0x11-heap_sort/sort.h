#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_array(const int *array, size_t size);

void swap(int *array1, int *array2);
void heap(int *array, int size, int mp, int length);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
