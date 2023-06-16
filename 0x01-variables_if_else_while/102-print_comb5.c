#include <stdio.h>

/**
 * main - entry point
 * Description: print all possible different combints
 *
 * Return: 0 (success)
*/
int main(void)
{
	int firstDigit = 0, seconDigit;

	while (firstDigit <= 99)
	{
	seconDigit = firstDigit;

	while (seconDigit <= 99)
	{
	if (seconDigit != firstDigit)
	{
	putchar((firstDigit / 10) + 48);
	putchar((firstDigit % 10) + 48);
	putchar(' ');
	putchar((seconDigit / 10) + 48);
	putchar((seconDigit % 10) + 48);
	if (firstDigit != 98 || seconDigit != 99)
	{
	putchar(',');
	putchar(' ');
	}

	}
	seconDigit++;
	}
	firstDigit++;

	}
	putchar('\n');

	return (0);



}
