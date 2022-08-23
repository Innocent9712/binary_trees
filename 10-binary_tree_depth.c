#include "binary_trees.h"

/**
 * binary_tree_depth - measure depth of a node
 * @tree: pointer to node being measured
 *
 * Return: depth of node tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (depth);

	while (tree->parent)
	{
		depth += 1;
		tree = tree->parent;
	}
	return (depth);
}
