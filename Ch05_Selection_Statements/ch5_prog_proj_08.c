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
	int hh_desired, mm_desired, desired_time;
	int hh_dep, mm_dep, closest_dep_time;
	int hh_arrive, mm_arrive, arrive_time;
	int curr_time_diff; // Computing the current time difference for each departure time
	int min_time_diff = 1440; // Assuming the start value is 24 hr diff (max diff)
	char dep_meridiem, arrive_meridiem; // a.m or p.m?

	// Reading user input (desired time)
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hh_desired, &mm_desired);

	// Convert the desired time from hh:mm format to total minutes format
	desired_time = hh_desired * 60 + mm_desired;

	// Finding the closest time to our desired time according to the given table
	// 08:00 a.m.
	curr_time_diff = 480 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 480; // 08:00 a.m.
		arrive_time = 616; // 10:16 a.m.
	}

	// 09:43 a.m.
	curr_time_diff = 583 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 583; //  09:43 a.m.
		arrive_time = 712; // 11:52 a.m.
	}

	// 11:19 a.m.
	curr_time_diff = 679 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign
	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 679; // 11:19 a.m.
		arrive_time = 811; // 01:31 p.m.
	}

	// 12:47 p.m.
	curr_time_diff = 767 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 767; // 12:47 p.m.
		arrive_time = 900; // 03:00 p.m.
	}

	// 02:00 p.m.
	curr_time_diff = 840 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 840; // 02:00 p.m.
		arrive_time = 968; // 04:08 p.m.
	}

	// 03:45 p.m.
	curr_time_diff = 945 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 945; // 03:45 p.m.
		arrive_time = 1075; // 05:55 p.m.
	}

	// 07:00 p.m.
	curr_time_diff = 1140 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 1140; // 07:00 p.m.
		arrive_time = 1280; // 09:20 p.m.
	}

	// 09:45 p.m.
	curr_time_diff = 1305 - desired_time; // +ve or -ve
	curr_time_diff = (curr_time_diff > 0) ? curr_time_diff : -curr_time_diff; // fix sign

	if(min_time_diff > curr_time_diff)
	{
		min_time_diff = curr_time_diff; // update new min diff
		closest_dep_time = 1305; // 09:45 p.m.
		arrive_time = 1438; // 11:58 p.m.
	}

	// Convert back the departure time from minutes format to hh:mm format
	hh_dep = closest_dep_time / 60;
	mm_dep = closest_dep_time % 60;

	// Convert from 24-hr format to 12-hr format with meridiem
	if(hh_dep == 0) // Midnight
	{
		hh_dep += 12;
		dep_meridiem = 'a';
	}
	else if(hh_dep >= 12)
	{
		if(hh_dep > 12)
			hh_dep -= 12;

		dep_meridiem = 'p';
	}
	else
	{
		dep_meridiem = 'a';
	}

	// Convert back the arrival time from minutes format to hh:mm format
	hh_arrive = arrive_time / 60;
	mm_arrive = arrive_time % 60;

	// Convert from 24-hr format to 12-hr format with meridiem
	if(hh_arrive == 0) // Midnight
	{
		hh_arrive += 12;
		arrive_meridiem = 'a';
	}
	else if(hh_arrive >= 12)
	{
		if(hh_arrive > 12)
			hh_arrive -= 12;

		arrive_meridiem = 'p';
	}
	else
	{
		arrive_meridiem = 'a';
	}


	printf("Closest departure time is %d:%.2d %c.m., ", hh_dep, mm_dep, dep_meridiem);
	printf("arriving at %d:%.2d %c.m.", hh_arrive, mm_arrive, arrive_meridiem);

	return 0;
}

