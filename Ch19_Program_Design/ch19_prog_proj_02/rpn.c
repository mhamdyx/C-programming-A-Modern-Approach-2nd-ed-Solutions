/*
 * rpn.c
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: RPN expressions

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"

int main(void)
{
	char ch;
	int op1 = 0, op2 = 0, result = 0;
	Stack s = create();

	printf("Enter an RPN expression: ");

	while (1)
	{
		scanf(" %c", &ch);

		if (ch >= '0' && ch <= '9')
			push(s, ch - '0');
		else if (ch == '+')
		{
			op2 = pop(s);
			op1 = pop(s);
			result = op1 + op2;
			push(s, result);
		}
		else if (ch == '-')
		{
			op2 = pop(s);
			op1 = pop(s);
			result = op1 - op2;
			push(s, result);
		}
		else if (ch == '*')
		{
			op2 = pop(s);
			op1 = pop(s);
			result = op1 * op2;
			push(s, result);
		}
		else if (ch == '/')
		{
			op2 = pop(s);
			op1 = pop(s);
			result = op1 / op2;
			push(s, result);
		}
		else if (ch == '=')
		{
			result = pop(s);
			printf("Value of expression: %d\n", result);
			result = 0;
			printf("Enter an RPN expression: ");
		}
		else
			break;
	}

	return 0;
}
