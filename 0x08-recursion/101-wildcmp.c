#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *wildcmp - compares two strings.
 *@s1:takes input from another.
 *@s2:takes input from another.
 * Return: 1 if the strings can be considered identical, otherwise return 0.
*/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
	return (1);
	}
	if (*s2 == '*')
	{
	if (*s1 == '\0')
	{
	return (wildcmp(s1, s2 + 1));
	}
	else
	{
	return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	}
	if (*s1 == *s2)
	{
	return (wildcmp(s1 + 1, s2 + 1));
	}
	return (0);
}
