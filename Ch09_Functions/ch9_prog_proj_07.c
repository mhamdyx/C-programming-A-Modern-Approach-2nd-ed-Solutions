/*
 * ch9_prog_proj_07.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

#include <stdio.h>

int power(int x, int n);

int main(void)
{
	int x, n;

	// Reading x
	printf("Enter x: ");
	scanf("%d", &x);

	// Reading n
	printf("Enter the power n: ");
	scanf("%d", &n);

	// Printing output
	printf("%d to the power %d(%d^%d) = %d", x, n, x, n, power(x, n));

	return 0;
}

int power(int x, int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n % 2 == 0)
	{

		return power(x, n / 2) * power(x, n / 2);
	}
	else
	{
		return x * power(x, n - 1);
	}
}
