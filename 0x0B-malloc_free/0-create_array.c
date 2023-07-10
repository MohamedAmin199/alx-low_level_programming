#include "main.h"
/**
 * create_array - A function that creates an array of chars,
 * and initializes it with a specific char.
 * @size: The size of the array.
 * @c: The specific char to intialize the array.
 * Return: pointer to the array (Success), NULL (Error).
 */

char *create_array(unsigned int size, char c)
{
	char *n = malloc(size);

	if (size == 0 || n == 0)
		return (NULL);

	while (size--)
		n[size] = c;

	return (n);
}
