#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: take the input from user.
 *
 * Return: value.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
	return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
	if (b[i] == '0')
	{
	result = result << 1;
	}
	else if (b[i] == '1')
	{
	result = (result << 1) | 1;
	}
	else
	{
	return (0);
	}
	}

	return (result);
}
