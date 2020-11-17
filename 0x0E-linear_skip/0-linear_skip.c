#include "search.h"

/**
 * linear_skip - Search for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tail;
    skiplist_t *fast_list = NULL;

	if (!list)
		return (NULL);

	tail = print_values(list, value);

	if (list->express)
		tail = tail->express;
	else
		while (tail->next)
			tail = tail->next;
	printf("Value found between indexes [%d] and [%d]\n",
		    (int) list->index, (int) tail->index);

	fast_list = skipping_values(list, tail, value);
    return (fast_list);
}

skiplist_t *print_values(skiplist_t *list, int value)
{
    while (list && list->express)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int) list->express->index, list->express->n);
		if (value > list->express->n)
			list = list->express;
		else
			break;
	}

    return list;
}

skiplist_t *skipping_values(skiplist_t *head, skiplist_t *tail, int value)
{
    while (head->index <= tail->index)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int) head->index, head->n);
		if (value == head->n)
			return (head);
		if (!head->next)
			break;
		head = head->next;
	}
	return (NULL);
}
