/*
 * ch16_prog_proj_05.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Daily Flights

#include <stdio.h>
#define NUM_TIMES 8

struct flight
{
	int dep_time;
	int arv_time;
};

int from_24_hr_time_to_mins(int hours, int minutes);
int from_12_hr_time_to_mins(int hours, int minutes, char meridiem);
void from_mins_to_24_hr_time(int total_minutes, int *hours, int *minutes);
void from_24_to_12_hr_time(int *hours, char *meridiem);

int main(void)
{
	int hr_24form, mins, total_desired_time, i;
	int dep_hr, dep_min, arv_hr, arv_min;
	char dep_meridiem, arv_meridiem;

	// Computing time in terms of total minutes starting from 00:00
	struct flight daily_flights[NUM_TIMES] =
	{
			// 08:00 a.m. - 10:16 a.m.
			{from_12_hr_time_to_mins(8, 0, 'a'), from_12_hr_time_to_mins(10, 16, 'a')},
			// 09:43 a.m. - 11:52 a.m.
			{from_12_hr_time_to_mins(9, 43, 'a'), from_12_hr_time_to_mins(11, 52, 'a')},
			// 11:19 a.m. - 01:31 p.m.
			{from_12_hr_time_to_mins(11, 19, 'a'), from_12_hr_time_to_mins(1, 31, 'p')},
			// 12:47 p.m. - 03:00 p.m.
			{from_12_hr_time_to_mins(12, 47, 'p'), from_12_hr_time_to_mins(3, 0, 'p')},
			// 02:00 p.m. - 04:08 p.m.
			{from_12_hr_time_to_mins(2, 0, 'p'), from_12_hr_time_to_mins(4, 8, 'p')},
			// 03:45 p.m. - 05:55 p.m.
			{from_12_hr_time_to_mins(3, 45, 'p'), from_12_hr_time_to_mins(5, 55, 'p')},
			// 07:00 p.m. - 09:20 p.m.
			{from_12_hr_time_to_mins(7, 0, 'p'), from_12_hr_time_to_mins(9, 20, 'p')},
			// 09:45 p.m. - 11:58 p.m.
			{from_12_hr_time_to_mins(9, 45, 'p'), from_12_hr_time_to_mins(11, 58, 'p')}
	};

	printf("Enter a 24-hour time: ");
	scanf("%d :%d", &hr_24form, &mins);

	total_desired_time = from_24_hr_time_to_mins(hr_24form, mins);

	printf("Closest departure time is ");

	// Finding the closest departure time between each pair
	for (i = 0; i < NUM_TIMES - 1; i++)
	{
		if (total_desired_time <= (daily_flights[i].dep_time + (daily_flights[i + 1].dep_time - daily_flights[i].dep_time) / 2))
			break;
	}

	from_mins_to_24_hr_time(daily_flights[i].dep_time, &dep_hr, &dep_min);
	from_24_to_12_hr_time(&dep_hr, &dep_meridiem);

	from_mins_to_24_hr_time(daily_flights[i].arv_time, &arv_hr, &arv_min);
	from_24_to_12_hr_time(&arv_hr, &arv_meridiem);

	printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
			dep_hr, dep_min, dep_meridiem, arv_hr, arv_min, arv_meridiem);

	return 0;
}

int from_24_hr_time_to_mins(int hours, int minutes)
{
	return hours * 60 + minutes;
}

int from_12_hr_time_to_mins(int hours, int minutes, char meridiem)
{
	if (hours == 12 && meridiem == 'a')
		hours = 0;
	else if (hours < 12 && meridiem == 'p')
		hours += 12;

	return from_24_hr_time_to_mins(hours, minutes);
}

void from_mins_to_24_hr_time(int total_minutes, int *hours, int *minutes)
{
	*hours = total_minutes / 60;
	*minutes = total_minutes % 60;
}

void from_24_to_12_hr_time(int *hours, char *meridiem)
{
	if (*hours == 0) // Midnight
	{
		(*hours) += 12;
		*meridiem = 'a';
	}
	else if (*hours >= 12)
	{
		if (*hours > 12)
			(*hours) -= 12;

		*meridiem = 'p';
	}
	else
		*meridiem = 'a';
}
