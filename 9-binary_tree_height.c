#include "binary_trees.h"

/**
 * binary_tree_height -  measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: tree is NULL, your function must return 0
 *
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count_left = 0, count_right = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	/* count all nodes in left */
	count_left =  1 + binary_tree_height(tree->left);
	/*count all nodes in right*/
	count_right =  1 + binary_tree_height(tree->right);
	/*since height is number of edges*/
	if (count_right > count_left)
		return (count_right);
	return (count_left);
}
