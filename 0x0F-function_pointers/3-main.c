#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

int (*get_op_func(char *s))(int, int);

/**
 * main - Entry point. Performs simple operations based on user input.
 * @argc: The number of command-line arguments (should be 4).
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success, 98 if incorrect number of arguments, 99 if invalid operator,
 *         100 if trying to divide by zero.
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;
    int (*op_func)(int, int);

    if (argc != 4)
    {
        printf("Error\n");
        return (98);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    op_func = get_op_func(argv[2]);

    if (op_func == NULL)
    {
        printf("Error\n");
        return (99);
    }

    if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
    {
        printf("Error\n");
        return (100);
    }

    result = op_func(num1, num2);
    printf("%d\n", result);

    return (0);
}
