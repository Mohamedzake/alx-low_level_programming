#include <stdio.h>
#include <stdlib.h>
/**
 **malloc_checked -  allocates memory using malloc.
 *@b: take the input from another.
 * Return: Always void .
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
	exit(98);
	}
	return (ptr);
}
