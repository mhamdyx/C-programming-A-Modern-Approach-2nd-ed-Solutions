/*
 * ch4_prog_proj_02.c
 *
 *  Created on: Apr 1, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Reversing number's digits (Extended)

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter a three-digit number: ");
	scanf("%d", &n);

	printf("The reversal is: %d%d%d\n", n % 10, n / 10 % 10, n / 10 / 10);

	return 0;
}
