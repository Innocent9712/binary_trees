#include "binary_trees.h"
#include <stdio.h>

binary_tree_t *recursive_check_up(const binary_tree_t *fluid,
				 const binary_tree_t *stat);
int recursive_check_down(const binary_tree_t *fluid,
				   const binary_tree_t *stat);
/**
 * binary_trees_ancestor - find common ancestor of 2 nodes
 * @first: first node
 * @second: second node
 *
 * Return: pointer to common ancestor or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL ||
	    first->parent == NULL ||
	    second == NULL ||
	    second->parent == NULL)
		return (NULL);
	if (recursive_check_down(first, second))
		return ((binary_tree_t *)first);
	return (recursive_check_up(first,second));
}

binary_tree_t *recursive_check_up(const binary_tree_t *fluid,
				 const binary_tree_t *stat)
{
	int result;

	if (fluid->parent == NULL)
		return (NULL);

	if (fluid->parent == stat)
		return ((binary_tree_t *)stat);

	if (fluid->parent->left == fluid)
		result = recursive_check_down(fluid->parent->right, stat);
	else
		result = recursive_check_down(fluid->parent->left, stat);
	if (result == 0)
		return (recursive_check_up(fluid->parent, stat));
	return (fluid->parent);
}


int recursive_check_down(const binary_tree_t *fluid,
				   const binary_tree_t *stat)
{
	printf("currently at: %d and checking for %d\n", fluid->n, stat->n);
	if (fluid == stat)
		return (1);

	if (fluid->left)
		recursive_check_down(fluid->left, stat);
	if (fluid->right)
		recursive_check_down(fluid->right, stat);
	return (0);
}
