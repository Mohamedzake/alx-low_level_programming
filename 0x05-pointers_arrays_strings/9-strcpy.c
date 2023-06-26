#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 **_strcpy - copies the string pointed to by src, including
 *	the terminating null byte (\0), to the buffer pointed to by dest.
 *@dest: take the input from another
 *@src: take the input from another
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	*dest = -1;
	*src = -1;
	while (*src != '\0')
	{
	*dest = *src;
	dest++;
	src++;
	}
	return (dest);

        
}
