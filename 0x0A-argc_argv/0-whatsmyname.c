#include <stdio.h>

/**
 * main - Entery point
 * Description: prints its name, followed by a new line.
 * @argc: takes input from another.
 * @argv: takes input from another
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
