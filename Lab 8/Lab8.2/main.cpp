#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

#define STRING_SIZE 100
#define SUF_SIZE 20

char** createMatrix(int count);
void inputMatrix(char** matrix, int count);
void printMatrix(char** matrix, int count);
void freeMatrix(char** matrix, int count);

void getSuffixes(char* suf1, char* suf2);
void replaceText(char* str, char* subStr, char* newStr);

int findSpaceIndex(char* str);

int main()
{
	printf("Insert rows count:\n");

	int count;
	scanf_s("%d", &count);

	char** matrix = createMatrix(count);

	getchar();

	inputMatrix(matrix, count);

	char* suf1 = (char*)malloc(SUF_SIZE * sizeof(char));
	char* suf2 = (char*)malloc(SUF_SIZE * sizeof(char));

	getSuffixes(suf1, suf2);

	for (int i = 0; i < count; i++)
	{
		replaceText(matrix[i], suf1, suf2);
	}

	printMatrix(matrix, count);

	freeMatrix(matrix, count);

	return 0;
}

char** createMatrix(int count)
{
	char** matrix = (char**)malloc(count * sizeof(char*));

	for (int i = 0; i < count; i++)
	{
		matrix[i] = (char*)malloc(STRING_SIZE * sizeof(char));
	}

	return matrix;
}

void inputMatrix(char** matrix, int count)
{
	printf("Insert Surname Name MiddleName:\n");
	for (int i = 0; i < count; i++)
	{
		gets_s(matrix[i], STRING_SIZE);
	}
}

void freeMatrix(char** matrix, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}

void printMatrix(char** matrix, int count)
{
	printf("\n");
	for (int i = 0; i < count; i++)
	{
		puts(matrix[i]);
	}
}

void getSuffixes(char* suf1, char* suf2)
{
	printf("Insert Suffixes wich will be changed:\n");
	gets_s(suf1, SUF_SIZE);
	gets_s(suf2, SUF_SIZE);

	realloc(suf1, strlen(suf1) + 1);
	realloc(suf2, strlen(suf2) + 1);
}

void replaceText(char* str, char* subStr, char* newStr)
{
	int surnameEnd = findSpaceIndex(str);

	while (strstr(str, subStr, surnameEnd))
	{
		char* buffer = (char*)malloc(STRING_SIZE * sizeof(char));
		strcpy(buffer, strstr(str, subStr, surnameEnd) + strlen(subStr));

		char* dest = strstr(str, subStr, surnameEnd) + strlen(newStr);

		char* p = strstr(str, subStr, surnameEnd);
		for (int i = 0; *p = newStr[i]; p++, i++);

		strcpy(dest, buffer);

		free(buffer);
	}

	realloc(str, strlen(str) + 1);
}

int findSpaceIndex(char* str)
{
	int i;
	for (i = 0; str[i] != ' ' && str[i]; i++);
	return i;
}