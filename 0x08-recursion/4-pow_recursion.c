#include "main.h"
#include <stdio.h>

/**
 *_pow_recursion - returns the value of x raised to the power of y.
 *@x: take the input from another.
 *@y: take the input from another.
 * Return: Always 0.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	return (-1);

	if (y == 0)
	return (1);
	return (x * _pow_recursion(x, y - 1));
}
