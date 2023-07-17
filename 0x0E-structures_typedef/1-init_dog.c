#include "dog.h"
#include "main.h"
/**
 * init_dog - Initializes a struct dog
 * @d: Pointer to the struct dog
 * @name: dog's name
 * @age: dog's age
 * @owner: Owner's name
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
	d->name = name;
	d->age = age;
	d->owner = owner;
	}
}
