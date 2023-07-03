#include "main.h"
/**
 * _strstr - A function that locates a substring.
 * @haystack: The string to be searched.
 * @needle: The substring to be located.
 * Return: 0
 */

char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == 0)
		return (haystack);

	while (*haystack)
	{
		i = 0;

		if (haystack[i] == needle[i])
		{
			do {
				if (needle[index + 1] == '\0')
					return (haystack);
				index++;

			} while (haystack[index] == needle[index]);
		}
		haystack++;
	}
	return ('\0');
}
