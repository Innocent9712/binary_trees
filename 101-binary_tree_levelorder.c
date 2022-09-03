#include "binary_trees.h"
void recursive_levelorder(const binary_tree_t *tree, void(*func)(int));
/**
 * binary_tree_levelorder - traverse a binary tree level by level
 * @tree: tree to traverse
 * @func: function to print value at each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	recursive_levelorder(tree, func);
}

/**
 * recursive_levelorder - main recursive function
 * @tree: binary tree to traverse
 * @func: function to print value at each node
 */

void recursive_levelorder(const binary_tree_t *tree, void(*func)(int))
{
	if (tree->left)
	{
		func(tree->left->n);
	}
	if (tree->right)
	{
		func(tree->right->n);
	}
	if (tree->left)
		recursive_levelorder(tree->left, func);
	if (tree->right)
		recursive_levelorder(tree->right, func);
}
