#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * saveStudentsToFile - a function that saves the student info
 * to a file.
 * @filename: the filename
 */

void saveStudentsToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        struct Student* student = &students[i];
        fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%d,%d",
                student->studentID, student->firstName, student->midName, student->lastName,
                student->dateOfBirth, student->gender, student->address, student->contactNumber,
                student->email, student->numCourses, student->isActive);

        for (int j = 0; j < student->numCourses; j++) {
            fprintf(file, ",%s,%s,%d,%d", student->courses[j]->code, student->courses[j]->title,
                    student->courses[j]->credits, student->grades[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Student data saved to file successfully.\n");
}
