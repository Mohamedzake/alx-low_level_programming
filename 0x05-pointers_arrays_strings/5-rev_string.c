#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * rev_string - reverses a string.
 *@s: take the input from another
 * Return: void
 */
void rev_string(char *s)
{
	int length, i;
	s = "Holberton!";

	length = strlen(s);

	for (i = length - 1; i >= 0; i--)
	{
	printf("%c", s[i]);
	}
	printf("\n");

}
