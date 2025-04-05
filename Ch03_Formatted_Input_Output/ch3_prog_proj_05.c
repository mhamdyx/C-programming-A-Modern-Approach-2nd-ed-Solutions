/*
 * ch3_prog_proj_05.c
 *
 *  Created on: Mar 19, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Magic Square

#include <stdio.h>

int main(void)
{
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	int n11, n12, n13, n14, n15, n16;
	int sum_r1, sum_r2, sum_r3, sum_r4;
	int sum_c1, sum_c2, sum_c3, sum_c4;
	int sum_d1, sum_d2;

	printf("Enter the numbers from 1 to 16 in any order:\n");

	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5,
			&n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);

	printf("%2d %2d %2d %2d\n", n1, n2, n3, n4);
	printf("%2d %2d %2d %2d\n", n5, n6, n7, n8);
	printf("%2d %2d %2d %2d\n", n9, n10, n11, n12);
	printf("%2d %2d %2d %2d\n", n13, n14, n15, n16);

	sum_r1 = n1 + n2 + n3 + n4;
	sum_r2 = n5 + n6 + n7 + n8;
	sum_r3 = n9 + n10 + n11 + n12;
	sum_r4 = n13 + n14 + n15 + n16;

	sum_c1 = n1 + n5 + n9 + n13;
	sum_c2 = n2 + n6 + n10 + n14;
	sum_c3 = n3 + n7 + n11 + n15;
	sum_c4 = n4 + n8 + n12 + n16;

	sum_d1 = n1 + n6 + n11 + n16;
	sum_d2 = n4 + n7 + n10 + n13;

	printf("\nRow sums: %d %d %d %d\n", sum_r1, sum_r2, sum_r3, sum_r4);
	printf("Column sums: %d %d %d %d\n", sum_c1, sum_c2, sum_c3, sum_c4);
	printf("Diagonal sums: %d %d\n", sum_d1, sum_d2);

	return 0;
}
