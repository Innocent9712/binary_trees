#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate the tree once to the right
 * @tree: tree to rotate
 *
 * Return: new tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_tree_left = NULL;

	if (!tree)
		return (NULL);

	if (tree->left)
	{
		new_root = tree->left;
	}

	if (new_root->right)
	{
		new_tree_left = new_root->right;
		new_tree_left->parent = tree;
	}

	tree->parent = new_root;
	new_root->right = tree;
	tree->left = new_tree_left;
	new_root->parent = NULL;

	return (new_root);
}
