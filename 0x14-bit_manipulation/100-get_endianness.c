/* 100-get_endianness.c */
#include "main.h"

int get_endianness(void)
{
    unsigned int x = 1;
    char *c = (char *)&x;
    return (*c);
}

