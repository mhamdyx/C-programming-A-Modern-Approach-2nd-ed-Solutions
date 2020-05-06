/*
 * ch6_prog_proj_03.c
 *
 *  Created on: Nov 23, 2019
 *      Author: SuperMoudy
 */

// Programming Project 3: Fraction's lowest terms (GCD)

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
