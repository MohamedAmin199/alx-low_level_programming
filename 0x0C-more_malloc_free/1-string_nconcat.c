#include "main.h"
/**
 * *string_nconcat - A function that concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 * Return: pointer.
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int i, j, len1, len2;

	/*Check if strings passed are NULL*/
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/*Compute the length of strings*/
	for (len1 = 0; s1[len1] != '\0'; len1++)
		;

	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	/*Memory reservation for case 1 & 2*/
	p = malloc(len1 + n + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	/*Copy firt string into p*/
	for (i = 0; s1[i] != '\0'; i++)
		p[i] = s1[i];
	/*Copy second string into p*/
	for (j = 0; j < n; j++)
	{
		p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	return (p);
}
