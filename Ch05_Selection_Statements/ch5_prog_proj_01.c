/*
 * ch5_prog_proj_01.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 1: Number of digits

#include <stdio.h>

int main(void)
{
	int number, digits_count;

	printf("Enter a number: ");
	scanf("%d", &number);

	if (number >= 0 && number <= 9)
	{
		digits_count = 1;
	}
	else if (number >= 10 && number <= 99)
	{
		digits_count = 2;
	}
	else if (number >= 100 && number <= 999)
	{
		digits_count = 3;
	}

	printf("The number %d has %d ", number, digits_count);

	if(digits_count > 1)
	{
		printf("digits\n");
	}
	else
	{
		printf("digit\n");
	}

	return 0;
}
