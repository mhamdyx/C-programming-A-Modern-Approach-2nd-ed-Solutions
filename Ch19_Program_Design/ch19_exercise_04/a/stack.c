/*
 * stack.c
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

// Stack type (Fixed-length array representation)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC void make_empty(Stack *s)
{
	s->top = 0;
}

PUBLIC bool is_empty(Stack *s)
{
	return s->top == 0;
}

PUBLIC bool is_full(Stack *s)
{
	return s->top == STACK_SIZE;
}

PUBLIC void push(Stack *s, int i)
{
	if(is_full(s))
		terminate("Error in push: stack is full.");

	s->contents[s->top++] = i;
}

PUBLIC int pop(Stack *s)
{
	if(is_empty(s))
		terminate("Error in pop: stack is empty.");

	return s->contents[--s->top];
}
