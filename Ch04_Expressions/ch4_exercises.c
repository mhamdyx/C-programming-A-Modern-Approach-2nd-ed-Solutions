/*
 * ch4_exercises.c
 *
 *  Created on: Apr 1, 2024
 *      Author: Mahmoud Hamdy
 */

// Q1
/**
 *
 * a) 1 2
 *
 * b) 0
 *
 * c) 1
 *
 * d) 0
 *
 */

//----------------------------------

// Q2
/**
 *
 * For C89, no, as the C89 standard states that if either operand
 * is negative, the result of a division can be rounded up or down.
 *
 * For example:
 * Suppose i = 9, j = 7
 * (-i)/j can be either -1 or -2 (implementation-defined behavior)
 * -(i/j) is -1 (regardless the implementation)
 *
 * For C99, yes, as the C99 standard states that the result of a
 * division is always truncated towards zero
 *
 * Foe example:
 * Suppose i = 9, j = 7
 * (-i)/j = -1
 * -(i/j) = -1
 *
 */


//----------------------------------

// Q3
/**
 * a) 8 / 5 = 1
 *
 * b) -8 / 5 = -1 or -2
 *
 * c) 8 / -5 = -1 or -2
 *
 * d) -8 / -5 = 1 or 2
 *
 */


//----------------------------------

// Q4
/**
 *
 * a) 8 / 5 = 1
 *
 * b) -8 / 5 = -1
 *
 * c) 8 / -5 = -1
 *
 * d) -8 / -5 = 1
 *
 */

//----------------------------------

// Q5
/**
 * a) 8 % 5 = 3
 *
 * b) -8 % 5 = -3 or 2
 *
 * c) 8 % -5 = 3 or -2
 *
 * d) -8 % -5 = -3 or 2
 *
 */

//----------------------------------

// Q6
/**
 * a) 8 % 5 = 3
 *
 * b) -8 % 5 = -3
 *
 * c) 8 % -5 = 3
 *
 * d) -8 % -5 = -3
 *
 */


//----------------------------------

// Q7
/**
 * Original Algorithm: 9 - [(Total - 1) % 10]
 * Total - 1 ---->(1)
 * (1) % 10 ----->(2)
 * 9 - (2) ------>(3)
 *
 *
 * Simplified Algorithm: 10 - [Total % 10]
 * Total % 10 --->(1)
 * 10 - (1) ----->(2)
 *
 * The simplified technique will not work simply because it is not
 * equivalent to the original. The order of operations of changed
 * and these operations are not cannot replace each other
 * (Remainder from division cannot replace subtraction)
 *
 */

//----------------------------------

// Q8
/**
 *
 * Programming approach:
 * If we use printf on both equations (given the same total value),
 * we will get the same result hence the program still works
 *
 * Math approach: Using modular arithmetic, we can prove that both
 * equations are equivalent
 *
 */


//----------------------------------

// Q9
/**
 * a) i = 7, j = 8;
 * i *= j + 1;
 *
 * j + 1 = 8 + 1 = 9 ----> (1)
 * i = i * (1) = 7 * 9 = 63 ---> (2)
 *
 * Output:
 * 63 8
 *
 *
 * b) i = j = k = 1;
 * i += j += k;
 *
 * k = 1 --->(1)
 * j = j + (1) = 1 + 1 = 2 --->(2)
 * i = i + (2) = 1 + 2 = 3 --->(3)
 *
 * Output:
 * 3 2 1
 *
 *
 * c) i = 1; j = 2; k = 3;
 * i -= j -= k;
 *
 * k = 3 --->(1)
 * j = j - (1) = 2 - 3 = -1 --->(2)
 * i = i - (2) = 1 - (-1) = 2 --->(3)
 *
 * Output:
 * 2 -1 3
 *
 * d) i = 2; j = 1; k = 0;
 * i *= j *= k;
 *
 * k = 0 --->(1)
 * j = j * (1) = 1 * 0 = 0 --->(2)
 * i = i * (2) = 2 * 0 = 0 --->(3)
 *
 * Output:
 * 0 0 0
 *
 */


//----------------------------------

// Q10
/**
 * a) i = 6;
 * j = i += i;
 *
 * i = 6 --->(1)
 * i = i + (1) = 6 + 6 = 12 --->(2)
 * j = (2) = 12 --->(3)
 *
 * Output:
 * 12 12
 *
 * b) i = 5;
 * j = (i -= 2) + 1;
 *
 * (i -= 2) ---> i = i - 2 = 5 - 2 = 3 --->(1)
 * j = (1) + 1 = 3 + 1 = 4 --->(2)
 *
 * Output:
 * 3 4
 *
 * c) i = 7;
 * j = 6 + (i = 2.5);
 *
 * (i = 2.5) ---> i = 2 --->(1)
 * j = 6 + (1) = 6 + 2 = 8 --->(2)
 *
 * Output:
 * 2 8
 *
 * d) i = 2; j = 8;
 * j = (i = 6) + (j = 3);
 *
 * (i = 6) ---> i = 6 --->(1)
 * (j = 3) ---> j = 3 --->(2)
 * j = (1) + (2) = 6 + 3 = 9 --->(3)
 *
 * Output:
 * 6 9
 *
 */


//----------------------------------

// Q11
/**
 *
 * a) i = 1;
 *
 * i++ - 1 = 1 - 1 = 0 ->(1)
 * i = 2 --->(2)
 *
 * Output:
 * 0 2
 *
 *
 * b) i = 10; j = 5;
 *
 * i++ - ++j = 10 - 6 = 4 --->(1)
 * i = 11 --->(2)
 *
 * Output:
 * 4 11 6
 *
 * c) i = 7; j = 8;
 *
 * i++ - --j = 7 - 7 = 0 --->(1)
 * i = 8 --->(2)
 *
 * Output:
 * 0 8 7
 *
 *
 * d) i = 3; j = 4; k = 5;
 *
 * i++ - j++ + --k = 3 - 4 + 4 = 3 --->(1)
 * i = 4 --->(2)
 * j = 5 --->(3)
 *
 * Output:
 * 3 4 5 4
 *
 */


//----------------------------------

// Q12
/**
 * a) i = 5;
 * j = ++i * 3 - 2;
 *
 * ++i ---> i = 6 --->(1)
 * j = (1) * 3 - 2 = 6 * 3 - 2 = 18 - 2 = 16 --->(2)
 *
 * Output:
 * 6 16
 *
 *
 * b) i = 5;
 * j = 3 - 2 * i++;
 *
 * i = 5 --->(1)
 * j = 3 - 2 * i++ = 3 - 2 * 5 = 3 - 10 = -7 --->(2)
 *
 * Output:
 * 6 -7
 *
 *
 * c) i = 7;
 * j = 3 * i-- + 2;
 *
 * i = 7 --->(1)
 * j = 3 * i-- + 2 = 3 * 7 + 2 = 21 + 2 = 23 --->(2)
 *
 * Output:
 * 6 23
 *
 * d) i = 7;
 * j = 3 + --i * 2;
 *
 * i = 7 --->(1)
 * j = 3 + --i * 2 = 3 + 6 * 2 = 3 + 12 = 15 --->(2)
 *
 * Output:
 * 6 15
 *
 */


//----------------------------------

// Q13
/**
 * ++i is exactly the same as (i += 1), in the sense that both
 * will return the same expression value (i + 1), while i++ will
 * only return the value of i before the increment.
 *
 */


//----------------------------------

// Q14
/**
 * a) a * b - c * d + e
 *
 * (((a * b) - (c * d)) + e)
 *
 *
 * b) a / b % c / d
 *
 * (((a / b) % c) / d)
 *
 *
 * c) - a - b + c - + d
 *
 * ((((-a) - b) + c) - (+d))
 *
 *
 * d) a * - b / c - d
 *
 * (((a * (-b)) / c) - d)
 *
 */


//----------------------------------

// Q15
/**
 * Initially: i = 1, j = 2
 *
 * a) i += j;
 *
 * j = 2 --->(1)
 * i += (1) ---> i = i + (1) = 1 + 2 = 3 --->(2)
 *
 * After execution: i = 3, j = 2
 *
 *
 * b) i--;
 *
 * After execution: i = 0, j = 2
 *
 * c) i * j / i;
 *
 * After execution: i = 1, j = 2
 *
 *
 * d) i % ++j;
 *
 * After execution: i = 1, j = 3
 *
 */
