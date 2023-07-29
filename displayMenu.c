#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * displayMenu - a function that displays the menu of the
 * student database.
 */

void displayMenu(void)
{
    int choice;
    char filename[MAX_NAME_LENGTH];

    do {
        printf("\n------------- Academic Progress Menu -------------\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Find Students by Name\n");
        printf("5. Edit Student\n");
        printf("6. Delete Student\n");
        printf("7. Add Course\n");
        printf("8. Remove Course\n");
        printf("9. Update Course\n");
        printf("10. Add Grade\n");
        printf("11. Update Grade\n");
        printf("12. View Courses and Grades for Student\n");
        printf("13. Calculate GPA for Student\n");
        printf("14. Save Students to File\n");
        printf("15. Load Students from File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                dispalyAllStudent();
                break;
            case 3:
                printf("Enter the student ID: ");
                scanf("%d", &choice);
                findStudentByID(choice);
                break;
            case 4:
                printf("Enter the name to search for: ");
                scanf("%s", filename);
                findStudentsByName(filename);
                break;
            case 5:
                editStudent();
                break;
            case 6:
                printf("Enter the student ID to delete: ");
                scanf("%d", &choice);
                deleteStudent(choice);
                break;
            case 7:
                printf("Enter the student ID to add the course: ");
		scanf("%d", &choice);
		printf("Enter the course code: ");
		char code[MAX_COURSE_CODE_LENGTH];
		scanf("%s", code);
		printf("Enter the course title: ");
		char title[MAX_COURSE_TITLE_LENGTH];
		scanf("%s", title);
		printf("Enter the course credits: ");
		int credits;
		scanf("%d", &credits);
		addCourse(choice, code, title, credits);
		break;
            case 8:
                printf("Enter the student ID to remove the course: ");
                scanf("%d", &choice);
                printf("Enter the course code to remove: ");
                scanf("%s", filename);
                removeCourse(choice, filename);
                break;
            case 9:
                printf("Enter the student ID to update the course: ");
                scanf("%d", &choice);
                printf("Enter the course code to update: ");
                scanf("%s", filename);
                printf("Enter the new course code: ");
                char newCode[MAX_COURSE_CODE_LENGTH];
                scanf("%s", newCode);
                printf("Enter the new course title: ");
                char newTitle[MAX_COURSE_TITLE_LENGTH];
                scanf("%s", newTitle);
                printf("Enter the new course credits: ");
                int newCredits;
                scanf("%d", &newCredits);
                updateCourse(choice, filename, newCode, newTitle, newCredits);
                break;
            case 10:
                printf("Enter the student ID to add the grade: ");
                scanf("%d", &choice);
                printf("Enter the course code to add the grade: ");
                scanf("%s", filename);
                printf("Enter the grade to add: ");
                int gradeToAdd;
                scanf("%d", &gradeToAdd);
                addGradeToCourse(choice, filename, gradeToAdd);
                break;
            case 11:
                printf("Enter the student ID to update the grade: ");
                scanf("%d", &choice);
                printf("Enter the course code to update the grade: ");
                scanf("%s", filename);
                printf("Enter the new grade: ");
                int newGrade;
                scanf("%d", &newGrade);
                updateGradeForCourse(choice, filename, newGrade);
                break;
            case 12:
                printf("Enter the student ID to view courses and grades: ");
                scanf("%d", &choice);
                viewCoursesAndGradesForStudent(choice);
                break;
            case 13:
                printf("Enter the student ID to calculate GPA: ");
                scanf("%d", &choice);
                calculateGPAForStudent(choice);
                break;
            case 14:
                printf("Enter the filename to save: ");
                scanf("%s", filename);
                saveStudentsToFile(filename);
                break;
            case 15:
                printf("Enter the filename to load: ");
                scanf("%s", filename);
                loadStudentsFromFile(filename);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

