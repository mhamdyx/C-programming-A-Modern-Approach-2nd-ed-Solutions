/*
 * ch4_prog_proj_04.c
 *
 *  Created on: Apr 1, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Decimal to Octal Conversion

#include <stdio.h>

int main(void)
{
	int n;
	int d1, d2, d3, d4, d5; // Octal number: d1d2d3d4d5

	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &n);

	d5 = n % 8;
	n /= 8;

	d4 = n % 8;
	n /= 8;

	d3 = n % 8;
	n /= 8;

	d2 = n % 8;
	n /= 8;

	d1 = n;

	printf("In octal, your number is: %d%d%d%d%d\n", d1, d2, d3, d4, d5);

	return 0;
}
