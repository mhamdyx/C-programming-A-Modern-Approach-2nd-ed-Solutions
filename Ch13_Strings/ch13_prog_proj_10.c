/*
 * ch13_prog_proj_10.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 10: First name and Last name

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 99 // You will not have to write a bio for that name :D

void reverse_name(char *name);
void read_name(char *name, int name_len);

int main(void)
{
	char name[NAME_LEN + 1];

	printf("Enter a first and last name: ");
	read_name(name, NAME_LEN);
	reverse_name(name);

	printf("%s\n", name);

	return 0;
}

void reverse_name(char *name)
{
	char first_name[4] = ",  ";
	first_name[2] = *name;
	char *last_name = name;

	while (*last_name++ != ' '); // Searching for the first letter in last name

	strcat(strcpy(name, last_name), first_name);
}

void read_name(char *name, int name_len)
{
	int i = 0;

	while (isspace(name[i] = getchar())); // Skipping initial spaces
	i++;

	// Read first name
	while (i < name_len)
		if (isspace(name[i++] = getchar()))
			break;

	while (isspace(name[i] = getchar())); // Skipping intermediate spaces
	i++;

	// Read last name
	while (i < name_len)
		if (isspace(name[i++] = getchar()))
			break;

	// Detect end of line and skip white-spaces at the end
	if (name[--i] != '\n') // last written white-space character
		while (getchar() != '\n');

	name[i] = '\0'; // convert to string
}
