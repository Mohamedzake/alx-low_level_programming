#include "main.h"


/**
 * print_last_digit - prints the last digit of a number.
 *
 * @n: take the input from another
 *
 * Return:lastDigit.
*/

int print_last_digit(int n)
{
	int last_Digit;
	last_Digit = n % 10;
	if (last_Digit < 0)
	{
	last_Digit = (-1) *  last_Digit;

	}
	_putchar(last_Digit + '0');
	return (last_Digit);

}
