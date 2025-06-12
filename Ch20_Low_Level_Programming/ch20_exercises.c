/*
 * ch20_exercises.c
 *
 *  Created on: May 18, 2020
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 * a) i = 8, j = 9
 * i >> 1 + j >> 1 = 8 >> 1 + 9 >> 1 = 8 >> 10 >> 1
 * = ((8 >> 10) >> 1) = 0 >> 1 = 0
 *
 * Output: 0
 *
 *
 * b) i = 1
 * i & ~i = 1 & (~1) = 0000 0000 0000 0001 & 1111 1111 1111 1110
 * = 0000 0000 0000 0000 = 0
 *
 * Output: 0
 *
 *
 * c) i = 2, j = 1, k = 0
 * ~i & j ^ k  = (((~i) & j) ^ k) = (((~2) & 1) ^ 0)
 * = (((~0000 0000 0000 0010) & 0000 0000 0000 0001) ^ 0000 0000 0000 0000)
 * = ((1111 1111 1111 1101 & 0000 0000 0000 0001) ^ 0000 0000 0000 0000)
 * = (0000 0000 0000 0001 ^ 0000 0000 0000 0000) = 0000 0000 0000 0001 = 1
 *
 * Output: 1
 *
 *
 * d) i = 7, j = 8, k = 9
 * i ^ j & k = (i ^ (j & k)) = (7 ^ (8 & 9)) =
 * = (0000...0111 ^ (0000...1000 & 0000...1001))
 * = (0000...0111 ^ 0000...1000) = 0000...1111 = 15
 *
 * Output: 15
 *
 */

//----------------------------------

// Q2

/*
 * Toggling a bit is done by using exclusive or bitwise operator (^)
 * with a mask consisting of 1 shifted by the desired position:
 *
 * Examples to toggle bit 4 in i:
 *
 * i = i ^ 0x10; // or i ^= 0x10;
 * i ^= 1 << 4;
 *
 */

//----------------------------------

// Q3

/*
 * x ^= y ---> x = x ^ y --->(1)
 *
 * y ^= x ---> y = y ^ x ---> from (1): y = y ^ (x ^ y) = y ^ y ^ x
 * = 0 ^ x = x ----> y = x --->(2)
 *
 * x ^= y ---> x = x ^ y ---> from (1) & (2): x = (x ^ y) ^ (x)
 * = x ^ x ^ y = 0 ^ y = y --->(3)
 *
 * From (2) & (3): values of x and y are swapped
 *
 * The result: swapping x and y
 *
 */

//----------------------------------

// Q4 + test script
/*
#include <stdio.h>

#define MK_COLOR(r, g, b) ((long) ((b) << 16) | ((g) << 8) | (r))

int main(void)
{
	printf("color: %ld\n", MK_COLOR(97, 65, 66)); // R = 0x61, G = 0x41, B = 0x42
	printf("color in hex: %#.8x", (unsigned int)MK_COLOR(97, 65, 66));
	return 0;
}
*/

//----------------------------------

// Q5 + test script
/*
#include <stdio.h>

#define GET_RED(color) ((u8) ((color) & 0xFF))
#define GET_GREEN(color) ((u8) (((color) >> 8) & 0xFF))
#define GET_BLUE(color) ((u8) (((color) >> 16) & 0xFF))

typedef unsigned char u8;

int main(void)
{
	long color = 4342113; // R = 0x61, G = 0x41, B = 0x42
	u8 red = GET_RED(color), green = GET_GREEN(color), blue = GET_BLUE(color);

	printf("Color = %ld, Color in hex = %#lx\n", color, color);
	printf("Red = %d, Red in hex = %#x\n", red, red);
	printf("Green = %d, Green in hex = %#x\n", green, green);
	printf("Blue = %d, Blue in hex = %#x\n", blue, blue);

	return 0;
}
*/

//----------------------------------

// Q6 + test script
/*
#include <stdio.h>

unsigned short swap_bytes(unsigned short i); // For (a) and (b)

int main(void)
{
	unsigned short hex_dec;
	SEB();
	printf("Enter a hexadecimal number (up to four digits): ");
	scanf("%hx", &hex_dec);

	printf("Number with bytes swapped: %hx\n", swap_bytes(hex_dec));

	return 0;
}
*/

// a) Non-condensed form
/*
unsigned short swap_bytes(unsigned short i)
{
	unsigned short low_byte = i >> 8, high_byte = i << 8;

	return high_byte | low_byte;
}
*/

// b) condensed form
/*
unsigned short swap_bytes(unsigned short i)
{
	return i << 8 | i >> 8;
}
*/

//----------------------------------

// Q7 + test script
/*
unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

#include <stdio.h>

int main(void)
{
	unsigned int val = 0x12345678;
	int rot_val = 4;

	printf("Original value = %#x\n", val);
	printf("Left-rotated value by %d = %#x\n", rot_val, rotate_left(val, 4));
	printf("Right-rotated value by %d = %#x\n", rot_val, rotate_right(val, 4));

	return 0;
}


unsigned int rotate_left(unsigned int i, int n)
{
	return (i << n) | (i >> (sizeof(i) * 8 - n));
}

unsigned int rotate_right(unsigned int i, int n)
{
	return (i >> n) | (i << (sizeof(i) * 8 - n));
}
*/

// Alternative implementation (assuming that int size is 4 bytes)
/*
unsigned int rotate_left(unsigned int i, int n)
{
	return (i << n) | (i >> (32 - n));
}

unsigned int rotate_right(unsigned int i, int n)
{
	return (i >> n) | (i << (32 - n));
}
*/

//----------------------------------

// Q8

/*
 * a) ~(~0 << n) = ~(0xFFFFFFFF << n) ---> first n bits are ones and 
 * otherwise is zero
 *
 * b) Returns a bit-field of length n-bits and with position m as the 
 * most significant bit
 * 
 * Explanation:
 * Let i = 0x12345678, m = 3, n = 4
 * 
 * i >> (m + 1 - n) = i >> (3 + 1 - 4) = i >> 0 = i
 * ~(~0 << n) = ~(0xFFFFFFFF << 4) = ~(0xFFFFFFF0) = 0x0000000F = 0xF
 * i & 0xF = 0x12345678 & 0x0000000F = 0x00000008 = 0x8 = 1000
 * Most significant bit of 1000 is bit 3 (and m = 3)
 *
 */

//----------------------------------

// Q9 + test script
/*
#include <stdio.h>

int count_ones(unsigned char ch); // For (a) and (b)

int main(void)
{
	unsigned char n = 9;

	printf("Number of 1s in %d: %d\n", n, count_ones(n));

	return 0;
}
*/


// a) With a loop
/*
int count_ones(unsigned char ch)
{
	int count = 0;

	do
	{
		count += (ch & 1) ? 1 : 0;
	} while(ch >>= 1);

	return count;
}
*/

// b) Without a loop
/*
int count_ones(unsigned char ch)
{
	return (ch & 1) + ((ch) ? count_ones(ch >> 1) : 0);
}
*/

//----------------------------------

// Q10 + test script
/*
#include <stdio.h>

unsigned int reverse_bits(unsigned int n);

int main(void)
{
	unsigned int n = 0xA0A0A0A0;

	printf("Original number = %#.8X\n", n);
	printf("Reversed number = %#.8X\n", reverse_bits(n));
	return 0;
}

unsigned int reverse_bits(unsigned int n)
{
	// Start from the position of most and least significant bits
	unsigned int high_bit = sizeof(n) * 8 - 1, low_bit = 0;

	for (; low_bit < high_bit; low_bit++, high_bit--)
		if ((n >> high_bit & 1) != (n >> low_bit & 1))
			n ^= ((1 << high_bit) | (1 << low_bit));

	return n;
}
*/

//----------------------------------

// Q11

/*
 * Since the bitwise operators '&', '^', and '|' have lower precedence
 * than relational and equality operators. The condition will always fail
 * no matter how many control keys are pressed as the first condition to
 * be evaluated is: (SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0 which is always
 * false if either BIT is set.
 *
 * If any bit is set the condition will be: if(key_code & false) which is
 * false but this is incorrect.
 *
 * To fix this condition, we have to add parentheses to prioritize the 
 * bitwise &:
 *
 * if((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
 *
 *
 */

//----------------------------------

// Q12

/*
 * Since bitwise shift operators have lower precedence than arithmetic
 * operators, the addition operation is evaluated first leading to incorrect
 * return value. To fix this code, we have to prioritize the shift operation
 * by adding parentheses when using bitwise shift operator:
 *
 */

// correction + test script
/*
#include <stdio.h>

unsigned short create_short(unsigned char high_byte, unsigned char low_byte);

int main(void)
{
	unsigned char x = 0xab, y = 0xcd;

	unsigned short z = create_short(x, y);

	printf("z = %#x\n", z);

	return 0;
}

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
	return (high_byte << 8) + low_byte;
}
*/

//----------------------------------

// Q13

/*
 * n &= n - 1, Let n is 8-bits and n = 7 = 0x07 = 0b00000111
 *
 * Once:
 * n &= n - 1 = n & (n - 1) = 0b0000_0111 & 0b0000_0110 = 0b0000_0110
 *
 * More than once:
 * n &= n - 1 = n & (n - 1) = 0b0000_0110 & 0b0000_0101 = 0b0000_0100
 *
 * Effect: This statement clears the rightmost bit with value 1
 *
 */

// Script to monitor the behavior
/*
#include <stdio.h>

void print_binary(unsigned int n);
void strange_function(unsigned int n);

int main(void)
{
	unsigned int i, j, k;

	i = 10;
	j = 95;
	k = 235;

	strange_function(i);
	strange_function(j);
	strange_function(k);

	return 0;
}

void strange_function(unsigned int n)
{
	for (; n; n &= n - 1)
		print_binary(n);

	putchar('\n');
}

void print_binary(unsigned int n)
{
	int i = sizeof(n) * 8;

	for (; i >= 0; i--)
		printf("%d", (n >> i) & 1);

	putchar('\n');
}
*/

//----------------------------------

// Q14
/*
typedef struct
{
	unsigned int fraction: 23, exponent: 8, sign: 1;
} IEEE_Float;
*/


// Note: This code will tell you your processor's endianness
/*
int main(void)
{
	int n = 1;

	if(*(char *)&n == 1)
		printf("Little endian\n");
	else
		printf("Big endian\n");

	return 0;
}
*/

//----------------------------------

// Q15

/*
 * a) Because some compilers treat the field's high-order bit as a sign bit,
 * but others don't. So, the compilers that treat it as a sign bit will have
 * the program print -1 and vice versa.
 *
 * b) To avoid this ambiguity, declare all bit-fields to be either
 * unsigned int or signed int.
 *
 */

//----------------------------------

// Q16 + test script
/*
#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

union
{
	struct
	{
		DWORD EAX, EBX, ECX, EDX;
	} dword;

	struct
	{
		WORD AX, EAXH, BX, EBXH, CX, ECXH, DX, EDXH;
	} word;

	struct
	{
		BYTE AL, AH, EAXH_L, EAXH_H;
		BYTE BL, BH, EBXH_L, EBXH_H;
		BYTE CL, CH, ECXH_L, ECXH_H;
		BYTE DL, DH, EDXH_L, EDXH_H;
	} byte;
} regs;

int main(void)
{

	regs.byte.AH = 0xab;
	regs.byte.AL = 0xcd;
	printf("AX = %#X, EAX = %#.8lX\n", regs.word.AX, regs.dword.EAX);

	regs.dword.EAX = 0xabcdeeff;
	printf("AX = %#.4X, AH = %#X, AL = %#X\n", regs.word.AX, regs.byte.AH, regs.byte.AL);

	return 0;
}
*/
