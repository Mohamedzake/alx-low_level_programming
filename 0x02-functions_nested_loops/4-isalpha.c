#include "main.h"


/**
 * _isalpha - checks for alphabetic character
 *
 * @c: take the input from another
 *
 * Return: 1 if character lowercase or uppercase
 *	or 0 for  any thigh another
*/

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
	return (1);
	}
	else
	{
	return (0);
	}


}
