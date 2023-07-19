#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Prints the opcodes of its own main function.
 * @argc: The number of command-line arguments (should be 2).
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success, 1 if incorrect number
 *	of arguments, 2 if size is negative.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	printf("Error\n");
	return (1);
	}

	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
	printf("Error\n");
	return (2);
	}

	unsigned char *main_addr = (unsigned char *)main;
	int i;

	for (i = 0; i < num_bytes; i++)
	{
	printf("%02x", main_addr[i]);
	if (i < num_bytes - 1)
	printf(" ");
	}
	printf("\n");

	return (0);
}

