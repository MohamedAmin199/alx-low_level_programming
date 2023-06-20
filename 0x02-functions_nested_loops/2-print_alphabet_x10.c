#include "main.h"

/**
 * print_alphabet_x10 - A function that prints alphabet 10 times,
 * in lowercase, followed by a new line.
 * Return: 0
 */

void print_alphabet_x10(void)
{

	int count;
	char letter;

	for (count = 0; count <= 9; count++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
	}
}
