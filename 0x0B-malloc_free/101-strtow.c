#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 *is_space - splits a string into words.
 *@c: take the input from another.
 * Return: Always void.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
	if (!is_space(str[i]) && (is_space(str[i + 1]) || str[i + 1] == '\0'))
	{
	count++;
	}
	i++;
	}

	return (count);
}

char **strtow(char *str)
{
	int i, j, k;
	int word_count = count_words(str);
	char **words = malloc((word_count + 1) * sizeof(char *));
	if (str == NULL || str[0] == '\0')
	{
	return (NULL);
	}
	if (words == NULL)
	{
	return (NULL);
	}
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
	if (!is_space(str[i]))
	{
	int word_length = 0;
	k = i;
	while (!is_space(str[k]) && str[k] != '\0')
	{
	word_length++;
	k++;
	}
	words[j] = malloc((word_length + 1) * sizeof(char));
	if (words[j] == NULL)
	{
	for (i = 0; i < j; i++)
	{
	free(words[i]);
	}
	free(words);
	return (NULL);
	}
	for (k = 0; k < word_length; k++)
	{
	words[j][k] = str[i];
	i++;
	}
	words[j][k] = '\0';
	j++;
	}
	else
	{
	i++;
	}
	}
	words[j] = NULL;
	return (words);
}
