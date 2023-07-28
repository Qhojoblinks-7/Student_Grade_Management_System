#include <stdio.h>
#include "main.h"

/**
 * deleteStudent - a function that deletes a student based on the ID
 * Return: nothing
 */

void deleteStudent()
{
	int studentID;

	printf("Enter the ID of the student to delete: ");
	scanf("%d", &studentID);

	int studentIndex = findStudentByID(studentID);
	if (studentIndex == -1)
	{
		printf("Student ID %d not found\n", studentID);
		return;
	}

	students[studentIndex].isActive = 0; /*Mark the student as inactive*/

	printf("Student with ID %d deleted successfully!\n", studentID);
}
