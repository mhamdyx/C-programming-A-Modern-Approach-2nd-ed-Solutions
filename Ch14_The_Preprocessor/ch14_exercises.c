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

/*
 * Note: The above macros work for numeric inputs only
 * and they will produce the correct results as long as the
 * parentheses are maintained.
 *
 * Otherwise, they will fail.
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
 * Problem: No parentheses around the replacement-list, hence this
 * may have wrong results if AVG is used as a denominator
 *
 * Example: 6.0 / AVG(3, 3) = 6.0 / (3 + 3) / 2 = 6.0 / 6 / 2
 * = 1.0 / 2 = 0.5 (But the desired is 2)
 *
 * Fix: Put parentheses around the replacement-list if it has an operator
 *
 * Correct Macro:
 * #define AVG(x, y) ((x+y) / 2)
 *
 *
 * b) #define AREA(x, y) (x) * (y)
 * Problem: No parentheses around the replacement-list, hence this
 * may have wrong results if AVG is used as a denominator
 *
 * Example: 24 / AREA(3, 4) = 24 / 3 * 4 = 8 * 4 = 32. Expectation was 2
 *
 * Fix: Put parentheses around the replacement-list if it has an operator
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
 * putchar('a' <= s[1] && s[++i] <= 'z' ? s[++i] - 'a' + 'A' : s[++i]) =
 * putchar('a' <= s[1] && s[2] <= 'z' ? s[++i] - 'a' + 'A' : s[++i]) =
 * putchar('a' <= s[1] && s[2] <= 'z' ? s[3] - 'a' + 'A' : s[++i]) =
 * putchar(s[3] - 'a' + 'A') = putchar('d' - 'a' + 'A') = putchar('D')
 *
 * Output: D
 *
 *
 * b) s = "0123", i = 0
 * putchar(TOUPPER(s[++i])) =
 * putchar('a' <= s[1] && s[++i] <= 'z' ? s[++i] - 'a' + 'A' : s[++i]) =
 * putchar('a' <= s[1] && s[++i] <= 'z' ? s[++i] - 'a' + 'A' : s[2]) =
 * putchar('2')
 *
 * Comment: first condition was false so the logical And doesn't continue evaluation
 *
 * Output: 2
 *
 */

//----------------------------------

// Q6 + test script
/*
#include <stdio.h>
#include <math.h>
#define DISP(f, x) printf(#f "(%g) = %g\n", (x), f(x)) // (a)

#define DISP2(f, x, y) printf(#f "(%g, %g) = %g\n", (x), (y), f(x, y)) // (b)

int main(void)
{
	DISP(sqrt, 3.0);
	DISP2(pow, 2.0, 3.0);

	return 0;
}
*/

//----------------------------------

// Q7

/*
 * a) long long_max(long x, long y) { return x > y ? x : y; }
 *
 * b) Beacuse types like "unsigned long" consist of two words and this will
 * cause an inconsistent replacement-list and compiler errors
 * For example, here is how the macro gets translated:
 * unsigned long unsigned long_max(unsigned long x, unsigned long y)
 * { return x > y ? x : y; }
 *
 * The function name does not depict that we desire unsigned long, and
 * the compiler will report an error due to the duplication of the word
 * unsigned
 *
 *
 * c) typedef unsigned long ULong
 * GENERIC_MAX(ULong);
 *
 * ULong is just an alias and is treated as unsigned long but not replaced
 * in the code by unsigned long, that's the difference.
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
 * Macro arguments are completely macro-expanded before they are
 * substituted into a macro body, unless they are stringified or
 * pasted with other tokens. After substitution, the entire macro
 * body, including the substituted arguments, is scanned again for
 * macros to be expanded. The result that the arguments are scanned
 * twice to expand macro calls in them.
 *
 * Interpretation:
 * Example 1:
 * #define LINE(x) #x
 * LINE(__LINE__) --> #__LINE__ --> "__LINE__"
 *
 * Comment: Argument x is stringized in the macro body, so it's not
 * macro-expanded before substitution
 * 
 * Example 2: Assume line number is 255
 * #define GET_LINE_NUM(x) LINE(x)
 * 1) Outer macro expansion
 * GET_LINE_NUM(__LINE__) --> LINE(__LINE__)
 * No # or ## in the macro body then do a prescan to the argument passed
 * which is __LINE__ and substitute its value in the macro body
 *
 * 2) Prescan: __LINE__ ---> 255
 *
 * 3) Substitution in the macro body: LINE(255)
 *
 * 4) Continue scanning the macro body for more macros to be expanded
 * LINE(255) --> #255 --> "255"
 *
 */

//----------------------------------

// Q9 + test script
/*
#include <stdio.h>

// (a)
#define CHECK(x, y, n) \
	((0 <= (x) && (x) <= ((n) - 1) && 0 <= (y) && (y) <= ((n) - 1)) ? 1 : 0)

// (b)
#define MEDIAN(x, y, z) (((x) <= (y)) ? \
	(((x) >= (z)) ? x : (((y) <= (z)) ? (y) : (z)))  : \
	(((x) <= (z)) ? x : (((y) >= (z)) ? (y) : (z))))


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

// Test Script:
// Hint: I deliberately changed _Pragma to puts to show you the result
/*
#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) puts(#x)

int main(void)
{
	IDENT(foo);
	return 0;
}
*/
