/*
 * ch8_prog_proj_01.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Repeated Digits (modified)

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	bool digit_seen[10] = {false};
	bool digit_repeated[10] = {false};
	int digit;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0)
	{
		digit = n % 10;

		if (digit_seen[digit])
			digit_repeated[digit] = true;
        else
		    digit_seen[digit] = true;

		n /= 10;
	}

	printf("Repeated digit(s):");

	for (digit = 0; digit < 10; digit++)
		if (digit_repeated[digit])
			printf(" %d", digit);

	printf("\n");

	return 0;
}
