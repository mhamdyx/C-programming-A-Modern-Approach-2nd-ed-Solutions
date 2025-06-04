/*
 * queueADT.c
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

// Queue ADT (Fixed-length array representation)

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type
{
	Item buffer[QUEUE_SIZE]; // Queue array
	int write; // Position of the first empty slot in the array (rear)
	int read; // Position of the next item to be removed (front)
	int size; // Number of items in the queue
};

static void terminate(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));

	if (q == NULL)
		terminate("Error in create: queue could not be created.");

	make_empty(q);

	return q;
}

void destroy(Queue q)
{
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

	if(q->write == QUEUE_SIZE)
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

	if (q->read == QUEUE_SIZE)
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

	return (q->write ? q->buffer[q->write - 1] : q->buffer[QUEUE_SIZE - 1]);
}

bool is_empty(Queue q)
{
	return q->size == 0;
}

bool is_full(Queue q)
{
	return q->size == QUEUE_SIZE;
}
