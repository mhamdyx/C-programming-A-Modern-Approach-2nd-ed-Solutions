/*
 * ch7_prog_proj_08.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 8: Daily Flights (modified)

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int hrs, mins, total_desired_time;
	char meridiem;

	// 8:00 AM, 9:43 AM
	int dep_time1 = 480, dep_time2 = 583;

	// 11:19 AM, 12:47 PM
	int dep_time3 = 679, dep_time4 = 767;

	// 2:00 PM, 3:45 PM
	int dep_time5 = 840, dep_time6 = 945;

	// 7:00 PM, 9:45 PM
	int dep_time7 = 1140, dep_time8 = 1305;

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

	total_desired_time = hrs * 60 + mins;

	printf("Closest departure time is ");

	// Finding the closest departure time between each pair
	if (total_desired_time <= (dep_time1 + (dep_time2 - dep_time1) / 2))
	{
		printf("8:00 a.m., arriving at 10:16 a.m.\n");
	}
	else if (total_desired_time <= (dep_time2 + (dep_time3 - dep_time2) / 2))
	{
		printf("9:43 a.m., arriving at 11:52 a.m.\n");
	}
	else if (total_desired_time <= (dep_time3 + (dep_time4 - dep_time3) / 2))
	{
		printf("11:19 a.m., arriving at 1:31 p.m.\n");
	}
	else if (total_desired_time <= (dep_time4 + (dep_time5 - dep_time4) / 2))
	{
		printf("12:47 p.m., arriving at 3:00 p.m.\n");
	}
	else if (total_desired_time <= (dep_time5 + (dep_time6 - dep_time5) / 2))
	{
		printf("2:00 p.m., arriving at 4:08 p.m.\n");
	}
	else if (total_desired_time <= (dep_time6 + (dep_time7 - dep_time6) / 2))
	{
		printf("3:45 p.m., arriving at 5:55 p.m.\n");
	}
	else if (total_desired_time <= (dep_time7 + (dep_time8 - dep_time7) / 2))
	{
		printf("7:00 p.m., arriving at 9:20 p.m.\n");
	}
	else
	{
		printf("9:45 p.m., arriving at 11:58 p.m.\n");
	}

	return 0;
}
