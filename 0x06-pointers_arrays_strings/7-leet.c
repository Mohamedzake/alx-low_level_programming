#include "main.h"

/**
 **leet - encodes a string into 1337.
 *@str: take the input from another
 *Return: str
*/
char *leet(char *str)
{
	int i, j;
	char leet_char[5] = {'4', '3', '0', '7', '1'};
	char normal_char[5][3] = {{"aA"}, {"eE"}, {"oO"}, {"tT"}, {"lL"}};

	for (i = 0; str[i] != '\0'; i++)
	{
	for (j = 0; j < 5; j++)
	{
	if (str[i] == normal_char[j][0] || str[i] == normal_char[j][1])
	{
	str[i] = leet_char[j];
	break;
	}
	}
	}
	return (str);
}
