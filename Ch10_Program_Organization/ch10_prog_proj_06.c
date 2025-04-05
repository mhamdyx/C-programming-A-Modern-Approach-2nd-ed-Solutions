/*
 * ch10_prog_proj_06.c
 *
 *  Created on: Nov 11, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: RPN expressions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

// External Variables
int contents[STACK_SIZE];
int top = 0;

// Stack prototypes
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
	int ch, op1 = 0, op2 = 0, result = 0;

	printf("Enter an RPN expression: ");

	while(1)
	{
		ch = getchar();

		if(ch == ' ')
		{
			continue;
		}
		else if(ch >= '0' && ch <= '9')
		{
			push(ch - '0');
		}
		else if(ch == '+')
		{
			op2 = pop();
			op1 = pop();
			result = op1 + op2;
			push(result);
		}
		else if(ch == '-')
		{
			op2 = pop();
			op1 = pop();
			result = op1 - op2;
			push(result);
		}
		else if(ch == '*')
		{
			op2 = pop();
			op1 = pop();
			result = op1 * op2;
			push(result);
		}
		else if(ch == '/')
		{
			op2 = pop();
			op1 = pop();
			result = op1 / op2;
			push(result);
		}
		else if(ch == '=')
		{
			result = pop();
			printf("Value of expression: %d\n", result);
		}
		else if(ch == '\n')
		{
			make_empty(s); // In case of omitting '=' and result remains in the stack
			result = 0;
			op1 = 0; 
			op2 = 0;
			printf("Enter an RPN expression: ");
		}
		else
		{
			break;
		}
	}

	return 0;
}

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
