#include <stddef.h>
#include "lists.h"
/**
 *listint_len - returns the number of elements in a linked listint_t list.
 *@h: take the input from another.
 * Return: void .
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
	h = h->next;
	count++;
	}

	return (count);
}
