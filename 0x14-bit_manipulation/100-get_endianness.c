#include "main.h"
/**
 *get_endianness - checks the endianness.
 *@void: take the input from another.
 * Return: void.
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	return (*c);
}
