#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *print_rev - prints a string, in reverse, followed by a new line.
 *@s: take the input from another
 * Return: void
 */
void print_rev(char *s)
{
	int length, i;

	s = "Hello, World!";


	length = strlen(s);

	for (i = length - 1; i >= 0; i--)
	{
	printf("%c", s[i]);
	}
	printf("\n");
}
