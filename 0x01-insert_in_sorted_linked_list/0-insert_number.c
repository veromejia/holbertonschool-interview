#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a node in a sorted position
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: the address of new node or null if fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *prev;
	listint_t *current = *head;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (current->next != NULL)
	{
		if (current->n >= new->n)
		{
			new->next = current;
			if (*head == current)
				*head = new;
			else
				prev->next = new;
			return (new);
		}
		prev = current;
		current = current->next;
	}

	if (current->n > new->n)
	{
		new->next = current;
		prev->next = new;
	}
	else
		current->next = new;
	return (new);
}
