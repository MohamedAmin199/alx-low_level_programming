#include "main.h"
/**
 * _puts - A function that prints a string, followed by a new line.
 * @str: The string to be printed.
 */

void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
