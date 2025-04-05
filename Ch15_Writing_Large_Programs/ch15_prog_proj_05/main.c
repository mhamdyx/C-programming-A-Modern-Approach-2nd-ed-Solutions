/*
 * main.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: RPN expressions

#include <stdio.h>
#include "stack.h"

int main(void)
{
	char ch;
	int op1 = 0, op2 = 0, result = 0;

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
		}
		else if(ch == '\n')
		{
			printf("Value of expression: %d\n", result);
			result = 0;
			op1 = 0;
			op2 = 0;
			printf("Enter an RPN expression: ");
			fflush(stdout); fflush(stdin);
		}
		else
		{
			break;
		}
	}

	return 0;
}
