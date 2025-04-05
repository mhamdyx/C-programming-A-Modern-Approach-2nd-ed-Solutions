/*
 * stack.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Mahmoud Hamdy
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define STACK_SIZE 100

extern int contents[STACK_SIZE];
extern int top;


void make_empty(void);

bool is_empty(void);

bool is_full(void);

void push(int i);

int pop(void);

void stack_overflow(void);

void stack_underflow(void);


#endif /* STACK_H_ */
