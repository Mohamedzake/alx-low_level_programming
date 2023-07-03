#include "main.h"
#include <stdio.h>

/**
 *print_diagsums - prints the sum of the two diagonals
 *	of a square matrix of integers.
 *@size: take the input from another .
 *@a: take the input from another .
 * Return: 0.
 */
void print_diagsums(int *a, int size)
{
	int sum1 = 0;
	int sum2 = 0;
	int i;

	for (i = 0; i < size; i++)
	{
	sum1 += a[i * size + i];
	sum2 += a[i * size + (size - 1 - i)];
	}

	printf("Sum of the main diagonal: %d\n", sum1);
	printf("Sum of the secondary diagonal: %d\n", sum2);
}
