#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *ancestor;

    if (!first || !second)
        return (NULL);

    ancestor = first;
    while (ancestor)
    {
        if (binary_tree_is_ancestor(ancestor, second))
            return ((binary_tree_t *)ancestor);
        ancestor = ancestor->parent;
    }

    return (NULL);
}

/**
 * binary_tree_is_ancestor - Check if a node is an ancestor of another
 * @ancestor: The potential ancestor node
 * @node: The potential descendant node
 * Return: 1 if ancestor is a true ancestor of node, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node)
{
    if (!node)
        return (0);

    while (node)
    {
        if (node == ancestor)
            return (1);
        node = node->parent;
    }

    return (0);
}

