#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

#define PATH "file.bin"
#define STR_LEN 255

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
void sortBooks(int (*compare)(Book*, Book*));
void deleteBook();

void inputBook(Book* book);
void printBook(Book* book);
void setBook(Book* book, char* str);

void writeBookToFile(Book* book, FILE** file);
Book readBookFromFile(FILE** file, int index);
int getSizeOfFile(FILE** file);
int getBooksCount(FILE** file);

void bobleSort(Book** books, int count, int (*compare)(Book*, Book*));
void swapBooks(Book* book1, Book* book2);
void copyBook(Book* dest, Book* source);
int compareName(Book* book1, Book* book2);
int compareRank(Book* book1, Book* book2);

char** createMatrix(int n);
void freeMatrix(char** matrix, int n);

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
			sortBooks(&compareRank);
			break;
		case 4:
			sortBooks(&compareName);
			break;
		case 5:
			deleteBook();
			break;
	}

	return 0;
}

void displayMainMenu()
{
	printf("   Welcome\n What do you want to do?\n Add new Book - (1)\n Display all Books - (2)\n Sort Books by rank - (3)\n Sort Books by Name - (4)\n Delete Book by Name - (5)\n Exit - (6)\n > ");
}

void addBook()
{
	FILE* file;
	fopen_s(&file, PATH, "ab");

	if (file)
	{		
		Book book;
		inputBook(&book);
		
		writeBookToFile(&book, &file);

		fclose(file);
	}
}

void inputBook(Book* book)
{
	printf("Insert BookName Author PageCount Rank via space:\n > ");

	char* str = (char*)malloc(STR_LEN * sizeof(char));
	gets_s(str, STR_LEN);

	setBook(book, str);
}

void setBook(Book* book, char* str)
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

void writeBookToFile(Book* book, FILE** file)
{
	fseek(*file, 0, SEEK_END);

	fwrite(book, sizeof(Book), 1, *file);

	rewind(*file);
}

void displayBooks()
{
	FILE* file;
	fopen_s(&file, PATH, "rb");

	if (file)
	{
		fseek(file, 0, SEEK_SET);

		int bookCount = getBooksCount(&file);

		for (int i = 0; i < bookCount; i++)
		{
			printBook(&readBookFromFile(&file, i));
		}
		
		fclose(file);
	}
}

Book readBookFromFile(FILE** file, int index)
{
	int offset = index * sizeof(Book);
	fseek(*file, offset, SEEK_SET);

	Book book;

	fread(&book, sizeof(Book), 1, *file);

	rewind(*file);

	return book;
}

void printBook(Book* book)
{
	printf(" %s %s %d %d\n", book->Name, book->Author, book->PageCount, book->Rank);
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

void freeMatrix(char** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}

int getSizeOfFile(FILE** file)
{
	fseek(*file, 0, SEEK_END);

	int size = ftell(*file);

	rewind(*file);
	
	return size;
}

int getBooksCount(FILE** file)
{
	return getSizeOfFile(file) / sizeof(Book);
}

void sortBooks(int (*comparator)(Book*, Book*))
{
	FILE* file;
	fopen_s(&file, PATH, "rb");

	if (file)
	{
		int booksCount = getBooksCount(&file);

		Book* books = (Book*)malloc(booksCount * sizeof(Book));

		for (int i = 0; i < booksCount; i++)
		{
			books[i] = readBookFromFile(&file, i);
		}

		bobleSort(&books, booksCount, comparator);

		for (int i = 0; i < booksCount; i++)
		{
			printBook(&books[i]);
		}

		fclose(file);
		free(books);
	}
}

void bobleSort(Book** books, int count, int (*compare)(Book*, Book*))
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (compare(&(*books)[j], &(*books)[j + 1]))
			{
				swapBooks(&((*books)[j]), &((*books)[j + 1]));
			}
		}
	}
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

void deleteBook()
{
	FILE* file;
	fopen_s(&file, PATH, "a+b");

	if (file)
	{
		printf("Which author do you want to delete? (name)\n > ");

		char* name = (char*)malloc(STR_LEN * sizeof(char));
		gets_s(name, STR_LEN);

		int booksCount = getBooksCount(&file);

		Book book;

		book = readBookFromFile(&file, 2);

		rewind(file);
		fwrite(&book, sizeof(Book), 1, file);

		for (int j = 0; j < booksCount - 1; j++)
		{
			
		}

		/*for (int i = 0; i < booksCount; i++)
		{
			book = readBookFromFile(&file, i);

			if (!strcmp(book.Name, name))
			{

			}

		}*/

		fclose(file);
	}
}

int compareRank(Book* book1, Book* book2)
{
	return (book1->Rank < book2->Rank);
}

int compareName(Book* book1, Book* book2)
{
	if (strcmp(book1->Name, book2->Name) >= 0)
		return 0;
	else
		return 1;
}