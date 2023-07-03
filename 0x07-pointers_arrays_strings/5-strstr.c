#include "main.h"
#include <stdio.h>

/**
 **_strstr - locates a substring.
 *@haystack: take the input from another .
 *@needle: take the input from another .
 * Return: haystack and null .
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
	char *h = haystack;
	char *n = needle;

	while (*n != '\0' && *h == *n)
	{
	h++;
	n++;
	}

	if (*n == '\0')
	{
	return (haystack);
	}

	haystack++;
	}
	return (NULL);
}
