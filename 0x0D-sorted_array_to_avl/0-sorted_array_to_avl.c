#include "binary_trees.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * new_node - creates an avl_t node
 * @value: value of the node
 * @parent: parent of the new node
 * Return: pointer to the newly created node
 */
avl_t *new_node(int value, avl_t *parent)
{
	avl_t *new = malloc(sizeof(avl_t));

	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}

/**
 * new_tree - Recursive function that constructs
 * a balanced tree based on a sorted array
 * @parent: parent node
 * @array: array of ints
 * @left: left side
 * @right: right side
 * Return: pointer to the root node of the created tree
 */
avl_t *new_tree(avl_t *parent, int *array, int left, int right)
{
	avl_t *new;
	int m = (right - left) / 2 + left;

	if (left > right)
		return (NULL);
	new = new_node(array[m], parent);
	if (!new)
		return (NULL);
	new->left = new_tree(new, array, left, m - 1);
	new->right = new_tree(new, array, m + 1, right);

	return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created AVL tree or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int left = 0;
	int right = size - 1;

	root = new_tree(root, array, left, right);
	if (!root)
		return (NULL);
	return (root);
}
