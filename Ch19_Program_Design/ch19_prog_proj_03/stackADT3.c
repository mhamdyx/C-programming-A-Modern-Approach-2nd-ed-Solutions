/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

// (Section 19.4, Page 500)

/*
 * stackADT3.c
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

// Stack ADT (Linked-list representation)

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node
{
	Item data;
	struct node *next;
};

struct stack_type
{
	struct node *top;
	int len;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_type));

	if(s == NULL)
		terminate("Error in create: stack could not be created.");

	s->top = NULL;
	s->len = 0;

	return s;
}

void destroy(Stack s)
{
	make_empty(s);
	free(s);
}

void make_empty(Stack s)
{
	while(!is_empty(s))
		pop(s);
}

bool is_empty(Stack s)
{
	return s->top == NULL;
}

bool is_full(Stack s)
{
	return false;
}

void push(Stack s, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
	s->len++;
}

Item pop(Stack s)
{
	struct node *old_top;
	Item i;

	if(is_empty(s))
		terminate("Error in pop: stack is empty.");

	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);
	s->len--;

	return i;
}

int length(Stack s)
{
	return s->len;
}
