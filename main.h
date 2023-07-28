#ifndef MAIN_H
#define MAIN_H

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_CONTACT_LENGTH 20
#define MAX_EMAIL_LENGTH 100

struct Student {
	int studentID;
	char firstName[MAX_NAME_LENGTH];
	char midName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	char dateOfBirth[MAX_NAME_LENGTH];
	char gender[MAX_NAME_LENGTH];
	char address[MAX_ADDRESS_LENGTH];
	char contactNumber[MAX_CONTACT_LENGTH];
	char email[MAX_EMAIL_LENGTH];
	int isActive;
};

void addStudent();
void dispalyAllStudent();
void editStudent();
int findStudentByID(int studentID);
void deleteStudent();
void retrieveInactiveStudents();
#endif
