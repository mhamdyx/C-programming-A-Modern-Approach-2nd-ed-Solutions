/*
 * ch3_prog_proj_01.c
 *
 *  Created on: Mar 19, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1:  Display date

#include <stdio.h>

int main(void)
{
	int day, month, year;

	printf("Enter a date (mm/dd/yyy): ");
	scanf("%d /%d /%d", &month, &day, &year);

	printf("You entered the date %04d%02d%02d\n", year, month, day);

	return 0;
}
