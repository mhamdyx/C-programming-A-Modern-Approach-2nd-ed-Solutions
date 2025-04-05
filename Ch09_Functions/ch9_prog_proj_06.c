/*
 * ch9_prog_proj_06.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: Polynomial

#include <stdio.h>

double compute_polynomial(double x);

int main(void)
{
	// Independent variable
	double x;

	// Reading x
	printf("Enter the value of x: ");
	scanf("%lf", &x);

	// Compute polynomial
	printf("The value of the polynomial = %lf\n", compute_polynomial(x));

	return 0;
}

double compute_polynomial(double x)
{
	double x2 = x * x;
	double x3 = x2 * x;
	double x4 = x3 * x;
	double x5 = x4 * x;

	return (3 * x5 + 2 * x4 - 5 * x3 - x2 + 7 * x - 6);
}

// Another implementation for the function (not necessary here though)
/*
double compute_polynomial(double x)
{
	double result = -6, symbol = x;

	for(int i = 0; i < 5; i++)
	{
		if(i == 0)
		{
			result += (7 * symbol);
		}
		else if(i == 1)
		{
			symbol *= x;
			result -= symbol;
		}
		else if(i == 2)
		{
			symbol *= x;
			result -= (5 * symbol);
		}
		else if(i == 3)
		{
			symbol *= x;
			result += (2 * symbol);
		}
		else if(i == 4)
		{
			symbol *= x;
			result += (3 * symbol);
		}
	}

	return result;
}
*/
