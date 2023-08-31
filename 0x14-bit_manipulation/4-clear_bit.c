#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: take the input from user.
 * @index: take the input from user.
 *
 * Return: value.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

    if (index >= sizeof(unsigned long int) * 8)
        return -1;

    mask = ~mask;
    *n &= mask;

    return 1;
}

