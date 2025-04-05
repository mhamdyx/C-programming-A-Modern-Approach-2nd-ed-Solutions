/*
 * ch7_exercises.c
 *
 *  Created on: Mar 3, 2024
 *      Author: Mahmoud Hamdy
 */

// Q1
/**
 * a) Decimal of 077 = 7 x (1) + 7 x (1 x 8) + 0 x (1 x 8 x 8)
 * = 7 + 56 + 0 = 63
 *
 * b) Decimal of 0x77 = 7 x (1) + 7 x (1 x 16) = 7 + 112 = 119
 *
 * c) Decimal of 0xABC = 12 x (1) + 11 x (1 x 16) + 10 x (1 x 16 x 16)
 * = 12 + 176 + 2560 = 2748
 *
 */

//----------------------------------

// Q2
/**
 * a) 010E2 -> Legal floating-point
 *
 * b) 32.1E+5 -> Legal floating-point
 *
 * c) 0790 -> Illegal constant as the 9 is not an octal digit
 *
 * d) 100_000 -> Illegal
 *
 * e) 3.978e-2 -> Legal floating-point
 *
 */

//----------------------------------

// Q3
/**
 * a) short unsigned int -> It's legal
 *
 * b) short float -> Illegal
 *
 * c) long double -> Legal (in C99)
 *
 * d) unsigned long -> Legal
 *
 */

//----------------------------------

// Q4
/**
 * a) Legal
 *
 * b) Legal
 *
 * c) Legal
 *
 * d) Illegal -> As printf is used to print the formatted string
 *
 */

//----------------------------------

// Q5
/**
 * a) Legal way -> using %c
 *
 * b) Illegal way -> As C doesn't support printing in binary format
 *
 * c) Legal way -> using %o
 *
 * d) Legal way -> using %x
 *
 */

//----------------------------------

// Q6
/**
 * a) There are 30 days per month -> char is enough
 *
 * b) There are 365 days per year -> short is enough (or int on 16-bit systems)
 *
 * c) There are 1440 mins per day -> short is enough (or int on 16-bit systems)
 *
 * d) There are 86400 sec per day -> long is enough (or int on 32-bit system)
 *
 */

//----------------------------------

// Q7
/**
 * a) Octal escape (\b) =\10
 *
 * b) Octal escape (\n) = \12
 *
 * c) Octal escape (\r) = \15
 *
 * d) Octal escape (\t) = \11
 *
 */

//----------------------------------

// Q8
/**
 * a) Hexadecimal escape (\b) = \x08
 *
 * b) Hexadecimal escape (\n) = \x0a
 *
 * c) Hexadecimal escape (\r) = \x0d
 *
 * d) Hexadecimal escape (\t) = \x09
 *
 */

//----------------------------------

// Q9
/**
 * int / int + char = int + char
 *
 * = int + int --> Implicit cast (Promotion)
 *
 * = int --> Type of the expression is int
 *
 */

//----------------------------------

// Q10
/**
 * int + (int) long * unsigned int
 *
 *  = int + int * unsigned int --> Explicit cast from long to int
 *
 *  = int + unsigned int * unsigned int --> Implicit cast (Promotion)
 *
 *  = int + unsigned int
 *
 *  = unsigned int + unsigned int --> Implicit cast (Promotion)
 *
 *  = unsigned int --> Type of expression is unsigned int
 *
 */

//----------------------------------

// Q11
/**
 * int * float / double
 *
 * = float * float / double --> Implicit cast (from int to float)
 *
 * = float / double
 *
 * = double / double --> Implicit cast (Promotion)
 *
 * = double --> Type of expression is double
 *
 */

//----------------------------------

// Q12
/**
 * double = int + float
 *
 * double = float + float --> Type conversion (from int to float)
 *
 * double = float
 *
 * double = double --> Conversion during assignment (from float to double)
 *
 */

//----------------------------------

// Q13
/**
 * char c = '\1'l
 * short s = 2;
 * int i = -3
 * long m = 5;
 * float f - 6.5f;
 * double d = 7.5;
 *
 * a) c * i --> Type: int
 * Value = 1 * -3 = -3
 *
 * b) s + m --> Type: long
 * Value = 2 + 5 = 7
 *
 * c) f / c --> Type: float
 * Value = 6.5f / 1 = 6.5f (6.500000 when printed)
 *
 * d) d / s --> Type: double
 * Value = 7.5 / 2 = 3.75 (3.750000 when printed)
 *
 * e) f - d --> Type: double
 * Value = 6.5 - 7.5 = -1.0 (-1.000000 when printed)
 *
 * f) (int) f --> Type: int
 * Value = 6
 *
 */

//----------------------------------

// Q14
/**
 * No, this will not always work
 * Reason: In case the whole number (non-fractional part) in f
 * exceeds the largest value of type int, wrong value will be
 * produced from the conversion
 *
 */

//----------------------------------

// Q15
/**
 * typedef char Int8;
 *
 * typedef short int Int16; // or just short only without int
 *
 * typedef long int Int32; // or just long only without int
 *
 */
