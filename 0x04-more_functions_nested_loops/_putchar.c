#include "unistd.h"

/**
 *_putchar - print the code
 *@c: take the input from another
 * Return: Always 0.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
