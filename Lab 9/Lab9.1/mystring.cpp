#include "mystring.h"
#include <string.h>
#include <stdlib.h>

int countWords(char* str, char* separator)
{
	int count = 0;
	char* p = str;

	for (char* pSep; pSep = strstr(p, separator); p++)
	{
		if (pSep != p)
		{
			count++;
			p = pSep;
		}
	}

	if (strlen(p))
		count++;

	return count;
}

int parseWords(char*** words, char* str, char* sep)
{
	int count = countWords(str, sep);
	char* p = str;
	*words = (char**)malloc(count * sizeof(char*));
	int i = 0;

	for (char* pSep; pSep = strstr(p, sep); p++)
	{
		if (pSep != p)
		{
			int len = pSep - p + 1;

			(*words)[i] = (char*)malloc(len * sizeof(char));

			getSub((*words)[i], p, len);

			p = pSep;
			i++;
		}
	}

	if (strlen(p))
	{
		int len = strlen(p) + 1;

		(*words)[i] = (char*)malloc(len * sizeof(char));

		getSub((*words)[i], p, len);
	}

	return count;
}

void getSub(char* output, char* p, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		output[i] = p[i];
	}

	output[len - 1] = '\0';
}

void strCpyMy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
}