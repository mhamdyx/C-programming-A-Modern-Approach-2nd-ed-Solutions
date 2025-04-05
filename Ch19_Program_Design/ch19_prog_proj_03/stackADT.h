/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

// (Section 19.4, Page 496)

/*
 * stackADT.h
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef STACKADT_H_
#define STACKADT_H_

#include <stdbool.h> // C99

typedef int Item;
typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);

void push(Stack s, Item i);
Item pop(Stack s);
int length(Stack s);

#endif /* STACKADT_H_ */
