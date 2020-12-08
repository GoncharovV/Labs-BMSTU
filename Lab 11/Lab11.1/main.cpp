#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 200
#define ROWS_COUNT 30

char** createMatrix(int n);
void strCopyMy(char* dest, char* source);

void readData(char** data, FILE** file, int *rowsCount);

void shiftMatrix(char** matrix, int from, int count);
void deleteEmptyRows(char** data, int *rowsCount);
void listRows(char** data, int rowsCount);

void strins(char* str, char* sub);
void strCatMy(char* dest, char* src);
void freeMatrix(char** matrix, int n);

void writeToNewFile(char** data, int rowsCount);

int main()
{
	int rowsCount = ROWS_COUNT;

	FILE* file;
	fopen_s(&file, "text.txt", "r");

	if (file)
	{
		char** data = createMatrix(rowsCount);

		readData(data, &file, &rowsCount);

		deleteEmptyRows(data, &rowsCount);

		listRows(data, rowsCount);

		writeToNewFile(data, rowsCount);

		freeMatrix(data, rowsCount);

		fclose(file);
	}

	return 0;
}

char** createMatrix(int n)
{
	char** matrix = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		matrix[i] = (char*)malloc(STRING_SIZE * sizeof(char));
	}

	return matrix;
}

void readData(char** data, FILE** file, int *rowsCount)
{
	for (int i = 0; i < *rowsCount; i++)
	{
		fgets(data[i], STRING_SIZE, *file);

		if (feof(*file))
		{
			*rowsCount = i;
			break;
		}
	}
}

void strCopyMy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
}

void shiftMatrix(char** matrix, int from, int count)
{
	for (int i = from; i < count - 1; i++)
	{
		strCopyMy(matrix[i], matrix[i + 1]);
	}

	realloc(matrix, (count - 1) * sizeof(matrix));
}

void deleteEmptyRows(char** data, int *rowsCount)
{
	for (int i = 0; i < *rowsCount; i++)
	{
		if (data[i][0] == '\n')
		{
			shiftMatrix(data, i, *rowsCount);
			(*rowsCount)--;
		}
	}
}

void listRows(char** data, int rowsCount)
{
	char number[5];
	char decoration[] = ". ";

	for (int i = 0; i < rowsCount; i++)
	{
		_itoa_s(i + 1, number, 10);
		strCatMy(number, decoration);
		strins(&data[i][0], number);
	}
}

void strins(char* str, char* sub)
{
	char* tmp = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strCopyMy(tmp, str);
	strCopyMy(str, sub);
	strCatMy(str, tmp);
	free(tmp);

}

void strCatMy(char* dest, char* src)
{
	int len = strlen(dest);
	for (int i = 0; dest[i + len] = src[i]; i++);
}

void freeMatrix(char** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}

void writeToNewFile(char** data, int rowsCount)
{
	FILE* newFile;
	fopen_s(&newFile, "newFile.txt", "w");

	if (newFile)
	{
		for (int i = 0; i < rowsCount; i++)
		{
			fputs(data[i], newFile);
		}

		fclose(newFile);
	}
}