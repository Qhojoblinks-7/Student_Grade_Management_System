#include "main.h"
#include <stdio.h>

/**
 * updateCourse - a function that updates the courses of a studeny
 * @studentID: the student ID
 * @oldCode: course formal code
 * @newCode: course new code
 * @newTitle: corse new title
 * @newCredits: new credits
 */

void updateCourse(int studentID, const char* oldCode, const char* newCode, const char* newTitle, int newCredits)
{
	int studentIndex = findStudentByID(studentID);

	if (studentIndex == -1)
	{
		printf("Student with ID %d not found.\n", studentID);
		return;
	}

	struct Student *student = &students[studentIndex];

	/*find the index of the old code in the course's array*/
	int i, courseIndex = -1;

	for (i = 0; i < student->numCourses; i++)
	{
		if (strcmp(student->courses[i]->code, oldCode) == 0)
		{
			courseIndex = i;
			break;
		}
	}

	if (courseIndex == -1)
	{
		printf("Course with code '%s' not found for Student ID %d.\n", oldCode, studentID);
		retuen;
	}

	/*update the course with new values*/
	strncpy(student->courses[courseIndex]->code, newCode, MAX_COURSE_CODE_LENGTH);
	strncpy(student->courses[courseIndex]->title, newTitle, MAX_COURSE_TITLE_LENGTH);
	student->courses[courseIndex]->credits = newCredits;

	printf("Course with code '%s' updated for Student ID %d.\n", oldCode, studentID);
}
