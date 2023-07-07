#include <stdio.h>

/**
 * main - Entery point
 * Description: prints the number of arguments passed into it.
 * @argc: takes input from another.
 * @argv: takes input from another
 * Return: always 0 (Success)
*/
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
