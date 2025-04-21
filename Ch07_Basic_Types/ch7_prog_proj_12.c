/*
 * ch7_prog_proj_12.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 12: Expression Evaluation

#include <stdio.h>

int main(void)
{
	float operand, accumulator;
	char operator;

	// Automatically accumulate the first operand
	printf("Enter an expression: ");
	scanf("%f", &accumulator);

	do
	{
		// Skip possible whitespaces
		while((operator = getchar()) == ' ');

		if (operator == '\n')
			break;
		else
			scanf("%f", &operand);

		switch (operator)
		{
		case '+': accumulator += operand; break;
		case '-': accumulator -= operand; break;
		case '*': accumulator *= operand; break;
		case '/': accumulator /= operand; break;
		default: break;
		}
	} while (1);

	printf("Value of expression: %.1f\n", accumulator);

	return 0;
}
