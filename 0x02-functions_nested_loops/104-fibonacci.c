#include "main.h"
#include <stdio.h>

/**
 * numLength - return the length of string
 *
 *@num:number
 *
 * Return: number of digit
*/

int numLength(int num)
{
	int length = 0;

	if (!num)
	return (1);
	while (num)
	{
	num = num / 10;
	length += 1;
	}
	return (length);
}


/**
 * main - finds and prints the first 98 Fibonacci numbers,
 *	starting with 1 and 2.
 *
 *
 * Return: 0
*/

int main(void)
{
	int num, initial;

	unsigned long f1 = 1, f2 = 2, sum,
	max = 100000000, f1o = 0, f2o = 0, sumo = 0;

	for (num = 1; num <= 98; num++)
	{
	if (f1o > 0)
	printf("lu", f1o);
	initial = numLength(max) - 1 - numLength(f1);

	while (f1o > 0 && initial > 0)
	{
	printf("%d", 0);
	initial--;
	}
	printf("lu", f1);
	sum = (f1 + f2) % max;
	sumo = f1o + f2o + (f1 + f2) / max;
	f1 = f2;
	f1o = f2o;
	f2 = sum;
	f2o = sumo;

	if (num != 98)
	printf(", ");
	else
	printf("\n");
	}
	return (0);
}
