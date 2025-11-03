/*
 * sum.c
 *
 *  Created on: Dec 18, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Adding up command-line arguments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sum = 0, i = 0;

	while(++i < argc)
		sum += atoi(argv[i]);

	printf("Total: %d\n", sum);

	return 0;
}
