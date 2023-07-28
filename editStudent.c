#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * editStudent -  afunction that edits the infomation of a student
 * Return: nothing
 */


void editStudent(void)
{
	int studentID;

	printf("Enter the ID of the student to edit: ");
	scanf("%d", &studentID);

	int studentIndex = findStudentByID(studentID);

	if (studentIndex == -1)
	{
		printf("Student ID %d not found", studentID);
		return;
	}

	struct Student *editedStudent = &students[studentIndex];

	char buffer[MAX_NAME_LENGTH];/* Temporary buffer for reading strings*/

	printf("Current last name: %s\n", editedStudent->lastName);
	printf("Enter new name (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->lastName, buffer, MAX_NAME_LENGTH);
	}

	printf("Current first name: %s\n", editedStudent->firstName);
	printf("Enter new name (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->firstName, buffer, MAX_NAME_LENGTH);
	}

	printf("Current middle name: %s\n", editedStudent->midName);
	printf("Enter new name (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->midName, buffer, MAX_NAME_LENGTH);
	}

	printf("Current date of birth: %s\n", editedStudent->dateOfBirth);
	printf("Enter new date of birth (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->dateOfBirth, buffer, MAX_NAME_LENGTH);
	}

	printf("Current gender: %s\n", editedStudent->gender);
	printf("Enter new gender (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->gender, buffer, MAX_NAME_LENGTH);
	}

	printf("Current address: %s\n", editedStudent->address);
	printf("Enter new address (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->address, buffer, MAX_ADDRESS_LENGTH);
	}

	printf("Current contact number: %s\n", editedStudent->contactNumber);
	printf("Enter new contact number (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->contactNumber, buffer, MAX_ADDRESS_LENGTH);
	}

	printf("Current email: %s\n", editedStudent->email);
	printf("Enter email (leave blank if no change): ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';/*Remove the trailing newline*/
	if (buffer[0] != '\0')
	{
		strncpy(editedStudent->email, buffer, MAX_EMAIL_LENGTH);
	}

	printf("Student information updated successfully!\n");
}
