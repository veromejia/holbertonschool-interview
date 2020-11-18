#include "search.h"

/**
 * print_checked - print the index checked in the list 
 * @low: list of values
 * @high: value to locate
 *
 */

void print_checked(int idx, int item)
{
	printf("Value checked at index [%i] = [%i]\n", (idx), (item));
}

/**
 * print_found - print  if the value was found 
 * @low: list of values
 * @high: value to locate
 *
 */
void print_found(int low, int high)
{
	printf("Value found between indexes [%i] and [%i]\n", (low), (high));
}

/**
 * linear_skip - search for a value in a sorted list of integers
 * @list: list of values
 * @value: value to locate
 *
 * Return: If value is not present in the list, return NULL.
 * Otherwise, returh a pointer to the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *last = list;

	if (list)
	{
		list = express_line(list, last, value); 
        return list;
	}
	return (NULL);
}

/**
 * express_line - search for a value in a sorted list of integers in the upper line (express line)
 * @list: list of values
 * @last: right side of the express line
 * @value: value to locate
 *
 * Return: If value is not present in the list, return NULL.
 * Otherwise, returh a pointer to the first node where value is located.
 */
skiplist_t *express_line(skiplist_t *list, skiplist_t *last, int value)
{   
    while( last->express && value > last->n )
    {
        list = last;
        last = last->express;
        print_checked(last->index, last->n);
    }
    if (value > last->n)
	{
			list = last;
			while (last->next)
				last = last->next;
	}
    print_found(list->index, last->index);
    last = last->next;
    list = full_line(list, last, value);
    return (list);

}

/**
 * full_line - search for a value in a sorted list of integers in the lower line (full line)
 * @list: list of values
 * @last: right side of the express line
 * @value: value to locate
 *
 * Return: If value is not present in the list, return NULL.
 * Otherwise, returh a pointer to the first node where value is located.
 */
skiplist_t *full_line(skiplist_t *list, skiplist_t *last, int value)
{
    while (list != last)
	{
	    print_checked(list->index, list->n);
	    if (list->n == value)
		    return (list);
		list = list->next;
	}
    return (NULL);
}

