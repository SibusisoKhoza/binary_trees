#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: Number of nodes with at least 1 child, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return (0);

    /* Recursively count nodes with at least 1 child */
    return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
