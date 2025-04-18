/*
 * ch6_prog_proj_01.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Largest non-negative number entered

#include <stdio.h>

int main(void)
{
	float number, largest_number = 0.0f;

	for(;;)
	{
		printf("Enter a number: ");
		scanf("%f", &number);

		if(number <= 0)
			break;

		if(number > largest_number)
			largest_number = number;
	}

	printf("\nThe largest number entered was %g\n", largest_number);

	return 0;
}
