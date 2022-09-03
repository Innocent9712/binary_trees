#include "binary_trees.h"

unsigned int count_nodes(const binary_tree_t *node);
int is_complete(const binary_tree_t *tree, unsigned int index,
		unsigned int number_of_nodes);

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: tree to check
 *
 * Return: result of is_complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	unsigned int node_count = count_nodes(tree);
	unsigned int index = 0;

	return (is_complete(tree, index, node_count));
}

/**
 * count_nodes - gets total number of nodes in the tree
 * @node: root node
 *
 * Return: number of nodes
 */

unsigned int count_nodes(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (1 + count_nodes(node->left) + count_nodes(node->right));
}

/**
 * is_complete - recursive function to check if tree is complete
 * @tree: tree to check
 * @index: current index of node
 * @number_of_nodes: total nodes in the tree
 *
 * Return: 1 (if complete) 0 (if not)
 */
int is_complete(const binary_tree_t *tree, unsigned int index,
		unsigned int number_of_nodes)
{
	if (!tree)
		return (1);

	if (index >= number_of_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, number_of_nodes)
		&& is_complete(tree->right, 2 * index + 2, number_of_nodes));
}
