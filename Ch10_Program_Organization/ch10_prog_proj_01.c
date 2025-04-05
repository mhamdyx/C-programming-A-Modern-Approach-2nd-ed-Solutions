/*
 * ch10_prog_proj_01.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Mahmoud Hamdy
 */

 // Programming Project 1: Stack

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
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
	char input, top_item;
	bool match = false;
	printf("Enter parentheses and/or braces: ");

	while(1)
	{
		input = getchar();

		if(input == '(' || input == '{')
		{
			match = false;
			push(input);
		}
		else if(input == ')')
		{
			top_item = pop();

			if(top_item != '(')
			{
				break;
			}
			match = true;
		}
		else if(input == '}')
		{
			top_item = pop();

			if(top_item != '{')
			{
				break;
			}
			match = true;
		}
		else if(input == '\n')
		{
			break;
		}
	}

	// Checking if stack is empty
	if(is_empty() && match)
	{
		printf("Parentheses/braces are nested properly");
	}
	else
	{
		printf("Parentheses/braces are not matched");
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

void push(char i)
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

char pop(void)
{
	if(is_empty())
	{
		stack_underflow();
	}

	return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Parentheses/braces are not matched");
	exit(EXIT_FAILURE);
}



// Another elegant implementation
/*
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
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
	char input;

	printf("Enter parentheses and/or braces: ");

	while((input = getchar()) != '\n')
	{

		if(input == '(' || input == '{')
		{
			push(input);
		}
		else if(input == ')' && pop() != '(')
		{
			printf("Parentheses/braces are not matched");
		}
		else if(input == '}' && pop() != '{')
		{
			printf("Parentheses/braces are not matched");
		}
	}

	// Checking if stack is empty
	if(is_empty())
	{
		printf("Parentheses/braces are nested properly");
	}
	else
	{
		printf("Parentheses/braces are not matched");
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

void push(char i)
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

char pop(void)
{
	if(is_empty())
	{
		stack_underflow();
	}

	return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Parentheses/braces are not matched");
	exit(EXIT_FAILURE);
}
*/
