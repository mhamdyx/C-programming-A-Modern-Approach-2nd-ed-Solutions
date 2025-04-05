/*
 * queue.h
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h> // C99

// Inserting item at the end of the queue
void enqueue(int i);

// Removing an item from the beginning of the queue
int dequeue(void);

// Returning the first item in the queue (without changing the queue)
int front_item(void);

// Returning the last item in the queue (without changing the queue)
int rear_item(void);

// Testing whether the queue is empty
bool is_empty(void);

#endif /* QUEUE_H_ */
