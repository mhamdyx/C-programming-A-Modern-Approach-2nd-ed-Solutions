/*
 * ch13_prog_proj_15.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 15: RPN expressions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

// External Variables
int contents[STACK_SIZE] = {0};
int top = 0;

// Stack prototypes
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int evaluate_RPN_expression(const char *expression);

int main(void)
{
	char exp[STACK_SIZE + 1];

	while(1)
	{
		printf("Enter an RPN expression: ");
		gets(exp);

		printf("Value of expression: %d\n", evaluate_RPN_expression(exp));
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

int evaluate_RPN_expression(const char *expression)
{
	int op1 = 0, op2 = 0, result = 0;

	while(*expression)
	{

		if(*expression == ' ')
		{
			expression++;
			continue;
		}
		else if(*expression >= '0' && *expression <= '9')
		{
			push(*expression - '0');
		}
		else if(*expression == '+')
		{
			op2 = pop();
			op1 = pop();
			result = op1 + op2;
			push(result);
		}
		else if(*expression == '-')
		{
			op2 = pop();
			op1 = pop();
			result = op1 - op2;
			push(result);
		}
		else if(*expression == '*')
		{
			op2 = pop();
			op1 = pop();
			result = op1 * op2;
			push(result);
		}
		else if(*expression == '/')
		{
			op2 = pop();
			op1 = pop();
			result = op1 / op2;
			push(result);
		}
		else if(*expression == '=')
		{
			result = pop();
		}
		else
		{
			exit(EXIT_FAILURE);
		}
		expression++;
	}

	return result;

}
