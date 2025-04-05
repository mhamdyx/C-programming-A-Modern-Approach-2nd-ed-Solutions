/*
 * ch3_prog_proj_04.c
 *
 *  Created on: Mar 19, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Display telephone number

#include <stdio.h>

int main(void)
{
	int area_code, central_office_code, line_number;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &area_code, &central_office_code, &line_number);

	printf("You entered %03d.%03d.%04d\n", area_code, central_office_code,
			line_number);

	return 0;
}
