#include "lists.h"
#include <stdlib.h>
/**
 * free_listint_safe - Frees a listint_t linked list safely (handles loops).
 * @h: Double pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
	count++;
	temp = current;
	current = current->next;


	if (temp < current)
	{
	temp->next = NULL;
	break;
	}

	free(temp);
	}
	*h = NULL;
	return (count);
}
