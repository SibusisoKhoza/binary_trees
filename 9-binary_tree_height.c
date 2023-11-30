#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    /* Get the height of the left and right subtrees */
    if (tree->left)
        left_height = 1 + binary_tree_height(tree->left);
    if (tree->right)
        right_height = 1 + binary_tree_height(tree->right);

    /* Return the maximum of both heights */
    return (left_height > right_height ? left_height : right_height);
}
