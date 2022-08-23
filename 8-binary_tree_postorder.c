#include "binary_trees.h"

void recursive_postorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_postorder - main func traverse binary tree in post-order
 * @tree: pointer to root node of the tree
 * @func: pointer to function called for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	recursive_postorder(tree, func);
}

/**
 * recursive_postorder - recursive func traverse tree in post order
 * @tree: pointer to node
 *@func: function to run on node
 */

void recursive_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree->left)
		recursive_postorder(tree->left, func);
	if (tree->right)
		recursive_postorder(tree->right, func);
	func(tree->n);
}
