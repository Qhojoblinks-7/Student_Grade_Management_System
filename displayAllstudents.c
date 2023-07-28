#include "main.h"

/**
 * displayAllStudents - a function that displays information of all students
 * Return: nothing
 */

void displayAllStudents()
{
	int i;
	if (studentCount == 0)
	{
		printf("No students to display.\n");
	}
	for (i = 0; i < studentCount; i++)
	{
		printf("ID: %d | Name: %s %s %s | DOB: %s | Gender: %s | Address: %s | Contact: %s | Email: %s\n",
					students[i].studentID,
					students[i].lastName,
					students[i].firstName,
					students[i].midName,
					students[i].dateOfBirth,
					students[i].gender,
					students[i].address,
					students[i].contactNumber,
					students[i].email);
		}
}
