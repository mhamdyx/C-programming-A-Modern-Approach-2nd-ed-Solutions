/*
 * ch2_prog_proj_06.c
 *
 *  Created on: Apr 6, 2025
 *      Author: Mahmoud Hamdy
 */

// Project 6: Calculate Polynomial (modified)

#include <stdio.h>

int main(void)
{
	int x, polynomial;

	printf("Enter x: ");
	scanf("%d", &x);

	polynomial = (((((((((3 * x) + 2) * x) - 5) * x) - 1) * x) + 7) * x) - 6;

	printf("Polynomial = %d\n", polynomial);

	return 0;
}
