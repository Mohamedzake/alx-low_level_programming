#include <stdio.h>

/**
 * main - entry point
 * Description: print  aplhabet ( lower ,upper)
 *
 * Return: 0 (success)
*/
int main(void)
{
	char ch = 'a';
	char CH = 'A';

	while (ch <= 'z')
	{
	putchar(ch);
	ch++;
	}

	while (CH <= 'z')
	{
	putchar(CH);
	CH++;
	}
	putchar('\n');

	return (0);

}
