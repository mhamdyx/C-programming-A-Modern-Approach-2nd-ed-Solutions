/*
 * ch5_prog_proj_05.c
 *
 *  Created on: Oct 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: tax income

#include <stdio.h>

int main(void)
{
	float  income, tax = 0.0f;

	printf("Enter the taxable income: ");
	scanf("%f", &income);

	if(income <= 750)
	{
		tax = 0.01f * income;
	}
	else if(income <= 2250)
	{
		tax = 7.5f + 0.02f * income;
	}
	else if(income <= 3750)
	{
		tax = 37.50f + 0.03f * income;
	}
	else if(income <= 5250)
	{
		tax = 82.50f + 0.04f * income;
	}
	else if(income <= 7000)
	{
		tax = 142.50f + 0.05f * income;
	}
	else if(income > 7000)
	{
		tax = 230.00f + 0.06f * income;
	}

	printf("Tax due = $%.2f", tax);

	return 0;

}
