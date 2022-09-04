#include "binary_trees.h"

int check_bst(const binary_tree_t *tree, const binary_tree_t *l,
	      const binary_tree_t *r);

/**
 * binary_tree_is_bst - check if a binary tree is a BST *
 * @tree: tree to check
 *
 * Return: 1 (if true) 0 (if false)
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bst(tree, NULL, NULL));
}

int check_bst(const binary_tree_t *tree, const binary_tree_t *l,
	      const binary_tree_t *r)
{
	if (!tree)
		return (1);

	if (l && tree->n < l->n)
		return (0);

	if (r && tree->n > r->n)
		return (0);

	return (check_bst(tree->left, l, tree) &&
		check_bst(tree->right, tree, r));
}
