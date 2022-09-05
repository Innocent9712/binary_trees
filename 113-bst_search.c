#include "binary_trees.h"

bst_t *search(const bst_t *tree, int value);

/**
 * @bst_search - search for a value in a BST
 * @tree: tree to search in
 * @value: value to search for
 * 
 * Return: the node containing the value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
    if (!tree || !value)
        return (NULL);

    return (search(tree, value));
}

/**
 * @bst_search - recursively search for a value in node in  BST
 * @tree: current node to search in
 * @value: value to search for
 * 
 * Return: the node containing the value
 */

bst_t *search(const bst_t *tree, int value)
{
    if (!tree)
        return(NULL);
    
    if (tree->n == value)
        return ((bst_t *)tree);

    if (tree->n > value)
        return (search(tree->left, value));
    return (search(tree->right, value));
}