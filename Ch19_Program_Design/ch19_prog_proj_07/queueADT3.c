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
	struct node *front;
	struct node *rear;
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

	q->front = NULL;
	q->rear = NULL;

	return q;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q);
}

void make_empty(Queue q)
{
	while (!is_empty(q))
		dequeue(q);
}

// Inserting item at the end of the queue
void enqueue(Queue q, Item i)
{
	struct node *new_rear = malloc(sizeof(struct node));

	if(new_rear == NULL)
		terminate("Error in enqueue: queue is full.");

	if (q->rear == NULL) // In case queue was empty
		q->front = new_rear;
	else
		q->rear->next = new_rear;

	new_rear->data = i;
	new_rear->next = NULL;
	q->rear = new_rear;
}

Item dequeue(Queue q)
{
	struct node *old_front;
	Item i;

	if (is_empty(q))
		terminate("Error in dequeue: queue is empty.");

	old_front = q->front;
	i = old_front->data;
	q->front = q->front->next;
	free(old_front);

	// If the queue became empty, rear would be NULL
	if (is_empty(q))
		q->rear = NULL;

	return i;
}

// Returning the first item in the queue (without changing the queue)
Item front(Queue q)
{
	if (is_empty(q))
		terminate("Error in front: queue is empty.");

	return q->front->data;
}

// Returning the last item in the queue (without changing the queue)
Item rear(Queue q)
{
	if (is_empty(q))
		terminate("Error in rear: queue is empty.");

	return q->rear->data;
}

bool is_empty(Queue q)
{
	return q->front == NULL;
}

bool is_full(Queue q)
{
	return false;
}
