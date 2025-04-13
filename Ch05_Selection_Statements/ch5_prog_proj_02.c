/*
 * ch5_prog_proj_02.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 2: Time conversion

// Solution 1 (Mine)
#include <stdio.h>

#define AM 1
#define PM 2

int main(void)
{
	int hr_24form, mins, hr_12form, meridiem;

	printf("Enter a 24-hour time: ");
	scanf("%d :%d", &hr_24form, &mins);

	// AM Part: 00:00/12:00 AM -> 11:59/11:59 AM
	// PM Part: 12:00/12:00 PM -> 23:59/11:59 PM

	if (hr_24form < 12) // AM: 00:00 -> 11:59
	{
		meridiem = AM;

		// [01]:00->[11]:59 (same as 24-hour), [00]:00->[00]:59 (+12)
		hr_12form = (hr_24form) ? hr_24form : 12;
	}
	else // PM: 12:00 -> 23:59
	{
		meridiem = PM;

		// [13]:00->[23]:59 (-12), [12]:00->[12]:59 (same as 24-hour)
		hr_12form = (hr_24form > 12) ? hr_24form - 12 : 12;
	}

	printf("Equivalent 12-hour time: %d:%.2d ", hr_12form, mins);

	switch(meridiem)
	{
        case AM: printf("AM\n"); break;
        case PM: printf("PM\n"); break;
	}

	return 0;
}

// Solution 2 (Author)
// http://knking.com/books/c2/answers/c5.html
