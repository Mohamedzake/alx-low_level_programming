#include "unistd.h"

/**
 *_putchar - check the code
 *@a: take the input from another .
 * Return: Always 0.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
