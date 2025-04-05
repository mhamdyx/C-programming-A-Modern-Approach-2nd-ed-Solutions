/*
 * ch7_prog_proj_01.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Printing a Table of Squares (Analysis)

// Case 1: Type of i is int

#include <stdio.h>

int main(void)
{
	int i;
	int n;
	int problem_detected = 0;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		printf("%10d%10d\n", i, i * i);

		if(i * i < 0)
		{
			problem_detected = 1;
			break;
		}
	}

	if(problem_detected)
		printf("\nThe problem is detected at i = %d\n", i);

	printf("When i is int, its size is %u bits\n", 8 * sizeof(i));

	return 0;
}

// Output
/**
 * The problem is detected at i = 46341
 * When i is int, its size is 32 bits
 */

//----------------------------------

// Case 2: Type of i is short
/*
int main(void)
{
	short i;
	int n;
	int problem_detected = 0;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		printf("%10hd%10hd\n", i, i * i);

		if((short)(i * i) < 0)
		{
			problem_detected = 1;
			break;
		}
	}

	if(problem_detected)
		printf("The problem is detected at i = %hd\n", i);

	printf("When i is short, its size is %u bits\n", 8 * sizeof(i));

	return 0;
}
*/

// Output
/**
 * The problem is detected at i = 182
 * When i is short, its size is 16 bits
 */

//----------------------------------

// Case 3: Type of i is long
/*
#include <stdio.h>

int main(void)
{
	long i;
	int n;
	int problem_detected = 0;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		printf("%10ld%10ld\n", i, i * i);

		if(i * i < 0)
		{
			problem_detected = 1;
			break;
		}
	}

	if(problem_detected)
		printf("\nThe problem is detected at i = %ld\n", i);

	printf("When i is long, its size is %u bits\n", 8 * sizeof(i));

	return 0;
}
*/

// Output
/**
 * The problem is detected at i = 46341
 * When i is long, its size is 32 bits
 */


