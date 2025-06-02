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

#define PUBLIC
#define PRIVATE static

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC void enqueue(Queue *q, int i)
{
	if (q->qsize == QUEUE_SIZE)
		terminate("Error in enqueue: queue is full.");

	q->buffer[q->rear++] = i;
	q->rear %= QUEUE_SIZE; // Keep rear within bounds
	q->qsize++;
}

PUBLIC int dequeue(Queue *q)
{
	int i;

	if (is_empty(q))
		terminate("Error in dequeue: queue is empty.");

	i = q->buffer[q->front++];
	q->front %= QUEUE_SIZE; // Keep front within bounds
	q->qsize--;

	return i;
}

PUBLIC int front_item(const Queue *q)
{
	if (is_empty(q))
		terminate("Error in front_item: queue is empty.");

	return q->buffer[q->front];
}

PUBLIC int rear_item(const Queue *q)
{
	if (is_empty(q))
		terminate("Error in rear_item: queue is empty.");

	return (q->rear ? q->buffer[q->rear - 1] : q->buffer[QUEUE_SIZE - 1]);
}

PUBLIC bool is_empty(const Queue *q)
{
	return q->qsize == 0; // or q->front == q->rear;
}
