#include "main.h"
#include <stdio.h>

/**
 *set_string - sets the value of a pointer to a char.
 *@s: take the input from another.
 *@to: take the input from another.
 * Return: 0.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
