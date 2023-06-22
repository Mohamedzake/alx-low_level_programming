#include "main.h"

/**
 * print_line - draws a straight line in the terminal.
 *
 * @n: take the input frpm another
 *
*/

void print_line(int n)
{
	int i;

	if (n > 0)
	{  
	for (i = 0; i < n; i++)
	{
	putchar('');
	}
	_putchar('\n');
	}
	else
	{
	_putchar('\n');
	}
}
