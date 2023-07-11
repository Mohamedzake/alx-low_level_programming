#include <stdlib.h>
#include <string.h>

char *argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int total_length = 0;
    int i, j;
    char *str;

    /* Calculate the total length of the concatenated string */
    for (i = 0; i < ac; i++)
    {
        total_length += strlen(av[i]);
    }

    /* Add space for newlines */
    total_length += ac - 1;

    /* Allocate memory for the concatenated string */
    str = (char *)malloc(sizeof(char) * (total_length + 1));
    if (str == NULL)
        return NULL;

    int position = 0;

    /* Copy each argument and add newline */
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

    /* Null-terminate the concatenated string */
    str[position] = '\0';

    return str;
}
