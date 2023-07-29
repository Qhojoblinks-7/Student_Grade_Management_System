#include "main.h"
#include <stdio.h>

void viewCoursesAndGradesForStudent(int studentID) {
    int studentIndex = findStudentByID(studentID);
    if (studentIndex == -1) {
        printf("Student with ID %d not found.\n", studentID);
        return;
    }

    struct Student* student = &students[studentIndex];

    printf("Courses and Grades for Student ID %d:\n", studentID);
    for (int i = 0; i < student->numCourses; i++) {
        printf("Course Code: %s\n", student->courses[i].code);
        printf("Course Title: %s\n", student->courses[i].title);
        printf("Course Credits: %d\n", student->courses[i].credits);
        printf("Grade: %d\n", student->grades[i]);
        printf("\n");
    }
}

