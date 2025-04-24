/*
 * ch8_prog_proj_02.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Repeated Digits (modified 2)

#include <stdio.h>

int main(void)
{
	int digit_seen_count[10] = {0};
	int digit;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0)
	{
		digit = n % 10;

		digit_seen_count[digit]++;

		n /= 10;
	}

	printf("Digit:      ");
	for (digit = 0; digit < 10; digit++)
		printf("%3d", digit);

	printf("\nOccurrences:");
	for (digit = 0; digit < 10; digit++)
		printf("%3d", digit_seen_count[digit]);

	printf("\n");

	return 0;
}
