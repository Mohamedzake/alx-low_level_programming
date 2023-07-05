#include "main.h"
/**
 * sqrt_helper - Recursive helper function to calculate the square root.
 * @n: The number to calculate the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The square root if it's a natural number, -1 otherwise.
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
	return (guess);

	if (guess * guess > n)
	return (-1);

	return (sqrt_helper(n, guess + 1));
}
/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 *@n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number. -1 if the number does not
 * have a natural square root.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	return (-1);

	return (sqrt_helper(n, 0));
}
