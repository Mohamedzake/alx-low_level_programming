#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *puts2 - prints every other character of a string,
 *	starting with the first character, followed by a new line.
 *@str: take the input from another
 * Return: void
 */
void puts2(char *str)
{
	int length, i;

	str = "0123456789";


	length = strlen(str);

	for (i = 0; str[i] != '\0'; i += 2)
	{

	
	printf("%c", str[i]);


	}
	printf("\n");
}


