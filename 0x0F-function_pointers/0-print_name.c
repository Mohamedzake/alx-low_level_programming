#include <stdio.h>
/**
 * print_name - prints a name
 * @name: name of the person
 *@f:take the input from another.
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}

