#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - Print a char.
 * @args: The va_list that contains the char to be printed.
 */
void print_char(va_list args)
{
    char c = va_arg(args, int);
    printf("%c", c);
}

/**
 * print_integer - Print an integer.
 * @args: The va_list that contains the integer to be printed.
 */
void print_integer(va_list args)
{
    int num = va_arg(args, int);
    printf("%d", num);
}

/**
 * print_float - Print a float.
 * @args: The va_list that contains the float to be printed.
 */
void print_float(va_list args)
{
    double num = va_arg(args, double);
    printf("%f", num);
}

/**
 * print_string - Print a string.
 * @args: The va_list that contains the string to be printed.
 */
void print_string(va_list args)
{
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(nil)";
    printf("%s", str);
}

/**
 * print_all - Print anything based on the provided format.
 * @format: A string containing the format specifiers.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0, j = 0;
    char *separator = "";

    print_fn_t print_fns[] = {
        {'c', print_char},
        {'i', print_integer},
        {'f', print_float},
        {'s', print_string},
        {0, NULL}
    };

    va_start(args, format);

    while (format && format[i])
    {
        j = 0;
        while (print_fns[j].format)
        {
            if (print_fns[j].format == format[i])
            {
                printf("%s", separator);
                print_fns[j].printer(args);
                separator = ", ";
                break;
            }
            j++;
        }
        i++;
    }

    va_end(args);
    printf("\n");
}

