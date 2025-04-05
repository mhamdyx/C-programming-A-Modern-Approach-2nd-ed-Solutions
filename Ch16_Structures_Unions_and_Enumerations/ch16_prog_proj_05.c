/*
 * ch16_prog_proj_05.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Daily Flights

#include <stdio.h>

struct flight
{
	int departure_time;
	int arrival_time;
};

int from_24_hr_time_to_mins(int hours, int minutes);
void from_mins_to_24_hr_time(int total_minutes, int *hours, int *minutes);
void from_24_to_12_hr_time(int *hours, int *minutess, char *meridiem);

int main(void)
{
	int desired_time, best_time_index = -1, time_range;
	int hh_desired, mm_desired, hh_dep, mm_dep, hh_arrive, mm_arrive;
	char dep_meridiem, arrive_meridiem;

	// Computing time in terms of total minutes starting from 00:00
	struct flight daily_flights[8] =
	{
			{480, 616},   // 08:00 a.m. - 10:16 a.m.
			{583, 712},   // 09:43 a.m. - 11:52 a.m.
			{679, 811},   // 11:19 a.m. - 01:31 p.m.
			{767, 900},   // 12:47 p.m. - 03:00 p.m.
			{840, 968},   // 02:00 p.m. - 04:08 p.m.
			{945, 1075},  // 03:45 p.m. - 05:55 p.m.
			{1140, 1280}, // 07:00 p.m. - 09:20 p.m.
			{1305, 1438}  // 09:45 p.m. - 11:58 p.m.
	};

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hh_desired, &mm_desired);

	desired_time = from_24_hr_time_to_mins(hh_desired, mm_desired);

	for(int i = 0; i < 7; i++)
	{
		time_range = daily_flights[i].departure_time +
				(daily_flights[i + 1].departure_time - daily_flights[i].departure_time) / 2;

		if(desired_time > daily_flights[i].departure_time && desired_time <= time_range)
		{
			best_time_index = i;
			break;
		}
	}

	if(best_time_index == -1)
	{
		if(desired_time <= 172) // 2:52 am --> (9:45 pm < 2:52 am < 8:00 am)
		{
			best_time_index = 7;
		}
		else
		{
			best_time_index = 0;
		}
	}

	// Calculating departure time
	from_mins_to_24_hr_time(daily_flights[best_time_index].departure_time,
			&hh_dep, &mm_dep);

	from_24_to_12_hr_time(&hh_dep, &mm_dep, &dep_meridiem);

	// Calculating arrival time
	from_mins_to_24_hr_time(daily_flights[best_time_index].arrival_time,
				&hh_arrive, &mm_arrive);

	from_24_to_12_hr_time(&hh_arrive, &mm_arrive, &arrive_meridiem);

	printf("Closest departure time is %d:%.2d %c.m., ", hh_dep, mm_dep, dep_meridiem);
	printf("arriving at %d:%.2d %c.m.", hh_arrive, mm_arrive, arrive_meridiem);

	return 0;
}


// Takes 24 hr format and returns its worth of minutes starting from midnight
int from_24_hr_time_to_mins(int hours, int minutes)
{
	return hours * 60 + minutes;
}

// Takes a total number of minutes counted from midnight and returns a 24 hr format
void from_mins_to_24_hr_time(int total_minutes, int *hours, int *minutes)
{
	*hours = total_minutes / 60;
	*minutes = total_minutes % 60;
}

// Takes a total number of minutes counted from midnight and returns a 12 hr format
void from_24_to_12_hr_time(int *hours, int *minutess, char *meridiem)
{
	if(*hours == 0) // Midnight
	{
		(*hours) += 12;
		*meridiem = 'a';
	}
	else if(*hours >= 12)
	{
		if(*hours > 12)
			(*hours) -= 12;

		*meridiem = 'p';
	}
	else
	{
		*meridiem = 'a';
	}
}
