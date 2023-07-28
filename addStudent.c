#include "main.h"
#include <stdlib.h>

/**
 * addStudent - this function adds a new student
 * Return: nothing
 */

void addStudent()
{
	int c;

	if (studenCount == MAX_STUDENTS)
	{
		printf ("Maximum student capacitty reached.\n");
		return;

	}

	struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));

	if (newStudent == NULL)
	{
		printf("Memory allocation failed. Unable to add student.\n");
		return;
	}

	/*clear the input buffer to prevent issues with fgets*/
	while ((c = getchar()) != '\n' && c !+ EOF);

	printf("Enter student ID: ");
	scanf("%d", &newStudent -> studentID);

	printf("Enter last name: ");
	fgets(newStudent -> lastName, MAX_NAME_LENGTH, stdin);
	newStudent -> lastName[strcspn(newStudent -> lastName, "\n")] = '\0';/*Remove the trailing newline*/

	 printf("Enter first name: ");
	 fgets(newStudent -> firstName,MAX_NAME_LENGTH, stdin);
	 newStudent -> firstName[strcpn(newStudent -> firstName, "\n")] = '\0';

	 printf("Enter middle name: ");
	 fgets(newStudent -> midName,MAX_NAME_LENGTH, stdin);
	 newStudent -> midName[strcpn(newStudent -> midName, "\n")] = '\0';

	 printf("Enter date of birth: ");
	 fgets(newStudent -> dateOfBirth,MAX_NAME_LENGTH, stdin);
	 newStudent -> dateOfBirth[strcpn(newStudent -> dateOfBirth, "\n")] = '\0';

	 printf("Enter gender: ");
	 fgets(newStudent -> gender,MAX_NAME_LENGTH, stdin);
	 newStudent -> gender[strcpn(newStudent -> gender, "\n")] = '\0';

	 printf("Enter address: ");
	 fgets(newStudent -> address,MAX_ADDRESS_LENGTH, stdin);
	 newStudent -> adress[strcpn(newStudent -> address, "\n")] = '\0';

	 printf("Enter contact number: ");
	 fgets(newStudent -> contactNumber, MAX_CONTACT_LENGTH, stdin);
	 newStudent -> contactNumber[strcpn(newStudent -> contactNumber, "\n")] = '\0';

	 printf("Enter email: ");
	 fgets(newStudent -> contactNumber, MAX_EMAIL_LENGTH, stdin);
	 newStudent->email[strcspn(newStudent->email, "\n")] = '\0';

	 students[studentsCount] = *newStudent;
	 studentCount++;

	 printf("Student added successfully!\n");

	 /*Free the dynamically allocated memory for the newStudent pointer*/
	 free(newStudent);
}
