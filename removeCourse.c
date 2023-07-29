#include "main.h"
#include <string.h>
#include <stdio.h>
/*Full definition of struct Course*/
struct Course
{
	char code[MAX_COURSE_CODE_LENGTH];
	char title[MAX_COURSE_TITLE_LENGTH];
	int credits;
};

/**
 * removeCourseFromStudent - a function tha removes a course from the
 * list of courses the student is studing.
 * @studentID: the student ID
 * @code: the course code.
 */

void removeCourseFromStudent(int studentID, const char* code)
{
	int studentIndex = findStudentByID(studentID);

	if (studentIndex == -1)
	{
		printf("Student with ID %d not found.\n", studentID);
		return;
	}

	/*get the student from the students array*/
	struct Student *student = &students[studentIndex];

	/*find the index of the course in the students's course array*/
	int i, courseIndex = -1;

	for (i = 0; i <student->numCourses; i++)
	{
		if (strcmp(student->courses[i]->code, code) == 0)
		{
			courseIndex = i;
			break;
		}
	}

	if (courseIndex == -1)
	{
		printf("Course with code '%s' not found for Student ID %d.\n", code, studentID);
		return;
	}

	/*Move the last course in the array to the position of the removed course*/
	student->courses[courseIndex] = student->courses[student->numCourses - 1];
	student->grades[courseIndex] = student->grades[student->numCourses - 1];

	/*Decrement the number of courses for the student*/
	student->numCourses--;
	printf("Course with code '%s' removed from Student ID %d.\n", code, studentID);
}
