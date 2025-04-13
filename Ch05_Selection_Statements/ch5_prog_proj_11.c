/*
 * ch5_prog_proj_11.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 11: English word for a two-digit number

#include <stdio.h>

int main(void)
{
	int units, tens, num;

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	tens = num / 10;
	units = num % 10;

	printf("You entered the number ");

	if(num == 0)
	{
		printf("zero");
	}
	else if(num >= 10 && num <= 19)
	{
		switch(num)
		{
		case 10: printf("ten"); break;
		case 11: printf("eleven"); break;
		case 12: printf("twelve"); break;
		case 13: printf("thirteen"); break;
		case 14: printf("fourteen"); break;
		case 15: printf("fifteen"); break;
		case 16: printf("sixteen"); break;
		case 17: printf("seventeen"); break;
		case 18: printf("eighteen"); break;
		case 19: printf("nineteen"); break;
		}
	}
	else
	{
		switch(tens)
		{
		case 2: printf("twenty"); break;
		case 3: printf("thirty"); break;
		case 4: printf("forty"); break;
		case 5: printf("fifty"); break;
		case 6: printf("sixty"); break;
		case 7: printf("seventy"); break;
		case 8: printf("eighty"); break;
		case 9: printf("ninety"); break;
		}

		//if(tens && units)
			//printf("-");

		switch(units)
		{
		case 1: printf("-one"); break;
		case 2: printf("-two"); break;
		case 3: printf("-three"); break;
		case 4: printf("-four"); break;
		case 5: printf("-five"); break;
		case 6: printf("-six"); break;
		case 7: printf("-seven"); break;
		case 8: printf("-eight"); break;
		case 9: printf("-nine"); break;
		}
	}

	printf(".\n");

	return 0;
}
