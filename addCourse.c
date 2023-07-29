#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Course {
    char code[MAX_COURSE_CODE_LENGTH];
    char title[MAX_COURSE_TITLE_LENGTH];
    int credits;
};
/**
 * addCourse - a function that adds a new course for a gieven student
 * @studentID: student id
 * @code: the code for theat particular course
 * @title: course title
 * @credits: credits u get petaining to the course
 */

void addCourse(int studentID, const char *code, const char *title, int credits)
{
	int studentIndex = findStudentByID(studentID);
	int i;

	if (credits <= 0 || credits > MAX_COURSE_CREDITS) {
        printf("Invalid number of course credits. Please enter a value between 1 and %d.\n", MAX_COURSE_CREDITS);
        return;
	}

	if (studentIndex == -1)
	{
		printf("Student with ID %d not found.\n", studentID);
		return;
	}

	/* Get the student from the student array */
	struct Student *student = &students[studentIndex];

	/* check if the course already exist for the student */
	for (i = 0; i < student->numCourses; i++)
	{
		if (strcmp(student->courses[i]->code, code) == 0)
		{
			printf("Course with code '%s' already exists for Student ID %d.\n", code, studentID);
			return;
		}
	}

	/* check pf the student has reached the maximum number of courses*/
	if (student->numCourses == MAX_COURSES)
	{
		printf("Student ID %d has already reached the maximum number of courses (%d).\n", studentID, MAX_COURSES);
		return;
	}

	/*create new course for student*/
	struct Course* newCourse = (struct Course*)malloc(sizeof(struct Course *));
	if (newCourse == NULL)
	{
		printf("Memory allocation failed. Unable to add course to Student ID %d.\n", studentID);
		return;
	}

	/*set the course details*/
	strncpy(newCourse->code, code, MAX_COURSE_CODE_LENGTH);
	strncpy(newCourse->title, title, MAX_COURSE_TITLE_LENGTH);
	newCourse->credits = credits;

	/*add the new course to the student's course array*/
	student->courses[student->numCourses] = newCourse;
	student->grades[student->numCourses] = -1; /*Initialize grade to -1 (not assigned)*/
	student->numCourses++;

	printf("Course with code '%s' added to Student ID %d.\n", code, studentID);
}
