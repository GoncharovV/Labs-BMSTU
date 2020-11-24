#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 100

void strCopyMy(char* dest, char* source);
void strCatMy(char* dest, char* src);
void strins(char* s, char* sub);
void addSpaces(char* str, int start, int end);
void dropWordToNewLine(char* str, int spaceInx);

int findLastSpaceIndex(char* str, int start, int end);

int main()
{
	char* str = (char*)malloc(STRING_SIZE * sizeof(char));

	printf("Insert string:\n > ");
	gets_s(str, STRING_SIZE);

	int width;
	printf("Insert width:\n > ");
	scanf_s("%d", &width);


	int start = 0;
	int end = width;

	char newLine[] = "\n";

	while (end < strlen(str))
	{
		if (str[end] != ' ')
		{
			addSpaces(str, start, end);
		}

		if (str[end] != '\0')
		{
			dropWordToNewLine(str, end);
		}		

		start = end + 1;
		end += width;
	}

	puts(str);

	return 0;
}

int findLastSpaceIndex(char* str, int start, int end)
{
	char space = ' ';

	int i = end;
	for (; str[i] != space && i < strlen(str); i--);

	return i;
}

void strCopyMy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
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

void addSpaces(char* str, int start, int end)
{
	char space[] = " ";

	int spaceIndex = findLastSpaceIndex(str, start, end);

	while (spaceIndex != end)
	{
		strins(&str[++spaceIndex], space);
	}
}

void dropWordToNewLine(char* str, int spaceInx)
{
	char newLineSym[] = "\n";
	strins(&str[spaceInx + 1], newLineSym);
}