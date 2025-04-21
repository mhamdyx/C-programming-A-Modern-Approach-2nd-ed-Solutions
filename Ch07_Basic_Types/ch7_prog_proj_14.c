/*
 * ch7_prog_proj_14.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 14: Square root using Newton's method

#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y, avg = 1.0;

	printf("Enter a positive number: ");
	scanf("%lf", &x);

	do
	{
		// new y (avg) becomes old y (y)
		y = avg;

		// compute the new y
		avg = (y + x / y) / 2;

	} while (fabs(avg - y) > 0.00001 * y);

	// get the latest y value
	y = avg;

	printf("Square root: %g\n", y);

	return 0;
}
