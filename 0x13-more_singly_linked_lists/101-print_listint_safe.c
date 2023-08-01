#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t count = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
	printf("[%p] %d\n", (void *)slow, slow->n);
	slow = slow->next;
	fast = fast->next->next;


	if (slow == fast)
	{
	printf("-> [%p] %d\n", (void *)slow, slow->n);
	exit(98);
	}
	count++;
	}

	if (slow != NULL)
	{
	printf("[%p] %d\n", (void *)slow, slow->n);
	count++;
	}

	return (count);
}