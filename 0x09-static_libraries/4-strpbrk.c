#include "main.h"
#include <stdio.h>

/**
 **_strpbrk - searches a string for any of a set of bytes.
 *@s: take the input from another .
 *@accept: take the input from another .
 * Return: s and null .
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
	for (i = 0; accept[i] != '\0'; i++)
	{
	if (*s == accept[i])
	{
	return (s);
	}
	}
	s++;
	}
	return (NULL);
}
