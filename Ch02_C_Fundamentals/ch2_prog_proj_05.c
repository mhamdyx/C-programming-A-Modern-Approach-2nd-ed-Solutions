/*
 * ch2_prog_proj_05.c
 *
 *  Created on: Apr 6, 2025
 *      Author: Mahmoud Hamdy
 */

// Project 5: Calculate Polynomial

#include <stdio.h>

int main(void)
{
	int x, xpow2, xpow3, xpow4, xpow5, polynomial;

	printf("Enter x: ");
	scanf("%d", &x);

	xpow2 = x * x;
	xpow3 = xpow2 * x;
	xpow4 = xpow3 * x;
	xpow5 = xpow4 * x;

	polynomial = (3 * xpow5) + (2 * xpow4) - (5 * xpow3)
			- xpow2 + (7 * x) - 6;

	printf("Polynomial = %d\n", polynomial);

	return 0;
}
