#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 20

struct Student
{
	char* name;
	int marks[5];
	int category;
};

void inputStudents(Student** students, int count);
void defineStudentsCategory(Student** students, int count);
void sortStudents(Student** students, int count);
void swapStudents(Student* student1, Student* student2);
void copyStudent(Student* dest, Student* source);
void displayStudents(Student** students, int count);
void freeStudents(Student** students, int count);

int haveMark(Student* student, int mark);

void strCopyMy(char* dest, char* source);

int main()
{
	printf("How many student will be listed?\n");
	int count;
	scanf_s("%d", &count);
	getchar();

	printf("Insert Student Name and 5 marks\n");

	Student* students = (Student*)malloc(count * sizeof(Student));

	inputStudents(&students, count);

	defineStudentsCategory(&students, count);

	sortStudents(&students, count);

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

void defineStudentsCategory(Student** students, int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int mark = 2; mark <= 5; mark++)
		{
			if (haveMark(&((*students)[i]), mark))
			{
				(*students)[i].category = mark;			
				break;
			}
		}	
	}
}

void sortStudents(Student** students, int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if ((*students)[j].category < (*students)[j + 1].category)
			{
				swapStudents( &(*students)[j + 1], &(*students)[j] );
			}
		}
	}
}

int haveMark(Student* student, int mark)
{
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		if (student->marks[i] == mark)
		{
			result = 1;
			break;
		}
	}

	return result;
}

void swapStudents(Student* student1, Student* student2)
{
	Student tmp;
	tmp.name = (char*)malloc(STRING_SIZE * sizeof(char));

	copyStudent(&tmp, student1);

	copyStudent(student1, student2);

	copyStudent(student2, &tmp);

	free(tmp.name);
}

void copyStudent(Student* dest, Student* source)
{
	strCopyMy(dest->name, source->name);

	for (int i = 0; i < 5; i++) 
		dest->marks[i] = source->marks[i];

	dest->category = source->category;
}

void strCopyMy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
}

void displayStudents(Student** students, int count)
{
	char headers[4][15] = { "Dvoechniki: ", "Troechniki: ", "Horoshisty: ", "Otlichniki: " };
	int category = 5;

	for (int i = 0; i < count; )
	{
		printf("\n%s\n", headers[category - 2]);

		while ((*students)[i].category == category && i < count)
		{
			printf("%s \tmarks: ", (*students)[i].name);

			for (int j = 0; j < 5; j++)
				printf("%d ", (*students)[i].marks[j]);

			printf("\n");

			i++;
		}

		category--;
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