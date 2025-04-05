/*
 * ch6_prog_proj_02.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Greatest common divison (GCD)

#include <stdio.h>

int main(void)
{
	int m, n, remainder;

	printf("Enter two integers: ");
	scanf("%d %d", &m, &n);

	// As long as n != 0, m != gcd
	while(n != 0)
	{
		// GCD - Euclid's algorithm:
		// 1) Compute the remainder of m / n
		remainder = m % n;

		// 2) Copy n into m
		m = n;

		// 3) Copy remainder into n
		n = remainder;

		// 4) Repeat the process...
	}

	printf("Greatest common divisor: %d\n", m);

	return 0;
}
