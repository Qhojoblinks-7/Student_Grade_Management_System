#include "main.h"
#include <stdio.h>

/**
 * loadStudentsFromFile - a function that loads info from a file
 * @filename: the name of the file.
 */

void loadStudentsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[4096];
    while (fgets(line, sizeof(line), file) != NULL) {
        struct Student newStudent;
        int numCourses;

        // Parse the line to extract student data
        int fieldsRead = sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d",
                                &newStudent.studentID, newStudent.firstName, newStudent.midName,
                                newStudent.lastName, newStudent.dateOfBirth, newStudent.gender,
                                newStudent.address, newStudent.contactNumber, newStudent.email,
                                &numCourses, &newStudent.isActive);

        if (fieldsRead != 11) {
            printf("Error parsing student data from file.\n");
            continue;
        }

        newStudent.numCourses = numCourses;
        if (newStudent.numCourses > MAX_COURSES) {
            printf("Number of courses for student ID %d exceeds the maximum limit. Ignoring additional courses.\n", newStudent.studentID);
            newStudent.numCourses = MAX_COURSES;
        }

        // Read and process course and grade data for each student
        for (int i = 0; i < newStudent.numCourses; i++) {
            char courseCode[MAX_COURSE_CODE_LENGTH];
            char courseTitle[MAX_COURSE_TITLE_LENGTH];
            int courseCredits, grade;

            if (fscanf(file, ",%[^,],%[^,],%d,%d", courseCode, courseTitle, &courseCredits, &grade) != 4) {
                printf("Error parsing course data for student ID %d from file.\n", newStudent.studentID);
                break;
            }

            // Search for the course in the global courses array
            int courseIndex = findCourseByCode(courseCode);
            if (courseIndex == -1) {
                printf("Course with code %s not found in the list of courses. Ignoring this course for student ID %d.\n", courseCode, newStudent.studentID);
                continue;
            }

            newStudent.courses[i] = &courses[courseIndex];
            newStudent.grades[i] = grade;
        }

        // Add the student to the global students array
        students[studentCount] = newStudent;
        studentCount++;

        // Skip the newline character at the end of the line
        fgetc(file);
    }

    fclose(file);
    printf("Student data loaded from file successfully.\n");
}
