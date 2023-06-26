#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *print_array - prints n elements of an array of integers,
 *	followed by a new line.
 *@a: take the input from another
 *@n: take the input from another
 * Return: void
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
	printf("%d, ", a[i]);
	}
	printf("\n");
}
