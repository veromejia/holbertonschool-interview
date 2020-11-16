#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - check if a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long temp;
	unsigned long reverse = 0;

	temp = n;

	while (temp != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + (temp % 10);
		temp = temp / 10;
	}
	if (n == reverse)
		return (1);
	else
		return (0);
}
