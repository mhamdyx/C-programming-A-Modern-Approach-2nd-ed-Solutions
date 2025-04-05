/*
 * ch6_prog_proj_08.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 8: One-month calendar

#include <stdio.h>

int main(void)
{
	int n, i, day;

	printf("Enter number of days in month: ");
	scanf("%d", &n);

	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &day);

	for(i = 1; i < day; i++)
	{
		printf("   ");
	}

	for(i = 1; i <= n; i++, day++)
	{
		printf("%2d ", i);

		if(day == 7)
		{
			day = 0;
			printf("\n");
		}
	}

	return 0;
}
