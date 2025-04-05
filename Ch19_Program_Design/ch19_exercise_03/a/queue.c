/*
 * queue.c
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC /* empty */
#define PRIVATE static
#define QUEUE_SIZE 100

PRIVATE int buffer[QUEUE_SIZE]; // Queue array
PRIVATE int rear = 0; // Position of the first empty slot in the array
PRIVATE int front = 0; // Position of the next item to be removed
PRIVATE int size = 0; // Number of items in the queue

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}


PUBLIC void enqueue(int i)
{
	if(size >= QUEUE_SIZE)
		terminate("Error in enqueue: queue is full.");

	buffer[rear++] = i;
	rear %= QUEUE_SIZE;
	size++;
}

PUBLIC int dequeue(void)
{
	if(is_empty())
		terminate("Error in dequeue: queue is empty.");

	int i = buffer[front++];
	front %= QUEUE_SIZE;
	size--;

	return i;
}

PUBLIC int front_item(void)
{
    if(is_empty())
        terminate("Error in front_item: queue is empty.");

	return buffer[front];
}

PUBLIC int rear_item(void)
{
    if(is_empty())
        terminate("Error in rear_item: queue is empty.");
        
	if(rear == 0)
		return buffer[QUEUE_SIZE];

	return buffer[rear - 1];
}

PUBLIC bool is_empty(void)
{
	return size == 0;
}
