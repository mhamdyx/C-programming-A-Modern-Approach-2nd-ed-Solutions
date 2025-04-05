/*
 * ch11_prog_proj_01.c
 *
 *  Created on: Nov 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Project 1: Smallest number of bills

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
	int USD_amount, _20_USD = 0, _10_USD = 0, _5_USD = 0, _1_USD = 0;

	printf("Enter a dollar amount: ");
	scanf("%d", &USD_amount);

	pay_amount(USD_amount, &_20_USD, &_10_USD, &_5_USD, &_1_USD);

	printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d",
			_20_USD, _10_USD, _5_USD, _1_USD);

	return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	if(dollars > 20)
	{
		*twenties = dollars / 20;
		dollars %= 20;
	}

	if(dollars > 10)
	{
		*tens = dollars / 10;
		dollars %= 10;
	}

	if(dollars > 5)
	{
		*fives = dollars / 5;
		dollars %= 5;
	}

	*ones = dollars;
}
