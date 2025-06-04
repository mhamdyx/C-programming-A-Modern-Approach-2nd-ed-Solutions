/*
 * queueclient.c
 *
 *  Created on: May 12, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: queueclient.c

#include <stdio.h>
#include "queueADT.h"

int main(void)
{
	Queue q1, q2;
	int n;

	q1 = create();
	q2 = create();

	enqueue(q1, 1);
	enqueue(q1, 2);

	n = dequeue(q1);
	printf("Dequeued %d from q1\n", n);

	enqueue(q2, n);
	n = dequeue(q1);
	printf("Dequeued %d from q1\n", n);

	enqueue(q2, n);

	destroy(q1);

	while (!is_empty(q2))
		printf("Dequeued %d from q2\n", dequeue(q2));

	enqueue(q2, 3);
	make_empty(q2);

	if (is_empty(q2))
		printf("q2 is empty\n");
	else
		printf("q2 is not empty\n");

	destroy(q2);

	return 0;
}
