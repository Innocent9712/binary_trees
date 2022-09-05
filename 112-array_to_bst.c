#include "binary_trees.h"
/**
 * array_to_bst - convert an array into a BST
 * @array: array to convert
 * @size: size of the array
 *
 * Return: root node of BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t count = 0;
	bst_t *root = binary_tree_node(NULL, array[count]);

	if (!array || !size || !array[size - 1] || !root)
		return (NULL);

	while (count < size)
	{
		bst_insert(&root, array[count]);
		count++;
	}

	return (root);
}
