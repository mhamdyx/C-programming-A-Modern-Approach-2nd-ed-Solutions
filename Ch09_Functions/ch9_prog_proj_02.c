/*
 * ch9_prog_proj_02.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: tax income

#include <stdio.h>

float compute_tax(float income);

int main(void)
{
	float  income;

	printf("Enter the taxable income: ");
	scanf("%f", &income);

	printf("Tax due = %f", compute_tax(income));

	return 0;
}

float compute_tax(float income)
{
	float tax = 0.0f;

	if(income > 0 && income <= 750)
	{
		tax = 0.01f * income;
	}
	else if(income > 750 && income <= 2250)
	{
		tax = 7.5f + 0.02f * income;
	}
	else if(income > 2250 && income <= 3750)
	{
		tax = 37.50f + 0.03f * income;
	}
	else if(income > 3750 && income <= 5250)
	{
		tax = 82.50f + 0.04f * income;
	}
	else if(income > 5250 && income <= 7000)
	{
		tax = 142.50f + 0.05f * income;
	}
	else if(income > 7000)
	{
		tax = 230.00f + 0.06f * income;
	}

	return tax;
}
