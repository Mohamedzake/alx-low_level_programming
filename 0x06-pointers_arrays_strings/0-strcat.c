#include "main.h"
#include <stdio.h>

/**
 **_strcat - concatenates two strings.
 *
 * Return: Always pointer.
 */
char *_strcat(char *dest, char *src)
{
	char *dest_pt = dest;

	while (*dest_pt != '\0') {
	dest_pt++;
	}
	while (*src != '\0')
	{
	*dest_pt = *src;
	dest_pt++;
	src++;
	}
	*dest_pt = '\0';
	return dest;
}
