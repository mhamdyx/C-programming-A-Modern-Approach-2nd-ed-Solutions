/*
 * queueADT2.h
 *
 *  Created on: May 12, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef QUEUEADT2_H_
#define QUEUEADT2_H_

#include <stdbool.h> // C99

typedef int Item;
typedef struct queue_type *Queue;

Queue create(int size);

void destroy(Queue q);

void make_empty(Queue q);

// Inserting item at the end of the queue
void enqueue(Queue q, Item i);

// Removing an item from the beginning of the queue
Item dequeue(Queue q);

// Returning the first item in the queue (without changing the queue)
Item front(Queue q);

// Returning the last item in the queue (without changing the queue)
Item rear(Queue q);

bool is_empty(Queue q);

bool is_full(Queue q);

#endif /* QUEUEADT2_H_ */
