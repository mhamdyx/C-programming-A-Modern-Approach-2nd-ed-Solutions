/*
 * ch10_prog_proj_01.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Stack (New implementation)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // C99 Only

#define STACK_SIZE 100

// External Variables
char contents[STACK_SIZE];
int top = 0;

// Prototypes
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
	char input_ch;
	bool match;

	printf("Enter parentheses and/or braces: ");
	while ((input_ch = getchar()) != '\n')
	{
		if (input_ch == '(' || input_ch == '{')
			push(input_ch);
		else if (input_ch == ')' && pop() != '(')
		{
			match = false;
			break;
		}
		else if (input_ch == '}' && pop() != '{')
		{
			match = false;
			break;
		}
		else // { matched } or ( matched )
			match = true;
	}

	if (is_empty() && match)
		printf("Parentheses/braces are nested properly\n");
	else
		printf("Parentheses/braces aren't nested properly\n");

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

void push(char ch)
{
	if(is_full())
		stack_overflow();
	else
		contents[top++] = ch;
}

char pop(void)
{
	if(is_empty())
		stack_underflow();

	return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Stack underflow\n");
	printf("Parentheses/braces aren't nested properly\n");
	exit(EXIT_FAILURE);
}
