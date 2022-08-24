#include "binary_trees.h"

int findADepth(const binary_tree_t *node);
int isPerfectRec(const binary_tree_t *root, int d, int level);

/**
 * binary_tree_is_perfect - checks if tree is a perfect tree
 * @tree: tree to check
 *
 * Return: 1 (perfect) 0 (not perfect)
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (!tree)
		return (0);

	depth = findADepth(tree);
	return (isPerfectRec(tree, depth, 0));
}


/**
 * findADepth - Returns depth of leftmost leaf.
 * @node: root node of tree
 *
 * Return: depth
 */

int findADepth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}

/**
 * isPerfectRec - recursively checks if a tree is perfect
 * @root: root node of tree
 * @d: depth of the tree
 * @level: current level of node
 *
 * Return: 1 (if perfect) 0 (if not)
 */

int isPerfectRec(const binary_tree_t *root, int d, int level)
{
	if (root == NULL)
		return (0);

	/**
	 * If leaf node, then its depth must be same as
	 * depth of all other leaves.
	 */
	if (root->left == NULL && root->right == NULL)
		return (d == level + 1);

	/*If internal node and one child is empty*/
	if (root->left == NULL || root->right == NULL)
		return (0);

	/*Left and right subtrees must be perfect.*/
	return (isPerfectRec(root->left, d, level + 1) &&
		isPerfectRec(root->right, d, level + 1));
}
