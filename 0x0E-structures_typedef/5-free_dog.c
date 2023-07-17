#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory allocated for a dog_t structure
 * @d: Pointer to the dog_t structure to be freed
 *
 * Return: void
 * Free the memory allocated for the name string
 * Free the memory allocated for the owner string
 * Free the memory allocated for the dog_t structure
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
	free(d->name);
	free(d->owner);
	free(d);
	}
}

