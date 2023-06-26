#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *puts_half - prints half of a string, followed by a new line
 *@str: take the input from another
 * Return: void
 */
void puts_half(char *str)
{
        int length, i, n;

	length = strlen(str);
	n = (length) / 2;
	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,
        sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
        Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex
        ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum
        dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in
        culpa qui officia deserunt mollit anim id est laborum.";

	for (i = n; str[i] != '\0'; ++i)
	{
	printf("%c", str[i]);
	}
	printf("\n");
}
