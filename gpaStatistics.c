#include "main.h"
#include <stdio.h>
#include <string.h>

void displayGPAStatistics() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }

    double totalGPA = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < studentCount; i++) {
        struct Student* student = &students[i];
        double studentGPA = 0.0;
        int totalStudentCredits = 0;

        for (int j = 0; j < student->numCourses; j++) {
            studentGPA += student->grades[j] * student->courses[j]->credits;
            totalStudentCredits += student->courses[j]->credits;
        }

        if (totalStudentCredits > 0) {
            studentGPA /= totalStudentCredits;
            totalGPA += studentGPA;
            totalCredits += totalStudentCredits;
        }

        printf("Student ID: %d, GPA: %.2f\n", student->studentID, studentGPA);
    }

    if (totalCredits > 0) {
        totalGPA /= totalCredits;
        printf("Overall GPA for all students: %.2f\n", totalGPA);
    } else {
        printf("Overall GPA for all students: N/A\n");
    }
}

