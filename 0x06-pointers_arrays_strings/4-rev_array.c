#include "main.h"
#include <stdio.h>

/**
 *reverse_array - reverses the content of an array of integers.
 *@a: take the input from another
 * @n: take the input from another
 * Return: Always void.
 */
void reverse_array(int *a, int n)
{
	int i, temp;

	for (i = 0; i < n / 2; i++)
	{
	temp = a[i];
	a[i] = a[n - 1 - i];
	a[n - 1 - i] = temp;
	}
}
