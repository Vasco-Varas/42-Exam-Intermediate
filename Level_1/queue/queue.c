//
// Created by Vasco Varas on 29-10-19.
//

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};
struct s_queue {
	struct s_node *first;
	struct s_node *last;
};


// - init() : Initialize the queue.
// The first and last pointers are set to NULL.
struct s_queue *init(void)
{
	// allocate memory and prepare variables
	struct s_queue  *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;

	return (queue);
}

// - enqueue(queue, item) : Add an item to the end of the queue.
void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new_node = malloc(sizeof(struct s_node));

	// Create node
	new_node->next = NULL;
	new_node->content = content;

	// Set node to queue's first node if it's not already defined
	if (!queue->first) queue->first = new_node;

	// If there's a last node, set it's next value
	if (queue->last) queue->last->next = new_node;

	// This is the new last node
	queue->last = new_node;
}


// - dequeue(queue) : Remove the first item from the queue and return it.
// If the queue is empty, the function returns NULL.
void *dequeue(struct s_queue *queue)
{
	void            *value = NULL;
	struct s_node   *old_first = queue->first;

	if (queue->first)
	{
		// Save the value of the node
		value = old_first->content;
		// Set the new first node to the old first node
		queue->first = old_first->next;
		// free the old first node
		free(old_first);
	}

	// Take care of eliminating the last node if it was the only one
	queue->last = (queue->first ? queue->last : NULL);
	return (value);
}


// - peek(queue) : Return the first item of the queue.
// If the queue is empty, the function returns NULL.
void *peek(struct s_queue *queue)
{
	// return value only if first exists
	return (queue->first ? queue->first->content : NULL);
}


// - isEmpty(queue) : Return 1 if the queue is empty, 0 otherwise.
int isEmpty(struct s_queue *queue)
{
	// not much to explain...
	return (queue->first ? 0 : 1);
}