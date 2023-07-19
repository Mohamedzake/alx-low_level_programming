/**
 *int_index - searches for an integer.
 *@array: take the input from another.
 *@size: take the input from another.
 *@cmp: take the input from another.
 * Return: Nothing.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
	{
	for (i = 0; i < size; i++)
	{
	if (cmp(array[i]))
	{
	return (i);
	}
	}
	}
	return (-1);
}
