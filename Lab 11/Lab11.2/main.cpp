#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

#define STR_LEN 200
#define MAX_ROWS 40
#define PATH "books.txt"

const int len = 255;

struct Book
{
	char Name[len];
	char Author[len];
	int PageCount;
	int Rank;
};

void displayMainMenu();

void addBook();
void displayBooks();
void sortBooks();
void deleteBook();

char** createMatrix(int n);
void freeMatrix(char** matrix, int n);

void readData(char** data, FILE** file, int* rowsCount);

void setBook(char* str, Book* book);
void copyBook(Book* dest, Book* source);
void swapBooks(Book* book1, Book* book2);
void printBook(Book* book);

void bobleSort(Book** books, int rowsCount);
void deleteBooksByAuthor(Book** books, char* author, int *rowsCount);
void printBooks(Book** books, int rowsCount);
void shiftBooks(Book** books, int rowsCount, int from);

void updateFile(Book** books, int rowCount);

int main()
{
	displayMainMenu();

	int action;
	scanf_s("%d", &action);
	getchar();

	switch (action)
	{
		case 1:
			addBook();
			break;

		case 2:
			displayBooks();
			break;

		case 3:
			sortBooks();
			break;

		case 4:
			deleteBook();
			break;
	}

	return 0;
}

void displayMainMenu()
{
	printf("   Welcome\n What do you want to do?\n Add new Book - (1)\n Display all Books - (2)\n Sort Books by rank - (3)\n Delete Books by Author - (4)\n Exit - (5)\n > ");
}

void addBook()
{
	FILE* file;
	fopen_s(&file, PATH, "a");

	if (file)
	{
		printf("Insert BookName Author PageCount Rank via space:\n > ");

		char* str = (char*)malloc(STR_LEN * sizeof(char));
		gets_s(str, STR_LEN);

		fputs("\n", file);
		fputs(str, file);

		free(str);
		fclose(file);
	}
}

void displayBooks()
{
	FILE* file;
	fopen_s(&file, PATH, "r");

	if (file)
	{
		printf("\n   Books in file:\n");

		int rowsCount = MAX_ROWS;
		char** data = createMatrix(rowsCount);

		readData(data, &file, &rowsCount);
		realloc(data, rowsCount * sizeof(char*));

		for (int i = 0; i < rowsCount; i++)
		{
			printf(" %s", data[i]);
		}

		freeMatrix(data, rowsCount);
		fclose(file);
	}
}

void sortBooks()
{
	FILE* file;
	fopen_s(&file, PATH, "r");

	if (file)
	{
		int rowsCount = MAX_ROWS;
		char** data = createMatrix(rowsCount);

		readData(data, &file, &rowsCount);
		realloc(data, rowsCount * sizeof(char*));

		Book* books = (Book*)malloc(rowsCount * sizeof(Book));

		for (int i = 0; i < rowsCount; i++)
		{
			setBook(data[i], &books[i]);
		}

		bobleSort(&books, rowsCount);

		printBooks(&books, rowsCount);

		fclose(file);

		freeMatrix(data, rowsCount);
		free(books);
	}
}

void deleteBook()
{
	FILE* file;
	fopen_s(&file, PATH, "r");
	
	if (file)
	{
		printf("Which author do you want to delete? (name)\n > ");

		char* author = (char*)malloc(STR_LEN * sizeof(char));
		gets_s(author, STR_LEN);

		int rowsCount = MAX_ROWS;
		char** data = createMatrix(rowsCount);

		readData(data, &file, &rowsCount);
		realloc(data, rowsCount * sizeof(char*));

		Book* books = (Book*)malloc(rowsCount * sizeof(Book));

		for (int i = 0; i < rowsCount; i++)
		{
			setBook(data[i], &books[i]);
		}

		deleteBooksByAuthor(&books, author, &rowsCount);
		realloc(data, rowsCount * sizeof(char*));

		printBooks(&books, rowsCount);

		fclose(file);

		updateFile(&books, rowsCount);

		freeMatrix(data, rowsCount);
		free(books);
	}
}

char** createMatrix(int n)
{
	char** matrix = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		matrix[i] = (char*)malloc(STR_LEN * sizeof(char));
	}

	return matrix;
}

void readData(char** data, FILE** file, int* rowsCount)
{
	int i;
	for (i = 0; i < *rowsCount && !feof(*file); i++)
	{
		fgets(data[i], STR_LEN, *file);
	}

	*rowsCount = i;
}

void setBook(char* str, Book* book)
{
	char** parsedString = createMatrix(4);
	
	char sep[] = " ";
	parseWords(&parsedString, str, sep);

	strCopyMy(book->Name, parsedString[0]);
	strCopyMy(book->Author, parsedString[1]);

	book->PageCount = atoi(parsedString[2]);
	book->Rank = atoi(parsedString[3]);

	freeMatrix(parsedString, 4);
}

void swapBooks(Book* book1, Book* book2)
{
	Book tmp;
	copyBook(&tmp, book1);

	copyBook(book1, book2);
	copyBook(book2, &tmp);
}

void copyBook(Book* dest, Book* source)
{
	strCopyMy(dest->Name, source->Name);
	strCopyMy(dest->Author, source->Author);
	dest->PageCount = source->PageCount;
	dest->Rank = source->Rank;
}

void bobleSort(Book** books, int rowsCount)
{
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < rowsCount - 1; j++)
		{
			if ((*books)[j].Rank < (*books)[j + 1].Rank)
			{
				swapBooks( &((*books)[j]) , &((*books)[j + 1]));
			}
		}
	}
}

void printBook(Book* book)
{
	printf(" %s %s %d %d\n", book->Name, book->Author, book->PageCount, book->Rank);
}

void printBooks(Book** books, int rowsCount)
{
	for (int i = 0; i < rowsCount; i++)
	{
		printBook(&(*books)[i]);
	}
}

void deleteBooksByAuthor(Book** books, char* author, int *rowsCount)
{
	for (int i = 0; i < *rowsCount; i++)
	{
		if (!strcmp((*books)[i].Author, author))
		{
			shiftBooks(books, *rowsCount, i);
			(*rowsCount)--;
			i--;
		}
	}
}

void shiftBooks(Book** books, int rowsCount, int from)
{
	for (int i = from; i < rowsCount - 1; i++)
	{
		copyBook(&(*books)[i], &(*books)[i + 1]);
	}

	realloc(*books, (rowsCount - 1) * sizeof(Book));
}

void updateFile(Book** books, int rowCount)
{
	FILE* file;
	fopen_s(&file, PATH, "w");
	
	if (file)
	{
		for (int i = 0; i < rowCount; i++)
		{
			fputs((*books)[i].Name, file);
			fputs(" ", file);

			fputs((*books)[i].Author, file);
			fputs(" ", file);

			char num[5];

			_itoa_s((*books)[i].PageCount, num, 10);
			fputs(num, file);
			fputs(" ", file);

			_itoa_s((*books)[i].Rank, num, 10);
			fputs(num, file);
			
			if (i != rowCount - 1)
				fputs("\n", file);
		}

		fclose(file);
	}
}

void freeMatrix(char** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}