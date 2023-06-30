#include "main.h"
#include <stdio.h>

/**
 **cap_string - capitalizes all words of a string.
 *@str: take the input from another
 * Return: Always void.
 */
char *cap_string(char *str)
{
	int i;

	if (str[0] >= 'a' && str[0] <= 'z')
	{
	str[0] -= 32;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
	if (str[i - 1] == ' '  str[i - 1] == '\t'  str[i - 1] == '\n'
	str[i - 1] == ','  str[i - 1] == ';'  str[i - 1] == '.'
	str[i - 1] == '!'  str[i - 1] == '?'  str[i - 1] == '"'
	str[i - 1] == '('  str[i - 1] == ')'  str[i - 1] == '{'
	str[i - 1] == '}'
	{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
	str[i] -= 32;
	}
	}
	}
	return (str);

}
