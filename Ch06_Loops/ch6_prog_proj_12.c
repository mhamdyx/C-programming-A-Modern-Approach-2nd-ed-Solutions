/*
 * ch6_prog_proj_12.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 12: Calculating mathematical constant e

#include <stdio.h>

int main(void)
{
	int i, factorial_i = 1;
	float e = 1.0f, epsilon, term = 1.0f;

	printf("This program calculates an approximate value of\n");
	printf("the mathematical constant e, using this formula:\n");
	printf("1 + 1/1! + 1/2! + 1/3! + ... + 1/n!\n");
	printf("where n is an integer\n\n");

	printf("Enter epsilon: ");
	scanf("%f", &epsilon);

	for(i = 1; term >= epsilon; i++)
	{
		// Calculate factorial i to get 1/i!
		factorial_i *= i;

		term = 1.0f / factorial_i;

		e += term;
	}

	printf("e is approximately equal to %f\n", e);

	return 0;
}
