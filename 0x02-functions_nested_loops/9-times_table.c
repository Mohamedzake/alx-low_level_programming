#include "main.h"


/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * @n && result: take the input from another
 *
 * Return:the 9 times table.
*/

void times_table(void)
{
	int n;
	int result;

	for (n = 0; n <= 10; n++)
	{
	result = 9 * n;
	_putchar((result + '0'));
	_putchar('\n');
	}
}
