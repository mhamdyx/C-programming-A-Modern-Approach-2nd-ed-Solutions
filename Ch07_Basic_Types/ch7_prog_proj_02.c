/*
 * ch7_prog_proj_02.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Printing a Table of Squares

#include <stdio.h>

int main(void)
{
	int i, n;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
    
	getchar(); // Read the extra \n left by scanf

	for(i = 1; i <= n; i++)
	{
		printf("%10d%10d\n", i, i * i);

		if(i % 24 == 0)
		{
			printf("Press Enter to coninue...");

			while(getchar() != '\n'); // Wait till enter is pressed
		}
	}

	return 0;
}
