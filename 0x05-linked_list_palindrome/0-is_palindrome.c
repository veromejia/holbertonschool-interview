#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if it is a palindrome or 0 if it is not a palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *aux = NULL;
	listint_t *tmp = NULL;
	int isPal = 1;

	if (*head == NULL)
		return (isPal);

	aux = *head;
	if (aux->next == NULL)
		return (isPal);

	tmp = cut_list(aux);
	reverse_listint(&tmp);

	while (tmp != NULL)
	{
		if (tmp->n != aux->n)
		{
			isPal = 0;
			break;
		}
		tmp = tmp->next;
		aux = aux->next;
	}

	free_listint(tmp);
	free_listint(aux);
	return (isPal);
}

/**
 * cut_list - function that split the list by the middle
 * @q: first element of tha list
 * Return: return the second half of the original list
 */
listint_t *cut_list(listint_t *q)
{
	listint_t *p = q;
	listint_t *start_second = NULL;

	while (1 == 1)
	{
		if (p->next != NULL)
		{
			if (p->next->next != NULL)
			{
				p = p->next->next;
				if (p->next == NULL)
				{
					start_second = q->next->next;
					break;
				}
			}
			else
			{
				p = p->next;
				start_second = q->next;
				break;
			}
		}
		else
		{
			start_second = q->next->next;
			break;
		}
		q = q->next;
	}
	q->next = NULL;
	return (start_second);
}

/**
 * reverse_listint - function that reversed a list
 * @head: first element of tha list
 * Return: return a new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *prev = NULL;

	while (*head != NULL)
	{
		*head = temp->next;
		temp->next = prev;
		prev = temp;
		temp = *head;
	}
	*head = prev;
	return (*head);
}
