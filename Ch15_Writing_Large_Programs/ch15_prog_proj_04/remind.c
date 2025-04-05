/*
 * remind.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: One-month remainder list

#include <stdio.h>
#include <string.h>
#include "readline.h"
#define MAX_REMIND 50 // maximum number of reminders
#define MSG_LEN 60    // max length of reminder message

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + 3];
	char day_str[3], msg_str[MSG_LEN + 1];
	int  day, i, j, num_remind = 0;

	for(;;)
	{
		if(num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder: ");
		scanf("%2d", &day);

		if(day == 0)
		{
			break;
		}

		sprintf(day_str, "%2d", day);
		read_line(msg_str, MSG_LEN);

		for(i = 0; i < num_remind; i++)
		{
			if(strcmp(day_str, reminders[i]) < 0)
				break;
		}

		for(j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);
		num_remind++;
	}

	printf("\nDay Reminder\n");
	for(i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}
