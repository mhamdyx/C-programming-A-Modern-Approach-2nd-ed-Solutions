/*
 * ch13_prog_proj_07.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: English word for a two-digit number

#include <stdio.h>

int main(void)
{
	int units, tens, num;
	char *tens_str[] =
	{
		"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};

	char *units_str[] =
	{
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	char *special_num_str[] =
	{
		"ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	tens = num / 10;
	units = num % 10;

	printf("You entered the number ");

	if (num < 10)
		printf("%s", units_str[num]);
	else if (num >= 10 && num <= 19)
		printf("%s", special_num_str[units]);
	else
	{
		if (tens)
			printf("%s", tens_str[tens - 2]);

		if (units && num > 19)
			printf("-%s", units_str[units]);
	}

	printf(".\n");

	return 0;
}
