#include "main.h"
#include <stdio.h>
/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: take the input from user.
 * Return: value.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
