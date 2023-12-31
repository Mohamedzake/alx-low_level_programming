#include "main.h"

/**
 *check_palindrome - Recursive helper function
 *	to check if a string is a palindrome.
 * @s: The string to be checked.
 * @start: The starting index of the current comparison.
 * @end: The ending index of the current comparison.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
	return (1);

	if (s[start] != s[end])
	return (0);

	return (check_palindrome(s, start + 1, end - 1));
}
/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to be checked.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = 0;
	int start = 0;
	int end;

	while (s[length] != '\0')
	length++;

	end = length - 1;

	return (check_palindrome(s, start, end));
}
