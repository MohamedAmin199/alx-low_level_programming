#include <stdio.h>
/**
 * main - Print all possible combinations of single-digit numbers.
 * Return:0
 */
int main(void)
{

	int x = 0;

	while (x < 10)
	{
		putchar(x);
		if (x != 9)
		{

	putchar(',');
	putchar(' ');
		}

		x++;
	}

	putchar('\n');
	return (0);
}
