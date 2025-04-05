/*
 * ch21_prog_proj_01.c
 *
 *  Created on: May 23, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: offsetof

#include <stdio.h>
#include <stddef.h>

struct s
{
	char a;
	int b[2];
	float c;
};

int main(void)
{
	struct s example;

	printf("Size of a = %d\n", sizeof(example.a));
	printf("Offset of a = %d\n\n", offsetof(struct s, a));

	printf("Size of b = %d\n", sizeof(example.b));
	printf("Offset of b = %d\n\n", offsetof(struct s, b));

	printf("Size of c = %d\n", sizeof(example.c));
	printf("Offset of c = %d\n\n", offsetof(struct s, c));

	printf("Size of the whole structure = %d\n", sizeof(struct s));

	return 0;
}

/*
 * From the output, we get that there is a hole of size 3 bytes lies between member a
 * and member b of the structure
 * 
 */
