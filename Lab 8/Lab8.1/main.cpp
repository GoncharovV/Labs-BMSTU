#include <stdio.h>
#include "mystring.h"

void removeWhiteSpaces(char* str);

int main()
{
	printf("Insert your string:\n");
	char str[100];
	gets_s(str);

	removeWhiteSpaces(str);

	puts(str);

	return 0;
}

void removeWhiteSpaces(char* str)
{	
	char* wp;
	char substring[] =  "  ";

	while (wp = strstr(str, substring))
		strcpy(wp, wp + 1);

	if (*str == ' ')
		strcpy(str, str + 1);

	if (strlen(str) > 1 && str[strlen(str) - 1] == ' ')
		str[strlen(str) - 1] = '\0';
}