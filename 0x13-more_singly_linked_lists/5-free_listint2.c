#include "lists.h"
#include <stdlib.h>
/**
 * free_listint2 - Frees a listint_t list.
 * @head: Pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *temp;

	if (head == NULL)
	return;

	current = *head;

	while (current != NULL)
	{
	temp = current;
	current = current->next;
	free(temp);
	}

	*head = NULL;
}
