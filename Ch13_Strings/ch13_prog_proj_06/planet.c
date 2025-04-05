/*
 * planet.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: Checking Planet Names (Improved)

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 9

bool same_letters(char *word1, char *word2);

int main(int argc, char *argv[])
{
	char *planets[] =
	{
			"Mercury", "Venus", "Earth",
			"Mars", "Jupiter", "Saturn",
			"Uranus", "Neptune", "Pluto"
	};


	int i, j;

	for(i = 1; i < argc; i++)
	{
		for(j = 0; j < NUM_PLANETS; j++)
		{
			if(same_letters(argv[i], planets[j]))
			{
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}

		if(j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}

	return 0;
}


bool same_letters(char *word1, char *word2)
{
	while(*word1 && *word2)
	{
		if(toupper(*word1++) != toupper(*word2++)) // Words don't match
			return false;
	}

	if(*word1 != *word2) // One word is shorter/longer than the other
		return false;

	return true;
}
