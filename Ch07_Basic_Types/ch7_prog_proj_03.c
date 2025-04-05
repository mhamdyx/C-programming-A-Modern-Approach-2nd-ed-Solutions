/*
 * ch7_prog_proj_03.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Summing a Series of Numbers

#include <stdio.h>

int main(void)
{
	double n, sum = 0;

	printf("This program sums a series of double values.\n");
	printf("Enter double values (0 to terminate): ");
	scanf("%lf", &n);

	while(n != 0.0)
	{
		sum += n;
		scanf("%lf", &n);
	}

	printf("The sum is: %f\n", sum);

	return 0;
}
