#include "main.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/**
 **cap_string - capitalizes all words of a string.
 *@str: take the input from another
 * Return: Always void.
 */
char *cap_string(char *str)
{
	int len = strlen(str);
	bool capitalize = true;
	int i;

	for (i = 0; i < len; i++) {
	if (isspace(str[i]) || str[i] == ',' || str[i] == ';' || str[i] == '.' ||
	str[i] == '!' || str[i] == '?' || str[i] == '"' || str[i] == '(' ||
 	str[i] == ')' || str[i] == '{' || str[i] == '}')
	{
	capitalize = true;
        }
	else if (capitalize)
	{
	str[i] = toupper(str[i]);
	capitalize = false;
	}
	}
	return (str);

}
