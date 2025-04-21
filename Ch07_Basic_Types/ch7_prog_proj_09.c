/*
 * ch7_prog_proj_09.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 9: Time Conversion (12 -> 24)

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int hrs, mins;
	char meridiem;

	printf("Enter a 12-hour time: ");
	scanf("%d :%d %c", &hrs, &mins, &meridiem);

	// Convert from 12-hour time to 24-hour time:
	if (toupper(meridiem) == 'P' && hrs != 12) // 1 PM -> 13, 12 PM -> 12
	{
		hrs += 12;
	}
	else if (toupper(meridiem) == 'A' && hrs == 12) // 1 AM -> 1, 12 AM -> 0
	{
		hrs = 0;
	}

	printf("Equivalent 24-hour time: %.2d:%.2d\n", hrs, mins);

	return 0;
}
