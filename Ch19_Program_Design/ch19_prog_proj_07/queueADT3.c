/*
 * queueADT3.c
 *
 *  Created on: May 12, 2020
 *      Author: Mahmoud Hamdy
 */

// Queue ADT (Linked-list representation)

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node
{
	Item data;
	struct node *next;
};

struct queue_type
{
	struct node *front_node;
	struct node *rear_node;
};

static void terminate(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));

	if(q == NULL)
		terminate("Error in create: queue could not be created.");

	q->front_node = NULL;
	q->rear_node = NULL;

	return q;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q);
}

void make_empty(Queue q)
{
	while(!is_empty(q))
		dequeue(q);
}

// Inserting item at the end of the queue
void enqueue(Queue q, Item i)
{
	struct node *new_rear = malloc(sizeof(struct node));

	if(new_rear == NULL)
		terminate("Error in enqueue: queue is full.");

	new_rear->data = i;
	new_rear->next = NULL;

	if(is_empty(q))
	{
		q->front_node = q->rear_node = new_rear;
		return;
	}

	q->rear_node->next = new_rear;
	q->rear_node = new_rear;
}

// Removing an item from the beginning of the queue
Item dequeue(Queue q)
{
	struct node *old_front;
	Item i;

	if(is_empty(q))
		terminate("Error in dequeue: queue is empty.");

	old_front = q->front_node;
	i = old_front->data;

	// In case only one node exists in linked-list
	if(q->front_node == q->rear_node)
		q->front_node = q->rear_node = NULL;
	else
		q->front_node = old_front->next;

	free(old_front);

	return i;
}

// Returning the first item in the queue (without changing the queue)
Item front(Queue q)
{
	if(is_empty(q))
		terminate("Error in front: queue is empty.");

	return q->front_node->data;
}

// Returning the last item in the queue (without changing the queue)
Item rear(Queue q)
{
	if(is_empty(q))
		terminate("Error in rear: queue is empty.");

	return q->rear_node->data;
}

bool is_empty(Queue q)
{
	return q->front_node == NULL;
}

bool is_full(Queue q)
{
	return false;
}
