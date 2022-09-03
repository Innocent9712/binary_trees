#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate the tree once to the left
 * @tree: tree to rotate
 *
 * Return: new tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_tree_right = NULL;

	if (!tree)
		return (NULL);

	if (tree->right)
	{
		new_root = tree->right;
	}

	if (new_root->left)
	{
		new_tree_right = new_root->left;
		new_tree_right->parent = tree;
	}

	tree->parent = new_root;
	new_root->left = tree;
	tree->right = new_tree_right;
	new_root->parent = NULL;

	return (new_root);
}
