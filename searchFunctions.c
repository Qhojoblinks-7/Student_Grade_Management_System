#include "main.h"
#include <stdio.h>

/**
 * findStudentByID -  a function that searches for student ID
 * Return: an int if success else -1
 */

int findStudentByID(int studentID)
{
	int i;

	for (i = 0; i < studentCount; i++)
	{
		if (students[i].studentID == studentID)
		{
			return (i);
		}
	}

	return (-1)
}
