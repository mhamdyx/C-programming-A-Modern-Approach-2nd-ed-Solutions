/*
 * ch14_exercises.c
 *
 *  Created on: Dec 27, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1 + test script
/*
#include <stdio.h>
#define CUBE(x) ((x) * (x) * (x)) // a)
#define REM(n) ((n) % 4) // b)
#define MUL_LT_100(x, y) ((((x) * (y)) < 100) ? 1 : 0) // c

int main(void)
{
	int x = 3, n = 19, y = 30;

	printf("Cube(x) = %d\nREM(n) = %d\n", CUBE(x), REM(n));
	printf("Is (x * y) < 100? %s\n", MUL_LT_100(x, y) ? "Yes" : "No");

	return 0;
}
*/

//----------------------------------

// Q2 + test script
/*
#include <stdio.h>
#define NELEMS(a) ((int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
	int a[] = {0, 1, 2, 2, 7, 1, 1, 1, 4, 2};

	printf("Length of array a = %d", NELEMS(a));

	return 0;
}
*/

//----------------------------------

// Q3
/*
 * #define DOUBLE(x) 2*x
 *
 * a) DOUBLE(1+2) = 2 * 1 + 2 = 2 + 2 = 4. Expectation was 6
 *
 * b) 4/DOUBLE(2) = 4 / 2 * 2 = 2 * 2 = 4. Expectation was 1
 *
 * c) fix: #define DOUBLE(x) (2 * (x)).
 *
 * Now:
 * a) DOUBLE(1+2) = (2 * (1+2)) = 2 * 3 = 6
 * b) 4/DOUBLE(2) = 4 / (2 * (2)) = 4 / 4 = 1
 *
 */


//----------------------------------

// Q4

/*
 * a) #define AVG(x, y) (x+y)/2
 * Problem: If x and y are expressions, the output will be unpredictable
 *
 * Example: AVG(4 / 2, 2) = 4 / 2 + 2 / 2 = 3. Expectation was 2.
 *
 * Fix: Put parentheses between each macro parameter
 *
 * Correct Macro:
 * #define AVG(x, y) ((x) + (y)) / 2
 *
 *
 * b) #define AREA(x, y) (x) * (y)
 * Problem: If the macro is used as a denominator, the output will be wrong
 *
 * Example: 24 / AREA(3, 4) = 24 / 3 * 4 = 8 * 4 = 32. Expectation was 2
 *
 * Fix: Put parentheses if the replacement list has an operator
 *
 * Correct Macro:
 * #define AREA(x, y) ((x) * (y))
 *
 */

//----------------------------------

// Q5

/*
 *
 * #define TOUPPER(c) ('a'<=(c)&&(c)<='z' ?(c)-'a'+'A':(c))
 *
 * a) s = "abcd", i = 0
 * putchar(TOUPPER(s[++i])) =
 * putchar('a' <= s[++i] && s[++i] <= 'z' ? s[++i] - 'a' + 'A' : s[++i]) =
 * putchar('a' <= s[1] && s[2] <= 'z' ? s[3] - 'a' + 'A' : s[++i]) =
 * putchar(s[3] - 'a' + 'A') = putchar('d' - 'a' + 'A') = putchar('D')
 *
 *
 * b) s = "0123", i = 0
 * putchar(TOUPPER(s[++i])) =
 * putchar('a' <= s[1] && s[++i] <= 'z' ? s[++i] - 'a' + 'A' : s[2]) =
 * putchar('2')
 *
 * Comment: first condition was false so the logical And doesn't continue evaluation
 *
 */


//----------------------------------

// Q6 + test script
/*
#include <stdio.h>
#include <math.h>
#define DISP(f, x) printf(#f"(%g) = %g\n", (x), f(x)); // (a)

#define DISP2(f, x, y) printf(#f"(%d, %d) = %g\n", (x), (y), f(x, y)); // (b)

int main(void)
{
	DISP(sqrt, 3.0)

	DISP2(pow, 2, 3)

	return 0;
}
*/

//----------------------------------

// Q7

/*
 * a) long long_max(long x, long y) { return x > y ? x : y; }
 *
 * b) Because we didn't specify to the macro that whether we want basic types or not
 * so when we attempt to do so, the function name still will be the same type_max and
 * not basic_type_max
 *
 * c) typedef unsigned long ulong
 * GENERIC_MAX(ulong);
 *
 * ulong is just an alias and it's treated as unsigned long but not replaced in the code
 * by unsigned long, that's the difference.
 *
 */


//----------------------------------

// Q8 + test script + comment on this quesion
/*
#include <stdio.h>

#define LINE_FILE "Line " GET_LINE_NUM(__LINE__) " of file "__FILE__
#define GET_LINE_NUM(x) LINE(x)
#define LINE(x) #x


int main(void)
{
	const char *str = LINE_FILE;
	puts(str);

	return 0;
}
*/

/*
 * Comment:
 * Macro arguments are completely macro-expanded before they are substituted into
 * a macro body, unless they are stringified or pasted with other tokens.
 * After substitution, the entire macro body, including the substituted arguments,
 * is scanned again for macros to be expanded. The result that the arguments
 * are scanned twice to expand macro calls in them.
 *
 * Interpretation:
 * #define LINE(x) #x (Strigification exits so arguments are not expanded first)
 * LINE(__LINE__) --> output: #__LINE__
 *
 * #define GET_LINE_NUM(x) LINE(x) (Arguments are expanded first since no # or ## exists)
 * GET_LINE_NUM(__LINE__) --> output: number
 *
 */


//----------------------------------

// Q9 + test script
/*
#include <stdio.h>

// (a)
#define CHECK(x, y, n) \
	(0 <= (x) && (x) <= ((n) - 1) && 0 <= (y) && (y) <= ((n) - 1)) ? 1 : 0

// (b)
#define MEDIAN(x, y, z) ((x) <= (y)) ? \
	(((x) >= (z)) ? x : (((y) <= (z)) ? (y) : (z)))  : \
	(((x) <= (z)) ? x : (((y) >= (z)) ? (y) : (z)))


// (c)
#define POLYNOMIAL(x) ((3 * (x) * (x) * (x) * (x) * (x)) + \
	(2 * (x) * (x) * (x) * (x)) - (5 * (x) * (x) * (x)) - \
	((x) * (x)) + (7 * (x)) - 6)

int main(void)
{
#if CHECK(2, 3, 8)
	printf("Inclusion exists\n");
#endif

	printf("%d\n", MEDIAN(9, 2, 3));
	printf("%d\n", POLYNOMIAL(0));

	return 0;
}
*/

//----------------------------------

// Q10
/*
 * When the function is very short (1~3 lines) it can be written as a macro instead
 * for speedy execution.
 *
 * On the other hand, functions which are large, recursive or its arguments
 * have side effects should never be used as macros.
 *
 */


//----------------------------------

// Q11 + test script
/*
#include <stdio.h>
#define ERROR(fstr, ...) fprintf(stderr, fstr, __VA_ARGS__) // called variadic macro

int main(void)
{
	ERROR("Range Error: index = %d\n", 3);

	return 0;
}
*/

//----------------------------------

// Q12

/*
 * a) #if M --> succeeds as M is defined with a value != 0
 *
 * b) #ifdef M --> succeeds as M is defined
 *
 * c) #ifndef M --> fails as M is defined
 *
 * d) #if defined(M) --> succeeds as M is defined
 *
 * e) #if !defined(M) --> fails as M is defined
 *
 */

//----------------------------------

// Q13
/*
// (a)
// The program starts in the next line:




void f(void);

int main(void)
{
	f();



	return 0;
}

void f(void)
{



	printf("N is undefined\n");

}

// (b) output: N is undefined\n (cursor stops at the next line)
*/

//----------------------------------

// Q14
/*
int main(void)
{
	int a[= 10], i, j, k, m; // syntax error


	i = j;




	i = 10 * j + 1;
	i = (x, y) x-y(j, k); // sytax error
	i = ((j) * (j)) * ((j) * (j));
	i = ((j) * (j)) * j;
	i = jk; // error: undefined variable jk
	puts("i" "j");



	i = SQR(j);

	i =    (j);

	return 0;
}
*/

//----------------------------------

// Q15 + test script
/*
#include <stdio.h>

#define ENGLISH
//#define FRENCH
//#define SPANISH

#ifdef ENGLISH
#	define INSERT_DISK "Insert Disk 1"
#
#elif defined(FRENCH)
#	define INSERT_DISK "Inserez Le Disque 1"
#
#elif defined(SPANISH)
#	define INSERT_DISK "Inserte El Disco 1"
#
#endif

int main(void)
{
	printf("%s\n", INSERT_DISK);

	return 0;
}
*/

//----------------------------------

// Q16

/*
 * #define IDENT(x) PRAGMA(ident #x)
 * #define PRAGMA(x) _Pragma(#x)
 *
 * IDENT(foo) --> PRAGMA(ident "foo") --> _Pragma("ident \"foo\"") --> ident "foo"
 *
 * Same effect as:
 * #pragma ident "foo"
 *
 */
