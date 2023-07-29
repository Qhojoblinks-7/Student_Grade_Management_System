#include "main.h"
#include <stdio.h>

/**
 * calculateGPAForStudent - a function that calculates the GPA for a
 * student based on their grades and credits
 * @studentID: the input taken to perform the operation
 * Return: GPA
 */

float calculateGPAForStudent(int studentID)
{
	int i, studentIndex = findStudentByID(studentID);

	if (studentIndex == -1)
	{
		printf("Student with ID %d not found.\n", studentID);
		return -1.0;
	}

	struct Student* student = &students[studentIndex];

	float totalCredits = 0.0;
	float totalGradeCredits = 0.0;

	for (i = 0; i < student->numCourses; i++)
	{
		int grade = student->grades[i];
		int credits = student->courses[i].credits;

		totalGradeCredits += grade * credits;
		totalCredits += credits;
	}

	if (totalCredits == 0.0)
	{
		printf("No courses found for Student ID %d.\n", studentID);
		return -1.0;
	}

	float GPA = totalGradeCredits / totalCredits;
	return GPA;

}
