#include <stdio.h>

/**
 * main - Entery point
 * Description: prints all arguments it receives.
 * @argc: takes input from another.
 * @argv: takes input from another
 * Return: always 0 (Success)
*/

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
	printf("%s\n", argv[i]);
	}
	return (0);
}
