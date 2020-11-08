#include <stddef.h>

int strlen(char* str)
{
	int len;

	for (len = 0; str[len]; len++);

	return len;
}

char* strcpy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);

	return dest;
}

char* strstr(char* str, char* subStr)
{
	char* q, * p = str, * qs = subStr;
	int check = 1;

	while (*p && *qs && check)
	{
		for (q = p, qs = subStr; *q && *q == *qs; q++, qs++) ;

		if (!(*qs && *q))
			check = 0;
		else
			p++;
	}

	return *p ? p : NULL;
}

char* strstr(char* str, char* subStr, int limiter)
{
	char* q, * p = str, * qs = subStr;
	int check = 1;
	int i = 0;

	while (*p && *qs && check && i < limiter)
	{
		for (q = p, qs = subStr; *q && *q == *qs; q++, qs++);

		if (!(*qs && *q))
			check = 0;
		else
			p++;

		i++;
	}

	return (*p && i < limiter) ? p : NULL;
}