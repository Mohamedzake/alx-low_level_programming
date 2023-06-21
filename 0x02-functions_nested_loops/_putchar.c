#include "unistd.h"

/**
 * _putchar - this function  prints the output.
 *
 * @c:take the input for another
 * Return: Always 0.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
