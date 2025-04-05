/*
 * ch11_prog_proj_03.c
 *
 *  Created on: Nov 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Fraction's lowest terms (GCD)

#include <stdio.h>
#include <stdlib.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
int gcd(int a, int b);

int main(void)
{
	int num1, den1, num2, den2;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &den1);

	reduce(num1, den1, &num2, &den2);

	printf("In lowest terms: %d/%d", num2, den2);

	return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int hcf = gcd(numerator, denominator);
	(*reduced_numerator) = numerator / hcf;
	(*reduced_denominator) = denominator / hcf;
}

int gcd(int a, int b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}
