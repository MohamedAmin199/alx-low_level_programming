#include "main.h"
/**
 * _memcpy - A function that copies memory area.
 * @dest: A pointer to the memory area to copy @src into.
 * @src: The source buffer to copy characters from.
 * @n: The number of bytes tobe copied.
 * Return: Pointer dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
