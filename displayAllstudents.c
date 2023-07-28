#include "main.h"
#include <stdio.h>

/**
 * displayAllStudents - a function that displays information of all students
 * Return: nothing
 */

void displayAllStudents(void)
{
	int i;

	if (studentCount == 0)
	{
		printf("No students to display.\n");
	}
	for (i = 0; i < studentCount; i++)
	{
		printf("|ID: %d |", students[i].studentID);
		printf(" Name: %s %s %s |", students[i].lastName, students[i].firstName, students[i].midName);
		printf(" DOB: %s |", students[i].dateOfBirth);
		printf(" Gender: %s |", students[i].gender);
		printf(" Address: %s |", students[i].address);
		printf(" contact: %s |", students[i].contactNumber);
		printf(" Email: %s |\n", students[i].email);
		}
}
