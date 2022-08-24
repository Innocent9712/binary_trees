#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: If tree is NULL, the function must return 0
 *
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (count);
	recursive_node_count(tree, &count);
	return (count);
}

/**
 * recursive_node_count - counts the nodes with at least 1
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * @count: number of nodes
 * Return: Nothing
 */
void recursive_node_count(const binary_tree_t *tree, size_t *count)
{
	if (tree->left || tree->right)
		(*count)++;
	if (tree->left)
		recursive_node_count(tree->left, count);
	if (tree->right)
		recursive_node_count(tree->right, count);
}
