/*
 * ch17_exercises.c
 *
 *  Created on: Apr 7, 2020
 *      Author: Mahmoud Hamdy
 */

// Q1
/*
#include <stdlib.h>

void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if(ptr == NULL)
	{
		printf("Memory Allocation Failed.\n");
		exit(EXIT_FAILURE);
	}

	return ptr;
}
*/


//----------------------------------

// Q2 + Test script
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *str);

int main(void)
{
	char str1[] = "Hello World!", *str2;

	str2 = duplicate(str1);

	printf("str1: %s\nstr2: %s\n", str1, str2);


	return 0;
}

char *duplicate(char *str)
{
	char *dup_str = malloc(strlen(str) + 1);

	if(dup_str != NULL)
		strcpy(dup_str, str);

	return dup_str;
}
*/

//----------------------------------

// Q3 + Test script
/*
#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main(void)
{
	int *arr = create_array(5, 10);

	for(int i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}


int *create_array(int n, int initial_value)
{
	int *arr = malloc(n * sizeof(int));

	if(arr == NULL)
		return NULL;

	for(int i = 0; i < n; i++)
		arr[i] = initial_value;

	return arr;
}
*/

//----------------------------------

// Q4 + Test script
/*
#include <stdio.h>
#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

int main(void)
{
	p = malloc(sizeof(struct rectangle)); // or sizeof(*p)
	p->upper_left.x = 10;
	p->upper_left.y = 25;

	p->lower_right.x = 20;
	p->lower_right.y = 15;

	printf("Rectangle Data:\nUpper_Left  = (%d, %d)\nLower_Right = (%d, %d)\n",
			p->upper_left.x, p->upper_left.y, p->lower_right.x, p->lower_right.y);

	return 0;
}
*/

//----------------------------------

// Q5

/*
 * a) Illegal --> should be p->d.b = ' ';
 *
 * b) Legal
 *
 * c) Legal
 *
 * d) Illegal --> should be p->d.c = 20; (d is a union not a pointer to union)
 *
 */

//----------------------------------

// Q6 + Test script
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

// This function doesn't support removing the first node
void delete_from_list(struct node *list, int n);

// Test functions
struct node *add_to_list(struct node *list, int n);
void print_list(struct node *list);

int main(void)
{
	struct node *list = NULL;

	list = add_to_list(list, 5);
	list = add_to_list(list, 4);
	list = add_to_list(list, 3);
	list = add_to_list(list, 2);
	list = add_to_list(list, 1);

	delete_from_list(list, 3);
	delete_from_list(list, 5);

	print_list(list);

	return 0;
}

void delete_from_list(struct node *list, int n)
{
	struct node *temp;

	for(temp = NULL; list != NULL && list->value != n; temp = list, list = list->next);

	if(list != NULL)
	{
		if(list->next == NULL)
			temp->next = NULL;
		else
			temp->next = list->next;

		free(list);
	}
}

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Error: malloc failed to add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;
	return new_node;
}

void print_list(struct node *list)
{
	while(list != NULL)
	{
		printf("%d\t", list->value);
		list = list->next;
	}

	printf("\n");
}
*/

/*
struct node *delete_from_list(struct node *list, int n)
{
	struct node *temp_node = list, *prev_node;

	if(temp_node != NULL && temp_node->value == n)
		list = list->next;
	else
	{
		while(temp_node->next != NULL)
		{
			if(temp_node->next->value == n)
			{
				prev_node = temp_node;
				temp_node = temp_node->next;
				prev_node->next = temp_node->next;
				break;
			}
			else
			{
				temp_node = temp_node->next;
			}
		}
	}

	free(temp_node);
	return list;
}
*/

//----------------------------------

// Q7

/*
 * After freeing the memory pointed to by p, p becomes a dangling pointer, meaning that
 * you can't access the memory that it points to, so the statement p = p->next is
 * undefined behavious because p still points to deallocated memory and we are trying to
 * access it by using p->next
 *
 * How to fix: Use another trailing pointer
 *
 * for(p = first; p != NULL; ) { temp = p; p = p->next; free(temp); }
 *
 */

//----------------------------------

// Q8 + Test script
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

//int contents[STACK_SIZE]; // was in stack.h (used for testing)
int top = 0; // was in stack.h (used for testing)

struct node
{
	int value;
	struct node *next;
} *contents = NULL; // Empty list (Top of the stack)



void make_empty(void);

bool is_empty(void);

bool push(int i);

int pop(void);

void stack_underflow(void); // Extra function for testing

void print_stack(struct node *list); // Extra function for testing


int main(void)
{
	// Make a list in this sequence: 1->2->3->4->5
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);

	print_list(contents);

	// Popping twice
	pop();
	pop();

	print_list(contents);

	// Making the list empty
	make_empty();
	print_list(contents);

	return 0;
}


// definitions in stack.c
void make_empty(void)
{
	struct node *temp;

	while(contents != NULL)
	{
		temp = contents;
		contents = contents->next;
		free(temp);
	}
}


bool is_empty(void)
{
	return contents == NULL;
}


bool push(int i)
{
	struct node *new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
		return false;

	new_node->value = i;
	new_node->next = contents;
	contents = new_node;

	return true;
}


int pop(void)
{
	if(is_empty())
	{
		stack_underflow();
	}

	struct node *temp = contents;
	int temp_val = temp->value;
	contents = contents->next;
	free(temp);

	return temp_val;
}


void stack_underflow(void)
{
	printf("Stack is empty!");
	exit(EXIT_FAILURE);
}

void print_stack(struct node *list)
{
	if(is_empty())
	{
		printf("Stack is empty\n");
		return;
	}

	while(list != NULL)
	{
		printf("%d\t", list->value);
		list = list->next;
	}

	printf("\n");
}
*/

//----------------------------------

// Q9

/*
 * True. (&x) acts as pointer to x so both statements are equivalent.
 *
 * Proof: (&x)->a = *(&x).a = *&x.a = *&(x.a) = x.a
 *
 */

//----------------------------------

// Q10
/*
#include <stdio.h>
#define NAME_LEN 30

struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

void print_part(struct part *p)
{
	printf("Part number: %d\n", p->number);
	printf("Part name: %s\n", p->name);
	printf("Quantity on hand: %d\n", p->on_hand);
}
*/

//----------------------------------

// Q11 + Test script
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

int count_occurrences(struct node *list, int n);

struct node *add_to_list(struct node *list, int n); // Extra for testing

int main(void)
{
	struct node *list = NULL; // List is empty at first
	int val;

	// 3->1->3->3->2->3->4->5->3: no(3) = 5
	list = add_to_list(list, 3);
	list = add_to_list(list, 5);
	list = add_to_list(list, 4);
	list = add_to_list(list, 3);
	list = add_to_list(list, 2);
	list = add_to_list(list, 3);
	list = add_to_list(list, 3);
	list = add_to_list(list, 1);
	list = add_to_list(list, 3);
	val = 3;

	printf("Number of occurrences of %d is %d\n", val, count_occurrences(list, val));

	return 0;
}

int count_occurrences(struct node *list, int n)
{
	int counter = 0;

	for(; list != NULL; list = list->next)
	{
		if(list->value == n)
			counter++;
	}

	return counter;
}


struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Error: malloc failed to add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;
	return new_node;
}
*/

//----------------------------------

// Q12 + Test script
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *find_last(struct node *list, int n);

struct node *add_to_list(struct node *list, int n); // Extra for testing

void print_node_and_next(struct node *list); // Extra for testing

int main(void)
{
	struct node *list = NULL; // List is empty at first

	// 3->1->3->3->2->3->4->5->3
	list = add_to_list(list, 3);
	list = add_to_list(list, 5);
	list = add_to_list(list, 4);
	list = add_to_list(list, 3);
	list = add_to_list(list, 2);
	list = add_to_list(list, 3);
	list = add_to_list(list, 3);
	list = add_to_list(list, 1);
	list = add_to_list(list, 3);

	struct node *p_1, *p_2, *p_3, *p_4, *p_5, *p_6;
	p_1 = find_last(list, 1);
	p_2 = find_last(list, 2);
	p_3 = find_last(list, 3);
	p_4 = find_last(list, 4);
	p_5 = find_last(list, 5);
	p_6 = find_last(list, 6);

	// We will know their positions by printing what's next to them
	print_node_and_next(p_1);
	print_node_and_next(p_2);
	print_node_and_next(p_3);
	print_node_and_next(p_4);
	print_node_and_next(p_5);
	print_node_and_next(p_6);


	return 0;
}

struct node *find_last(struct node *list, int n)
{
	struct node *last_n = NULL;

	for(; list != NULL; list = list->next)
	{
		if(list->value == n)
			last_n = list;
	}

	return last_n;
}


struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Error: malloc failed to add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;
	return new_node;
}

void print_node_and_next(struct node *list)
{
	if(list == NULL)
	{
		printf("Node is not found!\n");
		return;
	}

	printf("%d -> ", list->value);

	if(list->next != NULL)
		printf("%d\n", list->next->value);
	else
		printf("\n");
}
*/

//----------------------------------

// Q13

/*
 * This functions works correctly for in between nodes only. It doesn't handle
 * the cases of adding the node at first or at last.
 *
 * How is that?
 * At first: The condition in the while loop fails so the prev remains NULL
 * then: prev->next = new_node; fails because prev is a dangling pointer that
 * we can't access its memory to use assignment
 *
 * Fix: After the loop, we check if prev is NULL or not
 *
 *
 * At last: The condition itself becomes an error as cur became a dangling poninter
 * (of walue NULL) in the previous iteration. So, accessing its memory to check the
 * value member is undefined behavior leading to a program crash
 *
 * Fix: We add another condition in the loop to check cur to stop when it becomes NULL
 * to mark the ending of the list without accessing its memory content.
 *
 */


// Fix + Test script
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node);
void print_list(struct node *list); // Extra for testing
struct node *create_node(int n); // Extra for testing

int main(void)
{
	struct node *list = NULL; // List is empty at first


	// 3->1->3->3->2->3->4->5->3

	struct node *temp;
	temp = create_node(3);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(5);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(4);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(3);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(2);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(3);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(3);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(1);
	list = insert_into_ordered_list(list, temp);
	temp = create_node(3);
	list = insert_into_ordered_list(list, temp);
	print_list(list);

	return 0;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
	struct node *cur = list, *prev = NULL;

	while(cur != NULL // Last node case
			&& cur->value <= new_node->value)
	{
		prev = cur;
		cur = cur->next;
	}

	if(prev == NULL) // First node case
	{
		new_node->next = list;
		list = new_node;
	}
	else
	{
		prev->next = new_node;
		new_node->next = cur;
	}

	return list;
}


void print_list(struct node *list)
{
	while(list != NULL)
	{
		printf("%d\t", list->value);
		list = list->next;
	}

	printf("\n");
}

struct node *create_node(int n)
{
	struct node *temp_node = malloc(sizeof(struct node));
	temp_node->value = n;
	return temp_node;
}
*/

//----------------------------------

// Q14 + Test script
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

void delete_from_list(struct node **list, int n);
struct node *add_to_list(struct node *list, int n); // Extra for testing
void print_list(struct node *list); // Extra for testing


int main(void)
{
	struct node *list = NULL;

	list = add_to_list(list, 5);
	list = add_to_list(list, 4);
	list = add_to_list(list, 3);
	list = add_to_list(list, 2);
	list = add_to_list(list, 1);

	print_list(list);
	delete_from_list(&list, 3);
	print_list(list);
	delete_from_list(&list, 5);
	print_list(list);
	delete_from_list(&list, 1);
	print_list(list);

	return 0;
}


void delete_from_list(struct node **list, int n)
{
	struct node *cur = *list, *prev = NULL;
	for(; cur != NULL; prev = cur, cur = cur->next)
		if(cur->value == n)
			break;

	if(cur == NULL) // n is not found
		return;

	if(prev == NULL) // n is found at first
		*list = (*list)->next;
	else
	{
		prev->next = cur->next;
	}

	free(cur);
}


struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Error: malloc failed to add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;
	return new_node;
}


void print_list(struct node *list)
{
	printf("List contents: ");
	while(list != NULL)
	{
		printf("%d\t", list->value);
		list = list->next;
	}

	printf("\n");
}
*/

//----------------------------------

// Q15

/*
 * Output: 3
 *
 * How it works?
 * This program calls f2 number of times using the testing function f1 (through which
 * f2 is called) and stops when f2 returns 0. The input value that led to this result
 * is returned by the testing function f1.
 *
 * Program sequence:
 * f1(f2) ---> n = 0 ---> f2(0), n = 1 ---> f2(1), n = 2 ---> f2(2), n = 3 ---> f2(3)
 *
 */

//----------------------------------

// Q16 + Test script
/*
#include <stdio.h>

int sum(int (*f)(int), int start, int end);

int g(int n); // Extra for testing

int main(void)
{
	// Summation of g(1) to g(4) which equals 20 according to g
	printf("Sum = %d\n", sum(g, 1, 4));

	return 0;
}

int sum(int (*f)(int), int start, int end)
{
	int total = 0;

	for(int i = start; i <= end; i++)
		total += (*f)(i);

	return total;
}

int g(int n)
{
	return n * 2;
}
*/

//----------------------------------

// Q17

/*
 * A call to qsort:
 *
 * qsort(a + 50, 50, sizeof(int), compare);
 *
 * or
 *
 * qsort(&a[50], 50, sizeof(int), compare);
 *
 */

//----------------------------------

// Q18
/*

#define NAME_LEN 30
struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int compare_parts(const void *p, const void *q)
{
	const struct part *p1 = p;
	const struct part *p2 = q;

	if(p1->number > p2->number)
		return -1;
	else if(p1->number < p2->number)
		return 1;
	else
		return 0;
}
*/

//----------------------------------

// Q19 + Test script
/*
#include <stdio.h>
#include <string.h>

// Simplified command functions (Extra for testing)
void new_cmd(void) { printf("new_cmd is called\n"); }
void open_cmd(void) { printf("open_cmd is called\n"); }
void close_cmd(void) { printf("close_cmd is called\n"); }
void close_all_cmd(void) { printf("close_all_cmd is called\n"); }
void save_cmd(void) { printf("save_cmd is called\n"); }
void save_as_cmd(void) { printf("save_as_cmd is called\n"); }
void save_all_cmd(void) { printf("save_all_cmd is called\n"); }
void print_cmd(void) { printf("print_cmd is called\n"); }
void exit_cmd(void) { printf("exit_cmd is called\n"); }


struct
{
	char *cmd_name;
	void (*cmd_pointer)(void);
}
file_cmd[] =
{
		{"new", new_cmd},
		{"open", open_cmd},
		{"close", close_cmd},
		{"close all", close_all_cmd},
		{"save", save_cmd},
		{"save as", save_as_cmd},
		{"save all", save_all_cmd},
		{"print", print_cmd},
		{"exit", exit_cmd}
};


void enter_cmd(char *cmd);

int main(void)
{
	enter_cmd("new");
	enter_cmd("old");
	enter_cmd("save all");
	enter_cmd("Close");
	enter_cmd("exit");

	return 0;
}

void enter_cmd(char *cmd)
{
	for(int i = 0; i < 9; i++)
	{
		if(!strcmp(cmd, file_cmd[i].cmd_name))
		{
			file_cmd[i].cmd_pointer();
			return;
		}
	}

	printf("Invalid command\n");
}
*/
