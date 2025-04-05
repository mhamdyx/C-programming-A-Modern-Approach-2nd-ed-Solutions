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
	char input;
	bool match = true;
	Stack s = create();

	printf("Enter parentheses and/or braces: ");

	while((input = getchar()) != '\n')
	{
		if(input == '(' || input == '{')
		{
			match = false;
			push(s, input);
		}
		else if(input == ')' && pop(s) != '(')
		{
			break;
		}
		else if(input == '}' && pop(s) != '{')
		{
			break;
		}
		else
		{
			match = true;
		}
	}

	// Checking if stack is empty
	if(is_empty(s) && match)
	{
		printf("Parentheses/braces are nested properly");
	}
	else
	{
		printf("Parentheses/braces are not matched");
	}

	return 0;
}
