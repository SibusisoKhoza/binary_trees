#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue to store nodes */
	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	size_t front = 0, rear = 0;
	const binary_tree_t *current;

	if (queue == NULL)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		/* Enqueue left child */
		if (current->left != NULL)
			queue[rear++] = current->left;

		/* Enqueue right child */
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
