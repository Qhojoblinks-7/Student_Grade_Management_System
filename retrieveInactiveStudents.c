#include "main.h"
#include <sdtio.h>

/**
 * retrieveInactiveStudents - a function that helps retrieve
 * student info that has been marked inactive
 * Return: nothing
 */

void retrieveInactiveStudents()
{
	int inactiveStudentCount = 0;
	int i;

	/*Count the number of inactive students*/
	for (i = 0; i < studentCount; i++)
	{
		if (students[i].isActive == 0)
		{
			inactiveStudentCount++;
		}
	}

	if (inactiveStudentCount == 0)
	{
		printf("No inactive students found.\n");
		return;
	}

	printf("Inactive Students:\n");
	for (i = 0; i < studentCount; i++)
	{
		if (students[i].isActive == 0)
		{
			printf("Student ID: %d\n", students[i].studentID);
			printf("First Name: %s\n", students[i].firstName);
			printf("Last Name: %s\n", students[i].lastName);
			printf("Date of Birth: %s\n", students[i].dateOfBirth);
			printf("Gender: %s\n", students[i].gender);
			printf("Address: %s\n", students[i].address);
			printf("Contact Number: %s\n", students[i].contactNumber);
			printf("Email: %s\n", students[i].email);
			printf("\n");

		}
	}

	/*Ask the user if they want to activate any inactive students*/
	char choice;
	int studentID;
	int yes = 1;
	int Yes = 1;
	printf("Do you want to activate any inactive students? (Yes/No): ");
	scanf(" %c", &choice);

	if (choice == yes || choice == Yes)
	{
		printf("Enter the ID of the student you want to activate: ");
		scanf("%d", &studentID);

		int studentIndex = findStudentByID(studentID);
		if (studentIndex == -1 || students[studentIndex].isActive == 1)
		{
			printf("Invalid student ID or the student is already active.\n");
			return;
		}
		students[studentIndex].isActive = 1;

		printf("Student with ID %d has been activated!\n", studentID);
	}
}

