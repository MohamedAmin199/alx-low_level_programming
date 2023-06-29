#include "main.h"
/**
 * _strcat - A function that concatenates two strings.
 * @dest: A pointer to the string to be concatenated upon.
 * @src: The source string to be appended to @dest.
 * Return: A pointer to the destination string @dest.
 */

char *strcat(char *dest, const char *src)
{
	int a = -1, i;
	for (i = 0; dest[i] != '\0'; i++);

	do
	{
		a++;
		dest[i] = src[a];
		i++;
	}
	while (src[a] != '\0');

	return (dest);
}
