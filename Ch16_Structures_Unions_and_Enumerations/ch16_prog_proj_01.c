/*
 * ch16_prog_proj_01.c
 *
 *  Created on: Mar 12, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: International telephone calls

#include <stdio.h>
#define NUM_CODES 36

struct dialing_code
{
	char *country;
	int code;
};

const struct dialing_code country_codes[NUM_CODES] =
{
	    {"Argentina",            54}, {"Bangladesh",     889},
	    {"Brazil",               55}, {"Burma (Myanmar)", 95},
	    {"China",                86}, {"Colombia",        57},
	    {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
	    {"Ethiopia",            251}, {"France",          33},
	    {"Germany",              49}, {"India",           91},
	    {"Indonesia",            62}, {"Iran",            98},
	    {"Italy",                39}, {"Japan",           81},
	    {"Mexico",               52}, {"Nigeria",        234},
	    {"Pakistan",             92}, {"Philippines",     63},
	    {"Poland",               48}, {"Russia",           7},
	    {"South Africa",         27}, {"South Korea",     82},
	    {"Spain",                34}, {"Sudan",          249},
	    {"Thailand",             66}, {"Turkey",          90},
	    {"Ukraine",             380}, {"United Kingdom",  44},
	    {"United States",         1}, {"Vietnam",         84}
};

int lookup_code(int code);

int main(void)
{
	int code, index;
	
    printf("Please, enter an international dialing code: ");
	scanf("%d", &code);

	index = lookup_code(code);

	if(index == -1)
	{
		printf("Invalid code!\n");
	}
	else
	{
		printf("Corresponding country: %s\n", country_codes[index].country);
	}

	return 0;
}

int lookup_code(int code)
{
	for(int i = 0; i < NUM_CODES; i++)
	{
		if(country_codes[i].code == code)
			return i;
	}

	return -1;
}
