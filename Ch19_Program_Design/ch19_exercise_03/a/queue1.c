/*
 * queue1.c
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC
#define PRIVATE static
#define QUEUE_SIZE 100

PRIVATE int buffer[QUEUE_SIZE]; // Queue array
PRIVATE int rear = 0; // Position of the first empty slot in the array
PRIVATE int front = 0; // Position of the next item to be removed
PRIVATE int qsize = 0; // Number of items in the queue

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC void enqueue(int i)
{
	if (qsize == QUEUE_SIZE)
		terminate("Error in enqueue: queue is full.");

	buffer[rear++] = i;
	rear %= QUEUE_SIZE; // Keep rear within bounds
	qsize++;
}

PUBLIC int dequeue(void)
{
	int i;

	if (is_empty())
		terminate("Error in dequeue: queue is empty.");

	i = buffer[front++];
	front %= QUEUE_SIZE; // Keep front within bounds
	qsize--;

	return i;
}

PUBLIC int front_item(void)
{
	if (is_empty())
		terminate("Error in front_item: queue is empty.");

	return buffer[front];
}

PUBLIC int rear_item(void)
{
	if (is_empty())
		terminate("Error in rear_item: queue is empty.");

	return (rear ? buffer[rear - 1] : buffer[QUEUE_SIZE - 1]);
}

PUBLIC bool is_empty(void)
{
	return qsize == 0; // or return front == rear;
}
