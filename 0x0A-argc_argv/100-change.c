#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entery point
 * Description: prints the minimum number of coins to make change
 * for an amount of money.
 * @argc: takes input from another.
 * @argv: takes input from another
 * Return: always 0 (Success)
*/

int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
	printf("Error\n");
	return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
	printf("0\n");
	return (0);
	}

	coins += cents / 25;
	cents %= 25;

	coins += cents / 10;
	cents %= 10;

	coins += cents / 5;
	cents %= 5;

	coins += cents / 2;
	cents %= 2;

	coins += cents;

	printf("%d\n", coins);

	return (0);
}
