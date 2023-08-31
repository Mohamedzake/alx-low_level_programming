#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: take the input from user.
 * @index: take the input from user.
 *
 * Return: value.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
	return (-1);



	if (n & mask)
	return (1);
	else
	return (0);
}
