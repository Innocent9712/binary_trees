#include "binary_trees.h"

bst_t *traverse_and_insert(bst_t *tree, bst_t *node);

/**
 * bst_insert - main function to insert into a BST
 * @tree: BST to insert in
 * @value: value to insert in tree
 * Return: node inserted in tree
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = binary_tree_node(NULL, value);

	if (!tree || !node)
		return (NULL);

	if (!*tree)
	{
		*tree = node;
		return (node);
	}
	else
		return (traverse_and_insert(*tree, node));
}

/**
 * traverse_and_insert - go through the BST and insert a node
 * @tree:  tree to traverse
 * @node: node to insert
 * Return: node or NULL
 */

bst_t *traverse_and_insert(bst_t *tree, bst_t *node)
{
	if (tree->n == node->n)
		return (NULL);

	if (!tree->left && tree->n > node->n)
	{
		node->parent = tree;
		tree->left = node;
		return (node);
	}

	if (!tree->right && tree->n < node->n)
	{
		node->parent = tree;
		tree->right = node;
		return (node);
	}

	if (tree->n > node->n)
	{
		return (traverse_and_insert(tree->left, node));
	}
	else
		return (traverse_and_insert(tree->right, node));
}
