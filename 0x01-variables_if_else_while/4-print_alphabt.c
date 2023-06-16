#include <stdio.h>
/**
 * main - Print the alphabet in lowercase.
 * Print all the letters except q and e.
 * Return: 0
 */
int main(void)
{
	char c = 'a';

	while (c <= 'Z')
	{
		if (c != 'e' && c != 'q')
		{
			putchar(c);
		}
		c++;
	}

	putchar('\n');
	return (0);
}
