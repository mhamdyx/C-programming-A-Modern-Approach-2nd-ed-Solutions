/*
 * ch2_prog_proj_07.c
 *
 *  Created on: Nov 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Project 7: Smallest number of bills

#include <stdio.h>

int main(void)
{
	int usd_amount, bills;

	printf("Enter a dollar amount: ");
	scanf("%d", &usd_amount);

	bills = usd_amount / 20;
	printf("$20 bills: %d\n", bills);
	usd_amount %= 20;

	bills = usd_amount / 10;
	printf("$10 bills: %d\n", bills);
	usd_amount %= 10;

	bills = usd_amount / 5;
	printf(" $5 bills: %d\n", bills);
	usd_amount %= 5;

	printf(" $1 bills: %d\n", usd_amount);

	return 0;
}
