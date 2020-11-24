#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

#define STRING_SIZE 100
#define WORD_SIZE 20

struct Word
{
	char* value;
	int count;
};

void getString(char* str);
int isInDict(Word** dict, char* word, int count);
void addToDict(Word** dict, char* word, int count);
void displayDict(Word** dict, int count);

void freeDict(Word** dict, int count);
void freeWords(char*** words, int count);

int main()
{
	char* str = (char*)malloc(STRING_SIZE * sizeof(char));
	getString(str);

	char** words;
	char sep[] = " ";
	int countWords = parseWords(&words, str, sep);

	Word* dict = (Word*)malloc( sizeof(Word) );

	dict[0].value = (char*)malloc((strlen(words[0]) + 1) * sizeof(char));
	strCpyMy(dict[0].value, words[0]);
	dict[0].count = 1;

	int countInDict = 1;

	for (int i = 1; i < countWords; i++)
	{
		int inx;
		if ((inx = isInDict(&dict, words[i], countInDict)) != -1)
		{
			dict[inx].count++;
		}
		else
		{
			addToDict(&dict, words[i], countInDict);
			dict[i].count = 1;
			countInDict++;
		} 
	}


	displayDict(&dict, countInDict);

	freeWords(&words, countWords);
	freeDict(&dict, countInDict);

	return 0;
}

void getString(char* str)
{
	printf("Insert your string: \n");
	gets_s(str, STRING_SIZE);
}

int isInDict(Word** dict, char* word, int count)
{
	int result = -1;

	for (int i = 0; i < count; i++)
	{
		if (!strcmp((*dict)[i].value, word))
		{
			result = i;
			break;
		}
	}

	return result;
}

void addToDict(Word** dict, char* word, int count)
{
	realloc(*dict, (count + 1) * sizeof(Word));

	(*dict)[count].value = (char*)malloc(WORD_SIZE * sizeof(char));
	(*dict)[count].count = 1;

	strCpyMy((*dict)[count].value, word);
}

void displayDict(Word** dict, int count)
{
	printf("DICT\n");
	for (int i = 0; i < count; i++)
		printf("%s - (%d)\n", (*dict)[i].value, (*dict)[i].count);
}

void freeWords(char*** words, int count)
{
	for (int i = 0; i < count; i++)
		free((*words)[i]);

	free(*words);
}

void freeDict(Word** dict, int count)
{
	for (int i = 0; i < count; i++)
	{
		free((*dict)[i].value);
	}

	//free(*dict);
}
