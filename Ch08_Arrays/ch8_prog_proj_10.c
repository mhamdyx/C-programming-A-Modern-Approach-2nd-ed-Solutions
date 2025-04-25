/*
 * ch8_prog_proj_10.c
 *
 *  Created on: Apr 25, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 10: Daily Flights (modified)

#include <stdio.h>

#define NUM_TIMES 8

int main(void)
{
	int hr_24form, mins, total_desired_time, i;

	// 8:00 AM, 9:43 AM, 11:19 AM, 12:47 PM, 2:00 PM, 3:45 PM, 7:00 PM, 9:45 PM
	int dep_time[NUM_TIMES] = {480, 583, 679, 767, 840, 945, 1140, 1305};

	// 10:16 AM, 11:52 AM, 1:31 PM, 3:00 PM, 4:08 PM, 5:55 PM, 9:20 PM, 11:58 PM
	int arv_time[NUM_TIMES] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

	int dep_hr, dep_min, arv_hr, arv_min;
	char dep_meridiem, arv_meridiem;

	printf("Enter a 24-hour time: ");
	scanf("%d :%d", &hr_24form, &mins);

	total_desired_time = hr_24form * 60 + mins;

	printf("Closest departure time is ");

	// Finding the closest departure time between each pair
	for (i = 0; i < NUM_TIMES - 1; i++)
	{
		if (total_desired_time <= (dep_time[i] + (dep_time[i + 1] - dep_time[i]) / 2))
			break;
	}

	dep_min = dep_time[i] % 60;
	dep_hr = dep_time[i] / 60;

	if (dep_hr < 12 || dep_hr == 24)
	{
		dep_hr = (dep_hr == 24) ? 12 : dep_hr;
		dep_meridiem = 'a';
	}
	else // dep_hr >= 12 and < 24
	{
		dep_hr = (dep_hr == 12) ? dep_hr : dep_hr - 12;
		dep_meridiem = 'p';
	}

	arv_min = arv_time[i] % 60;
	arv_hr = arv_time[i] / 60;

	if (arv_hr < 12 || arv_hr == 24)
	{
		arv_hr = (arv_hr == 24) ? 12 : arv_hr;
		arv_meridiem = 'a';
	}
	else // arv_hr >= 12 and < 24
	{
		arv_hr = (arv_hr == 12) ? arv_hr : arv_hr - 12;
		arv_meridiem = 'p';
	}


	printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
			dep_hr, dep_min, dep_meridiem, arv_hr, arv_min, arv_meridiem);

	return 0;
}
