#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    const binary_tree_t **queue;
    int front = 0, rear = 0;
    int size = 0, i;

    if (tree == NULL || func == NULL)
        return;

    queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
    if (queue == NULL)
        return;

    queue[rear++] = tree;

    while (front < rear)
    {
        size = rear - front;

        for (i = 0; i < size; i++)
        {
            func(queue[front]->n);

            if (queue[front]->left)
                queue[rear++] = queue[front]->left;

            if (queue[front]->right)
                queue[rear++] = queue[front]->right;

            front++;
        }
    }

    free(queue);
}
