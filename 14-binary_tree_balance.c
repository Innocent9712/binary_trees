#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0 else balnce factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int c_l = 0, c_r = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	c_l = (tree->left) ? 1 + count_edge(tree->left) : count_edge(tree->left);
	c_r = (tree->right) ? 1 + count_edge(tree->right) : count_edge(tree->right);
	return (c_l - c_r);
}

/**
 * count_edge - count the edges
 * @tree: pointer to a node
 * Return: number of edges
 */

int count_edge(const binary_tree_t *tree)
{
	int c_l = 0, c_r = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	c_l = 1 + count_edge(tree->left);
	c_r = 1 + count_edge(tree->right);
	if (c_r > c_l)
		return (c_r);
	return (c_l);
}
