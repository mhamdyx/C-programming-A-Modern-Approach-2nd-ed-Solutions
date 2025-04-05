/*
 * ch11_prog_proj_02.c
 *
 *  Created on: Nov 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Daily Flights

#include <stdio.h>
#include <math.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
int from_24_hr_time_to_mins(int hours, int minutes);
int from_12_hr_time_to_mins(int hours, int minutes, char meridiem);
void from_mins_to_24_hr_time(int total_minutes, int *hours, int *minutes);
void from_24_to_12_hr_time(int *hours, int *minutess, char *meridiem);

int main(void)
{
	int desired_time, departure_time, arrival_time;
	int hh_desired, mm_desired, hh_dep, mm_dep, hh_arrive, mm_arrive;
	char dep_meridiem, arrive_meridiem;


	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hh_desired, &mm_desired);

	// From 24-hours time to total minutes starting from midnight
	desired_time = from_24_hr_time_to_mins(hh_desired, mm_desired);

	// Closest flight algorithm
	find_closest_flight(desired_time, &departure_time, &arrival_time);

	// Getting the nearest departure time back to its original format
	from_mins_to_24_hr_time(departure_time, &hh_dep, &mm_dep);
	from_24_to_12_hr_time(&hh_dep, &mm_dep, &dep_meridiem);

	// Getting the nearest arrival time back to its original format
	from_mins_to_24_hr_time(arrival_time, &hh_arrive, &mm_arrive);
	from_24_to_12_hr_time(&hh_arrive, &mm_arrive, &arrive_meridiem);

	printf("Closest departure time is %d:%.2d %c.m., ", hh_dep, mm_dep, dep_meridiem);
	printf("arriving at %d:%.2d %c.m.", hh_arrive, mm_arrive, arrive_meridiem);

	return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
	int best_time_index = -1, time_range;

	// Computing time in terms of total minutes starting from 00:00
	int dep_time[8] =
	{
		from_12_hr_time_to_mins(8, 0, 'a'),   //480,  // 08:00 a.m.
		from_12_hr_time_to_mins(9, 43, 'a'),  //583,  // 09:43 a.m.
		from_12_hr_time_to_mins(11, 19, 'a'), //679,  // 11:19 a.m.
		from_12_hr_time_to_mins(12, 47, 'p'), //767,  // 12:47 p.m.
		from_12_hr_time_to_mins(2, 0, 'p'),   //840,  // 02:00 p.m.
		from_12_hr_time_to_mins(3, 45, 'p'),  //945,  // 03:45 p.m.
		from_12_hr_time_to_mins(7, 0, 'p'),   //1140, // 07:00 p.m.
		from_12_hr_time_to_mins(9, 45, 'p')   //1305  // 09:45 p.m.
	};

	int arrive_time[8] =
	{
		from_12_hr_time_to_mins(10, 16, 'a'), //or 616,  // 10:16 a.m.
		from_12_hr_time_to_mins(11, 52, 'a'), //or 712,  // 11:52 a.m.
		from_12_hr_time_to_mins(1, 31, 'p'),  //or 811,  // 01:31 p.m.
		from_12_hr_time_to_mins(3, 0, 'p'),   //or 900,  // 03:00 p.m.
		from_12_hr_time_to_mins(4, 8, 'p'),   //or 968,  // 04:08 p.m.
		from_12_hr_time_to_mins(5, 55, 'p'),  //or 1075, // 05:55 p.m.
		from_12_hr_time_to_mins(9, 20, 'p'),  //or 1280, // 09:20 p.m.
		from_12_hr_time_to_mins(11, 58, 'p')  //or 1438  // 11:58 p.m.
	};


	for(int i = 0; i < 7; i++)
	{
		time_range = dep_time[i] + (dep_time[i + 1] - dep_time[i]) / 2;
		if(desired_time > dep_time[i] && desired_time <= time_range)
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

	*departure_time = dep_time[best_time_index];
	*arrival_time = arrive_time[best_time_index];
}

int from_24_hr_time_to_mins(int hours, int minutes)
{
	return hours * 60 + minutes;
}

int from_12_hr_time_to_mins(int hours, int minutes, char meridiem)
{
	if(hours == 12 && meridiem == 'a')
	{
		hours = 0;
	}
	else if(hours < 12 && meridiem == 'p')
	{
		hours += 12;
	}

	return from_24_hr_time_to_mins(hours, minutes);
}

void from_mins_to_24_hr_time(int total_minutes, int *hours, int *minutes)
{
	*hours = total_minutes / 60;
	*minutes = total_minutes % 60;
}

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
