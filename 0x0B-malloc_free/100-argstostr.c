#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 **argstostr - concatenates all the arguments of your program.
 *@ac: take the input from another.
 *@av: take the input from another.
 * Return: Always void.
 */
char *argstostr(int ac, char **av)
{
	int total_lengt = 0;
	int i, j;
	char *str;
	int position = 0;

	if (ac == 0 || av == NULL)
	return (NULL);


	for (i = 0; i < ac; i++)
	{
	total_lengt += strlen(av[i]);
	}

	total_lengt += ac - 1;

	str = (char *)malloc(sizeof(char) * (total_lengt + 1));
	if (str == NULL)
	return (NULL);

	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
	{
	str[position] = av[i][j];
	position++;
	}

	if (i != ac - 1)
	{
	str[position] = '\n';
	position++;
	}
	}

	str[position] = '\0';

	return (str);
}
