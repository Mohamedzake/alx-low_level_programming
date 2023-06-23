#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: finds and prints the largest prime factor of 612852475143
 *
 * Return: 0 (Success)
*/

int main(void)
{
	long num = 612852475143;
	long f = 2;
	long large_f = 0;

	while (num > 1)
	{
	if (num % f == 0)
	{
	num /= f;
	large_f = f;

	while (num % large_f == 0)
	{
	num /= large_f;
	}
	}
	else
	{
	f++;
	}
	}
	printf("%ld\n", large_f);
	return (0);
}
