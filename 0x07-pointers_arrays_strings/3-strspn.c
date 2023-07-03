#include "main.h"
#include <stdio.h>

/**
 *_strspn - gets the length of a prefix substring.
 *@accept: take the input from another .
 *@s: take the input from another .
 * Return: count .
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int match;

	while (*s != '\0')
	{
	match = 0;
	for (int i = 0; accept[i] != '\0'; i++)
	{
	if (*s == accept[i])
	{
	match = 1;
	break;
	}
	}
	if (match == 0)
	{
	break;
	}
	count++;
	s++;
	}

	return (count);
}
