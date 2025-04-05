/*
 * stack.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Mahmoud Hamdy
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int contents[STACK_SIZE];

int top = 0;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if(is_full())
	{
		stack_overflow();
	}
	else
	{
		contents[top++] = i;
	}
}

int pop(void)
{
	if(is_empty())
	{
		stack_underflow();
	}

	return contents[--top];
}

void stack_overflow(void)
{
	printf("Expression is too complex");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression");
	exit(EXIT_FAILURE);
}
