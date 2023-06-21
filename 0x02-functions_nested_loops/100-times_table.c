#include "main.h"


/**
 * print_times_table -  prints the n times table, starting with 0.
 *
 * @n: takes number input
 *
 * Return:the n times table
*/

void print_times_table(int n)
{
	int result, mult, num;

	if (n <= 15 && n >= 0)
	{
	for (num = 0; num <= n; num++)
	{
	_putchar(48);
	for (mult = 1; mult <= n; mult++)
	{
	_putchar(',');
	_putchar(' ');
	result = num * mult;
	if (result <= 9)

	_putchar(' ');
	if (result <= 99)

	_putchar(' ');
	if (result >= 100)
	{
	_putchar((result / 100) + 48);
	_putchar((result / 10) % 10 + 48);
	}
	else if (result <= 99 && result >= 10)

	_putchar((result / 10) + 48);
	_putchar((result % 10) + 48);
	}
	_putchar('\n');
	}
	}

}
