#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *_atoi - convert a string to an integer.
 *
 *@s: take the input from another
 * Return: void
 */
int _atoi(char *s)
{
	unsigned int digit = 0;
	int sign = 1;

	do {
	if (*s == '-')
	sign *= -1;
	else if (*s >= '0' && *s <= '9')
	digit = (digit * 10) + (*s - '0');
	else if (digit > 0)
	break;
	} while (*s++);
	return (digit * sign);

}
