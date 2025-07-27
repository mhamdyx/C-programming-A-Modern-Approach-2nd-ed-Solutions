/*
 * ch22_exercises.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Mahmoud Hamdy
 */


// Q1

/*
 * (a) Binary data
 *
 * (b) Text data
 *
 * (c) Text data
 *
 * (d) Binary data
 *
 */


//----------------------------------

// Q2

/*
 * (a) "rb+" or "r+b"
 *
 * (b) "a"
 *
 * (c) "rb"
 *
 * (d) "r"
 *
 */

//----------------------------------

// Q3

/*
 * There is no guarantee that calling fopen will succeed.
 * If fopen fails to open the file the if-condition is bypassed.
 * The error is in fclose that is outside the if-condition, because
 * it will be called regardless the outcome of fopen. If fopen failed,
 * fclose would fail because fp would be NULL. This would lead to
 * undefined behavior (and potentially a program crash).
 *
 * To fix this situation, we should either include the calling of fclose
 * inside the if-statement block or add an else clause to report to user
 * that fopen failed and terminate the program.
 *
 */

// Here are the possible fixes
//#define Q3_FIX1
//#define Q3_FIX2

#ifdef Q3_FIX1

FILE *fp;

if (fp = fopen(filename, "r"))
{
	// read characters until end-of-fle
	fclose(fp);
}

#elif Q3_FIX2

if (fp = fopen(filename, "r"))
{
	// read characters until end-of-fle
}
else
{
	printf("Error: can not open %s\n", filename);
	exit(EXIT_FAILURE);
}

fclose(fp);

#endif


//----------------------------------

// Q4

/*
 * Given %#012.5g
 * # --> Floating-point numbers always have the decimal point and
 * trailing zeros aren't removed from numbers printed with g
 *
 * 0 --> Numbers are padded with zeros up to the field width
 *
 * 12 -> Minimum field width (with padding for small numbers)
 *
 * .5 -> Precision = 5, and for g, it means:
 * Max number of significant digits to be printed
 *
 * g --> converts double value to either f or e (scientific notation)
 *
 * Criteria for g conversion:
 * e is chosen if the equivalent scientific notation (s.n) has
 * an exponent that is less than -4 or greater than or equal the
 * precision ( >= 5 in this case)
 *
 * f is chosen otherwise
 *
 *
 *
 * (a) 83.7361 ----> (s.n is 8.37361 x 10^1 --> f is chosen)
 *
 * There are 6 significant digits, so only 5 are chosen and we
 * approximate the fifth ----> 83.736 ---> Then we pad with zeros
 *
 *
 * Output: 00000083.736
 *
 *
 *
 * (b) 29748.6607 ---> (s.n is 2.97486607 x 10^4 ---> f is chosen)
 *
 * There are 9 significant digits, so only 5 are chosen and we
 * approximate the fifth ---> 29749 ---> Then we pad with zeros
 * and remember we keep the . (because of the #)
 *
 * Output: 00000029749.
 *
 *
 * (c) 1054932234.0 ---> (s.n is 1.054932234 x 10^9 --> e is chosen)
 *
 * There are 10 digits (in s.n), so only 5 are chosen and we
 * approximate the fifth --> 1.0549e+09 --> Then we pad with zeros
 *
 * Output: 001.0549e+09
 *
 *
 * (d) 0.0000235218 ---> (s.n is 2.35218 x 10^-5 ---> e is chosen)
 *
 * There are 6 digit (in s.n), so only 5 are chosen and we approximate
 * the fifth ---> 2.3522e-05 ---> Then we pad with zeros
 *
 * Output: 002.3522e-05
 *
 *
 */


// Useful test
/*

#include <stdio.h>

int main(void)
{
	double a = 83.7361;
	double b = 29748.6607;
	double c = 1054932234.0;
	double d = 0.0000235218;

	printf("%#012.5g\n", a);
	printf("%#012.5g\n", b);
	printf("%#012.5g\n", c);
	printf("%#012.5g\n", d);


	return 0;
}
*/


//----------------------------------

// Q5

/*
 * Both have the same effect, an integer with zero padding (if necessary).
 * We can use %.nd and %0nd interchangeably (where n can be any number)
 *
 */

//----------------------------------

// Q6

/*
 * printf((widget == 1) ? "%d widget" : "%d widgets", widget);
 *
 */


//----------------------------------

// Q7

/*
 * n = scanf("%d%f%d", &i, &x, &j);
 *
 * (a) 10 20 30\n
 *
 * 10 is read
 * space is skipped
 * 20 is read
 * space is skipped
 * 30 is read
 *
 * i = 10
 * x = 20.000000
 * j = 30
 * n = 3
 *
 *
 * (b) 1.0 2.0 3.0\n
 *
 * 1 is read and . is left for the next read
 * .0 is read
 * space is skipped
 * 2 is read and . is left for the next read
 *
 * i = 1
 * x = 0.000000
 * j = 2
 * n = 3
 *
 *
 * (c) 0.1 0.2 0.3\n
 *
 * 0 is read and . is left for the next read
 * .1 is read
 * space is skipped
 * 0 is read and . is left for the next read
 *
 * i = 0
 * x = 0.100000
 * j = 0
 * n = 3
 *
 *
 * (d) .1 .2 .3\n
 *
 * Reading mismatch (between input and specifier), so the function
 * will return
 *
 * i, x, j after the call have the same value as before the call
 * n = 0
 *
 */


//----------------------------------

// Q8

/*
 * They are not equivalent because "%1s" stores an additional null
 * character after storing the non-white-space character. " %c" just
 * stores the non-white-space character and nothing else after it.
 *
 */

//----------------------------------

// Q9

/*
 * (a) getch()
 *
 */



//----------------------------------

// Q10
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	int ch;

	if (argc != 3)
	{
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(source_fp)) != EOF)
	{
		if (putc(ch, dest_fp) == EOF)
		{
			fprintf(stderr, "Error during writing in %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
*/


//----------------------------------

// Q11

/*
 * The program would compile without an error because there is no
 * syntax error, but running the program is a different story as
 * the program will print ones in the output file due to the logical
 * error in the program. The equality operator (!=) has a higher
 * precedence than the assignment operator (=), so what happens first
 * is that getc(source_fp) gets compared with EOF. The result of this
 * expression is either true or false represented by the digits 1 or 0.
 *
 * As long as the condition is true, a one gets assigned to ch, which
 * will be written to the output file. Eventually the output file will
 * be full of ones until the input stream reach the EOF state.
 * (assuming no errors during writing)
 *
 */

//----------------------------------

// Q12

/*
 * There is a logical error. fgetc gets called twice, so the first
 * character in the while condition is different from the one in the
 * if condition. We are skipping almost half the characters in the
 * input stream. Instead, we should call fgetc once and store the
 * return value in an int variable then compare with EOF if they are
 * not equal we are good to go to the if condition to count the dots.
 *
 * The fix is added below
 *
 */


// Fix + Test script
/*

#include <stdio.h>

int count_periods(const char *filename)
{
	FILE *fp;
	int n = 0, ch; // Fix 1

	if ((fp = fopen(filename, "r")) != NULL)
	{
		while ((ch = fgetc(fp)) != EOF)
			if (ch == '.')
				n++;

		fclose(fp);
	}

	return n;
}

#define FILENAME "hello.txt" // Arbitrary

int main(void)
{
	printf("Number of periods = %d\n", count_periods(FILENAME));

	return 0;
}
*/

//----------------------------------

// Q13

/*
// Implementation + Test script
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "hello.txt" // Arbitrary

int line_length(const char *filename, int n);

int main(void)
{
	int line_num, line_len;

	printf("Enter the line number: ");
	scanf("%d", &line_num);

	line_len = line_length(FILENAME, line_num);
	printf("Length of line %d = %d\n", line_num, line_len);

	return 0;
}

int line_length(const char *filename, int n)
{
	FILE *input_file;
	int ch, len = 0;

	if ((input_file = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (--n)
	{
		if (fscanf(input_file, "%*[^\n]") == EOF)
			return 0; // Line does not exist or reading error

		getc(input_file); // Skip \n at the end of line
	}

	while ((ch = getc(input_file)) != EOF)
	{
		if (ch == '\n')
			break; // Exclude \n from len

		len++;
	}

	fclose(input_file);
	return len;
}
*/

//----------------------------------

// Q14

/*
// Implementation + Test Script
#include <stdio.h>
#include <stdlib.h>
#define LEN 50 // Arbitrary
#define FILENAME "hello.txt" // Arbitrary

// (a)
char *myfgets(char *in_str, int n, FILE *in_stream);

// (b)
int myfputs(const char *out_str, FILE *out_stream);

int main(void)
{
	FILE *in_stream;
	char input_line[LEN];

	if((in_stream = fopen(FILENAME, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s", FILENAME);
		exit(EXIT_FAILURE);
	}

	while (myfgets(input_line, LEN, in_stream) != NULL)
		myfputs(input_line, stdout);
		//printf("%s", input_line); // Test your fgets version first

	return 0;
}


// (a)
char *myfgets(char *in_str, int n, FILE *in_stream)
{
	int ch, i = 0;

	while (i < n && (ch = getc(in_stream)) != EOF)
	{
		in_str[i++] = (char)ch;

		if (ch == '\n')
			break;
	}

	// Check eof "before" reading or error during reading
	if (i == 0 || ferror(in_stream))
		return NULL;

	in_str[i] = '\0';
	return in_str;
}


// (b)
int myfputs(const char *out_str, FILE *out_stream)
{
	while (*out_str && fputc(*out_str++, out_stream) != EOF);

	if (ferror(out_stream))
		return EOF;

	return 1;
}
*/

//----------------------------------

// Q15

/*
 * SEEK_SET: A point before the first byte of the file
 * SEEK_END: A point after the last byte of the file
 * SEEK_CUR: A point at the current byte of the file
 *
 *
 * a) fseek(fp, n * 64L, SEEK_SET);
 *
 * b) fseek(fp, -64L, SEEK_END);
 *
 * c) fseek(fp, 64L, SEEK_CUR);
 *
 * d) fseek(fp, -2 * 64L, SEEK_CUR);
 *
 */


//----------------------------------

// Q16


/*
 * sscanf(str, "%*[^#]#%[0-9,]", sales_rank);
 *
 * %*[^#] is a scanset that means suppress assignment of all
 * characters in the string up to and excluding the # character
 *
 * # consumes the # character from the input string
 *
 * %[0-9,] is a scanset that consumes a string consisting of
 * numbers and commas
 *
 *
 */

