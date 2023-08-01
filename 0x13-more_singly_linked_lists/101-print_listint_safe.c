#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_listint_safe - Prints a listint_t linked list safely (handles loops).
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 *         If a loop is detected, the function will exit with status 98.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *loop_start = NULL;

	while (current != NULL)
	{
	printf("[%p] %d\n", (void *)current, current->n);
	count++;

	if (current > current->next)
	{
	loop_start = current->next;
	break;
	}

	current = current->next;
	}

	if (loop_start != NULL)
	{
	printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
	exit(98);
	}

	return (count);
}
