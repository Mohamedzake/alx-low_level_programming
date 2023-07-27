/* 3-add_node_end.c */

#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be duplicated and added as the new node's str.
 *
 * Return: Address of the new element or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (str == NULL)
	return (NULL);


	if (new_node == NULL)
	return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
	free(new_node);
	return (NULL);
	}

	new_node->len = strlen(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
	*head = new_node;
	}
	else
	{
	list_t *last_node = *head;

	while (last_node->next != NULL)
	last_node = last_node->next;

	last_node->next = new_node;
	}

	return (new_node);
}
