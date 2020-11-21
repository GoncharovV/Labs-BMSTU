#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 20

struct Student
{
	char* name;
	int marks[5];
	float averageMark;
};

void inputStudents(Student** students, int count);
void copyStudent(Student* dest, Student* source);
void strCopyMy(char* dest, char* source);
void deleteUnderachievers(Student** students, int* count);
void shiftStudents(Student** students, int from, int count);
void setAverageMarks(Student** students, int count);
void displayStudents(Student** students, int count);
void freeStudents(Student** students, int count);

int isUnderachiever(Student* student);
float calcAverageMark(int* mark);

int main()
{
	printf("How many student will be listed?\n");
	int count;
	scanf_s("%d", &count);
	getchar();

	printf("Insert Student Name and 5 marks\n");

	Student* students = (Student*)malloc(count * sizeof(Student));

	inputStudents(&students, count);

	deleteUnderachievers(&students, &count);

	setAverageMarks(&students, count);

	displayStudents(&students, count);

	freeStudents(&students, count);

	return 0;
}

void inputStudents(Student** students, int count)
{
	for (int i = 0; i < count; i++)
	{
		(*students)[i].name = (char*)malloc(STRING_SIZE * sizeof(char));

		gets_s((*students)[i].name, STRING_SIZE);

		for (int j = 0; j < 5; j++)
			scanf_s("%d", &(*students)[i].marks[j]);

		getchar();
	}
}

void deleteUnderachievers(Student** students, int* count)
{
	for (int i = 0; i < *count; i++)
	{
		if (isUnderachiever( &(*students)[i] ))
		{
			shiftStudents(students, i, *count);
			(*count)--;
		}		
	}
}

int isUnderachiever(Student* student)
{
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		if (student->marks[i] == 2)
			result++;
	}

	if (result <= 2)
		result = 0;
	
	return result;
}

void copyStudent(Student* dest, Student* source)
{
	strCopyMy(dest->name, source->name);

	for (int i = 0; i < 5; i++)
		dest->marks[i] = source->marks[i];
}

void strCopyMy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
}

void shiftStudents(Student** students, int from, int count)
{
	for (int i = from; i < count - 1; i++)
	{
		copyStudent(&(*students)[i], &(*students)[i + 1]);
	}

	realloc(*students, (count - 1) * sizeof(Student));
}

void setAverageMarks(Student** students, int count)
{
	for (int i = 0; i < count; i++)
	{
		(*students)[i].averageMark = calcAverageMark((*students)[i].marks);
	}
}

float calcAverageMark(int* marks)
{
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		result += marks[i];
	}

	return (float)result / 5;
}

void displayStudents(Student** students, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("\n%s \tmarks: ", (*students)[i].name);

		for (int j = 0; j < 5; j++)
			printf("%d ", (*students)[i].marks[j]);

		printf("Average mark is - %.3f", (*students)[i].averageMark);

		printf("\n");
	}
}

void freeStudents(Student** students, int count)
{
	for (int i = 0; i < count; i++)
	{
		free((*students)[i].name);
	}

	free(*students);
}