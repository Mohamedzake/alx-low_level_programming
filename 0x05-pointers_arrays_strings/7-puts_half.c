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

	length = strlen(str);
	n = (length - 1 ) / 2;

	for (i = 0; i <= n; i++)
	{
	printf("%c", str[i]);
	}
	printf("\n");
}
