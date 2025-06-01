/*
 * stack.h
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define STACK_SIZE 100

typedef struct
{
	int contents[STACK_SIZE];
	int top;
} Stack;

void make_empty(Stack *s);

bool is_empty(const Stack *s);

bool is_full(const Stack *s);

void push(Stack *s, int i);

int pop(Stack *s);

#endif /* STACK_H_ */
