/*
 * ch4_prog_proj_01.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Reversing number's digits

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter a two-digit number: ");
	scanf("%d", &n);

	printf("The reversal is: %d%d\n", n % 10, n / 10);

	return 0;
}
