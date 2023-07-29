// transcript.c

#include "main.h"
#include <stdio.h>
#include <string.h>

void displayTranscript(int studentID) {
    int studentIndex = findStudentByID(studentID);
    if (studentIndex == -1) {
        printf("Student with ID %d not found.\n", studentID);
        return;
    }

    struct Student* student = &students[studentIndex];

    printf("Transcript for Student ID %d:\n", student->studentID);
    printf("Name: %s %s %s\n", student->firstName, student->midName, student->lastName);
    printf("Date of Birth: %s\n", student->dateOfBirth);
    printf("Gender: %s\n", student->gender);
    printf("Address: %s\n", student->address);
    printf("Contact Number: %s\n", student->contactNumber);
    printf("Email: %s\n", student->email);

    printf("Courses Taken:\n");
    for (int i = 0; i < student->numCourses; i++) {
        printf("Course Code: %s\n", student->courses[i]->code);
        printf("Course Title: %s\n", student->courses[i]->title);
        printf("Credits: %d\n", student->courses[i]->credits);
        printf("Grade: %d\n", student->grades[i]);
        printf("\n");
    }
}

