#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - reate a program that generates random valid
 *	passwords for the program 101-crackme.
 *
 * return : 0
*/




int main(void)
{
	int sum;
	char c;
	srand(time(NULL));
	while (sum <= 2645)
	{
	c = rand() % 128;
	sum += c;
	putchar(c);
	}
	putchar(2772 - sum);
	return (0);



}
