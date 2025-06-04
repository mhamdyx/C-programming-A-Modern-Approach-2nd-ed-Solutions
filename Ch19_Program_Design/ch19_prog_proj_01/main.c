/*
 * main.c
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // C99 Only
#include "stackADT.h"

int main(void)
{
	char input_ch;
	bool match;
	Stack s = create();

	printf("Enter parentheses and/or braces: ");

	while ((input_ch = getchar()) != '\n')
	{
		if (input_ch == '(' || input_ch == '{')
			push(s, input_ch);
		else if (input_ch == ')' && pop(s) != '(')
		{
			match = false;
			break;
		}
		else if (input_ch == '}' && pop(s) != '{')
		{
			match = false;
			break;
		}
		else // { matched } or ( matched )
			match = true;
	}

	// Checking if stack is empty
	if (is_empty(s) && match)
		printf("Parentheses/braces are nested properly\n");
	else
		printf("Parentheses/braces aren't nested properly\n");

	return 0;
}
