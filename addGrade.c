#include "main.h"
#include <stdio.h>
#include <string.h>

/* addGradeToCourse - a function that addas grades
 * @studentID: the student ID
 * @courseCode: course code
 * @grade: the grade to be added
 */

void addGradeToCourse(int studentID, const char* courseCode, int grade)
{
	int studentIndex = findStudentByID(studentID);

	if (grade < 0 || grade > 100) {
        printf("Invalid grade. Please enter a value between 0 and 100.\n");
        return;
	}

	if (studentIndex == -1)
	{
		printf("Student with ID %d not found.\n", studentID);
		return;
	}

	struct Student* student = &students[studentIndex];

	int i, courseIndex = -1;

	for (i = 0; i < student->numCourses; i++)
	{
		if (strcmp(student->courses[i].code, courseCode) == 0)
		{
			courseIndex = i;
			break;
		}
	}

	if (courseIndex == -1)
	{
		printf("Course with code '%s' not found for Student ID %d.\n", courseCode, studentID);
		return;
	}

	student->grades[courseIndex] = grade;

	printf("Grade %d added to Course with code '%s' for Student ID %d.\n", grade, courseCode, studentID);
}
