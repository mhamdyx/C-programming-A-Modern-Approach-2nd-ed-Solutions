/*
 * ch6_prog_proj_10.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 10: Comparing Dates

#include <stdio.h>

int main(void)
{
	int input_mm, input_dd, input_yy;
	int earliest_mm, earliest_dd, earliest_yy;

	handle_eclipse_terminal_emulator_bug();

	printf("Enter a date (mm/dd/yy): ");
	scanf("%d /%d /%d", &earliest_mm, &earliest_dd, &earliest_yy);

	do
	{
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d /%d /%d", &input_mm, &input_dd, &input_yy);

		// Naive condition (assuming 0/0/0 is the only wrong input)
		if(input_mm == 0 && input_dd == 0 && input_yy == 0)
			break;

		if((input_yy < earliest_yy) ||
		    (input_yy == earliest_yy && input_mm < earliest_mm) ||
		    (input_yy == earliest_yy && input_mm == earliest_mm && input_dd < earliest_dd))
		{
			earliest_yy = input_yy;
			earliest_mm = input_mm;
			earliest_dd = input_dd;
		}

	} while(1);

	printf("%d/%d/%02d is the earliest date\n", earliest_mm, earliest_dd, earliest_yy);

	return 0;
}
