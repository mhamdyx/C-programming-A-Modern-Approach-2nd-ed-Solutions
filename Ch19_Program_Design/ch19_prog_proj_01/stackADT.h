/*
 * stackADT.h
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef STACKADT_H_
#define STACKADT_H_

#include <stdbool.h> // C99

typedef char Item;
typedef struct stack_type *Stack;

Stack create(void);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(Stack s);

bool is_full(Stack s);

void push(Stack s, Item i);

Item pop(Stack s);

#endif /* STACKADT_H_ */
