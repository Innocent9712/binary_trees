#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int count = 1;

	if (!tree)
		return (0);
	if (!tree->left || !tree->right)
		return (0);
	if (!count)
	{
		count = binary_tree_is_full(tree->right);
		count = binary_tree_is_full(tree->left);
	}
	return (count);
}
