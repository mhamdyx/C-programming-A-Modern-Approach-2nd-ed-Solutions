/*
 * ch5_prog_proj_09.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 9: Comparing Dates

#include <stdio.h>

int main(void)
{
	int mm1, dd1, yy1, mm2, dd2, yy2, earlier_date = 0;

	printf("Enter first date (mm/dd/yy): ");
	scanf(" %d / %d / %d", &mm1, &dd1, &yy1);

	printf("Enter second date (mm/dd/yy): ");
	scanf(" %d / %d / %d", &mm2, &dd2, &yy2);

	if(yy1 < yy2)
		earlier_date = 1;
	else if(yy1 > yy2)
		earlier_date = 2;
	else
	{
		if(mm1 < mm2)
			earlier_date = 1;
		else if(mm1 > mm2)
			earlier_date = 2;
		else
		{
			if(dd1 < dd2)
				earlier_date = 1;
			else if(dd1 > dd2)
				earlier_date = 2;
		}
	}


	if(earlier_date == 1)
	{
		printf("%d/%d/%02d is earlier than %d/%d/%02d\n", mm1, dd1, yy1, mm2, dd2, yy2);
	}
	else if(earlier_date == 2)
	{
		printf("%d/%d/%02d is earlier than %d/%d/%02d\n", mm2, dd2, yy2, mm1, dd1, yy1);
	}
	else
	{
		printf("Both dates are the same\n");
	}

	return 0;
}
