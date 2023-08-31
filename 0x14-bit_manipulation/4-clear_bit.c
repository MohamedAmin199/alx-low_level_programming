#include "main.h"
/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 * @n: A pointer to the bit.
 * @index: The index.
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int p = 1;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	p <<= index;
	p = ~p;

	*n &= p;

	return (1);
}
