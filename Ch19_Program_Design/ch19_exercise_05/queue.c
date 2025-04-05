/*
 * queue.c
 *
 *  Created on: May 10, 2020
 *      Author: Mahmoud Hamdy
 */

// Queue type (Fixed-length array representation)

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}


PUBLIC void enqueue(Queue *q, int i)
{
	if(q->size == QUEUE_SIZE)
		terminate("Error in enqueue: queue is full.");

	q->buffer[q->rear++] = i;
	q->size++;

	if(q->rear == QUEUE_SIZE)
		q->rear = 0;
}

PUBLIC int dequeue(Queue *q)
{
	if(is_empty(q))
		terminate("Error in dequeue: queue is empty.");

	int i = q->buffer[q->front++];
	q->size--;

	if(q->front == QUEUE_SIZE)
		q->front = 0;

	return i;
}

PUBLIC int front_item(Queue *q)
{
	if(is_empty(q))
		terminate("Error in front_item: queue is empty.");

	return q->buffer[q->front];
}

PUBLIC int rear_item(Queue *q)
{
	if(is_empty(q))
		terminate("Error in rear_item: queue is empty.");

	if(q->rear == 0)
		return q->buffer[QUEUE_SIZE - 1];

	return q->buffer[q->rear - 1];
}

PUBLIC bool is_empty(Queue *q)
{
	return q->size == 0;
}
