#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * main - have the code.
 *@argc : take the input from another.
 *@argv: take the input from another.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
	printf("Error\n");
	return (98);
	}

	_multiply(argv[1], argv[2]);
	return (0);
}
/**
 * _isdigit - Checks if a string is composed of digits.
 * @str: The string to check.
 *
 * Return: 1 if the string is composed of digits, 0 otherwise.
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
	if (!isdigit(str[i]))
	return (0);
	i++;
	}

	return (1);
}
/**
 * _strlen - Computes the length of a string.
 * @str: The string to compute the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
	len++;

	return (len);
}
/**
 * _multiply - Multiplies two numbers and prints the result.
 * @num1: The first number.
 * @num2: The second number.
 */
void _multiply(char *num1, char *num2)
{
	int i, j;
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int len_result = len1 + len2;
	int *result = calloc(len_result, sizeof(int));

	if (result == NULL)
	{
	printf("Error\n");
	exit(98);
	}


	for (i = len1 - 1; i >= 0; i--)
	{
	for (j = len2 - 1; j >= 0; j--)
	{
	int mul = (num1[i] - '0') * (num2[j] - '0');
	int sum = result[i + j + 1] + mul;

	result[i + j] += sum / 10;
	result[i + j + 1] = sum % 10;
	}
	}

	i = 0;
	while (i < len_result - 1 && result[i] == 0)
	i++;

	while (i < len_result)
	printf("%d", result[i++]);

	printf("\n");
	free(result);
}
