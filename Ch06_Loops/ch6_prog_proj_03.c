/*
 * ch6_prog_proj_03.c
 *
 *  Created on: Nov 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Fraction's lowest terms (GCD)
// New solution from 2024 (related to programming project 2)
#include <stdio.h>

int main(void)
{
	int numerator, denominator, m, n, remainder;

	printf("Enter a fracation: ");
	scanf("%d / %d", &numerator, &denominator);

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


// Old solution from 2019
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1, den1, num2, den2, gcd = -1;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &den1);

	if(num1 == den1)
	{
		printf("In lowest terms: 1/1");
		return 0;
	}

	num2 = num1, den2 = den1;
	while(1)
	{
		if(den2 == 0)
		{
			gcd = num2;
			break;
		}
		else if(den2 == 1)
		{
			gcd = 1;
			break;
		}

		gcd = num2 % den2;
		num2 = den2;
		den2 = gcd;
	}

	num1 /= gcd;
	den1 /= gcd;

	printf("In lowest terms: %d/%d", num1, den1);

	return 0;
}
*/
