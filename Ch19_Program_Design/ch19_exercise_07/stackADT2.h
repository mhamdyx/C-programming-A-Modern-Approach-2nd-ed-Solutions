/*
 * stackADT2.h
 *
 *  Created on: May 10, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef STACKADT2_H_
#define STACKADT2_H_

#include <stdbool.h> // C99

typedef int Item;
typedef struct stack_type *Stack;

Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);

void push(Stack s, Item i);
Item pop(Stack s);

#endif /* STACKADT2_H_ */
