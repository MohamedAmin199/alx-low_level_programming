#include "main.h"
/**
 * swap_int - A function that swaps the values of two integers.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */

void swap_int(int *a, int *b)
{
	int n;

	int n = *a;
	*a = *b;
	*b = *n;
}
