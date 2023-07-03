#include "main.h"
/**
 * _strpbrk - A function that searches a string
 *	for any of a set of bytes.
 * @s: The string.
 * @accept: The bytes in the string.
 * Return: NULL if no such byte is found.
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return (s);
	i		}
		}
		s++;
	}
	return ('\0');
}
