#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *main - Add one line to this code.
 *
 * Return: 0 .
*/
int main(void)
{
	int a[] = {91, 92, 97, 98, 99};
	int *p;

	printf("a[2] = %d\n", *(&a[0] + 2));
	return (0);
}
