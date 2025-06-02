/*
 * queue.h
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h> // C99

#define QUEUE_SIZE 100

typedef struct
{
	int buffer[QUEUE_SIZE]; // Queue array
	int rear; // Position of the first empty slot in the array
	int front; // Position of the next item to be removed
	int qsize; // Number of items in the queue
} Queue;

// Inserting item at the end of the queue
void enqueue(Queue *q, int i);

// Removing an item from the beginning of the queue
int dequeue(Queue *q);

// Returning the first item in the queue (without changing the queue)
int front_item(const Queue *q);

// Returning the last item in the queue (without changing the queue)
int rear_item(const Queue *q);

// Testing whether the queue is empty
bool is_empty(const Queue *q);

#endif /* QUEUE_H_ */
