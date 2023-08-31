#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: value.
 */
int get_endianness(void)
{
	unsigned int test = 1;
	unsigned char *ptr = (unsigned char *)&test;


	return (*ptr == 1);
}
