/*
 * ch5_prog_proj_08.c
 *
 *  Created on: Nov 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 8: Daily Flights

#include <stdio.h>

int main(void)
{
	int hr_24form, mins, total_desired_time;

	// 8:00 AM, 9:43 AM
	int dep_time1 = 480, dep_time2 = 583;

	// 11:19 AM, 12:47 PM
	int dep_time3 = 679, dep_time4 = 767;

	// 2:00 PM, 3:45 PM
	int dep_time5 = 840, dep_time6 = 945;

	// 7:00 PM, 9:45 PM
	int dep_time7 = 1140, dep_time8 = 1305;

	printf("Enter a 24-hour time: ");
	scanf("%d :%d", &hr_24form, &mins);

	total_desired_time = hr_24form * 60 + mins;

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
