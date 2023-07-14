#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 **string_nconcat - concatenates two strings.
 *@s1: take the input from another.
 *@s2: take the input from another.
 *@n: take the input from another.
 * Return: Always void .
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, concat_len;
	char *concat;

	if (s1 == NULL)
	s1 = "";
	if (s2 == NULL)
	s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
	n = len2;

	concat_len = len1 + n;

	concat = malloc(sizeof(char) * (concat_len + 1));

	if (concat == NULL)
	return (NULL);

	memcpy(concat, s1, len1);
	memcpy(concat + len1, s2, n);
	concat[concat_len] = '\0';

	return (concat);
}
