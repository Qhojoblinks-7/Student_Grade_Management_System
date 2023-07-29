#ifndef MAIN_H
#define MAIN_H

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_CONTACT_LENGTH 20
#define MAX_EMAIL_LENGTH 100
#define MAX_COURSES 10
#define MAX_COURSE_CODE_LENGTH 10
#define MAX_COURSE_TITLE_LENGTH 100

struct Courses;

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
	struct Course *courses[MAX_COURSES];
	int grades [MAX_COURSES];
	int numCourses;
	int isActive;
};

struct Courses{
	char code[MAX_COURSE_CODE_LENGTH];
	char title[MAX_COURSE_CODE_LENGTH];
	int credits;
};

void addStudent();
void dispalyAllStudent();
void editStudent();
int findStudentByID(int studentID);
void findStudentsByName(const char* name);
void saveStudentsToFile(const char* filename);
void loadStudentsFromFile(const char* filename);
void displayMenu();
void deleteStudent();
void retrieveInactiveStudents();
void addCourse(int studentID, const char* code, const char* title, int credits);
void removeCourse(int studentID, const char* code);
void updateCourse(int studentID, const char* oldCode, const char* newCode, const char* newTitle, int newCredits);
void updateGradeForCourse(int studentID, const char* courseCode, int newGrade);
void addGradeToCourse(int studentID, const char* courseCode, int grade);
void viewCoursesAndGradesForStudent(int studentID);
void calculateGPAForStudent(int studentID);
void displayTranscript(int studentID);
void displayGPAStatistics();
#endif
