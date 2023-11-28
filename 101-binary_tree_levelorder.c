#include "binary_trees.h"

#include <stdio.h>
binary_tree_t **create_queue(int *front, int *rear);
void enqueue_node(binary_tree_t **queue, binary_tree_t *node, int *rear);
binary_tree_t *dequeue_node(binary_tree_t **queue, int *front);

/**
 * binary_tree_levelorder - traverse a bs using level order
 * @tree: node
 * @func: function pointer
 *
 * Return: None
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *curr = NULL, **queue = NULL;
	int front, rear;
		
	if (tree == NULL || func == NULL)
		return;

	queue = create_queue(&front, &rear);
	curr = (binary_tree_t *) tree;

	while (curr != NULL)
	{
		func(curr->n);
		if (curr->left != NULL)
			enqueue_node(queue, curr->left, &rear);
		if (curr->right !=  NULL)
			enqueue_node(queue, curr->right, &rear);

		curr = dequeue_node(queue, &front);
	}

	free(queue);
}


binary_tree_t **create_queue(int *front, int *rear)
{
	binary_tree_t **queue = NULL;

	queue = (binary_tree_t **) calloc(100, sizeof(binary_tree_t *));
	if (queue == NULL)
		return NULL;

	*front = 0, *rear = 0;
	return (queue);
}

void enqueue_node(binary_tree_t **queue, binary_tree_t *node, int *rear)
{
	queue[*rear] = node;
	(*rear)++;
}

binary_tree_t *dequeue_node(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}
