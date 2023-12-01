#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *tmp1, *tmp2;

	if (first == NULL || second == NULL)
		return (NULL);

	tmp1 = first;
	while (tmp1)
	{
		tmp2 = second;
		while (tmp2)
		{
			if (tmp1 == tmp2)
				return ((binary_tree_t *)tmp1);
			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}

