/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

// remind2.c (Section 17.2, page 418)
// Printing a One-Month Reminder List

/*
 * ch17_prog_proj_07.c
 *
 *  Created on: Apr 9, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: remind2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_REMIND 50 // maximum number of reminders
#define MSG_LEN 60    // max length of reminder message

struct vstring
{
	int len;
	char chars[]; // flexible array member (c99 only)
};

int read_line(char str[], int n);

int main(void)
{
	struct vstring *reminders[MAX_REMIND];
	char day_str[3], msg_str[MSG_LEN + 1];
	int  day, i, j, num_remind = 0;

	for (;;)
	{
		if (num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder: ");
		scanf("%2d", &day);

		if (day == 0)
			break;

		sprintf(day_str, "%2d", day);
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]->chars) < 0)
				break;

		for (j = num_remind; j > i; j--)
			reminders[j] = reminders[j - 1];

		reminders[i] = malloc(sizeof(struct vstring) + 2 + strlen(msg_str) + 1);
		if (reminders[i] == NULL)
		{
			printf("-- No space left --\n");
			break;
		}

		strcpy(reminders[i]->chars, day_str);
		strcat(reminders[i]->chars, msg_str);
		reminders[i]->len = strlen(reminders[i]->chars);
		num_remind++;
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]->chars);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';

	return i;
}
