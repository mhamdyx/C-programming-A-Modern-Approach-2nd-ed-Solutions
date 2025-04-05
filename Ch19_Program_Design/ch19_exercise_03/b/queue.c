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

struct node
{
	int data;
	struct node *next;
};

PRIVATE struct node *rear = NULL;
PRIVATE struct node *front = NULL;

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC void enqueue(int i)
{
	struct node *new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
		terminate("Error in enqueue: queue is full.");

	if(rear != NULL)
	{
		rear->next = new_node;
		rear = rear->next;
	}
	else
	{
		rear = new_node; // Queue was empty
		front = new_node;
	}

	rear->data = i;
	rear->next = NULL;
}

PUBLIC int dequeue(void)
{
	struct node *old_front;
	int i;

	if(is_empty())
		terminate("Error in dequeue: queue is empty.");

	old_front = front;
	i = front->data;
	front = front->next;
	free(old_front);

	// If the queue became empty, rear would be NULL
	if(is_empty())
		rear = NULL;

	return i;
}

PUBLIC int front_item(void)
{
	if(is_empty())
		terminate("Error in front_item: queue is empty.");

	return front->data;
}

PUBLIC int rear_item(void)
{
	if(is_empty())
		terminate("Error in rear_item: queue is empty.");

	return rear->data;
}

PUBLIC bool is_empty(void)
{
	return front == NULL;
}
