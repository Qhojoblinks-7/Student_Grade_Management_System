#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * findStudentsByName - a function that finds the details of a student
 * by name.
 * @name: the name to be searched
 * Return: nothing
 */

void findStudentsByName(const char *name)
{
	int foundCount = 0;
	int i;

	for (i = 0; i < studentCount; i++)
	{
		if (strstr(students[i].firstName, name) != NULL)
		{
			printf("Student ID: %d\n", students[i].studentID);
			printf("First Name: %s\n", students[i].firstName);
			printf("\n");
			foundCount++;
		}

		if (strstr(students[i].midName, name) != NULL)
		{
			printf("Student ID: %d\n", students[i].studentID);
			printf("Middle Name: %s\n", students[i].midName);
			printf("\n");
			foundCount++;
		}

		if (strstr(students[i].lastName, name) != NULL)
		{
			printf("Student ID: %d\n", students[i].studentID);
			printf("Last Name: %s\n", students[i].lastName);
			printf("\n");
			foundCount++;
		}
	}
	if (foundCount == 0)
	{
		printf("No students found with the name '%s'\n", name);
	}
}
