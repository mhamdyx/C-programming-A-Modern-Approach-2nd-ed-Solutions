/*
 * ch6_prog_proj_03.c
 *
 *  Created on: Nov 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Fraction's lowest terms (GCD)

#include <stdio.h>

int main(void)
{
	int numerator, denominator, m, n, remainder;

	printf("Enter a fracation: ");
	scanf("%d /%d", &numerator, &denominator);

	m = numerator;
	n = denominator;

	while(n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}

	printf("In lowest terms: %d/%d\n", numerator / m, denominator / m);

	return 0;
}
