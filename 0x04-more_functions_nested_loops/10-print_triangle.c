#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line.
 *
 * @size: take the input frpm another
 *
*/

void print_triangle(int size)
{

	int i, j, n;
	int num = size;

	if (size > 0)
	{
	for (i = 0; i < size; i++)
	{
	for (j = 1; j < num; j++)
	{
	_putchar(' ');
	}
	for (n = 0; n <= i; n++)
	{
	_putchar('#');
	}
	_putchar('\n');
	num--;
	}

	}
	else
	{
	_putchar('\n');
	}
}
