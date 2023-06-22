#include "main.h"
/**
 * print_square - A function that prints a square uses the character #.
 * @size: The size of the square.
 */

void print_square(int size)
{
	int hgt, wid;

	if (size > 0)
	{
		for (hgt = 0; hgt < size; hgt++)
		{
			for (wid = 0; wid < size; wid++)
				_putchar('#');
			_putchar('\n');
		}
	}
	_putchar('\n');
}
