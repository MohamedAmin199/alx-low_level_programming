#include "main.h"
/**
 * *str_concat - A function that concatenates two strings.
 * @s1: The string to be concatenated upon.
 * @s2: The string to be concatenated to s1.
 * Return: pointer to the new string created (Success), or NULL (Error).
 */

char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int i, concat_i = 0, len = 0;

	if (s1 == NULL)
		s1 = "\0";

	if (s2 == NULL)
		s2 = "\0";

	for (i = 0; s1[i] || s2[i]; i++)
		len++;

	concat_str = malloc(sizeof(char) * len);

	if (concat_str == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		concat_str[concat_i++] = s1[i];

	for (i = 0; s2[i]; i++)
		concat_str[concat_i++] = s2[i];

	return (concat_str);
}
