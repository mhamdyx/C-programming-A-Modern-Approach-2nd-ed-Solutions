/*
 * queueADT2.c
 *
 *  Created on: May 12, 2020
 *      Author: Mahmoud Hamdy
 */

// Queue ADT (Dynamic array representation)

#include <stdio.h>
#include <stdlib.h>
#include "queueADT2.h"

struct queue_type
{
	Item *buffer; // Queue dynamic array
	int write; // Position of the first empty slot in the array (rear)
	int read; // Position of the next item to be removed (front)
	int size; // Number of items in the queue
	int max_size; // Maximum number of items that can be in the queue
};

static void terminate(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int size)
{
	Queue q = malloc(sizeof(struct queue_type));

	if (q == NULL)
		terminate("Error in create: queue could not be created.");

	q->buffer = malloc(size * sizeof(Item));

	if (q->buffer == NULL)
	{
		free(q);
		terminate("Error in create: queue could not be created.");
	}

	make_empty(q);
	q->max_size = size;

	return q;
}

void destroy(Queue q)
{
	free(q->buffer);
	free(q);
}

void make_empty(Queue q)
{
	q->read = 0;
	q->write = 0;
	q->size = 0;
}

// Inserting item at the end of the queue
void enqueue(Queue q, Item i)
{
	if (is_full(q))
		terminate("Error in enqueue: queue is full.");

	q->buffer[q->write++] = i;
	q->size++;

	if (q->write == q->max_size)
		q->write = 0; // Keep write (rear) within bounds
}

// Removing an item from the beginning of the queue
Item dequeue(Queue q)
{
	Item i;

	if (is_empty(q))
		terminate("Error in dequeue: queue is empty.");

	i = q->buffer[q->read++];
	q->size--;

	if (q->read == q->max_size)
		q->read = 0; // Keep read (front) within bounds

	return i;
}

// Returning the first item in the queue (without changing the queue)
Item front(Queue q)
{
	if (is_empty(q))
		terminate("Error in front: queue is empty.");

	return q->buffer[q->read];
}

// Returning the last item in the queue (without changing the queue)
Item rear(Queue q)
{
	if (is_empty(q))
		terminate("Error in rear: queue is empty.");

	return (q->write ? q->buffer[q->write - 1] : q->buffer[q->max_size - 1]);
}

bool is_empty(Queue q)
{
	return q->size == 0;
}

bool is_full(Queue q)
{
	return q->size == q->max_size;
}
