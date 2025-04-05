/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

// (Section 6.3, Pages 110-111)

/*
 * ch6_prog_proj_07.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: Table of squares using an odd method

#include <stdio.h>

int main(void)
{
	int i, n, odd, square;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	odd = 3;
	for(i = 1, square = 1; i <= n; odd += 2, ++i)
	{
		printf("%10d%10d\n", i, square);

		square += odd;
	}

	return 0;
}
