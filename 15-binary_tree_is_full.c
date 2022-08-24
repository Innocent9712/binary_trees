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
	check_full(tree, &count);
	return (count);
}
/**
 * check_full - checks if all nodes have two nodes
 * @count: pointer to number of nodes
 * @tree: pointer to root
 * Return: Nothing
 */
void check_full(const binary_tree_t *tree, int *count)
{
	if (!tree)
		return;
	if (tree->left && tree->right)
	{
		if (!tree->left || !tree->right)
		{
			(*count) = 1;
			return;
		}
	}
	else if (!(!tree->right && !tree->left))
	{
		(*count) = 0;
	}
	check_full(tree->left, count);
	check_full(tree->right, count);
}
