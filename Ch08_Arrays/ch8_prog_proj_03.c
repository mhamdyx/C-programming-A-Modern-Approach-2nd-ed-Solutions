/*
 * ch8_prog_proj_03.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Repeated Digits (modified 3)

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	bool digit_seen[10] = {false};
	int digit;
	long n;

	while (1)
	{
		printf("Enter a number: ");
		scanf("%ld", &n);

		// Check termination condition
		if (n <= 0)
			break;

		while (n > 0)
		{
			digit = n % 10;

			if (digit_seen[digit])
				break;
			digit_seen[digit] = true;
			n /= 10;
		}

		if (n > 0)
			printf("Repeated digit\n");
		else
			printf("No repeated digit\n");

		// Reset digit_seen array
		for (digit = 0; digit < 10; digit++)
			digit_seen[digit] = false;
	}

	return 0;
}
