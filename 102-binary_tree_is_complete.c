#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag = 0;
	queue_t *queue = NULL;

	if (!tree)
		return (0);

	queue = push_to_queue(queue, (binary_tree_t *)tree);

	while (queue)
	{
		tree = pop_from_queue(&queue);
		if (tree->left)
		{
			if (flag)
				return (0);
			queue = push_to_queue(queue, tree->left);
		}
		else
			flag = 1;

		if (tree->right)
		{
			if (flag)
				return (0);
			queue = push_to_queue(queue, tree->right);
		}
		else
			flag = 1;
	}
	return (1);
}
