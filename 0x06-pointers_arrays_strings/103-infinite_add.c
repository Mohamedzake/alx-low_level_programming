#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * *infinite_add - adds two numbers.
 * @n1: take the input from another
 * @n2: take the input from another
 * @r: take the input from another
 * @size_r: take the input from another
 *
 * Return: 0 or r
*/

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, len1, len2, carry = 0;
	char *temp;

	len1 = strlen(n1);
	len2 = strlen(n2);

	if (len1 >= size_r || len2 >= size_r)
	{
	return (0);
	}

	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 1;
	r[k] = '\0';

	while (i >= 0  j >= 0  carry > 0)
	{
	int sum = carry;

	if (i >= 0)
	sum += n1[i--] - '0';
	if (j >= 0)
	sum += n2[j--] - '0';
	r[--k] = sum % 10 + '0';
	carry = sum / 10;
	}

	if (k < 0)
	return (0);

	temp = (char *)malloc((size_r - k) * sizeof(char));
	if (temp == NULL)
	return (0);

	strcpy(temp, &r[k]);
	strcpy(r, temp);
	free(temp);
	return (r);
}
