#include "binary_trees.h"

void traverse(const binary_tree_t *tree, size_t *count);

/**
 * binary_tree_size - get the size of a binary tree
 * @tree: tree to check
 *
 * Return: size of tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (count);
	traverse(tree, &count);
	return (count);
}


/**
 * traverse - goes through a binary tree using in-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @count: current count of tree size during traversal
 */

void traverse(const binary_tree_t *tree, size_t *count)
{
	if (tree->left)
	{
		traverse(tree->left, count);
	}
	*count += 1;
	if (tree->right)
	{
		traverse(tree->right, count);
	}
}
