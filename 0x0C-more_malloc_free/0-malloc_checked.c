#include "main.h"
/**
 * *malloc_checked - A function that allocates memory using malloc.
 * @b: The number of bytes to be allocated.
 * Return: A pointer.
 */

void *malloc_checked(unsigned int b)
{
	int *m = malloc(b);

	if (m == 0)
		exit(98);

	return (m);
}
