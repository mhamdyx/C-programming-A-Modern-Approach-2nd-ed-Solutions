/*
 * ch2_exercises.c
 *
 *  Created on: Apr 5, 2025
 *      Author: Mahmoud Hamdy
 */


// Q1

/*
 * I do get a warning saying: control reaches end of non-void function
 *
 * To make it go away, simply add return 0; at the end of the program
 *
 */

//----------------------------------
// Q2

/*
 * a) Directives:
 *    #include <stdio.h>
 *
 *    Statements:
 *    printf("Parkinson's Law:\nWork expands so as to ");
 *    printf("fill the time\n");
 *    printf("available for its completion.\n");
 *    return 0;
 *
 * b) Output:
 *    Parkinson's Law:
 *    Work expands so as to fill the time
 *    available for its completion.
 *
 */

//----------------------------------
// Q3
/*
#include<stdio.h>

int main(void)
{
	int height = 8, length = 12, width = 10, volume;

	height = 8;
	length = 12;
	width = 10;
	volume = height * length * width;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);

	return 0;
}
*/

//----------------------------------
// Q4
/*
#include <stdio.h>

int main(void)
{
	int a, b, c, d, e;
	float v, w, x, y, z;

	printf("%d %d %d %d %d\n", a, b, c, d, e);
	printf("%f %f %f %f %f\n", v, w, x, y, z);

	return 0;
}
*/

/*
 * There is no pattern to the output, just random values
 */

//----------------------------------
// Q5

/*
 * a) Illegal: identifiers must start with letters or underscores only
 *
 * b) Legal
 *
 * c) Legal
 *
 * d) Legal
 *
 */

//----------------------------------
// Q6

/*
 * The unnecessary repetition to adjacent underscores will affect
 * the readability of the variable
 *
 */

//----------------------------------
// Q7

/*
 * a) Keyword
 *
 * b) Not a keyword
 *
 * c) Not a keyword
 *
 * d) Not a keyword
 *
 * e) Keyword
 *
 */

//----------------------------------
// Q8

/*
 * answer=(3*q-p*p)/3;
 *
 * Tokens are:
 * answer, =, (, 3, *, q, -, p, *, p, ), /, 3, ;
 *
 * Identifiers: answer, q, p, p (+4)
 * Operators and punctuation: =, (, *, -, *, ), /, ; (+8)
 * Constants: 3, 3 (+2)
 *
 *
 * Number of tokens = 4 + 8 + 2 = 14
 *
 */

//----------------------------------
// Q9

/*
 * answer = (3 * q - p * p) / 3;
 *
 */

//----------------------------------

// Q10

/*
 * While spaces are allowed between different tokens, the essential
 * spaces are the spaces that will make the program fail if they
 * are omitted.
 * For example:
 * int main (Space between keyword and and main)
 * int height (Space between keyword and variable identifier)
 * return 0 (Space between keyword and constant)
 *
 */



