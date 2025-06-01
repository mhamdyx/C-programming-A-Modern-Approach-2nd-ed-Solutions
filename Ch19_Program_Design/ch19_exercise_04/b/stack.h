/*
 * stack.h
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
};

// I've included two different solutions
// Feel free to unlock the solution of your interest by uncommenting
// a directive while commenting the other

#define Q4_B_SOL1
//#define Q4_B_SOL2

// I do this alot in my local repo but this is the first time I show it
// in my Github repo (Hopefully this will give you some intuition)

#ifdef Q4_B_SOL1

typedef struct
{
	struct node *top;
} Stack;

#elif Q4_B_SOL2

typedef struct node *Stack;

#endif /* Q4_B_SOL */

void make_empty(Stack *s);

bool is_empty(const Stack *s);

bool is_full(const Stack *s);

void push(Stack *s, int i);

int pop(Stack *s);

#endif /* STACK_H_ */
