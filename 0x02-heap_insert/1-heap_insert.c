#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new_node = find_insertion(*root, value, 0, binary_tree_size(*root) + 1);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}


/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_size, r_size;

	if (tree == NULL)
		return (0);

	l_size = binary_tree_size(tree->left);
	r_size = binary_tree_size(tree->right);
	return (1 + l_size + r_size);
}

/**
 * find_insertion - find where the node have to be inserted
 * @root: double pointer to the root node of the Heap
 * @value: value to be inserted
 * @i: index of the node
 * @size: position where the node will be inserted
 * Return: new pointer inserted
 */
heap_t *find_insertion(binary_tree_t *root, int value, int i, int size)
{
	heap_t *lnode;
	heap_t *rnode;

	if (!root)
		return (0);
	if (i + 1 == size / 2)
	{
		if (size % 2 == 1)
		{
			root->right = binary_tree_node(root, value);
			return (root->right);
		}
		else
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
	}
	lnode = find_insertion(root->left, value, 2 * i + 1, size);
	if (lnode)
		return (lnode);
	rnode = find_insertion(root->right, value, 2 * i + 2, size);
	return (rnode);
}
