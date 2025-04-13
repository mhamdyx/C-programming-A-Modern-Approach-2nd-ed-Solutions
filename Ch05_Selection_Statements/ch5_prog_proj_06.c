/*
 * ch5_prog_proj_06.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 6: UPC (modified)

#include <stdio.h>

int main(void)
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5;
	int first_sum, second_sum, total;
	int check_digit, computed_check_digit;

	printf("Enter the first (single) digit: ");
	scanf("%1d", &d);

	printf("Enter first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

	printf("Enter the last (single) digit: ");
	scanf("%1d", &check_digit);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;

	computed_check_digit = 9 - ((total - 1) % 10);

	if (check_digit == computed_check_digit)
	{
		printf("VALID\n");
	}
	else
	{
		printf("NOT VALID\n");
	}

	return 0;
}
