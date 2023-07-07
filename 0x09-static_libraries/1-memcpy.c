#include "main.h"
#include <stdio.h>

/**
 **_memcpy - copies memory area.
 *@dest: take the input from another .
 *@src: take the input from another .
 *@n: take the input from another .
 * Return: dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
	dest[i] = src[i];
	}
	return (dest);


}
