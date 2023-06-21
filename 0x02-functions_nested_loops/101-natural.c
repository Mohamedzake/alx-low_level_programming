#include "main.h"


/**
 * main - prints the sum of all the multiples of 3 or 5 below 1024 (excluded).
 *
 *
 * Return: 0
*/

int main(void)
{
	int num, sum;

	for (num = 0; num < 1024; num++)
	{
	if ((num % 3 == 0) || (num % 5 == 0))
	{
	sum += num;
	}
	}
	_putchar(sum + '0');
	return (0);

}
