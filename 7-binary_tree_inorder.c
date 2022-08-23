#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	recursive_inorder(tree, func);
}

/**
 * recursive_inorder - rucursively print values
 * @tree: pointer to node
 * @func: pointer to print function
 * Return: Nothin
 */
void recursive_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree->left)
	{
		recursive_inorder(tree->left, func);
	}
	func(tree->n);
	if (tree->right)
	{
		recursive_inorder(tree->right, func);
	}
}
