#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - create a new node
 * @parent: parent of the node to be created
 * @value:value to be placed in the new node
 *
 * Return: pointer to new node or NULL
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
