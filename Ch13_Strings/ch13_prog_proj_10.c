/*
 * ch13_prog_proj_10.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 10: First name and Last name

#include <stdio.h>
#include <string.h>
#define NAME_LEN 100 // You will not have to write a bio for that name :D

void reverse_name(char *name);
void read_name(char *name, int name_len);

int main(void)
{
	//char last_ch, first_ch;
	char name[NAME_LEN];

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

	while(*last_name++ != ' '); // Searching for the first letter in last name

	strcat(strcpy(name, last_name), first_name);
}



void read_name(char *name, int name_len)
{
	int name_count = 0;

	while((name[name_count] = getchar()) == ' '); // Skipping initial spaces

	// Read first name
	while((name[++name_count] = getchar()) != ' ' && name_count < name_len);
	name_count++;


	while((name[name_count] = getchar()) == ' '); // Skipping what's more than one space

	// Read last name
	do
	{
		name[++name_count] = getchar();
	} while(name[name_count] && name[name_count] != '\n'
			&& name[name_count] != ' ' && name_count < name_len);

	name[name_count] = '\0';
}
