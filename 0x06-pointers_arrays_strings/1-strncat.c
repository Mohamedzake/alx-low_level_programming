#include "main.h"
#include <stdio.h>

/**
 **_strncat - concatenates two strings.
 *@dest: take the input from another.
 *@src: take the input from another.
 *@n: take the input from another.
 * Return: Always pointer
 */
char *_strncat(char *dest, char *src, int n)
{
	char *dest_pt = dest;

	while (*dest_pt != '\0')
	{
	dest_pt++;
	}

	while (n > 0 && *src != '\0')
	{
	*dest_pt = *src;
	dest_pt++;
	src++;
	n--;
	}
	*dest_pt = '\0';

	return (dest);
}
