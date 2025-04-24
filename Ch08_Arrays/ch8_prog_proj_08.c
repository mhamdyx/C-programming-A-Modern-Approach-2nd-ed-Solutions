/*
 * ch8_prog_proj_08.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 8: 5 x 5 array of integers (modified)

#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_QUIZZES 5
#define MAX_GRADE 100
#define MIN_GRADE 0

int main(void)
{
	int grades[NUM_STUDENTS][NUM_QUIZZES], student, quiz;
	int total_grades = 0, highest_grade = MIN_GRADE, lowest_grade = MAX_GRADE;
	float avg_grade;

	for (student = 0; student < NUM_STUDENTS; student++)
	{
		printf("Enter student %d grades: ", student + 1);
		for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
			scanf("%d", &grades[student][quiz]);
	}

	// Computing total grades and average grade per student
	printf("\nStudent  Total  Average\n");
	for (student = 0; student < NUM_STUDENTS; student++)
	{
		printf("%4d     ", student + 1);

		for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
			total_grades += grades[student][quiz];

		avg_grade = (float)total_grades / NUM_QUIZZES;

		printf("%4d   %6.2f\n", total_grades, avg_grade);

		total_grades = 0; // Reset for next calculation
	}

	// Computing average score, high score, lowe score for each quiz
	printf("\nQuiz  Average  Highest  Lowest\n");

	for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
	{
		printf("%3d   ", quiz + 1);

		for (student = 0; student < NUM_STUDENTS; student++)
		{
			total_grades += grades[student][quiz];

			if (grades[student][quiz] > highest_grade)
				highest_grade = grades[student][quiz];

			if (grades[student][quiz] < lowest_grade)
				lowest_grade = grades[student][quiz];
		}

		avg_grade = (float)total_grades / NUM_STUDENTS;

		printf("%6.2f   %4d     %4d\n", avg_grade, highest_grade, lowest_grade);

		// Reset for next calculations
		total_grades = 0;
		highest_grade = MIN_GRADE;
		lowest_grade = MAX_GRADE;
	}

	return 0;
}
