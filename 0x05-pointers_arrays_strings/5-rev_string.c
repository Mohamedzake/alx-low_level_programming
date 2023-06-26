#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * rev_string - reverses a string.
 *@s: take the input from another
 * Return: void
 */

void rev_string(char *s)
{

	int length, i, j;

	length = strlen(s);

	for (i = 0, j = length - 1; i < j; i++, j--) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	}
}

void print_rev(char *s)
{
	s = "Hello, World!";


	rev_string(s);

	printf("After reversal: %s\n", s);


}
