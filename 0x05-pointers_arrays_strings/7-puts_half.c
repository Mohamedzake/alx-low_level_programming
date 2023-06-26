#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *puts_half - prints half of a string, followed by a new line.
 *@str: take the input from another
 * Return: void
 */
void puts_half(char *str)
{
        int length, i, n;
	str = "0123456789";
	length = strlen(str);
	n = (length - 1 ) / 2;

	for (i = n; i <= length - 1; i++)
	{
	printf("%c", str[i]);
	}
	printf("\n");
}
